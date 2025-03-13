#include "connection.h"

connection::connection()
{

}

bool connection::createconnect()
{
    bool test=false;
<<<<<<< HEAD
    db = QSqlDatabase::addDatabase("QODBC");
=======
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
>>>>>>> d87739afc8594a1567a22d28d94f597f500e3067
    db.setDatabaseName("Source_Projet2A");
    db.setUserName("SYSTEM");
    db.setPassword("azerty");

    if (db.open())
        test=true;





    return  test;
}

<<<<<<< HEAD
QSqlDatabase connection::getDatabase()
{
    return db;
}

=======
>>>>>>> d87739afc8594a1567a22d28d94f597f500e3067
