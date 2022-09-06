#include <fstream>
#include <algorithm>
#include <sstream>
#include <iterator>

#include "parser.h"

#define TYPE_BYTE_FILE    0
#define TYPE_BYTE_SKIP    1

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

/*
 * Functions defined in parser.h to be used in the 
 * main program
 */
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
  for(Line line : code->lines){
    cout << "LINE " << i << ": ";
    /* Placeholder for some actual decoding */

    /* save amount of parameters used in the instruction */
    line.parameter_count = line.words.size();

    /*here we save the program code length of an instruction */
    string str = line.words[0];
    transform(str.begin(), str.end(), str.begin(),[](unsigned char c){ return tolower(c); });
    line.length = categorize_Instruction_Length(str);

    /* here we initialize space for an appropriate amount of program memory lines of code */
    for(int j = 0 ; j < line.length ; j++) {
      printf("NEW PROGRAM MEMORY LINE %d : %d\n", i, j);
      Program_Word tmp = {.program_word = 0, .type = 0};
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
void decode_Lines(Code * code, Memory * memory) {

  /* Thanks to this we can categorize instructions 
   * and later at execution call apropriate functions 
   * for each type - addwf as byte_file for example */
  /* Byte_file can be further split into three categories by number of 
   * parameters f,d,a [3]|(f,a | fs,fd)[2] */
  vector<string> byte_file = {""};
  /* Byte_skip can be further split into three categories by number of 
   * parameters f,d,a [3]| f,a [2] */
  vector<string> byte_skip = {""};
  /* Bit_file always have three parameters f,b,a */ 
  vector<string> bit_file = {""};
  /* Bit_skip always have three parameters f,b,a */ 
  vector<string> bit_skip = {""};
  /* Inherent instructions don't have parameters */
  vector<string> inherent = {""};
  /* Literals can have either two or one parameters 
   * fn,k | k */
  vector<string> literal = {""};
  /* Control instructions have either one or two parameters 
   *( n | s | k )[1] | k,s [2] */
  vector<string> control = {""};

  int i = 0;
  cout << "DECODING INSTRUCTIONS\n";
  for(Line line : code->lines){
    /* Placeholder for some actual decoding */
  }
}
