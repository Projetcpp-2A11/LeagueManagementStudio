#ifndef STADIUM_H
#define STADIUM_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QTableWidget>

class Stadium
{
private:
    int id;
    QString name;
    QString address;
    int capacity;
    QString status;  // New status field

public:
    // Constructors
    Stadium();
    Stadium(const QString &name, const QString &address, int capacity, const QString &status);

    // Getters and Setters
    int getStadiumID() const;
    void setStadiumID(int newId);

    QString getName() const;
    void setName(const QString &newName);

    QString getAddress() const;
    void setAddress(const QString &newAddress);

    int getCapacity() const;
    void setCapacity(int newCapacity);

    QString getStatus() const;
    void setStatus(const QString &newStatus);

    // CRUD Methods
    bool addStadium();
    bool updateStadium ( int id);
    bool deleteStadium ( int id);
    void listStadiums(QTableWidget* table);
};

#endif // STADIUM_H
