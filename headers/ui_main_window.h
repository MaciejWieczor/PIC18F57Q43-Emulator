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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
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
    QWidget *tab;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_6;
    QTableWidget *tableWidget_instr;
    QHBoxLayout *horizontalLayout_5;
    QTableWidget *tableWidget_cpu;
    QTableWidget *tableWidget_ind_stack;
    QWidget *tab_3;
    QHBoxLayout *horizontalLayout_9;
    QHBoxLayout *horizontalLayout_13;
    QTableWidget *tableWidget_tmr0;
    QTableWidget *tableWidget_4;
    QWidget *tab_4;
    QHBoxLayout *horizontalLayout_15;
    QHBoxLayout *horizontalLayout_14;
    QTableWidget *tableWidget_cpu_4;
    QTableWidget *tableWidget_5;
    QWidget *interrupts;
    QHBoxLayout *horizontalLayout_17;
    QHBoxLayout *horizontalLayout_12;
    QTableWidget *tableWidget_int;
    QTableWidget *tableWidget_pir;
    QWidget *tab_2;
    QHBoxLayout *horizontalLayout_7;
    QHBoxLayout *horizontalLayout_8;
    QTableWidget *tableWidget_cpu_2;
    QTableWidget *tableWidget_3;
    QWidget *tab_6;
    QWidget *tab_7;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_add_plot;
    QPushButton *pushButton;
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
    QTableWidget *tableWidget_2;
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
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        sizePolicy1.setHeightForWidth(tab->sizePolicy().hasHeightForWidth());
        tab->setSizePolicy(sizePolicy1);
        verticalLayout_4 = new QVBoxLayout(tab);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setSizeConstraint(QLayout::SetDefaultConstraint);
        tableWidget_instr = new QTableWidget(tab);
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
        tableWidget_cpu = new QTableWidget(tab);
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

        tableWidget_ind_stack = new QTableWidget(tab);
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

        tabs_regs->addTab(tab, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        horizontalLayout_9 = new QHBoxLayout(tab_3);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        tableWidget_tmr0 = new QTableWidget(tab_3);
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

        tableWidget_4 = new QTableWidget(tab_3);
        if (tableWidget_4->columnCount() < 1)
            tableWidget_4->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem37 = new QTableWidgetItem();
        tableWidget_4->setHorizontalHeaderItem(0, __qtablewidgetitem37);
        if (tableWidget_4->rowCount() < 7)
            tableWidget_4->setRowCount(7);
        QTableWidgetItem *__qtablewidgetitem38 = new QTableWidgetItem();
        tableWidget_4->setVerticalHeaderItem(0, __qtablewidgetitem38);
        QTableWidgetItem *__qtablewidgetitem39 = new QTableWidgetItem();
        tableWidget_4->setVerticalHeaderItem(1, __qtablewidgetitem39);
        QTableWidgetItem *__qtablewidgetitem40 = new QTableWidgetItem();
        tableWidget_4->setVerticalHeaderItem(2, __qtablewidgetitem40);
        QTableWidgetItem *__qtablewidgetitem41 = new QTableWidgetItem();
        tableWidget_4->setVerticalHeaderItem(3, __qtablewidgetitem41);
        QTableWidgetItem *__qtablewidgetitem42 = new QTableWidgetItem();
        tableWidget_4->setVerticalHeaderItem(4, __qtablewidgetitem42);
        QTableWidgetItem *__qtablewidgetitem43 = new QTableWidgetItem();
        tableWidget_4->setVerticalHeaderItem(5, __qtablewidgetitem43);
        QTableWidgetItem *__qtablewidgetitem44 = new QTableWidgetItem();
        tableWidget_4->setVerticalHeaderItem(6, __qtablewidgetitem44);
        tableWidget_4->setObjectName(QString::fromUtf8("tableWidget_4"));
        sizePolicy1.setHeightForWidth(tableWidget_4->sizePolicy().hasHeightForWidth());
        tableWidget_4->setSizePolicy(sizePolicy1);
        tableWidget_4->setMinimumSize(QSize(177, 0));
        tableWidget_4->horizontalHeader()->setDefaultSectionSize(165);

        horizontalLayout_13->addWidget(tableWidget_4);


        horizontalLayout_9->addLayout(horizontalLayout_13);

        tabs_regs->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        horizontalLayout_15 = new QHBoxLayout(tab_4);
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        tableWidget_cpu_4 = new QTableWidget(tab_4);
        if (tableWidget_cpu_4->columnCount() < 1)
            tableWidget_cpu_4->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem45 = new QTableWidgetItem();
        tableWidget_cpu_4->setHorizontalHeaderItem(0, __qtablewidgetitem45);
        if (tableWidget_cpu_4->rowCount() < 9)
            tableWidget_cpu_4->setRowCount(9);
        QTableWidgetItem *__qtablewidgetitem46 = new QTableWidgetItem();
        tableWidget_cpu_4->setVerticalHeaderItem(0, __qtablewidgetitem46);
        QTableWidgetItem *__qtablewidgetitem47 = new QTableWidgetItem();
        tableWidget_cpu_4->setVerticalHeaderItem(1, __qtablewidgetitem47);
        QTableWidgetItem *__qtablewidgetitem48 = new QTableWidgetItem();
        tableWidget_cpu_4->setVerticalHeaderItem(2, __qtablewidgetitem48);
        QTableWidgetItem *__qtablewidgetitem49 = new QTableWidgetItem();
        tableWidget_cpu_4->setVerticalHeaderItem(3, __qtablewidgetitem49);
        QTableWidgetItem *__qtablewidgetitem50 = new QTableWidgetItem();
        tableWidget_cpu_4->setVerticalHeaderItem(4, __qtablewidgetitem50);
        QTableWidgetItem *__qtablewidgetitem51 = new QTableWidgetItem();
        tableWidget_cpu_4->setVerticalHeaderItem(5, __qtablewidgetitem51);
        QTableWidgetItem *__qtablewidgetitem52 = new QTableWidgetItem();
        tableWidget_cpu_4->setVerticalHeaderItem(6, __qtablewidgetitem52);
        QTableWidgetItem *__qtablewidgetitem53 = new QTableWidgetItem();
        tableWidget_cpu_4->setVerticalHeaderItem(7, __qtablewidgetitem53);
        QTableWidgetItem *__qtablewidgetitem54 = new QTableWidgetItem();
        tableWidget_cpu_4->setVerticalHeaderItem(8, __qtablewidgetitem54);
        tableWidget_cpu_4->setObjectName(QString::fromUtf8("tableWidget_cpu_4"));
        sizePolicy1.setHeightForWidth(tableWidget_cpu_4->sizePolicy().hasHeightForWidth());
        tableWidget_cpu_4->setSizePolicy(sizePolicy1);
        tableWidget_cpu_4->setMinimumSize(QSize(177, 210));
        tableWidget_cpu_4->horizontalHeader()->setMinimumSectionSize(50);
        tableWidget_cpu_4->horizontalHeader()->setDefaultSectionSize(165);
        tableWidget_cpu_4->verticalHeader()->setDefaultSectionSize(30);

        horizontalLayout_14->addWidget(tableWidget_cpu_4);

        tableWidget_5 = new QTableWidget(tab_4);
        if (tableWidget_5->columnCount() < 1)
            tableWidget_5->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem55 = new QTableWidgetItem();
        tableWidget_5->setHorizontalHeaderItem(0, __qtablewidgetitem55);
        if (tableWidget_5->rowCount() < 7)
            tableWidget_5->setRowCount(7);
        QTableWidgetItem *__qtablewidgetitem56 = new QTableWidgetItem();
        tableWidget_5->setVerticalHeaderItem(0, __qtablewidgetitem56);
        QTableWidgetItem *__qtablewidgetitem57 = new QTableWidgetItem();
        tableWidget_5->setVerticalHeaderItem(1, __qtablewidgetitem57);
        QTableWidgetItem *__qtablewidgetitem58 = new QTableWidgetItem();
        tableWidget_5->setVerticalHeaderItem(2, __qtablewidgetitem58);
        QTableWidgetItem *__qtablewidgetitem59 = new QTableWidgetItem();
        tableWidget_5->setVerticalHeaderItem(3, __qtablewidgetitem59);
        QTableWidgetItem *__qtablewidgetitem60 = new QTableWidgetItem();
        tableWidget_5->setVerticalHeaderItem(4, __qtablewidgetitem60);
        QTableWidgetItem *__qtablewidgetitem61 = new QTableWidgetItem();
        tableWidget_5->setVerticalHeaderItem(5, __qtablewidgetitem61);
        QTableWidgetItem *__qtablewidgetitem62 = new QTableWidgetItem();
        tableWidget_5->setVerticalHeaderItem(6, __qtablewidgetitem62);
        tableWidget_5->setObjectName(QString::fromUtf8("tableWidget_5"));
        sizePolicy1.setHeightForWidth(tableWidget_5->sizePolicy().hasHeightForWidth());
        tableWidget_5->setSizePolicy(sizePolicy1);
        tableWidget_5->setMinimumSize(QSize(177, 0));
        tableWidget_5->horizontalHeader()->setDefaultSectionSize(165);

        horizontalLayout_14->addWidget(tableWidget_5);


        horizontalLayout_15->addLayout(horizontalLayout_14);

        tabs_regs->addTab(tab_4, QString());
        interrupts = new QWidget();
        interrupts->setObjectName(QString::fromUtf8("interrupts"));
        horizontalLayout_17 = new QHBoxLayout(interrupts);
        horizontalLayout_17->setObjectName(QString::fromUtf8("horizontalLayout_17"));
        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        tableWidget_int = new QTableWidget(interrupts);
        if (tableWidget_int->columnCount() < 1)
            tableWidget_int->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem63 = new QTableWidgetItem();
        tableWidget_int->setHorizontalHeaderItem(0, __qtablewidgetitem63);
        if (tableWidget_int->rowCount() < 10)
            tableWidget_int->setRowCount(10);
        QTableWidgetItem *__qtablewidgetitem64 = new QTableWidgetItem();
        tableWidget_int->setVerticalHeaderItem(0, __qtablewidgetitem64);
        QTableWidgetItem *__qtablewidgetitem65 = new QTableWidgetItem();
        tableWidget_int->setVerticalHeaderItem(1, __qtablewidgetitem65);
        QTableWidgetItem *__qtablewidgetitem66 = new QTableWidgetItem();
        tableWidget_int->setVerticalHeaderItem(2, __qtablewidgetitem66);
        QTableWidgetItem *__qtablewidgetitem67 = new QTableWidgetItem();
        tableWidget_int->setVerticalHeaderItem(3, __qtablewidgetitem67);
        QTableWidgetItem *__qtablewidgetitem68 = new QTableWidgetItem();
        tableWidget_int->setVerticalHeaderItem(4, __qtablewidgetitem68);
        QTableWidgetItem *__qtablewidgetitem69 = new QTableWidgetItem();
        tableWidget_int->setVerticalHeaderItem(5, __qtablewidgetitem69);
        QTableWidgetItem *__qtablewidgetitem70 = new QTableWidgetItem();
        tableWidget_int->setVerticalHeaderItem(6, __qtablewidgetitem70);
        QTableWidgetItem *__qtablewidgetitem71 = new QTableWidgetItem();
        tableWidget_int->setVerticalHeaderItem(7, __qtablewidgetitem71);
        QTableWidgetItem *__qtablewidgetitem72 = new QTableWidgetItem();
        tableWidget_int->setVerticalHeaderItem(8, __qtablewidgetitem72);
        QTableWidgetItem *__qtablewidgetitem73 = new QTableWidgetItem();
        tableWidget_int->setVerticalHeaderItem(9, __qtablewidgetitem73);
        tableWidget_int->setObjectName(QString::fromUtf8("tableWidget_int"));
        sizePolicy1.setHeightForWidth(tableWidget_int->sizePolicy().hasHeightForWidth());
        tableWidget_int->setSizePolicy(sizePolicy1);
        tableWidget_int->setMinimumSize(QSize(177, 210));
        tableWidget_int->horizontalHeader()->setMinimumSectionSize(50);
        tableWidget_int->horizontalHeader()->setDefaultSectionSize(165);
        tableWidget_int->verticalHeader()->setDefaultSectionSize(30);

        horizontalLayout_12->addWidget(tableWidget_int);

        tableWidget_pir = new QTableWidget(interrupts);
        if (tableWidget_pir->columnCount() < 3)
            tableWidget_pir->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem74 = new QTableWidgetItem();
        tableWidget_pir->setHorizontalHeaderItem(0, __qtablewidgetitem74);
        QTableWidgetItem *__qtablewidgetitem75 = new QTableWidgetItem();
        tableWidget_pir->setHorizontalHeaderItem(1, __qtablewidgetitem75);
        QTableWidgetItem *__qtablewidgetitem76 = new QTableWidgetItem();
        tableWidget_pir->setHorizontalHeaderItem(2, __qtablewidgetitem76);
        if (tableWidget_pir->rowCount() < 13)
            tableWidget_pir->setRowCount(13);
        QTableWidgetItem *__qtablewidgetitem77 = new QTableWidgetItem();
        tableWidget_pir->setVerticalHeaderItem(0, __qtablewidgetitem77);
        QTableWidgetItem *__qtablewidgetitem78 = new QTableWidgetItem();
        tableWidget_pir->setVerticalHeaderItem(1, __qtablewidgetitem78);
        QTableWidgetItem *__qtablewidgetitem79 = new QTableWidgetItem();
        tableWidget_pir->setVerticalHeaderItem(2, __qtablewidgetitem79);
        QTableWidgetItem *__qtablewidgetitem80 = new QTableWidgetItem();
        tableWidget_pir->setVerticalHeaderItem(3, __qtablewidgetitem80);
        QTableWidgetItem *__qtablewidgetitem81 = new QTableWidgetItem();
        tableWidget_pir->setVerticalHeaderItem(4, __qtablewidgetitem81);
        QTableWidgetItem *__qtablewidgetitem82 = new QTableWidgetItem();
        tableWidget_pir->setVerticalHeaderItem(5, __qtablewidgetitem82);
        QTableWidgetItem *__qtablewidgetitem83 = new QTableWidgetItem();
        tableWidget_pir->setVerticalHeaderItem(6, __qtablewidgetitem83);
        QTableWidgetItem *__qtablewidgetitem84 = new QTableWidgetItem();
        tableWidget_pir->setVerticalHeaderItem(7, __qtablewidgetitem84);
        QTableWidgetItem *__qtablewidgetitem85 = new QTableWidgetItem();
        tableWidget_pir->setVerticalHeaderItem(8, __qtablewidgetitem85);
        QTableWidgetItem *__qtablewidgetitem86 = new QTableWidgetItem();
        tableWidget_pir->setVerticalHeaderItem(9, __qtablewidgetitem86);
        QTableWidgetItem *__qtablewidgetitem87 = new QTableWidgetItem();
        tableWidget_pir->setVerticalHeaderItem(10, __qtablewidgetitem87);
        QTableWidgetItem *__qtablewidgetitem88 = new QTableWidgetItem();
        tableWidget_pir->setVerticalHeaderItem(11, __qtablewidgetitem88);
        QTableWidgetItem *__qtablewidgetitem89 = new QTableWidgetItem();
        tableWidget_pir->setVerticalHeaderItem(12, __qtablewidgetitem89);
        tableWidget_pir->setObjectName(QString::fromUtf8("tableWidget_pir"));
        sizePolicy1.setHeightForWidth(tableWidget_pir->sizePolicy().hasHeightForWidth());
        tableWidget_pir->setSizePolicy(sizePolicy1);
        tableWidget_pir->setMinimumSize(QSize(177, 0));
        tableWidget_pir->horizontalHeader()->setDefaultSectionSize(70);
        tableWidget_pir->horizontalHeader()->setStretchLastSection(true);
        tableWidget_pir->verticalHeader()->setStretchLastSection(true);

        horizontalLayout_12->addWidget(tableWidget_pir);


        horizontalLayout_17->addLayout(horizontalLayout_12);

        tabs_regs->addTab(interrupts, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        horizontalLayout_7 = new QHBoxLayout(tab_2);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        tableWidget_cpu_2 = new QTableWidget(tab_2);
        if (tableWidget_cpu_2->columnCount() < 1)
            tableWidget_cpu_2->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem90 = new QTableWidgetItem();
        tableWidget_cpu_2->setHorizontalHeaderItem(0, __qtablewidgetitem90);
        if (tableWidget_cpu_2->rowCount() < 9)
            tableWidget_cpu_2->setRowCount(9);
        QTableWidgetItem *__qtablewidgetitem91 = new QTableWidgetItem();
        tableWidget_cpu_2->setVerticalHeaderItem(0, __qtablewidgetitem91);
        QTableWidgetItem *__qtablewidgetitem92 = new QTableWidgetItem();
        tableWidget_cpu_2->setVerticalHeaderItem(1, __qtablewidgetitem92);
        QTableWidgetItem *__qtablewidgetitem93 = new QTableWidgetItem();
        tableWidget_cpu_2->setVerticalHeaderItem(2, __qtablewidgetitem93);
        QTableWidgetItem *__qtablewidgetitem94 = new QTableWidgetItem();
        tableWidget_cpu_2->setVerticalHeaderItem(3, __qtablewidgetitem94);
        QTableWidgetItem *__qtablewidgetitem95 = new QTableWidgetItem();
        tableWidget_cpu_2->setVerticalHeaderItem(4, __qtablewidgetitem95);
        QTableWidgetItem *__qtablewidgetitem96 = new QTableWidgetItem();
        tableWidget_cpu_2->setVerticalHeaderItem(5, __qtablewidgetitem96);
        QTableWidgetItem *__qtablewidgetitem97 = new QTableWidgetItem();
        tableWidget_cpu_2->setVerticalHeaderItem(6, __qtablewidgetitem97);
        QTableWidgetItem *__qtablewidgetitem98 = new QTableWidgetItem();
        tableWidget_cpu_2->setVerticalHeaderItem(7, __qtablewidgetitem98);
        QTableWidgetItem *__qtablewidgetitem99 = new QTableWidgetItem();
        tableWidget_cpu_2->setVerticalHeaderItem(8, __qtablewidgetitem99);
        tableWidget_cpu_2->setObjectName(QString::fromUtf8("tableWidget_cpu_2"));
        sizePolicy1.setHeightForWidth(tableWidget_cpu_2->sizePolicy().hasHeightForWidth());
        tableWidget_cpu_2->setSizePolicy(sizePolicy1);
        tableWidget_cpu_2->setMinimumSize(QSize(177, 210));
        tableWidget_cpu_2->horizontalHeader()->setMinimumSectionSize(50);
        tableWidget_cpu_2->horizontalHeader()->setDefaultSectionSize(165);
        tableWidget_cpu_2->verticalHeader()->setDefaultSectionSize(30);

        horizontalLayout_8->addWidget(tableWidget_cpu_2);

        tableWidget_3 = new QTableWidget(tab_2);
        if (tableWidget_3->columnCount() < 1)
            tableWidget_3->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem100 = new QTableWidgetItem();
        tableWidget_3->setHorizontalHeaderItem(0, __qtablewidgetitem100);
        if (tableWidget_3->rowCount() < 7)
            tableWidget_3->setRowCount(7);
        QTableWidgetItem *__qtablewidgetitem101 = new QTableWidgetItem();
        tableWidget_3->setVerticalHeaderItem(0, __qtablewidgetitem101);
        QTableWidgetItem *__qtablewidgetitem102 = new QTableWidgetItem();
        tableWidget_3->setVerticalHeaderItem(1, __qtablewidgetitem102);
        QTableWidgetItem *__qtablewidgetitem103 = new QTableWidgetItem();
        tableWidget_3->setVerticalHeaderItem(2, __qtablewidgetitem103);
        QTableWidgetItem *__qtablewidgetitem104 = new QTableWidgetItem();
        tableWidget_3->setVerticalHeaderItem(3, __qtablewidgetitem104);
        QTableWidgetItem *__qtablewidgetitem105 = new QTableWidgetItem();
        tableWidget_3->setVerticalHeaderItem(4, __qtablewidgetitem105);
        QTableWidgetItem *__qtablewidgetitem106 = new QTableWidgetItem();
        tableWidget_3->setVerticalHeaderItem(5, __qtablewidgetitem106);
        QTableWidgetItem *__qtablewidgetitem107 = new QTableWidgetItem();
        tableWidget_3->setVerticalHeaderItem(6, __qtablewidgetitem107);
        tableWidget_3->setObjectName(QString::fromUtf8("tableWidget_3"));
        sizePolicy1.setHeightForWidth(tableWidget_3->sizePolicy().hasHeightForWidth());
        tableWidget_3->setSizePolicy(sizePolicy1);
        tableWidget_3->setMinimumSize(QSize(177, 0));
        tableWidget_3->horizontalHeader()->setDefaultSectionSize(165);

        horizontalLayout_8->addWidget(tableWidget_3);


        horizontalLayout_7->addLayout(horizontalLayout_8);

        tabs_regs->addTab(tab_2, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QString::fromUtf8("tab_6"));
        tabs_regs->addTab(tab_6, QString());
        tab_7 = new QWidget();
        tab_7->setObjectName(QString::fromUtf8("tab_7"));
        tabs_regs->addTab(tab_7, QString());

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

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        sizePolicy3.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy3);

        verticalLayout->addWidget(pushButton);

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
        tableWidget_2 = new QTableWidget(AccessBank);
        if (tableWidget_2->columnCount() < 1)
            tableWidget_2->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem108 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(0, __qtablewidgetitem108);
        if (tableWidget_2->rowCount() < 3)
            tableWidget_2->setRowCount(3);
        QTableWidgetItem *__qtablewidgetitem109 = new QTableWidgetItem();
        tableWidget_2->setVerticalHeaderItem(0, __qtablewidgetitem109);
        QTableWidgetItem *__qtablewidgetitem110 = new QTableWidgetItem();
        tableWidget_2->setVerticalHeaderItem(1, __qtablewidgetitem110);
        QTableWidgetItem *__qtablewidgetitem111 = new QTableWidgetItem();
        tableWidget_2->setVerticalHeaderItem(2, __qtablewidgetitem111);
        tableWidget_2->setObjectName(QString::fromUtf8("tableWidget_2"));
        tableWidget_2->setRowCount(3);
        tableWidget_2->setColumnCount(1);
        tableWidget_2->horizontalHeader()->setStretchLastSection(true);
        tableWidget_2->verticalHeader()->setStretchLastSection(true);

        verticalLayout_5->addWidget(tableWidget_2);

        return_stack = new QTableWidget(AccessBank);
        if (return_stack->columnCount() < 1)
            return_stack->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem112 = new QTableWidgetItem();
        return_stack->setHorizontalHeaderItem(0, __qtablewidgetitem112);
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
        bank_select_table->setObjectName(QString::fromUtf8("bank_select_table"));

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

        tabs_regs->setCurrentIndex(6);
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
        tabs_regs->setTabText(tabs_regs->indexOf(tab), QCoreApplication::translate("MainWindow", "CPU", nullptr));
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
        QTableWidgetItem *___qtablewidgetitem37 = tableWidget_4->horizontalHeaderItem(0);
        ___qtablewidgetitem37->setText(QCoreApplication::translate("MainWindow", "REG", nullptr));
        QTableWidgetItem *___qtablewidgetitem38 = tableWidget_4->verticalHeaderItem(0);
        ___qtablewidgetitem38->setText(QCoreApplication::translate("MainWindow", "A", nullptr));
        QTableWidgetItem *___qtablewidgetitem39 = tableWidget_4->verticalHeaderItem(1);
        ___qtablewidgetitem39->setText(QCoreApplication::translate("MainWindow", "B", nullptr));
        QTableWidgetItem *___qtablewidgetitem40 = tableWidget_4->verticalHeaderItem(2);
        ___qtablewidgetitem40->setText(QCoreApplication::translate("MainWindow", "C", nullptr));
        QTableWidgetItem *___qtablewidgetitem41 = tableWidget_4->verticalHeaderItem(3);
        ___qtablewidgetitem41->setText(QCoreApplication::translate("MainWindow", "D", nullptr));
        QTableWidgetItem *___qtablewidgetitem42 = tableWidget_4->verticalHeaderItem(4);
        ___qtablewidgetitem42->setText(QCoreApplication::translate("MainWindow", "E", nullptr));
        QTableWidgetItem *___qtablewidgetitem43 = tableWidget_4->verticalHeaderItem(5);
        ___qtablewidgetitem43->setText(QCoreApplication::translate("MainWindow", "F", nullptr));
        QTableWidgetItem *___qtablewidgetitem44 = tableWidget_4->verticalHeaderItem(6);
        ___qtablewidgetitem44->setText(QCoreApplication::translate("MainWindow", "G", nullptr));
        tabs_regs->setTabText(tabs_regs->indexOf(tab_3), QCoreApplication::translate("MainWindow", "TMR0/1", nullptr));
        QTableWidgetItem *___qtablewidgetitem45 = tableWidget_cpu_4->horizontalHeaderItem(0);
        ___qtablewidgetitem45->setText(QCoreApplication::translate("MainWindow", "REG", nullptr));
        QTableWidgetItem *___qtablewidgetitem46 = tableWidget_cpu_4->verticalHeaderItem(0);
        ___qtablewidgetitem46->setText(QCoreApplication::translate("MainWindow", "WREG", nullptr));
        QTableWidgetItem *___qtablewidgetitem47 = tableWidget_cpu_4->verticalHeaderItem(1);
        ___qtablewidgetitem47->setText(QCoreApplication::translate("MainWindow", "STATUS.N", nullptr));
        QTableWidgetItem *___qtablewidgetitem48 = tableWidget_cpu_4->verticalHeaderItem(2);
        ___qtablewidgetitem48->setText(QCoreApplication::translate("MainWindow", "STATUS.OV", nullptr));
        QTableWidgetItem *___qtablewidgetitem49 = tableWidget_cpu_4->verticalHeaderItem(3);
        ___qtablewidgetitem49->setText(QCoreApplication::translate("MainWindow", "STATUS.Z", nullptr));
        QTableWidgetItem *___qtablewidgetitem50 = tableWidget_cpu_4->verticalHeaderItem(4);
        ___qtablewidgetitem50->setText(QCoreApplication::translate("MainWindow", "STATUS.DC", nullptr));
        QTableWidgetItem *___qtablewidgetitem51 = tableWidget_cpu_4->verticalHeaderItem(5);
        ___qtablewidgetitem51->setText(QCoreApplication::translate("MainWindow", "STATUS.C", nullptr));
        QTableWidgetItem *___qtablewidgetitem52 = tableWidget_cpu_4->verticalHeaderItem(6);
        ___qtablewidgetitem52->setText(QCoreApplication::translate("MainWindow", "BSR", nullptr));
        QTableWidgetItem *___qtablewidgetitem53 = tableWidget_cpu_4->verticalHeaderItem(7);
        ___qtablewidgetitem53->setText(QCoreApplication::translate("MainWindow", "B", nullptr));
        QTableWidgetItem *___qtablewidgetitem54 = tableWidget_cpu_4->verticalHeaderItem(8);
        ___qtablewidgetitem54->setText(QCoreApplication::translate("MainWindow", "C", nullptr));
        QTableWidgetItem *___qtablewidgetitem55 = tableWidget_5->horizontalHeaderItem(0);
        ___qtablewidgetitem55->setText(QCoreApplication::translate("MainWindow", "REG", nullptr));
        QTableWidgetItem *___qtablewidgetitem56 = tableWidget_5->verticalHeaderItem(0);
        ___qtablewidgetitem56->setText(QCoreApplication::translate("MainWindow", "A", nullptr));
        QTableWidgetItem *___qtablewidgetitem57 = tableWidget_5->verticalHeaderItem(1);
        ___qtablewidgetitem57->setText(QCoreApplication::translate("MainWindow", "B", nullptr));
        QTableWidgetItem *___qtablewidgetitem58 = tableWidget_5->verticalHeaderItem(2);
        ___qtablewidgetitem58->setText(QCoreApplication::translate("MainWindow", "C", nullptr));
        QTableWidgetItem *___qtablewidgetitem59 = tableWidget_5->verticalHeaderItem(3);
        ___qtablewidgetitem59->setText(QCoreApplication::translate("MainWindow", "D", nullptr));
        QTableWidgetItem *___qtablewidgetitem60 = tableWidget_5->verticalHeaderItem(4);
        ___qtablewidgetitem60->setText(QCoreApplication::translate("MainWindow", "E", nullptr));
        QTableWidgetItem *___qtablewidgetitem61 = tableWidget_5->verticalHeaderItem(5);
        ___qtablewidgetitem61->setText(QCoreApplication::translate("MainWindow", "F", nullptr));
        QTableWidgetItem *___qtablewidgetitem62 = tableWidget_5->verticalHeaderItem(6);
        ___qtablewidgetitem62->setText(QCoreApplication::translate("MainWindow", "G", nullptr));
        tabs_regs->setTabText(tabs_regs->indexOf(tab_4), QCoreApplication::translate("MainWindow", "TMR2/3", nullptr));
        QTableWidgetItem *___qtablewidgetitem63 = tableWidget_int->horizontalHeaderItem(0);
        ___qtablewidgetitem63->setText(QCoreApplication::translate("MainWindow", "REG", nullptr));
        QTableWidgetItem *___qtablewidgetitem64 = tableWidget_int->verticalHeaderItem(0);
        ___qtablewidgetitem64->setText(QCoreApplication::translate("MainWindow", "INTCON0", nullptr));
        QTableWidgetItem *___qtablewidgetitem65 = tableWidget_int->verticalHeaderItem(1);
        ___qtablewidgetitem65->setText(QCoreApplication::translate("MainWindow", "INTCON0.GIEH", nullptr));
        QTableWidgetItem *___qtablewidgetitem66 = tableWidget_int->verticalHeaderItem(2);
        ___qtablewidgetitem66->setText(QCoreApplication::translate("MainWindow", "INTCON0.GIEL", nullptr));
        QTableWidgetItem *___qtablewidgetitem67 = tableWidget_int->verticalHeaderItem(3);
        ___qtablewidgetitem67->setText(QCoreApplication::translate("MainWindow", "INTCON0.IPEN", nullptr));
        QTableWidgetItem *___qtablewidgetitem68 = tableWidget_int->verticalHeaderItem(4);
        ___qtablewidgetitem68->setText(QCoreApplication::translate("MainWindow", "INTCON0.INT2EDG", nullptr));
        QTableWidgetItem *___qtablewidgetitem69 = tableWidget_int->verticalHeaderItem(5);
        ___qtablewidgetitem69->setText(QCoreApplication::translate("MainWindow", "INTCON0.INT1EDG", nullptr));
        QTableWidgetItem *___qtablewidgetitem70 = tableWidget_int->verticalHeaderItem(6);
        ___qtablewidgetitem70->setText(QCoreApplication::translate("MainWindow", "INTCON0.INT0EDG", nullptr));
        QTableWidgetItem *___qtablewidgetitem71 = tableWidget_int->verticalHeaderItem(7);
        ___qtablewidgetitem71->setText(QCoreApplication::translate("MainWindow", "INTCON1", nullptr));
        QTableWidgetItem *___qtablewidgetitem72 = tableWidget_int->verticalHeaderItem(8);
        ___qtablewidgetitem72->setText(QCoreApplication::translate("MainWindow", "INTCON1.STAT", nullptr));
        QTableWidgetItem *___qtablewidgetitem73 = tableWidget_int->verticalHeaderItem(9);
        ___qtablewidgetitem73->setText(QCoreApplication::translate("MainWindow", "IVTAD", nullptr));
        QTableWidgetItem *___qtablewidgetitem74 = tableWidget_pir->horizontalHeaderItem(0);
        ___qtablewidgetitem74->setText(QCoreApplication::translate("MainWindow", "PIR", nullptr));
        QTableWidgetItem *___qtablewidgetitem75 = tableWidget_pir->horizontalHeaderItem(1);
        ___qtablewidgetitem75->setText(QCoreApplication::translate("MainWindow", "PIE", nullptr));
        QTableWidgetItem *___qtablewidgetitem76 = tableWidget_pir->horizontalHeaderItem(2);
        ___qtablewidgetitem76->setText(QCoreApplication::translate("MainWindow", "IPR", nullptr));
        QTableWidgetItem *___qtablewidgetitem77 = tableWidget_pir->verticalHeaderItem(0);
        ___qtablewidgetitem77->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        QTableWidgetItem *___qtablewidgetitem78 = tableWidget_pir->verticalHeaderItem(1);
        ___qtablewidgetitem78->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        QTableWidgetItem *___qtablewidgetitem79 = tableWidget_pir->verticalHeaderItem(2);
        ___qtablewidgetitem79->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        QTableWidgetItem *___qtablewidgetitem80 = tableWidget_pir->verticalHeaderItem(3);
        ___qtablewidgetitem80->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        QTableWidgetItem *___qtablewidgetitem81 = tableWidget_pir->verticalHeaderItem(4);
        ___qtablewidgetitem81->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        QTableWidgetItem *___qtablewidgetitem82 = tableWidget_pir->verticalHeaderItem(5);
        ___qtablewidgetitem82->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        QTableWidgetItem *___qtablewidgetitem83 = tableWidget_pir->verticalHeaderItem(6);
        ___qtablewidgetitem83->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        QTableWidgetItem *___qtablewidgetitem84 = tableWidget_pir->verticalHeaderItem(7);
        ___qtablewidgetitem84->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
        QTableWidgetItem *___qtablewidgetitem85 = tableWidget_pir->verticalHeaderItem(8);
        ___qtablewidgetitem85->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
        QTableWidgetItem *___qtablewidgetitem86 = tableWidget_pir->verticalHeaderItem(9);
        ___qtablewidgetitem86->setText(QCoreApplication::translate("MainWindow", "9", nullptr));
        QTableWidgetItem *___qtablewidgetitem87 = tableWidget_pir->verticalHeaderItem(10);
        ___qtablewidgetitem87->setText(QCoreApplication::translate("MainWindow", "10", nullptr));
        QTableWidgetItem *___qtablewidgetitem88 = tableWidget_pir->verticalHeaderItem(11);
        ___qtablewidgetitem88->setText(QCoreApplication::translate("MainWindow", "11", nullptr));
        QTableWidgetItem *___qtablewidgetitem89 = tableWidget_pir->verticalHeaderItem(12);
        ___qtablewidgetitem89->setText(QCoreApplication::translate("MainWindow", "12", nullptr));
        tabs_regs->setTabText(tabs_regs->indexOf(interrupts), QCoreApplication::translate("MainWindow", "INTERRUPTS", nullptr));
        QTableWidgetItem *___qtablewidgetitem90 = tableWidget_cpu_2->horizontalHeaderItem(0);
        ___qtablewidgetitem90->setText(QCoreApplication::translate("MainWindow", "REG", nullptr));
        QTableWidgetItem *___qtablewidgetitem91 = tableWidget_cpu_2->verticalHeaderItem(0);
        ___qtablewidgetitem91->setText(QCoreApplication::translate("MainWindow", "WREG", nullptr));
        QTableWidgetItem *___qtablewidgetitem92 = tableWidget_cpu_2->verticalHeaderItem(1);
        ___qtablewidgetitem92->setText(QCoreApplication::translate("MainWindow", "STATUS.N", nullptr));
        QTableWidgetItem *___qtablewidgetitem93 = tableWidget_cpu_2->verticalHeaderItem(2);
        ___qtablewidgetitem93->setText(QCoreApplication::translate("MainWindow", "STATUS.OV", nullptr));
        QTableWidgetItem *___qtablewidgetitem94 = tableWidget_cpu_2->verticalHeaderItem(3);
        ___qtablewidgetitem94->setText(QCoreApplication::translate("MainWindow", "STATUS.Z", nullptr));
        QTableWidgetItem *___qtablewidgetitem95 = tableWidget_cpu_2->verticalHeaderItem(4);
        ___qtablewidgetitem95->setText(QCoreApplication::translate("MainWindow", "STATUS.DC", nullptr));
        QTableWidgetItem *___qtablewidgetitem96 = tableWidget_cpu_2->verticalHeaderItem(5);
        ___qtablewidgetitem96->setText(QCoreApplication::translate("MainWindow", "STATUS.C", nullptr));
        QTableWidgetItem *___qtablewidgetitem97 = tableWidget_cpu_2->verticalHeaderItem(6);
        ___qtablewidgetitem97->setText(QCoreApplication::translate("MainWindow", "BSR", nullptr));
        QTableWidgetItem *___qtablewidgetitem98 = tableWidget_cpu_2->verticalHeaderItem(7);
        ___qtablewidgetitem98->setText(QCoreApplication::translate("MainWindow", "B", nullptr));
        QTableWidgetItem *___qtablewidgetitem99 = tableWidget_cpu_2->verticalHeaderItem(8);
        ___qtablewidgetitem99->setText(QCoreApplication::translate("MainWindow", "C", nullptr));
        QTableWidgetItem *___qtablewidgetitem100 = tableWidget_3->horizontalHeaderItem(0);
        ___qtablewidgetitem100->setText(QCoreApplication::translate("MainWindow", "REG", nullptr));
        QTableWidgetItem *___qtablewidgetitem101 = tableWidget_3->verticalHeaderItem(0);
        ___qtablewidgetitem101->setText(QCoreApplication::translate("MainWindow", "A", nullptr));
        QTableWidgetItem *___qtablewidgetitem102 = tableWidget_3->verticalHeaderItem(1);
        ___qtablewidgetitem102->setText(QCoreApplication::translate("MainWindow", "B", nullptr));
        QTableWidgetItem *___qtablewidgetitem103 = tableWidget_3->verticalHeaderItem(2);
        ___qtablewidgetitem103->setText(QCoreApplication::translate("MainWindow", "C", nullptr));
        QTableWidgetItem *___qtablewidgetitem104 = tableWidget_3->verticalHeaderItem(3);
        ___qtablewidgetitem104->setText(QCoreApplication::translate("MainWindow", "D", nullptr));
        QTableWidgetItem *___qtablewidgetitem105 = tableWidget_3->verticalHeaderItem(4);
        ___qtablewidgetitem105->setText(QCoreApplication::translate("MainWindow", "E", nullptr));
        QTableWidgetItem *___qtablewidgetitem106 = tableWidget_3->verticalHeaderItem(5);
        ___qtablewidgetitem106->setText(QCoreApplication::translate("MainWindow", "F", nullptr));
        QTableWidgetItem *___qtablewidgetitem107 = tableWidget_3->verticalHeaderItem(6);
        ___qtablewidgetitem107->setText(QCoreApplication::translate("MainWindow", "G", nullptr));
        tabs_regs->setTabText(tabs_regs->indexOf(tab_2), QCoreApplication::translate("MainWindow", "FSR", nullptr));
        tabs_regs->setTabText(tabs_regs->indexOf(tab_6), QCoreApplication::translate("MainWindow", "DMA", nullptr));
        tabs_regs->setTabText(tabs_regs->indexOf(tab_7), QCoreApplication::translate("MainWindow", "Placeholder", nullptr));
        pushButton_add_plot->setText(QCoreApplication::translate("MainWindow", "Add plot", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Run until line (C):", nullptr));
        pushButton_breakpoint->setText(QCoreApplication::translate("MainWindow", "Run until address:", nullptr));
        pushButton_start->setText(QCoreApplication::translate("MainWindow", "START SIMULATION", nullptr));
        pushButton_disasm->setText(QCoreApplication::translate("MainWindow", "STEP [DISASM]", nullptr));
        QTableWidgetItem *___qtablewidgetitem108 = tableWidget_2->horizontalHeaderItem(0);
        ___qtablewidgetitem108->setText(QCoreApplication::translate("MainWindow", "Fast Register Stack", nullptr));
        QTableWidgetItem *___qtablewidgetitem109 = tableWidget_2->verticalHeaderItem(0);
        ___qtablewidgetitem109->setText(QCoreApplication::translate("MainWindow", "STATUS", nullptr));
        QTableWidgetItem *___qtablewidgetitem110 = tableWidget_2->verticalHeaderItem(1);
        ___qtablewidgetitem110->setText(QCoreApplication::translate("MainWindow", "WREG", nullptr));
        QTableWidgetItem *___qtablewidgetitem111 = tableWidget_2->verticalHeaderItem(2);
        ___qtablewidgetitem111->setText(QCoreApplication::translate("MainWindow", "BSR", nullptr));
        QTableWidgetItem *___qtablewidgetitem112 = return_stack->horizontalHeaderItem(0);
        ___qtablewidgetitem112->setText(QCoreApplication::translate("MainWindow", "Return Stack", nullptr));
        Memory_Tabs->setTabText(Memory_Tabs->indexOf(AccessBank), QCoreApplication::translate("MainWindow", "Access Bank", nullptr));
        pb_set_bank->setText(QCoreApplication::translate("MainWindow", "Set Register Bank", nullptr));
        Memory_Tabs->setTabText(Memory_Tabs->indexOf(tab_8), QCoreApplication::translate("MainWindow", "Strona", nullptr));
        Memory_Tabs->setTabText(Memory_Tabs->indexOf(logic_analyzer), QCoreApplication::translate("MainWindow", "Logic analyzer", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIN_WINDOW_H
