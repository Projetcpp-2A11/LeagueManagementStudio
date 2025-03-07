#include "stadium.h"
#include "staduimpage.h"
#include "qboxlayout.h"
#include "qcontainerfwd.h"
#include "qheaderview.h"
#include "qpushbutton.h"
#include "qsqlerror.h"
#include <QMessageBox>

int Stadium::getStadiumID() const
{
    return id;
}

void Stadium::setStadiumID(int newStadiumID)
{
    id = newStadiumID;
}

QString Stadium::getName() const
{
    return name;
}

void Stadium::setName(const QString &newName)
{
    name = newName;
}

QString Stadium::getAddress() const
{
    return address;
}

void Stadium::setAddress(const QString &newAddress)
{
    address = newAddress;
}

int Stadium::getCapacity() const
{
    return capacity;
}

void Stadium::setCapacity(int newCapacity)
{
    capacity = newCapacity;
}

QString Stadium::getStatus() const {
    return status;
}

void Stadium::setStatus(const QString &newStatus) {
    status = newStatus;
}


Stadium::Stadium() {}

Stadium::Stadium(const QString &name, const QString &address, int capacity, const QString &status):
    name(name),
    address(address),
    capacity(capacity),
    status(status)
{}

bool Stadium::addStadium()
{
    QSqlQuery query;
    query.prepare("INSERT INTO Stadium (name, address, capacity, status) "
                  "VALUES (:name, :address, :capacity, :status)");

    query.bindValue(":name", name);
    query.bindValue(":address", address);
    query.bindValue(":capacity", capacity);
    query.bindValue(":status", status);

    if (query.exec()) {
        qDebug() << "Stadium added successfully!";
        return true;
    } else {
        qDebug() << "Error adding stadium:" << query.lastError().text();
        return false;
    }
}

void Stadium::listStadiums(QTableWidget* table)
{
    table->clearContents();
    table->setRowCount(0);
    table->verticalHeader()->setVisible(false);

    QString queryStr = "SELECT  STADIUMID, NAME, ADDRESS, CAPACITY ,STATUS FROM STADIUM";
    QSqlQuery query;

    if (query.exec(queryStr)) {
        int row = 0;
        while (query.next()) {
            table->insertRow(row);
            table->setItem(row, 0, new QTableWidgetItem(query.value(0).toString()));
            table->setItem(row, 1, new QTableWidgetItem(query.value(1).toString()));
            table->setItem(row, 2, new QTableWidgetItem(query.value(2).toString()));
            table->setItem(row, 3, new QTableWidgetItem(query.value(3).toString()));
            table->setItem(row, 4, new QTableWidgetItem(query.value(4).toString()));
            table->setColumnWidth(5, 200);
            table->setRowHeight(row, 60);



            ++row;
        }
    } else {
        qDebug() << "Failed to fetch data: " << query.lastError();
    }
}

bool Stadium::updateStadium(int stadiumID)
{
    QSqlQuery query;
    query.prepare("UPDATE Stadium SET name = :name, address = :address, capacity = :capacity, status = :status WHERE id = :id");

    query.bindValue(":name", name);
    query.bindValue(":address", address);
    query.bindValue(":capacity", capacity);
    query.bindValue(":status", status);
    query.bindValue(":id", stadiumID);

    if (query.exec()) {
        qDebug() << "Stadium with ID" << stadiumID << "updated successfully!";
        return true;
    } else {
        qDebug() << "Error updating stadium:" << query.lastError().text();
        return false;
    }
}

bool Stadium::deleteStadium(int id)
{
    QSqlQuery query;
    query.prepare("DELETE FROM Stadium WHERE STADIUMID = :id");
    query.bindValue(":id", id);

    if (query.exec()) {
        qDebug() << "Stadium with ID" << id << "deleted successfully!";
        return true;
    } else {
        qDebug() << "Error deleting stadium:" << query.lastError().text();
        return false;
    }
}

