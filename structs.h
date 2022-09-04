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

/* Union type to abstract a 21 bit register
 * that is in reality three 8 bit registers 
 * combined - sometimes byte access is locked
 * (like in the case of PC) */
union R_21 {
  unsigned int DATA : 21;
  struct {
    u8 L;
    u8 H;
    u8 U : 5;
  };
};

union R_16 {
  u16 DATA;
  struct {
    u8 L;
    u8 H;
  };
};

/* Clock structure 
 * @tnow - timespec of when the clock was turned on
 * @period - clock period in nanoseconds
 * @active - 0/1 off/on*/
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
 * @length - amount of lines in source code
 * @instruction_Cycle - 0-2 values (fetch/exec/exec2)
 * @clock_Cycle - 0-11 values (inc,read memory, latch, decode, execute)
 * @pc_Changed - 0/1 - a flag set if pc was changed (if instruction was 
 *                     a goto or something like that)
 * @current_Line - PC/2 to know which line to load
 * @main_clock - Clock structure ticking for the CPU
 * */
typedef struct Code {
  vector<Line> lines;
  vector<u16> decoded_lines;
  int length;
  u8 instruction_Cycle;
  u8 clock_Cycle;
  u8 pc_Changed;
  u32 current_Line;
  Clock main_clock;
} Code;

/* Memory structure 
 * @program_counter - 21 bit PC with only even values
 *                    pointing to instruction address*/
typedef struct Memory {
  union R_21 program_counter;
  union R_16 instruction_register;
  union R_16 instruction_data_latch;
} Memory;

/* Bus structure */
typedef struct Bus {
  u16 instruction_Bus;
  u16 data_Bus;
} Bus;

#endif /* STRUCTS_H */
