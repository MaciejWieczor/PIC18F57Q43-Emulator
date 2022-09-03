#include<vector>
#include<iostream>
#include<signal.h>           /* Definition of SIGEV_* constants */
#include<time.h>
#include<stdint.h>
using namespace std;

#ifndef STRUCTS_H
#define STRUCTS_H

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long u64;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef signed long s64;

/* Clock structure */
typedef struct Clock {
  timespec tnow;
  u32 period;
  u8 active;
} Clock;

/* Line structure
 * @words - a vector array of words used in one instruction
 * @type - number suggesting if instruction is an opcode, data or a label
 * @number - number meaning which line in the code it is
 * @length - number meaning if instruction is 1, 2 or 3 bytes long*/
typedef struct Line {
  vector<string> words;
  int type;
  int number; 
  int length;
} Line;

/* Code structure 
 * @lines - an array of line structures
 * @length - amount of lines in source code*/
typedef struct Code {
  vector<Line> lines;
  int length;
  Clock main_clock;
} Code;

/* Memory structure */
typedef struct Memory {
} Memory;

/* Bus structure */
typedef struct Bus {
} Bus;

#endif /* STRUCTS_H */
