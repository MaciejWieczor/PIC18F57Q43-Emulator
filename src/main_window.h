#include "ui_main_window.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QMainWindow *parent = nullptr);

private:
    Ui::MainWindow ui;
};
