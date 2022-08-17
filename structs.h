#include<vector>
#include<iostream>
using namespace std;

#ifndef STRUCTS_H
#define STRUCTS_H

/* Line structure
 * @words - a vector array of words used in one instruction
 * @type - number suggesting if instruction is an opcode, data or a label*/
typedef struct Line {
  vector<string> words;
  int type;
} Line;

/* Code structure 
 * @lines - an array of line structures
 * @length - amount of lines in source code*/
typedef struct Code {
  vector<Line> lines;
  int length;
} Code;

/* Memory structure */
typedef struct Memory {
} Memory;

#endif /* STRUCTS_H */
