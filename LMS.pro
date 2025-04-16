QT       += core gui widgets uitools multimedia sql
QT += core gui widgets printsupport pdf
QT += charts

greaterThan(QT_MAJOR_VERSION, 4):

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    chatbot.cpp \
    chatbotdialog.cpp \
    connection.cpp \
    custombutton.cpp \
    customtextinput.cpp \
    homepage.cpp \
    main.cpp \
    mainwindow.cpp \
    partner.cpp \
    partnerpage.cpp

HEADERS += \
    chatbot.h \
    chatbotdialog.h \
    connection.h \
    custombutton.h \
    customtextinput.h \
    homepage.h \
    mainwindow.h \
    partner.h \
    partnerpage.h

FORMS += \
    homepage.ui \
    mainwindow.ui \
    partnerpage.ui

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





