#include<iostream>
#include<vector>
#include<string>
#include"structs.h"
using namespace std;


/* A function to load the program code from file to a vector of strings 
 * @name - string containing the name of the source code file*/
vector<string> load_Program_Text(string name);

/* A function to split whole program code into words
 * @name - the name of the text file to read code from*/
Code split_Program_Code(string name);

/* Print some data about the split words 
 * @code - Code struct with all parsed data*/
void print_Program_Code(Code code);

/* Parse code text to get some metadata and save it 
 * @code - Code struct that needs parsing*/
void parse_Code(Code * code);
