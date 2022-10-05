#include "main_window.h"

Ui_MainWindow::Ui_MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    ui->setupUi(this);
}

Ui_MainWindow::~Ui_MainWindow()
{
    delete ui;
}


void Ui_MainWindow::setupUi(QMainWindow *MainWindow) {
    if (MainWindow->objectName().isEmpty())
        MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
    MainWindow->resize(800, 600);
    centralwidget = new QWidget(MainWindow);
    centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
    tabWidget = new QTabWidget(centralwidget);
    tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
    tabWidget->setGeometry(QRect(6, 9, 781, 541));
    tab = new QWidget();
    tab->setObjectName(QString::fromUtf8("tab"));
    verticalLayoutWidget = new QWidget(tab);
    verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
    verticalLayoutWidget->setGeometry(QRect(9, 9, 761, 491));
    verticalLayout = new QVBoxLayout(verticalLayoutWidget);
    verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
    verticalLayout->setContentsMargins(0, 0, 0, 0);
    horizontalLayout = new QHBoxLayout();
    horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
    pushButton_2 = new QPushButton(verticalLayoutWidget);
    pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

    horizontalLayout->addWidget(pushButton_2);

    pushButton = new QPushButton(verticalLayoutWidget);
    pushButton->setObjectName(QString::fromUtf8("pushButton"));

    horizontalLayout->addWidget(pushButton);

    radioButton = new QRadioButton(verticalLayoutWidget);
    radioButton->setObjectName(QString::fromUtf8("radioButton"));

    horizontalLayout->addWidget(radioButton);

    radioButton_2 = new QRadioButton(verticalLayoutWidget);
    radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));

    horizontalLayout->addWidget(radioButton_2);


    verticalLayout->addLayout(horizontalLayout);

    horizontalLayout_3 = new QHBoxLayout();
    horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
    scrollArea = new QScrollArea(verticalLayoutWidget);
    scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
    QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(scrollArea->sizePolicy().hasHeightForWidth());
    scrollArea->setSizePolicy(sizePolicy);
    scrollArea->setWidgetResizable(true);
    scrollAreaWidgetContents = new QWidget();
    scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
    scrollAreaWidgetContents->setGeometry(QRect(0, 0, 374, 452));
    textBrowser = new QTextBrowser(scrollAreaWidgetContents);
    textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
    textBrowser->setGeometry(QRect(0, 0, 461, 471));
    scrollArea->setWidget(scrollAreaWidgetContents);

    horizontalLayout_3->addWidget(scrollArea);

    verticalLayout_2 = new QVBoxLayout();
    verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
    label_3 = new QLabel(verticalLayoutWidget);
    label_3->setObjectName(QString::fromUtf8("label_3"));

    verticalLayout_2->addWidget(label_3);

    label_2 = new QLabel(verticalLayoutWidget);
    label_2->setObjectName(QString::fromUtf8("label_2"));

    verticalLayout_2->addWidget(label_2);

    label = new QLabel(verticalLayoutWidget);
    label->setObjectName(QString::fromUtf8("label"));

    verticalLayout_2->addWidget(label);


    horizontalLayout_3->addLayout(verticalLayout_2);


    verticalLayout->addLayout(horizontalLayout_3);

    tabWidget->addTab(tab, QString());
    tab_2 = new QWidget();
    tab_2->setObjectName(QString::fromUtf8("tab_2"));
    tabWidget->addTab(tab_2, QString());
    MainWindow->setCentralWidget(centralwidget);
    menubar = new QMenuBar(MainWindow);
    menubar->setObjectName(QString::fromUtf8("menubar"));
    menubar->setGeometry(QRect(0, 0, 800, 22));
    MainWindow->setMenuBar(menubar);
    statusbar = new QStatusBar(MainWindow);
    statusbar->setObjectName(QString::fromUtf8("statusbar"));
    MainWindow->setStatusBar(statusbar);

    retranslateUi(MainWindow);

    tabWidget->setCurrentIndex(0);


    QMetaObject::connectSlotsByName(MainWindow);
} // setupUi


void Ui_MainWindow::retranslateUi(QMainWindow *MainWindow) {
    MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
    pushButton_2->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
    pushButton->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
    radioButton->setText(QCoreApplication::translate("MainWindow", "RadioButton", nullptr));
    radioButton_2->setText(QCoreApplication::translate("MainWindow", "RadioButton", nullptr));
    label_3->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
    label_2->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
    label->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
    tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "Tab 1", nullptr));
    tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "Tab 2", nullptr));
} // retranslateUi
