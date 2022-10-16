#include "ui_main_window.h"
#include "structs.h"
#include <QFileDialog>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QMainWindow *parent = nullptr);

private slots:
    void start_emulator();
    void myclicked();
    void openFile();
    void machine_State_Step();
    void update_LabelTableInstr();
    void update_LabelTableCpu();
    void update_LabelTableReturnStack();
    void update_Table();
    void update_Labels();
    void disasm_Highlight();

private:
    Ui::MainWindow ui;
    Code priv_code;
    Memory priv_memory;
    Bus priv_bus;
    int a = 0;
    QString filename = "programs/program2.asm";
    int gui_cur_line = 0;
};
