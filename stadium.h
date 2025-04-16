#ifndef STADIUM_H
#define STADIUM_H

#include "qlabel.h"
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QTableWidget>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QString>
#include <QDate>
#include <QJsonDocument>
#include <QJsonObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QTableWidget>

class Stadium
{
private:
    int id;
    QString name;
    QString address;
    int capacity;
    QString status;
    QNetworkAccessManager *networkManager;
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
    bool updateStadium(int stadiumID, const QString &newName, const QString &newAddress, int newCapacity, const QString &newStatus);
    bool deleteStadium ( int id);
    void listStadiums(QTableWidget* table);
    bool searchStadiums(const QString &searchText, QTableWidget *tableWidget);
    bool filterStadiums(int index, QTableWidget *tableWidget);
    void exportListToPDF(QTableWidget *tableWidget, const QString &fileName);
    void showStadiumStatusChart(QTableWidget *tableWidget);
    void showTopStadiumsByCapacity(QTableWidget *tableWidget);
    bool isStadiumAvailable(int stadiumID);
    void checkStadiumPracticality(int stadiumID, const QDate &matchDate, QWidget *parent);
    void generatePdfReport(const QString &stadiumName, const QString &address, const QString &status,
                           const QString &date, const QString &weather, const QString &decision, QWidget *parent);
    void checkMatchAndShowSeats(const QString &matchIDRaw, QWidget *topWidget, QWidget *bottomWidget,
                               QWidget *leftWidget, QWidget *rightWidget, QLineEdit *attendanceLabel, QLineEdit *matchider);
    int calculatePeoplePerSquare(int capacity);


private slots:
    QString getWeatherForDate(const QDate &date, const QString &location);
    void generateSeatGrid(int rows, int cols, int peoplePerSquare, int totalPeople, int occupiedPeople, QWidget *seatGridWidget);

};

#endif // STADIUM_H
