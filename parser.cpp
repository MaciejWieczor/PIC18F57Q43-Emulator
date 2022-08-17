#include <fstream>
#include <algorithm>
#include <sstream>
#include <iterator>

#include "parser.h"

using namespace std;

// function to load text line by line
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

// function to strip whitespace from line
const string WHITESPACE = " \n\r\t\f\v";
string ltrim(const string &s) {
    size_t start = s.find_first_not_of(WHITESPACE);
    return (start == string::npos) ? "" : s.substr(start);
}
 
string rtrim(const string &s) {
    size_t end = s.find_last_not_of(WHITESPACE);
    return (end == string::npos) ? "" : s.substr(0, end + 1);
}

string trim(const string &s) {
  return rtrim(ltrim(s));
}

/* check if line is only whitespace */
int whitespace_only(string str) {
  if(str.find_first_not_of(' ') != string::npos)
  {
    return 1;
  }
  /* There is only whitespace */
  return 0;
}

/* remove comments from string */
void remove_comments(string * original) {
  *original = original->substr(0, original->find(";"));
}

void remove_comma(string * str) {
  str->erase(std::remove(str->begin(), str->end(), ','), str->end());
}

Line split_Line(string s_line) {
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
    remove_comments(&tmp);
    /* Check if this line has anything left after removals */
    /* If line is empty just skip it */
    if(whitespace_only(tmp)) {
    /* Remove commas */
    remove_comma(&tmp);
    /* Now split line along spaces */
    /* And save the words vector */
    word_container.lines.push_back(split_Line(tmp));
    }
  }
  return word_container;
}

void print_Program_Code(Code code) {
  int i = 0;
  for(Line line : code.lines){
    cout << "LINE " << i << ": ";
    i++;
    for(string word : line.words){
      /*here do some prints */
      cout << word << " | ";
    }
    cout << "\n";
  }
}

void parse_Code(Code * code) {
  int i = 0;
  for(Line line : code->lines){
    i++;
    for(string word : line.words){
      /*here do some parsing */
    }
  }
  code->length = i;
}
// function to categorize opcodes
// function to translate vector to struct
