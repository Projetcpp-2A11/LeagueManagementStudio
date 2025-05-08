/********************************************************************************
** Form generated from reading UI file 'playerpage.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLAYERPAGE_H
#define UI_PLAYERPAGE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_playerPage
{
public:
    QWidget *contentArea;
    QTabWidget *tabWidget;
    QWidget *tab;
    QLineEdit *searchLineEdit;
    QPushButton *searchButton;
    QPushButton *sortButton;
    QPushButton *exportButton;
    QTableWidget *playerTableWidget;
    QPushButton *nextPageTable;
    QPushButton *prevPageTable;
    QPushButton *refreshButton;
    QWidget *tab_2;
    QLineEdit *firstName1;
    QLineEdit *lastName;
    QLineEdit *phoneNum;
    QComboBox *teamID;
    QLineEdit *status;
    QPushButton *addPlayerButton;
    QComboBox *positionComboBox;
    QLineEdit *playerNumber;
    QLineEdit *playerImage;
    QPushButton *BrowseImageButton;
    QWidget *tab_3;
    QSplitter *chartView;
    QPushButton *statistiqueButton;
    QWidget *sidebar;
    QPushButton *exitButton;
    QPushButton *homeButton;
    QPushButton *aboutButton;
    QPushButton *notifButton;

    void setupUi(QWidget *playerPage)
    {
        if (playerPage->objectName().isEmpty())
            playerPage->setObjectName("playerPage");
        playerPage->resize(1050, 681);
        contentArea = new QWidget(playerPage);
        contentArea->setObjectName("contentArea");
        contentArea->setGeometry(QRect(0, 0, 1050, 681));
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
        tabWidget->setCursor(QCursor(Qt::CursorShape::ArrowCursor));
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
        searchLineEdit = new QLineEdit(tab);
        searchLineEdit->setObjectName("searchLineEdit");
        searchLineEdit->setGeometry(QRect(30, 30, 241, 71));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Segoe UI")});
        font1.setPointSize(14);
        font1.setBold(false);
        font1.setItalic(false);
        searchLineEdit->setFont(font1);
        searchLineEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        searchButton->setGeometry(QRect(290, 40, 66, 51));
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
        sortButton = new QPushButton(tab);
        sortButton->setObjectName("sortButton");
        sortButton->setGeometry(QRect(380, 40, 66, 51));
        sortButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        sortButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        sortButton->setIcon(icon1);
        exportButton = new QPushButton(tab);
        exportButton->setObjectName("exportButton");
        exportButton->setGeometry(QRect(130, 570, 231, 51));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Segoe UI")});
        font2.setPointSize(14);
        font2.setBold(true);
        font2.setItalic(false);
        exportButton->setFont(font2);
        exportButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        exportButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        exportButton->setIcon(icon2);
        exportButton->setIconSize(QSize(40, 50));
        playerTableWidget = new QTableWidget(tab);
        if (playerTableWidget->columnCount() < 6)
            playerTableWidget->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        playerTableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        playerTableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        playerTableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        playerTableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        playerTableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        playerTableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        playerTableWidget->setObjectName("playerTableWidget");
        playerTableWidget->setGeometry(QRect(10, 110, 901, 451));
        playerTableWidget->viewport()->setProperty("cursor", QVariant(QCursor(Qt::CursorShape::CrossCursor)));
        playerTableWidget->setStyleSheet(QString::fromUtf8("QTableWidget {\n"
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
        playerTableWidget->horizontalHeader()->setStretchLastSection(true);
        nextPageTable = new QPushButton(tab);
        nextPageTable->setObjectName("nextPageTable");
        nextPageTable->setGeometry(QRect(700, 570, 66, 31));
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
        prevPageTable->setGeometry(QRect(780, 569, 66, 31));
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
        refreshButton = new QPushButton(tab);
        refreshButton->setObjectName("refreshButton");
        refreshButton->setGeometry(QRect(770, 50, 66, 51));
        refreshButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        refreshButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        refreshButton->setIcon(icon5);
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        firstName1 = new QLineEdit(tab_2);
        firstName1->setObjectName("firstName1");
        firstName1->setGeometry(QRect(80, 70, 301, 41));
        firstName1->setFont(font1);
        firstName1->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        lastName = new QLineEdit(tab_2);
        lastName->setObjectName("lastName");
        lastName->setGeometry(QRect(80, 122, 301, 41));
        lastName->setFont(font1);
        lastName->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        phoneNum = new QLineEdit(tab_2);
        phoneNum->setObjectName("phoneNum");
        phoneNum->setGeometry(QRect(80, 220, 301, 41));
        phoneNum->setFont(font1);
        phoneNum->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        teamID = new QComboBox(tab_2);
        teamID->setObjectName("teamID");
        teamID->setGeometry(QRect(80, 420, 301, 41));
        teamID->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        teamID->setStyleSheet(QString::fromUtf8("QComboBox {\n"
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
        status = new QLineEdit(tab_2);
        status->setObjectName("status");
        status->setGeometry(QRect(80, 270, 301, 41));
        status->setFont(font1);
        status->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        addPlayerButton = new QPushButton(tab_2);
        addPlayerButton->setObjectName("addPlayerButton");
        addPlayerButton->setGeometry(QRect(350, 520, 221, 61));
        addPlayerButton->setFont(font2);
        addPlayerButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        addPlayerButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/textures/textures/addIcon.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        addPlayerButton->setIcon(icon6);
        addPlayerButton->setIconSize(QSize(50, 50));
        positionComboBox = new QComboBox(tab_2);
        positionComboBox->addItem(QString());
        positionComboBox->addItem(QString());
        positionComboBox->addItem(QString());
        positionComboBox->addItem(QString());
        positionComboBox->addItem(QString());
        positionComboBox->addItem(QString());
        positionComboBox->addItem(QString());
        positionComboBox->addItem(QString());
        positionComboBox->addItem(QString());
        positionComboBox->addItem(QString());
        positionComboBox->setObjectName("positionComboBox");
        positionComboBox->setGeometry(QRect(80, 170, 301, 41));
        positionComboBox->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        positionComboBox->setStyleSheet(QString::fromUtf8("QComboBox {\n"
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
        playerNumber = new QLineEdit(tab_2);
        playerNumber->setObjectName("playerNumber");
        playerNumber->setGeometry(QRect(80, 370, 301, 41));
        playerNumber->setFont(font1);
        playerNumber->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        playerImage = new QLineEdit(tab_2);
        playerImage->setObjectName("playerImage");
        playerImage->setGeometry(QRect(80, 320, 301, 41));
        playerImage->setFont(font1);
        playerImage->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        BrowseImageButton = new QPushButton(tab_2);
        BrowseImageButton->setObjectName("BrowseImageButton");
        BrowseImageButton->setGeometry(QRect(390, 310, 192, 51));
        BrowseImageButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName("tab_3");
        chartView = new QSplitter(tab_3);
        chartView->setObjectName("chartView");
        chartView->setGeometry(QRect(50, 110, 779, 283));
        chartView->setOrientation(Qt::Orientation::Horizontal);
        statistiqueButton = new QPushButton(tab_3);
        statistiqueButton->setObjectName("statistiqueButton");
        statistiqueButton->setGeometry(QRect(310, 430, 221, 61));
        statistiqueButton->setFont(font2);
        statistiqueButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        statistiqueButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        statistiqueButton->setIcon(icon6);
        statistiqueButton->setIconSize(QSize(50, 50));
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
        icon7.addFile(QString::fromUtf8(":/textures/textures/exitIcon.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        exitButton->setIcon(icon7);
        exitButton->setIconSize(QSize(50, 50));
        homeButton = new QPushButton(sidebar);
        homeButton->setObjectName("homeButton");
        homeButton->setGeometry(QRect(50, 10, 75, 61));
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
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/textures/textures/homeIcon.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        homeButton->setIcon(icon8);
        homeButton->setIconSize(QSize(50, 50));
        aboutButton = new QPushButton(sidebar);
        aboutButton->setObjectName("aboutButton");
        aboutButton->setGeometry(QRect(50, 170, 71, 61));
        aboutButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        aboutButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/textures/textures/aboutIcon.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        aboutButton->setIcon(icon9);
        aboutButton->setIconSize(QSize(50, 50));
        notifButton = new QPushButton(sidebar);
        notifButton->setObjectName("notifButton");
        notifButton->setGeometry(QRect(50, 90, 75, 71));
        notifButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        notifButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/textures/textures/notifsIcon.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        notifButton->setIcon(icon10);
        notifButton->setIconSize(QSize(50, 50));
        notifButton->raise();
        homeButton->raise();
        aboutButton->raise();
        exitButton->raise();

        retranslateUi(playerPage);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(playerPage);
    } // setupUi

    void retranslateUi(QWidget *playerPage)
    {
        playerPage->setWindowTitle(QCoreApplication::translate("playerPage", "Form", nullptr));
        searchLineEdit->setPlaceholderText(QCoreApplication::translate("playerPage", "Search player", nullptr));
        searchButton->setText(QString());
        sortButton->setText(QString());
        exportButton->setText(QCoreApplication::translate("playerPage", "Export List", nullptr));
        QTableWidgetItem *___qtablewidgetitem = playerTableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("playerPage", "FIRSTNAME", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = playerTableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("playerPage", "LASTNAME", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = playerTableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("playerPage", "POSITION", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = playerTableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("playerPage", "STATUS", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = playerTableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("playerPage", "TEAMID", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = playerTableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("playerPage", "ACTIONS", nullptr));
        nextPageTable->setText(QString());
        prevPageTable->setText(QString());
        refreshButton->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("playerPage", "Player List", nullptr));
        firstName1->setText(QString());
        firstName1->setPlaceholderText(QCoreApplication::translate("playerPage", "First Name", nullptr));
        lastName->setPlaceholderText(QCoreApplication::translate("playerPage", "Last Name", nullptr));
        phoneNum->setPlaceholderText(QCoreApplication::translate("playerPage", "Phone Number", nullptr));
        teamID->setPlaceholderText(QCoreApplication::translate("playerPage", "Select ID", nullptr));
        status->setPlaceholderText(QCoreApplication::translate("playerPage", "Status", nullptr));
        addPlayerButton->setText(QCoreApplication::translate("playerPage", "Add Player", nullptr));
        positionComboBox->setItemText(0, QCoreApplication::translate("playerPage", "GK", nullptr));
        positionComboBox->setItemText(1, QCoreApplication::translate("playerPage", "RB", nullptr));
        positionComboBox->setItemText(2, QCoreApplication::translate("playerPage", "LB", nullptr));
        positionComboBox->setItemText(3, QCoreApplication::translate("playerPage", "CB", nullptr));
        positionComboBox->setItemText(4, QCoreApplication::translate("playerPage", "CM", nullptr));
        positionComboBox->setItemText(5, QCoreApplication::translate("playerPage", "RM", nullptr));
        positionComboBox->setItemText(6, QCoreApplication::translate("playerPage", "LM", nullptr));
        positionComboBox->setItemText(7, QCoreApplication::translate("playerPage", "RW", nullptr));
        positionComboBox->setItemText(8, QCoreApplication::translate("playerPage", "LW", nullptr));
        positionComboBox->setItemText(9, QCoreApplication::translate("playerPage", "ST", nullptr));

        positionComboBox->setPlaceholderText(QCoreApplication::translate("playerPage", "Select Position", nullptr));
        playerNumber->setPlaceholderText(QCoreApplication::translate("playerPage", "Player Number", nullptr));
        playerImage->setPlaceholderText(QString());
        BrowseImageButton->setText(QCoreApplication::translate("playerPage", "Add Photo", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("playerPage", "Add Player", nullptr));
        statistiqueButton->setText(QCoreApplication::translate("playerPage", "Statistique", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("playerPage", "Statistics", nullptr));
        exitButton->setText(QString());
        homeButton->setText(QString());
        aboutButton->setText(QString());
        notifButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class playerPage: public Ui_playerPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLAYERPAGE_H
