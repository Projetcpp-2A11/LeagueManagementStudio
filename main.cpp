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
        w.show();
        return a.exec();
    } else {
        qDebug ( "Failed to connect to database");

        return 0;
    }



}
