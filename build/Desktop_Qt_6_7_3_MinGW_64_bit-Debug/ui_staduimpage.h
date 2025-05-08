/********************************************************************************
** Form generated from reading UI file 'staduimpage.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STADUIMPAGE_H
#define UI_STADUIMPAGE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Staduimpage
{
public:
    QHBoxLayout *horizontalLayout;
    QWidget *contentArea;
    QTabWidget *tabWidget;
    QWidget *tab;
    QLineEdit *searchStaduimInput;
    QPushButton *searchButton;
    QPushButton *exportListButton;
    QTableWidget *tableWidget;
    QPushButton *refresh;
    QComboBox *filter;
    QPushButton *prevPageTable;
    QPushButton *nextPageTable;
    QWidget *tab_2;
    QLineEdit *Name;
    QLineEdit *Adress;
    QPushButton *AddStadium;
    QLineEdit *capacity;
    QLineEdit *status;
    QLineEdit *NameER;
    QLineEdit *AdressER;
    QLineEdit *capacityER;
    QLineEdit *statusER;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QWidget *tab_3;
    QPushButton *showChartButton;
    QPushButton *showTopStadiumsButton;
    QWidget *tab_4;
    QLineEdit *stadiumid;
    QLineEdit *date;
    QLineEdit *stadiumidinput;
    QLineEdit *IDER;
    QDateEdit *dateinput;
    QLineEdit *DATEER;
    QPushButton *checkButton;
    QLineEdit *lineEdit_5;
    QWidget *tab_5;
    QLineEdit *matchider;
    QLineEdit *matchid;
    QLineEdit *matchidInput;
    QPushButton *checkSeatsButton;
    QWidget *topSeatsWidget;
    QWidget *leftSeatsWidget;
    QWidget *rightSeatsWidget;
    QWidget *football_field;
    QWidget *bottomSeatsWidget;
    QLineEdit *attendanceLabel;
    QWidget *green;
    QWidget *red;
    QLineEdit *greenColor;
    QLineEdit *redColor;
    QWidget *sidebar;
    QPushButton *exitButton;
    QPushButton *homeButton;
    QPushButton *notifButton;
    QPushButton *aboutButton;

    void setupUi(QWidget *Staduimpage)
    {
        if (Staduimpage->objectName().isEmpty())
            Staduimpage->setObjectName("Staduimpage");
        Staduimpage->resize(1050, 681);
        horizontalLayout = new QHBoxLayout(Staduimpage);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        contentArea = new QWidget(Staduimpage);
        contentArea->setObjectName("contentArea");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(contentArea->sizePolicy().hasHeightForWidth());
        contentArea->setSizePolicy(sizePolicy);
        contentArea->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, \n"
"                                x1:0, y1:0, x2:0, y2:1, \n"
"                                stop:0 rgba(6, 6, 6, 255), \n"
"                                stop:0.41 rgba(56, 50, 52, 255), \n"
"                                stop:1 rgba(34, 33, 33, 255));;\n"
""));
        tabWidget = new QTabWidget(contentArea);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(120, 0, 941, 681));
        QFont font;
        font.setBold(true);
        tabWidget->setFont(font);
        tabWidget->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        tabWidget->setStyleSheet(QString::fromUtf8("QTabBar::tab {\n"
"    background: qlineargradient(spread:pad,\n"
"                                x1:0, y1:0, x2:1, y2:1,\n"
"                                stop:0 #b30000,\n"
"                                stop:0.5 #d40000,\n"
"                                stop:1 #ff4d4d);\n"
"    color: white;\n"
"    border: 1px solid #990000;\n"
"    border-radius: 8px;\n"
"    padding: 10px 20px;\n"
"    margin: 2px;\n"
"    font: bold 12pt \"Segoe UI\";\n"
"    min-width: 150px;\n"
"    transition: all 0.3s ease;\n"
"}\n"
"\n"
"QTabBar::tab:selected {\n"
"    background: qlineargradient(spread:pad,\n"
"                                x1:0, y1:0, x2:1, y2:1,\n"
"                                stop:0 #ffffff,\n"
"                                stop:1 #ffcccc);\n"
"    color: #990000;\n"
"    font: bold 13pt \"Segoe UI\";\n"
"    border: 2px solid #990000;\n"
"    border-bottom: none;\n"
"    border-radius: 8px 8px 0 0;\n"
"}\n"
"\n"
"QTabBar::tab:hover {\n"
"    background: qlineargradient(spread:pad,\n"
"        "
                        "                        x1:0, y1:0, x2:1, y2:1,\n"
"                                stop:0 #ff6666,\n"
"                                stop:1 #ff9999);\n"
"    color: #000000;\n"
"    font: bold 12pt \"Segoe UI\";\n"
"}\n"
"\n"
"QTabWidget::pane {\n"
"    border: 2px solid #990000;\n"
"    border-top: none;\n"
"    border-radius: 0 0 8px 8px;\n"
"    background-color: #fefefe;\n"
"}\n"
""));
        tab = new QWidget();
        tab->setObjectName("tab");
        searchStaduimInput = new QLineEdit(tab);
        searchStaduimInput->setObjectName("searchStaduimInput");
        searchStaduimInput->setGeometry(QRect(50, 40, 201, 61));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Segoe UI")});
        font1.setPointSize(14);
        font1.setBold(false);
        font1.setItalic(false);
        searchStaduimInput->setFont(font1);
        searchStaduimInput->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #ffffff;\n"
"    padding: 8px 12px;\n"
"    color: #000000;\n"
"    font: 14pt \"Segoe UI\";\n"
"    border: 2px solid #990000;\n"
"    border-radius: 8px;\n"
"}\n"
"\n"
"/* Hover effect */\n"
"QLineEdit:hover {\n"
"    border: 2px solid #ff3333;\n"
"    background-color: #fff0f0;\n"
"    transition: all 0.3s ease-in-out;\n"
"}\n"
"\n"
"/* Focus effect */\n"
"QLineEdit:focus {\n"
"    border: 2px solid #ff0004;\n"
"    background-color: #ffffff;\n"
"    box-shadow: 0 0 8px rgba(255, 0, 0, 0.3);\n"
"}\n"
""));
        searchButton = new QPushButton(tab);
        searchButton->setObjectName("searchButton");
        searchButton->setGeometry(QRect(280, 50, 66, 51));
        searchButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        searchButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background: qlineargradient(spread:pad, \n"
"                                x1:0, y1:0, x2:1, y2:1, \n"
"                                stop:0 rgba(255, 0, 0, 255), \n"
"                                stop:0.41 rgba(195, 22, 58, 255), \n"
"                                stop:1 rgba(255, 117, 0, 255));\n"
"    color: white;\n"
"    border: 2px solid #990000;\n"
"    border-radius: 10px;\n"
"    padding: 12px 24px;\n"
"    font: bold 14pt \"Segoe UI\";\n"
"    min-width: 14px;\n"
"    cursor: pointer;\n"
"    transition: all 0.3s ease; /* Transition fluide */\n"
"}\n"
"\n"
"/* Hover effect */\n"
"QPushButton:hover {\n"
"    background: qlineargradient(spread:pad, \n"
"                                x1:0.25, y1:0, x2:0.75, y2:1, \n"
"                                stop:0 rgba(0, 255, 254, 255),     \n"
"                                stop:0.26 rgba(38, 170, 196, 255), \n"
"                                stop:0.67 rgba(89, 85, 131, 255),\n"
"                                stop:1 rgba"
                        "(0, 238, 255, 255));\n"
"    border: 2px solid #ff0004; /* Border change on hover */\n"
"    color: #ffffff;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"/* Pressed effect */\n"
"QPushButton:pressed {\n"
"    background-color: #cc0000;\n"
"    border: 2px solid #990000;\n"
"    color: white;\n"
"    padding-left: 14px;\n"
"    padding-top: 14px;\n"
"    box-shadow: inset 0 0 10px rgba(0, 0, 0, 0.2); /* Shadow on press */\n"
"}\n"
""));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/textures/textures/searchIcon.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        searchButton->setIcon(icon);
        exportListButton = new QPushButton(tab);
        exportListButton->setObjectName("exportListButton");
        exportListButton->setGeometry(QRect(80, 570, 192, 51));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Segoe UI")});
        font2.setPointSize(14);
        font2.setBold(true);
        font2.setItalic(false);
        exportListButton->setFont(font2);
        exportListButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        exportListButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background: qlineargradient(spread:pad, \n"
"                                x1:0, y1:0, x2:1, y2:1, \n"
"                                stop:0 rgba(255, 0, 0, 255), \n"
"                                stop:0.41 rgba(195, 22, 58, 255), \n"
"                                stop:1 rgba(255, 117, 0, 255));\n"
"    color: white;\n"
"    border: 2px solid #990000;\n"
"    border-radius: 10px;\n"
"    padding: 12px 24px;\n"
"    font: bold 14pt \"Segoe UI\";\n"
"    min-width: 140px;\n"
"    cursor: pointer;\n"
"    transition: all 0.3s ease; /* Transition fluide */\n"
"}\n"
"\n"
"/* Hover effect */\n"
"QPushButton:hover {\n"
"    background: qlineargradient(spread:pad, \n"
"                                x1:0.25, y1:0, x2:0.75, y2:1, \n"
"                                stop:0 rgba(0, 255, 254, 255),     \n"
"                                stop:0.26 rgba(38, 170, 196, 255), \n"
"                                stop:0.67 rgba(89, 85, 131, 255),\n"
"                                stop:1 rgb"
                        "a(0, 238, 255, 255));\n"
"    border: 2px solid #ff0004; /* Border change on hover */\n"
"    color: #ffffff;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"/* Pressed effect */\n"
"QPushButton:pressed {\n"
"    background-color: #cc0000;\n"
"    border: 2px solid #990000;\n"
"    color: white;\n"
"    padding-left: 14px;\n"
"    padding-top: 14px;\n"
"    box-shadow: inset 0 0 10px rgba(0, 0, 0, 0.2); /* Shadow on press */\n"
"}\n"
""));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/textures/textures/exportIcon.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        exportListButton->setIcon(icon1);
        exportListButton->setIconSize(QSize(40, 50));
        tableWidget = new QTableWidget(tab);
        if (tableWidget->columnCount() < 6)
            tableWidget->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(50, 110, 821, 451));
        tableWidget->setStyleSheet(QString::fromUtf8("QTableWidget {\n"
"    background-color: #f9f9f9;\n"
"    border: 3px solid #b30000;\n"
"    border-radius: 10px;\n"
"    gridline-color: #dcdcdc;\n"
"    font-size: 14px;\n"
"    color: #000;\n"
"}\n"
"\n"
"QTableWidget::item {\n"
"    padding: 10px;\n"
"    border-bottom: 1px solid #e0e0e0;\n"
"    color: #000000;\n"
"}\n"
"\n"
"QTableWidget::item:selected {\n"
"    background-color: #b30000;  /* Red selection */\n"
"    color: white;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QTableWidget::item:hover {\n"
"    background-color: #ffe6e6;  /* Light red hover */\n"
"    color: #000;\n"
"}\n"
"\n"
"QHeaderView::section {\n"
"    background-color: #b30000;\n"
"    color: white;\n"
"    padding: 6px 10px;\n"
"    font-size: 15px;\n"
"    font-weight: bold;\n"
"    border: 1px solid #990000;\n"
"    min-width: 120px;\n"
"    border-radius: 5px;\n"
"}\n"
"\n"
"QTableCornerButton::section {\n"
"    background-color: #b30000;\n"
"    border: 1px solid #990000;\n"
"}\n"
"\n"
"QTableWidget QWidget {\n"
"    background: "
                        "transparent;\n"
"}\n"
"\n"
"QTableWidget QPushButton {\n"
"    background-color: qlineargradient(spread:pad, \n"
"                            x1:0, y1:0, x2:1, y2:1, \n"
"                            stop:0 #b30000, \n"
"                            stop:0.5 #e60000, \n"
"                            stop:1 #ff4d4d);\n"
"    border-radius: 8px;\n"
"    color: white;\n"
"    font-size: 13px;\n"
"    min-width: 90px;\n"
"    min-height: 35px;\n"
"    border: none;\n"
"}\n"
"\n"
"QTableWidget QPushButton:hover {\n"
"    background-color: qlineargradient(spread:pad,\n"
"                            x1:0, y1:0, x2:1, y2:1,\n"
"                            stop:0 #ffffff,\n"
"                            stop:1 #ffcccc);\n"
"    color: #b30000;\n"
"    font-weight: bold;\n"
"}\n"
""));
        tableWidget->setEditTriggers(QAbstractItemView::EditTrigger::NoEditTriggers);
        tableWidget->horizontalHeader()->setStretchLastSection(true);
        refresh = new QPushButton(tab);
        refresh->setObjectName("refresh");
        refresh->setGeometry(QRect(770, 50, 66, 51));
        refresh->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        refresh->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background: qlineargradient(spread:pad, \n"
"                                x1:0, y1:0, x2:1, y2:1, \n"
"                                stop:0 rgba(255, 0, 0, 255), \n"
"                                stop:0.41 rgba(195, 22, 58, 255), \n"
"                                stop:1 rgba(255, 117, 0, 255));\n"
"    color: white;\n"
"    border: 2px solid #990000;\n"
"    border-radius: 10px;\n"
"    padding: 12px 24px;\n"
"    font: bold 14pt \"Segoe UI\";\n"
"    min-width: 14px;\n"
"    cursor: pointer;\n"
"    transition: all 0.3s ease; /* Transition fluide */\n"
"}\n"
"\n"
"/* Hover effect */\n"
"QPushButton:hover {\n"
"    background: qlineargradient(spread:pad, \n"
"                                x1:0.25, y1:0, x2:0.75, y2:1, \n"
"                                stop:0 rgba(0, 255, 254, 255),     \n"
"                                stop:0.26 rgba(38, 170, 196, 255), \n"
"                                stop:0.67 rgba(89, 85, 131, 255),\n"
"                                stop:1 rgba"
                        "(0, 238, 255, 255));\n"
"    border: 2px solid #ff0004; /* Border change on hover */\n"
"    color: #ffffff;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"/* Pressed effect */\n"
"QPushButton:pressed {\n"
"    background-color: #cc0000;\n"
"    border: 2px solid #990000;\n"
"    color: white;\n"
"    padding-left: 14px;\n"
"    padding-top: 14px;\n"
"    box-shadow: inset 0 0 10px rgba(0, 0, 0, 0.2); /* Shadow on press */\n"
"}\n"
""));
        QIcon icon2(QIcon::fromTheme(QIcon::ThemeIcon::ViewRefresh));
        refresh->setIcon(icon2);
        filter = new QComboBox(tab);
        filter->addItem(QString());
        filter->addItem(QString());
        filter->addItem(QString());
        filter->addItem(QString());
        filter->addItem(QString());
        filter->setObjectName("filter");
        filter->setGeometry(QRect(590, 57, 171, 41));
        filter->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    background-color: qlineargradient(spread:pad, \n"
"                            x1:0, y1:0, x2:1, y2:1, \n"
"                            stop:0 rgba(255, 0, 0, 255), \n"
"                            stop:0.41 rgba(195, 22, 58, 255), \n"
"                            stop:1 rgba(255, 117, 0, 255));\n"
"    border: 2px solid #b71c1c;\n"
"    border-radius: 5px;\n"
"    padding: 5px;\n"
"    color: white;\n"
"    font-size: 14px;\n"
"}\n"
"\n"
"QComboBox::drop-down {\n"
"    border: none;\n"
"    background: transparent;\n"
"    width: 25px;\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"    image: url(:/icons/down-arrow.png); /* Use an image */\n"
"    width: 10px;\n"
"    height: 10px;\n"
"}\n"
"\n"
"/* Alternative Unicode Arrow */\n"
"QComboBox::down-arrow:before {\n"
"    content: \"\342\226\274\";  \n"
"    font-size: 12px;\n"
"    color: white;\n"
"}\n"
"\n"
"QComboBox:hover {\n"
"    background-color: qlineargradient(x1: 0.25, y1: 0, x2: 0.75, y2: 1, \n"
"                            stop: 0 r"
                        "gba(0, 255, 254, 255),     \n"
"                            stop: 0.26 rgba(38, 170, 196, 255), \n"
"                            stop: 0.67 rgba(89, 85, 131, 255),\n"
"                            stop: 1 rgba(0, 238, 255, 255));\n"
"    border: 2px solid #26a69a;\n"
"}\n"
""));
        prevPageTable = new QPushButton(tab);
        prevPageTable->setObjectName("prevPageTable");
        prevPageTable->setGeometry(QRect(800, 570, 66, 41));
        prevPageTable->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background: qlineargradient(spread:pad, \n"
"                                x1:0, y1:0, x2:1, y2:1, \n"
"                                stop:0 rgba(255, 0, 0, 255), \n"
"                                stop:0.41 rgba(195, 22, 58, 255), \n"
"                                stop:1 rgba(255, 117, 0, 255));\n"
"    color: white;\n"
"    border: 2px solid #990000;\n"
"    border-radius: 10px;\n"
"    padding: 12px 24px;\n"
"    font: bold 14pt \"Segoe UI\";\n"
"    min-width: 14px;\n"
"    cursor: pointer;\n"
"    transition: all 0.3s ease; /* Transition fluide */\n"
"}\n"
"\n"
"/* Hover effect */\n"
"QPushButton:hover {\n"
"    background: qlineargradient(spread:pad, \n"
"                                x1:0.25, y1:0, x2:0.75, y2:1, \n"
"                                stop:0 rgba(0, 255, 254, 255),     \n"
"                                stop:0.26 rgba(38, 170, 196, 255), \n"
"                                stop:0.67 rgba(89, 85, 131, 255),\n"
"                                stop:1 rgba"
                        "(0, 238, 255, 255));\n"
"    border: 2px solid #ff0004; /* Border change on hover */\n"
"    color: #ffffff;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"/* Pressed effect */\n"
"QPushButton:pressed {\n"
"    background-color: #cc0000;\n"
"    border: 2px solid #990000;\n"
"    color: white;\n"
"    padding-left: 14px;\n"
"    padding-top: 14px;\n"
"    box-shadow: inset 0 0 10px rgba(0, 0, 0, 0.2); /* Shadow on press */\n"
"}\n"
""));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/textures/textures/nextIcon.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        prevPageTable->setIcon(icon3);
        nextPageTable = new QPushButton(tab);
        nextPageTable->setObjectName("nextPageTable");
        nextPageTable->setGeometry(QRect(730, 570, 66, 41));
        nextPageTable->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background: qlineargradient(spread:pad, \n"
"                                x1:0, y1:0, x2:1, y2:1, \n"
"                                stop:0 rgba(255, 0, 0, 255), \n"
"                                stop:0.41 rgba(195, 22, 58, 255), \n"
"                                stop:1 rgba(255, 117, 0, 255));\n"
"    color: white;\n"
"    border: 2px solid #990000;\n"
"    border-radius: 10px;\n"
"    padding: 12px 24px;\n"
"    font: bold 14pt \"Segoe UI\";\n"
"    min-width: 14px;\n"
"    cursor: pointer;\n"
"    transition: all 0.3s ease; /* Transition fluide */\n"
"}\n"
"\n"
"/* Hover effect */\n"
"QPushButton:hover {\n"
"    background: qlineargradient(spread:pad, \n"
"                                x1:0.25, y1:0, x2:0.75, y2:1, \n"
"                                stop:0 rgba(0, 255, 254, 255),     \n"
"                                stop:0.26 rgba(38, 170, 196, 255), \n"
"                                stop:0.67 rgba(89, 85, 131, 255),\n"
"                                stop:1 rgba"
                        "(0, 238, 255, 255));\n"
"    border: 2px solid #ff0004; /* Border change on hover */\n"
"    color: #ffffff;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"/* Pressed effect */\n"
"QPushButton:pressed {\n"
"    background-color: #cc0000;\n"
"    border: 2px solid #990000;\n"
"    color: white;\n"
"    padding-left: 14px;\n"
"    padding-top: 14px;\n"
"    box-shadow: inset 0 0 10px rgba(0, 0, 0, 0.2); /* Shadow on press */\n"
"}\n"
""));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/textures/textures/prevIcon.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        nextPageTable->setIcon(icon4);
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        Name = new QLineEdit(tab_2);
        Name->setObjectName("Name");
        Name->setGeometry(QRect(240, 100, 301, 31));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Arial")});
        Name->setFont(font3);
        Name->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: white;\n"
"    padding: 5px;\n"
"    color: black;\n"
"    font-size: 16px;\n"
"}\n"
"\n"
"/* Hover effect */\n"
"QLineEdit:hover {\n"
"	border:3px dashed qlineargradient(spread:pad, \n"
"                            x1:0, y1:0, x2:1, y2:1, \n"
"                            stop:0 rgba(255, 0, 0, 255), \n"
"                            stop:0.41 rgba(195, 22, 58, 255), \n"
"                            stop:1 rgba(255, 117, 0, 255));;  ;  ;\n"
"}\n"
"\n"
"/* Focus effect */\n"
"QLineEdit:focus {\n"
"    border:2px solid  qlineargradient(spread:pad, \n"
"                            x1:0, y1:0, x2:1, y2:1, \n"
"                            stop:0 rgba(255, 0, 0, 255), \n"
"                            stop:0.41 rgba(195, 22, 58, 255), \n"
"                            stop:1 rgba(255, 117, 0, 255));;  ;  ;\n"
"}\n"
""));
        Adress = new QLineEdit(tab_2);
        Adress->setObjectName("Adress");
        Adress->setGeometry(QRect(240, 163, 301, 31));
        Adress->setFont(font3);
        Adress->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: white;\n"
"    padding: 5px;\n"
"    color: black;\n"
"    font-size: 16px;\n"
"}\n"
"\n"
"/* Hover effect */\n"
"QLineEdit:hover {\n"
"	border:3px dashed qlineargradient(spread:pad, \n"
"                            x1:0, y1:0, x2:1, y2:1, \n"
"                            stop:0 rgba(255, 0, 0, 255), \n"
"                            stop:0.41 rgba(195, 22, 58, 255), \n"
"                            stop:1 rgba(255, 117, 0, 255));;  ;  ;\n"
"}\n"
"\n"
"/* Focus effect */\n"
"QLineEdit:focus {\n"
"    border:2px solid  qlineargradient(spread:pad, \n"
"                            x1:0, y1:0, x2:1, y2:1, \n"
"                            stop:0 rgba(255, 0, 0, 255), \n"
"                            stop:0.41 rgba(195, 22, 58, 255), \n"
"                            stop:1 rgba(255, 117, 0, 255));;  ;  ;\n"
"}\n"
""));
        AddStadium = new QPushButton(tab_2);
        AddStadium->setObjectName("AddStadium");
        AddStadium->setGeometry(QRect(350, 490, 241, 71));
        AddStadium->setFont(font2);
        AddStadium->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        AddStadium->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background: qlineargradient(spread:pad, \n"
"                                x1:0, y1:0, x2:1, y2:1, \n"
"                                stop:0 rgba(255, 0, 0, 255), \n"
"                                stop:0.41 rgba(195, 22, 58, 255), \n"
"                                stop:1 rgba(255, 117, 0, 255));\n"
"    color: white;\n"
"    border: 2px solid #990000;\n"
"    border-radius: 10px;\n"
"    padding: 12px 24px;\n"
"    font: bold 14pt \"Segoe UI\";\n"
"    min-width: 14px;\n"
"    cursor: pointer;\n"
"    transition: all 0.3s ease; /* Transition fluide */\n"
"}\n"
"\n"
"/* Hover effect */\n"
"QPushButton:hover {\n"
"    background: qlineargradient(spread:pad, \n"
"                                x1:0.25, y1:0, x2:0.75, y2:1, \n"
"                                stop:0 rgba(0, 255, 254, 255),     \n"
"                                stop:0.26 rgba(38, 170, 196, 255), \n"
"                                stop:0.67 rgba(89, 85, 131, 255),\n"
"                                stop:1 rgba"
                        "(0, 238, 255, 255));\n"
"    border: 2px solid #ff0004; /* Border change on hover */\n"
"    color: #ffffff;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"/* Pressed effect */\n"
"QPushButton:pressed {\n"
"    background-color: #cc0000;\n"
"    border: 2px solid #990000;\n"
"    color: white;\n"
"    padding-left: 14px;\n"
"    padding-top: 14px;\n"
"    box-shadow: inset 0 0 10px rgba(0, 0, 0, 0.2); /* Shadow on press */\n"
"}\n"
""));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/textures/textures/addIcon.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        AddStadium->setIcon(icon5);
        AddStadium->setIconSize(QSize(50, 50));
        capacity = new QLineEdit(tab_2);
        capacity->setObjectName("capacity");
        capacity->setGeometry(QRect(240, 230, 301, 31));
        capacity->setFont(font3);
        capacity->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: white;\n"
"    padding: 5px;\n"
"    color: black;\n"
"    font-size: 16px;\n"
"}\n"
"\n"
"/* Hover effect */\n"
"QLineEdit:hover {\n"
"	border:3px dashed qlineargradient(spread:pad, \n"
"                            x1:0, y1:0, x2:1, y2:1, \n"
"                            stop:0 rgba(255, 0, 0, 255), \n"
"                            stop:0.41 rgba(195, 22, 58, 255), \n"
"                            stop:1 rgba(255, 117, 0, 255));;  ;  ;\n"
"}\n"
"\n"
"/* Focus effect */\n"
"QLineEdit:focus {\n"
"    border:2px solid  qlineargradient(spread:pad, \n"
"                            x1:0, y1:0, x2:1, y2:1, \n"
"                            stop:0 rgba(255, 0, 0, 255), \n"
"                            stop:0.41 rgba(195, 22, 58, 255), \n"
"                            stop:1 rgba(255, 117, 0, 255));;  ;  ;\n"
"}\n"
""));
        status = new QLineEdit(tab_2);
        status->setObjectName("status");
        status->setGeometry(QRect(240, 300, 301, 31));
        status->setFont(font3);
        status->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: white;\n"
"    padding: 5px;\n"
"    color: black;\n"
"    font-size: 16px;\n"
"}\n"
"\n"
"/* Hover effect */\n"
"QLineEdit:hover {\n"
"	border:3px dashed qlineargradient(spread:pad, \n"
"                            x1:0, y1:0, x2:1, y2:1, \n"
"                            stop:0 rgba(255, 0, 0, 255), \n"
"                            stop:0.41 rgba(195, 22, 58, 255), \n"
"                            stop:1 rgba(255, 117, 0, 255));;  ;  ;\n"
"}\n"
"\n"
"/* Focus effect */\n"
"QLineEdit:focus {\n"
"    border:2px solid  qlineargradient(spread:pad, \n"
"                            x1:0, y1:0, x2:1, y2:1, \n"
"                            stop:0 rgba(255, 0, 0, 255), \n"
"                            stop:0.41 rgba(195, 22, 58, 255), \n"
"                            stop:1 rgba(255, 117, 0, 255));;  ;  ;\n"
"}\n"
""));
        NameER = new QLineEdit(tab_2);
        NameER->setObjectName("NameER");
        NameER->setGeometry(QRect(240, 130, 301, 28));
        NameER->setStyleSheet(QString::fromUtf8("color:rgb(170, 0, 0);"));
        NameER->setReadOnly(true);
        AdressER = new QLineEdit(tab_2);
        AdressER->setObjectName("AdressER");
        AdressER->setGeometry(QRect(240, 190, 301, 28));
        AdressER->setStyleSheet(QString::fromUtf8("color:rgb(170, 0, 0);"));
        AdressER->setReadOnly(true);
        capacityER = new QLineEdit(tab_2);
        capacityER->setObjectName("capacityER");
        capacityER->setGeometry(QRect(240, 260, 301, 28));
        capacityER->setStyleSheet(QString::fromUtf8("color:rgb(170, 0, 0);"));
        capacityER->setReadOnly(true);
        statusER = new QLineEdit(tab_2);
        statusER->setObjectName("statusER");
        statusER->setGeometry(QRect(240, 330, 301, 28));
        statusER->setStyleSheet(QString::fromUtf8("color:rgb(170, 0, 0);"));
        statusER->setReadOnly(true);
        lineEdit = new QLineEdit(tab_2);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(110, 100, 113, 28));
        lineEdit->setReadOnly(true);
        lineEdit_2 = new QLineEdit(tab_2);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(110, 170, 113, 28));
        lineEdit_2->setReadOnly(true);
        lineEdit_3 = new QLineEdit(tab_2);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(110, 230, 113, 28));
        lineEdit_3->setReadOnly(true);
        lineEdit_4 = new QLineEdit(tab_2);
        lineEdit_4->setObjectName("lineEdit_4");
        lineEdit_4->setGeometry(QRect(110, 300, 113, 28));
        lineEdit_4->setReadOnly(true);
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName("tab_3");
        showChartButton = new QPushButton(tab_3);
        showChartButton->setObjectName("showChartButton");
        showChartButton->setGeometry(QRect(53, 187, 601, 61));
        showChartButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background: qlineargradient(spread:pad, \n"
"                                x1:0, y1:0, x2:1, y2:1, \n"
"                                stop:0 rgba(255, 0, 0, 255), \n"
"                                stop:0.41 rgba(195, 22, 58, 255), \n"
"                                stop:1 rgba(255, 117, 0, 255));\n"
"    color: white;\n"
"    border: 2px solid #990000;\n"
"    border-radius: 10px;\n"
"    padding: 12px 24px;\n"
"    font: bold 14pt \"Segoe UI\";\n"
"    min-width: 14px;\n"
"    cursor: pointer;\n"
"    transition: all 0.3s ease; /* Transition fluide */\n"
"}\n"
"\n"
"/* Hover effect */\n"
"QPushButton:hover {\n"
"    background: qlineargradient(spread:pad, \n"
"                                x1:0.25, y1:0, x2:0.75, y2:1, \n"
"                                stop:0 rgba(0, 255, 254, 255),     \n"
"                                stop:0.26 rgba(38, 170, 196, 255), \n"
"                                stop:0.67 rgba(89, 85, 131, 255),\n"
"                                stop:1 rgba"
                        "(0, 238, 255, 255));\n"
"    border: 2px solid #ff0004; /* Border change on hover */\n"
"    color: #ffffff;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"/* Pressed effect */\n"
"QPushButton:pressed {\n"
"    background-color: #cc0000;\n"
"    border: 2px solid #990000;\n"
"    color: white;\n"
"    padding-left: 14px;\n"
"    padding-top: 14px;\n"
"    box-shadow: inset 0 0 10px rgba(0, 0, 0, 0.2); /* Shadow on press */\n"
"}\n"
""));
        showTopStadiumsButton = new QPushButton(tab_3);
        showTopStadiumsButton->setObjectName("showTopStadiumsButton");
        showTopStadiumsButton->setGeometry(QRect(53, 110, 601, 51));
        showTopStadiumsButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background: qlineargradient(spread:pad, \n"
"                                x1:0, y1:0, x2:1, y2:1, \n"
"                                stop:0 rgba(255, 0, 0, 255), \n"
"                                stop:0.41 rgba(195, 22, 58, 255), \n"
"                                stop:1 rgba(255, 117, 0, 255));\n"
"    color: white;\n"
"    border: 2px solid #990000;\n"
"    border-radius: 10px;\n"
"    padding: 12px 24px;\n"
"    font: bold 14pt \"Segoe UI\";\n"
"    min-width: 14px;\n"
"    cursor: pointer;\n"
"    transition: all 0.3s ease; /* Transition fluide */\n"
"}\n"
"\n"
"/* Hover effect */\n"
"QPushButton:hover {\n"
"    background: qlineargradient(spread:pad, \n"
"                                x1:0.25, y1:0, x2:0.75, y2:1, \n"
"                                stop:0 rgba(0, 255, 254, 255),     \n"
"                                stop:0.26 rgba(38, 170, 196, 255), \n"
"                                stop:0.67 rgba(89, 85, 131, 255),\n"
"                                stop:1 rgba"
                        "(0, 238, 255, 255));\n"
"    border: 2px solid #ff0004; /* Border change on hover */\n"
"    color: #ffffff;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"/* Pressed effect */\n"
"QPushButton:pressed {\n"
"    background-color: #cc0000;\n"
"    border: 2px solid #990000;\n"
"    color: white;\n"
"    padding-left: 14px;\n"
"    padding-top: 14px;\n"
"    box-shadow: inset 0 0 10px rgba(0, 0, 0, 0.2); /* Shadow on press */\n"
"}\n"
""));
        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName("tab_4");
        stadiumid = new QLineEdit(tab_4);
        stadiumid->setObjectName("stadiumid");
        stadiumid->setGeometry(QRect(120, 180, 113, 28));
        stadiumid->setReadOnly(true);
        date = new QLineEdit(tab_4);
        date->setObjectName("date");
        date->setGeometry(QRect(120, 260, 113, 28));
        date->setReadOnly(true);
        stadiumidinput = new QLineEdit(tab_4);
        stadiumidinput->setObjectName("stadiumidinput");
        stadiumidinput->setGeometry(QRect(260, 180, 301, 31));
        stadiumidinput->setFont(font3);
        stadiumidinput->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: white;\n"
"    padding: 5px;\n"
"    color: black;\n"
"    font-size: 16px;\n"
"}\n"
"\n"
"/* Hover effect */\n"
"QLineEdit:hover {\n"
"	border:3px dashed qlineargradient(spread:pad, \n"
"                            x1:0, y1:0, x2:1, y2:1, \n"
"                            stop:0 rgba(255, 0, 0, 255), \n"
"                            stop:0.41 rgba(195, 22, 58, 255), \n"
"                            stop:1 rgba(255, 117, 0, 255));;  ;  ;\n"
"}\n"
"\n"
"/* Focus effect */\n"
"QLineEdit:focus {\n"
"    border:2px solid  qlineargradient(spread:pad, \n"
"                            x1:0, y1:0, x2:1, y2:1, \n"
"                            stop:0 rgba(255, 0, 0, 255), \n"
"                            stop:0.41 rgba(195, 22, 58, 255), \n"
"                            stop:1 rgba(255, 117, 0, 255));;  ;  ;\n"
"}\n"
""));
        IDER = new QLineEdit(tab_4);
        IDER->setObjectName("IDER");
        IDER->setGeometry(QRect(260, 210, 301, 28));
        IDER->setStyleSheet(QString::fromUtf8("color:rgb(170, 0, 0);"));
        IDER->setReadOnly(true);
        dateinput = new QDateEdit(tab_4);
        dateinput->setObjectName("dateinput");
        dateinput->setGeometry(QRect(260, 260, 301, 29));
        DATEER = new QLineEdit(tab_4);
        DATEER->setObjectName("DATEER");
        DATEER->setGeometry(QRect(260, 290, 301, 28));
        DATEER->setStyleSheet(QString::fromUtf8("color:rgb(170, 0, 0);"));
        DATEER->setReadOnly(true);
        checkButton = new QPushButton(tab_4);
        checkButton->setObjectName("checkButton");
        checkButton->setGeometry(QRect(600, 370, 141, 51));
        checkButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background: qlineargradient(spread:pad, \n"
"                                x1:0, y1:0, x2:1, y2:1, \n"
"                                stop:0 rgba(255, 0, 0, 255), \n"
"                                stop:0.41 rgba(195, 22, 58, 255), \n"
"                                stop:1 rgba(255, 117, 0, 255));\n"
"    color: white;\n"
"    border: 2px solid #990000;\n"
"    border-radius: 10px;\n"
"    padding: 12px 24px;\n"
"    font: bold 14pt \"Segoe UI\";\n"
"    min-width: 14px;\n"
"    cursor: pointer;\n"
"    transition: all 0.3s ease; /* Transition fluide */\n"
"}\n"
"\n"
"/* Hover effect */\n"
"QPushButton:hover {\n"
"    background: qlineargradient(spread:pad, \n"
"                                x1:0.25, y1:0, x2:0.75, y2:1, \n"
"                                stop:0 rgba(0, 255, 254, 255),     \n"
"                                stop:0.26 rgba(38, 170, 196, 255), \n"
"                                stop:0.67 rgba(89, 85, 131, 255),\n"
"                                stop:1 rgba"
                        "(0, 238, 255, 255));\n"
"    border: 2px solid #ff0004; /* Border change on hover */\n"
"    color: #ffffff;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"/* Pressed effect */\n"
"QPushButton:pressed {\n"
"    background-color: #cc0000;\n"
"    border: 2px solid #990000;\n"
"    color: white;\n"
"    padding-left: 14px;\n"
"    padding-top: 14px;\n"
"    box-shadow: inset 0 0 10px rgba(0, 0, 0, 0.2); /* Shadow on press */\n"
"}\n"
""));
        lineEdit_5 = new QLineEdit(tab_4);
        lineEdit_5->setObjectName("lineEdit_5");
        lineEdit_5->setGeometry(QRect(130, 50, 371, 71));
        lineEdit_5->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    font-size: 18px;\n"
"    font-weight: bold;\n"
"    color: white;\n"
"    background-color: #2C3E50; /* Dark blue-gray background */\n"
"    border: 2px solid #1ABC9C; /* Teal border */\n"
"    border-radius: 10px;\n"
"    padding: 8px;\n"
"    text-align: center;\n"
"}\n"
"QLineEdit:focus {\n"
"    border: 2px solid #E74C3C; /* Red border when focused */\n"
"    background-color: #34495E; /* Slightly darker background */\n"
"}\n"
""));
        lineEdit_5->setReadOnly(true);
        tabWidget->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName("tab_5");
        matchider = new QLineEdit(tab_5);
        matchider->setObjectName("matchider");
        matchider->setGeometry(QRect(120, 70, 301, 28));
        matchider->setStyleSheet(QString::fromUtf8("color:rgb(170, 0, 0);"));
        matchider->setReadOnly(true);
        matchid = new QLineEdit(tab_5);
        matchid->setObjectName("matchid");
        matchid->setGeometry(QRect(10, 40, 113, 28));
        matchid->setReadOnly(true);
        matchidInput = new QLineEdit(tab_5);
        matchidInput->setObjectName("matchidInput");
        matchidInput->setGeometry(QRect(120, 40, 301, 31));
        matchidInput->setFont(font3);
        matchidInput->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: white;\n"
"    padding: 5px;\n"
"    color: black;\n"
"    font-size: 16px;\n"
"}\n"
"\n"
"/* Hover effect */\n"
"QLineEdit:hover {\n"
"	border:3px dashed qlineargradient(spread:pad, \n"
"                            x1:0, y1:0, x2:1, y2:1, \n"
"                            stop:0 rgba(255, 0, 0, 255), \n"
"                            stop:0.41 rgba(195, 22, 58, 255), \n"
"                            stop:1 rgba(255, 117, 0, 255));;  ;  ;\n"
"}\n"
"\n"
"/* Focus effect */\n"
"QLineEdit:focus {\n"
"    border:2px solid  qlineargradient(spread:pad, \n"
"                            x1:0, y1:0, x2:1, y2:1, \n"
"                            stop:0 rgba(255, 0, 0, 255), \n"
"                            stop:0.41 rgba(195, 22, 58, 255), \n"
"                            stop:1 rgba(255, 117, 0, 255));;  ;  ;\n"
"}\n"
""));
        checkSeatsButton = new QPushButton(tab_5);
        checkSeatsButton->setObjectName("checkSeatsButton");
        checkSeatsButton->setGeometry(QRect(430, 40, 141, 51));
        checkSeatsButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background: qlineargradient(spread:pad, \n"
"                                x1:0, y1:0, x2:1, y2:1, \n"
"                                stop:0 rgba(255, 0, 0, 255), \n"
"                                stop:0.41 rgba(195, 22, 58, 255), \n"
"                                stop:1 rgba(255, 117, 0, 255));\n"
"    color: white;\n"
"    border: 2px solid #990000;\n"
"    border-radius: 10px;\n"
"    padding: 12px 24px;\n"
"    font: bold 14pt \"Segoe UI\";\n"
"    min-width: 14px;\n"
"    cursor: pointer;\n"
"    transition: all 0.3s ease; /* Transition fluide */\n"
"}\n"
"\n"
"/* Hover effect */\n"
"QPushButton:hover {\n"
"    background: qlineargradient(spread:pad, \n"
"                                x1:0.25, y1:0, x2:0.75, y2:1, \n"
"                                stop:0 rgba(0, 255, 254, 255),     \n"
"                                stop:0.26 rgba(38, 170, 196, 255), \n"
"                                stop:0.67 rgba(89, 85, 131, 255),\n"
"                                stop:1 rgba"
                        "(0, 238, 255, 255));\n"
"    border: 2px solid #ff0004; /* Border change on hover */\n"
"    color: #ffffff;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"/* Pressed effect */\n"
"QPushButton:pressed {\n"
"    background-color: #cc0000;\n"
"    border: 2px solid #990000;\n"
"    color: white;\n"
"    padding-left: 14px;\n"
"    padding-top: 14px;\n"
"    box-shadow: inset 0 0 10px rgba(0, 0, 0, 0.2); /* Shadow on press */\n"
"}\n"
""));
        topSeatsWidget = new QWidget(tab_5);
        topSeatsWidget->setObjectName("topSeatsWidget");
        topSeatsWidget->setGeometry(QRect(150, 110, 621, 101));
        leftSeatsWidget = new QWidget(tab_5);
        leftSeatsWidget->setObjectName("leftSeatsWidget");
        leftSeatsWidget->setGeometry(QRect(0, 220, 141, 301));
        rightSeatsWidget = new QWidget(tab_5);
        rightSeatsWidget->setObjectName("rightSeatsWidget");
        rightSeatsWidget->setGeometry(QRect(780, 220, 141, 301));
        football_field = new QWidget(tab_5);
        football_field->setObjectName("football_field");
        football_field->setGeometry(QRect(150, 220, 551, 271));
        football_field->setStyleSheet(QString::fromUtf8(""));
        bottomSeatsWidget = new QWidget(tab_5);
        bottomSeatsWidget->setObjectName("bottomSeatsWidget");
        bottomSeatsWidget->setGeometry(QRect(150, 530, 621, 101));
        attendanceLabel = new QLineEdit(tab_5);
        attendanceLabel->setObjectName("attendanceLabel");
        attendanceLabel->setGeometry(QRect(590, 40, 301, 41));
        attendanceLabel->setStyleSheet(QString::fromUtf8("color:white;"));
        attendanceLabel->setReadOnly(true);
        green = new QWidget(tab_5);
        green->setObjectName("green");
        green->setGeometry(QRect(10, 550, 31, 21));
        green->setStyleSheet(QString::fromUtf8("background-color:rgb(1, 255, 1)"));
        red = new QWidget(tab_5);
        red->setObjectName("red");
        red->setGeometry(QRect(10, 580, 31, 21));
        red->setStyleSheet(QString::fromUtf8("background-color:#ffcccc"));
        greenColor = new QLineEdit(tab_5);
        greenColor->setObjectName("greenColor");
        greenColor->setGeometry(QRect(50, 550, 91, 21));
        greenColor->setInputMethodHints(Qt::InputMethodHint::ImhNoAutoUppercase);
        greenColor->setReadOnly(true);
        redColor = new QLineEdit(tab_5);
        redColor->setObjectName("redColor");
        redColor->setGeometry(QRect(50, 580, 91, 21));
        redColor->setReadOnly(true);
        tabWidget->addTab(tab_5, QString());
        sidebar = new QWidget(contentArea);
        sidebar->setObjectName("sidebar");
        sidebar->setGeometry(QRect(-30, 0, 151, 701));
        sidebar->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background: qlineargradient(spread:pad, \n"
"                                x1:0, y1:0, x2:1, y2:1, \n"
"                                stop:0 rgba(255, 0, 0, 255), \n"
"                                stop:0.41 rgba(195, 22, 58, 255), \n"
"                                stop:1 rgba(255, 117, 0, 255));\n"
"    color: white;\n"
"    border: 2px solid #990000;\n"
"    border-radius: 10px;\n"
"    padding: 12px 24px;\n"
"    font: bold 14pt \"Segoe UI\";\n"
"    min-width: 14px;\n"
"    cursor: pointer;\n"
"    transition: all 0.3s ease; /* Transition fluide */\n"
"}\n"
"\n"
"/* Hover effect */\n"
"QPushButton:hover {\n"
"    background: qlineargradient(spread:pad, \n"
"                                x1:0.25, y1:0, x2:0.75, y2:1, \n"
"                                stop:0 rgba(0, 255, 254, 255),     \n"
"                                stop:0.26 rgba(38, 170, 196, 255), \n"
"                                stop:0.67 rgba(89, 85, 131, 255),\n"
"                                stop:1 rgba"
                        "(0, 238, 255, 255));\n"
"    border: 2px solid #ff0004; /* Border change on hover */\n"
"    color: #ffffff;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"/* Pressed effect */\n"
"QPushButton:pressed {\n"
"    background-color: #cc0000;\n"
"    border: 2px solid #990000;\n"
"    color: white;\n"
"    padding-left: 14px;\n"
"    padding-top: 14px;\n"
"    box-shadow: inset 0 0 10px rgba(0, 0, 0, 0.2); /* Shadow on press */\n"
"}\n"
""));
        exitButton = new QPushButton(sidebar);
        exitButton->setObjectName("exitButton");
        exitButton->setGeometry(QRect(50, 280, 70, 61));
        exitButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        exitButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border:none;\n"
"\n"
"\n"
"\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: red;\n"
"    box-shadow: 0px 0px 10px rgba(255, 0, 0, 0.5);\n"
"	border-radius:15px;\n"
"}"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/textures/textures/exitIcon.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        exitButton->setIcon(icon6);
        exitButton->setIconSize(QSize(50, 50));
        homeButton = new QPushButton(sidebar);
        homeButton->setObjectName("homeButton");
        homeButton->setEnabled(true);
        homeButton->setGeometry(QRect(50, 10, 70, 61));
        homeButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        homeButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background: qlineargradient(spread:pad, \n"
"                                x1:0, y1:0, x2:1, y2:1, \n"
"                                stop:0 rgba(255, 0, 0, 255), \n"
"                                stop:0.41 rgba(195, 22, 58, 255), \n"
"                                stop:1 rgba(255, 117, 0, 255));\n"
"    color: white;\n"
"    border: 2px solid #990000;\n"
"    border-radius: 10px;\n"
"    padding: 12px 24px;\n"
"    font: bold 14pt \"Segoe UI\";\n"
"    min-width: 14px;\n"
"    cursor: pointer;\n"
"    transition: all 0.3s ease; /* Transition fluide */\n"
"}\n"
"\n"
"/* Hover effect */\n"
"QPushButton:hover {\n"
"    background: qlineargradient(spread:pad, \n"
"                                x1:0.25, y1:0, x2:0.75, y2:1, \n"
"                                stop:0 rgba(0, 255, 254, 255),     \n"
"                                stop:0.26 rgba(38, 170, 196, 255), \n"
"                                stop:0.67 rgba(89, 85, 131, 255),\n"
"                                stop:1 rgba"
                        "(0, 238, 255, 255));\n"
"    border: 2px solid #ff0004; /* Border change on hover */\n"
"    color: #ffffff;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"/* Pressed effect */\n"
"QPushButton:pressed {\n"
"    background-color: #cc0000;\n"
"    border: 2px solid #990000;\n"
"    color: white;\n"
"    padding-left: 14px;\n"
"    padding-top: 14px;\n"
"    box-shadow: inset 0 0 10px rgba(0, 0, 0, 0.2); /* Shadow on press */\n"
"}\n"
""));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/textures/textures/homeIcon.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        homeButton->setIcon(icon7);
        homeButton->setIconSize(QSize(50, 50));
        notifButton = new QPushButton(sidebar);
        notifButton->setObjectName("notifButton");
        notifButton->setGeometry(QRect(50, 100, 70, 61));
        notifButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        notifButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border:none;\n"
"\n"
"\n"
"\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: yellow;\n"
"    box-shadow: 0px 0px 10px rgba(255, 0, 0, 0.5);\n"
"	border-radius:15px;\n"
"}"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/textures/textures/notifsIcon.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        notifButton->setIcon(icon8);
        notifButton->setIconSize(QSize(50, 50));
        aboutButton = new QPushButton(sidebar);
        aboutButton->setObjectName("aboutButton");
        aboutButton->setGeometry(QRect(50, 190, 70, 61));
        aboutButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        aboutButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border:none;\n"
"\n"
"\n"
"\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: lime;\n"
"    box-shadow: 0px 0px 10px rgba(255, 0, 0, 0.5);\n"
"	border-radius:15px;\n"
"}"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/textures/textures/aboutIcon.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        aboutButton->setIcon(icon9);
        aboutButton->setIconSize(QSize(50, 50));

        horizontalLayout->addWidget(contentArea);


        retranslateUi(Staduimpage);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Staduimpage);
    } // setupUi

    void retranslateUi(QWidget *Staduimpage)
    {
        Staduimpage->setWindowTitle(QCoreApplication::translate("Staduimpage", "Form", nullptr));
        searchStaduimInput->setPlaceholderText(QCoreApplication::translate("Staduimpage", "Search Staduim", nullptr));
        searchButton->setText(QString());
        exportListButton->setText(QCoreApplication::translate("Staduimpage", "Export List", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("Staduimpage", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("Staduimpage", "Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("Staduimpage", "Adress", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("Staduimpage", "Capacity", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("Staduimpage", "Status", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("Staduimpage", "Actions", nullptr));
        refresh->setText(QString());
        filter->setItemText(0, QCoreApplication::translate("Staduimpage", "SORT", nullptr));
        filter->setItemText(1, QCoreApplication::translate("Staduimpage", "Sort by Name [A_Z]", nullptr));
        filter->setItemText(2, QCoreApplication::translate("Staduimpage", "Sort by Name [Z_A]", nullptr));
        filter->setItemText(3, QCoreApplication::translate("Staduimpage", "Sort by Capacity ASC", nullptr));
        filter->setItemText(4, QCoreApplication::translate("Staduimpage", "Sort by Capacity DESC ", nullptr));

        prevPageTable->setText(QString());
        nextPageTable->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("Staduimpage", "Staduims List", nullptr));
        Name->setPlaceholderText(QCoreApplication::translate("Staduimpage", "Name", nullptr));
        Adress->setPlaceholderText(QCoreApplication::translate("Staduimpage", "Adress", nullptr));
        AddStadium->setText(QCoreApplication::translate("Staduimpage", "Add Staduim", nullptr));
        capacity->setPlaceholderText(QCoreApplication::translate("Staduimpage", "Capacity", nullptr));
        status->setPlaceholderText(QCoreApplication::translate("Staduimpage", "Status", nullptr));
        lineEdit->setText(QCoreApplication::translate("Staduimpage", "Name :", nullptr));
        lineEdit_2->setText(QCoreApplication::translate("Staduimpage", "Adress :", nullptr));
        lineEdit_3->setText(QCoreApplication::translate("Staduimpage", "Capacity :", nullptr));
        lineEdit_4->setText(QCoreApplication::translate("Staduimpage", "Status :", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("Staduimpage", "Add staduim ", nullptr));
        showChartButton->setText(QCoreApplication::translate("Staduimpage", "STADIUM STATUS DISTRIBUTION", nullptr));
        showTopStadiumsButton->setText(QCoreApplication::translate("Staduimpage", "TOP 5 STADIUMS BY CAPACITY", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("Staduimpage", "Statistics", nullptr));
        stadiumid->setText(QCoreApplication::translate("Staduimpage", "STADIUM ID :", nullptr));
        date->setText(QCoreApplication::translate("Staduimpage", "DATE :", nullptr));
        stadiumidinput->setPlaceholderText(QCoreApplication::translate("Staduimpage", "STADIUM ID", nullptr));
        checkButton->setText(QCoreApplication::translate("Staduimpage", "CHECK", nullptr));
        lineEdit_5->setPlaceholderText(QCoreApplication::translate("Staduimpage", "Stadium Availability & Weather CheckStadium Availability & Weather Check", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QCoreApplication::translate("Staduimpage", "Availability", nullptr));
        matchider->setText(QString());
        matchid->setText(QCoreApplication::translate("Staduimpage", "MATCH ID :", nullptr));
        matchidInput->setText(QString());
        matchidInput->setPlaceholderText(QCoreApplication::translate("Staduimpage", "MATCH ID", nullptr));
        checkSeatsButton->setText(QCoreApplication::translate("Staduimpage", "CHECK", nullptr));
        attendanceLabel->setText(QString());
        greenColor->setText(QCoreApplication::translate("Staduimpage", "FULL", nullptr));
        redColor->setText(QCoreApplication::translate("Staduimpage", "EMPTY", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QCoreApplication::translate("Staduimpage", "Attendance", nullptr));
        exitButton->setText(QString());
        homeButton->setText(QString());
        notifButton->setText(QString());
        aboutButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Staduimpage: public Ui_Staduimpage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STADUIMPAGE_H
