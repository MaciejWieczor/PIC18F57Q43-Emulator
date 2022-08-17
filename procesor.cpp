#include <time.h>
#include <stdio.h>

#include "procesor.h"

int clk_Pulse(struct timespec *tstart, int period) {
  struct timespec tnow={0,0};
  clock_gettime(CLOCK_MONOTONIC, &tnow);
  long int diff = tnow.tv_nsec + 10e9*tnow.tv_sec - tstart->tv_nsec - 10e9*tstart->tv_sec;
//  printf("time %ld, start %ld diff %ld\n", tnow.tv_nsec, tstart->tv_nsec, diff);
  /* if elapsed time bigger than period send pulse 
   * and update tstart */
  if (diff >= period) {
    clock_gettime(CLOCK_MONOTONIC, tstart);
    return 1;
  }
  /* else return zero */
  else return 0;
}

int init_Memory(Code * code, Memory * memory) {
  return 0;
}

int load_Instruction(Code * code, Memory * memory) {
  return 0;
}

int execute_Instruction(Code * code, Memory * memory) {
  return 0;
}

int machine_State(int state, int request, Code * code, Memory * memory) {
  /* Possible states are instruction load and 
    * instruction execute */
  int ERR;
  switch (state) {

    case INSTRUCTION_LOAD:
      /* here we load the intruction to the register */
      ERR = load_Instruction(code, memory);
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
