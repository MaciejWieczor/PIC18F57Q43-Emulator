#include <map>
#include <iterator>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <iterator>

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

map<string, u8> opcode_number = {{"addwf", 9},{"addwfc", 8},{"andwf", 5},{"clrf", 53},{"comf", 7},
                                 {"decf", 1},{"incf", 10},{"iorwf", 4},{"movf", 20},{"movff", 12},
                                 {"movffl", 6},{"movwf", 55},{"mulwf", 1},{"negf", 54},{"rlcf", 13},
                                 {"rlncf", 17},{"rrcf", 12},{"rrncf", 16},{"setf", 52},{"subfwb", 21},
                                 {"subwf", 23},{"subwfb", 22},{"swapf", 14},{"xorwf", 6}
};
map<u8, string> number_opcode = reverse_map(opcode_number);

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
  return line;
}

static u8 categorize_Instruction_Length(string opcode) {
  vector<string> two_byte = {"call", "movff", "goto", "lfsr", "movsf", "movss"};
  vector<string> three_byte = {"movffl", "movsfl"};

  if (std::find(two_byte.begin(), two_byte.end(), opcode) != two_byte.end()) return 2;
  else if (std::find(three_byte.begin(), three_byte.end(), opcode) != three_byte.end()) return 3;
  else return 1;
}

/* --------------------------------------------------------------------------------------------------*/
/* Here is a big block of functions used to decode each type 
 * of instruction and fill the Program_Word structure */
static void byte_file_encode(Line * line, Memory * memory, u8 index) {
  cout << line->words[0] << " is " << "byte_file type\n";
  /* Anon union for easier access to parameters */
  /* defined in structs.h */
  WORD_UNION p_word;
  p_word.byte.opcode = opcode_number.find(line->words[0])->second;
  p_word.byte.f = stoul(line->words[1]);
  switch(line->words.size()) {
      case 2:
        p_word.byte.d = 1;
        p_word.byte.a = 1;
        break;
      case 3:
        p_word.byte.d = stoul(line->words[2]);
        p_word.byte.a = 1;
        break;
      case 4:
        p_word.byte.d = stoul(line->words[2]);
        p_word.byte.a = stoul(line->words[3]);
        break;
      default:
        cout << "ERROR - WRONG NUMBER OF PARAMETERS IN INSTRUCTION NR. " << line->number;
    }
  memory->program_memory[index].program_word = p_word.program_word;
  memory->program_memory[index].type = BYTE_FILE;
}

static void byte_file_nw_encode(Line * line, Memory * memory, u8 index) {
  cout << line->words[0] << " is " << "byte_file_nw type\n";
  /* Anon union for easier access to parameters */
  /* defined in structs.h */
  WORD_UNION p_word;
  p_word.byte_nw.opcode = opcode_number.find(line->words[0])->second;
  p_word.byte_nw.f = stoul(line->words[1]);
  switch(line->words.size()) {
      case 2:
        p_word.byte_nw.a = 1;
        break;
      case 3:
        p_word.byte_nw.a = stoul(line->words[3]);
        break;
      default:
        cout << "ERROR - WRONG NUMBER OF PARAMETERS IN INSTRUCTION NR. " << line->number;
    }
  memory->program_memory[index].program_word = p_word.program_word;
  memory->program_memory[index].type = BYTE_FILE_NW;
}

static void bit_encode(Line * line, Memory * memory, u8 index) {
  cout << line->words[0] << " is " << "bit_file type\n";
  WORD_UNION p_word;
  p_word.bit.opcode = opcode_number.find(line->words[0])->second;
  p_word.bit.f = stoul(line->words[1]);
  switch(line->words.size()) {
      case 2:
        p_word.bit.b = stoul(line->words[2]);
        p_word.bit.a = 1;
        break;
      case 3:
        p_word.bit.b = stoul(line->words[2]);
        p_word.bit.a = stoul(line->words[3]);
        break;
      default:
        cout << "ERROR - WRONG NUMBER OF PARAMETERS IN INSTRUCTION NR. " << line->number;
    }
  memory->program_memory[index].program_word = p_word.program_word;
  memory->program_memory[index].type = BIT;
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
  for(string line : lines){
    string tmp;
    /* Remove whitespace from line */
    tmp = trim(line);
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
    }
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
  for(Line &line : code->lines){
    cout << "LINE " << i << ": ";
    /* Placeholder for some actual decoding */

    /*here we save the program code length of an instruction */
    string str = line.words[0];
    transform(str.begin(), str.end(), str.begin(),[](unsigned char c){ return tolower(c); }); line.words[0] = str;
    line.length = categorize_Instruction_Length(str);

    /* here we initialize space for an appropriate amount of program memory lines of code */
    for(int j = 0 ; j < line.length ; j++) {
      printf("NEW PROGRAM MEMORY LINE %d : %d\n", i, j);
      Program_Word tmp = {.program_word = 0, .type = ERROR_TYPE};
      memory->program_memory.push_back(tmp);
    }

    /* Some tmp padding */
    for(int j = 0 ; j < 100 ; j++) {
      Program_Word tmp = {.program_word = 0, .type = ERROR_TYPE};
      memory->program_memory.push_back(tmp);
    }

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
    cout << "PROGRAM CODE INDEX " << i << " - LEN " << line.length << " - OPCODE " << line.words[0] << "\n";

    /* Call apropriate function based on instruction type */
    if (std::find(byte_file.begin(), byte_file.end(), line.words[0]) != byte_file.end()) 
      byte_file_encode(&line, memory, i);

    if (std::find(byte_file_nw.begin(), byte_file_nw.end(), line.words[0]) != byte_file_nw.end()) 
      byte_file_nw_encode(&line, memory, i);
      
    if (std::find(bit_file.begin(), bit_file.end(), line.words[0]) != bit_file.end()) 
      bit_encode(&line, memory, i);
      
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
  bus->instruction_Bus = memory->program_memory[0].program_word;

}
