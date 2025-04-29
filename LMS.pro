QT       += core gui widgets uitools multimedia sql printsupport  charts multimediawidgets serialport

greaterThan(QT_MAJOR_VERSION, 4):

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    arduino.cpp \
    arduinocontroller.cpp \
    connection.cpp \
    employee.cpp \
    employeepage.cpp \
    employeeupdateform.cpp \
    homepage.cpp \
    lmspenalty.cpp \
    lmstimer.cpp \
    lmsvar.cpp \
    main.cpp \
    mainwindow.cpp \
    matchpage.cpp \
    teams.cpp \
    match.cpp \
    uianimationhelper.cpp \
    stadium.cpp

HEADERS += \
    arduino.h \
    arduinocontroller.h \
    connection.h \
    employee.h \
    employeepage.h \
    employeeupdateform.h \
    homepage.h \
    lmspenalty.h \
    lmstimer.h \
    lmsvar.h \
    mainwindow.h \
    matchpage.h \
    teams.h \
    match.h \
    uianimationhelper.h \
    stadium.h

FORMS += \
    arduinocontroller.ui \
    employeepage.ui \
    employeeupdateform.ui \
    homepage.ui \
    mainwindow.ui \
    matchs.ui \


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc

TARGET = LMS

DISTFILES += \
    faceRecogScript.py \
    saveEncodings.py \
    speechRecognition.py
    testSR.py





