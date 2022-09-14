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

enum instruction_type {
  ERROR_TYPE,
  /* Byte_file */
  BYTE_FILE, 
  /* Byte_file_nw */
  BYTE_FILE_NW, 
  /* Byte_file / Byte_file_nw */
  BYTE_SKIP, 
  /* Bit_file  */
  BIT, 
  /* Inherent */
  INHERENT, 
  /* Control */
  BRA_COND, 
  BRA_UNCOND, 
  RET, 
  CALL, 
  GOTOI, 
  /* Literal */
  LITERAL,
  LITERAL_FSR,
  LFSR_ST,
};

union WORD_UNION {
  u16 program_word;

  struct {
    u8 opcode : 6;
    u8 d : 1;
    u8 a : 1;
    u8 f : 8;
  } byte;

  struct {
    u8 opcode : 7;
    u8 a : 1;
    u8 f : 8;
  } byte_nw;

  struct {
    /* For nop just set msb to 0xFX or 0x0X*/
    u8 msb : 8;
    u8 lsb : 8;
  } inherent;

  struct {
    u8 opcode : 8;
    u8 n : 8;
  } bra_cond;

  /* For BRA and RCALL */
  struct {
    u8 opcode : 5;
    u16 n : 11;
  } bra_uncond;

  /* For RETURN i RETFIE */
  struct {
    u8 zeros : 8;
    u8 opcode : 7;
    u8 s : 1;
  } ret;

  struct {
    u8 opcode : 7;
    u8 s : 1;
    u8 k : 7;
  } call;

  struct {
    u8 opcode : 8;
    u8 k : 8;
  } gotoi;

  struct {
    u8 opcode : 4;
    u8 b : 3;
    u8 a : 1;
    u8 f : 8;
  } bit;

  /* Literal formats defined */
  struct {
    u8 opcode : 8;
    u8 k : 8;
  } literal;

  struct {
    u8 opcode : 8;
    u8 f : 2;
    u8 k : 6;
  } addl_fsr;

  struct {
    u8 opcode : 8;
    u8 zeros : 2;
    u8 fn : 2;
    u8 k : 4;
  } lfsr;
};

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

typedef struct Memory_Bank {
  u8 data[256];
} Memory_Bank;

typedef struct Access_Bank {
  u8* data[256];
} Access_Bank;

typedef struct RAM {
  Memory_Bank bank[37];
} RAM;

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
  int address;
  vector<string> words;
  int parameter_count;
  int type;
  int number; 
  int length;
  int index;
} Line;

/* Code structure 
 * @lines - an array of line structures
 * @length - amount of lines in source code
 * @clock_Cycle - 0-3 values (inc,read memory, latch, decode, execute)
 * @pc_Changed - 0/1 - a flag set if pc was changed (if instruction was 
 *                     a goto or something like that)
 * @current_Line - PC/2 to know which line to load
 * @main_clock - Clock structure ticking for the CPU
 * */
typedef struct Code {
  int base_address;
  vector<Line> lines;
  int length;
  u8 clock_Cycle;
  u8 pc_Changed;
  u32 current_Line;
  Clock main_clock;
} Code;

/* Program_word structure 
 * @program_word - a massive union to help access bit fields
 * @type - defines what type of instruction we're dealing with
 * */
typedef struct Program_Word {
  u16 program_word;
  enum instruction_type type;
  int address;
  int index;
  int jump_address;
} Program_Word;

/* Memory structure 
 * @program_counter - 21 bit PC with only even values
 *                    pointing to instruction address*/
typedef struct Memory {
  union R_21 program_counter;
  Program_Word instruction_register;
  Program_Word instruction_data_latch;
  u8 wreg;

  union R_16 file_select_register[3];
  union R_16 indirect_file_register[3];
  union R_16 ram_address;
  u8 bank_select_register;
  Access_Bank access_bank;

  RAM ram;

  vector<Program_Word> program_memory;
} Memory;

/* Bus structure */
typedef struct Bus {
  Program_Word instruction_Bus;
  u16 data_Bus;
} Bus;

#endif /* STRUCTS_H */
