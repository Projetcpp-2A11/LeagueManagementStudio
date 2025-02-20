/********************************************************************************
** Form generated from reading UI file 'employeepage.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EMPLOYEEPAGE_H
#define UI_EMPLOYEEPAGE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
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

class Ui_employeePage
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
    QTabWidget *tabWidget;
    QWidget *tab;
    QLineEdit *searchEmployeeInput;
    QPushButton *searchButton;
    QPushButton *filterButton;
    QPushButton *exportListButton;
    QTableWidget *tableWidget;
    QPushButton *nextPageTable;
    QPushButton *prevPageTable;
    QWidget *tab_2;
    QLineEdit *firstName;
    QLineEdit *lastName;
    QLineEdit *adress;
    QLineEdit *numTlf;
    QComboBox *department;
    QLineEdit *poste;
    QPushButton *addEmployeeButton;
    QWidget *tab_3;
    QSplitter *splitter;

    void setupUi(QWidget *employeePage)
    {
        if (employeePage->objectName().isEmpty())
            employeePage->setObjectName("employeePage");
        employeePage->resize(1080, 666);
        horizontalLayout = new QHBoxLayout(employeePage);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        sidebar = new QWidget(employeePage);
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

        contentArea = new QWidget(employeePage);
        contentArea->setObjectName("contentArea");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(contentArea->sizePolicy().hasHeightForWidth());
        contentArea->setSizePolicy(sizePolicy2);
        contentArea->setStyleSheet(QString::fromUtf8("background-color:#858585;\n"
""));
        tabWidget = new QTabWidget(contentArea);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(-20, 0, 871, 681));
        QFont font1;
        font1.setBold(true);
        tabWidget->setFont(font1);
        tabWidget->setStyleSheet(QString::fromUtf8("QTabBar::tab {\n"
"    background: #C51D34;  \n"
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
"    background: #2980b9;\n"
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
        searchEmployeeInput = new QLineEdit(tab);
        searchEmployeeInput->setObjectName("searchEmployeeInput");
        searchEmployeeInput->setGeometry(QRect(120, 70, 181, 31));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Arial")});
        searchEmployeeInput->setFont(font2);
        searchEmployeeInput->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        searchButton = new QPushButton(tab);
        searchButton->setObjectName("searchButton");
        searchButton->setGeometry(QRect(320, 70, 41, 31));
        searchButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        searchButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color:#C51D34;\n"
"\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: blue; \n"
"}"));
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::SystemSearch));
        searchButton->setIcon(icon);
        filterButton = new QPushButton(tab);
        filterButton->setObjectName("filterButton");
        filterButton->setGeometry(QRect(380, 70, 41, 31));
        filterButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        filterButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
"border-radius:10px;\n"
"color:white;\n"
"}\n"
"QPushButton:hover {\n"
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
""));
        tableWidget->horizontalHeader()->setStretchLastSection(true);
        nextPageTable = new QPushButton(tab);
        nextPageTable->setObjectName("nextPageTable");
        nextPageTable->setGeometry(QRect(740, 570, 31, 24));
        nextPageTable->setStyleSheet(QString::fromUtf8("background-color:#C51D34;"));
        QIcon icon3(QIcon::fromTheme(QIcon::ThemeIcon::MediaSeekBackward));
        nextPageTable->setIcon(icon3);
        prevPageTable = new QPushButton(tab);
        prevPageTable->setObjectName("prevPageTable");
        prevPageTable->setGeometry(QRect(780, 569, 31, 24));
        prevPageTable->setStyleSheet(QString::fromUtf8("background-color:#C51D34;\n"
""));
        QIcon icon4(QIcon::fromTheme(QIcon::ThemeIcon::MediaSeekForward));
        prevPageTable->setIcon(icon4);
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        firstName = new QLineEdit(tab_2);
        firstName->setObjectName("firstName");
        firstName->setGeometry(QRect(80, 70, 301, 31));
        firstName->setFont(font2);
        firstName->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        lastName = new QLineEdit(tab_2);
        lastName->setObjectName("lastName");
        lastName->setGeometry(QRect(80, 210, 301, 31));
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
        adress = new QLineEdit(tab_2);
        adress->setObjectName("adress");
        adress->setGeometry(QRect(80, 330, 301, 31));
        adress->setFont(font2);
        adress->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        numTlf->setGeometry(QRect(500, 70, 321, 31));
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
        department->addItem(QString());
        department->addItem(QString());
        department->addItem(QString());
        department->setObjectName("department");
        department->setGeometry(QRect(490, 330, 321, 31));
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
        poste = new QLineEdit(tab_2);
        poste->setObjectName("poste");
        poste->setGeometry(QRect(490, 210, 321, 31));
        poste->setFont(font2);
        poste->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        addEmployeeButton = new QPushButton(tab_2);
        addEmployeeButton->setObjectName("addEmployeeButton");
        addEmployeeButton->setGeometry(QRect(330, 480, 221, 31));
        addEmployeeButton->setFont(font3);
        addEmployeeButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        addEmployeeButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color:#C51D34;\n"
"border-radius:10px;\n"
"color:white;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: blue; \n"
"}"));
        QIcon icon5(QIcon::fromTheme(QIcon::ThemeIcon::ListAdd));
        addEmployeeButton->setIcon(icon5);
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName("tab_3");
        splitter = new QSplitter(tab_3);
        splitter->setObjectName("splitter");
        splitter->setGeometry(QRect(50, 110, 779, 283));
        splitter->setOrientation(Qt::Orientation::Horizontal);
        tabWidget->addTab(tab_3, QString());

        horizontalLayout->addWidget(contentArea);


        retranslateUi(employeePage);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(employeePage);
    } // setupUi

    void retranslateUi(QWidget *employeePage)
    {
        employeePage->setWindowTitle(QCoreApplication::translate("employeePage", "Form", nullptr));
        employeeButton->setText(QCoreApplication::translate("employeePage", "      Employees", nullptr));
        teamsButton->setText(QCoreApplication::translate("employeePage", "Teams", nullptr));
        matchsButton->setText(QCoreApplication::translate("employeePage", "Matchs", nullptr));
        playersButton->setText(QCoreApplication::translate("employeePage", "Players", nullptr));
        stadiumsButton->setText(QCoreApplication::translate("employeePage", "Stadiums", nullptr));
        partnersButton->setText(QCoreApplication::translate("employeePage", "Partners", nullptr));
        empIoyeeIcon->setText(QString());
        teamsIcon->setText(QString());
        matchsIcon->setText(QString());
        playersIcon->setText(QString());
        stadiumIcon->setText(QString());
        partnersIcon->setText(QString());
        searchEmployeeInput->setPlaceholderText(QCoreApplication::translate("employeePage", "search employee", nullptr));
        searchButton->setText(QString());
        filterButton->setText(QString());
        exportListButton->setText(QCoreApplication::translate("employeePage", "Export List", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("employeePage", "Identifiant", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("employeePage", "Nom", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("employeePage", "Prenom", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("employeePage", "Department", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("employeePage", "Actions", nullptr));
        nextPageTable->setText(QString());
        prevPageTable->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("employeePage", "Employee List", nullptr));
        firstName->setText(QString());
        firstName->setPlaceholderText(QCoreApplication::translate("employeePage", "First Name", nullptr));
        lastName->setPlaceholderText(QCoreApplication::translate("employeePage", "Last Name", nullptr));
        adress->setPlaceholderText(QCoreApplication::translate("employeePage", "Address", nullptr));
        numTlf->setPlaceholderText(QCoreApplication::translate("employeePage", "Phone Number", nullptr));
        department->setItemText(0, QCoreApplication::translate("employeePage", "Select Department", nullptr));
        department->setItemText(1, QCoreApplication::translate("employeePage", "Human resources", nullptr));
        department->setItemText(2, QCoreApplication::translate("employeePage", "Federation", nullptr));
        department->setItemText(3, QCoreApplication::translate("employeePage", "Municipality", nullptr));
        department->setItemText(4, QString());

        poste->setPlaceholderText(QCoreApplication::translate("employeePage", "Position", nullptr));
        addEmployeeButton->setText(QCoreApplication::translate("employeePage", "Add Employee", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("employeePage", "Add Employe", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("employeePage", "Statistics", nullptr));
    } // retranslateUi

};

namespace Ui {
    class employeePage: public Ui_employeePage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EMPLOYEEPAGE_H
