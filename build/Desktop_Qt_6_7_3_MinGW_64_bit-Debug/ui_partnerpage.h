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
    QLineEdit *searchEmployeeInput;
    QPushButton *searchButton;
    QPushButton *filterButton;
    QPushButton *exportListButton;
    QTableWidget *partnersTable;
    QPushButton *nextPageTable;
    QPushButton *prevPageTable;
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
    QWidget *tab_3;
    QSplitter *splitter;
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
        searchEmployeeInput = new QLineEdit(tab);
        searchEmployeeInput->setObjectName("searchEmployeeInput");
        searchEmployeeInput->setGeometry(QRect(20, 70, 181, 31));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Arial")});
        searchEmployeeInput->setFont(font1);
        searchEmployeeInput->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        searchButton->setGeometry(QRect(210, 70, 41, 31));
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
        filterButton->setGeometry(QRect(260, 70, 41, 31));
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
        exportListButton->setGeometry(QRect(20, 570, 191, 41));
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
        icon2.addFile(QString::fromUtf8("textures/exportIcon.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        exportListButton->setIcon(icon2);
        exportListButton->setIconSize(QSize(40, 50));
        partnersTable = new QTableWidget(tab);
        if (partnersTable->columnCount() < 6)
            partnersTable->setColumnCount(6);
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
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        partnersTable->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        partnersTable->setObjectName("partnersTable");
        partnersTable->setGeometry(QRect(20, 110, 901, 451));
        partnersTable->setStyleSheet(QString::fromUtf8("QTableWidget {\n"
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
        partnersTable->setEditTriggers(QAbstractItemView::EditTrigger::NoEditTriggers);
        partnersTable->horizontalHeader()->setStretchLastSection(true);
        nextPageTable = new QPushButton(tab);
        nextPageTable->setObjectName("nextPageTable");
        nextPageTable->setGeometry(QRect(840, 570, 31, 24));
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
        prevPageTable->setGeometry(QRect(880, 570, 31, 24));
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
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        name = new QLineEdit(tab_2);
        name->setObjectName("name");
        name->setGeometry(QRect(260, 70, 301, 31));
        name->setFont(font1);
        name->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        addPartnerButton = new QPushButton(tab_2);
        addPartnerButton->setObjectName("addPartnerButton");
        addPartnerButton->setGeometry(QRect(140, 520, 221, 61));
        addPartnerButton->setFont(font2);
        addPartnerButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        addPartnerButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        QIcon icon5;
        icon5.addFile(QString::fromUtf8("textures/addIcon.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        addPartnerButton->setIcon(icon5);
        addPartnerButton->setIconSize(QSize(50, 50));
        stadiumList = new QComboBox(tab_2);
        stadiumList->setObjectName("stadiumList");
        stadiumList->setGeometry(QRect(480, 380, 201, 31));
        label = new QLabel(tab_2);
        label->setObjectName("label");
        label->setGeometry(QRect(350, 10, 131, 41));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Arial")});
        font3.setPointSize(28);
        label->setFont(font3);
        label->setStyleSheet(QString::fromUtf8("background:transparent;"));
        label_2 = new QLabel(tab_2);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(240, 120, 381, 41));
        label_2->setFont(font3);
        label_2->setStyleSheet(QString::fromUtf8("background:transparent;"));
        startDate = new QDateEdit(tab_2);
        startDate->setObjectName("startDate");
        startDate->setGeometry(QRect(110, 270, 161, 31));
        label_3 = new QLabel(tab_2);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(110, 230, 111, 41));
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
        label_4->setGeometry(QRect(480, 230, 111, 41));
        label_4->setFont(font4);
        label_4->setStyleSheet(QString::fromUtf8("background:transparent;"));
        teamList = new QComboBox(tab_2);
        teamList->setObjectName("teamList");
        teamList->setGeometry(QRect(110, 380, 201, 31));
        addPartnerandSponsor = new QPushButton(tab_2);
        addPartnerandSponsor->setObjectName("addPartnerandSponsor");
        addPartnerandSponsor->setGeometry(QRect(450, 520, 391, 61));
        addPartnerandSponsor->setFont(font2);
        addPartnerandSponsor->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        addPartnerandSponsor->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        addPartnerandSponsor->setIcon(icon5);
        addPartnerandSponsor->setIconSize(QSize(50, 50));
        partnerList = new QComboBox(tab_2);
        partnerList->setObjectName("partnerList");
        partnerList->setGeometry(QRect(290, 180, 201, 31));
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
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/textures/textures/exitIcon.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        exitButton->setIcon(icon6);
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
        QIcon icon7;
        icon7.addFile(QString::fromUtf8("textures/aboutIcon.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        aboutButton->setIcon(icon7);
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
        QIcon icon8;
        icon8.addFile(QString::fromUtf8("textures/notifsIcon.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        notifButton->setIcon(icon8);
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
        QIcon icon9;
        icon9.addFile(QString::fromUtf8("textures/homeIcon.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        homeButton->setIcon(icon9);
        homeButton->setIconSize(QSize(50, 50));

        horizontalLayout->addWidget(contentArea);


        retranslateUi(partnerpage);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(partnerpage);
    } // setupUi

    void retranslateUi(QWidget *partnerpage)
    {
        partnerpage->setWindowTitle(QCoreApplication::translate("partnerpage", "Form", nullptr));
        searchEmployeeInput->setPlaceholderText(QCoreApplication::translate("partnerpage", "Search partner", nullptr));
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
        QTableWidgetItem *___qtablewidgetitem5 = partnersTable->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("partnerpage", "Actions", nullptr));
        nextPageTable->setText(QString());
        prevPageTable->setText(QString());
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
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("partnerpage", "Add partner", nullptr));
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
