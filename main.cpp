#include<stdio.h>
#include<stdlib.h>

#include "parser.h"
#include "asemblator.h"
#include "procesor.h"

#define MAIN_CLOCK_PERIOD_NS 2e8

/*
 * Naming conventions : 
 * Code - struct (big first letter)
 * code - variable (small letters)
 * CODE - define (all big letters)
 * code_Function_Name - function (camel case)
 */

int main(){
  Code code = split_Program_Code("program2.asm");
  //print_Program_Code(&code);

  /* I set the clock to 1e9 nanoseconds for debug */
  Memory memory;
  Bus bus;

  init_Memory(&code, &memory, &bus);
  init_Clock(&code.main_clock);
  parse_Code(&code, &memory);
  decode_Lines(&code, &memory, &bus);

  cout << "PROGRAM MEMORY SIZE : " << memory.program_memory.size() << "\n";

  while(1){
    if(clk_Pulse(&code.main_clock, MAIN_CLOCK_PERIOD_NS)){
      machine_State(&code, &memory, &bus);
    }
  }

  return 0;
}
