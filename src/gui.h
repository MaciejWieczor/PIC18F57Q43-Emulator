#ifndef MYTIMER_H
#define MYTIMER_H

#include "structs.h"
#include "modules.h"
#include "processor.h"
#include "QtCore/QDebug"
#include "QtCore/QTimer"
#include "QtCore/QElapsedTimer"
#include "QtWidgets/QPushButton"
#include "QtWidgets/QApplication"
#include "QtWidgets/QMainWindow"
#include "QtWidgets/QLabel"

class MyTimer : public QObject
{
    Q_OBJECT
public:
    MyTimer(Code * code, Memory * memory, Bus * bus);
    QTimer *timer;
    void myMethod(Code * code, Memory * memory, Bus * bus);
};


class StepButton : public QObject 
{
    Q_OBJECT
public:
    StepButton(Code * code, Memory * memory, Bus * bus);
    QPushButton * button;
    void machine_State_Step(Code * code, Memory * memory, Bus * bus);
};

#endif // MYTIMER_H
