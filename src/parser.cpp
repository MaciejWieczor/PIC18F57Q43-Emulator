#include "structs.h"
#include "parser.h"

using namespace std;

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

static void save_C_Line(string * original, Code * code, int txt_index) {
    if(regex_match(*original, regex("^[0-9]+:(.*)"))) {
    printf("FOUND C LINE : %s, AT LINE NUMBER %d\n", original->c_str(), txt_index);
    C_Line l = {.line = *original, .txt_index = txt_index};
    code->c_lines.push_back(l);
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

  /* Here we save the instruction coded by the disassembler */
  tmp = "0x" + line.words[1];
  line.coded_disasm = stoul(tmp, NULL, 16);

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
  char* p;
  p_word.bit.f = strtol(line->words[1].c_str(), &p, 16);
  if (*p) {
      // conversion failed because the input wasn't a number
    p_word.byte.f = (line->coded_disasm & 0x00FF);
  }

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
}

static void byte_file_nw_encode(Line * line, Memory * memory) {
  cout << line->words[0] << " is " << "byte_file_nw type\n";
  /* Anon union for easier access to parameters */
  /* defined in structs.h */
  WORD_UNION p_word;
  p_word.byte_nw.opcode = opcode7_number.find(line->words[0])->second;
  char* p;
  p_word.byte_nw.f = strtol(line->words[1].c_str(), &p, 16);
  if (*p) {
      // conversion failed because the input wasn't a number
    p_word.byte_nw.f = (line->coded_disasm & 0x00FF);
  }

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
  char* p;
  p_word.bit.f = strtol(line->words[1].c_str(), &p, 16);
  if (*p) {
      // conversion failed because the input wasn't a number
    p_word.byte_nw.f = (line->coded_disasm & 0x00FF);
  }
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
  WORD_UNION p_word;
  p_word.inherent.lsb = opcode8_number.find(line->words[0])->second;
  printf("ENCODED : opcode %d\n", p_word.inherent.lsb);
  memory->program_memory[line->address/2].program_word = p_word.program_word;
  memory->program_memory[line->address/2].type = INHERENT;
}

/* Here we encode control instructions. They usually modify the PC so they 
 * carry an address in their argument. To make life easier we'll just save 
 * the argument-address in a field in the program word structure. For any 
 * non-jump instruction it will just equal the base address. (We use the 
 * data field in Program_Word struct)
 * Possible formats are :
 * Conditional branch*/
static void control_encode(Line * line, Memory * memory, u8 index) {
  printf("%s is control type\n", line->words[0].c_str());
  WORD_UNION p_word;
  if( line->words[0] == "return" || line->words[0] == "retfie" ) {
    p_word.ret.zeros = 0;
    p_word.ret.opcode = opcode7_number.find(line->words[0])->second;
    p_word.ret.s = stoul(line->words[1], NULL, 16);
    memory->program_memory[line->address/2].type = RET;
    printf("ENCODED : opcode %d k %d\n", p_word.ret.opcode, p_word.ret.s);
  }
  else if ( line->words[0] == "call" ) {
    p_word.call.opcode = opcode7_number.find(line->words[0])->second;
    p_word.call.s = stoul(line->words[2], NULL, 16);
    p_word.call.k = 0;
    memory->program_memory[line->address/2].data = stoul(line->words[1], NULL, 16);
    memory->program_memory[line->address/2].type = CALL;
    printf("ENCODED : opcode %d k %X\n", p_word.call.opcode, memory->program_memory[line->address/2].data);
  }
  else if (line->words[0] == "goto") {
    p_word.gotoi.opcode = opcode8_number.find(line->words[0])->second;
    p_word.gotoi.k = 0;
    memory->program_memory[line->address/2].data = stoul(line->words[1], NULL, 16);
    memory->program_memory[line->address/2].type = GOTOI;
    printf("ENCODED : opcode %d k %X\n", p_word.gotoi.opcode, memory->program_memory[line->address/2].data);
  }
  /* 5 bit opcode means unconditional branch */
  else if(opcode5_number.find(line->words[0]) != opcode5_number.end()) {
    p_word.bra_uncond.opcode = opcode5_number.find(line->words[0])->second;
    p_word.bra_uncond.n = stoul(line->words[1], NULL, 16);
    memory->program_memory[line->address/2].data = stoul(line->words[1], NULL, 16);
    memory->program_memory[line->address/2].type = BRA_UNCOND;
    printf("ENCODED : opcode %d k %X\n", p_word.bra_uncond.opcode, memory->program_memory[line->address/2].data);
  }
  /* 8 bit opcode means conditional branch */
  else if(opcode8_number.find(line->words[0]) != opcode8_number.end()) {
    p_word.bra_cond.opcode = opcode8_number.find(line->words[0])->second;
    p_word.bra_cond.n = stoul(line->words[1], NULL, 16);
    memory->program_memory[line->address/2].data = stoul(line->words[1], NULL, 16);
    memory->program_memory[line->address/2].type = BRA_COND;
    printf("ENCODED : opcode %d k %X\n", p_word.bra_cond.opcode, memory->program_memory[line->address/2].data);
  }
  memory->program_memory[line->address/2].program_word = p_word.program_word;
  
}

/* Here we encode literal instructions in three formats (as specified at the end 
 * of WORD_UNION data structure. A literal - 8 bit opcode and 8 bit parameter,
 * lsfr - 8 bit opcode, 2 bit zeroes, 2 bit fsr select, 4 bit literal start (lfsr 
 * stores 14 bit literal in the program_word.data field, that's used to store longer 
 * data than one program word), addlfsr - 8 bit opcode, 2 bit fsr select, 6 bit literal */
static void literal_encode(Line * line, Memory * memory, u8 index) {
  printf("%s is literal type\n", line->words[0].c_str());
  WORD_UNION p_word;
  /* First case - 8 bit opcode */
  if(line->words[0] == "lfsr") {
    p_word.lfsr.opcode = opcode8_number.find(line->words[0])->second;
    p_word.lfsr.zeros = 0;
    p_word.lfsr.fn = stoul(line->words[1], NULL, 16);
    p_word.lfsr.k = 0;
    memory->program_memory[line->address/2].data = stoul(line->words[2], NULL, 16);
    memory->program_memory[line->address/2].type = LFSR;
    printf("ENCODED : opcode %d, fn %d, k %d\n", p_word.lfsr.opcode, p_word.lfsr.fn, memory->program_memory[line->address/2].data);
  }
  else if(line->words[0] == "addfsr" || line->words[0] == "subfsr") {
    p_word.addl_fsr.opcode = opcode8_number.find(line->words[0])->second;
    p_word.addl_fsr.f = stoul(line->words[1], NULL, 16);
    p_word.addl_fsr.k = stoul(line->words[2], NULL, 16);
    memory->program_memory[line->address/2].type = LITERAL_FSR;
    printf("ENCODED : opcode %d, fn %d, k %d\n", p_word.addl_fsr.opcode, p_word.addl_fsr.f, p_word.addl_fsr.k);
  }
  else if(opcode8_number.find(line->words[0]) != opcode8_number.end()) {
    p_word.literal.opcode = opcode8_number.find(line->words[0])->second;
    p_word.literal.k = stoul(line->words[1], NULL, 16);
    memory->program_memory[line->address/2].type = LITERAL;
    printf("ENCODED : opcode %d k %d\n", p_word.literal.opcode, p_word.literal.k);
  }
  memory->program_memory[line->address/2].program_word = p_word.program_word;
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
      save_C_Line(&tmp, &word_container, i);
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
        word_container.lines[j].txt_index = i;
        j++;
      }
    }
    i++;
  }
  word_container.txt_length = i;
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
    Program_Word tmp = {.program_word = 0, .type = NOP_TYPE, 
                        .address = 0, .index = 0, .data = 0};
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
    cout << " - AT TXT LINE : " << line.txt_index;
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
                                 "movwf", "mulwf", "negf", "setf"};

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

/* This returns the first C_Line's txt_index that contains a substring str */
static int find_C_Line(Code * code, string str) {
  for(C_Line line : code->c_lines){
    size_t found = line.line.find(str);
    if (found!=string::npos)
      /* FOUND */
      return line.txt_index;
  }
  printf("DIDN'T FIND A C LINE WITH SUBSTRING %s IN IT\n", str.c_str());
  return -1;
}

/* This returns the address of the first disasm line after C_Line at txt index */
static int find_Next_Disasm_Prog_Word(Code * code, int txt_index) {
  for(Line line : code->lines){
    if(line.txt_index > txt_index)
      return line.address;
  }
  printf("NEXT LINE AFTER C MAIN WAS NOT FOUND\n");
  return -1;
}

void find_IRQs(Code * code, Memory * memory) {
  /* Find main C_Line */
  int main_index = find_C_Line(code, "main(");
  /* Find next disasm line */
  int main_disasm_adr = find_Next_Disasm_Prog_Word(code, main_index);

  if(main_disasm_adr != -1) {
    /* Set as the first address to start program from */
    code->base_address = memory->program_memory[main_disasm_adr/2].address;
    /* Overwrite program counter to the main instruction */
    memory->program_counter.DATA = code->base_address - 2;
  }

  /* Find TMR0 IRQ address */
  /* Check if string contains substring */ /* "IRQ_TMR0" */
  int tmr0_index = find_C_Line(code, "IRQ_TMR0");
  /* Find the next disasm line after the found C_Line */
  int tmr0_disasm_adr = find_Next_Disasm_Prog_Word(code, tmr0_index);
  /* Save interrupt handler address to memory modules structure */
  if(tmr0_disasm_adr != -1) {
    memory->modules.TMR0_module.enabled = 1;
    memory->modules.TMR0_module.ivt_address = tmr0_disasm_adr;
    memory->modules.IVT_module.interrupt_vector.insert({"tmr0", tmr0_disasm_adr});
  }
  else
    memory->modules.TMR0_module.enabled = 0;
}
