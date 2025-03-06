#include "employeeupdateform.h"
#include "employee.h"
#include "ui_employeeupdateform.h"
#include "QSqlQuery"
#include "QSqlError"

employeeUpdateForm::employeeUpdateForm(QWidget *parent , int userID)
    : QWidget(parent)
    , ui(new Ui::employeeUpdateForm)
{
    ui->setupUi(this);


    ui->userIDLabel->setText(QString::number(userID));
    QSqlQuery query;
    query.prepare("SELECT USERID, FIRSTNAME, LASTNAME, DEPNAME, ADDRESS, PHONENUM, POSITION FROM Employees WHERE USERID = :userID");
    query.bindValue(":userID", userID);

    if (query.exec() && query.next()) {
        // Set the data from the query to the input fields
        ui->firstName->setText(query.value("FIRSTNAME").toString());
        ui->lastName->setText(query.value("LASTNAME").toString());
        ui->address->setText(query.value("ADDRESS").toString());
        ui->phoneNum->setText(query.value("PHONENUM").toString());
        ui->position->setText(query.value("POSITION").toString());
        QString department = query.value("DEPNAME").toString();

        // Find the index of the department in the combo box and set it
        int departmentIndex = ui->department->findText(department);
        if (departmentIndex != -1) {
            ui->department->setCurrentIndex(departmentIndex); // Set the selected department
        }

    } else {
        qDebug() << "Failed to fetch employee data for USERID" << userID << ":" << query.lastError();
    }
}

employeeUpdateForm::~employeeUpdateForm()
{
    delete ui;
}


void employeeUpdateForm::on_save_exit_clicked()
{

    QString firstName = ui->firstName->text();
    QString lastName = ui->lastName->text();
    QString department = ui->department->currentText();
    QString position = ui->position->text();
    QString address = ui->address->text();
    int userId = ui->userIDLabel->text().toInt();
    QString phone = ui->phoneNum->text();
    employeeToBeUpdated.updateEmployeeDetails(userId,firstName, lastName, department, position, address, phone);
    this->close();

}


void employeeUpdateForm::on_cancel_clicked()
{
    this->close();
}

