#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include "qtablewidget.h"
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QRandomGenerator>
#include <QDate>
class employee
{
private:
    int userID;
    QString mdp;
    QString firstName;
    QString lastName;
    QString address;
    QString phoneNumber;
    QString depName;
    QString position;
    QString faceIdPicUrl;
    QString voiceIdUrl;




public:
    employee();
    employee( const QString &mdp, const QString &firstName, const QString &lastName, const QString &address, const QString &phoneNumber, const QString &depName, const QString &position, const QString &faceIdPicUrl, const QString &voiceIdUrl);

    // getters and setters
    int getUserID() const;
    void setUserID(int newUserID);
    QString getMdp() const;
    void setMdp(const QString &newMdp);
    QString getFirstName() const;
    void setFirstName(const QString &newFirstName);
    QString getLastName() const;
    void setLastName(const QString &newLastName);
    QString getAddress() const;
    void setAddress(const QString &newAddress);
    QString getPhoneNumber() const;
    void setPhoneNumber(const QString &newPhoneNumber);
    QString getDepName() const;
    void setDepName(const QString &newDepName);
    QString getPosition() const;
    void setPosition(const QString &newPosition);
    QString getFaceIdPicUrl() const;
    void setFaceIdPicUrl(const QString &newFaceIdPicUrl);
    QString getVoiceIdUrl() const;
    void setVoiceIdUrl(const QString &newVoiceIdUrl);


    //Crud methods:
    bool addEmployee();
    void listEmployees(QTableWidget* table , QString queryStr = "SELECT USERID, FIRSTNAME, LASTNAME, DEPNAME FROM Employees");
    bool updateEmployeeUsingUserId ( int userID);
    bool deleteEmployeeUsingUserID ( int userID);
    QString generatePassword(const QString &firstName, const QString &lastName, const QString &phoneNumber);
    QString generateUserID(const QString &firstName, const QString &lastName, const QString &depName, const QString &position);
    bool updateEmployeeDetails(int userID, const QString &firstName, const QString &lastName,
                               const QString &department, const QString &position, const QString &address,
                               const QString &phone);



};


#endif // EMPLOYEE_H
