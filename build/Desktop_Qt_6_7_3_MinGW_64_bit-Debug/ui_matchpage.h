/********************************************************************************
** Form generated from reading UI file 'matchpage.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MATCHPAGE_H
#define UI_MATCHPAGE_H

#include <QtCore/QDate>
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

class Ui_MatchPage
{
public:
    QHBoxLayout *horizontalLayout;
    QWidget *contentArea;
    QWidget *contentArea_2;
    QTabWidget *tabWidget;
    QWidget *tab;
    QLineEdit *searchMatchInput;
    QPushButton *searchButton;
    QPushButton *filterButton;
    QPushButton *exportListButton;
    QTableWidget *matchsTable;
    QPushButton *refresh;
    QPushButton *nextPageTable;
    QPushButton *prevPageTable;
    QWidget *tab_2;
    QLineEdit *score;
    QPushButton *addMatchButton;
    QComboBox *team2;
    QComboBox *team1;
    QDateEdit *datematch;
    QComboBox *stade;
    QLabel *messteam;
    QLabel *messteam_2;
    QLabel *messscore;
    QLabel *messstaduim;
    QLabel *messdate;
    QWidget *tab_3;
    QSplitter *Stats;
    QPushButton *statButton;
    QWidget *sidebar_2;
    QPushButton *exitButton;
    QPushButton *aboutButton_2;
    QPushButton *notifButton_2;
    QPushButton *homeButton;

    void setupUi(QWidget *MatchPage)
    {
        if (MatchPage->objectName().isEmpty())
            MatchPage->setObjectName("MatchPage");
        MatchPage->resize(1050, 681);
        horizontalLayout = new QHBoxLayout(MatchPage);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        contentArea = new QWidget(MatchPage);
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
        contentArea_2 = new QWidget(contentArea);
        contentArea_2->setObjectName("contentArea_2");
        contentArea_2->setGeometry(QRect(150, 20, 1050, 681));
        sizePolicy.setHeightForWidth(contentArea_2->sizePolicy().hasHeightForWidth());
        contentArea_2->setSizePolicy(sizePolicy);
        contentArea_2->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, \n"
"                                x1:0, y1:0, x2:0, y2:1, \n"
"                                stop:0 rgba(6, 6, 6, 255), \n"
"                                stop:0.41 rgba(56, 50, 52, 255), \n"
"                                stop:1 rgba(34, 33, 33, 255));;\n"
""));
        tabWidget = new QTabWidget(contentArea_2);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(10, 0, 941, 671));
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
        searchMatchInput = new QLineEdit(tab);
        searchMatchInput->setObjectName("searchMatchInput");
        searchMatchInput->setGeometry(QRect(10, 40, 221, 61));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Segoe UI")});
        font1.setPointSize(14);
        font1.setBold(false);
        font1.setItalic(false);
        searchMatchInput->setFont(font1);
        searchMatchInput->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        searchButton->setGeometry(QRect(240, 40, 66, 61));
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
        filterButton->setGeometry(QRect(310, 42, 66, 61));
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
        exportListButton->setGeometry(QRect(380, 42, 221, 61));
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
        icon2.addFile(QString::fromUtf8(":/textures/textures/exportIcon.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        exportListButton->setIcon(icon2);
        exportListButton->setIconSize(QSize(40, 50));
        matchsTable = new QTableWidget(tab);
        if (matchsTable->columnCount() < 6)
            matchsTable->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        matchsTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        matchsTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        matchsTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        matchsTable->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        matchsTable->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        matchsTable->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        matchsTable->setObjectName("matchsTable");
        matchsTable->setGeometry(QRect(10, 110, 871, 431));
        matchsTable->setStyleSheet(QString::fromUtf8("QTableWidget {\n"
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
        matchsTable->setEditTriggers(QAbstractItemView::EditTrigger::NoEditTriggers);
        matchsTable->horizontalHeader()->setStretchLastSection(true);
        refresh = new QPushButton(tab);
        refresh->setObjectName("refresh");
        refresh->setGeometry(QRect(800, 40, 66, 61));
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
        QIcon icon3(QIcon::fromTheme(QIcon::ThemeIcon::ViewRefresh));
        refresh->setIcon(icon3);
        nextPageTable = new QPushButton(tab);
        nextPageTable->setObjectName("nextPageTable");
        nextPageTable->setGeometry(QRect(700, 550, 66, 41));
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
        prevPageTable = new QPushButton(tab);
        prevPageTable->setObjectName("prevPageTable");
        prevPageTable->setGeometry(QRect(780, 550, 66, 41));
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
        prevPageTable->setIcon(icon4);
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        score = new QLineEdit(tab_2);
        score->setObjectName("score");
        score->setGeometry(QRect(260, 220, 301, 81));
        score->setFont(font1);
        score->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        addMatchButton = new QPushButton(tab_2);
        addMatchButton->setObjectName("addMatchButton");
        addMatchButton->setGeometry(QRect(310, 540, 231, 51));
        addMatchButton->setFont(font2);
        addMatchButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        addMatchButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        QIcon icon5;
        icon5.addFile(QString::fromUtf8("textures/addIcon.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        addMatchButton->setIcon(icon5);
        addMatchButton->setIconSize(QSize(50, 50));
        team2 = new QComboBox(tab_2);
        team2->setObjectName("team2");
        team2->setGeometry(QRect(506, 40, 221, 71));
        team2->setStyleSheet(QString::fromUtf8("QComboBox {\n"
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
        team1 = new QComboBox(tab_2);
        team1->setObjectName("team1");
        team1->setGeometry(QRect(80, 40, 231, 71));
        team1->setStyleSheet(QString::fromUtf8("QComboBox {\n"
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
        datematch = new QDateEdit(tab_2);
        datematch->setObjectName("datematch");
        datematch->setGeometry(QRect(500, 400, 261, 71));
        datematch->setStyleSheet(QString::fromUtf8("QDateEdit {\n"
"    background-color: #ffffff;\n"
"    padding: 8px 12px;\n"
"    color: #000000;\n"
"    font: 14pt \"Segoe UI\";\n"
"    border: 2px solid #990000;\n"
"    border-radius: 8px;\n"
"}\n"
"\n"
"/* Bouton de calendrier */\n"
"QDateEdit::drop-down {\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: top right;\n"
"    width: 30px;\n"
"    border-left: 2px solid #990000;\n"
"    border-top-right-radius: 8px;\n"
"    border-bottom-right-radius: 8px;\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:1,\n"
"                                 stop:0 #b30000,\n"
"                                 stop:1 #ff4d4d);\n"
"    image: url(:/textures/textures/calendarIcon.png); /* Remplace avec ton ic\303\264ne */\n"
"}\n"
"\n"
"/* Hover effect */\n"
"QDateEdit:hover {\n"
"    border: 2px solid #ff1a1a;\n"
"    background-color: #fff0f0;\n"
"}\n"
"\n"
"/* Focus effect */\n"
"QDateEdit:focus {\n"
"    border: 2px solid #ff0000;\n"
"    background-color: #ffffff;\n"
"}\n"
""));
        datematch->setDate(QDate(2025, 3, 1));
        stade = new QComboBox(tab_2);
        stade->setObjectName("stade");
        stade->setGeometry(QRect(80, 400, 251, 71));
        stade->setStyleSheet(QString::fromUtf8("QComboBox {\n"
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
        messteam = new QLabel(tab_2);
        messteam->setObjectName("messteam");
        messteam->setGeometry(QRect(80, 130, 231, 41));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Arial Rounded MT Bold")});
        font3.setPointSize(7);
        messteam->setFont(font3);
        messteam->setStyleSheet(QString::fromUtf8("border:none;\n"
"background:none;"));
        messteam_2 = new QLabel(tab_2);
        messteam_2->setObjectName("messteam_2");
        messteam_2->setGeometry(QRect(500, 130, 231, 41));
        messteam_2->setFont(font3);
        messteam_2->setStyleSheet(QString::fromUtf8("border:none;\n"
"background:none;"));
        messscore = new QLabel(tab_2);
        messscore->setObjectName("messscore");
        messscore->setGeometry(QRect(260, 320, 291, 61));
        messscore->setFont(font3);
        messscore->setStyleSheet(QString::fromUtf8("border:none;\n"
"background:none;"));
        messstaduim = new QLabel(tab_2);
        messstaduim->setObjectName("messstaduim");
        messstaduim->setGeometry(QRect(90, 490, 231, 41));
        messstaduim->setFont(font3);
        messstaduim->setStyleSheet(QString::fromUtf8("border:none;\n"
"background:none;"));
        messdate = new QLabel(tab_2);
        messdate->setObjectName("messdate");
        messdate->setGeometry(QRect(510, 500, 231, 41));
        messdate->setFont(font3);
        messdate->setStyleSheet(QString::fromUtf8("border:none;\n"
"background:none;"));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName("tab_3");
        Stats = new QSplitter(tab_3);
        Stats->setObjectName("Stats");
        Stats->setGeometry(QRect(-2, 20, 851, 531));
        Stats->setOrientation(Qt::Orientation::Horizontal);
        statButton = new QPushButton(tab_3);
        statButton->setObjectName("statButton");
        statButton->setGeometry(QRect(40, 20, 791, 73));
        statButton->setFont(font2);
        statButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        statButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        statButton->setIcon(icon2);
        statButton->setIconSize(QSize(40, 50));
        tabWidget->addTab(tab_3, QString());
        sidebar_2 = new QWidget(contentArea);
        sidebar_2->setObjectName("sidebar_2");
        sidebar_2->setGeometry(QRect(70, -10, 91, 691));
        sidebar_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        exitButton = new QPushButton(sidebar_2);
        exitButton->setObjectName("exitButton");
        exitButton->setGeometry(QRect(0, 240, 81, 71));
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
        aboutButton_2 = new QPushButton(sidebar_2);
        aboutButton_2->setObjectName("aboutButton_2");
        aboutButton_2->setGeometry(QRect(0, 170, 81, 61));
        aboutButton_2->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        aboutButton_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/textures/textures/aboutIcon.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        aboutButton_2->setIcon(icon7);
        aboutButton_2->setIconSize(QSize(50, 50));
        notifButton_2 = new QPushButton(sidebar_2);
        notifButton_2->setObjectName("notifButton_2");
        notifButton_2->setGeometry(QRect(0, 90, 81, 71));
        notifButton_2->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        notifButton_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        notifButton_2->setIcon(icon8);
        notifButton_2->setIconSize(QSize(50, 50));
        homeButton = new QPushButton(sidebar_2);
        homeButton->setObjectName("homeButton");
        homeButton->setGeometry(QRect(0, 20, 81, 61));
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
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/textures/textures/homeIcon.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        homeButton->setIcon(icon9);
        homeButton->setIconSize(QSize(50, 50));

        horizontalLayout->addWidget(contentArea);


        retranslateUi(MatchPage);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MatchPage);
    } // setupUi

    void retranslateUi(QWidget *MatchPage)
    {
        MatchPage->setWindowTitle(QCoreApplication::translate("MatchPage", "Form", nullptr));
        searchMatchInput->setPlaceholderText(QCoreApplication::translate("MatchPage", "Search Match", nullptr));
        searchButton->setText(QString());
        filterButton->setText(QString());
        exportListButton->setText(QCoreApplication::translate("MatchPage", "Export List", nullptr));
        QTableWidgetItem *___qtablewidgetitem = matchsTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MatchPage", "Team 1", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = matchsTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MatchPage", "Team 2", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = matchsTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MatchPage", "Date", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = matchsTable->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MatchPage", "Score", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = matchsTable->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MatchPage", "Stadium", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = matchsTable->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MatchPage", "Actions", nullptr));
        refresh->setText(QString());
        nextPageTable->setText(QString());
        prevPageTable->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MatchPage", "Match List", nullptr));
        score->setPlaceholderText(QCoreApplication::translate("MatchPage", "Final Score", nullptr));
        addMatchButton->setText(QCoreApplication::translate("MatchPage", "Add Match", nullptr));
        team2->setPlaceholderText(QCoreApplication::translate("MatchPage", "Team 2", nullptr));
        team1->setPlaceholderText(QCoreApplication::translate("MatchPage", "Team 1", nullptr));
        stade->setPlaceholderText(QCoreApplication::translate("MatchPage", "Stadium", nullptr));
        messteam->setText(QString());
        messteam_2->setText(QString());
        messscore->setText(QString());
        messstaduim->setText(QString());
        messdate->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MatchPage", "Add Match", nullptr));
        statButton->setText(QCoreApplication::translate("MatchPage", "Stat", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("MatchPage", "Statistics", nullptr));
        exitButton->setText(QString());
        aboutButton_2->setText(QString());
        notifButton_2->setText(QString());
        homeButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MatchPage: public Ui_MatchPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MATCHPAGE_H
