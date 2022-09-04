#include <time.h>
#include <stdio.h>

#include "procesor.h"

#define CLOCK_PC_INC                0
#define CLOCK_PC_ADDRESS_LATCH      1
#define CLOCK_READ_PROGRAM_MEMORY   2
#define CLOCK_INSTRUCTION_BUS       3
#define CLOCK_LATCH_IR              4
#define CLOCK_DECODE_DIRECT         5
#define CLOCK_DECODE_INDIRECT       6
#define CLOCK_EXECUTE               7

static u16 read_Instruction_Bus(Code * code, Memory * memory, Bus * bus) {
  return bus->instruction_Bus; 
}

static int fetch_Instruction(Code * code, Memory * memory) {
  /*In the fetch phase the Program Counter (PC) is incremented and 
   * the instruction is put out on to the bus - only in the next 
   * phase it is latched into Instruction Register*/
  switch(code->clock_Cycle) {

    case CLOCK_PC_INC:
      memory->program_counter.DATA += 2;
      break;

    case CLOCK_PC_ADDRESS_LATCH:
      break;

    case CLOCK_READ_PROGRAM_MEMORY:
      memory->instruction_data_latch.DATA = code->decoded_lines[memory->program_counter.DATA/2];
      break;

    case CLOCK_INSTRUCTION_BUS:
      break;

    default:
      break;
  }
  return 0;
}

static int execute_Instruction(Code * code, Memory * memory, Bus * bus) {
  /*Instruction from the bus is latched into the Instruction 
   * Register. Next the instruction is decoded and executed over 
   * the next few clock cycles. Data memory is read and written 
   * during execution as well.*/
  switch(code->clock_Cycle) {

    case CLOCK_LATCH_IR:
      memory->instruction_register.DATA = read_Instruction_Bus(code, memory, bus);
      break;

    case CLOCK_DECODE_DIRECT:
      break;

    case CLOCK_DECODE_INDIRECT:
      break;

    case CLOCK_EXECUTE:
      break;

    default:
      break;
  }
  return 0;
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

int init_Memory(Code * code, Memory * memory) {
  memory->program_counter.DATA = 0;
  code->clock_Cycle = 0;
  code->instruction_Cycle = 0;
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
  printf("STATE %d : PC %d | CLOCK %d \n", code->instruction_Cycle, memory->program_counter.DATA, code->clock_Cycle);
  printf("CURRENT LINE OF CODE : ");
  for(string word : code->lines[memory->program_counter.DATA/2].words){
    /*here do some prints */
    cout << word << " ";
  }

  cout << "\n";
  int ERR;

  switch (code->instruction_Cycle) {

    case INSTRUCTION_LOAD:
      /* here we load the intruction to the register */
      ERR = fetch_Instruction(code, memory);
      if(code->clock_Cycle == 3) {
        code->instruction_Cycle = INSTRUCTION_EXECUTE;
        code->clock_Cycle++;
      }
      else code->clock_Cycle++;
      break;

    case INSTRUCTION_EXECUTE:
      /* here we execute the intruction in the memory */
      ERR = execute_Instruction(code, memory, bus);
      if((code->clock_Cycle == 7 && !code->pc_Changed) || code->clock_Cycle == 11) {
        code->instruction_Cycle = INSTRUCTION_LOAD;
        code->clock_Cycle = 0;
      }
      else code->clock_Cycle++;
      break;

    default:
      code->instruction_Cycle = INSTRUCTION_LOAD;
      break;
  }
}
