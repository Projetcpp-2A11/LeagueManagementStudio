#ifndef CONNECTION_H
#define CONNECTION_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

class connection
{
public:
    connection();
    bool createconnect();
    QSqlDatabase getDatabase();  // Get the database object

private:
    QSqlDatabase db;  // Store the database connection

};

#endif // CONNECTION_H
