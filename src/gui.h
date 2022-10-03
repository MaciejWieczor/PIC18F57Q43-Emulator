#ifndef MYTIMER_H
#define MYTIMER_H

#include "QtCore/QDebug"
#include "QtCore/QTimer"
#include "QtWidgets/QPushButton"
#include "QtWidgets/QApplication"
#include "QtWidgets/QMainWindow"

class MyTimer : public QObject
{
    Q_OBJECT
public:
    MyTimer();
    QTimer *timer;

public slots:
    void MyTimerSlot();
};

#endif // MYTIMER_H
