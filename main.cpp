#include<stdio.h>
#include<stdlib.h>

#include "parser.h"
#include "asemblator.h"
#include "procesor.h"

int main(){
  Code code = split_Program_Code("program.txt");
  parse_Code(&code);
  print_Program_Code(code);

  int state = 0;
  int request = 0;
  /* I set the clock to 10e9 nanoseconds for debug */
  int period = 1000000000;
  Memory memory;

  init_Memory(&code, &memory);

  struct timespec tnow={0,0};
  clock_gettime(CLOCK_MONOTONIC, &tnow);

  while(1){
    if(clk_Pulse(&tnow, period)){
      state = machine_State(state, request, &code, &memory);
    }
  }

  return 0;
}
