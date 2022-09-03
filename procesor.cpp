#include <time.h>
#include <stdio.h>

#include "procesor.h"

int clk_Pulse(Clock * clock, int period) {
  struct timespec tnow={0,0};
  clock_gettime(CLOCK_MONOTONIC, &tnow);
  long int diff = tnow.tv_nsec + 10e9*tnow.tv_sec - clock->tnow.tv_nsec - 10e9*clock->tnow.tv_sec;
//  printf("time %ld, start %ld diff %ld\n", tnow.tv_nsec, tstart->tv_nsec, diff);
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
  return 0;
}

int init_Clock(Clock * clock) {
  clock->tnow={0,0};
  clock_gettime(CLOCK_MONOTONIC, &clock->tnow);
  return 0;
}

int fetch_Instruction(Code * code, Memory * memory) {
  /*In the fetch phase the Program Counter (PC) is incremented and 
   * the instruction is put out on to the bus - only in the next 
   * phase it is latched into Instruction Register*/
  return 0;
}

int execute_Instruction(Code * code, Memory * memory) {
  /*Instruction from the bus is latched into the Instruction 
   * Register. Next the instruction is decoded and executed over 
   * the next few clock cycles. Data memory is read and written 
   * during execution as well.*/
  return 0;
}

int machine_State(int state, int request, Code * code, Memory * memory) {
  /* Possible states are instruction load and 
    * instruction execute */
  int ERR;
  switch (state) {

    case INSTRUCTION_LOAD:
      /* here we load the intruction to the register */
      ERR = fetch_Instruction(code, memory);
      state = INSTRUCTION_EXECUTE;
      break;

    case INSTRUCTION_EXECUTE:
      /* here we execute the intruction in the memory */
      ERR = execute_Instruction(code, memory);
      state = INSTRUCTION_LOAD;
      break;

    default:
      state = INSTRUCTION_LOAD;
      break;
  }
  printf("STATE %d\n", state);
  return state;
}
