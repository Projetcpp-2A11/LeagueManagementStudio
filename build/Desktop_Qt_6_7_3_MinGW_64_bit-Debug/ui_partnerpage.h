/********************************************************************************
** Form generated from reading UI file 'partnerpage.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PARTNERPAGE_H
#define UI_PARTNERPAGE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_partnerpage
{
public:
    QHBoxLayout *horizontalLayout;
    QWidget *contentArea;
    QTabWidget *tabWidget;
    QWidget *tab;
    QLineEdit *searchpartner;
    QPushButton *searchButton;
    QPushButton *filterButton;
    QPushButton *exportListButton;
    QTableWidget *partnersTable;
    QPushButton *nextPageTable;
    QPushButton *prevPageTable;
    QPushButton *refrechebutton;
    QPushButton *deletepartner;
    QPushButton *updatepartner;
    QWidget *tab_2;
    QLineEdit *name;
    QPushButton *addPartnerButton;
    QComboBox *stadiumList;
    QLabel *label;
    QLabel *label_2;
    QDateEdit *startDate;
    QLabel *label_3;
    QDateEdit *endDate;
    QLabel *label_4;
    QComboBox *teamList;
    QPushButton *addPartnerandSponsor;
    QComboBox *partnerList;
    QPushButton *recommend_2;
    QWidget *tab_3;
    QSplitter *splitter;
    QPushButton *start;
    QWidget *sidebar;
    QPushButton *exitButton;
    QPushButton *aboutButton;
    QPushButton *notifButton;
    QPushButton *homeButton;

    void setupUi(QWidget *partnerpage)
    {
        if (partnerpage->objectName().isEmpty())
            partnerpage->setObjectName("partnerpage");
        partnerpage->resize(1050, 681);
        horizontalLayout = new QHBoxLayout(partnerpage);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        contentArea = new QWidget(partnerpage);
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
        searchpartner = new QLineEdit(tab);
        searchpartner->setObjectName("searchpartner");
        searchpartner->setGeometry(QRect(20, 40, 181, 61));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Segoe UI")});
        font1.setPointSize(14);
        font1.setBold(false);
        font1.setItalic(false);
        searchpartner->setFont(font1);
        searchpartner->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        searchButton->setGeometry(QRect(210, 50, 66, 51));
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
        filterButton = new QPushButton(tab);
        filterButton->setObjectName("filterButton");
        filterButton->setGeometry(QRect(290, 50, 66, 51));
        filterButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        filterButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/textures/textures/filterIcon.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        filterButton->setIcon(icon1);
        exportListButton = new QPushButton(tab);
        exportListButton->setObjectName("exportListButton");
        exportListButton->setGeometry(QRect(20, 570, 192, 51));
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
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("textures/exportIcon.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        exportListButton->setIcon(icon2);
        exportListButton->setIconSize(QSize(40, 50));
        partnersTable = new QTableWidget(tab);
        if (partnersTable->columnCount() < 5)
            partnersTable->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        partnersTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        partnersTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        partnersTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        partnersTable->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        partnersTable->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        partnersTable->setObjectName("partnersTable");
        partnersTable->setGeometry(QRect(20, 110, 901, 451));
        partnersTable->setStyleSheet(QString::fromUtf8("QTableWidget {\n"
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
        partnersTable->setEditTriggers(QAbstractItemView::EditTrigger::NoEditTriggers);
        partnersTable->horizontalHeader()->setStretchLastSection(true);
        nextPageTable = new QPushButton(tab);
        nextPageTable->setObjectName("nextPageTable");
        nextPageTable->setGeometry(QRect(790, 570, 66, 41));
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
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/textures/textures/prevIcon.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        nextPageTable->setIcon(icon3);
        prevPageTable = new QPushButton(tab);
        prevPageTable->setObjectName("prevPageTable");
        prevPageTable->setGeometry(QRect(860, 570, 66, 41));
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
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/textures/textures/nextIcon.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        prevPageTable->setIcon(icon4);
        refrechebutton = new QPushButton(tab);
        refrechebutton->setObjectName("refrechebutton");
        refrechebutton->setGeometry(QRect(840, 50, 66, 51));
        refrechebutton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        refrechebutton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        QIcon icon5(QIcon::fromTheme(QIcon::ThemeIcon::ViewRefresh));
        refrechebutton->setIcon(icon5);
        deletepartner = new QPushButton(tab);
        deletepartner->setObjectName("deletepartner");
        deletepartner->setGeometry(QRect(400, 50, 192, 51));
        deletepartner->setFont(font2);
        deletepartner->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        deletepartner->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        QIcon icon6(QIcon::fromTheme(QIcon::ThemeIcon::EditDelete));
        deletepartner->setIcon(icon6);
        deletepartner->setIconSize(QSize(50, 50));
        updatepartner = new QPushButton(tab);
        updatepartner->setObjectName("updatepartner");
        updatepartner->setGeometry(QRect(600, 50, 192, 51));
        updatepartner->setFont(font2);
        updatepartner->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        updatepartner->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        QIcon icon7(QIcon::fromTheme(QIcon::ThemeIcon::DocumentProperties));
        updatepartner->setIcon(icon7);
        updatepartner->setIconSize(QSize(50, 50));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        name = new QLineEdit(tab_2);
        name->setObjectName("name");
        name->setGeometry(QRect(260, 70, 301, 41));
        name->setFont(font1);
        name->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        addPartnerButton = new QPushButton(tab_2);
        addPartnerButton->setObjectName("addPartnerButton");
        addPartnerButton->setGeometry(QRect(140, 520, 231, 61));
        addPartnerButton->setFont(font2);
        addPartnerButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        addPartnerButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        QIcon icon8;
        icon8.addFile(QString::fromUtf8("textures/addIcon.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        addPartnerButton->setIcon(icon8);
        addPartnerButton->setIconSize(QSize(50, 50));
        stadiumList = new QComboBox(tab_2);
        stadiumList->setObjectName("stadiumList");
        stadiumList->setGeometry(QRect(480, 380, 201, 41));
        stadiumList->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    background-color: #ffffff;\n"
"    padding: 8px 12px;\n"
"    color: #000000;\n"
"    font: 14pt \"Segoe UI\";\n"
"    border: 2px solid #990000;\n"
"    border-radius: 8px;\n"
"}\n"
"\n"
"/* Drop-down arrow button */\n"
"QComboBox::drop-down {\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: top right;\n"
"    width: 30px;\n"
"    border-left: 2px solid #990000;\n"
"    border-top-right-radius: 8px;\n"
"    border-bottom-right-radius: 8px;\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:1,\n"
"                                 stop:0 #b30000,\n"
"                                 stop:1 #ff4d4d);\n"
"    image: url(:/textures/textures/downArrowIcon.png);\n"
"}\n"
"\n"
"/* When hovered */\n"
"QComboBox:hover {\n"
"    border: 2px solid #ff1a1a;\n"
"    background-color: #fff0f0;\n"
"}\n"
"\n"
"/* When focused */\n"
"QComboBox:focus {\n"
"    border: 2px solid #ff0000;\n"
"}\n"
"\n"
"/* Drop-down popup style */\n"
"QComboBox QAbstractItemView {\n"
"    background-color"
                        ": #ffffff;\n"
"    border: 2px solid #b30000;\n"
"    selection-background-color: #d40000;\n"
"    selection-color: white;\n"
"    border-radius: 8px;\n"
"    padding: 5px;\n"
"    font: 13pt \"Segoe UI\";\n"
"    color: #000000;\n"
"}\n"
""));
        label = new QLabel(tab_2);
        label->setObjectName("label");
        label->setGeometry(QRect(350, 10, 191, 41));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Arial")});
        font3.setPointSize(28);
        label->setFont(font3);
        label->setStyleSheet(QString::fromUtf8("background:transparent;"));
        label_2 = new QLabel(tab_2);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(240, 120, 421, 41));
        label_2->setFont(font3);
        label_2->setStyleSheet(QString::fromUtf8("background:transparent;"));
        startDate = new QDateEdit(tab_2);
        startDate->setObjectName("startDate");
        startDate->setGeometry(QRect(110, 270, 161, 31));
        startDate->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    background-color: #ffffff;\n"
"    padding: 8px 12px;\n"
"    color: #000000;\n"
"    font: 14pt \"Segoe UI\";\n"
"    border: 2px solid #990000;\n"
"    border-radius: 8px;\n"
"}\n"
"\n"
"/* Drop-down arrow button */\n"
"QComboBox::drop-down {\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: top right;\n"
"    width: 30px;\n"
"    border-left: 2px solid #990000;\n"
"    border-top-right-radius: 8px;\n"
"    border-bottom-right-radius: 8px;\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:1,\n"
"                                 stop:0 #b30000,\n"
"                                 stop:1 #ff4d4d);\n"
"    image: url(:/textures/textures/downArrowIcon.png);\n"
"}\n"
"\n"
"/* When hovered */\n"
"QComboBox:hover {\n"
"    border: 2px solid #ff1a1a;\n"
"    background-color: #fff0f0;\n"
"}\n"
"\n"
"/* When focused */\n"
"QComboBox:focus {\n"
"    border: 2px solid #ff0000;\n"
"}\n"
"\n"
"/* Drop-down popup style */\n"
"QComboBox QAbstractItemView {\n"
"    background-color"
                        ": #ffffff;\n"
"    border: 2px solid #b30000;\n"
"    selection-background-color: #d40000;\n"
"    selection-color: white;\n"
"    border-radius: 8px;\n"
"    padding: 5px;\n"
"    font: 13pt \"Segoe UI\";\n"
"    color: #000000;\n"
"}\n"
""));
        label_3 = new QLabel(tab_2);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(110, 230, 131, 41));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Arial")});
        font4.setPointSize(18);
        label_3->setFont(font4);
        label_3->setStyleSheet(QString::fromUtf8("background:transparent;"));
        endDate = new QDateEdit(tab_2);
        endDate->setObjectName("endDate");
        endDate->setGeometry(QRect(480, 270, 161, 31));
        label_4 = new QLabel(tab_2);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(480, 230, 131, 41));
        label_4->setFont(font4);
        label_4->setStyleSheet(QString::fromUtf8("background:transparent;"));
        teamList = new QComboBox(tab_2);
        teamList->setObjectName("teamList");
        teamList->setGeometry(QRect(110, 380, 201, 41));
        teamList->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    background-color: #ffffff;\n"
"    padding: 8px 12px;\n"
"    color: #000000;\n"
"    font: 14pt \"Segoe UI\";\n"
"    border: 2px solid #990000;\n"
"    border-radius: 8px;\n"
"}\n"
"\n"
"/* Drop-down arrow button */\n"
"QComboBox::drop-down {\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: top right;\n"
"    width: 30px;\n"
"    border-left: 2px solid #990000;\n"
"    border-top-right-radius: 8px;\n"
"    border-bottom-right-radius: 8px;\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:1,\n"
"                                 stop:0 #b30000,\n"
"                                 stop:1 #ff4d4d);\n"
"    image: url(:/textures/textures/downArrowIcon.png);\n"
"}\n"
"\n"
"/* When hovered */\n"
"QComboBox:hover {\n"
"    border: 2px solid #ff1a1a;\n"
"    background-color: #fff0f0;\n"
"}\n"
"\n"
"/* When focused */\n"
"QComboBox:focus {\n"
"    border: 2px solid #ff0000;\n"
"}\n"
"\n"
"/* Drop-down popup style */\n"
"QComboBox QAbstractItemView {\n"
"    background-color"
                        ": #ffffff;\n"
"    border: 2px solid #b30000;\n"
"    selection-background-color: #d40000;\n"
"    selection-color: white;\n"
"    border-radius: 8px;\n"
"    padding: 5px;\n"
"    font: 13pt \"Segoe UI\";\n"
"    color: #000000;\n"
"}\n"
""));
        addPartnerandSponsor = new QPushButton(tab_2);
        addPartnerandSponsor->setObjectName("addPartnerandSponsor");
        addPartnerandSponsor->setGeometry(QRect(450, 520, 391, 61));
        addPartnerandSponsor->setFont(font2);
        addPartnerandSponsor->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        addPartnerandSponsor->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        addPartnerandSponsor->setIcon(icon8);
        addPartnerandSponsor->setIconSize(QSize(50, 50));
        partnerList = new QComboBox(tab_2);
        partnerList->setObjectName("partnerList");
        partnerList->setGeometry(QRect(290, 180, 201, 41));
        partnerList->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    background-color: #ffffff;\n"
"    padding: 8px 12px;\n"
"    color: #000000;\n"
"    font: 14pt \"Segoe UI\";\n"
"    border: 2px solid #990000;\n"
"    border-radius: 8px;\n"
"}\n"
"\n"
"/* Drop-down arrow button */\n"
"QComboBox::drop-down {\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: top right;\n"
"    width: 30px;\n"
"    border-left: 2px solid #990000;\n"
"    border-top-right-radius: 8px;\n"
"    border-bottom-right-radius: 8px;\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:1,\n"
"                                 stop:0 #b30000,\n"
"                                 stop:1 #ff4d4d);\n"
"    image: url(:/textures/textures/downArrowIcon.png);\n"
"}\n"
"\n"
"/* When hovered */\n"
"QComboBox:hover {\n"
"    border: 2px solid #ff1a1a;\n"
"    background-color: #fff0f0;\n"
"}\n"
"\n"
"/* When focused */\n"
"QComboBox:focus {\n"
"    border: 2px solid #ff0000;\n"
"}\n"
"\n"
"/* Drop-down popup style */\n"
"QComboBox QAbstractItemView {\n"
"    background-color"
                        ": #ffffff;\n"
"    border: 2px solid #b30000;\n"
"    selection-background-color: #d40000;\n"
"    selection-color: white;\n"
"    border-radius: 8px;\n"
"    padding: 5px;\n"
"    font: 13pt \"Segoe UI\";\n"
"    color: #000000;\n"
"}\n"
""));
        recommend_2 = new QPushButton(tab_2);
        recommend_2->setObjectName("recommend_2");
        recommend_2->setGeometry(QRect(320, 380, 66, 41));
        recommend_2->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        recommend_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        QIcon icon9(QIcon::fromTheme(QIcon::ThemeIcon::DialogError));
        recommend_2->setIcon(icon9);
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName("tab_3");
        splitter = new QSplitter(tab_3);
        splitter->setObjectName("splitter");
        splitter->setGeometry(QRect(50, 110, 779, 283));
        splitter->setOrientation(Qt::Orientation::Horizontal);
        start = new QPushButton(tab_3);
        start->setObjectName("start");
        start->setGeometry(QRect(360, 530, 192, 51));
        start->setFont(font2);
        start->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        start->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        QIcon icon10(QIcon::fromTheme(QIcon::ThemeIcon::MediaPlaybackStart));
        start->setIcon(icon10);
        start->setIconSize(QSize(40, 50));
        tabWidget->addTab(tab_3, QString());
        sidebar = new QWidget(contentArea);
        sidebar->setObjectName("sidebar");
        sidebar->setGeometry(QRect(-30, 0, 151, 681));
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
        exitButton->setGeometry(QRect(53, 240, 71, 71));
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
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/textures/textures/exitIcon.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        exitButton->setIcon(icon11);
        exitButton->setIconSize(QSize(50, 50));
        aboutButton = new QPushButton(sidebar);
        aboutButton->setObjectName("aboutButton");
        aboutButton->setGeometry(QRect(50, 170, 71, 61));
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
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/textures/textures/aboutIcon.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        aboutButton->setIcon(icon12);
        aboutButton->setIconSize(QSize(50, 50));
        notifButton = new QPushButton(sidebar);
        notifButton->setObjectName("notifButton");
        notifButton->setGeometry(QRect(50, 90, 75, 71));
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
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/textures/textures/notifsIcon.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        notifButton->setIcon(icon13);
        notifButton->setIconSize(QSize(50, 50));
        homeButton = new QPushButton(sidebar);
        homeButton->setObjectName("homeButton");
        homeButton->setGeometry(QRect(50, 20, 75, 61));
        homeButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        homeButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border:none;\n"
"\n"
"\n"
"\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: white;\n"
"    box-shadow: 0px 0px 10px rgba(255, 0, 0, 0.5);\n"
"	border-radius:15px;\n"
"}"));
        QIcon icon14;
        icon14.addFile(QString::fromUtf8(":/textures/textures/homeIcon.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        homeButton->setIcon(icon14);
        homeButton->setIconSize(QSize(50, 50));

        horizontalLayout->addWidget(contentArea);


        retranslateUi(partnerpage);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(partnerpage);
    } // setupUi

    void retranslateUi(QWidget *partnerpage)
    {
        partnerpage->setWindowTitle(QCoreApplication::translate("partnerpage", "Form", nullptr));
        searchpartner->setPlaceholderText(QCoreApplication::translate("partnerpage", "Search partner", nullptr));
        searchButton->setText(QString());
        filterButton->setText(QString());
        exportListButton->setText(QCoreApplication::translate("partnerpage", "Export List", nullptr));
        QTableWidgetItem *___qtablewidgetitem = partnersTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("partnerpage", "Partner", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = partnersTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("partnerpage", "Team", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = partnersTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("partnerpage", "Stadium", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = partnersTable->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("partnerpage", "Start date", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = partnersTable->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("partnerpage", "End date", nullptr));
        nextPageTable->setText(QString());
        prevPageTable->setText(QString());
        refrechebutton->setText(QString());
        deletepartner->setText(QCoreApplication::translate("partnerpage", " delete", nullptr));
        updatepartner->setText(QCoreApplication::translate("partnerpage", "update", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("partnerpage", "partner List", nullptr));
        name->setText(QString());
        name->setPlaceholderText(QCoreApplication::translate("partnerpage", " Name", nullptr));
        addPartnerButton->setText(QCoreApplication::translate("partnerpage", "Add Partner", nullptr));
        stadiumList->setPlaceholderText(QCoreApplication::translate("partnerpage", "Stadium List", nullptr));
        label->setText(QCoreApplication::translate("partnerpage", "Partner", nullptr));
        label_2->setText(QCoreApplication::translate("partnerpage", "Sponsorship Details", nullptr));
        label_3->setText(QCoreApplication::translate("partnerpage", "Start Date", nullptr));
        label_4->setText(QCoreApplication::translate("partnerpage", "End Date", nullptr));
        teamList->setPlaceholderText(QCoreApplication::translate("partnerpage", "Team List", nullptr));
        addPartnerandSponsor->setText(QCoreApplication::translate("partnerpage", "Add Partner and Sponsor", nullptr));
        partnerList->setPlaceholderText(QCoreApplication::translate("partnerpage", "Partner List", nullptr));
        recommend_2->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("partnerpage", "Add partner", nullptr));
        start->setText(QCoreApplication::translate("partnerpage", "stats", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("partnerpage", "Statistics", nullptr));
        exitButton->setText(QString());
        aboutButton->setText(QString());
        notifButton->setText(QString());
        homeButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class partnerpage: public Ui_partnerpage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PARTNERPAGE_H
