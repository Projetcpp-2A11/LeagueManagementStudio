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
<<<<<<< HEAD
    QSqlDatabase getDatabase();  // Get the database object

private:
    QSqlDatabase db;  // Store the database connection

=======
>>>>>>> d87739afc8594a1567a22d28d94f597f500e3067
};

#endif // CONNECTION_H
