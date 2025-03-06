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
    QTabWidget *tabWidget;
    QWidget *tab;
    QLineEdit *searchMatchInput;
    QPushButton *searchButton;
    QPushButton *filterButton;
    QPushButton *exportListButton;
    QTableWidget *matchsTable;
    QPushButton *nextPageTable;
    QPushButton *prevPageTable;
    QPushButton *refresh;
    QWidget *tab_2;
    QLineEdit *score;
    QPushButton *addMatchButton;
    QComboBox *team1;
    QComboBox *team2;
    QDateEdit *datematch;
    QComboBox *stade;
    QWidget *tab_3;
    QSplitter *splitter;
    QWidget *sidebar;
    QPushButton *exitButton;
    QPushButton *aboutButton;
    QPushButton *notifButton;
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
        tabWidget = new QTabWidget(contentArea);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(120, 0, 941, 681));
        QFont font;
        font.setBold(true);
        tabWidget->setFont(font);
        tabWidget->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        tabWidget->setStyleSheet(QString::fromUtf8("QTabBar::tab {\n"
"    background: qlineargradient(spread:pad, \n"
"                            x1:0, y1:0, x2:1, y2:1, \n"
"                            stop:0 rgba(255, 0, 0, 255), \n"
"                            stop:0.41 rgba(195, 22, 58, 255), \n"
"                            stop:1 rgba(255, 117, 0, 255));;  ;  \n"
"    color: white;\n"
"    border: 2px solid black;\n"
"    padding: 10px;\n"
"	width: 263%\n"
"	\n"
"   \n"
"}\n"
"\n"
"\n"
"QTabBar::tab:selected {\n"
"    background:qlineargradient(spread:pad, \n"
"                            x1:0, y1:0, x2:1, y2:1, \n"
"                            stop:0 rgba(0, 213, 246, 255), \n"
"                            stop:0.18 rgba(100, 100, 138, 255), \n"
"                            stop:1 rgba(0, 212, 255, 255));;\n"
"    color: white;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QTabBar::tab:hover {\n"
"    background: lightblue;\n"
"    color: black;\n"
"}\n"
"\n"
""));
        tab = new QWidget();
        tab->setObjectName("tab");
        searchMatchInput = new QLineEdit(tab);
        searchMatchInput->setObjectName("searchMatchInput");
        searchMatchInput->setGeometry(QRect(120, 70, 181, 31));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Arial")});
        searchMatchInput->setFont(font1);
        searchMatchInput->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: white;\n"
"    border: 2px solid qlineargradient(x1: 0, y1: 0, x2: 1, y2: 1, \n"
"                                stop: 0 rgba(255, 255, 255, 255), \n"
"                                stop: 1 rgba(240, 240, 240, 255));;\n"
"    border-radius: 8px;\n"
"    padding: 5px;\n"
"    color: black;\n"
"    font-size: 16px;\n"
"}\n"
"\n"
"/* Hover effect */\n"
"QLineEdit:hover {\n"
"    border-color: #ff3347;\n"
"}\n"
"\n"
"/* Focus effect */\n"
"QLineEdit:focus {\n"
"    border-color: #ff0004;\n"
"    box-shadow: none; /* Qt stylesheets do not support box-shadow */\n"
"}\n"
""));
        searchButton = new QPushButton(tab);
        searchButton->setObjectName("searchButton");
        searchButton->setGeometry(QRect(320, 70, 41, 31));
        searchButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        searchButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color:qlineargradient(spread:pad, \n"
"                            x1:0, y1:0, x2:1, y2:1, \n"
"                            stop:0 rgba(255, 0, 0, 255), \n"
"                            stop:0.41 rgba(195, 22, 58, 255), \n"
"                            stop:1 rgba(255, 117, 0, 255));;  ;  \n"
"\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: qlineargradient(x1: 0.25, y1: 0, x2: 0.75, y2: 1, \n"
"                            stop: 0 rgba(0, 255, 254, 255),     \n"
"                            stop: 0.26 rgba(38, 170, 196, 255), \n"
"                            stop: 0.67 rgba(89, 85, 131, 255),\n"
"                            stop: 1 rgba(0, 238, 255, 255));  ; \n"
"}"));
        QIcon icon;
        icon.addFile(QString::fromUtf8("textures/searchIcon.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        searchButton->setIcon(icon);
        filterButton = new QPushButton(tab);
        filterButton->setObjectName("filterButton");
        filterButton->setGeometry(QRect(380, 70, 41, 31));
        filterButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        filterButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color:qlineargradient(spread:pad, \n"
"                            x1:0, y1:0, x2:1, y2:1, \n"
"                            stop:0 rgba(255, 0, 0, 255), \n"
"                            stop:0.41 rgba(195, 22, 58, 255), \n"
"                            stop:1 rgba(255, 117, 0, 255));;  ;  \n"
"\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: qlineargradient(x1: 0.25, y1: 0, x2: 0.75, y2: 1, \n"
"                            stop: 0 rgba(0, 255, 254, 255),     \n"
"                            stop: 0.26 rgba(38, 170, 196, 255), \n"
"                            stop: 0.67 rgba(89, 85, 131, 255),\n"
"                            stop: 1 rgba(0, 238, 255, 255));  ; \n"
"}"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("textures/filterIcon.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        filterButton->setIcon(icon1);
        exportListButton = new QPushButton(tab);
        exportListButton->setObjectName("exportListButton");
        exportListButton->setGeometry(QRect(130, 570, 191, 41));
        QFont font2;
        font2.setPointSize(18);
        exportListButton->setFont(font2);
        exportListButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        exportListButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color:qlineargradient(spread:pad, \n"
"                            x1:0, y1:0, x2:1, y2:1, \n"
"                            stop:0 rgba(255, 0, 0, 255), \n"
"                            stop:0.41 rgba(195, 22, 58, 255), \n"
"                            stop:1 rgba(255, 117, 0, 255));;  ;  \n"
"border-radius:10px;\n"
"color:white;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color:qlineargradient(x1: 0.25, y1: 0, x2: 0.75, y2: 1, \n"
"                            stop: 0 rgba(0, 255, 254, 255),     \n"
"                            stop: 0.26 rgba(38, 170, 196, 255), \n"
"                            stop: 0.67 rgba(89, 85, 131, 255),\n"
"                            stop: 1 rgba(0, 238, 255, 255));  \n"
"}"));
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
        matchsTable->setGeometry(QRect(50, 110, 871, 451));
        matchsTable->setStyleSheet(QString::fromUtf8("QTableWidget {\n"
"    background-color: #ecf0f1;\n"
"    border: 4px solid #2980b9; \n"
"    border-radius: 10px;\n"
"    gridline-color: #bdc3c7;\n"
"    font-size: 14px;\n"
"}\n"
"\n"
"QTableWidget::item {\n"
"    padding: 10px;\n"
"    border-bottom: 1px solid #bdc3c7;\n"
"	color:black;\n"
"}\n"
"\n"
"QTableWidget::item:selected {\n"
"    background-color: #3498db;\n"
"    color: white;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QTableWidget::item:hover {\n"
"    background-color: #f1c40f;\n"
"    color: black;\n"
"}\n"
"\n"
"QHeaderView::section {\n"
"    background-color: #2980b9; /* Blue header */\n"
"    color: white;\n"
"    padding: 5px 5px; /* Increase horizontal padding */\n"
"    font-size: 15px;\n"
"    font-weight: bold;\n"
"    border: 1px solid #1c5986;\n"
"    min-width: 120px; /* Minimum width for each column */\n"
"}\n"
"\n"
"QTableCornerButton::section {\n"
"    background-color: #2980b9;\n"
"    border: 1px solid #1c5986;\n"
"}\n"
"\n"
"QTableWidget QWidget {\n"
"background:transparent;\n"
""
                        "\n"
"	}\n"
"\n"
"QTableWidget QPushButton {\n"
"    background-color: qlineargradient(spread:pad, \n"
"                            x1:0, y1:0, x2:1, y2:1, \n"
"                            stop:0 rgba(255, 0, 0, 255), \n"
"                            stop:0.41 rgba(195, 22, 58, 255), \n"
"                            stop:1 rgba(255, 117, 0, 255));  \n"
"    border-radius: 10px;\n"
"    color: white;\n"
"    font-size: 12px;\n"
"min-width: 100px;  /* Ensure a minimum width */\n"
"    min-height: 40px;  /* Ensure a minimum height */\n"
"}\n"
"\n"
"QTableWidget QPushButton:hover {\n"
"    background-color: qlineargradient(x1: 0.25, y1: 0, x2: 0.75, y2: 1, \n"
"                            stop: 0 rgba(0, 255, 254, 255),     \n"
"                            stop: 0.26 rgba(38, 170, 196, 255), \n"
"                            stop: 0.67 rgba(89, 85, 131, 255),\n"
"                            stop: 1 rgba(0, 238, 255, 255));  \n"
"}\n"
""));
        matchsTable->setEditTriggers(QAbstractItemView::EditTrigger::NoEditTriggers);
        matchsTable->horizontalHeader()->setStretchLastSection(true);
        nextPageTable = new QPushButton(tab);
        nextPageTable->setObjectName("nextPageTable");
        nextPageTable->setGeometry(QRect(740, 570, 31, 24));
        nextPageTable->setStyleSheet(QString::fromUtf8("QPushButton {background-color:qlineargradient(spread:pad, \n"
"                            x1:0, y1:0, x2:1, y2:1, \n"
"                            stop:0 rgba(255, 0, 0, 255), \n"
"                            stop:0.41 rgba(195, 22, 58, 255), \n"
"                            stop:1 rgba(255, 117, 0, 255));;  ;  \n"
"}\n"
"QPushButton:hover{\n"
"	background-color:qlineargradient(x1: 0.25, y1: 0, x2: 0.75, y2: 1, \n"
"                            stop: 0 rgba(0, 255, 254, 255),     \n"
"                            stop: 0.26 rgba(38, 170, 196, 255), \n"
"                            stop: 0.67 rgba(89, 85, 131, 255),\n"
"                            stop: 1 rgba(0, 238, 255, 255));  \n"
"\n"
"\n"
"\n"
"}\n"
"\n"
"\n"
""));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8("textures/prevIcon.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        nextPageTable->setIcon(icon3);
        prevPageTable = new QPushButton(tab);
        prevPageTable->setObjectName("prevPageTable");
        prevPageTable->setGeometry(QRect(780, 569, 31, 24));
        prevPageTable->setStyleSheet(QString::fromUtf8("QPushButton {background-color:qlineargradient(spread:pad, \n"
"                            x1:0, y1:0, x2:1, y2:1, \n"
"                            stop:0 rgba(255, 0, 0, 255), \n"
"                            stop:0.41 rgba(195, 22, 58, 255), \n"
"                            stop:1 rgba(255, 117, 0, 255));;  ;  \n"
"}\n"
"QPushButton:hover{\n"
"	background-color:qlineargradient(x1: 0.25, y1: 0, x2: 0.75, y2: 1, \n"
"                            stop: 0 rgba(0, 255, 254, 255),     \n"
"                            stop: 0.26 rgba(38, 170, 196, 255), \n"
"                            stop: 0.67 rgba(89, 85, 131, 255),\n"
"                            stop: 1 rgba(0, 238, 255, 255));  \n"
"\n"
"\n"
"\n"
"}\n"
"\n"
"\n"
""));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8("textures/nextIcon.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        prevPageTable->setIcon(icon4);
        refresh = new QPushButton(tab);
        refresh->setObjectName("refresh");
        refresh->setGeometry(QRect(860, 70, 41, 31));
        refresh->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        refresh->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color:qlineargradient(spread:pad, \n"
"                            x1:0, y1:0, x2:1, y2:1, \n"
"                            stop:0 rgba(255, 0, 0, 255), \n"
"                            stop:0.41 rgba(195, 22, 58, 255), \n"
"                            stop:1 rgba(255, 117, 0, 255));;  ;  \n"
"\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: qlineargradient(x1: 0.25, y1: 0, x2: 0.75, y2: 1, \n"
"                            stop: 0 rgba(0, 255, 254, 255),     \n"
"                            stop: 0.26 rgba(38, 170, 196, 255), \n"
"                            stop: 0.67 rgba(89, 85, 131, 255),\n"
"                            stop: 1 rgba(0, 238, 255, 255));  ; \n"
"}"));
        QIcon icon5(QIcon::fromTheme(QIcon::ThemeIcon::ViewRefresh));
        refresh->setIcon(icon5);
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        score = new QLineEdit(tab_2);
        score->setObjectName("score");
        score->setGeometry(QRect(260, 220, 301, 31));
        score->setFont(font1);
        score->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        addMatchButton = new QPushButton(tab_2);
        addMatchButton->setObjectName("addMatchButton");
        addMatchButton->setGeometry(QRect(350, 520, 221, 61));
        addMatchButton->setFont(font2);
        addMatchButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        addMatchButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color:qlineargradient(spread:pad, \n"
"                            x1:0, y1:0, x2:1, y2:1, \n"
"                            stop:0 rgba(255, 0, 0, 255), \n"
"                            stop:0.41 rgba(195, 22, 58, 255), \n"
"                            stop:1 rgba(255, 117, 0, 255));;  ;  \n"
"border-radius:10px;\n"
"color:white;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: qlineargradient(x1: 0.25, y1: 0, x2: 0.75, y2: 1, \n"
"                            stop: 0 rgba(0, 255, 254, 255),     \n"
"                            stop: 0.26 rgba(38, 170, 196, 255), \n"
"                            stop: 0.67 rgba(89, 85, 131, 255),\n"
"                            stop: 1 rgba(0, 238, 255, 255));  ; \n"
"}"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8("textures/addIcon.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        addMatchButton->setIcon(icon6);
        addMatchButton->setIconSize(QSize(50, 50));
        team1 = new QComboBox(tab_2);
        team1->setObjectName("team1");
        team1->setGeometry(QRect(506, 120, 221, 31));
        team1->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    background-color: white;\n"
"    padding: 5px;\n"
"    color: black;\n"
"    font-size: 16px;\n"
"    border: 2px solid transparent; /* Default border */\n"
"}\n"
"\n"
"/* Drop-down arrow area */\n"
"QComboBox::drop-down {\n"
"    border: none;\n"
"    width: 30px;\n"
"   ; /* Keep background for drop-down */\n"
"    border-top-right-radius: 8px;\n"
"    border-bottom-right-radius: 8px;\n"
"    image: url(:/textures/textures/downArrowIcon.png);\n"
"}\n"
"\n"
"/* Hover effect */\n"
"QComboBox:hover {\n"
"    border: 3px dashed qlineargradient(spread:pad, \n"
"                            x1:0, y1:0, x2:1, y2:1, \n"
"                            stop:0 rgba(255, 0, 0, 255), \n"
"                            stop:0.41 rgba(195, 22, 58, 255), \n"
"                            stop:1 rgba(255, 117, 0, 255));\n"
"}\n"
"\n"
"/* Focus effect */\n"
"QComboBox:focus {\n"
"    border: 2px solid qlineargradient(spread:pad, \n"
"                            x1:0, y1:0, x2:1, y2:1, \n"
"                      "
                        "      stop:0 rgba(255, 0, 0, 255), \n"
"                            stop:0.41 rgba(195, 22, 58, 255), \n"
"                            stop:1 rgba(255, 117, 0, 255));\n"
"}\n"
"\n"
"/* Style for the dropdown list */\n"
"QComboBox QAbstractItemView {\n"
"    background-color: white;\n"
"    border: 2px solid #C51D34;\n"
"    selection-background-color: #ff0004;\n"
"    selection-color: white;\n"
"    border-radius: 8px;\n"
"    color: black;\n"
"}\n"
""));
        team2 = new QComboBox(tab_2);
        team2->setObjectName("team2");
        team2->setGeometry(QRect(80, 120, 231, 31));
        team2->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    background-color: white;\n"
"    padding: 5px;\n"
"    color: black;\n"
"    font-size: 16px;\n"
"    border: 2px solid transparent; /* Default border */\n"
"}\n"
"\n"
"/* Drop-down arrow area */\n"
"QComboBox::drop-down {\n"
"    border: none;\n"
"    width: 30px;\n"
"   ; /* Keep background for drop-down */\n"
"    border-top-right-radius: 8px;\n"
"    border-bottom-right-radius: 8px;\n"
"    image: url(:/textures/textures/downArrowIcon.png);\n"
"}\n"
"\n"
"/* Hover effect */\n"
"QComboBox:hover {\n"
"    border: 3px dashed qlineargradient(spread:pad, \n"
"                            x1:0, y1:0, x2:1, y2:1, \n"
"                            stop:0 rgba(255, 0, 0, 255), \n"
"                            stop:0.41 rgba(195, 22, 58, 255), \n"
"                            stop:1 rgba(255, 117, 0, 255));\n"
"}\n"
"\n"
"/* Focus effect */\n"
"QComboBox:focus {\n"
"    border: 2px solid qlineargradient(spread:pad, \n"
"                            x1:0, y1:0, x2:1, y2:1, \n"
"                      "
                        "      stop:0 rgba(255, 0, 0, 255), \n"
"                            stop:0.41 rgba(195, 22, 58, 255), \n"
"                            stop:1 rgba(255, 117, 0, 255));\n"
"}\n"
"\n"
"/* Style for the dropdown list */\n"
"QComboBox QAbstractItemView {\n"
"    background-color: white;\n"
"    border: 2px solid #C51D34;\n"
"    selection-background-color: #ff0004;\n"
"    selection-color: white;\n"
"    border-radius: 8px;\n"
"    color: black;\n"
"}\n"
""));
        datematch = new QDateEdit(tab_2);
        datematch->setObjectName("datematch");
        datematch->setGeometry(QRect(500, 380, 261, 31));
        datematch->setStyleSheet(QString::fromUtf8("QDateEdit {\n"
"    background-color: white;\n"
"    padding: 5px;\n"
"    color: black;\n"
"    font-size: 16px;\n"
"    border: 2px solid transparent; /* Default border */\n"
"}\n"
"\n"
"/* Drop-down arrow area */\n"
"\n"
"/* Hover effect */\n"
"QDateEdit:hover {\n"
"    border: 3px dashed qlineargradient(spread:pad, \n"
"                            x1:0, y1:0, x2:1, y2:1, \n"
"                            stop:0 rgba(255, 0, 0, 255), \n"
"                            stop:0.41 rgba(195, 22, 58, 255), \n"
"                            stop:1 rgba(255, 117, 0, 255));\n"
"}\n"
"\n"
"\n"
""));
        datematch->setDate(QDate(2025, 3, 1));
        stade = new QComboBox(tab_2);
        stade->setObjectName("stade");
        stade->setGeometry(QRect(80, 380, 251, 31));
        stade->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    background-color: white;\n"
"    padding: 5px;\n"
"    color: black;\n"
"    font-size: 16px;\n"
"    border: 2px solid transparent; /* Default border */\n"
"}\n"
"\n"
"/* Drop-down arrow area */\n"
"QComboBox::drop-down {\n"
"    border: none;\n"
"    width: 30px;\n"
"   ; /* Keep background for drop-down */\n"
"    border-top-right-radius: 8px;\n"
"    border-bottom-right-radius: 8px;\n"
"    image: url(:/textures/textures/downArrowIcon.png);\n"
"}\n"
"\n"
"/* Hover effect */\n"
"QComboBox:hover {\n"
"    border: 3px dashed qlineargradient(spread:pad, \n"
"                            x1:0, y1:0, x2:1, y2:1, \n"
"                            stop:0 rgba(255, 0, 0, 255), \n"
"                            stop:0.41 rgba(195, 22, 58, 255), \n"
"                            stop:1 rgba(255, 117, 0, 255));\n"
"}\n"
"\n"
"/* Focus effect */\n"
"QComboBox:focus {\n"
"    border: 2px solid qlineargradient(spread:pad, \n"
"                            x1:0, y1:0, x2:1, y2:1, \n"
"                      "
                        "      stop:0 rgba(255, 0, 0, 255), \n"
"                            stop:0.41 rgba(195, 22, 58, 255), \n"
"                            stop:1 rgba(255, 117, 0, 255));\n"
"}\n"
"\n"
"/* Style for the dropdown list */\n"
"QComboBox QAbstractItemView {\n"
"    background-color: white;\n"
"    border: 2px solid #C51D34;\n"
"    selection-background-color: #ff0004;\n"
"    selection-color: white;\n"
"    border-radius: 8px;\n"
"    color: black;\n"
"}\n"
""));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName("tab_3");
        splitter = new QSplitter(tab_3);
        splitter->setObjectName("splitter");
        splitter->setGeometry(QRect(50, 110, 779, 283));
        splitter->setOrientation(Qt::Orientation::Horizontal);
        tabWidget->addTab(tab_3, QString());
        sidebar = new QWidget(contentArea);
        sidebar->setObjectName("sidebar");
        sidebar->setGeometry(QRect(-30, 0, 151, 311));
        sidebar->setStyleSheet(QString::fromUtf8("background:gray;"));
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
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/textures/textures/exitIcon.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        exitButton->setIcon(icon7);
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
        QIcon icon8;
        icon8.addFile(QString::fromUtf8("textures/aboutIcon.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        aboutButton->setIcon(icon8);
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
        QIcon icon9;
        icon9.addFile(QString::fromUtf8("textures/notifsIcon.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        notifButton->setIcon(icon9);
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
        QIcon icon10;
        icon10.addFile(QString::fromUtf8("textures/homeIcon.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        homeButton->setIcon(icon10);
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
        nextPageTable->setText(QString());
        prevPageTable->setText(QString());
        refresh->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MatchPage", "Match List", nullptr));
        score->setPlaceholderText(QCoreApplication::translate("MatchPage", "Final Score", nullptr));
        addMatchButton->setText(QCoreApplication::translate("MatchPage", "Add Match", nullptr));
        team1->setPlaceholderText(QCoreApplication::translate("MatchPage", "Team 2", nullptr));
        team2->setPlaceholderText(QCoreApplication::translate("MatchPage", "Team 1", nullptr));
        stade->setPlaceholderText(QCoreApplication::translate("MatchPage", "Stadium", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MatchPage", "Add Match", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("MatchPage", "Statistics", nullptr));
        exitButton->setText(QString());
        aboutButton->setText(QString());
        notifButton->setText(QString());
        homeButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MatchPage: public Ui_MatchPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MATCHPAGE_H
