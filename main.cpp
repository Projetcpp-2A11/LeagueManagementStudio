#include "teamspage1.h"
#include <QApplication>
#include <QMessageBox>
#include "connection.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    teamsPage w;
    Connection c;
    if(c.createconnect())
    {
        w.setWindowTitle("League Management Studio");
        w.setGeometry(0, 0, 1920, 1080);
        w.show();
        return a.exec();
    } else {
        qDebug ( "Failed to connect to database");

        return 0;
    }
}
