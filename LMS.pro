QT       += core gui widgets uitools multimedia

greaterThan(QT_MAJOR_VERSION, 4):

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    custombutton.cpp \
    customtextinput.cpp \
    employeepage.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    custombutton.h \
    customtextinput.h \
    employeepage.h \
    mainwindow.h

FORMS += \
    employeepage.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc

TARGET = LMS

DISTFILES += \
    faceRecogScript.py

# Include PortAudio and Pocketsphinx paths (adjust to where you've installed them)
INCLUDEPATH += "C:/portaudio/include"  # PortAudio include path
INCLUDEPATH += "C:/pocketsphinx-5.0.4/include"  # Pocketsphinx include path
LIBS += -lpocketsphinx -lsphinxbase



