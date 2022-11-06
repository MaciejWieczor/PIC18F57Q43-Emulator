/********************************************************************************
** Form generated from reading UI file 'main_window.ui'
**
** Created by: Qt User Interface Compiler version 5.15.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAIN_WINDOW_H
#define UI_MAIN_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionLoad_File;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_11;
    QVBoxLayout *verticalLayout_10;
    QHBoxLayout *horizontalLayout_11;
    QScrollArea *scrollArea_9;
    QWidget *scrollAreaWidgetContents_9;
    QGridLayout *gridLayout_3;
    QTextBrowser *text_c;
    QScrollArea *scrollArea_10;
    QWidget *text_disasm_scroll;
    QGridLayout *gridLayout_2;
    QTextBrowser *text_disasm;
    QTabWidget *tabs_regs;
    QWidget *tab_cpu;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_6;
    QTableWidget *tableWidget_instr;
    QHBoxLayout *horizontalLayout_5;
    QTableWidget *tableWidget_cpu;
    QTableWidget *tableWidget_ind_stack;
    QWidget *tab_tmr;
    QHBoxLayout *horizontalLayout_9;
    QHBoxLayout *horizontalLayout_13;
    QTableWidget *tableWidget_tmr0;
    QTableWidget *tableWidget_tmr1;
    QWidget *tab_adc;
    QHBoxLayout *horizontalLayout_15;
    QHBoxLayout *horizontalLayout_14;
    QTableWidget *tableWidget_adc0;
    QTableWidget *tableWidget_adc1;
    QWidget *tab_interrupts;
    QHBoxLayout *horizontalLayout_17;
    QHBoxLayout *horizontalLayout_12;
    QTableWidget *tableWidget_int;
    QTableWidget *tableWidget_pir;
    QWidget *tab_;
    QHBoxLayout *horizontalLayout_24;
    QHBoxLayout *horizontalLayout_25;
    QTableWidget *tableWidget_uart_0;
    QTableWidget *tableWidget_uart_1;
    QWidget *tab_ports_pps;
    QHBoxLayout *horizontalLayout_27;
    QHBoxLayout *horizontalLayout_26;
    QTableWidget *tableWidget_ports0;
    QTableWidget *tableWidget_ports1;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_add_plot;
    QPushButton *pushButton_breakpoint_line;
    QTextEdit *textEdit_line_break_addr;
    QPushButton *pushButton_breakpoint;
    QTextEdit *textEdit_addr_break_addr;
    QPushButton *pushButton_start;
    QPushButton *pushButton_disasm;
    QTabWidget *Memory_Tabs;
    QWidget *AccessBank;
    QHBoxLayout *horizontalLayout_10;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_5;
    QTableWidget *tableWidget_frs;
    QTableWidget *return_stack;
    QTableWidget *tableWidget;
    QWidget *tab_8;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QTextEdit *te_set_bank;
    QPushButton *pb_set_bank;
    QVBoxLayout *verticalLayout_3;
    QTableWidget *bank_select_table;
    QWidget *logic_analyzer;
    QVBoxLayout *verticalLayout_8;
    QWidget *verticalWidget_plots;
    QVBoxLayout *verticalLayout_7;
    QWidget *tab_5;
    QHBoxLayout *horizontalLayout_16;
    QVBoxLayout *verticalLayout_9;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *pushButton_porta;
    QTextEdit *textEdit_porta;
    QHBoxLayout *horizontalLayout_20;
    QPushButton *pushButton_portb;
    QTextEdit *textEdit_portb;
    QHBoxLayout *horizontalLayout_18;
    QPushButton *pushButton_portc;
    QTextEdit *textEdit_portc;
    QVBoxLayout *verticalLayout_13;
    QHBoxLayout *horizontalLayout_23;
    QPushButton *pushButton_portd;
    QTextEdit *textEdit_portd;
    QHBoxLayout *horizontalLayout_19;
    QPushButton *pushButton_porte;
    QTextEdit *textEdit_porte;
    QHBoxLayout *horizontalLayout_22;
    QPushButton *pushButton_portf;
    QTextEdit *textEdit_portf;
    QWidget *tab;
    QHBoxLayout *horizontalLayout_29;
    QHBoxLayout *horizontalLayout_28;
    QVBoxLayout *verticalLayout_14;
    QPushButton *pushButton_setaddr;
    QLabel *label_3;
    QTextEdit *textEdit_addr;
    QLabel *label_4;
    QTextEdit *textEdit_value;
    QVBoxLayout *verticalLayout_16;
    QLabel *label;
    QTextBrowser *textBrowser;
    QVBoxLayout *verticalLayout_15;
    QLabel *label_2;
    QTextBrowser *textBrowser_2;
    QVBoxLayout *verticalLayout_18;
    QCheckBox *checkBox;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_5;
    QTextEdit *textEdit;
    QMenuBar *menubar;
    QMenu *menuFile;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1231, 987);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        actionLoad_File = new QAction(MainWindow);
        actionLoad_File->setObjectName(QString::fromUtf8("actionLoad_File"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        verticalLayout_11 = new QVBoxLayout(centralwidget);
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        horizontalLayout_11->setSizeConstraint(QLayout::SetNoConstraint);
        scrollArea_9 = new QScrollArea(centralwidget);
        scrollArea_9->setObjectName(QString::fromUtf8("scrollArea_9"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(scrollArea_9->sizePolicy().hasHeightForWidth());
        scrollArea_9->setSizePolicy(sizePolicy1);
        scrollArea_9->setMinimumSize(QSize(0, 400));
        scrollArea_9->setWidgetResizable(true);
        scrollAreaWidgetContents_9 = new QWidget();
        scrollAreaWidgetContents_9->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_9"));
        scrollAreaWidgetContents_9->setGeometry(QRect(0, 0, 347, 473));
        gridLayout_3 = new QGridLayout(scrollAreaWidgetContents_9);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        text_c = new QTextBrowser(scrollAreaWidgetContents_9);
        text_c->setObjectName(QString::fromUtf8("text_c"));

        gridLayout_3->addWidget(text_c, 1, 0, 1, 1);

        scrollArea_9->setWidget(scrollAreaWidgetContents_9);

        horizontalLayout_11->addWidget(scrollArea_9);

        scrollArea_10 = new QScrollArea(centralwidget);
        scrollArea_10->setObjectName(QString::fromUtf8("scrollArea_10"));
        sizePolicy1.setHeightForWidth(scrollArea_10->sizePolicy().hasHeightForWidth());
        scrollArea_10->setSizePolicy(sizePolicy1);
        scrollArea_10->setWidgetResizable(true);
        text_disasm_scroll = new QWidget();
        text_disasm_scroll->setObjectName(QString::fromUtf8("text_disasm_scroll"));
        text_disasm_scroll->setGeometry(QRect(0, 0, 346, 473));
        gridLayout_2 = new QGridLayout(text_disasm_scroll);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        text_disasm = new QTextBrowser(text_disasm_scroll);
        text_disasm->setObjectName(QString::fromUtf8("text_disasm"));

        gridLayout_2->addWidget(text_disasm, 0, 0, 1, 1);

        scrollArea_10->setWidget(text_disasm_scroll);

        horizontalLayout_11->addWidget(scrollArea_10);

        tabs_regs = new QTabWidget(centralwidget);
        tabs_regs->setObjectName(QString::fromUtf8("tabs_regs"));
        sizePolicy1.setHeightForWidth(tabs_regs->sizePolicy().hasHeightForWidth());
        tabs_regs->setSizePolicy(sizePolicy1);
        tabs_regs->setMinimumSize(QSize(390, 475));
        tabs_regs->setMaximumSize(QSize(500, 16777215));
        tab_cpu = new QWidget();
        tab_cpu->setObjectName(QString::fromUtf8("tab_cpu"));
        sizePolicy1.setHeightForWidth(tab_cpu->sizePolicy().hasHeightForWidth());
        tab_cpu->setSizePolicy(sizePolicy1);
        verticalLayout_4 = new QVBoxLayout(tab_cpu);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setSizeConstraint(QLayout::SetDefaultConstraint);
        tableWidget_instr = new QTableWidget(tab_cpu);
        if (tableWidget_instr->columnCount() < 1)
            tableWidget_instr->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget_instr->setHorizontalHeaderItem(0, __qtablewidgetitem);
        if (tableWidget_instr->rowCount() < 3)
            tableWidget_instr->setRowCount(3);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget_instr->setVerticalHeaderItem(0, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget_instr->setVerticalHeaderItem(1, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget_instr->setVerticalHeaderItem(2, __qtablewidgetitem3);
        tableWidget_instr->setObjectName(QString::fromUtf8("tableWidget_instr"));
        tableWidget_instr->setEnabled(true);
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Ignored);
        sizePolicy2.setHorizontalStretch(1);
        sizePolicy2.setVerticalStretch(1);
        sizePolicy2.setHeightForWidth(tableWidget_instr->sizePolicy().hasHeightForWidth());
        tableWidget_instr->setSizePolicy(sizePolicy2);
        tableWidget_instr->setMinimumSize(QSize(365, 100));
        tableWidget_instr->setBaseSize(QSize(0, 100));
        tableWidget_instr->setRowCount(3);
        tableWidget_instr->setColumnCount(1);
        tableWidget_instr->horizontalHeader()->setDefaultSectionSize(365);
        tableWidget_instr->horizontalHeader()->setStretchLastSection(true);
        tableWidget_instr->verticalHeader()->setDefaultSectionSize(32);
        tableWidget_instr->verticalHeader()->setStretchLastSection(true);

        verticalLayout_6->addWidget(tableWidget_instr);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        tableWidget_cpu = new QTableWidget(tab_cpu);
        if (tableWidget_cpu->columnCount() < 1)
            tableWidget_cpu->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget_cpu->setHorizontalHeaderItem(0, __qtablewidgetitem4);
        if (tableWidget_cpu->rowCount() < 9)
            tableWidget_cpu->setRowCount(9);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget_cpu->setVerticalHeaderItem(0, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget_cpu->setVerticalHeaderItem(1, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget_cpu->setVerticalHeaderItem(2, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget_cpu->setVerticalHeaderItem(3, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget_cpu->setVerticalHeaderItem(4, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget_cpu->setVerticalHeaderItem(5, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget_cpu->setVerticalHeaderItem(6, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget_cpu->setVerticalHeaderItem(7, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidget_cpu->setVerticalHeaderItem(8, __qtablewidgetitem13);
        tableWidget_cpu->setObjectName(QString::fromUtf8("tableWidget_cpu"));
        sizePolicy.setHeightForWidth(tableWidget_cpu->sizePolicy().hasHeightForWidth());
        tableWidget_cpu->setSizePolicy(sizePolicy);
        tableWidget_cpu->setMinimumSize(QSize(177, 210));
        tableWidget_cpu->horizontalHeader()->setMinimumSectionSize(50);
        tableWidget_cpu->horizontalHeader()->setDefaultSectionSize(165);
        tableWidget_cpu->horizontalHeader()->setStretchLastSection(true);
        tableWidget_cpu->verticalHeader()->setDefaultSectionSize(30);
        tableWidget_cpu->verticalHeader()->setStretchLastSection(true);

        horizontalLayout_5->addWidget(tableWidget_cpu);

        tableWidget_ind_stack = new QTableWidget(tab_cpu);
        if (tableWidget_ind_stack->columnCount() < 1)
            tableWidget_ind_stack->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableWidget_ind_stack->setHorizontalHeaderItem(0, __qtablewidgetitem14);
        if (tableWidget_ind_stack->rowCount() < 9)
            tableWidget_ind_stack->setRowCount(9);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableWidget_ind_stack->setVerticalHeaderItem(0, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tableWidget_ind_stack->setVerticalHeaderItem(1, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tableWidget_ind_stack->setVerticalHeaderItem(2, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        tableWidget_ind_stack->setVerticalHeaderItem(3, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        tableWidget_ind_stack->setVerticalHeaderItem(4, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        tableWidget_ind_stack->setVerticalHeaderItem(5, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        tableWidget_ind_stack->setVerticalHeaderItem(6, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        tableWidget_ind_stack->setVerticalHeaderItem(7, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        tableWidget_ind_stack->setVerticalHeaderItem(8, __qtablewidgetitem23);
        tableWidget_ind_stack->setObjectName(QString::fromUtf8("tableWidget_ind_stack"));
        sizePolicy.setHeightForWidth(tableWidget_ind_stack->sizePolicy().hasHeightForWidth());
        tableWidget_ind_stack->setSizePolicy(sizePolicy);
        tableWidget_ind_stack->setMinimumSize(QSize(177, 0));
        tableWidget_ind_stack->horizontalHeader()->setCascadingSectionResizes(false);
        tableWidget_ind_stack->horizontalHeader()->setDefaultSectionSize(165);
        tableWidget_ind_stack->horizontalHeader()->setStretchLastSection(true);
        tableWidget_ind_stack->verticalHeader()->setCascadingSectionResizes(false);
        tableWidget_ind_stack->verticalHeader()->setStretchLastSection(true);

        horizontalLayout_5->addWidget(tableWidget_ind_stack);


        verticalLayout_6->addLayout(horizontalLayout_5);

        verticalLayout_6->setStretch(0, 4);
        verticalLayout_6->setStretch(1, 10);

        verticalLayout_4->addLayout(verticalLayout_6);

        tabs_regs->addTab(tab_cpu, QString());
        tab_tmr = new QWidget();
        tab_tmr->setObjectName(QString::fromUtf8("tab_tmr"));
        horizontalLayout_9 = new QHBoxLayout(tab_tmr);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        tableWidget_tmr0 = new QTableWidget(tab_tmr);
        if (tableWidget_tmr0->columnCount() < 1)
            tableWidget_tmr0->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        tableWidget_tmr0->setHorizontalHeaderItem(0, __qtablewidgetitem24);
        if (tableWidget_tmr0->rowCount() < 12)
            tableWidget_tmr0->setRowCount(12);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        tableWidget_tmr0->setVerticalHeaderItem(0, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        tableWidget_tmr0->setVerticalHeaderItem(1, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        tableWidget_tmr0->setVerticalHeaderItem(2, __qtablewidgetitem27);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        tableWidget_tmr0->setVerticalHeaderItem(3, __qtablewidgetitem28);
        QTableWidgetItem *__qtablewidgetitem29 = new QTableWidgetItem();
        tableWidget_tmr0->setVerticalHeaderItem(4, __qtablewidgetitem29);
        QTableWidgetItem *__qtablewidgetitem30 = new QTableWidgetItem();
        tableWidget_tmr0->setVerticalHeaderItem(5, __qtablewidgetitem30);
        QTableWidgetItem *__qtablewidgetitem31 = new QTableWidgetItem();
        tableWidget_tmr0->setVerticalHeaderItem(6, __qtablewidgetitem31);
        QTableWidgetItem *__qtablewidgetitem32 = new QTableWidgetItem();
        tableWidget_tmr0->setVerticalHeaderItem(7, __qtablewidgetitem32);
        QTableWidgetItem *__qtablewidgetitem33 = new QTableWidgetItem();
        tableWidget_tmr0->setVerticalHeaderItem(8, __qtablewidgetitem33);
        QTableWidgetItem *__qtablewidgetitem34 = new QTableWidgetItem();
        tableWidget_tmr0->setVerticalHeaderItem(9, __qtablewidgetitem34);
        QTableWidgetItem *__qtablewidgetitem35 = new QTableWidgetItem();
        tableWidget_tmr0->setVerticalHeaderItem(10, __qtablewidgetitem35);
        QTableWidgetItem *__qtablewidgetitem36 = new QTableWidgetItem();
        tableWidget_tmr0->setVerticalHeaderItem(11, __qtablewidgetitem36);
        tableWidget_tmr0->setObjectName(QString::fromUtf8("tableWidget_tmr0"));
        sizePolicy1.setHeightForWidth(tableWidget_tmr0->sizePolicy().hasHeightForWidth());
        tableWidget_tmr0->setSizePolicy(sizePolicy1);
        tableWidget_tmr0->setMinimumSize(QSize(177, 210));
        tableWidget_tmr0->horizontalHeader()->setMinimumSectionSize(50);
        tableWidget_tmr0->horizontalHeader()->setDefaultSectionSize(165);
        tableWidget_tmr0->verticalHeader()->setDefaultSectionSize(30);

        horizontalLayout_13->addWidget(tableWidget_tmr0);

        tableWidget_tmr1 = new QTableWidget(tab_tmr);
        if (tableWidget_tmr1->columnCount() < 1)
            tableWidget_tmr1->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem37 = new QTableWidgetItem();
        tableWidget_tmr1->setHorizontalHeaderItem(0, __qtablewidgetitem37);
        if (tableWidget_tmr1->rowCount() < 16)
            tableWidget_tmr1->setRowCount(16);
        QTableWidgetItem *__qtablewidgetitem38 = new QTableWidgetItem();
        tableWidget_tmr1->setVerticalHeaderItem(0, __qtablewidgetitem38);
        QTableWidgetItem *__qtablewidgetitem39 = new QTableWidgetItem();
        tableWidget_tmr1->setVerticalHeaderItem(1, __qtablewidgetitem39);
        QTableWidgetItem *__qtablewidgetitem40 = new QTableWidgetItem();
        tableWidget_tmr1->setVerticalHeaderItem(2, __qtablewidgetitem40);
        QTableWidgetItem *__qtablewidgetitem41 = new QTableWidgetItem();
        tableWidget_tmr1->setVerticalHeaderItem(3, __qtablewidgetitem41);
        QTableWidgetItem *__qtablewidgetitem42 = new QTableWidgetItem();
        tableWidget_tmr1->setVerticalHeaderItem(4, __qtablewidgetitem42);
        QTableWidgetItem *__qtablewidgetitem43 = new QTableWidgetItem();
        tableWidget_tmr1->setVerticalHeaderItem(5, __qtablewidgetitem43);
        QTableWidgetItem *__qtablewidgetitem44 = new QTableWidgetItem();
        tableWidget_tmr1->setVerticalHeaderItem(6, __qtablewidgetitem44);
        QTableWidgetItem *__qtablewidgetitem45 = new QTableWidgetItem();
        tableWidget_tmr1->setVerticalHeaderItem(7, __qtablewidgetitem45);
        QTableWidgetItem *__qtablewidgetitem46 = new QTableWidgetItem();
        tableWidget_tmr1->setVerticalHeaderItem(8, __qtablewidgetitem46);
        QTableWidgetItem *__qtablewidgetitem47 = new QTableWidgetItem();
        tableWidget_tmr1->setVerticalHeaderItem(9, __qtablewidgetitem47);
        QTableWidgetItem *__qtablewidgetitem48 = new QTableWidgetItem();
        tableWidget_tmr1->setVerticalHeaderItem(10, __qtablewidgetitem48);
        QTableWidgetItem *__qtablewidgetitem49 = new QTableWidgetItem();
        tableWidget_tmr1->setVerticalHeaderItem(11, __qtablewidgetitem49);
        QTableWidgetItem *__qtablewidgetitem50 = new QTableWidgetItem();
        tableWidget_tmr1->setVerticalHeaderItem(12, __qtablewidgetitem50);
        QTableWidgetItem *__qtablewidgetitem51 = new QTableWidgetItem();
        tableWidget_tmr1->setVerticalHeaderItem(13, __qtablewidgetitem51);
        QTableWidgetItem *__qtablewidgetitem52 = new QTableWidgetItem();
        tableWidget_tmr1->setVerticalHeaderItem(14, __qtablewidgetitem52);
        QTableWidgetItem *__qtablewidgetitem53 = new QTableWidgetItem();
        tableWidget_tmr1->setVerticalHeaderItem(15, __qtablewidgetitem53);
        tableWidget_tmr1->setObjectName(QString::fromUtf8("tableWidget_tmr1"));
        sizePolicy1.setHeightForWidth(tableWidget_tmr1->sizePolicy().hasHeightForWidth());
        tableWidget_tmr1->setSizePolicy(sizePolicy1);
        tableWidget_tmr1->setMinimumSize(QSize(177, 0));
        tableWidget_tmr1->horizontalHeader()->setDefaultSectionSize(165);

        horizontalLayout_13->addWidget(tableWidget_tmr1);


        horizontalLayout_9->addLayout(horizontalLayout_13);

        tabs_regs->addTab(tab_tmr, QString());
        tab_adc = new QWidget();
        tab_adc->setObjectName(QString::fromUtf8("tab_adc"));
        horizontalLayout_15 = new QHBoxLayout(tab_adc);
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        tableWidget_adc0 = new QTableWidget(tab_adc);
        if (tableWidget_adc0->columnCount() < 1)
            tableWidget_adc0->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem54 = new QTableWidgetItem();
        tableWidget_adc0->setHorizontalHeaderItem(0, __qtablewidgetitem54);
        if (tableWidget_adc0->rowCount() < 16)
            tableWidget_adc0->setRowCount(16);
        QTableWidgetItem *__qtablewidgetitem55 = new QTableWidgetItem();
        tableWidget_adc0->setVerticalHeaderItem(0, __qtablewidgetitem55);
        QTableWidgetItem *__qtablewidgetitem56 = new QTableWidgetItem();
        tableWidget_adc0->setVerticalHeaderItem(1, __qtablewidgetitem56);
        QTableWidgetItem *__qtablewidgetitem57 = new QTableWidgetItem();
        tableWidget_adc0->setVerticalHeaderItem(2, __qtablewidgetitem57);
        QTableWidgetItem *__qtablewidgetitem58 = new QTableWidgetItem();
        tableWidget_adc0->setVerticalHeaderItem(3, __qtablewidgetitem58);
        QTableWidgetItem *__qtablewidgetitem59 = new QTableWidgetItem();
        tableWidget_adc0->setVerticalHeaderItem(4, __qtablewidgetitem59);
        QTableWidgetItem *__qtablewidgetitem60 = new QTableWidgetItem();
        tableWidget_adc0->setVerticalHeaderItem(5, __qtablewidgetitem60);
        QTableWidgetItem *__qtablewidgetitem61 = new QTableWidgetItem();
        tableWidget_adc0->setVerticalHeaderItem(6, __qtablewidgetitem61);
        QTableWidgetItem *__qtablewidgetitem62 = new QTableWidgetItem();
        tableWidget_adc0->setVerticalHeaderItem(7, __qtablewidgetitem62);
        QTableWidgetItem *__qtablewidgetitem63 = new QTableWidgetItem();
        tableWidget_adc0->setVerticalHeaderItem(8, __qtablewidgetitem63);
        QTableWidgetItem *__qtablewidgetitem64 = new QTableWidgetItem();
        tableWidget_adc0->setVerticalHeaderItem(9, __qtablewidgetitem64);
        QTableWidgetItem *__qtablewidgetitem65 = new QTableWidgetItem();
        tableWidget_adc0->setVerticalHeaderItem(10, __qtablewidgetitem65);
        QTableWidgetItem *__qtablewidgetitem66 = new QTableWidgetItem();
        tableWidget_adc0->setVerticalHeaderItem(11, __qtablewidgetitem66);
        QTableWidgetItem *__qtablewidgetitem67 = new QTableWidgetItem();
        tableWidget_adc0->setVerticalHeaderItem(12, __qtablewidgetitem67);
        QTableWidgetItem *__qtablewidgetitem68 = new QTableWidgetItem();
        tableWidget_adc0->setVerticalHeaderItem(13, __qtablewidgetitem68);
        QTableWidgetItem *__qtablewidgetitem69 = new QTableWidgetItem();
        tableWidget_adc0->setVerticalHeaderItem(14, __qtablewidgetitem69);
        QTableWidgetItem *__qtablewidgetitem70 = new QTableWidgetItem();
        tableWidget_adc0->setVerticalHeaderItem(15, __qtablewidgetitem70);
        tableWidget_adc0->setObjectName(QString::fromUtf8("tableWidget_adc0"));
        sizePolicy1.setHeightForWidth(tableWidget_adc0->sizePolicy().hasHeightForWidth());
        tableWidget_adc0->setSizePolicy(sizePolicy1);
        tableWidget_adc0->setMinimumSize(QSize(177, 210));
        tableWidget_adc0->horizontalHeader()->setMinimumSectionSize(50);
        tableWidget_adc0->horizontalHeader()->setDefaultSectionSize(165);
        tableWidget_adc0->horizontalHeader()->setStretchLastSection(true);
        tableWidget_adc0->verticalHeader()->setDefaultSectionSize(30);

        horizontalLayout_14->addWidget(tableWidget_adc0);

        tableWidget_adc1 = new QTableWidget(tab_adc);
        if (tableWidget_adc1->columnCount() < 1)
            tableWidget_adc1->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem71 = new QTableWidgetItem();
        tableWidget_adc1->setHorizontalHeaderItem(0, __qtablewidgetitem71);
        if (tableWidget_adc1->rowCount() < 11)
            tableWidget_adc1->setRowCount(11);
        QTableWidgetItem *__qtablewidgetitem72 = new QTableWidgetItem();
        tableWidget_adc1->setVerticalHeaderItem(0, __qtablewidgetitem72);
        QTableWidgetItem *__qtablewidgetitem73 = new QTableWidgetItem();
        tableWidget_adc1->setVerticalHeaderItem(1, __qtablewidgetitem73);
        QTableWidgetItem *__qtablewidgetitem74 = new QTableWidgetItem();
        tableWidget_adc1->setVerticalHeaderItem(2, __qtablewidgetitem74);
        QTableWidgetItem *__qtablewidgetitem75 = new QTableWidgetItem();
        tableWidget_adc1->setVerticalHeaderItem(3, __qtablewidgetitem75);
        QTableWidgetItem *__qtablewidgetitem76 = new QTableWidgetItem();
        tableWidget_adc1->setVerticalHeaderItem(4, __qtablewidgetitem76);
        QTableWidgetItem *__qtablewidgetitem77 = new QTableWidgetItem();
        tableWidget_adc1->setVerticalHeaderItem(5, __qtablewidgetitem77);
        QTableWidgetItem *__qtablewidgetitem78 = new QTableWidgetItem();
        tableWidget_adc1->setVerticalHeaderItem(6, __qtablewidgetitem78);
        QTableWidgetItem *__qtablewidgetitem79 = new QTableWidgetItem();
        tableWidget_adc1->setVerticalHeaderItem(7, __qtablewidgetitem79);
        QTableWidgetItem *__qtablewidgetitem80 = new QTableWidgetItem();
        tableWidget_adc1->setVerticalHeaderItem(8, __qtablewidgetitem80);
        QTableWidgetItem *__qtablewidgetitem81 = new QTableWidgetItem();
        tableWidget_adc1->setVerticalHeaderItem(9, __qtablewidgetitem81);
        QTableWidgetItem *__qtablewidgetitem82 = new QTableWidgetItem();
        tableWidget_adc1->setVerticalHeaderItem(10, __qtablewidgetitem82);
        tableWidget_adc1->setObjectName(QString::fromUtf8("tableWidget_adc1"));
        sizePolicy1.setHeightForWidth(tableWidget_adc1->sizePolicy().hasHeightForWidth());
        tableWidget_adc1->setSizePolicy(sizePolicy1);
        tableWidget_adc1->setMinimumSize(QSize(177, 0));
        tableWidget_adc1->horizontalHeader()->setDefaultSectionSize(165);
        tableWidget_adc1->horizontalHeader()->setStretchLastSection(true);

        horizontalLayout_14->addWidget(tableWidget_adc1);


        horizontalLayout_15->addLayout(horizontalLayout_14);

        tabs_regs->addTab(tab_adc, QString());
        tab_interrupts = new QWidget();
        tab_interrupts->setObjectName(QString::fromUtf8("tab_interrupts"));
        horizontalLayout_17 = new QHBoxLayout(tab_interrupts);
        horizontalLayout_17->setObjectName(QString::fromUtf8("horizontalLayout_17"));
        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        tableWidget_int = new QTableWidget(tab_interrupts);
        if (tableWidget_int->columnCount() < 1)
            tableWidget_int->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem83 = new QTableWidgetItem();
        tableWidget_int->setHorizontalHeaderItem(0, __qtablewidgetitem83);
        if (tableWidget_int->rowCount() < 10)
            tableWidget_int->setRowCount(10);
        QTableWidgetItem *__qtablewidgetitem84 = new QTableWidgetItem();
        tableWidget_int->setVerticalHeaderItem(0, __qtablewidgetitem84);
        QTableWidgetItem *__qtablewidgetitem85 = new QTableWidgetItem();
        tableWidget_int->setVerticalHeaderItem(1, __qtablewidgetitem85);
        QTableWidgetItem *__qtablewidgetitem86 = new QTableWidgetItem();
        tableWidget_int->setVerticalHeaderItem(2, __qtablewidgetitem86);
        QTableWidgetItem *__qtablewidgetitem87 = new QTableWidgetItem();
        tableWidget_int->setVerticalHeaderItem(3, __qtablewidgetitem87);
        QTableWidgetItem *__qtablewidgetitem88 = new QTableWidgetItem();
        tableWidget_int->setVerticalHeaderItem(4, __qtablewidgetitem88);
        QTableWidgetItem *__qtablewidgetitem89 = new QTableWidgetItem();
        tableWidget_int->setVerticalHeaderItem(5, __qtablewidgetitem89);
        QTableWidgetItem *__qtablewidgetitem90 = new QTableWidgetItem();
        tableWidget_int->setVerticalHeaderItem(6, __qtablewidgetitem90);
        QTableWidgetItem *__qtablewidgetitem91 = new QTableWidgetItem();
        tableWidget_int->setVerticalHeaderItem(7, __qtablewidgetitem91);
        QTableWidgetItem *__qtablewidgetitem92 = new QTableWidgetItem();
        tableWidget_int->setVerticalHeaderItem(8, __qtablewidgetitem92);
        QTableWidgetItem *__qtablewidgetitem93 = new QTableWidgetItem();
        tableWidget_int->setVerticalHeaderItem(9, __qtablewidgetitem93);
        tableWidget_int->setObjectName(QString::fromUtf8("tableWidget_int"));
        sizePolicy1.setHeightForWidth(tableWidget_int->sizePolicy().hasHeightForWidth());
        tableWidget_int->setSizePolicy(sizePolicy1);
        tableWidget_int->setMinimumSize(QSize(177, 210));
        tableWidget_int->horizontalHeader()->setMinimumSectionSize(50);
        tableWidget_int->horizontalHeader()->setDefaultSectionSize(165);
        tableWidget_int->verticalHeader()->setDefaultSectionSize(30);

        horizontalLayout_12->addWidget(tableWidget_int);

        tableWidget_pir = new QTableWidget(tab_interrupts);
        if (tableWidget_pir->columnCount() < 3)
            tableWidget_pir->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem94 = new QTableWidgetItem();
        tableWidget_pir->setHorizontalHeaderItem(0, __qtablewidgetitem94);
        QTableWidgetItem *__qtablewidgetitem95 = new QTableWidgetItem();
        tableWidget_pir->setHorizontalHeaderItem(1, __qtablewidgetitem95);
        QTableWidgetItem *__qtablewidgetitem96 = new QTableWidgetItem();
        tableWidget_pir->setHorizontalHeaderItem(2, __qtablewidgetitem96);
        if (tableWidget_pir->rowCount() < 13)
            tableWidget_pir->setRowCount(13);
        QTableWidgetItem *__qtablewidgetitem97 = new QTableWidgetItem();
        tableWidget_pir->setVerticalHeaderItem(0, __qtablewidgetitem97);
        QTableWidgetItem *__qtablewidgetitem98 = new QTableWidgetItem();
        tableWidget_pir->setVerticalHeaderItem(1, __qtablewidgetitem98);
        QTableWidgetItem *__qtablewidgetitem99 = new QTableWidgetItem();
        tableWidget_pir->setVerticalHeaderItem(2, __qtablewidgetitem99);
        QTableWidgetItem *__qtablewidgetitem100 = new QTableWidgetItem();
        tableWidget_pir->setVerticalHeaderItem(3, __qtablewidgetitem100);
        QTableWidgetItem *__qtablewidgetitem101 = new QTableWidgetItem();
        tableWidget_pir->setVerticalHeaderItem(4, __qtablewidgetitem101);
        QTableWidgetItem *__qtablewidgetitem102 = new QTableWidgetItem();
        tableWidget_pir->setVerticalHeaderItem(5, __qtablewidgetitem102);
        QTableWidgetItem *__qtablewidgetitem103 = new QTableWidgetItem();
        tableWidget_pir->setVerticalHeaderItem(6, __qtablewidgetitem103);
        QTableWidgetItem *__qtablewidgetitem104 = new QTableWidgetItem();
        tableWidget_pir->setVerticalHeaderItem(7, __qtablewidgetitem104);
        QTableWidgetItem *__qtablewidgetitem105 = new QTableWidgetItem();
        tableWidget_pir->setVerticalHeaderItem(8, __qtablewidgetitem105);
        QTableWidgetItem *__qtablewidgetitem106 = new QTableWidgetItem();
        tableWidget_pir->setVerticalHeaderItem(9, __qtablewidgetitem106);
        QTableWidgetItem *__qtablewidgetitem107 = new QTableWidgetItem();
        tableWidget_pir->setVerticalHeaderItem(10, __qtablewidgetitem107);
        QTableWidgetItem *__qtablewidgetitem108 = new QTableWidgetItem();
        tableWidget_pir->setVerticalHeaderItem(11, __qtablewidgetitem108);
        QTableWidgetItem *__qtablewidgetitem109 = new QTableWidgetItem();
        tableWidget_pir->setVerticalHeaderItem(12, __qtablewidgetitem109);
        tableWidget_pir->setObjectName(QString::fromUtf8("tableWidget_pir"));
        sizePolicy1.setHeightForWidth(tableWidget_pir->sizePolicy().hasHeightForWidth());
        tableWidget_pir->setSizePolicy(sizePolicy1);
        tableWidget_pir->setMinimumSize(QSize(177, 0));
        tableWidget_pir->horizontalHeader()->setDefaultSectionSize(70);
        tableWidget_pir->horizontalHeader()->setStretchLastSection(true);
        tableWidget_pir->verticalHeader()->setStretchLastSection(true);

        horizontalLayout_12->addWidget(tableWidget_pir);


        horizontalLayout_17->addLayout(horizontalLayout_12);

        tabs_regs->addTab(tab_interrupts, QString());
        tab_ = new QWidget();
        tab_->setObjectName(QString::fromUtf8("tab_"));
        horizontalLayout_24 = new QHBoxLayout(tab_);
        horizontalLayout_24->setObjectName(QString::fromUtf8("horizontalLayout_24"));
        horizontalLayout_25 = new QHBoxLayout();
        horizontalLayout_25->setObjectName(QString::fromUtf8("horizontalLayout_25"));
        tableWidget_uart_0 = new QTableWidget(tab_);
        if (tableWidget_uart_0->columnCount() < 1)
            tableWidget_uart_0->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem110 = new QTableWidgetItem();
        tableWidget_uart_0->setHorizontalHeaderItem(0, __qtablewidgetitem110);
        if (tableWidget_uart_0->rowCount() < 15)
            tableWidget_uart_0->setRowCount(15);
        QTableWidgetItem *__qtablewidgetitem111 = new QTableWidgetItem();
        tableWidget_uart_0->setVerticalHeaderItem(0, __qtablewidgetitem111);
        QTableWidgetItem *__qtablewidgetitem112 = new QTableWidgetItem();
        tableWidget_uart_0->setVerticalHeaderItem(1, __qtablewidgetitem112);
        QTableWidgetItem *__qtablewidgetitem113 = new QTableWidgetItem();
        tableWidget_uart_0->setVerticalHeaderItem(2, __qtablewidgetitem113);
        QTableWidgetItem *__qtablewidgetitem114 = new QTableWidgetItem();
        tableWidget_uart_0->setVerticalHeaderItem(3, __qtablewidgetitem114);
        QTableWidgetItem *__qtablewidgetitem115 = new QTableWidgetItem();
        tableWidget_uart_0->setVerticalHeaderItem(4, __qtablewidgetitem115);
        QTableWidgetItem *__qtablewidgetitem116 = new QTableWidgetItem();
        tableWidget_uart_0->setVerticalHeaderItem(5, __qtablewidgetitem116);
        QTableWidgetItem *__qtablewidgetitem117 = new QTableWidgetItem();
        tableWidget_uart_0->setVerticalHeaderItem(6, __qtablewidgetitem117);
        QTableWidgetItem *__qtablewidgetitem118 = new QTableWidgetItem();
        tableWidget_uart_0->setVerticalHeaderItem(7, __qtablewidgetitem118);
        QTableWidgetItem *__qtablewidgetitem119 = new QTableWidgetItem();
        tableWidget_uart_0->setVerticalHeaderItem(8, __qtablewidgetitem119);
        QTableWidgetItem *__qtablewidgetitem120 = new QTableWidgetItem();
        tableWidget_uart_0->setVerticalHeaderItem(9, __qtablewidgetitem120);
        QTableWidgetItem *__qtablewidgetitem121 = new QTableWidgetItem();
        tableWidget_uart_0->setVerticalHeaderItem(10, __qtablewidgetitem121);
        QTableWidgetItem *__qtablewidgetitem122 = new QTableWidgetItem();
        tableWidget_uart_0->setVerticalHeaderItem(11, __qtablewidgetitem122);
        QTableWidgetItem *__qtablewidgetitem123 = new QTableWidgetItem();
        tableWidget_uart_0->setVerticalHeaderItem(12, __qtablewidgetitem123);
        QTableWidgetItem *__qtablewidgetitem124 = new QTableWidgetItem();
        tableWidget_uart_0->setVerticalHeaderItem(13, __qtablewidgetitem124);
        QTableWidgetItem *__qtablewidgetitem125 = new QTableWidgetItem();
        tableWidget_uart_0->setVerticalHeaderItem(14, __qtablewidgetitem125);
        tableWidget_uart_0->setObjectName(QString::fromUtf8("tableWidget_uart_0"));
        sizePolicy1.setHeightForWidth(tableWidget_uart_0->sizePolicy().hasHeightForWidth());
        tableWidget_uart_0->setSizePolicy(sizePolicy1);
        tableWidget_uart_0->setMinimumSize(QSize(177, 210));
        tableWidget_uart_0->horizontalHeader()->setMinimumSectionSize(50);
        tableWidget_uart_0->horizontalHeader()->setDefaultSectionSize(165);
        tableWidget_uart_0->horizontalHeader()->setStretchLastSection(true);
        tableWidget_uart_0->verticalHeader()->setDefaultSectionSize(30);

        horizontalLayout_25->addWidget(tableWidget_uart_0);

        tableWidget_uart_1 = new QTableWidget(tab_);
        if (tableWidget_uart_1->columnCount() < 1)
            tableWidget_uart_1->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem126 = new QTableWidgetItem();
        tableWidget_uart_1->setHorizontalHeaderItem(0, __qtablewidgetitem126);
        if (tableWidget_uart_1->rowCount() < 16)
            tableWidget_uart_1->setRowCount(16);
        QTableWidgetItem *__qtablewidgetitem127 = new QTableWidgetItem();
        tableWidget_uart_1->setVerticalHeaderItem(0, __qtablewidgetitem127);
        QTableWidgetItem *__qtablewidgetitem128 = new QTableWidgetItem();
        tableWidget_uart_1->setVerticalHeaderItem(1, __qtablewidgetitem128);
        QTableWidgetItem *__qtablewidgetitem129 = new QTableWidgetItem();
        tableWidget_uart_1->setVerticalHeaderItem(2, __qtablewidgetitem129);
        QTableWidgetItem *__qtablewidgetitem130 = new QTableWidgetItem();
        tableWidget_uart_1->setVerticalHeaderItem(3, __qtablewidgetitem130);
        QTableWidgetItem *__qtablewidgetitem131 = new QTableWidgetItem();
        tableWidget_uart_1->setVerticalHeaderItem(4, __qtablewidgetitem131);
        QTableWidgetItem *__qtablewidgetitem132 = new QTableWidgetItem();
        tableWidget_uart_1->setVerticalHeaderItem(5, __qtablewidgetitem132);
        QTableWidgetItem *__qtablewidgetitem133 = new QTableWidgetItem();
        tableWidget_uart_1->setVerticalHeaderItem(6, __qtablewidgetitem133);
        QTableWidgetItem *__qtablewidgetitem134 = new QTableWidgetItem();
        tableWidget_uart_1->setVerticalHeaderItem(7, __qtablewidgetitem134);
        QTableWidgetItem *__qtablewidgetitem135 = new QTableWidgetItem();
        tableWidget_uart_1->setVerticalHeaderItem(8, __qtablewidgetitem135);
        QTableWidgetItem *__qtablewidgetitem136 = new QTableWidgetItem();
        tableWidget_uart_1->setVerticalHeaderItem(9, __qtablewidgetitem136);
        QTableWidgetItem *__qtablewidgetitem137 = new QTableWidgetItem();
        tableWidget_uart_1->setVerticalHeaderItem(10, __qtablewidgetitem137);
        QTableWidgetItem *__qtablewidgetitem138 = new QTableWidgetItem();
        tableWidget_uart_1->setVerticalHeaderItem(11, __qtablewidgetitem138);
        QTableWidgetItem *__qtablewidgetitem139 = new QTableWidgetItem();
        tableWidget_uart_1->setVerticalHeaderItem(12, __qtablewidgetitem139);
        QTableWidgetItem *__qtablewidgetitem140 = new QTableWidgetItem();
        tableWidget_uart_1->setVerticalHeaderItem(13, __qtablewidgetitem140);
        QTableWidgetItem *__qtablewidgetitem141 = new QTableWidgetItem();
        tableWidget_uart_1->setVerticalHeaderItem(14, __qtablewidgetitem141);
        QTableWidgetItem *__qtablewidgetitem142 = new QTableWidgetItem();
        tableWidget_uart_1->setVerticalHeaderItem(15, __qtablewidgetitem142);
        tableWidget_uart_1->setObjectName(QString::fromUtf8("tableWidget_uart_1"));
        sizePolicy1.setHeightForWidth(tableWidget_uart_1->sizePolicy().hasHeightForWidth());
        tableWidget_uart_1->setSizePolicy(sizePolicy1);
        tableWidget_uart_1->setMinimumSize(QSize(177, 0));
        tableWidget_uart_1->horizontalHeader()->setDefaultSectionSize(165);
        tableWidget_uart_1->horizontalHeader()->setStretchLastSection(true);

        horizontalLayout_25->addWidget(tableWidget_uart_1);


        horizontalLayout_24->addLayout(horizontalLayout_25);

        tabs_regs->addTab(tab_, QString());
        tab_ports_pps = new QWidget();
        tab_ports_pps->setObjectName(QString::fromUtf8("tab_ports_pps"));
        horizontalLayout_27 = new QHBoxLayout(tab_ports_pps);
        horizontalLayout_27->setObjectName(QString::fromUtf8("horizontalLayout_27"));
        horizontalLayout_26 = new QHBoxLayout();
        horizontalLayout_26->setObjectName(QString::fromUtf8("horizontalLayout_26"));
        tableWidget_ports0 = new QTableWidget(tab_ports_pps);
        if (tableWidget_ports0->columnCount() < 1)
            tableWidget_ports0->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem143 = new QTableWidgetItem();
        tableWidget_ports0->setHorizontalHeaderItem(0, __qtablewidgetitem143);
        if (tableWidget_ports0->rowCount() < 12)
            tableWidget_ports0->setRowCount(12);
        QTableWidgetItem *__qtablewidgetitem144 = new QTableWidgetItem();
        tableWidget_ports0->setVerticalHeaderItem(0, __qtablewidgetitem144);
        QTableWidgetItem *__qtablewidgetitem145 = new QTableWidgetItem();
        tableWidget_ports0->setVerticalHeaderItem(1, __qtablewidgetitem145);
        QTableWidgetItem *__qtablewidgetitem146 = new QTableWidgetItem();
        tableWidget_ports0->setVerticalHeaderItem(2, __qtablewidgetitem146);
        QTableWidgetItem *__qtablewidgetitem147 = new QTableWidgetItem();
        tableWidget_ports0->setVerticalHeaderItem(3, __qtablewidgetitem147);
        QTableWidgetItem *__qtablewidgetitem148 = new QTableWidgetItem();
        tableWidget_ports0->setVerticalHeaderItem(4, __qtablewidgetitem148);
        QTableWidgetItem *__qtablewidgetitem149 = new QTableWidgetItem();
        tableWidget_ports0->setVerticalHeaderItem(5, __qtablewidgetitem149);
        QTableWidgetItem *__qtablewidgetitem150 = new QTableWidgetItem();
        tableWidget_ports0->setVerticalHeaderItem(6, __qtablewidgetitem150);
        QTableWidgetItem *__qtablewidgetitem151 = new QTableWidgetItem();
        tableWidget_ports0->setVerticalHeaderItem(7, __qtablewidgetitem151);
        QTableWidgetItem *__qtablewidgetitem152 = new QTableWidgetItem();
        tableWidget_ports0->setVerticalHeaderItem(8, __qtablewidgetitem152);
        QTableWidgetItem *__qtablewidgetitem153 = new QTableWidgetItem();
        tableWidget_ports0->setVerticalHeaderItem(9, __qtablewidgetitem153);
        QTableWidgetItem *__qtablewidgetitem154 = new QTableWidgetItem();
        tableWidget_ports0->setVerticalHeaderItem(10, __qtablewidgetitem154);
        QTableWidgetItem *__qtablewidgetitem155 = new QTableWidgetItem();
        tableWidget_ports0->setVerticalHeaderItem(11, __qtablewidgetitem155);
        tableWidget_ports0->setObjectName(QString::fromUtf8("tableWidget_ports0"));
        sizePolicy1.setHeightForWidth(tableWidget_ports0->sizePolicy().hasHeightForWidth());
        tableWidget_ports0->setSizePolicy(sizePolicy1);
        tableWidget_ports0->setMinimumSize(QSize(177, 210));
        tableWidget_ports0->horizontalHeader()->setMinimumSectionSize(50);
        tableWidget_ports0->horizontalHeader()->setDefaultSectionSize(165);
        tableWidget_ports0->horizontalHeader()->setStretchLastSection(true);
        tableWidget_ports0->verticalHeader()->setDefaultSectionSize(30);
        tableWidget_ports0->verticalHeader()->setStretchLastSection(false);

        horizontalLayout_26->addWidget(tableWidget_ports0);

        tableWidget_ports1 = new QTableWidget(tab_ports_pps);
        if (tableWidget_ports1->columnCount() < 1)
            tableWidget_ports1->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem156 = new QTableWidgetItem();
        tableWidget_ports1->setHorizontalHeaderItem(0, __qtablewidgetitem156);
        if (tableWidget_ports1->rowCount() < 12)
            tableWidget_ports1->setRowCount(12);
        QTableWidgetItem *__qtablewidgetitem157 = new QTableWidgetItem();
        tableWidget_ports1->setVerticalHeaderItem(0, __qtablewidgetitem157);
        QTableWidgetItem *__qtablewidgetitem158 = new QTableWidgetItem();
        tableWidget_ports1->setVerticalHeaderItem(1, __qtablewidgetitem158);
        QTableWidgetItem *__qtablewidgetitem159 = new QTableWidgetItem();
        tableWidget_ports1->setVerticalHeaderItem(2, __qtablewidgetitem159);
        QTableWidgetItem *__qtablewidgetitem160 = new QTableWidgetItem();
        tableWidget_ports1->setVerticalHeaderItem(3, __qtablewidgetitem160);
        QTableWidgetItem *__qtablewidgetitem161 = new QTableWidgetItem();
        tableWidget_ports1->setVerticalHeaderItem(4, __qtablewidgetitem161);
        QTableWidgetItem *__qtablewidgetitem162 = new QTableWidgetItem();
        tableWidget_ports1->setVerticalHeaderItem(5, __qtablewidgetitem162);
        QTableWidgetItem *__qtablewidgetitem163 = new QTableWidgetItem();
        tableWidget_ports1->setVerticalHeaderItem(6, __qtablewidgetitem163);
        QTableWidgetItem *__qtablewidgetitem164 = new QTableWidgetItem();
        tableWidget_ports1->setVerticalHeaderItem(7, __qtablewidgetitem164);
        QTableWidgetItem *__qtablewidgetitem165 = new QTableWidgetItem();
        tableWidget_ports1->setVerticalHeaderItem(8, __qtablewidgetitem165);
        QTableWidgetItem *__qtablewidgetitem166 = new QTableWidgetItem();
        tableWidget_ports1->setVerticalHeaderItem(9, __qtablewidgetitem166);
        QTableWidgetItem *__qtablewidgetitem167 = new QTableWidgetItem();
        tableWidget_ports1->setVerticalHeaderItem(10, __qtablewidgetitem167);
        QTableWidgetItem *__qtablewidgetitem168 = new QTableWidgetItem();
        tableWidget_ports1->setVerticalHeaderItem(11, __qtablewidgetitem168);
        tableWidget_ports1->setObjectName(QString::fromUtf8("tableWidget_ports1"));
        sizePolicy1.setHeightForWidth(tableWidget_ports1->sizePolicy().hasHeightForWidth());
        tableWidget_ports1->setSizePolicy(sizePolicy1);
        tableWidget_ports1->setMinimumSize(QSize(177, 0));
        tableWidget_ports1->horizontalHeader()->setDefaultSectionSize(165);
        tableWidget_ports1->horizontalHeader()->setStretchLastSection(true);

        horizontalLayout_26->addWidget(tableWidget_ports1);


        horizontalLayout_27->addLayout(horizontalLayout_26);

        tabs_regs->addTab(tab_ports_pps, QString());

        horizontalLayout_11->addWidget(tabs_regs);


        verticalLayout_10->addLayout(horizontalLayout_11);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetMaximumSize);
        pushButton_add_plot = new QPushButton(centralwidget);
        pushButton_add_plot->setObjectName(QString::fromUtf8("pushButton_add_plot"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Ignored);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(pushButton_add_plot->sizePolicy().hasHeightForWidth());
        pushButton_add_plot->setSizePolicy(sizePolicy3);

        verticalLayout->addWidget(pushButton_add_plot);

        pushButton_breakpoint_line = new QPushButton(centralwidget);
        pushButton_breakpoint_line->setObjectName(QString::fromUtf8("pushButton_breakpoint_line"));
        sizePolicy3.setHeightForWidth(pushButton_breakpoint_line->sizePolicy().hasHeightForWidth());
        pushButton_breakpoint_line->setSizePolicy(sizePolicy3);

        verticalLayout->addWidget(pushButton_breakpoint_line);

        textEdit_line_break_addr = new QTextEdit(centralwidget);
        textEdit_line_break_addr->setObjectName(QString::fromUtf8("textEdit_line_break_addr"));
        QSizePolicy sizePolicy4(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(textEdit_line_break_addr->sizePolicy().hasHeightForWidth());
        textEdit_line_break_addr->setSizePolicy(sizePolicy4);

        verticalLayout->addWidget(textEdit_line_break_addr);

        pushButton_breakpoint = new QPushButton(centralwidget);
        pushButton_breakpoint->setObjectName(QString::fromUtf8("pushButton_breakpoint"));
        sizePolicy4.setHeightForWidth(pushButton_breakpoint->sizePolicy().hasHeightForWidth());
        pushButton_breakpoint->setSizePolicy(sizePolicy4);

        verticalLayout->addWidget(pushButton_breakpoint);

        textEdit_addr_break_addr = new QTextEdit(centralwidget);
        textEdit_addr_break_addr->setObjectName(QString::fromUtf8("textEdit_addr_break_addr"));
        sizePolicy4.setHeightForWidth(textEdit_addr_break_addr->sizePolicy().hasHeightForWidth());
        textEdit_addr_break_addr->setSizePolicy(sizePolicy4);

        verticalLayout->addWidget(textEdit_addr_break_addr);

        pushButton_start = new QPushButton(centralwidget);
        pushButton_start->setObjectName(QString::fromUtf8("pushButton_start"));
        QSizePolicy sizePolicy5(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(pushButton_start->sizePolicy().hasHeightForWidth());
        pushButton_start->setSizePolicy(sizePolicy5);

        verticalLayout->addWidget(pushButton_start);

        pushButton_disasm = new QPushButton(centralwidget);
        pushButton_disasm->setObjectName(QString::fromUtf8("pushButton_disasm"));
        sizePolicy5.setHeightForWidth(pushButton_disasm->sizePolicy().hasHeightForWidth());
        pushButton_disasm->setSizePolicy(sizePolicy5);

        verticalLayout->addWidget(pushButton_disasm);


        horizontalLayout_2->addLayout(verticalLayout);

        Memory_Tabs = new QTabWidget(centralwidget);
        Memory_Tabs->setObjectName(QString::fromUtf8("Memory_Tabs"));
        AccessBank = new QWidget();
        AccessBank->setObjectName(QString::fromUtf8("AccessBank"));
        horizontalLayout_10 = new QHBoxLayout(AccessBank);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        tableWidget_frs = new QTableWidget(AccessBank);
        if (tableWidget_frs->columnCount() < 1)
            tableWidget_frs->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem169 = new QTableWidgetItem();
        tableWidget_frs->setHorizontalHeaderItem(0, __qtablewidgetitem169);
        if (tableWidget_frs->rowCount() < 3)
            tableWidget_frs->setRowCount(3);
        QTableWidgetItem *__qtablewidgetitem170 = new QTableWidgetItem();
        tableWidget_frs->setVerticalHeaderItem(0, __qtablewidgetitem170);
        QTableWidgetItem *__qtablewidgetitem171 = new QTableWidgetItem();
        tableWidget_frs->setVerticalHeaderItem(1, __qtablewidgetitem171);
        QTableWidgetItem *__qtablewidgetitem172 = new QTableWidgetItem();
        tableWidget_frs->setVerticalHeaderItem(2, __qtablewidgetitem172);
        tableWidget_frs->setObjectName(QString::fromUtf8("tableWidget_frs"));
        tableWidget_frs->setRowCount(3);
        tableWidget_frs->setColumnCount(1);
        tableWidget_frs->horizontalHeader()->setStretchLastSection(true);
        tableWidget_frs->verticalHeader()->setStretchLastSection(true);

        verticalLayout_5->addWidget(tableWidget_frs);

        return_stack = new QTableWidget(AccessBank);
        if (return_stack->columnCount() < 1)
            return_stack->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem173 = new QTableWidgetItem();
        return_stack->setHorizontalHeaderItem(0, __qtablewidgetitem173);
        if (return_stack->rowCount() < 8)
            return_stack->setRowCount(8);
        return_stack->setObjectName(QString::fromUtf8("return_stack"));
        return_stack->setRowCount(8);
        return_stack->setColumnCount(1);
        return_stack->horizontalHeader()->setStretchLastSection(true);
        return_stack->verticalHeader()->setStretchLastSection(true);

        verticalLayout_5->addWidget(return_stack);

        verticalLayout_5->setStretch(0, 4);
        verticalLayout_5->setStretch(1, 8);

        horizontalLayout->addLayout(verticalLayout_5);

        tableWidget = new QTableWidget(AccessBank);
        if (tableWidget->columnCount() < 16)
            tableWidget->setColumnCount(16);
        if (tableWidget->rowCount() < 16)
            tableWidget->setRowCount(16);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        sizePolicy.setHeightForWidth(tableWidget->sizePolicy().hasHeightForWidth());
        tableWidget->setSizePolicy(sizePolicy);
        tableWidget->setSelectionMode(QAbstractItemView::ExtendedSelection);
        tableWidget->setRowCount(16);
        tableWidget->setColumnCount(16);
        tableWidget->horizontalHeader()->setVisible(true);
        tableWidget->horizontalHeader()->setMinimumSectionSize(15);
        tableWidget->horizontalHeader()->setDefaultSectionSize(35);
        tableWidget->verticalHeader()->setVisible(true);
        tableWidget->verticalHeader()->setMinimumSectionSize(19);
        tableWidget->verticalHeader()->setDefaultSectionSize(25);

        horizontalLayout->addWidget(tableWidget);

        horizontalLayout->setStretch(0, 2);
        horizontalLayout->setStretch(1, 10);

        horizontalLayout_10->addLayout(horizontalLayout);

        Memory_Tabs->addTab(AccessBank, QString());
        tab_8 = new QWidget();
        tab_8->setObjectName(QString::fromUtf8("tab_8"));
        horizontalLayout_4 = new QHBoxLayout(tab_8);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        te_set_bank = new QTextEdit(tab_8);
        te_set_bank->setObjectName(QString::fromUtf8("te_set_bank"));
        sizePolicy1.setHeightForWidth(te_set_bank->sizePolicy().hasHeightForWidth());
        te_set_bank->setSizePolicy(sizePolicy1);
        te_set_bank->setMinimumSize(QSize(0, 60));
        te_set_bank->setBaseSize(QSize(0, 100));

        verticalLayout_2->addWidget(te_set_bank);

        pb_set_bank = new QPushButton(tab_8);
        pb_set_bank->setObjectName(QString::fromUtf8("pb_set_bank"));
        QSizePolicy sizePolicy6(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(pb_set_bank->sizePolicy().hasHeightForWidth());
        pb_set_bank->setSizePolicy(sizePolicy6);

        verticalLayout_2->addWidget(pb_set_bank);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));

        verticalLayout_2->addLayout(verticalLayout_3);

        verticalLayout_2->setStretch(0, 1);
        verticalLayout_2->setStretch(1, 1);
        verticalLayout_2->setStretch(2, 6);

        horizontalLayout_3->addLayout(verticalLayout_2);

        bank_select_table = new QTableWidget(tab_8);
        if (bank_select_table->columnCount() < 16)
            bank_select_table->setColumnCount(16);
        if (bank_select_table->rowCount() < 16)
            bank_select_table->setRowCount(16);
        bank_select_table->setObjectName(QString::fromUtf8("bank_select_table"));
        bank_select_table->setRowCount(16);
        bank_select_table->setColumnCount(16);
        bank_select_table->horizontalHeader()->setMinimumSectionSize(35);
        bank_select_table->horizontalHeader()->setDefaultSectionSize(38);
        bank_select_table->verticalHeader()->setMinimumSectionSize(17);
        bank_select_table->verticalHeader()->setDefaultSectionSize(25);

        horizontalLayout_3->addWidget(bank_select_table);

        horizontalLayout_3->setStretch(0, 1);
        horizontalLayout_3->setStretch(1, 10);

        horizontalLayout_4->addLayout(horizontalLayout_3);

        Memory_Tabs->addTab(tab_8, QString());
        logic_analyzer = new QWidget();
        logic_analyzer->setObjectName(QString::fromUtf8("logic_analyzer"));
        verticalLayout_8 = new QVBoxLayout(logic_analyzer);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        verticalWidget_plots = new QWidget(logic_analyzer);
        verticalWidget_plots->setObjectName(QString::fromUtf8("verticalWidget_plots"));
        verticalLayout_7 = new QVBoxLayout(verticalWidget_plots);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));

        verticalLayout_8->addWidget(verticalWidget_plots);

        Memory_Tabs->addTab(logic_analyzer, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QString::fromUtf8("tab_5"));
        horizontalLayout_16 = new QHBoxLayout(tab_5);
        horizontalLayout_16->setObjectName(QString::fromUtf8("horizontalLayout_16"));
        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        pushButton_porta = new QPushButton(tab_5);
        pushButton_porta->setObjectName(QString::fromUtf8("pushButton_porta"));
        sizePolicy4.setHeightForWidth(pushButton_porta->sizePolicy().hasHeightForWidth());
        pushButton_porta->setSizePolicy(sizePolicy4);

        horizontalLayout_6->addWidget(pushButton_porta);

        textEdit_porta = new QTextEdit(tab_5);
        textEdit_porta->setObjectName(QString::fromUtf8("textEdit_porta"));
        sizePolicy4.setHeightForWidth(textEdit_porta->sizePolicy().hasHeightForWidth());
        textEdit_porta->setSizePolicy(sizePolicy4);

        horizontalLayout_6->addWidget(textEdit_porta);


        verticalLayout_9->addLayout(horizontalLayout_6);

        horizontalLayout_20 = new QHBoxLayout();
        horizontalLayout_20->setObjectName(QString::fromUtf8("horizontalLayout_20"));
        pushButton_portb = new QPushButton(tab_5);
        pushButton_portb->setObjectName(QString::fromUtf8("pushButton_portb"));
        sizePolicy4.setHeightForWidth(pushButton_portb->sizePolicy().hasHeightForWidth());
        pushButton_portb->setSizePolicy(sizePolicy4);

        horizontalLayout_20->addWidget(pushButton_portb);

        textEdit_portb = new QTextEdit(tab_5);
        textEdit_portb->setObjectName(QString::fromUtf8("textEdit_portb"));
        sizePolicy4.setHeightForWidth(textEdit_portb->sizePolicy().hasHeightForWidth());
        textEdit_portb->setSizePolicy(sizePolicy4);

        horizontalLayout_20->addWidget(textEdit_portb);


        verticalLayout_9->addLayout(horizontalLayout_20);

        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setObjectName(QString::fromUtf8("horizontalLayout_18"));
        pushButton_portc = new QPushButton(tab_5);
        pushButton_portc->setObjectName(QString::fromUtf8("pushButton_portc"));
        sizePolicy4.setHeightForWidth(pushButton_portc->sizePolicy().hasHeightForWidth());
        pushButton_portc->setSizePolicy(sizePolicy4);

        horizontalLayout_18->addWidget(pushButton_portc);

        textEdit_portc = new QTextEdit(tab_5);
        textEdit_portc->setObjectName(QString::fromUtf8("textEdit_portc"));
        sizePolicy4.setHeightForWidth(textEdit_portc->sizePolicy().hasHeightForWidth());
        textEdit_portc->setSizePolicy(sizePolicy4);

        horizontalLayout_18->addWidget(textEdit_portc);


        verticalLayout_9->addLayout(horizontalLayout_18);


        horizontalLayout_16->addLayout(verticalLayout_9);

        verticalLayout_13 = new QVBoxLayout();
        verticalLayout_13->setObjectName(QString::fromUtf8("verticalLayout_13"));
        horizontalLayout_23 = new QHBoxLayout();
        horizontalLayout_23->setObjectName(QString::fromUtf8("horizontalLayout_23"));
        pushButton_portd = new QPushButton(tab_5);
        pushButton_portd->setObjectName(QString::fromUtf8("pushButton_portd"));
        sizePolicy4.setHeightForWidth(pushButton_portd->sizePolicy().hasHeightForWidth());
        pushButton_portd->setSizePolicy(sizePolicy4);

        horizontalLayout_23->addWidget(pushButton_portd);

        textEdit_portd = new QTextEdit(tab_5);
        textEdit_portd->setObjectName(QString::fromUtf8("textEdit_portd"));
        sizePolicy4.setHeightForWidth(textEdit_portd->sizePolicy().hasHeightForWidth());
        textEdit_portd->setSizePolicy(sizePolicy4);

        horizontalLayout_23->addWidget(textEdit_portd);


        verticalLayout_13->addLayout(horizontalLayout_23);

        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setObjectName(QString::fromUtf8("horizontalLayout_19"));
        pushButton_porte = new QPushButton(tab_5);
        pushButton_porte->setObjectName(QString::fromUtf8("pushButton_porte"));
        sizePolicy4.setHeightForWidth(pushButton_porte->sizePolicy().hasHeightForWidth());
        pushButton_porte->setSizePolicy(sizePolicy4);

        horizontalLayout_19->addWidget(pushButton_porte);

        textEdit_porte = new QTextEdit(tab_5);
        textEdit_porte->setObjectName(QString::fromUtf8("textEdit_porte"));
        sizePolicy4.setHeightForWidth(textEdit_porte->sizePolicy().hasHeightForWidth());
        textEdit_porte->setSizePolicy(sizePolicy4);

        horizontalLayout_19->addWidget(textEdit_porte);


        verticalLayout_13->addLayout(horizontalLayout_19);

        horizontalLayout_22 = new QHBoxLayout();
        horizontalLayout_22->setObjectName(QString::fromUtf8("horizontalLayout_22"));
        pushButton_portf = new QPushButton(tab_5);
        pushButton_portf->setObjectName(QString::fromUtf8("pushButton_portf"));
        sizePolicy4.setHeightForWidth(pushButton_portf->sizePolicy().hasHeightForWidth());
        pushButton_portf->setSizePolicy(sizePolicy4);

        horizontalLayout_22->addWidget(pushButton_portf);

        textEdit_portf = new QTextEdit(tab_5);
        textEdit_portf->setObjectName(QString::fromUtf8("textEdit_portf"));
        sizePolicy4.setHeightForWidth(textEdit_portf->sizePolicy().hasHeightForWidth());
        textEdit_portf->setSizePolicy(sizePolicy4);

        horizontalLayout_22->addWidget(textEdit_portf);


        verticalLayout_13->addLayout(horizontalLayout_22);


        horizontalLayout_16->addLayout(verticalLayout_13);

        Memory_Tabs->addTab(tab_5, QString());
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        horizontalLayout_29 = new QHBoxLayout(tab);
        horizontalLayout_29->setObjectName(QString::fromUtf8("horizontalLayout_29"));
        horizontalLayout_28 = new QHBoxLayout();
        horizontalLayout_28->setObjectName(QString::fromUtf8("horizontalLayout_28"));
        verticalLayout_14 = new QVBoxLayout();
        verticalLayout_14->setObjectName(QString::fromUtf8("verticalLayout_14"));
        pushButton_setaddr = new QPushButton(tab);
        pushButton_setaddr->setObjectName(QString::fromUtf8("pushButton_setaddr"));
        sizePolicy4.setHeightForWidth(pushButton_setaddr->sizePolicy().hasHeightForWidth());
        pushButton_setaddr->setSizePolicy(sizePolicy4);

        verticalLayout_14->addWidget(pushButton_setaddr);

        label_3 = new QLabel(tab);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy4.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy4);
        label_3->setAlignment(Qt::AlignCenter);

        verticalLayout_14->addWidget(label_3);

        textEdit_addr = new QTextEdit(tab);
        textEdit_addr->setObjectName(QString::fromUtf8("textEdit_addr"));
        sizePolicy4.setHeightForWidth(textEdit_addr->sizePolicy().hasHeightForWidth());
        textEdit_addr->setSizePolicy(sizePolicy4);

        verticalLayout_14->addWidget(textEdit_addr);

        label_4 = new QLabel(tab);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        QSizePolicy sizePolicy7(QSizePolicy::Preferred, QSizePolicy::Ignored);
        sizePolicy7.setHorizontalStretch(0);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy7);
        label_4->setAlignment(Qt::AlignCenter);

        verticalLayout_14->addWidget(label_4);

        textEdit_value = new QTextEdit(tab);
        textEdit_value->setObjectName(QString::fromUtf8("textEdit_value"));
        sizePolicy4.setHeightForWidth(textEdit_value->sizePolicy().hasHeightForWidth());
        textEdit_value->setSizePolicy(sizePolicy4);

        verticalLayout_14->addWidget(textEdit_value);


        horizontalLayout_28->addLayout(verticalLayout_14);

        verticalLayout_16 = new QVBoxLayout();
        verticalLayout_16->setObjectName(QString::fromUtf8("verticalLayout_16"));
        label = new QLabel(tab);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_16->addWidget(label);

        textBrowser = new QTextBrowser(tab);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        sizePolicy4.setHeightForWidth(textBrowser->sizePolicy().hasHeightForWidth());
        textBrowser->setSizePolicy(sizePolicy4);

        verticalLayout_16->addWidget(textBrowser);


        horizontalLayout_28->addLayout(verticalLayout_16);

        verticalLayout_15 = new QVBoxLayout();
        verticalLayout_15->setObjectName(QString::fromUtf8("verticalLayout_15"));
        label_2 = new QLabel(tab);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout_15->addWidget(label_2);

        textBrowser_2 = new QTextBrowser(tab);
        textBrowser_2->setObjectName(QString::fromUtf8("textBrowser_2"));
        sizePolicy4.setHeightForWidth(textBrowser_2->sizePolicy().hasHeightForWidth());
        textBrowser_2->setSizePolicy(sizePolicy4);

        verticalLayout_15->addWidget(textBrowser_2);


        horizontalLayout_28->addLayout(verticalLayout_15);

        verticalLayout_18 = new QVBoxLayout();
        verticalLayout_18->setObjectName(QString::fromUtf8("verticalLayout_18"));
        checkBox = new QCheckBox(tab);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        sizePolicy4.setHeightForWidth(checkBox->sizePolicy().hasHeightForWidth());
        checkBox->setSizePolicy(sizePolicy4);

        verticalLayout_18->addWidget(checkBox);

        radioButton = new QRadioButton(tab);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        sizePolicy4.setHeightForWidth(radioButton->sizePolicy().hasHeightForWidth());
        radioButton->setSizePolicy(sizePolicy4);

        verticalLayout_18->addWidget(radioButton);

        radioButton_2 = new QRadioButton(tab);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));
        sizePolicy4.setHeightForWidth(radioButton_2->sizePolicy().hasHeightForWidth());
        radioButton_2->setSizePolicy(sizePolicy4);

        verticalLayout_18->addWidget(radioButton_2);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_5 = new QLabel(tab);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setAlignment(Qt::AlignCenter);

        horizontalLayout_7->addWidget(label_5);

        textEdit = new QTextEdit(tab);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        sizePolicy4.setHeightForWidth(textEdit->sizePolicy().hasHeightForWidth());
        textEdit->setSizePolicy(sizePolicy4);

        horizontalLayout_7->addWidget(textEdit);


        verticalLayout_18->addLayout(horizontalLayout_7);


        horizontalLayout_28->addLayout(verticalLayout_18);


        horizontalLayout_29->addLayout(horizontalLayout_28);

        Memory_Tabs->addTab(tab, QString());

        horizontalLayout_2->addWidget(Memory_Tabs);


        verticalLayout_10->addLayout(horizontalLayout_2);


        verticalLayout_11->addLayout(verticalLayout_10);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1231, 22));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menuFile->menuAction());
        menuFile->addAction(actionLoad_File);

        retranslateUi(MainWindow);

        tabs_regs->setCurrentIndex(4);
        Memory_Tabs->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "DSM-57", nullptr));
        actionLoad_File->setText(QCoreApplication::translate("MainWindow", "Load File", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_instr->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "Instruction", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_instr->verticalHeaderItem(0);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Program Counter", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_instr->verticalHeaderItem(1);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Execute", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget_instr->verticalHeaderItem(2);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "Fetch", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget_cpu->horizontalHeaderItem(0);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "REG", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget_cpu->verticalHeaderItem(0);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "WREG", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget_cpu->verticalHeaderItem(1);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "STATUS.N", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget_cpu->verticalHeaderItem(2);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("MainWindow", "STATUS.OV", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget_cpu->verticalHeaderItem(3);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("MainWindow", "STATUS.Z", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget_cpu->verticalHeaderItem(4);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("MainWindow", "STATUS.DC", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget_cpu->verticalHeaderItem(5);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("MainWindow", "STATUS.C", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget_cpu->verticalHeaderItem(6);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("MainWindow", "BSR", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget_cpu->verticalHeaderItem(7);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("MainWindow", "TOS", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget_cpu->verticalHeaderItem(8);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("MainWindow", "STKPTR", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidget_ind_stack->horizontalHeaderItem(0);
        ___qtablewidgetitem14->setText(QCoreApplication::translate("MainWindow", "REG", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = tableWidget_ind_stack->verticalHeaderItem(0);
        ___qtablewidgetitem15->setText(QCoreApplication::translate("MainWindow", "FSR0", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = tableWidget_ind_stack->verticalHeaderItem(1);
        ___qtablewidgetitem16->setText(QCoreApplication::translate("MainWindow", "FSR1", nullptr));
        QTableWidgetItem *___qtablewidgetitem17 = tableWidget_ind_stack->verticalHeaderItem(2);
        ___qtablewidgetitem17->setText(QCoreApplication::translate("MainWindow", "FSR2", nullptr));
        QTableWidgetItem *___qtablewidgetitem18 = tableWidget_ind_stack->verticalHeaderItem(3);
        ___qtablewidgetitem18->setText(QCoreApplication::translate("MainWindow", "INDF0", nullptr));
        QTableWidgetItem *___qtablewidgetitem19 = tableWidget_ind_stack->verticalHeaderItem(4);
        ___qtablewidgetitem19->setText(QCoreApplication::translate("MainWindow", "INDF1", nullptr));
        QTableWidgetItem *___qtablewidgetitem20 = tableWidget_ind_stack->verticalHeaderItem(5);
        ___qtablewidgetitem20->setText(QCoreApplication::translate("MainWindow", "INDF2", nullptr));
        QTableWidgetItem *___qtablewidgetitem21 = tableWidget_ind_stack->verticalHeaderItem(6);
        ___qtablewidgetitem21->setText(QCoreApplication::translate("MainWindow", "TOSU", nullptr));
        QTableWidgetItem *___qtablewidgetitem22 = tableWidget_ind_stack->verticalHeaderItem(7);
        ___qtablewidgetitem22->setText(QCoreApplication::translate("MainWindow", "TOSH", nullptr));
        QTableWidgetItem *___qtablewidgetitem23 = tableWidget_ind_stack->verticalHeaderItem(8);
        ___qtablewidgetitem23->setText(QCoreApplication::translate("MainWindow", "TOSL", nullptr));
        tabs_regs->setTabText(tabs_regs->indexOf(tab_cpu), QCoreApplication::translate("MainWindow", "CPU", nullptr));
        QTableWidgetItem *___qtablewidgetitem24 = tableWidget_tmr0->horizontalHeaderItem(0);
        ___qtablewidgetitem24->setText(QCoreApplication::translate("MainWindow", "REG", nullptr));
        QTableWidgetItem *___qtablewidgetitem25 = tableWidget_tmr0->verticalHeaderItem(0);
        ___qtablewidgetitem25->setText(QCoreApplication::translate("MainWindow", "TMR0CON0", nullptr));
        QTableWidgetItem *___qtablewidgetitem26 = tableWidget_tmr0->verticalHeaderItem(1);
        ___qtablewidgetitem26->setText(QCoreApplication::translate("MainWindow", "TMR0CON0.EN", nullptr));
        QTableWidgetItem *___qtablewidgetitem27 = tableWidget_tmr0->verticalHeaderItem(2);
        ___qtablewidgetitem27->setText(QCoreApplication::translate("MainWindow", "TMR0CON0.OUT", nullptr));
        QTableWidgetItem *___qtablewidgetitem28 = tableWidget_tmr0->verticalHeaderItem(3);
        ___qtablewidgetitem28->setText(QCoreApplication::translate("MainWindow", "TMR0CON0.MD16", nullptr));
        QTableWidgetItem *___qtablewidgetitem29 = tableWidget_tmr0->verticalHeaderItem(4);
        ___qtablewidgetitem29->setText(QCoreApplication::translate("MainWindow", "TMR0CON0.OUTPS", nullptr));
        QTableWidgetItem *___qtablewidgetitem30 = tableWidget_tmr0->verticalHeaderItem(5);
        ___qtablewidgetitem30->setText(QCoreApplication::translate("MainWindow", "TMR0CON1", nullptr));
        QTableWidgetItem *___qtablewidgetitem31 = tableWidget_tmr0->verticalHeaderItem(6);
        ___qtablewidgetitem31->setText(QCoreApplication::translate("MainWindow", "TMR0CON1.CS", nullptr));
        QTableWidgetItem *___qtablewidgetitem32 = tableWidget_tmr0->verticalHeaderItem(7);
        ___qtablewidgetitem32->setText(QCoreApplication::translate("MainWindow", "TMR0CON1.ASYNC", nullptr));
        QTableWidgetItem *___qtablewidgetitem33 = tableWidget_tmr0->verticalHeaderItem(8);
        ___qtablewidgetitem33->setText(QCoreApplication::translate("MainWindow", "TMR0CON1.CKPS", nullptr));
        QTableWidgetItem *___qtablewidgetitem34 = tableWidget_tmr0->verticalHeaderItem(9);
        ___qtablewidgetitem34->setText(QCoreApplication::translate("MainWindow", "TMR0H", nullptr));
        QTableWidgetItem *___qtablewidgetitem35 = tableWidget_tmr0->verticalHeaderItem(10);
        ___qtablewidgetitem35->setText(QCoreApplication::translate("MainWindow", "TMR0L", nullptr));
        QTableWidgetItem *___qtablewidgetitem36 = tableWidget_tmr0->verticalHeaderItem(11);
        ___qtablewidgetitem36->setText(QCoreApplication::translate("MainWindow", "ISR ADDR", nullptr));
        QTableWidgetItem *___qtablewidgetitem37 = tableWidget_tmr1->horizontalHeaderItem(0);
        ___qtablewidgetitem37->setText(QCoreApplication::translate("MainWindow", "REG", nullptr));
        QTableWidgetItem *___qtablewidgetitem38 = tableWidget_tmr1->verticalHeaderItem(0);
        ___qtablewidgetitem38->setText(QCoreApplication::translate("MainWindow", "TMR1CON", nullptr));
        QTableWidgetItem *___qtablewidgetitem39 = tableWidget_tmr1->verticalHeaderItem(1);
        ___qtablewidgetitem39->setText(QCoreApplication::translate("MainWindow", "TMR1CON.ON", nullptr));
        QTableWidgetItem *___qtablewidgetitem40 = tableWidget_tmr1->verticalHeaderItem(2);
        ___qtablewidgetitem40->setText(QCoreApplication::translate("MainWindow", "TMR1CON.RD16", nullptr));
        QTableWidgetItem *___qtablewidgetitem41 = tableWidget_tmr1->verticalHeaderItem(3);
        ___qtablewidgetitem41->setText(QCoreApplication::translate("MainWindow", "TMR1CON.SYNC", nullptr));
        QTableWidgetItem *___qtablewidgetitem42 = tableWidget_tmr1->verticalHeaderItem(4);
        ___qtablewidgetitem42->setText(QCoreApplication::translate("MainWindow", "TMR1CON.CKPS", nullptr));
        QTableWidgetItem *___qtablewidgetitem43 = tableWidget_tmr1->verticalHeaderItem(5);
        ___qtablewidgetitem43->setText(QCoreApplication::translate("MainWindow", "TMR1GCON", nullptr));
        QTableWidgetItem *___qtablewidgetitem44 = tableWidget_tmr1->verticalHeaderItem(6);
        ___qtablewidgetitem44->setText(QCoreApplication::translate("MainWindow", "TMR1GCON.GVAL", nullptr));
        QTableWidgetItem *___qtablewidgetitem45 = tableWidget_tmr1->verticalHeaderItem(7);
        ___qtablewidgetitem45->setText(QCoreApplication::translate("MainWindow", "TMR1GCON.GGO", nullptr));
        QTableWidgetItem *___qtablewidgetitem46 = tableWidget_tmr1->verticalHeaderItem(8);
        ___qtablewidgetitem46->setText(QCoreApplication::translate("MainWindow", "TMR1GCON.GSPM", nullptr));
        QTableWidgetItem *___qtablewidgetitem47 = tableWidget_tmr1->verticalHeaderItem(9);
        ___qtablewidgetitem47->setText(QCoreApplication::translate("MainWindow", "TMR1GCON.GTM", nullptr));
        QTableWidgetItem *___qtablewidgetitem48 = tableWidget_tmr1->verticalHeaderItem(10);
        ___qtablewidgetitem48->setText(QCoreApplication::translate("MainWindow", "TMR1GCON.GPOL", nullptr));
        QTableWidgetItem *___qtablewidgetitem49 = tableWidget_tmr1->verticalHeaderItem(11);
        ___qtablewidgetitem49->setText(QCoreApplication::translate("MainWindow", "TMR1GCON.GE", nullptr));
        QTableWidgetItem *___qtablewidgetitem50 = tableWidget_tmr1->verticalHeaderItem(12);
        ___qtablewidgetitem50->setText(QCoreApplication::translate("MainWindow", "T1CLK", nullptr));
        QTableWidgetItem *___qtablewidgetitem51 = tableWidget_tmr1->verticalHeaderItem(13);
        ___qtablewidgetitem51->setText(QCoreApplication::translate("MainWindow", "T1GATE", nullptr));
        QTableWidgetItem *___qtablewidgetitem52 = tableWidget_tmr1->verticalHeaderItem(14);
        ___qtablewidgetitem52->setText(QCoreApplication::translate("MainWindow", "TMR1", nullptr));
        QTableWidgetItem *___qtablewidgetitem53 = tableWidget_tmr1->verticalHeaderItem(15);
        ___qtablewidgetitem53->setText(QCoreApplication::translate("MainWindow", "ISR ADDR", nullptr));
        tabs_regs->setTabText(tabs_regs->indexOf(tab_tmr), QCoreApplication::translate("MainWindow", "TMR0/1", nullptr));
        QTableWidgetItem *___qtablewidgetitem54 = tableWidget_adc0->horizontalHeaderItem(0);
        ___qtablewidgetitem54->setText(QCoreApplication::translate("MainWindow", "REG", nullptr));
        QTableWidgetItem *___qtablewidgetitem55 = tableWidget_adc0->verticalHeaderItem(0);
        ___qtablewidgetitem55->setText(QCoreApplication::translate("MainWindow", "ADCON0", nullptr));
        QTableWidgetItem *___qtablewidgetitem56 = tableWidget_adc0->verticalHeaderItem(1);
        ___qtablewidgetitem56->setText(QCoreApplication::translate("MainWindow", "ADCON0.ON", nullptr));
        QTableWidgetItem *___qtablewidgetitem57 = tableWidget_adc0->verticalHeaderItem(2);
        ___qtablewidgetitem57->setText(QCoreApplication::translate("MainWindow", "ADCON0.CONT", nullptr));
        QTableWidgetItem *___qtablewidgetitem58 = tableWidget_adc0->verticalHeaderItem(3);
        ___qtablewidgetitem58->setText(QCoreApplication::translate("MainWindow", "ADCON0.CS", nullptr));
        QTableWidgetItem *___qtablewidgetitem59 = tableWidget_adc0->verticalHeaderItem(4);
        ___qtablewidgetitem59->setText(QCoreApplication::translate("MainWindow", "ADCON0.FM", nullptr));
        QTableWidgetItem *___qtablewidgetitem60 = tableWidget_adc0->verticalHeaderItem(5);
        ___qtablewidgetitem60->setText(QCoreApplication::translate("MainWindow", "ADCON0.GO", nullptr));
        QTableWidgetItem *___qtablewidgetitem61 = tableWidget_adc0->verticalHeaderItem(6);
        ___qtablewidgetitem61->setText(QCoreApplication::translate("MainWindow", "ADCON1", nullptr));
        QTableWidgetItem *___qtablewidgetitem62 = tableWidget_adc0->verticalHeaderItem(7);
        ___qtablewidgetitem62->setText(QCoreApplication::translate("MainWindow", "ADCON1.PPOL", nullptr));
        QTableWidgetItem *___qtablewidgetitem63 = tableWidget_adc0->verticalHeaderItem(8);
        ___qtablewidgetitem63->setText(QCoreApplication::translate("MainWindow", "ADCON1.IPEN", nullptr));
        QTableWidgetItem *___qtablewidgetitem64 = tableWidget_adc0->verticalHeaderItem(9);
        ___qtablewidgetitem64->setText(QCoreApplication::translate("MainWindow", "ADCON1.GPOL", nullptr));
        QTableWidgetItem *___qtablewidgetitem65 = tableWidget_adc0->verticalHeaderItem(10);
        ___qtablewidgetitem65->setText(QCoreApplication::translate("MainWindow", "ADCON1.DSEN", nullptr));
        QTableWidgetItem *___qtablewidgetitem66 = tableWidget_adc0->verticalHeaderItem(11);
        ___qtablewidgetitem66->setText(QCoreApplication::translate("MainWindow", "ADCON2", nullptr));
        QTableWidgetItem *___qtablewidgetitem67 = tableWidget_adc0->verticalHeaderItem(12);
        ___qtablewidgetitem67->setText(QCoreApplication::translate("MainWindow", "ADCON2.PSIS", nullptr));
        QTableWidgetItem *___qtablewidgetitem68 = tableWidget_adc0->verticalHeaderItem(13);
        ___qtablewidgetitem68->setText(QCoreApplication::translate("MainWindow", "ADCON2.CRS", nullptr));
        QTableWidgetItem *___qtablewidgetitem69 = tableWidget_adc0->verticalHeaderItem(14);
        ___qtablewidgetitem69->setText(QCoreApplication::translate("MainWindow", "ADCON2.ACLR", nullptr));
        QTableWidgetItem *___qtablewidgetitem70 = tableWidget_adc0->verticalHeaderItem(15);
        ___qtablewidgetitem70->setText(QCoreApplication::translate("MainWindow", "ADCON2.MD", nullptr));
        QTableWidgetItem *___qtablewidgetitem71 = tableWidget_adc1->horizontalHeaderItem(0);
        ___qtablewidgetitem71->setText(QCoreApplication::translate("MainWindow", "REG", nullptr));
        QTableWidgetItem *___qtablewidgetitem72 = tableWidget_adc1->verticalHeaderItem(0);
        ___qtablewidgetitem72->setText(QCoreApplication::translate("MainWindow", "ADCLK", nullptr));
        QTableWidgetItem *___qtablewidgetitem73 = tableWidget_adc1->verticalHeaderItem(1);
        ___qtablewidgetitem73->setText(QCoreApplication::translate("MainWindow", "ADPCH", nullptr));
        QTableWidgetItem *___qtablewidgetitem74 = tableWidget_adc1->verticalHeaderItem(2);
        ___qtablewidgetitem74->setText(QCoreApplication::translate("MainWindow", "ADPRE", nullptr));
        QTableWidgetItem *___qtablewidgetitem75 = tableWidget_adc1->verticalHeaderItem(3);
        ___qtablewidgetitem75->setText(QCoreApplication::translate("MainWindow", "ADACQ", nullptr));
        QTableWidgetItem *___qtablewidgetitem76 = tableWidget_adc1->verticalHeaderItem(4);
        ___qtablewidgetitem76->setText(QCoreApplication::translate("MainWindow", "ADRES", nullptr));
        QTableWidgetItem *___qtablewidgetitem77 = tableWidget_adc1->verticalHeaderItem(5);
        ___qtablewidgetitem77->setText(QCoreApplication::translate("MainWindow", "ADPREV", nullptr));
        QTableWidgetItem *___qtablewidgetitem78 = tableWidget_adc1->verticalHeaderItem(6);
        ___qtablewidgetitem78->setText(QCoreApplication::translate("MainWindow", "ADACT", nullptr));
        QTableWidgetItem *___qtablewidgetitem79 = tableWidget_adc1->verticalHeaderItem(7);
        ___qtablewidgetitem79->setText(QCoreApplication::translate("MainWindow", "ADCON3", nullptr));
        QTableWidgetItem *___qtablewidgetitem80 = tableWidget_adc1->verticalHeaderItem(8);
        ___qtablewidgetitem80->setText(QCoreApplication::translate("MainWindow", "ADCON3.CALC", nullptr));
        QTableWidgetItem *___qtablewidgetitem81 = tableWidget_adc1->verticalHeaderItem(9);
        ___qtablewidgetitem81->setText(QCoreApplication::translate("MainWindow", "ADCON3.SOI", nullptr));
        QTableWidgetItem *___qtablewidgetitem82 = tableWidget_adc1->verticalHeaderItem(10);
        ___qtablewidgetitem82->setText(QCoreApplication::translate("MainWindow", "ADCON3.TMD", nullptr));
        tabs_regs->setTabText(tabs_regs->indexOf(tab_adc), QCoreApplication::translate("MainWindow", "ADC", nullptr));
        QTableWidgetItem *___qtablewidgetitem83 = tableWidget_int->horizontalHeaderItem(0);
        ___qtablewidgetitem83->setText(QCoreApplication::translate("MainWindow", "REG", nullptr));
        QTableWidgetItem *___qtablewidgetitem84 = tableWidget_int->verticalHeaderItem(0);
        ___qtablewidgetitem84->setText(QCoreApplication::translate("MainWindow", "INTCON0", nullptr));
        QTableWidgetItem *___qtablewidgetitem85 = tableWidget_int->verticalHeaderItem(1);
        ___qtablewidgetitem85->setText(QCoreApplication::translate("MainWindow", "INTCON0.GIEH", nullptr));
        QTableWidgetItem *___qtablewidgetitem86 = tableWidget_int->verticalHeaderItem(2);
        ___qtablewidgetitem86->setText(QCoreApplication::translate("MainWindow", "INTCON0.GIEL", nullptr));
        QTableWidgetItem *___qtablewidgetitem87 = tableWidget_int->verticalHeaderItem(3);
        ___qtablewidgetitem87->setText(QCoreApplication::translate("MainWindow", "INTCON0.IPEN", nullptr));
        QTableWidgetItem *___qtablewidgetitem88 = tableWidget_int->verticalHeaderItem(4);
        ___qtablewidgetitem88->setText(QCoreApplication::translate("MainWindow", "INTCON0.INT2EDG", nullptr));
        QTableWidgetItem *___qtablewidgetitem89 = tableWidget_int->verticalHeaderItem(5);
        ___qtablewidgetitem89->setText(QCoreApplication::translate("MainWindow", "INTCON0.INT1EDG", nullptr));
        QTableWidgetItem *___qtablewidgetitem90 = tableWidget_int->verticalHeaderItem(6);
        ___qtablewidgetitem90->setText(QCoreApplication::translate("MainWindow", "INTCON0.INT0EDG", nullptr));
        QTableWidgetItem *___qtablewidgetitem91 = tableWidget_int->verticalHeaderItem(7);
        ___qtablewidgetitem91->setText(QCoreApplication::translate("MainWindow", "INTCON1", nullptr));
        QTableWidgetItem *___qtablewidgetitem92 = tableWidget_int->verticalHeaderItem(8);
        ___qtablewidgetitem92->setText(QCoreApplication::translate("MainWindow", "INTCON1.STAT", nullptr));
        QTableWidgetItem *___qtablewidgetitem93 = tableWidget_int->verticalHeaderItem(9);
        ___qtablewidgetitem93->setText(QCoreApplication::translate("MainWindow", "IVTAD", nullptr));
        QTableWidgetItem *___qtablewidgetitem94 = tableWidget_pir->horizontalHeaderItem(0);
        ___qtablewidgetitem94->setText(QCoreApplication::translate("MainWindow", "PIR", nullptr));
        QTableWidgetItem *___qtablewidgetitem95 = tableWidget_pir->horizontalHeaderItem(1);
        ___qtablewidgetitem95->setText(QCoreApplication::translate("MainWindow", "PIE", nullptr));
        QTableWidgetItem *___qtablewidgetitem96 = tableWidget_pir->horizontalHeaderItem(2);
        ___qtablewidgetitem96->setText(QCoreApplication::translate("MainWindow", "IPR", nullptr));
        QTableWidgetItem *___qtablewidgetitem97 = tableWidget_pir->verticalHeaderItem(0);
        ___qtablewidgetitem97->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        QTableWidgetItem *___qtablewidgetitem98 = tableWidget_pir->verticalHeaderItem(1);
        ___qtablewidgetitem98->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        QTableWidgetItem *___qtablewidgetitem99 = tableWidget_pir->verticalHeaderItem(2);
        ___qtablewidgetitem99->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        QTableWidgetItem *___qtablewidgetitem100 = tableWidget_pir->verticalHeaderItem(3);
        ___qtablewidgetitem100->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        QTableWidgetItem *___qtablewidgetitem101 = tableWidget_pir->verticalHeaderItem(4);
        ___qtablewidgetitem101->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        QTableWidgetItem *___qtablewidgetitem102 = tableWidget_pir->verticalHeaderItem(5);
        ___qtablewidgetitem102->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        QTableWidgetItem *___qtablewidgetitem103 = tableWidget_pir->verticalHeaderItem(6);
        ___qtablewidgetitem103->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        QTableWidgetItem *___qtablewidgetitem104 = tableWidget_pir->verticalHeaderItem(7);
        ___qtablewidgetitem104->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
        QTableWidgetItem *___qtablewidgetitem105 = tableWidget_pir->verticalHeaderItem(8);
        ___qtablewidgetitem105->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
        QTableWidgetItem *___qtablewidgetitem106 = tableWidget_pir->verticalHeaderItem(9);
        ___qtablewidgetitem106->setText(QCoreApplication::translate("MainWindow", "9", nullptr));
        QTableWidgetItem *___qtablewidgetitem107 = tableWidget_pir->verticalHeaderItem(10);
        ___qtablewidgetitem107->setText(QCoreApplication::translate("MainWindow", "10", nullptr));
        QTableWidgetItem *___qtablewidgetitem108 = tableWidget_pir->verticalHeaderItem(11);
        ___qtablewidgetitem108->setText(QCoreApplication::translate("MainWindow", "11", nullptr));
        QTableWidgetItem *___qtablewidgetitem109 = tableWidget_pir->verticalHeaderItem(12);
        ___qtablewidgetitem109->setText(QCoreApplication::translate("MainWindow", "12", nullptr));
        tabs_regs->setTabText(tabs_regs->indexOf(tab_interrupts), QCoreApplication::translate("MainWindow", "INTERRUPTS", nullptr));
        QTableWidgetItem *___qtablewidgetitem110 = tableWidget_uart_0->horizontalHeaderItem(0);
        ___qtablewidgetitem110->setText(QCoreApplication::translate("MainWindow", "REG", nullptr));
        QTableWidgetItem *___qtablewidgetitem111 = tableWidget_uart_0->verticalHeaderItem(0);
        ___qtablewidgetitem111->setText(QCoreApplication::translate("MainWindow", "U1CON0", nullptr));
        QTableWidgetItem *___qtablewidgetitem112 = tableWidget_uart_0->verticalHeaderItem(1);
        ___qtablewidgetitem112->setText(QCoreApplication::translate("MainWindow", "U1CON0.BRGS", nullptr));
        QTableWidgetItem *___qtablewidgetitem113 = tableWidget_uart_0->verticalHeaderItem(2);
        ___qtablewidgetitem113->setText(QCoreApplication::translate("MainWindow", "U1CON0.ABDEN", nullptr));
        QTableWidgetItem *___qtablewidgetitem114 = tableWidget_uart_0->verticalHeaderItem(3);
        ___qtablewidgetitem114->setText(QCoreApplication::translate("MainWindow", "U1CON0.TXEN", nullptr));
        QTableWidgetItem *___qtablewidgetitem115 = tableWidget_uart_0->verticalHeaderItem(4);
        ___qtablewidgetitem115->setText(QCoreApplication::translate("MainWindow", "U1CON0.RXEN", nullptr));
        QTableWidgetItem *___qtablewidgetitem116 = tableWidget_uart_0->verticalHeaderItem(5);
        ___qtablewidgetitem116->setText(QCoreApplication::translate("MainWindow", "U1CON0.MODE", nullptr));
        QTableWidgetItem *___qtablewidgetitem117 = tableWidget_uart_0->verticalHeaderItem(6);
        ___qtablewidgetitem117->setText(QCoreApplication::translate("MainWindow", "U1CON1", nullptr));
        QTableWidgetItem *___qtablewidgetitem118 = tableWidget_uart_0->verticalHeaderItem(7);
        ___qtablewidgetitem118->setText(QCoreApplication::translate("MainWindow", "U1CON1.ON", nullptr));
        QTableWidgetItem *___qtablewidgetitem119 = tableWidget_uart_0->verticalHeaderItem(8);
        ___qtablewidgetitem119->setText(QCoreApplication::translate("MainWindow", "U1CON1.WUE", nullptr));
        QTableWidgetItem *___qtablewidgetitem120 = tableWidget_uart_0->verticalHeaderItem(9);
        ___qtablewidgetitem120->setText(QCoreApplication::translate("MainWindow", "U1CON1.RXBIMD", nullptr));
        QTableWidgetItem *___qtablewidgetitem121 = tableWidget_uart_0->verticalHeaderItem(10);
        ___qtablewidgetitem121->setText(QCoreApplication::translate("MainWindow", "U1CON1.BRKOVR", nullptr));
        QTableWidgetItem *___qtablewidgetitem122 = tableWidget_uart_0->verticalHeaderItem(11);
        ___qtablewidgetitem122->setText(QCoreApplication::translate("MainWindow", "U1CON1.SENDB", nullptr));
        QTableWidgetItem *___qtablewidgetitem123 = tableWidget_uart_0->verticalHeaderItem(12);
        ___qtablewidgetitem123->setText(QCoreApplication::translate("MainWindow", "U1BRG", nullptr));
        QTableWidgetItem *___qtablewidgetitem124 = tableWidget_uart_0->verticalHeaderItem(13);
        ___qtablewidgetitem124->setText(QCoreApplication::translate("MainWindow", "U1RXB", nullptr));
        QTableWidgetItem *___qtablewidgetitem125 = tableWidget_uart_0->verticalHeaderItem(14);
        ___qtablewidgetitem125->setText(QCoreApplication::translate("MainWindow", "U1TXB", nullptr));
        QTableWidgetItem *___qtablewidgetitem126 = tableWidget_uart_1->horizontalHeaderItem(0);
        ___qtablewidgetitem126->setText(QCoreApplication::translate("MainWindow", "REG", nullptr));
        QTableWidgetItem *___qtablewidgetitem127 = tableWidget_uart_1->verticalHeaderItem(0);
        ___qtablewidgetitem127->setText(QCoreApplication::translate("MainWindow", "U1CON2", nullptr));
        QTableWidgetItem *___qtablewidgetitem128 = tableWidget_uart_1->verticalHeaderItem(1);
        ___qtablewidgetitem128->setText(QCoreApplication::translate("MainWindow", "U1CON2.RUNOVF", nullptr));
        QTableWidgetItem *___qtablewidgetitem129 = tableWidget_uart_1->verticalHeaderItem(2);
        ___qtablewidgetitem129->setText(QCoreApplication::translate("MainWindow", "U1CON2.RXPOL", nullptr));
        QTableWidgetItem *___qtablewidgetitem130 = tableWidget_uart_1->verticalHeaderItem(3);
        ___qtablewidgetitem130->setText(QCoreApplication::translate("MainWindow", "U1CON2.STP", nullptr));
        QTableWidgetItem *___qtablewidgetitem131 = tableWidget_uart_1->verticalHeaderItem(4);
        ___qtablewidgetitem131->setText(QCoreApplication::translate("MainWindow", "U1CON2.C0EN", nullptr));
        QTableWidgetItem *___qtablewidgetitem132 = tableWidget_uart_1->verticalHeaderItem(5);
        ___qtablewidgetitem132->setText(QCoreApplication::translate("MainWindow", "U1CON2.TXPOL", nullptr));
        QTableWidgetItem *___qtablewidgetitem133 = tableWidget_uart_1->verticalHeaderItem(6);
        ___qtablewidgetitem133->setText(QCoreApplication::translate("MainWindow", "U1CON2.FLO", nullptr));
        QTableWidgetItem *___qtablewidgetitem134 = tableWidget_uart_1->verticalHeaderItem(7);
        ___qtablewidgetitem134->setText(QCoreApplication::translate("MainWindow", "U1FIFO", nullptr));
        QTableWidgetItem *___qtablewidgetitem135 = tableWidget_uart_1->verticalHeaderItem(8);
        ___qtablewidgetitem135->setText(QCoreApplication::translate("MainWindow", "U1FIFO.TXWRE", nullptr));
        QTableWidgetItem *___qtablewidgetitem136 = tableWidget_uart_1->verticalHeaderItem(9);
        ___qtablewidgetitem136->setText(QCoreApplication::translate("MainWindow", "U1FIFO.STPMD", nullptr));
        QTableWidgetItem *___qtablewidgetitem137 = tableWidget_uart_1->verticalHeaderItem(10);
        ___qtablewidgetitem137->setText(QCoreApplication::translate("MainWindow", "U1FIFO.TXBE", nullptr));
        QTableWidgetItem *___qtablewidgetitem138 = tableWidget_uart_1->verticalHeaderItem(11);
        ___qtablewidgetitem138->setText(QCoreApplication::translate("MainWindow", "U1FIFO.TXBF", nullptr));
        QTableWidgetItem *___qtablewidgetitem139 = tableWidget_uart_1->verticalHeaderItem(12);
        ___qtablewidgetitem139->setText(QCoreApplication::translate("MainWindow", "U1FIFO.RXIDL", nullptr));
        QTableWidgetItem *___qtablewidgetitem140 = tableWidget_uart_1->verticalHeaderItem(13);
        ___qtablewidgetitem140->setText(QCoreApplication::translate("MainWindow", "U1FIFO.XON", nullptr));
        QTableWidgetItem *___qtablewidgetitem141 = tableWidget_uart_1->verticalHeaderItem(14);
        ___qtablewidgetitem141->setText(QCoreApplication::translate("MainWindow", "U1.FIFO.RXBE", nullptr));
        QTableWidgetItem *___qtablewidgetitem142 = tableWidget_uart_1->verticalHeaderItem(15);
        ___qtablewidgetitem142->setText(QCoreApplication::translate("MainWindow", "U1.FIFO.RXBF", nullptr));
        tabs_regs->setTabText(tabs_regs->indexOf(tab_), QCoreApplication::translate("MainWindow", "UART", nullptr));
        QTableWidgetItem *___qtablewidgetitem143 = tableWidget_ports0->horizontalHeaderItem(0);
        ___qtablewidgetitem143->setText(QCoreApplication::translate("MainWindow", "REG", nullptr));
        QTableWidgetItem *___qtablewidgetitem144 = tableWidget_ports0->verticalHeaderItem(0);
        ___qtablewidgetitem144->setText(QCoreApplication::translate("MainWindow", "PORTA", nullptr));
        QTableWidgetItem *___qtablewidgetitem145 = tableWidget_ports0->verticalHeaderItem(1);
        ___qtablewidgetitem145->setText(QCoreApplication::translate("MainWindow", "PORTB", nullptr));
        QTableWidgetItem *___qtablewidgetitem146 = tableWidget_ports0->verticalHeaderItem(2);
        ___qtablewidgetitem146->setText(QCoreApplication::translate("MainWindow", "PORTC", nullptr));
        QTableWidgetItem *___qtablewidgetitem147 = tableWidget_ports0->verticalHeaderItem(3);
        ___qtablewidgetitem147->setText(QCoreApplication::translate("MainWindow", "PORTD", nullptr));
        QTableWidgetItem *___qtablewidgetitem148 = tableWidget_ports0->verticalHeaderItem(4);
        ___qtablewidgetitem148->setText(QCoreApplication::translate("MainWindow", "PORTE", nullptr));
        QTableWidgetItem *___qtablewidgetitem149 = tableWidget_ports0->verticalHeaderItem(5);
        ___qtablewidgetitem149->setText(QCoreApplication::translate("MainWindow", "PORTF", nullptr));
        QTableWidgetItem *___qtablewidgetitem150 = tableWidget_ports0->verticalHeaderItem(6);
        ___qtablewidgetitem150->setText(QCoreApplication::translate("MainWindow", "TRISA", nullptr));
        QTableWidgetItem *___qtablewidgetitem151 = tableWidget_ports0->verticalHeaderItem(7);
        ___qtablewidgetitem151->setText(QCoreApplication::translate("MainWindow", "TRISB", nullptr));
        QTableWidgetItem *___qtablewidgetitem152 = tableWidget_ports0->verticalHeaderItem(8);
        ___qtablewidgetitem152->setText(QCoreApplication::translate("MainWindow", "TRISC", nullptr));
        QTableWidgetItem *___qtablewidgetitem153 = tableWidget_ports0->verticalHeaderItem(9);
        ___qtablewidgetitem153->setText(QCoreApplication::translate("MainWindow", "TRISD", nullptr));
        QTableWidgetItem *___qtablewidgetitem154 = tableWidget_ports0->verticalHeaderItem(10);
        ___qtablewidgetitem154->setText(QCoreApplication::translate("MainWindow", "TRISE", nullptr));
        QTableWidgetItem *___qtablewidgetitem155 = tableWidget_ports0->verticalHeaderItem(11);
        ___qtablewidgetitem155->setText(QCoreApplication::translate("MainWindow", "TRISF", nullptr));
        QTableWidgetItem *___qtablewidgetitem156 = tableWidget_ports1->horizontalHeaderItem(0);
        ___qtablewidgetitem156->setText(QCoreApplication::translate("MainWindow", "REG", nullptr));
        QTableWidgetItem *___qtablewidgetitem157 = tableWidget_ports1->verticalHeaderItem(0);
        ___qtablewidgetitem157->setText(QCoreApplication::translate("MainWindow", "LATA", nullptr));
        QTableWidgetItem *___qtablewidgetitem158 = tableWidget_ports1->verticalHeaderItem(1);
        ___qtablewidgetitem158->setText(QCoreApplication::translate("MainWindow", "LATB", nullptr));
        QTableWidgetItem *___qtablewidgetitem159 = tableWidget_ports1->verticalHeaderItem(2);
        ___qtablewidgetitem159->setText(QCoreApplication::translate("MainWindow", "LATC", nullptr));
        QTableWidgetItem *___qtablewidgetitem160 = tableWidget_ports1->verticalHeaderItem(3);
        ___qtablewidgetitem160->setText(QCoreApplication::translate("MainWindow", "LATD", nullptr));
        QTableWidgetItem *___qtablewidgetitem161 = tableWidget_ports1->verticalHeaderItem(4);
        ___qtablewidgetitem161->setText(QCoreApplication::translate("MainWindow", "LATE", nullptr));
        QTableWidgetItem *___qtablewidgetitem162 = tableWidget_ports1->verticalHeaderItem(5);
        ___qtablewidgetitem162->setText(QCoreApplication::translate("MainWindow", "LATF", nullptr));
        QTableWidgetItem *___qtablewidgetitem163 = tableWidget_ports1->verticalHeaderItem(6);
        ___qtablewidgetitem163->setText(QCoreApplication::translate("MainWindow", "ANSELA", nullptr));
        QTableWidgetItem *___qtablewidgetitem164 = tableWidget_ports1->verticalHeaderItem(7);
        ___qtablewidgetitem164->setText(QCoreApplication::translate("MainWindow", "ANSELB", nullptr));
        QTableWidgetItem *___qtablewidgetitem165 = tableWidget_ports1->verticalHeaderItem(8);
        ___qtablewidgetitem165->setText(QCoreApplication::translate("MainWindow", "ANSELC", nullptr));
        QTableWidgetItem *___qtablewidgetitem166 = tableWidget_ports1->verticalHeaderItem(9);
        ___qtablewidgetitem166->setText(QCoreApplication::translate("MainWindow", "ANSELD", nullptr));
        QTableWidgetItem *___qtablewidgetitem167 = tableWidget_ports1->verticalHeaderItem(10);
        ___qtablewidgetitem167->setText(QCoreApplication::translate("MainWindow", "ANSELE", nullptr));
        QTableWidgetItem *___qtablewidgetitem168 = tableWidget_ports1->verticalHeaderItem(11);
        ___qtablewidgetitem168->setText(QCoreApplication::translate("MainWindow", "ANSELF", nullptr));
        tabs_regs->setTabText(tabs_regs->indexOf(tab_ports_pps), QCoreApplication::translate("MainWindow", "PORTS", nullptr));
        pushButton_add_plot->setText(QCoreApplication::translate("MainWindow", "Add plot", nullptr));
        pushButton_breakpoint_line->setText(QCoreApplication::translate("MainWindow", "Run until line (C):", nullptr));
        pushButton_breakpoint->setText(QCoreApplication::translate("MainWindow", "Run until address:", nullptr));
        pushButton_start->setText(QCoreApplication::translate("MainWindow", "START SIMULATION", nullptr));
        pushButton_disasm->setText(QCoreApplication::translate("MainWindow", "STEP [DISASM]", nullptr));
        QTableWidgetItem *___qtablewidgetitem169 = tableWidget_frs->horizontalHeaderItem(0);
        ___qtablewidgetitem169->setText(QCoreApplication::translate("MainWindow", "Fast Register Stack", nullptr));
        QTableWidgetItem *___qtablewidgetitem170 = tableWidget_frs->verticalHeaderItem(0);
        ___qtablewidgetitem170->setText(QCoreApplication::translate("MainWindow", "STATUS", nullptr));
        QTableWidgetItem *___qtablewidgetitem171 = tableWidget_frs->verticalHeaderItem(1);
        ___qtablewidgetitem171->setText(QCoreApplication::translate("MainWindow", "WREG", nullptr));
        QTableWidgetItem *___qtablewidgetitem172 = tableWidget_frs->verticalHeaderItem(2);
        ___qtablewidgetitem172->setText(QCoreApplication::translate("MainWindow", "BSR", nullptr));
        QTableWidgetItem *___qtablewidgetitem173 = return_stack->horizontalHeaderItem(0);
        ___qtablewidgetitem173->setText(QCoreApplication::translate("MainWindow", "Return Stack", nullptr));
        Memory_Tabs->setTabText(Memory_Tabs->indexOf(AccessBank), QCoreApplication::translate("MainWindow", "Access Bank", nullptr));
        pb_set_bank->setText(QCoreApplication::translate("MainWindow", "Set Register Bank", nullptr));
        Memory_Tabs->setTabText(Memory_Tabs->indexOf(tab_8), QCoreApplication::translate("MainWindow", "Register Page", nullptr));
        Memory_Tabs->setTabText(Memory_Tabs->indexOf(logic_analyzer), QCoreApplication::translate("MainWindow", "Logic analyzer", nullptr));
        pushButton_porta->setText(QCoreApplication::translate("MainWindow", "PORTA", nullptr));
        pushButton_portb->setText(QCoreApplication::translate("MainWindow", "PORTB", nullptr));
        pushButton_portc->setText(QCoreApplication::translate("MainWindow", "PORTC", nullptr));
        pushButton_portd->setText(QCoreApplication::translate("MainWindow", "PORTD", nullptr));
        pushButton_porte->setText(QCoreApplication::translate("MainWindow", "PORTE", nullptr));
        pushButton_portf->setText(QCoreApplication::translate("MainWindow", "PORTF", nullptr));
        Memory_Tabs->setTabText(Memory_Tabs->indexOf(tab_5), QCoreApplication::translate("MainWindow", "Ports", nullptr));
        pushButton_setaddr->setText(QCoreApplication::translate("MainWindow", "Set register [address] to value [value]", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Address [0 - 3FFF]", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Value [0 - 255]", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "UART TX history", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "UART RX history", nullptr));
        checkBox->setText(QCoreApplication::translate("MainWindow", "Enable signal", nullptr));
        radioButton->setText(QCoreApplication::translate("MainWindow", "Sine wave", nullptr));
        radioButton_2->setText(QCoreApplication::translate("MainWindow", "Square wave", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Frequency", nullptr));
        Memory_Tabs->setTabText(Memory_Tabs->indexOf(tab), QCoreApplication::translate("MainWindow", "Signals", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIN_WINDOW_H
