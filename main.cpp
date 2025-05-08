#include "mainwindow.h"
#include <connection.h>
#include <QApplication>
#include <simulationrun.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    if (argc > 2 && QString(argv[1]) == "--simulate") {
        bool ok;
        int matchID = QString(argv[2]).toInt(&ok);
        if (ok) {
            return SimulationRun::run(matchID);
        } else {
            qDebug() << "Invalid matchID for simulation";
            return 1;
        }
    }


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
