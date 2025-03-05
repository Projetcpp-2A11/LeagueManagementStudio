#include "employeepage.h"
#include "ui_employeepage.h"
#include <QMessageBox>
#include <QVBoxLayout>
#include <employee.h>
#include <connection.h>

employeePage::employeePage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::employeePage)
{
    setWindowTitle("Employee Page");
    ui->setupUi(this);
    setupEmployeeTable();
    setMinimumSize(1000, 800);
    resize(800, 600);

    // Apply a layout to ensure resizing works properly
    QVBoxLayout *layout = new QVBoxLayout(this);
    setLayout(layout);

}




employeePage::~employeePage()
{
    delete ui;
}

void employeePage::setupEmployeeTable() {
    // Assuming you have a QTableWidget named `employeeTableWidget` in your employeepage UI
    // Populate the table with employee data
    ui->employeeTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

    employee emp;
    emp.listEmployees(ui->employeeTableWidget);
}


void employeePage::on_exitButton_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Exit Confirmation",
                                  "Are you sure you want to logout and exit?",
                                  QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        QApplication::quit();
    }

}


void employeePage::on_homeButton_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Dashboard Confirmation",
                                  "Are you sure you want to return to the dashboard? All unsaved work will be lost.",
                                  QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        homepage *HomePage = new homepage();
        HomePage->show();

        this->close();
    }
}


void employeePage::on_notifButton_clicked()
{

}


void employeePage::on_aboutButton_clicked()
{
    QMessageBox::information(this, "About This Page", "This is the Employee Page,here you can manage the employees and perform basic CRUD operations.\n\nVersion 1.0\n\nDeveloped by TechSpire.",
                             QMessageBox::Ok);
}

void employeePage::on_addEmployeeButton_clicked()
{


    // Get input values from UI
    QString firstName = ui->firstName->text().trimmed();
    QString lastName = ui->lastName->text().trimmed();
    QString address = ui->adress->text();
    QString phoneNum = ui->numTlf->text();
    QString depName = ui->department->currentText();
    QString position = ui->poste->text();

    // Validate input fields
    if (firstName.isEmpty() || lastName.isEmpty() ||
        address.isEmpty() || phoneNum.isEmpty() || depName.isEmpty() || position.isEmpty()) {
        QMessageBox::warning(this, "Error", "Please fill all fields");
        return;
    }

    // Create Employee object using constructor
    employee newEmployee( "", firstName, lastName, address, phoneNum, depName, position, "", "");

    // Generate USERID inside addEmployee() since it's dynamic
    if (newEmployee.addEmployee()) {
        QMessageBox::information(this, "Success", "Employee added successfully");
        // Clear fields after successful insertion
        ui->firstName->clear();
        ui->lastName->clear();
        ui->adress->clear();
        ui->numTlf->clear();
        ui->department->setCurrentIndex(0);
        ui->poste->clear();
    } else {
        QMessageBox::critical(this, "Error", "Error Adding employee");
    }
}

