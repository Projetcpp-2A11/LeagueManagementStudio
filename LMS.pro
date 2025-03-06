QT       += core gui widgets uitools multimedia sql

greaterThan(QT_MAJOR_VERSION, 4):

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    connection.cpp \
    custombutton.cpp \
    customtextinput.cpp \
    employee.cpp \
    employeepage.cpp \
    employeeupdateform.cpp \
    homepage.cpp \
    main.cpp \
    mainwindow.cpp \
    matchpage.cpp \
    teams.cpp \

HEADERS += \
    connection.h \
    custombutton.h \
    customtextinput.h \
    employee.h \
    employeepage.h \
    employeeupdateform.h \
    homepage.h \
    mainwindow.h \
    matchpage.h \
    teams.h \

FORMS += \
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
    speechRecognition.py
    testSR.py





