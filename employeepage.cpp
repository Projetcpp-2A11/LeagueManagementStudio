#include "employeepage.h"
#include "employeeupdateform.h"
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
    addButtonsToRows(ui->employeeTableWidget);
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
        refresh();
    } else {
        QMessageBox::critical(this, "Error", "Error Adding employee");
    }
}


void employeePage::on_refreshButton_clicked()
{
    refresh();
}

void employeePage::on_delete_employee_clicked(int row)
{

    qDebug() << "delete clicked" << row;

    int userID = ui->employeeTableWidget->item(row, 0)->text().toInt();
    if (emp.deleteEmployeeUsingUserID(userID)) {
        qDebug() << "Employee with USERID" << userID << "was deleted.";
        refresh();
    } else {
        qDebug() << "Failed to delete employee with USERID" << userID;
    }
}

void employeePage::on_update_employee_clicked(int row)
{
    qDebug() << "update clicked" << row;
    int userID = ui->employeeTableWidget->item(row, 0)->text().toInt();
    employeeUpdateForm *updatePage = new employeeUpdateForm(nullptr,userID);
    updatePage->show();




}


void employeePage::addButtonsToRows(QTableWidget* table)
{
    // Iterate through each row in the table
    for (int row = 0; row < table->rowCount(); ++row) {
        // Create delete and update buttons
        QPushButton* deleteButton = new QPushButton("Delete");
        QPushButton* updateButton = new QPushButton("Update");

        // Create a widget to hold the buttons
        QWidget* actionWidget = new QWidget();
        QHBoxLayout* actionLayout = new QHBoxLayout(actionWidget);
        actionLayout->setContentsMargins(0, 0, 0, 0);  // Remove margins
        actionLayout->setSpacing(20);  // Add spacing between the buttons

        // Add buttons to the layout
        actionLayout->addWidget(deleteButton);
        actionLayout->addWidget(updateButton);

        // Set the size policy for the action widget to allow expansion
        actionWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);

        // Set the action widget as the cell widget in the table
        table->setCellWidget(row, 4, actionWidget);

        // Connect buttons to their respective slots
        connect(deleteButton, &QPushButton::clicked, this, [this, row]() {
            on_delete_employee_clicked(row);  // Pass the row index to the delete method
        });

        connect(updateButton, &QPushButton::clicked, this, [this, row]() {
            on_update_employee_clicked(row);  // Pass the row index to the update method
        });

        // Adjust the column and row size to ensure enough space for the buttons
        table->setColumnWidth(4, 200);  // Adjust column width for the actions column
        table->setRowHeight(row, 60);   // Set row height for the actions row
    }
}

void employeePage::refresh()
{
    ui->employeeTableWidget->clearContents();
    ui->employeeTableWidget->setRowCount(0);  // Reset row count

    // Repopulate the table with updated employee data
    emp.listEmployees(ui->employeeTableWidget);
    addButtonsToRows(ui->employeeTableWidget);
}

void employeePage::on_employeeTableWidget_cellActivated(int row, int column)
{

}

