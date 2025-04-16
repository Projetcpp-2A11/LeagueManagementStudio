QT       += core gui widgets uitools sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
TARGET = LMS
CONFIG += c++17
QT += printsupport
QT += charts
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    connection.cpp \
    custombutton.cpp \
    customtextinput.cpp \
    main.cpp \
    teams.cpp \
    teamspage1.cpp \
    teamtypeform.cpp

HEADERS += \
    connection.h \
    custombutton.h \
    customtextinput.h \
    teams.h \
    teamspage1.h \
    teamtypeform.h

FORMS += \
    teamspage1.ui \
    teamstype.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
