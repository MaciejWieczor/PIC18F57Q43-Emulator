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

  QApplication app (argc, argv);
  MainWindow ui;
  ui.show();
  return app.exec();

  return 0;
}
