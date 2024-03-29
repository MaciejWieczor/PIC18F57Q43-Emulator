#ifndef STRUCTS_H
#define STRUCTS_H

#include <math.h>
#include"modules.h"
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

/* CPU Memory registers definitions */

#define FSR2      0x4D9
#define FSR1      0x4E1
#define FSR0      0x4E9
#define WREG      0x4E8
#define BSR       0x4E0
#define STATUS    0x4D8
#define PROD      0x4F3
#define PC        0x4F9
#define STKPTR    0x4FC
#define TOS       0x4FD

#define INDF0     0x4EF
#define INDF1     0x4E7
#define INDF2     0x4DF

#define PLUSW0     0x4EB
#define PREINC0    0x4EC
#define POSTDEC0   0x4ED
#define POSTINC0   0x4EE

/* UART */
#define U1CON0    0x2AB
#define U1CON1    0x2AC
#define U1CON2    0x2AD
#define U1BRG     0x2AE
#define U1RXB     0x2A1
#define U1TXB     0x2A3
#define U1FIFO    0x2B0

/* PPS */ 

#define RA0PPS    0x201
#define UART1_PPS 0x20
// C,F
#define UART2_PPS 0x23
// B,D
#define UART3_PPS 0x26
// A,F

/* PORTS */

#define PORTA     0x4CE
#define TRISA     0x4C6
/* LATB = ANSELA + 1 */
#define LATA      0x4BE
/* ANSELB = ANSELA + 8 */
#define ANSELA    0x400

/* ADC definitions */

#define ADCON0    0x3F3
#define ADCON1    0x3F4
#define ADCON2    0x3F5
#define ADCON3    0x3F6
#define ADCLK     0x3FA
#define ADPCH     0x3EC
#define ADPRE     0x3F1
#define ADACQ     0x3EE
#define ADRES     0x3EA
#define ADPREV    0x3E8
#define ADACT     0x3F9

/* TMR1 definitions */

#define T1CON     0x31E
#define T3CON     0x32A
#define T5CON     0x336

#define T1CLK     0x321
#define T3CLK     0x32D
#define T5CLK     0x339

#define T1GATE    0x320
#define T3GATE    0x32C
#define T5GATE    0x338

#define TMR1L     0x31C
#define TMR1H     0x31D
#define TMR3L     0x328
#define TMR5L     0x334

#define T1GCON    0x31F
#define T3GCON    0x32B
#define T5GCON    0x337

/* TMR0 definitions */

#define TMR0L     0x318
#define TMR0H     0x319
#define T0CON0    0x31A
#define T0CON1    0x31B

/* IVT/interrupt definitions */

#define IPR0    0x362
#define PIR0    0x4AE
#define PIR1    0x4AF
#define PIR2    0x4B0
#define PIR3    0x4B1
#define PIR4    0x4B2
#define INTCON0 0x4D6
#define INTCON1 0x4D7
#define PIE0    0x49E
#define PIE1    0x49F
#define PIE2    0x4A0
#define PIE3    0x4A1

#define IVTBASE 0x45D
#define IVTAD   0x45A
#define IVTLOCK 0x459

enum signals_adc {
  SINE_WAVE,
};

enum context {
  /* Main context */
  POLLING_CONT,
  /* Low context */
  LOW_CONT,
  /* High while main */ 
  HIGH_M_CONT,
  /* High while low */ 
  HIGH_L_CONT,
  INT_LAT_0_2_CONT,
  INT_LAT_0_3_CONT,
  INT_LAT_1_CONT,
  INT_LAT_2_CONT,
};

enum prior_lvl {
  MAIN_PRIORITY_LVL,
  LOW_PRIORITY_LVL,
  HIGH_PRIORITY_LVL,
};

/* IVT IRQ IDs */

#define TMR0_ID   0x1F
#define TMR1_ID   0x1C

/* typedefs for unsigned types */

  typedef unsigned char u8;
  typedef unsigned short u16;
  typedef unsigned int u32;
  typedef unsigned long u64;
  typedef signed char s8;
  typedef signed short s16;
  typedef signed int s32;
  typedef signed long s64;

/* UART unions */ 

union U1CON0_R {
  u8 data;
  struct {
    u8 MODE : 4;
    u8 RXEN : 1;
    u8 TXEN : 1;
    u8 ABDEN : 1;
    u8 BRGS : 1;
  };
};

union U1CON1_R {
  u8 data;
  struct {
    u8 SENDB : 1;
    u8 BRKOVR : 1;
    u8 empty_0 : 1;
    u8 RXBIMD : 1;
    u8 WUE : 1;
    u8 empty_1 : 2;
    u8 ON : 1;
  };
};

union U1CON2_R {
  u8 data;
  struct {
    u8 FLO : 2;
    u8 TXPOL : 1;
    u8 C0EN : 1;
    u8 STP : 2;
    u8 RXPOL : 1;
    u8 RUNOVF : 1;
  };
};

union U1FIFO_R {
  u8 data;
  struct {
    u8 RXBF : 1;
    u8 RXBE : 1;
    u8 XON : 1;
    u8 RXIDL : 1;
    u8 TXBF : 1;
    u8 TXBE : 1;
    u8 STMPD : 1;
    u8 TXWRE : 1;
  };
};

/* ADC unionts */ 
union ADCON0_R {
  u8 data;
  struct {
    u8 GO : 1;
    u8 empty_2 : 1;
    u8 FM : 1;
    u8 empty_1 : 1;
    u8 CS : 1;
    u8 empty : 1;
    u8 CONT : 1;
    u8 ON : 1;
  };
};

union ADCON1_R {
  u8 data;
  struct {
    u8 DSEN : 1;
    u8 empty : 4;
    u8 GPOL : 1;
    u8 IPEN : 1;
    u8 PPOL : 1;
  };
};

union ADCON2_R {
  u8 data;
  struct {
    u8 MD : 3;
    u8 ACLR : 1;
    u8 CRS : 3;
    u8 PSIS : 1;
  };
};

union ADCON3_R {
  u8 data;
  struct {
    u8 TMD : 3;
    u8 SOI : 1;
    u8 CALC : 3;
    u8 empty : 1;
  };
};

/* TMR1 unions */ 
union T1CON_R {
  u8 data;
  struct {
    u8 ON : 1;
    u8 RD16 : 1;
    u8 SYNC : 1;
    u8 empty_1 : 1;
    u8 CKPS : 2;
    u8 empty_0 : 2;
  };
};

union T1GCON_R {
  u8 data;
  struct {
    u8 empty : 2;
    u8 GVAL : 1;
    u8 GGO : 1;
    u8 GSPM : 1;
    u8 GTM : 1;
    u8 GPOL : 1;
    u8 GE : 1;
  };
};

union T1CLK_R {
  u8 data;
  struct {
    u8 CS : 5;
    u8 empty : 3;
  };
};

union T1GATE_R {
  u8 data;
  struct {
    u8 GSS : 6;
    u8 empty : 2;
  };
};

/* TMR0 unions */
union T0CON0_R {
  u8 data;
  struct {
  u8 OUTPS: 4;
  u8 MD16 : 1;
  u8 OUT  : 1;
  u8 empty: 1;
  u8 EN   : 1;
  };
};

union T0CON1_R {
  u8 data;
  struct {
  u8 CKPS  : 4;
  u8 ASYNC: 1;
  u8 CS   : 3;
  };
};

/* IVT unions */
union PIR1_R {
  u8 data;
  struct {
    u8 INT0IF : 1;
    u8 ZCDIF : 1;
    u8 ADIF : 1;
    u8 ACTIF : 1;
    u8 CM1IF : 1;
    u8 SMT1IF : 1;
    u8 SMT1PRAIF : 1;
    u8 SMT1PWAIF : 1;
  };
};

union PIE1_R {
  u8 data;
  struct {
    u8 INT0IE : 1;
    u8 ZCDIE : 1;
    u8 ADIE : 1;
    u8 ACTIE : 1;
    u8 CM1IF : 1;
    u8 SMT1IE : 1;
    u8 SMT1PRAIE : 1;
    u8 SMT1PWAIE : 1;
  };
};

union PIR3_R {
  u8 data;
  struct {
    u8 SPI1RXIF : 1;
    u8 SPI1TXIF : 1;
    u8 SPI1IF : 1;
    u8 TMR2IF : 1;
    u8 TMR1IF : 1;
    u8 TMR1GIF : 1;
    u8 CCP1IF : 1;
    u8 TMR0IF : 1;
  };
};

union PIE3_R {
  u8 data;
  struct {
    u8 SPI1RXIE : 1;
    u8 SPI1TXIE : 1;
    u8 SPI1IE : 1;
    u8 TMR2IE : 1;
    u8 TMR1IE : 1;
    u8 TMR1GIE : 1;
    u8 CCP1IE : 1;
    u8 TMR0IE : 1;
  };
};

union INTCON0_R {
  u8 data;
  struct {
    u8 INT0EDG : 1;
    u8 INT1EDG : 1;
    u8 INT2EDG : 1;
    u8 empty : 2;
    u8 IPEN : 1;
    u8 GIEL : 1;
    u8 GIEGIEH : 1;
  };
};

union INTCON1_R {
  u8 data; 
  struct {
    /* 11: High ISR while Low ISR
     * 10: High ISR while Main 
     * 01: Low ISR while Main 
     * 00: Main*/
    u8 empty : 6;
    u8 STAT : 2;
  };
};

/* Instruction type defines */
enum instruction_type {
  NOP_TYPE,
  /* Byte_file */
  BYTE_FILE, 
  /* Byte_file_nw */
  BYTE_FILE_NW, 
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
  u8 C : 1;
  u8 DC : 1;
  u8 Z : 1;
  u8 OV : 1;
  u8 N : 1;
  u8 PD : 1;
  u8 TO : 1;
  u8 undef : 1;
  };
};

union WORD_UNION {
  u16 program_word;

  struct {
    u8 f : 8;
    u8 a : 1;
    u8 d : 1;
    u8 opcode : 6;
  } byte;

  struct {
    u8 f : 8;
    u8 a : 1;
    u8 opcode : 7;
  } byte_nw;

  struct {
    /* For nop just set msb to 0xFX or 0x0X*/
    u8 lsb : 8;
    u8 msb : 8;
  } inherent;

  struct {
    u8 n : 8;
    u8 opcode : 8;
  } bra_cond;

  /* For BRA and RCALL */
  struct {
    u16 n : 11;
    u8 opcode : 5;
  } bra_uncond;

  /* For RETURN i RETFIE */
  struct {
    u8 s : 1;
    u8 opcode : 7;
    u8 zeros : 8;
  } ret;

  struct {
    u8 k : 8;
    u8 s : 1;
    u8 opcode : 7;
  } call;

  struct {
    u8 k : 8;
    u8 opcode : 8;
  } gotoi;

  struct {
    u8 f : 8;
    u8 a : 1;
    u8 b : 3;
    u8 opcode : 4;
  } bit;

  /* Literal formats defined */
  struct {
    u8 k : 8;
    u8 opcode : 8;
  } literal;

  struct {
    u8 k : 6;
    u8 f : 2;
    u8 opcode : 8;
  } addl_fsr;

  struct {
    u8 k : 4;
    u8 fn : 2;
    u8 zeros : 2;
    u8 opcode : 8;
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

/* MODULE DEFINITIONS */
typedef struct Interrupt_Vector_Module {
  map<string, int> interrupt_vector;
  u8 context;
  u8 last_context;
  u8 instruction_len;
  int current_isr_addr;
  u8 current_isr_prior_lvl;
} Interrupt_Vector_Module;


typedef struct TMR0_Module {
  u8 enabled;
  int ivt_address;
  /* ACC is the counter */
  int acc;
  int pre_acc;
  int post_acc;
  int pre;
  int post;
} TMR0_module;

typedef struct TMR1_Module {
  u8 enabled;
  int ivt_address;
  /* ACC is the counter */
  int acc;
  int pre_acc;
  int pre;
  /* This value is used for 
   * checking if there was a rising/falling edge*/
  u8 last_cs_val;
} TMR1_module;

typedef struct TMR3_Module {
  u8 enabled;
  int ivt_address;
  /* ACC is the counter */
  int acc;
  int pre_acc;
  int pre;
} TMR3_module;

typedef struct TMR5_Module {
  u8 enabled;
  int ivt_address;
  /* ACC is the counter */
  int acc;
  int pre_acc;
  int pre;
} TMR5_module;

typedef struct Analog_Pin {
  short val;
} Analog_Pin;

typedef struct Ports_Module {
  Analog_Pin port_pins[6][8];
} Ports_Module;

enum ADC_STATE {
	ADC_WAITING,
	ADC_PRECHARGE,
	ADC_ACQUIRE,
	ADC_CONVERT,
};

typedef struct ADC_Module {
  long long nano_clock;
  long long nano_end;
  unsigned short last_measured_value;
  ADC_STATE state;
} ADC_Module;

enum UART_STATE {
  UART_OFF,
  UART_POLL,
  UART_POLL_SEND,
  UART_SEND
};

typedef struct UART_Module {
  UART_STATE state;
  int frequency_split;
  u8 TSR;
  int counter;
  int bit_counter;
  u8 transaction_start;
  u8 port;
  u8 pin;
  u8 port_changed;
} UART_Module;

/* MODULES */

typedef struct Modules {
  Interrupt_Vector_Module IVT_module;
  TMR0_Module TMR0_module;
  TMR1_Module TMR1_module;
  TMR3_Module TMR3_module;
  TMR5_Module TMR5_module;
  Ports_Module Ports_module;
  ADC_Module ADC_module;
  UART_Module UART_module;
} Modules;


typedef struct Access_Bank {
  u8* data[256];
} Access_Bank;

/* Clock structure 
 * @timer - QTimer used with the Qt framework
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
  int txt_index;
  int last_c_index;
  int gui_len;
  u16 coded_disasm;
} Line;

typedef struct C_Line {
  string line;
  int txt_index;
  int index;
  int gui_len;
} C_Line;

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
  vector<C_Line> c_lines;
  int length;
  int txt_length;
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
  int return_stack [127];
  vector<u8> fast_register_stack;

  Modules modules;
  u8 pc_EN;

  long long time_moment;
  long long Fosc_moment;
  long long Fosc_period_nano;
} Memory;

typedef struct Data_Bus {
  u8 two_byte_write;
  u16 data;
  u32 indirect_address;
  u32 indirect_reg;
  u16 last_fsr0;
  u16 last_fsr1;
  u16 last_fsr2;
  u8 write;
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
#define INSTR_MOVWF    55
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

void module_interrupt(Memory * memory, Bus * bus, Code * code, int clock);

void module_tmr0(Memory * memory, Bus * bus, int clock);

void module_tmr1(Memory * memory, Bus * bus, int clock);

void module_adc(Memory * memory, Bus * bus, int clock);

void module_uart(Memory * memory, Bus * bus, int clock);

void module_pps(Memory * memory, Bus * bus, int clock);

void module_uart(Memory * memory, Bus * bus, int clock);
