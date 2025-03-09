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

    if (empUpdateValidateInputs()) {
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

}


void employeeUpdateForm::on_cancel_clicked()
{
    this->close();
}

bool employeeUpdateForm::empUpdateValidateInputs()
{

        QString errorMessage;

        // First Name Validation
        if (ui->firstName->text().isEmpty() || ui->firstName->text().length() < 3 || ui->firstName->text().contains(QRegularExpression("[0-9]"))) {
            errorMessage += "- First Name: Must be at least 3 characters and contain only letters.\n";
        }

        // Last Name Validation
        if (ui->lastName->text().isEmpty() || ui->lastName->text().length() < 4 || ui->lastName->text().contains(QRegularExpression("[0-9]"))) {
            errorMessage += "- Last Name: Must be at least 4 characters and contain only letters.\n";
        }

        // Address Validation
        if (ui->address->text().isEmpty() || ui->address->text().length() < 6) {
            errorMessage += "- Address: Must be at least 6 characters long.\n";
        }

        // Phone Number Validation (Only digits, +, - allowed)
        if (ui->phoneNum->text().isEmpty() || !ui->phoneNum->text().contains(QRegularExpression("^[0-9+\\-]+$"))) {
            errorMessage += "- Phone Number: Only digits, '+', and '-' are allowed.\n";
        }

        // Position Validation (At least 4 characters)
        if (ui->position->text().isEmpty() || ui->position->text().length() < 4) {
            errorMessage += "- Position: Must be at least 4 characters long.\n";
        }

        // Department Validation (Must be selected)
        if (ui->department->currentText() == "Select Department" || ui->department->currentText().isEmpty()) {
            errorMessage += "- Department: Must be selected.\n";
        }

        // If there are any errors, show the message box
        if (!errorMessage.isEmpty()) {
            QMessageBox::warning(this, "Input Error", errorMessage);
            return false;
        }

        return true;






}

