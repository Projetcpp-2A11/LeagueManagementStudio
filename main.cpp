#include "connection.h"
#include "mainwindow.h"
#include <connection.h>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
<<<<<<< HEAD
=======
    w.setWindowTitle("League Management Studio");
    w.setGeometry(0, 0, 1920, 1080);
    w.setWindowIcon(QIcon(":/textures/textures/app_icon.png"));
    w.setStyleSheet(
        "QWidget#MainWindow  {"
        "   background-image: url(:/textures/textures/login_background.png);" // Path to your image
        "   background-position: center;"                   // Center the image
        "   background-repeat: no-repeat;"                  // Prevent tiling
        "   background-size: cover;"                        // Scale to cover the widget
        "}"
        );
    w.setFixedSize(1920,1080);
    connection newcnx;
    newcnx.createconnect();
>>>>>>> d87739afc8594a1567a22d28d94f597f500e3067

    connection newConnection;
    bool testBdConnection = newConnection.createconnect();
    if (testBdConnection) {
        qDebug ( "Database connection successful");
        w.show();
        return a.exec();
    } else {
        qDebug ( "Failed to connect to database");

        return 0;
    }



}
