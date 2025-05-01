QT       += core gui widgets uitools multimedia sql charts printsupport  serialport

greaterThan(QT_MAJOR_VERSION, 4):

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    arduino.cpp \
    arduinocontroller.cpp \
    connection.cpp \
    custombutton.cpp \
    customtextinput.cpp \
    employee.cpp \
    employeepage.cpp \
    employeeupdateform.cpp \
    homepage.cpp \
    lmstimer.cpp \
    main.cpp \
    mainwindow.cpp \
    match.cpp \
    matchpage.cpp \
    player.cpp \
    playerpage.cpp \
    playerperformance.cpp \
    playerupdateform.cpp \
    teams.cpp \
    uianimationhelper.cpp

HEADERS += \
    arduino.h \
    arduinocontroller.h \
    connection.h \
    custombutton.h \
    customtextinput.h \
    employee.h \
    employeepage.h \
    employeeupdateform.h \
    homepage.h \
    lmstimer.h \
    mainwindow.h \
    match.h \
    matchpage.h \
    player.h \
    playerpage.h \
    playerperformance.h \
    playerupdateform.h \
    teams.h \
    uianimationhelper.h


FORMS += \
    arduinocontroller.ui \
    employeepage.ui \
    employeeupdateform.ui \
    homepage.ui \
    mainwindow.ui \
    matchs.ui \
    playerpage.ui \
    playerperformance.ui \
    playerupdateform.ui


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





