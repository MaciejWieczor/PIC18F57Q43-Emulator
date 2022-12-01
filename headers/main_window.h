#include "ui_main_window.h"
#include "structs.h"
#include <QFileDialog>
#include <qwt_plot.h>

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
    void RunUntilAddr();
    void RunUntilTime();
    void RunUntilLine();
    void update_LabelTableInstr();
    void update_LabelTableCpu();
    void update_LabelTablePorts();
    void update_LabelTableInt();
    void update_LabelTableInt_Pir();
    void update_LabelTableTmr0();
    void update_LabelTableTmr1();
    void update_LabelTableAdc();
    void update_LabelTableUart();
    void update_LabelTableReturnStack();
    void update_LabelTableFastReturnStack();
    void update_Table();
    void update_Labels();
    void disasm_Highlight();
    void c_line_Highlight();
    void Add_Plot();
    void Add_Bit_Plot();
    void Set_Addr();
    void update_Plots();
    void update_Bit_Plots();
    void update_PlotsInv();
    void update_Bit_PlotsInv();
    void change_Bank_Selected();
    void module_ports();
    void clear_plots();
    void reset();



private:
    Ui::MainWindow ui;
    Code priv_code;
    Memory priv_memory;
    Bus priv_bus;
    int a = 0;
    int bank_selected = 3;
    QString filename = "programs/program.asm";
    int gui_cur_line = 0;
    vector<QwtPlot *> plots;
    vector<QTextEdit *> plot_addrs;
    vector<vector<QPointF>> points;
    int file_loaded = 0;

    int plot_count = 0;
    QwtPlot * bit_plot_axis;
    vector<QwtPlot *> bit_plots;
    vector<QTextEdit *> bit_plot_reg;
    vector<QTextEdit *> bit_plot_bit;
    vector<vector<QPointF>> bit_points;

    long long int reset_plot_value = 0;
};
