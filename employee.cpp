#include "employee.h"
#include "connection.h"
#include "qcontainerfwd.h"
#include "qheaderview.h"
#include "qsqlerror.h"
#include <QSignalMapper>

int employee::getUserID() const
{
    return userID;
}

void employee::setUserID(int newUserID)
{
    userID = newUserID;
}

QString employee::getMdp() const
{
    return mdp;
}

void employee::setMdp(const QString &newMdp)
{
    mdp = newMdp;
}

QString employee::getFirstName() const
{
    return firstName;
}

void employee::setFirstName(const QString &newFirstName)
{
    firstName = newFirstName;
}

QString employee::getLastName() const
{
    return lastName;
}

void employee::setLastName(const QString &newLastName)
{
    lastName = newLastName;
}

QString employee::getAddress() const
{
    return address;
}

void employee::setAddress(const QString &newAddress)
{
    address = newAddress;
}

QString employee::getPhoneNumber() const
{
    return phoneNumber;
}

void employee::setPhoneNumber(const QString &newPhoneNumber)
{
    phoneNumber = newPhoneNumber;
}

QString employee::getDepName() const
{
    return depName;
}

void employee::setDepName(const QString &newDepName)
{
    depName = newDepName;
}

QString employee::getPosition() const
{
    return position;
}

void employee::setPosition(const QString &newPosition)
{
    position = newPosition;
}

QString employee::getFaceIdPicUrl() const
{
    return faceIdPicUrl;
}

void employee::setFaceIdPicUrl(const QString &newFaceIdPicUrl)
{
    faceIdPicUrl = newFaceIdPicUrl;
}

QString employee::getVoiceIdUrl() const
{
    return voiceIdUrl;
}

void employee::setVoiceIdUrl(const QString &newVoiceIdUrl)
{
    voiceIdUrl = newVoiceIdUrl;
}



employee::employee() {}

employee::employee( const QString &mdp, const QString &firstName, const QString &lastName, const QString &address, const QString &phoneNumber, const QString &depName, const QString &position, const QString &faceIdPicUrl, const QString &voiceIdUrl) :
    mdp(mdp),
    firstName(firstName),
    lastName(lastName),
    address(address),
    phoneNumber(phoneNumber),
    depName(depName),
    position(position),
    faceIdPicUrl(faceIdPicUrl),
    voiceIdUrl(voiceIdUrl)
{}
// password and user id generation
QString employee::generatePassword(const QString &firstName, const QString &lastName, const QString &phoneNumber) {
    if (lastName.isEmpty() || phoneNumber.length() < 4 || firstName.isEmpty()) {
        return "Default123";  // Fallback password if data is insufficient
    }

    return QString("%1%2%3")
        .arg(lastName.left(1).toUpper())  // First letter of last name
        .arg(phoneNumber.left(4))         // First 4 digits of phone number
        .arg(firstName.left(1));
}

QString employee::generateUserID(const QString &firstName, const QString &lastName, const QString &depName, const QString &position)
{
    QString month = QDate::currentDate().toString("MM");

    // Ensure phone number is at least 2 digits long, then pick two random digits from the phone number
    QString phoneDigits = phoneNumber;
    QString randomFromPhone;
    if (phoneDigits.length() > 1) {
        randomFromPhone = QString("%1%2")
        .arg(phoneDigits[QRandomGenerator::global()->bounded(phoneDigits.length())].digitValue())
            .arg(phoneDigits[QRandomGenerator::global()->bounded(phoneDigits.length())].digitValue());
    }

    // Generate two random digits independently
    int randomNum = QRandomGenerator::global()->bounded(10, 100); // Random 2-digit number between 10 and 99
    QString randomStr = QString::number(randomNum);

    // Return the formatted USERID
    return QString("%1%2%3")
        .arg(month)          // Month (e.g., "03" for March)
        .arg(randomFromPhone) // Two random digits from the phone number
        .arg(randomStr);      // Random 2-digit number
}
// crud methods implementations

bool employee::updateEmployeeDetails(int userID, const QString &firstName, const QString &lastName, const QString &department, const QString &position, const QString &address, const QString &phone)
{
    QSqlQuery query;

    // Prepare the SQL query to update the employee details
    query.prepare("UPDATE Employees SET FIRSTNAME = :firstName, LASTNAME = :lastName, "
                  "DEPNAME = :department, POSITION = :position, ADDRESS = :address, "
                  "PHONENUM = :phone WHERE USERID = :userID");

    // Bind the values to the placeholders in the query
    query.bindValue(":firstName", firstName);
    query.bindValue(":lastName", lastName);
    query.bindValue(":department", department);
    query.bindValue(":position", position);
    query.bindValue(":address", address);
    query.bindValue(":phone", phone);
    query.bindValue(":userID", userID);

    if (query.exec()) {
        qDebug() << "Employee with USERID" << userID << "updated successfully.";
        return true;
    } else {
        qDebug() << "Failed to update employee with USERID" << userID << ":" << query.lastError();
        return false;
    }
}




bool employee::addEmployee()
{
    QString userId = generateUserID(this->firstName, this->lastName, this->depName, this->position);
    QString mdp = generatePassword(this->firstName,this->lastName,this->phoneNumber);


    QSqlQuery query;
    query.prepare("INSERT INTO EMPLOYEES (USERID, MDP, FIRSTNAME, LASTNAME, ADDRESS, PHONENUM, DEPNAME, POSITION) "
                  "VALUES (:userid, :mdp, :firstname, :lastname, :address, :phonenum, :depname, :position)");

    query.bindValue(":userid", userId);
    query.bindValue(":mdp", mdp);
    query.bindValue(":firstname", this->firstName);
    query.bindValue(":lastname", this->lastName);
    query.bindValue(":address", this->address);
    query.bindValue(":phonenum", this->phoneNumber);
    query.bindValue(":depname", this->depName);
    query.bindValue(":position", this->position);

    if (query.exec()) {
        qDebug() << "Employee added successfully! USERID:" << userId;
        return true;
    } else {
        qDebug() << "Error adding employee:" << query.lastError().text();
        qDebug() << "USERID:" << userId;
        qDebug() << "MDP:" << mdp;
        qDebug() << "FIRSTNAME:" << this->firstName;
        qDebug() << "LASTNAME:" << this->lastName;
        qDebug() << "ADDRESS:" << this->address;
        qDebug() << "PHONENUM:" << this->phoneNumber;
        qDebug() << "DEPNAME:" << this->depName;
        qDebug() << "POSITION:" << this->position;

        return false;
    }


}

void employee::listEmployees(QTableWidget* table, QString queryStr)
{
    table->clearContents();
    table->setRowCount(0);
    table->verticalHeader()->setVisible(false);
    QSqlQuery query;

    if (query.exec(queryStr)) {
        int row = 0;
        while (query.next()) {
            table->insertRow(row);
            table->setItem(row, 0, new QTableWidgetItem(query.value(0).toString()));  // USERID
            table->setItem(row, 1, new QTableWidgetItem(query.value(1).toString()));  // FIRSTNAME
            table->setItem(row, 2, new QTableWidgetItem(query.value(2).toString()));  // LASTNAME
            table->setItem(row, 3, new QTableWidgetItem(query.value(3).toString()));  // DEPNAME
            ++row;

        }
    } else {
        qDebug() << "Failed to fetch data: " << query.lastError();
    }
}



bool employee::updateEmployeeUsingUserId(int userID)
{

}

bool employee::deleteEmployeeUsingUserID(int userID)
{
    QSqlQuery query;
    query.prepare("DELETE FROM Employees WHERE USERID = :userID");
    query.bindValue(":userID", userID);

    if (query.exec()) {

            qDebug() << "Employee with USERID" << userID << "deleted successfully.";
            return true;

            qDebug() << "Failed to commit the transaction.";
            return false;

    } else {
        qDebug() << "Failed to delete employee with USERID" << userID << ":" << query.lastError();
        return false;
    }
}


