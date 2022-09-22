#ifndef STRUCTS_H
#define STRUCTS_H

#include<vector>
#include<iostream>
#include<signal.h>           /* Definition of SIGEV_* constants */
#include<time.h>
#include<stdint.h>
#include<map>
#include<algorithm>
#include<iterator>
#include<regex>
#include<fstream>
using namespace std;

#define FSR0      0x4E9
#define WREG      0x4E8
#define BSR       0x4E0
#define STATUS    0x4D8
#define PROD      0x4F3

  typedef unsigned char u8;
  typedef unsigned short u16;
  typedef unsigned int u32;
  typedef unsigned long u64;
  typedef signed char s8;
  typedef signed short s16;
  typedef signed int s32;
  typedef signed long s64;

static vector<string> byte_skip_opcode = {"cpfseq", "cpfsgt", "cpfslt", "decfsz", "dcfsnz", "incfsz", "infsnz", "tstfsz"};

enum instruction_type {
  ERROR_TYPE,
  /* Byte_file */
  BYTE_FILE, 
  /* Byte_file_nw */
  BYTE_FILE_NW, 
  BYTE_SKIP,
  BYTE_SKIP_NW,
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
  LFSR,
};

union STATUS_R {
  u8 reg;
  struct {
  u8 undef : 1;
  u8 TO : 1;
  u8 PD : 1;
  u8 N : 1;
  u8 OV : 1;
  u8 Z : 1;
  u8 DC : 1;
  u8 C : 1;
  };
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

typedef struct Access_Bank {
  u8* data[256];
} Access_Bank;

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
 * @length - number meaning if instruction is 1, 2 or 3 bytes long
 * @index - line number*/
typedef struct Line {
  int address;
  vector<string> words;
  int parameter_count;
  int type;
  int number; 
  int length;
  int index;
  u16 coded_disasm;
} Line;

/* Code structure 
 * @base_address - the PC value of the first instruction
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
 * @address - program memory address (PC) assigned to the instruction
 * @data - any additional data that comes with the instruction (for example 
 *         any address with goto or branch, or literals longer than 8 bits)
 * */
typedef struct Program_Word {
  u16 program_word;
  enum instruction_type type;
  int address;
  int index;
  int data;
} Program_Word;

/* Memory structure 
 * @program_counter - 21 bit PC with only even values
 *                    pointing to instruction address
 * @instruction_register - hold a proram word of the current instruction
 * @instruction_data_latch - latch register used in fetch stage
 * @data_address - 14 bit address that we set while executing instruction, 
 *                 to know where we will save the result*/
typedef struct Memory {
  union R_21 program_counter;
  Program_Word instruction_register;
  Program_Word instruction_data_latch;
  u16 data_address;

  Access_Bank access_bank;
  vector<u8> data_memory;

  vector<Program_Word> program_memory;
} Memory;

typedef struct Data_Bus {
  u8 two_byte_write;
  u16 data;
} Data_Bus;

/* Bus structure */
typedef struct Bus {
  Program_Word instruction_Bus;
  Data_Bus data_Bus;
} Bus;

#endif /* STRUCTS_H */

#ifndef OPCODE_NUM_H
#define OPCODE_NUM_H

/* Here we define opcode numbers for execution lookup in switch 
 * expression */
#define INSTR_MOVFFL    6
#define INSTR_BTG       7
#define INSTR_BSF       8
#define INSTR_BCF       9
#define INSTR_BTFSS    10
#define INSTR_BTFSC    11
#define INSTR_MOVFF    12
#define INSTR_BRA      26
#define INSTR_RCALL    27
#define INSTR_ADDWF     9
#define INSTR_ADDWFC    8
#define INSTR_ANDWF     5
#define INSTR_COMF      7
#define INSTR_DECF      1
#define INSTR_INCF     10
#define INSTR_IORWF     4
#define INSTR_MOVF     20
#define INSTR_RLCF     13
#define INSTR_RLNCF    17
#define INSTR_RRCF     12
#define INSTR_RRNCF    16
#define INSTR_SUBFWB   21
#define INSTR_SUBWF    23
#define INSTR_SUBWFB   22
#define INSTR_SWAPF    14
#define INSTR_XORWF     6
#define INSTR_DECFSZ   11
#define INSTR_DCFSNZ   19
#define INSTR_INCFSZ   15
#define INSTR_INFSNZ   18
#define INSTR_CLRF     53
#define INSTR_MOVWF    17
#define INSTR_MULWF     1
#define INSTR_NEGF     54
#define INSTR_SETF     52
#define INSTR_CPFSEQ   49
#define INSTR_CPFSGT   50
#define INSTR_CPFSLT   48
#define INSTR_TSTFSZ   51
#define INSTR_CALL    118
#define INSTR_RETFIE    8
#define INSTR_RETURN    9
#define INSTR_BC      226
#define INSTR_BN      230
#define INSTR_BNC     227
#define INSTR_BNN     231
#define INSTR_BNOV    229
#define INSTR_BNZ     225
#define INSTR_BOV     228
#define INSTR_BZ      224
#define INSTR_CALLW    20
#define INSTR_GOTO    239
#define INSTR_RETLW    12
#define INSTR_CLRWDT    4
#define INSTR_DAW       7
#define INSTR_POP       6
#define INSTR_PUSH      5
#define INSTR_RESET   255
#define INSTR_SLEEP     3
#define INSTR_NOP       0
#define INSTR_ADDFSR  232
#define INSTR_ADDLW    15
#define INSTR_ANDLW    11
#define INSTR_IORLW     9
#define INSTR_LFSR    238
#define INSTR_MOVLB     1
#define INSTR_MOVLW    14
#define INSTR_MULLW    13
#define INSTR_RETLW    12
#define INSTR_SUBFSR  233
#define INSTR_SUBLW     8
#define INSTR_XORLW    10

/*
 * Below I am mapping the opcode strings to numbers 
 * I also group them by the amount of bits they occupy 
 * in the coded instruction so that later it's easier to 
 * differentiate between instructions with the same actual 
 * value of the opcode
 * */
static map<string, u8> opcode4_number = {{"movffl", 6},{"btg", 7},{"bsf", 8},{"bcf", 9},
                                  {"btfss", 10},{"btfsc", 11},{"movff", 12}};

static map<string, u8> opcode5_number = {{"bra", 26},{"rcall", 27}};

static map<string, u8> opcode6_number = {{"addwf", 9},{"addwfc", 8},{"andwf", 5},{"comf", 7},
                                 {"decf", 1},{"incf", 10},{"iorwf", 4},{"movf", 20},{"rlcf", 13},
                                 {"rlncf", 17},{"rrcf", 12},{"rrncf", 16},{"subfwb", 21},
                                 {"subwf", 23},{"subwfb", 22},{"swapf", 14},{"xorwf", 6},
                                 {"decfsz", 11},{"dcfsnz", 19},{"incfsz", 15},{"infsnz", 18}};

static map<string, u8> opcode7_number = {{"clrf", 53},{"movwf", 55},{"mulwf", 1},{"negf", 54},{"setf", 52},
                                  {"cpfseq", 49},{"cpfsgt", 50},{"cpfslt", 48},{"tstfsz", 51},
                                  {"call", 118},{"retfie", 8},{"return", 9}};

static map<string, u8> opcode8_number = {{"bc", 226},{"bn", 230},{"bnc", 227},{"bnn", 231},
                                 {"bnov", 229},{"bnz", 225},{"bov", 228},{"bz", 224},{"callw", 20},
                                 {"goto", 239},{"retlw", 12},{"clrwdt", 4},
                                 {"daw", 7},{"pop", 6},{"push", 5},{"reset", 255},
                                 {"sleep", 3}, {"nop", 0},{"xorlw", 10},
                                 {"addfsr", 232},{"addlw", 15},{"andlw", 11},
                                 {"iorlw", 9},{"lfsr", 238},{"movlb", 1},{"movlw", 14},
                                 {"mullw", 13},{"retlw", 12},{"subfsr", 233},{"sublw", 8}};

#endif /* OPCODE_NUM_H */
