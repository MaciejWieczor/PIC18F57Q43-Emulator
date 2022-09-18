#include <map>
#include <iterator>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <iterator>
#include <regex>

#include "parser.h"

#define TYPE_BYTE_FILE    0
#define TYPE_BYTE_SKIP    1

using namespace std;

static map<u8, string> reverse_map(const map<string, u8>& m) {
    map<u8, string> r;
    for (const auto& kv : m)
        r[kv.second] = kv.first;
    return r;
}


/*
 * Below I am mapping the opcode strings to numbers 
 * I also group them by the amount of bits they occupy 
 * in the coded instruction so that later it's easier to 
 * differentiate between instructions with the same actual 
 * value of the opcode
 * */
map<string, u8> opcode4_number = {{"movffl", 6},{"btg", 7},{"bsf", 8},{"bcf", 9},
                                  {"btfss", 10},{"btfsc", 11},{"movff", 12}};

map<string, u8> opcode5_number = {{"bra", 26},{"rcall", 27}};

map<string, u8> opcode6_number = {{"addwf", 9},{"addwfc", 8},{"andwf", 5},{"comf", 7},
                                 {"decf", 1},{"incf", 10},{"iorwf", 4},{"movf", 20},{"rlcf", 13},
                                 {"rlncf", 17},{"rrcf", 12},{"rrncf", 16},{"subfwb", 21},
                                 {"subwf", 23},{"subwfb", 22},{"swapf", 14},{"xorwf", 6},
                                 {"decfsz", 11},{"dcfsnz", 19},{"incfsz", 15},{"infsnz", 18}};

map<string, u8> opcode7_number = {{"clrf", 53},{"movwf", 55},{"mulwf", 1},{"negf", 54},{"setf", 52},
                                  {"cpfseq", 49},{"cpfsgt", 50},{"cpfslt", 48},{"tstfsz", 51},
                                  {"call", 118},{"retfie", 8},{"return", 9}};

map<string, u8> opcode8_number = {{"bc", 226},{"bn", 230},{"bnc", 227},{"bnn", 231},
                                 {"bnov", 229},{"bnz", 225},{"bov", 228},{"bz", 224},{"callw", 20},
                                 {"goto", 239},{"retlw", 12},{"clrwdt", 4},
                                 {"daw", 7},{"pop", 6},{"push", 5},{"reset", 255},
                                 {"sleep", 3},
                                 {"addfsr", 232},{"addlw", 15},{"andlw", 11},
                                 {"iorlw", 9},{"lfsr", 238},{"movlb", 1},{"movlw", 14},
                                 {"mullw", 13},{"retlw", 12},{"subfsr", 233},{"sublw", 8}};

map<u8, string> number_opcode7 = reverse_map(opcode7_number);
map<u8, string> number_opcode6 = reverse_map(opcode6_number);
map<u8, string> number_opcode5 = reverse_map(opcode5_number);
map<u8, string> number_opcode4 = reverse_map(opcode4_number);
map<u8, string> number_opcode8 = reverse_map(opcode8_number);


/* 
 * Static functions to use in other functions 
 */
const string whitespace = " \n\r\t\f\v";
static string ltrim(const string &s) {
    size_t start = s.find_first_not_of(whitespace);
    return (start == string::npos) ? "" : s.substr(start);
}
 
static string rtrim(const string &s) {
    size_t end = s.find_last_not_of(whitespace);
    return (end == string::npos) ? "" : s.substr(0, end + 1);
}

static string trim(const string &s) {
  return rtrim(ltrim(s));
}

/*
 * Condition functions
 */
/* check if line is only whitespace */
static int whitespace_Only(string str) {
  if(str.find_first_not_of(' ') != string::npos)
  {
    return 1;
  }
  /* There is only whitespace */
  return 0;
}

/* remove comments from string */
static void remove_Comments(string * original) {
  *original = original->substr(0, original->find(";"));
  *original = original->substr(0, original->find("---"));
}

static void save_C_Line(string * original) {
    if(regex_match(*original, regex("^[0-9]+:(.*)"))) {
    printf("FOUND C LINE\n");
    *original = "";
  }
}

static void remove_Comma(string * str) {
  str->erase(std::remove(str->begin(), str->end(), ','), str->end());
}

static Line split_Line(string s_line) {
  Line line;
  stringstream ss(s_line);
  istream_iterator<string> begin(ss);
  istream_iterator<string> end;
  vector<string> tokens(begin, end);

  for (string s: tokens) {
      line.words.push_back(s);
  }

  string tmp = "0x" + line.words[0];
  line.address = stoul(tmp, NULL, 16);
  /* Delete the first two string as they are the address 
   * which we save just above and the code which we don't need */
  line.words.erase(line.words.begin(), line.words.begin() + 2);

  return line;
}

static u8 categorize_Instruction_Length(string opcode) {
  vector<string> two_byte = {"call", "movff", "lfsr", "movsf", "movss"};
  vector<string> three_byte = {"movffl", "movsfl"};

  if (std::find(two_byte.begin(), two_byte.end(), opcode) != two_byte.end()) return 2;
  else if (std::find(three_byte.begin(), three_byte.end(), opcode) != three_byte.end()) return 3;
  else return 1;
}

/* --------------------------------------------------------------------------------------------------*/
/* Here is a big block of functions used to decode each type 
 * of instruction and fill the Program_Word structure */
/* Each function accesses the opcode - number maps based on the category 
 * that each instruction belongs to (it depends on the structure of parameters, 
 * their length, etc.) Some opcode numbers occur in the instruction set more than 
 * once so there is a need to categorize - for example 
 * byte oriented instrucions have a 6 bit opcode, then d and a parameters and a 
 * register address but there are instructions that access a register but 
 * have a hardcoded d parameter. In that case the opcode is 7 bit long and it 
 * is categorized separately. Some instructions like BRA need to be 
 * separately coded because they have a different length of the opcode (5 bits) and 
 * they carry an address to jump to. To avoid the problems of coding a jump address 
 * in two separate program words we just assign it an additional field in the program 
 * word structure. If an instruction needs to jump it has its argument right there to 
 * write to the program counter - and of course execute the next instruction as a NOP */
static void byte_file_encode(Line * line, Memory * memory) {
  cout << line->words[0] << " is " << "byte_file type\n";
  /* Anon union for easier access to parameters */
  /* defined in structs.h */
  WORD_UNION p_word;
  p_word.byte.opcode = opcode6_number.find(line->words[0])->second;
  p_word.byte.f = stoul(line->words[1], NULL, 16);

        if(line->words[2] == "F")
          p_word.byte.d = 1; /* Default */
        else
          p_word.byte.d = 0;

        if(line->words[3] == "ACCESS")
          p_word.byte.a = 0;
        else
          p_word.byte.a = 1; /* Default */

  memory->program_memory[line->address/2].program_word = p_word.program_word;
  memory->program_memory[line->address/2].type = BYTE_FILE;
  memory->program_memory[line->address/2].address = line->address;
  memory->program_memory[line->address/2].index = line->index;
}

static void byte_file_nw_encode(Line * line, Memory * memory) {
  cout << line->words[0] << " is " << "byte_file_nw type\n";
  /* Anon union for easier access to parameters */
  /* defined in structs.h */
  WORD_UNION p_word;
  p_word.byte_nw.opcode = opcode7_number.find(line->words[0])->second;
  p_word.byte_nw.f = stoul(line->words[1], NULL, 16);

        if(line->words[2] == "ACCESS")
          p_word.byte_nw.a = 0;
        else
          p_word.byte_nw.a = 1; /* Default */

  printf("ENCODED : opcode %d a %d f %d\n", p_word.byte_nw.opcode, p_word.byte_nw.a, p_word.byte_nw.f);
  memory->program_memory[line->address/2].program_word = p_word.program_word;
  memory->program_memory[line->address/2].type = BYTE_FILE_NW;
}

static void bit_encode(Line * line, Memory * memory) {
  cout << line->words[0] << " is " << "bit_file type\n";
  WORD_UNION p_word;
  p_word.bit.opcode = opcode4_number.find(line->words[0])->second;
  p_word.bit.f = stoul(line->words[1], NULL, 16);
  p_word.bit.b = stoul(line->words[2], NULL, 16);

        if(line->words[3] == "ACCESS")
          p_word.bit.a = 0;
        else
          p_word.bit.a = 1; /* Default */

  printf("ENCODED : opcode %d b %d a %d f %d\n", p_word.bit.opcode, p_word.bit.b, p_word.bit.a, p_word.bit.f);
  memory->program_memory[line->address/2].program_word = p_word.program_word;
  memory->program_memory[line->address/2].type = BIT;
}

static void inherent_encode(Line * line, Memory * memory, u8 index) {
  cout << line->words[0] << " is " << "inherent type\n";
}

static void control_encode(Line * line, Memory * memory, u8 index) {
  cout << line->words[0] << " is " << "control type\n";
}

static void literal_encode(Line * line, Memory * memory, u8 index) {
  cout << line->words[0] << " is " << "literal type\n";
}

/* -----------------------------------------------
 * Functions defined in parser.h to be used in the 
 * main program
 * ---------------------------------------------*/
vector<string> load_Program_Text(string name) {
  vector<string> container;
  fstream newfile;
  newfile.open(name, ios::in); //open a file to perform read operation using file object
   if (newfile.is_open()){   //checking whether the file is open
      string tp;
      while(getline(newfile, tp)){ //read data from file object and put it into string.
        container.push_back(tp);
      }
      newfile.close(); //close the file object.
   }
  return container;
}

Code split_Program_Code(string name) {
  Code word_container;
  /* Load the program text into a vector line by line */
  vector<string> lines = load_Program_Text(name);
  /* Go line by line and do string parsing */
  int i = 0;
  int j = 0;
  int offset = 0;
  for(string line : lines){
    /* Get current index */
    if(i > 3) {
      string tmp;
      /* Remove whitespace from line */
      tmp = trim(line);
      /* Find and remove C line */
      save_C_Line(&tmp);
      /* Remove comments from line */
      remove_Comments(&tmp);
      /* Check if this line has anything left after removals */
      /* If line is empty just skip it */
      if(whitespace_Only(tmp)) {
        /* Remove commas */
        remove_Comma(&tmp);
        /* Now split line along spaces */
        /* And save the words vector */
        word_container.lines.push_back(split_Line(tmp));
        if( word_container.lines.size() == 1 )
          word_container.base_address = word_container.lines[0].address;
        word_container.lines[j].index = j;
        j++;
      }
    }
    i++;
  }
  return word_container;
}

void print_Program_Code(Code * code) {
  int i = 0;
  for(Line line : code->lines){
    cout << "LINE " << i << ": ";
    i++;
    for(string word : line.words){
      /*here do some prints */
      cout << word << " - bytes: " << line.length << " | ";
    }
  }
}

void parse_Code(Code * code, Memory * memory) {
  int i = 0;
  /* here we initialize space for an appropriate amount of program memory lines of code */
  int program_memory_size = 64 * 1024; // this is the amount of program_words we can have
  for(int j = 0 ; j < program_memory_size ; j++) {
    Program_Word tmp = {.program_word = 0, .type = ERROR_TYPE, 
                        .address = 0, .index = 0, .jump_address = code->base_address};
    memory->program_memory.push_back(tmp);
  }

  for(Line &line : code->lines){
    cout << "LINE " << i << ": ";
    /* Placeholder for some actual decoding */

    /*here we save the program code length of an instruction */
    string str = line.words[0];
    transform(str.begin(), str.end(), str.begin(),[](unsigned char c){ return tolower(c); }); line.words[0] = str;
    line.length = categorize_Instruction_Length(str);

    memory->program_memory[line.address/2].address = line.address;
    memory->program_memory[line.address/2].index = line.index;

    for(string word : line.words){
      /*here do some parsing */
      cout << word << " | ";
    }
    cout << "\n";
    i++;
  }
  code->length = i;
}

/* function to categorize opcodes */
void decode_Lines(Code * code, Memory * memory, Bus * bus) {

  /* Thanks to this we can categorize instructions 
   * and later at execution call apropriate functions 
   * for each type - addwf as byte_file for example */
  /* Byte_file can be further split into three categories by number of 
   * parameters f,d,a [3]|(f,a | fs,fd)[2] */
  vector<string> byte_file = {"addwf", "addwfc", "andwf", "comf",
                              "decf", "incf", "iorwf", "movf", "rlcf",
                              "rlncf", "rrcf", "rrncf", "subfwb", 
                              "subwf", "subwfb", "swapf", "xorwf",
                              "decfsz", "dcfsnz", "incfsz", "infsnz"};

  vector<string> byte_file_nw = {"cpfseq", "cpfsgt", "cpfslt", "clrf", 
                                 "movff", "movffl", "tstfsz",
                                 "movwf", "mulwf", "negwf", "setf"};

  /* Bit type always has three parameters f,b,a */ 
  vector<string> bit_file = {"bcf", "bsf", "btg", "btfsc", "btfss"};

  /* Inherent instructions don't have parameters */
  vector<string> inherent = {"clrwdt", "daw", "nop", "pop", "push",
                             "reset", "sleep"};
  /* Literals can have either two or one parameters 
   * fn,k | k */
  vector<string> literal = {"addfsr", "addlw", "andlw", "iorlw",
                            "lfsr", "movlb", "movlw", "mullw",
                            "retlw", "subfsr", "sublw", "xorlw"};
  /* Control instructions have either one or two parameters 
   *( n | s | k )[1] | k,s [2] */
  vector<string> control = {"bc", "bn", "bnc", "bnn", "bnov",
                            "bnz", "bov", "bra", "bz", "call",
                            "callw", "goto", "rcall", "retfie",
                            "retlw", "return"};

  int i = 0;

  printf("DECODING INSTRUCTIONS\n");
  for(Line &line : code->lines){
    /* Placeholder for some actual decoding */
    cout << "PROGRAM CODE INDEX " << line.index << " - LEN ";
    cout << line.length << " - OPCODE " << line.words[0] << " - ADDRESS " << line.address << " - ";
    cout << "PROGRAM MEM INDEX " << i <<"\n";

    /* Call apropriate function based on instruction type */
    if (std::find(byte_file.begin(), byte_file.end(), line.words[0]) != byte_file.end()) 
      byte_file_encode(&line, memory);

    if (std::find(byte_file_nw.begin(), byte_file_nw.end(), line.words[0]) != byte_file_nw.end()) 
      byte_file_nw_encode(&line, memory);
      
    if (std::find(bit_file.begin(), bit_file.end(), line.words[0]) != bit_file.end()) 
      bit_encode(&line, memory);
      
    if (std::find(inherent.begin(), inherent.end(), line.words[0]) != inherent.end()) 
      inherent_encode(&line, memory, i);

    if (std::find(control.begin(), control.end(), line.words[0]) != control.end()) 
      control_encode(&line, memory, i);

    if (std::find(literal.begin(), literal.end(), line.words[0]) != literal.end()) 
      literal_encode(&line, memory, i);

    /* Increment index (i) by the amount of words it will take in the 
     * program memory */
    i += line.length;
  }

  /* Some post initialization */
  bus->instruction_Bus = memory->program_memory[0];

}
