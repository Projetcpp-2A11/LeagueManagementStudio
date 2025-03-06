#include "connection.h"

connection::connection()
{

}

bool connection::createconnect()
{
    bool test=false;
    db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Source_Projet2A");
    db.setUserName("SYSTEM");
    db.setPassword("azerty");

    if (db.open())
        test=true;





    return  test;
}

QSqlDatabase connection::getDatabase()
{
    return db;
}

