#include "mainwindow.h"
#include <connection.h>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    connection newConnection;
    bool testBdConnection = newConnection.createconnect();
    if (testBdConnection) {
        qDebug ( "Database connection successful");
        w.setWindowTitle("League Management Studio");
        w.setGeometry(0, 0, 1920, 1080);
        w.setWindowIcon(QIcon(":/textures/textures/app_icon.png"));
        w.setStyleSheet(
            "QWidget#MainWindow  {"
            "   background-image: url(:/textures/textures/login_background.png);"
            "   background-position: center;"
            "   background-repeat: no-repeat;"
            "   background-size: cover;"
            "}"
            );
        w.setFixedSize(1920,1080);
        w.show();
        return a.exec();
    } else {
        qDebug ( "Failed to connect to database");

        return 0;
    }



}
