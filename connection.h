#ifndef CONNECTION_H
#define CONNECTION_H

#include <QSqlDatabase>

class Connection
{
public:
    // Constructeur
    Connection();

    // Méthode pour établir la connexion à la base de données
    bool createconnection();

    // Méthode pour fermer la connexion à la base de données
    void closeConnection();

private:
    // Attribut pour stocker la connexion à la base de données
    QSqlDatabase db;
};

#endif // CONNECTION_H
