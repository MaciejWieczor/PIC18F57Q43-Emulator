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

class MyTimer : public QObject
{
    Q_OBJECT
public:
    MyTimer(Code * code, Memory * memory, Bus * bus, Modules * modules);
    QTimer *timer;
    void myMethod(Code * code, Memory * memory, Bus * bus, Modules * modules);
};

#endif // MYTIMER_H
