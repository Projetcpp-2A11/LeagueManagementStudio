#include "connection.h"

// Constructeur : initialise la base de données avec le pilote ODBC
Connection::Connection()
{
    db = QSqlDatabase::addDatabase("QODBC");
}

// Méthode pour établir la connexion à la base de données
bool Connection::createconnection()
{
    bool test = false;

    // Configuration de la connexion
    db.setDatabaseName("Source_Projet2A"); // Nom de la source de données (DSN)
    db.setUserName("SYSTEM");       // Nom d'utilisateur de la base de données
    db.setPassword("azerty");       // Mot de passe de l'utilisateur

    // Tentative d'ouverture de la connexion
    if (db.open())
    {
        test = true; // La connexion est réussie
    }

    return test; // Retourne true si la connexion est établie, sinon false
}

// Méthode pour fermer la connexion à la base de données
void Connection::closeConnection()
{
    db.close(); // Ferme la connexion
}
