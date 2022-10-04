#include "gui.h"

MyTimer::MyTimer(Code * code, Memory * memory, Bus * bus, Modules * modules)
{
    // create a timer
    timer = new QTimer(this);

    // setup signal and slot
    connect(timer, &QTimer::timeout,
          this, [=]() { myMethod(code, memory, bus, modules); });

    // msec
    timer->start(1000);
}

void MyTimer::myMethod(Code * code, Memory * memory, Bus * bus, Modules * modules) {
  qDebug() << "REEE";
  machine_State(code, memory, bus);
  module_tmr0(modules, bus);
}
