#include "stadiumupdateform.h"
#include "ui_stadiumupdateform.h"
#include "QSqlQuery"
#include "QSqlError"


stadiumupdateform::stadiumupdateform(QWidget *parent, int stadiumID)
    : QWidget(parent)
    , ui(new Ui::stadiumupdateform)
{
    ui->setupUi(this);
    ui->stadiumid->setText(QString::number(stadiumID));

    QSqlQuery query;
    query.prepare("SELECT stadiumID, name, address, capacity, status FROM Stadium WHERE stadiumID = :stadiumID");
    query.bindValue(":stadiumID", stadiumID);

    if (query.exec() && query.next()) {
        // Fill fields with current stadium details
        ui->name->setText(query.value("name").toString());
        ui->adress->setText(query.value("address").toString());
        ui->capacity->setText(query.value("capacity").toString());
        ui->status->setText(query.value("status").toString());
    } else {
        qDebug() << "Failed to fetch stadium data for ID" << stadiumID << ":" << query.lastError();
    }
}

stadiumupdateform::~stadiumupdateform()
{
    delete ui;
}

void stadiumupdateform::on_save_clicked()
{
    if (validateInputs()) {
        int stadiumID = ui->stadiumid->text().toInt();
        QString name = ui->name->text();
        QString address = ui->adress->text();
        int capacity = ui->capacity->text().toInt();
        QString status = ui->status->text();
        if (stadiumToBeUpdated.updateStadium(stadiumID, name, address, capacity, status)) {
            qDebug() << "Stadium updated successfully!";
            this->close();
        } else {
            qDebug() << "Error updating stadium!";
        }
    }
}

void stadiumupdateform::on_cancel_clicked()
{
    this->close();
}

bool stadiumupdateform::validateInputs()
{
    // Clear previous error messages
    ui->nameER->clear();
    ui->adressER->clear();
    ui->capacityER->clear();
    ui->statusER->clear();

    bool valid = true; // Assume inputs are valid initially

    // Stadium Name Validation
    QString name = ui->name->text().trimmed();
    if (name.isEmpty()) {
        ui->nameER->setText("The stadium name cannot be empty.");
        valid = false;
    } else if (name.length() < 3) {
        ui->nameER->setText("Must be at least 3 characters.");
        valid = false;
    }

    // Address Validation
    QString address = ui->adress->text().trimmed();
    if (address.isEmpty()) {
        ui->adressER->setText("The stadium address cannot be empty.");
        valid = false;
    } else if (address.length() < 3) {
        ui->adressER->setText("Must be at least 5 characters.");
        valid = false;
    }

    // Capacity Validation
    bool ok;
    int capacity = ui->capacity->text().toInt(&ok);
    if (!ok || capacity <= 0) {
        ui->capacityER->setText("Must be a valid positive number.");
        valid = false;
    }

    // Status Validation (Must be 'available' or 'not available')
    QString status = ui->status->text().trimmed();
    if (status.isEmpty()) {
        ui->statusER->setText("Status cannot be empty.");
        valid = false;
    } else if (status != "available" && status != "not available") {
        ui->statusER->setText("Must be 'available' or 'not available'.");
        valid = false;
    }

    return valid; // Returns true if all validations pass, false otherwise
}
