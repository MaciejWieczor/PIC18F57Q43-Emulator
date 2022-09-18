#include <time.h>
#include <stdio.h>

#include "procesor.h"

#define CLOCK_PC_INC_LATCH_IR       0
#define CLOCK_PC_INC_DECODE         1
#define CLOCK_ADDRESS_PROCESS       2
#define CLOCK_LATCH_WRITE           3

static Program_Word read_Instruction_Bus(Code * code, Memory * memory, Bus * bus) {
  return bus->instruction_Bus; 
}

/* Here we need to check the file parameter of the instruction 
 * and resolve it to an actual address that we access in the next step */
static void decode_memory(Memory * memory, Code * code) {
      Program_Word tmp_p;
      WORD_UNION tmp;
      tmp_p = memory->instruction_register;
      tmp.program_word = tmp_p.program_word;
}

/* Here we change the values of registers according to the opcode 
 * and the parameters */
static void execute_instruction(Memory * memory) {
      switch(memory->instruction_register.type) {

      /* File operations that take one byte as register address */
      case BYTE_FILE:
        break;
      
      default:
        break;
  }
}

/* Here we take the value that we got from the operation and we save 
 * it back either to f or to WREG */
static void write_to_memory(Memory * memory) {
}

static int fetch_Instruction(Code * code, Memory * memory, Bus * bus, u8 clock) {
  /*In the fetch phase the Program Counter (PC) is incremented and 
   * the instruction is put out on to the bus - only in the next 
   * phase it is latched into Instruction Register*/
  switch(code->clock_Cycle) {

    case CLOCK_PC_INC_LATCH_IR:
      memory->program_counter.DATA += 2;
      code->current_Line = memory->program_counter.DATA / 2;
      break;

    case CLOCK_PC_INC_DECODE:
      break;

    case CLOCK_ADDRESS_PROCESS:
      /* The instruction is latched into the data latch after program memory */
      memory->instruction_data_latch = memory->program_memory[code->current_Line];
      break;

    case CLOCK_LATCH_WRITE:
      /* Data latch outputs the instruction onto the bus */
      bus->instruction_Bus = memory->instruction_data_latch;
      break;

    default:
      break;
  }
  return 0;
}

static int execute_Instruction(Code * code, Memory * memory, Bus * bus, u8 clock) {
  /*Instruction from the bus is latched into the Instruction 
   * Register. Next the instruction is decoded and executed over 
   * the next few clock cycles. Data memory is read and written 
   * during execution as well.*/
  switch(code->clock_Cycle) {

    case CLOCK_PC_INC_LATCH_IR:
      memory->instruction_register = read_Instruction_Bus(code, memory, bus);
      break;

    case CLOCK_PC_INC_DECODE:
      decode_memory(memory, code);
      break;

    case CLOCK_ADDRESS_PROCESS:
      execute_instruction(memory);
      break;

    case CLOCK_LATCH_WRITE:
      write_to_memory(memory);
      break;

    default:
      break;
  }
  return 0;
}

static void print_coded_instr(Code * code, Memory * memory, Bus * bus) {

  Program_Word tmp_p;
  WORD_UNION tmp;
  tmp_p = memory->instruction_register;
  tmp.program_word = tmp_p.program_word;
  printf("REGISTER STATE : \n");
  printf("PC : 0x%X, ", memory->program_counter.DATA);
  printf("BSR : %d, ", memory->data_memory[BSR]);
  printf("WREG : %d", memory->data_memory[WREG]);
  printf("\n");
  printf("LAST INSTRUCTION (EXECUTED) : %s, ", code->lines[tmp_p.index].words[0].c_str());
  printf("\n");
  printf("NEXT INSTRUCTION (LOADED) : %s, ", code->lines[read_Instruction_Bus(code, memory, bus).index].words[0].c_str());
  switch(tmp_p.type) {
    default:
      printf("\n");
      break;
  }
}

static u16 data_address(u8 bsr, u8 f) {
  return f + bsr * 0x100;
}

int clk_Pulse(Clock * clock, int period) {
  struct timespec tnow={0,0};
  clock_gettime(CLOCK_MONOTONIC, &tnow);
  long int diff = tnow.tv_nsec + 10e9*tnow.tv_sec - clock->tnow.tv_nsec - 10e9*clock->tnow.tv_sec;
  //printf("time %ld, start %ld diff %ld\n", tnow.tv_nsec, tstart->tv_nsec, diff);
  /* if elapsed time bigger than period send pulse 
   * and update tstart */
  if (diff >= period) {
    clock_gettime(CLOCK_MONOTONIC, &clock->tnow);
    return 1;
  }
  /* else return zero */
  else return 0;
}

int init_Memory(Code * code, Memory * memory, Bus * bus) {
  /* Here we first set the program counter to the base address */
  memory->program_counter.DATA = code->base_address - 2;
  memory->instruction_register.program_word = 0;

  bus->instruction_Bus = {.program_word = 0, .type = ERROR_TYPE};
  bus->data_Bus = 0;

  code->current_Line = memory->program_counter.DATA / 2;
  code->clock_Cycle = 0;

  /* Init data memory banks */
  for(int i = 0 ; i < 64 ; i++) {
    for(int j = 0 ; j < 256 ; j++) {
      memory->data_memory.push_back(0);
    }
  }

  /* Init virtual access bank */
  for(int i = 0 ; i < 256 ; i++) {
    if( i < 96 ) {
      memory->access_bank.data[i] = &memory->data_memory[data_address(5, i)];
    }
    else {
      memory->access_bank.data[i] = &memory->data_memory[data_address(4, i)];
    }
  }

  memory->data_memory[BSR] = 0;

  return 0;
}

int init_Clock(Clock * clock) {
  clock->tnow={0,0};
  clock_gettime(CLOCK_MONOTONIC, &clock->tnow);
  return 0;
}

void machine_State(Code * code, Memory * memory, Bus * bus) {
  /* Possible states are instruction load and 
    * instruction execute */
  // PRINTS FOR DEBUG

  fetch_Instruction(code, memory, bus, code->clock_Cycle);
  execute_Instruction(code, memory, bus, code->clock_Cycle);
  code->clock_Cycle++;
  if(code->clock_Cycle == 4) {
    code->clock_Cycle = 0;
    printf("---------------------------------------------------------\n");
    /* TBD Print register values for debugging purpouses */
    print_coded_instr(code, memory, bus);
  }
}
