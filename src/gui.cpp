#include "gui.h"
#include "processor.h"

MyTimer::MyTimer(Code * code, Memory * memory, Bus * bus)
{
    // create a timer
    timer = new QTimer(this);

    // setup signal and slot
    connect(timer, &QTimer::timeout,
          this, [=]() { myMethod(code, memory, bus); });

    // msec
    timer->start(250);
}

void MyTimer::myMethod(Code * code, Memory * memory, Bus * bus) {
  machine_State(code, memory, bus);
  module_tmr0(memory, bus);
}

StepButton::StepButton(Code * code, Memory * memory, Bus * bus) {
    button = new QPushButton("AAA");
    connect(button,&QPushButton::clicked, [=]() { machine_State_Step(code, memory, bus); }); 
    button->show();
};

void StepButton::machine_State_Step(Code * code, Memory * memory, Bus * bus) {
  /* Possible states are instruction load and 
    * instruction execute */
  // PRINTS FOR DEBUG

  for(int i = 0 ; i < 4 ; i++) {
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
}
