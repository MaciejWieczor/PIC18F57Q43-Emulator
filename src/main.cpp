#include<stdio.h>
#include<stdlib.h>

#include "parser.h"
#include "processor.h"
#include "modules.h"
#include "gui.h"
#include "main_window.h"

#define MAIN_CLOCK_PERIOD_NS 2e8


/*
 * Naming conventions : 
 * Code - struct (big first letter)
 * code - variable (small letters)
 * CODE - define (all big letters)
 * code_Function_Name - function (camel case)
 */

int main(int argc, char *argv[]){
  Code code = split_Program_Code("src/program.asm");
  //print_Program_Code(&code);

  /* I set the clock to 1e9 nanoseconds for debug */
  Memory memory;
  Bus bus;

  init_Memory(&code, &memory, &bus);
  init_Clock(&code.main_clock);
  parse_Code(&code, &memory);
  decode_Lines(&code, &memory, &bus);

  cout << "PROGRAM MEMORY SIZE : " << memory.program_memory.size() << "\n";

  /* TESTING QT WINDOWS */
  QApplication app (argc, argv);
  Ui_MainWindow w;
  w.show();

//  StepButton button(&code, &memory, &bus);
//  MyTimer timer(&code, &memory, &bus);

  return app.exec();

  return 0;
}
