/********************************************************************************
** Form generated from reading UI file 'matchpage.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MATCHPAGE_H
#define UI_MATCHPAGE_H

<<<<<<< HEAD
#include <QtCore/QDate>
=======
>>>>>>> d87739afc8594a1567a22d28d94f597f500e3067
#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
<<<<<<< HEAD
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
=======
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
>>>>>>> d87739afc8594a1567a22d28d94f597f500e3067
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

<<<<<<< HEAD
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
=======
class Ui_matchPage
{
public:
    QHBoxLayout *horizontalLayout;
    QWidget *sidebar;
    QPushButton *employeeButton;
    QPushButton *teamsButton;
    QPushButton *matchsButton;
    QPushButton *playersButton;
    QPushButton *stadiumsButton;
    QPushButton *partnersButton;
    QLabel *empIoyeeIcon;
    QLabel *teamsIcon;
    QLabel *matchsIcon;
    QLabel *playersIcon;
    QLabel *stadiumIcon;
    QLabel *partnersIcon;
    QWidget *contentArea;
    QTabWidget *updatematch;
    QWidget *tab;
    QLineEdit *searchmatchsInput;
    QPushButton *searchButton;
    QPushButton *filterButton;
    QPushButton *exportListButton;
    QTableWidget *tableWidget;
    QPushButton *nextPageTable;
    QPushButton *prevPageTable;
    QWidget *tab_2;
    QLineEdit *teams1;
    QLineEdit *lastName;
    QLineEdit *numTlf;
    QComboBox *department;
    QPushButton *addmatchButton;
    QPushButton *updatematchButton_2;
    QWidget *tab_3;
    QSplitter *splitter;

    void setupUi(QWidget *matchPage)
    {
        if (matchPage->objectName().isEmpty())
            matchPage->setObjectName("matchPage");
        matchPage->resize(1080, 666);
        horizontalLayout = new QHBoxLayout(matchPage);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        sidebar = new QWidget(matchPage);
        sidebar->setObjectName("sidebar");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(sidebar->sizePolicy().hasHeightForWidth());
        sidebar->setSizePolicy(sizePolicy);
        sidebar->setMinimumSize(QSize(200, 0));
        sidebar->setStyleSheet(QString::fromUtf8("background-color:#434343;"));
        employeeButton = new QPushButton(sidebar);
        employeeButton->setObjectName("employeeButton");
        employeeButton->setGeometry(QRect(-10, 10, 181, 61));
        QFont font;
        font.setFamilies({QString::fromUtf8("Arial")});
        font.setPointSize(16);
        employeeButton->setFont(font);
        employeeButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        employeeButton->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        employeeButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: red;             /* Red background */\n"
"    border-radius: 15px;               /* Rounded corners */\n"
"    color: white;                      /* White text */\n"
"    border: none;                      /* No border */\n"
"    padding: 10px 20px;                /* Padding inside the button */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: blue;           /* Blue background when hovered */\n"
"}\n"
"\n"
"QPushButton[selected=\"true\"] {\n"
"    background-color: blue;            /* Blue background when selected */\n"
"}"));
        teamsButton = new QPushButton(sidebar);
        teamsButton->setObjectName("teamsButton");
        teamsButton->setGeometry(QRect(-10, 100, 181, 61));
        teamsButton->setFont(font);
        teamsButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        teamsButton->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        teamsButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: red;             /* Red background */\n"
"    border-radius: 15px;               /* Rounded corners */\n"
"    color: white;                      /* White text */\n"
"    border: none;                      /* No border */\n"
"    padding: 10px 20px;                /* Padding inside the button */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: blue;           /* Blue background when hovered */\n"
"}\n"
"QPushButton:pressed, QPushButton:checked {\n"
"    background-color: blue;           /* Blue background when pressed or selected */\n"
"}"));
        matchsButton = new QPushButton(sidebar);
        matchsButton->setObjectName("matchsButton");
        matchsButton->setGeometry(QRect(-10, 210, 181, 61));
        matchsButton->setFont(font);
        matchsButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        matchsButton->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        matchsButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: red;             /* Red background */\n"
"    border-radius: 15px;               /* Rounded corners */\n"
"    color: white;                      /* White text */\n"
"    border: none;                      /* No border */\n"
"    padding: 10px 20px;                /* Padding inside the button */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: blue;           /* Blue background when hovered */\n"
"}\n"
"QPushButton:pressed, QPushButton:checked {\n"
"    background-color: blue;           /* Blue background when pressed or selected */\n"
"}"));
        matchsButton->setCheckable(true);
        matchsButton->setChecked(true);
        playersButton = new QPushButton(sidebar);
        playersButton->setObjectName("playersButton");
        playersButton->setGeometry(QRect(-10, 330, 181, 61));
        playersButton->setFont(font);
        playersButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        playersButton->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        playersButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: red;             /* Red background */\n"
"    border-radius: 15px;               /* Rounded corners */\n"
"    color: white;                      /* White text */\n"
"    border: none;                      /* No border */\n"
"    padding: 10px 20px;                /* Padding inside the button */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: blue;           /* Blue background when hovered */\n"
"}\n"
"QPushButton:pressed, QPushButton:checked {\n"
"    background-color: blue;           /* Blue background when pressed or selected */\n"
"}"));
        stadiumsButton = new QPushButton(sidebar);
        stadiumsButton->setObjectName("stadiumsButton");
        stadiumsButton->setGeometry(QRect(-10, 460, 181, 61));
        stadiumsButton->setFont(font);
        stadiumsButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        stadiumsButton->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        stadiumsButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: red;             /* Red background */\n"
"    border-radius: 15px;               /* Rounded corners */\n"
"    color: white;                      /* White text */\n"
"    border: none;                      /* No border */\n"
"    padding: 10px 20px;                /* Padding inside the button */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: blue;           /* Blue background when hovered */\n"
"}\n"
"QPushButton:pressed, QPushButton:checked {\n"
"    background-color: blue;           /* Blue background when pressed or selected */\n"
"}"));
        partnersButton = new QPushButton(sidebar);
        partnersButton->setObjectName("partnersButton");
        partnersButton->setGeometry(QRect(-10, 570, 181, 61));
        partnersButton->setFont(font);
        partnersButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        partnersButton->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        partnersButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: red;             /* Red background */\n"
"    border-radius: 15px;               /* Rounded corners */\n"
"    color: white;                      /* White text */\n"
"    border: none;                      /* No border */\n"
"    padding: 10px 20px;                /* Padding inside the button */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: blue;           /* Blue background when hovered */\n"
"}\n"
"QPushButton:pressed, QPushButton:checked {\n"
"    background-color: blue;           /* Blue background when pressed or selected */\n"
"}"));
        empIoyeeIcon = new QLabel(sidebar);
        empIoyeeIcon->setObjectName("empIoyeeIcon");
        empIoyeeIcon->setGeometry(QRect(0, 20, 51, 41));
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(empIoyeeIcon->sizePolicy().hasHeightForWidth());
        empIoyeeIcon->setSizePolicy(sizePolicy1);
        empIoyeeIcon->setStyleSheet(QString::fromUtf8("background-color:none"));
        empIoyeeIcon->setPixmap(QPixmap(QString::fromUtf8(":/textures/textures/employeeIcon.png")));
        empIoyeeIcon->setScaledContents(true);
        teamsIcon = new QLabel(sidebar);
        teamsIcon->setObjectName("teamsIcon");
        teamsIcon->setGeometry(QRect(0, 100, 51, 61));
        teamsIcon->setStyleSheet(QString::fromUtf8("background-color:none"));
        teamsIcon->setPixmap(QPixmap(QString::fromUtf8(":/textures/textures/teamsIcon.png")));
        teamsIcon->setScaledContents(true);
        matchsIcon = new QLabel(sidebar);
        matchsIcon->setObjectName("matchsIcon");
        matchsIcon->setGeometry(QRect(0, 220, 51, 51));
        matchsIcon->setStyleSheet(QString::fromUtf8("background-color:none"));
        matchsIcon->setPixmap(QPixmap(QString::fromUtf8(":/textures/textures/matchsIcon.png")));
        matchsIcon->setScaledContents(true);
        playersIcon = new QLabel(sidebar);
        playersIcon->setObjectName("playersIcon");
        playersIcon->setGeometry(QRect(-20, 320, 91, 71));
        playersIcon->setStyleSheet(QString::fromUtf8("background-color:none"));
        playersIcon->setPixmap(QPixmap(QString::fromUtf8(":/textures/textures/playersIcon.png")));
        playersIcon->setScaledContents(true);
        stadiumIcon = new QLabel(sidebar);
        stadiumIcon->setObjectName("stadiumIcon");
        stadiumIcon->setGeometry(QRect(4, 473, 31, 31));
        stadiumIcon->setStyleSheet(QString::fromUtf8("background-color:none"));
        stadiumIcon->setPixmap(QPixmap(QString::fromUtf8(":/textures/textures/stadiumIcon.png")));
        stadiumIcon->setScaledContents(true);
        partnersIcon = new QLabel(sidebar);
        partnersIcon->setObjectName("partnersIcon");
        partnersIcon->setGeometry(QRect(-1, 585, 41, 31));
        partnersIcon->setStyleSheet(QString::fromUtf8("background-color:none"));
        partnersIcon->setPixmap(QPixmap(QString::fromUtf8(":/textures/textures/partnersIcon.png")));
        partnersIcon->setScaledContents(true);

        horizontalLayout->addWidget(sidebar);

        contentArea = new QWidget(matchPage);
        contentArea->setObjectName("contentArea");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(contentArea->sizePolicy().hasHeightForWidth());
        contentArea->setSizePolicy(sizePolicy2);
        contentArea->setStyleSheet(QString::fromUtf8("background-color:#858585;\n"
""));
        updatematch = new QTabWidget(contentArea);
        updatematch->setObjectName("updatematch");
        updatematch->setGeometry(QRect(-20, 0, 871, 681));
        QFont font1;
        font1.setBold(true);
        updatematch->setFont(font1);
        updatematch->setStyleSheet(QString::fromUtf8("QTabBar::tab {\n"
"    background: #C51D34;  \n"
>>>>>>> d87739afc8594a1567a22d28d94f597f500e3067
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
<<<<<<< HEAD
"    background:qlineargradient(spread:pad, \n"
"                            x1:0, y1:0, x2:1, y2:1, \n"
"                            stop:0 rgba(0, 213, 246, 255), \n"
"                            stop:0.18 rgba(100, 100, 138, 255), \n"
"                            stop:1 rgba(0, 212, 255, 255));;\n"
=======
"    background: #2980b9;\n"
>>>>>>> d87739afc8594a1567a22d28d94f597f500e3067
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
<<<<<<< HEAD
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
=======
        searchmatchsInput = new QLineEdit(tab);
        searchmatchsInput->setObjectName("searchmatchsInput");
        searchmatchsInput->setGeometry(QRect(120, 70, 181, 31));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Arial")});
        searchmatchsInput->setFont(font2);
        searchmatchsInput->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: white;\n"
"    border: 2px solid #C51D34;\n"
>>>>>>> d87739afc8594a1567a22d28d94f597f500e3067
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
<<<<<<< HEAD
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
=======
"background-color:#C51D34;\n"
"\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: blue; \n"
"}"));
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::SystemSearch));
>>>>>>> d87739afc8594a1567a22d28d94f597f500e3067
        searchButton->setIcon(icon);
        filterButton = new QPushButton(tab);
        filterButton->setObjectName("filterButton");
        filterButton->setGeometry(QRect(380, 70, 41, 31));
        filterButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        filterButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
<<<<<<< HEAD
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
=======
"background-color:#C51D34;\n"
"\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: blue; \n"
"}"));
        QIcon icon1(QIcon::fromTheme(QIcon::ThemeIcon::AddressBookNew));
        filterButton->setIcon(icon1);
        exportListButton = new QPushButton(tab);
        exportListButton->setObjectName("exportListButton");
        exportListButton->setGeometry(QRect(120, 580, 221, 31));
        QFont font3;
        font3.setPointSize(18);
        exportListButton->setFont(font3);
        exportListButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        exportListButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color:#C51D34;\n"
>>>>>>> d87739afc8594a1567a22d28d94f597f500e3067
"border-radius:10px;\n"
"color:white;\n"
"}\n"
"QPushButton:hover {\n"
<<<<<<< HEAD
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
=======
"    background-color: blue; \n"
"}"));
        QIcon icon2(QIcon::fromTheme(QIcon::ThemeIcon::DocumentOpen));
        exportListButton->setIcon(icon2);
        tableWidget = new QTableWidget(tab);
        if (tableWidget->columnCount() < 5)
            tableWidget->setColumnCount(5);
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
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(120, 110, 701, 451));
        tableWidget->setStyleSheet(QString::fromUtf8("QTableWidget {\n"
>>>>>>> d87739afc8594a1567a22d28d94f597f500e3067
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
<<<<<<< HEAD
"	color:black;\n"
=======
>>>>>>> d87739afc8594a1567a22d28d94f597f500e3067
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
<<<<<<< HEAD
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
=======
""));
        tableWidget->horizontalHeader()->setStretchLastSection(true);
        nextPageTable = new QPushButton(tab);
        nextPageTable->setObjectName("nextPageTable");
        nextPageTable->setGeometry(QRect(740, 570, 31, 24));
        nextPageTable->setStyleSheet(QString::fromUtf8("background-color:#C51D34;"));
        QIcon icon3(QIcon::fromTheme(QIcon::ThemeIcon::MediaSeekBackward));
>>>>>>> d87739afc8594a1567a22d28d94f597f500e3067
        nextPageTable->setIcon(icon3);
        prevPageTable = new QPushButton(tab);
        prevPageTable->setObjectName("prevPageTable");
        prevPageTable->setGeometry(QRect(780, 569, 31, 24));
<<<<<<< HEAD
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
=======
        prevPageTable->setStyleSheet(QString::fromUtf8("background-color:#C51D34;\n"
""));
        QIcon icon4(QIcon::fromTheme(QIcon::ThemeIcon::MediaSeekForward));
        prevPageTable->setIcon(icon4);
        updatematch->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        teams1 = new QLineEdit(tab_2);
        teams1->setObjectName("teams1");
        teams1->setGeometry(QRect(80, 70, 301, 31));
        teams1->setFont(font2);
        teams1->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: white;\n"
"    border: 2px solid #C51D34;\n"
"    border-radius: 8px;\n"
>>>>>>> d87739afc8594a1567a22d28d94f597f500e3067
"    padding: 5px;\n"
"    color: black;\n"
"    font-size: 16px;\n"
"}\n"
"\n"
"/* Hover effect */\n"
"QLineEdit:hover {\n"
<<<<<<< HEAD
"	border:3px dashed qlineargradient(spread:pad, \n"
"                            x1:0, y1:0, x2:1, y2:1, \n"
"                            stop:0 rgba(255, 0, 0, 255), \n"
"                            stop:0.41 rgba(195, 22, 58, 255), \n"
"                            stop:1 rgba(255, 117, 0, 255));;  ;  ;\n"
=======
"    border-color: #ff3347;\n"
>>>>>>> d87739afc8594a1567a22d28d94f597f500e3067
"}\n"
"\n"
"/* Focus effect */\n"
"QLineEdit:focus {\n"
<<<<<<< HEAD
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
=======
"    border-color: #ff0004;\n"
"    box-shadow: none; /* Qt stylesheets do not support box-shadow */\n"
"}\n"
""));
        lastName = new QLineEdit(tab_2);
        lastName->setObjectName("lastName");
        lastName->setGeometry(QRect(80, 340, 301, 31));
        lastName->setFont(font2);
        lastName->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: white;\n"
"    border: 2px solid #C51D34;\n"
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
        numTlf = new QLineEdit(tab_2);
        numTlf->setObjectName("numTlf");
        numTlf->setGeometry(QRect(80, 200, 321, 31));
        numTlf->setFont(font2);
        numTlf->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: white;\n"
"    border: 2px solid #C51D34;\n"
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
        department = new QComboBox(tab_2);
        department->addItem(QString());
        department->addItem(QString());
        department->setObjectName("department");
        department->setGeometry(QRect(500, 70, 321, 31));
        department->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    background-color: white;\n"
"    border: 2px solid #C51D34;\n"
"    border-radius: 8px;\n"
"    padding: 5px;\n"
"    color: black;\n"
"    font-size: 16px;\n"
"    selection-background-color: #C51D34;\n"
"}\n"
"\n"
"/* Drop-down arrow area */\n"
"QComboBox::drop-down {\n"
"    border: none;\n"
"    width: 30px;\n"
"    background-color: #C51D34;\n"
"    border-top-right-radius: 8px;\n"
"    border-bottom-right-radius: 8px;\n"
"}\n"
"\n"
"/* When the combo box is hovered */\n"
"QComboBox:hover {\n"
"    border-color: #ff3347;\n"
"}\n"
"\n"
"/* When the combo box is focused */\n"
"QComboBox:focus {\n"
"    border-color: #ff0004;\n"
"}\n"
"\n"
"/* Style for the dropdown list */\n"
"QComboBox QAbstractItemView {\n"
"    background-color: white;\n"
"    border: 2px solid #C51D34;\n"
"    selection-background-color: #ff0004;\n"
"    selection-color: white;\n"
"    border-radius: 8px;\n"
"	color:black;\n"
"}\n"
"\n"
""));
        addmatchButton = new QPushButton(tab_2);
        addmatchButton->setObjectName("addmatchButton");
        addmatchButton->setGeometry(QRect(250, 480, 221, 31));
        addmatchButton->setFont(font3);
        addmatchButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        addmatchButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color:#C51D34;\n"
>>>>>>> d87739afc8594a1567a22d28d94f597f500e3067
"border-radius:10px;\n"
"color:white;\n"
"}\n"
"QPushButton:hover {\n"
<<<<<<< HEAD
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
=======
"    background-color: blue; \n"
"}"));
        QIcon icon5(QIcon::fromTheme(QIcon::ThemeIcon::ListAdd));
        addmatchButton->setIcon(icon5);
        updatematchButton_2 = new QPushButton(tab_2);
        updatematchButton_2->setObjectName("updatematchButton_2");
        updatematchButton_2->setGeometry(QRect(510, 480, 221, 31));
        updatematchButton_2->setFont(font3);
        updatematchButton_2->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        updatematchButton_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color:#C51D34;\n"
"border-radius:10px;\n"
"color:white;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: blue; \n"
"}"));
        updatematchButton_2->setIcon(icon5);
        updatematch->addTab(tab_2, QString());
>>>>>>> d87739afc8594a1567a22d28d94f597f500e3067
        tab_3 = new QWidget();
        tab_3->setObjectName("tab_3");
        splitter = new QSplitter(tab_3);
        splitter->setObjectName("splitter");
        splitter->setGeometry(QRect(50, 110, 779, 283));
        splitter->setOrientation(Qt::Orientation::Horizontal);
<<<<<<< HEAD
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
=======
        updatematch->addTab(tab_3, QString());
>>>>>>> d87739afc8594a1567a22d28d94f597f500e3067

        horizontalLayout->addWidget(contentArea);


<<<<<<< HEAD
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
=======
        retranslateUi(matchPage);

        updatematch->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(matchPage);
    } // setupUi

    void retranslateUi(QWidget *matchPage)
    {
        matchPage->setWindowTitle(QCoreApplication::translate("matchPage", "Form", nullptr));
        employeeButton->setText(QCoreApplication::translate("matchPage", "      Employees", nullptr));
        teamsButton->setText(QCoreApplication::translate("matchPage", "Teams", nullptr));
        matchsButton->setText(QCoreApplication::translate("matchPage", "Matchs", nullptr));
        playersButton->setText(QCoreApplication::translate("matchPage", "Players", nullptr));
        stadiumsButton->setText(QCoreApplication::translate("matchPage", "Stadiums", nullptr));
        partnersButton->setText(QCoreApplication::translate("matchPage", "Partners", nullptr));
        empIoyeeIcon->setText(QString());
        teamsIcon->setText(QString());
        matchsIcon->setText(QString());
        playersIcon->setText(QString());
        stadiumIcon->setText(QString());
        partnersIcon->setText(QString());
#if QT_CONFIG(tooltip)
        updatematch->setToolTip(QCoreApplication::translate("matchPage", "<html><head/><body><p>updatematch</p><p><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        searchmatchsInput->setText(QString());
        searchmatchsInput->setPlaceholderText(QCoreApplication::translate("matchPage", "search matchs", nullptr));
        searchButton->setText(QString());
        filterButton->setText(QString());
        exportListButton->setText(QCoreApplication::translate("matchPage", "Export List", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("matchPage", " team1", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("matchPage", "team2", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("matchPage", "date match", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("matchPage", "stade", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("matchPage", "Actions", nullptr));
        nextPageTable->setText(QString());
        prevPageTable->setText(QString());
        updatematch->setTabText(updatematch->indexOf(tab), QCoreApplication::translate("matchPage", "matchs List", nullptr));
        teams1->setText(QString());
        teams1->setPlaceholderText(QCoreApplication::translate("matchPage", "team1", nullptr));
        lastName->setText(QString());
        lastName->setPlaceholderText(QCoreApplication::translate("matchPage", "date match", nullptr));
        numTlf->setText(QString());
        numTlf->setPlaceholderText(QCoreApplication::translate("matchPage", "team2", nullptr));
        department->setItemText(0, QCoreApplication::translate("matchPage", "Select stade", nullptr));
        department->setItemText(1, QString());

        addmatchButton->setText(QCoreApplication::translate("matchPage", "Add matchs", nullptr));
        updatematchButton_2->setText(QCoreApplication::translate("matchPage", "update matchs", nullptr));
        updatematch->setTabText(updatematch->indexOf(tab_2), QCoreApplication::translate("matchPage", "Add matchs", nullptr));
        updatematch->setTabText(updatematch->indexOf(tab_3), QCoreApplication::translate("matchPage", "Statistics", nullptr));
>>>>>>> d87739afc8594a1567a22d28d94f597f500e3067
    } // retranslateUi

};

namespace Ui {
<<<<<<< HEAD
    class MatchPage: public Ui_MatchPage {};
=======
    class matchPage: public Ui_matchPage {};
>>>>>>> d87739afc8594a1567a22d28d94f597f500e3067
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MATCHPAGE_H
