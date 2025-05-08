QT       += core gui widgets uitools multimedia sql printsupport  charts multimediawidgets serialport

greaterThan(QT_MAJOR_VERSION, 4):

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# INCLUDES pour les headers SDL
INCLUDEPATH += "C:/Users/choua/OneDrive/Bureau/Projet C++/LMS/include" \
               "C:/Users/choua/OneDrive/Bureau/Projet C++/LMS/include/SDL2"

LIBS += -L"C:/Users/choua/OneDrive/Bureau/Projet C++/LMS/lib" \
        -lSDL2 \
        -lSDL2_ttf \
        -lSDL2_mixer

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
    staduimpage.cpp \
    teams.cpp \
    match.cpp \
    uianimationhelper.cpp \
    stadium.cpp \
    player.cpp \
    playerpage.cpp \
    playerperformance.cpp \
    playerupdateform.cpp \
    pronosticdialog.cpp \
    simulation.cpp \
    simulationrun.cpp \
    stadiumupdateform.cpp \
    teamspage1.cpp \
    teamtypeform.cpp \
    partner.cpp \
    partnerpage.cpp \
    chatbot.cpp \
    chatbotdialog.cpp \
    matchesupdateform.cpp \
    dialog.cpp \
    dialogpronostic.cpp \

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
    staduimpage.h \
    teams.h \
    match.h \
    uianimationhelper.h \
    stadium.h \
    player.h \
    playerpage.h \
    playerperformance.h \
    playerupdateform.h \
    pronosticdialog.h \
    simulationrun.h \
    stadiumupdateform.h \
    teamspage1.h \
    teamtypeform.h \
    partner.h \
    partnerpage.h \
    chatbot.h \
    chatbotdialog.h \
    matchesupdateform.h \
    dialog.h \
    dialogpronostic.h \
    simulation.h \

FORMS += \
    arduinocontroller.ui \
    employeepage.ui \
    employeeupdateform.ui \
    homepage.ui \
    mainwindow.ui \
    matchs.ui \
    playerpage.ui \
    playerperformance.ui \
    playerupdateform.ui \
    stadiumupdateform.ui \
    staduimpage.ui \
    teamspage1.ui \
    teamstype.ui  \
    partnerpage.ui \
    matchesupdateform.ui \
    matchpage.ui \
    dialog.ui


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





