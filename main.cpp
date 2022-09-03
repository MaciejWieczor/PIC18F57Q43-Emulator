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
  int period = 1e9;
  Memory memory;

  init_Memory(&code, &memory);
  init_Clock(&code.main_clock);

  while(1){
    if(clk_Pulse(&code.main_clock, period)){
      state = machine_State(state, request, &code, &memory);
    }
  }

  return 0;
}
