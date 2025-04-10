#include "mainwindow.h"
#include <connection.h>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
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
    Connection newConnection;
    if ( !newConnection.createconnection()) {
        qDebug() << "DB not open . exiting";
        return 0 ;
    }

    w.show();
    return a.exec();
}
