QT       += core gui widgets uitools multimedia sql serialport
CONFIG += console
TARGET = my_project
QT += printsupport
QT -= core gui charts
QT += charts
QT += network


greaterThan(QT_MAJOR_VERSION, 4):

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Staduimpage.cpp \
    arduino.cpp \
    arduinocontroller.cpp \
    connection.cpp \
    custombutton.cpp \
    customtextinput.cpp \
    homepage.cpp \
    lmspenalty.cpp \
    lmstimer.cpp \
    lmsvar.cpp \
    main.cpp \
    mainwindow.cpp \
    match.cpp \
    player.cpp \
    playerpage.cpp \
    playerperformance.cpp \
    playerupdateform.cpp \
    stadium.cpp \
    stadiumupdateform.cpp \
    teams.cpp \
    uianimationhelper.cpp

HEADERS += \
    Staduimpage.h \
    arduino.h \
    arduinocontroller.h \
    connection.h \
    custombutton.h \
    customtextinput.h \
    homepage.h \
    lmspenalty.h \
    lmstimer.h \
    lmsvar.h \
    mainwindow.h \
    match.h \
    player.h \
    playerpage.h \
    playerperformance.h \
    playerupdateform.h \
    playerupdateform.h \
    stadium.h \
    stadiumupdateform.h \
    teams.h \
    uianimationhelper.h

FORMS += \
    Staduimpage.ui \
    arduinocontroller.ui \
    homepage.ui \
    mainwindow.ui \
    playerpage.ui \
    playerperformance.ui \
    playerupdateform.ui \
    stadiumupdateform.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc

TARGET = LMS

DISTFILES += \
    faceRecogScript.py \
    speechRecognition.py
    testSR.py


find_package(Qt6 REQUIRED COMPONENTS Charts)
target_link_libraries(LeagueManagementStudio PRIVATE Qt6::Charts)


