#include"structs.h"

/* A function to load the program code from file to a vector of strings 
 * @name - string containing the name of the source code file*/
vector<string> load_Program_Text(string name);

/* A function to split whole program code into words
 * @name - the name of the text file to read code from*/
Code split_Program_Code(string name);

/* Print some data about the split words 
 * @code - Code struct with all parsed data*/
void print_Program_Code(Code * code);

/* Parse code text to get some metadata and save it 
 * Mosly resolve labels and switch from variables 
 * to actual numbers
 * @code - Code struct that needs parsing*/
void parse_Code(Code * code, Memory * memory);

/* Decode parsed lines from words and numbers 
 * into program memory entity (2-6 bytes lines based 
 * on the type of instruction)
 * @code - Parsed code*/
void decode_Lines(Code * code, Memory * memory, Bus * bus);

void find_IRQs(Code * code, Memory * memory);
