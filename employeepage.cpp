#include "employeepage.h"
#include "employeeupdateform.h"
#include "qevent.h"
#include "ui_employeepage.h"
#include <QMessageBox>
#include <QVBoxLayout>
#include <employee.h>
#include <connection.h>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QChart>
#include <QtCharts/QLegend>
#include <QtCharts/QPieSlice>



employeePage::employeePage(QWidget *parent , employee * loggedInEmployee)
    : QWidget(parent)
    , ui(new Ui::employeePage),
    loggedIneEmp(loggedInEmployee)
{
    setWindowTitle("Employee Page");
    ui->setupUi(this);
    setupEmployeeTable(defaultQueryStr);
    setupFilterGroupBox();
    setupStatistics();
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

void employeePage::setupEmployeeTable(QString queryStr) {

    ui->employeeTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    employee emp;
    emp.listEmployees(ui->employeeTableWidget,queryStr);
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
        homepage *HomePage = new homepage(nullptr,loggedIneEmp);
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
    if ( empInsertionValidateInputs()) {
        QString firstName = ui->firstName->text().trimmed();
        QString lastName = ui->lastName->text().trimmed();
        QString address = ui->adress->text();
        QString phoneNum = ui->numTlf->text();
        QString depName = ui->department->currentText();
        QString position = ui->poste->text();
        employee newEmployee( "", firstName, lastName, address, phoneNum, depName, position, "", "");
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

    } else {
        QMessageBox::warning(this, "Error", "Please correct the invalid inputs");
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

bool employeePage::empInsertionValidateInputs()
{
    bool allValid = true;

    // Regular expression to allow only letters and spaces
    QRegularExpression nameRegex("^[A-Za-z ]+$");

    // First Name Validation
    if (ui->firstName->text().isEmpty() || ui->firstName->text().length() < 3 ||
        !ui->firstName->text().contains(nameRegex)) {
        ui->fNameErrorMSG->setText("Invalid: At least 3 letters, no numbers allowed");
        allValid = false;
    } else {
        ui->fNameErrorMSG->clear();
    }

    // Last Name Validation
    if (ui->lastName->text().isEmpty() || ui->lastName->text().length() < 4 ||
        !ui->lastName->text().contains(nameRegex)) {
        ui->lNameErrorMSG->setText("Invalid: At least 4 letters, no numbers allowed");
        allValid = false;
    } else {
        ui->lNameErrorMSG->clear();
    }

    // Address Validation
    if (ui->adress->text().isEmpty() || ui->adress->text().length() < 6) {
        ui->adressErrorMSG->setText("Invalid: At least 6 characters");
        allValid = false;
    } else {
        ui->adressErrorMSG->clear();
    }

    // Phone Number Validation (Only digits, +, and - allowed)
    if (ui->numTlf->text().isEmpty() ||
        !ui->numTlf->text().contains(QRegularExpression("^[0-9+\\-]+$"))) {
        ui->phoneNumErrorMSG->setText("Invalid: Only digits, '+', and '-' are allowed");
        allValid = false;
    } else {
        ui->phoneNumErrorMSG->clear();
    }

    // Position Validation (No numbers allowed)
    if (ui->poste->text().isEmpty() || ui->poste->text().length() < 4 ||
        !ui->poste->text().contains(nameRegex)) {
        ui->positionErrorMSG->setText("Invalid: At least 4 letters, no numbers allowed");
        allValid = false;
    } else {
        ui->positionErrorMSG->clear();
    }

    // Department Combo Box Validation
    if (ui->department->currentText() == "Select Department") {
        ui->depErrorMSG->setText("Invalid Selection");
        allValid = false;
    } else {
        ui->depErrorMSG->clear();
    }

    return allValid;
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
        actionLayout->setSpacing(10);  // Add spacing between the buttons

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
    emp.listEmployees(ui->employeeTableWidget,defaultQueryStr);
    addButtonsToRows(ui->employeeTableWidget);
    setupStatistics();
}
void employeePage::setupFilterGroupBox() {

    ui->filterGroupBox->setVisible(false);



}

QMap<QString, int> employeePage::getDepartmentCounts() {
    QMap<QString, int> deptCounts;
    QSqlQuery query;

    QStringList departments = {"HR", "League", "Commerce", "Municipality", "Federation"};

    for (const QString &dept : departments) {
        query.prepare("SELECT COUNT(*) FROM EMPLOYEES WHERE DEPNAME = :dep");
        query.bindValue(":dep", dept);
        if (query.exec() && query.next()) {
            int count = query.value(0).toInt();
            deptCounts[dept] = count;
        } else {
            qDebug() << "Error fetching count for department" << dept << ":" << query.lastError().text();
            deptCounts[dept] = 0;
        }
    }

    return deptCounts;
}


void employeePage::showDepartmentStatsChart() {
    QMap<QString, int> deptCounts = getDepartmentCounts();

    QPieSeries *series = new QPieSeries();
    for (auto it = deptCounts.begin(); it != deptCounts.end(); ++it) {
        series->append(it.key(), it.value());
    }

    // Optional: show labels and customize
    for (auto slice : series->slices()) {
        slice->setLabelVisible(true);
    }

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Employees by Department");
    chart->legend()->setAlignment(Qt::AlignBottom);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    // Add chart to layout
    QLayout *layout = ui->chartContainer->layout();
    if (!layout) {
        layout = new QVBoxLayout(ui->chartContainer);
        ui->chartContainer->setLayout(layout);
    }

    layout->addWidget(chartView);
}


void employeePage::on_filterButton_clicked()
{
    ui->filterGroupBox->setVisible(true);
    ui->depFilterBox->setVisible(false);


}


void employeePage::on_cancelFilter_clicked()
{
    ui->filterGroupBox->setVisible(false);
}


void employeePage::on_searchCriteriaBox_currentIndexChanged(int index)
{
    if ( ui->searchCriteriaBox->currentIndex() == 3  ) {
        ui->depFilterBox->setVisible(true);
    } else {
        ui->depFilterBox->setVisible(false);

    }
}


QSqlQuery employeePage::on_applyFilter_clicked()
{
    int searchCriteraIndex = ui->searchCriteriaBox->currentIndex();
    QString selectedDepartment = ui->depFilterBox->currentText();
    QString searchBoxInput  = ui->searchEmployeeInput->text();
    QSqlQuery query;
    QString sortType = "ASC";


    switch(searchCriteraIndex) {
    case 0: // search by first name
        currentQueryStr = "SELECT USERID,FIRSTNAME,LASTNAME,DEPNAME FROM EMPLOYEES WHERE FIRSTNAME=:firstname";
        query.prepare(currentQueryStr);
        query.bindValue(":firstname",searchBoxInput);
        qDebug() << &query;

        break;
    case 1 : // search by last name

        currentQueryStr = "SELECT USERID,FIRSTNAME,LASTNAME,DEPNAME FROM EMPLOYEES WHERE LASTNAME=:LASTNAME";
        query.prepare(currentQueryStr);

        query.bindValue(":lastname",searchBoxInput);


        break;

    case 2 : // search by position
        currentQueryStr = "SELECT USERID,FIRSTNAME,LASTNAME,DEPNAME FROM EMPLOYEES WHERE position=:position";
        query.prepare(currentQueryStr);
        query.bindValue(":position", searchBoxInput);



        break;

    case 3 : // search by department

        currentQueryStr = "SELECT USERID,FIRSTNAME,LASTNAME,DEPNAME FROM EMPLOYEES WHERE DEPNAME=:selectedDepartment";
        query.prepare(currentQueryStr);

        query.bindValue(":selectedDepartment",selectedDepartment);




        break;

    case 4 : // adress
        currentQueryStr = "SELECT USERID,FIRSTNAME,LASTNAME,DEPNAME FROM EMPLOYEES WHERE ADDRESS LIKE :adress";
        query.prepare(currentQueryStr);

        query.bindValue(":address", "%" + searchBoxInput + "%"); // Correct LIKE syntax



        break;

    case 5 : //Default
        currentQueryStr = defaultQueryStr;
        query.prepare(currentQueryStr);


        break;

    }

    switch(ui->sortCriteriaBox_2->currentIndex()) {
    case 0:

        currentQueryStr +=" ASC";
        break;
    case 1 :
        currentQueryStr +=" DESC";
        break;




    }
    qDebug() << currentQueryStr;

    ui->filterGroupBox->setVisible(false);

    return query;


}






void employeePage::on_searchButton_clicked()
{

    QSqlQuery searchQuery = on_applyFilter_clicked();
    emp.listEmployeesByCriteria(ui->employeeTableWidget, searchQuery);
    addButtonsToRows(ui->employeeTableWidget);


}

bool employeePage::exportTableToCSV(QTableWidget *table)
{
    QString filePath = QFileDialog::getSaveFileName(nullptr, "Save File", "", "CSV Files (*.csv)");
    if (filePath.isEmpty())
        return false;

    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "Failed to open file for writing";
        return false;
    }

    QTextStream stream(&file);

    for (int col = 0; col < table->columnCount(); ++col) {
        QTableWidgetItem *headerItem = table->horizontalHeaderItem(col);
        if (headerItem)
            stream << headerItem->text();
        else
            stream << "Column " << col + 1;

        if (col < table->columnCount() - 1)
            stream << ",";
    }
    stream << "\n";

    for (int row = 0; row < table->rowCount(); ++row) {
        for (int col = 0; col < table->columnCount(); ++col) {
            QTableWidgetItem *cellItem = table->item(row, col);
            if (cellItem)
                stream << cellItem->text();
            else
                stream << "";

            if (col < table->columnCount() - 1)
                stream << ",";
        }
        stream << "\n";
    }

    file.close();
    return true;
    qDebug() << "CSV file saved at" << filePath;

}

void employeePage::setupStatistics() {
    // Create a map to store department counts
    QMap<QString, int> departmentCounts;

    // List of all departments
    QStringList departments = {"HR", "League", "Commerce", "Municipality", "Federation"};

    QSqlQuery query;

    // Loop over departments and get their employee count
    for (const QString &dep : departments) {
        query.prepare("SELECT COUNT(*) FROM employees WHERE DEPNAME = :dep");
        query.bindValue(":dep", dep);
        if (query.exec() && query.next()) {
            departmentCounts[dep] = query.value(0).toInt();
        }
    }

    int totalEmployees = 0;
    for (auto it = departmentCounts.begin(); it != departmentCounts.end(); ++it) {
        totalEmployees += it.value();
    }

    // Now create the pie chart
    QPieSeries *series = new QPieSeries();

    // Define an array of colors for the slices
    QList<QColor> sliceColors = {
        QColor(255, 99, 71),  // Tomato (HR)
        QColor(100, 149, 237), // Cornflower Blue (League)
        QColor(34, 139, 34),  // Forest Green (Commerce)
        QColor(255, 165, 0),  // Orange (Municipality)
        QColor(75, 0, 130)    // Indigo (Federation)
    };

    int colorIndex = 0;

    // Add data to the series and set custom colors
    for (auto it = departmentCounts.begin(); it != departmentCounts.end(); ++it) {
        QPieSlice *slice = series->append(it.key(), it.value());

        // Set the color of each slice
        slice->setBrush(sliceColors[colorIndex]);

        // Move to the next color in the list
        colorIndex++;
    }

    // Create the chart and add the series
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Employees by Department");
    chart->legend()->setAlignment(Qt::AlignRight);

    // Create the chart view
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    // Set the parent of chartView to be chartContainer
    chartView->setParent(ui->chartContainer);  // Assuming chartContainer is a QWidget in your UI

    // Manually set the geometry of the chart view inside the chartContainer
    chartView->setGeometry(0, 0, 400, 300);  // Position (0, 0) and Size (400x300)



    ui->totalCountLabel->setText( QString::number(totalEmployees));

    // Set the department counts labels
    ui->hrCountLabel->setText(QString::number(departmentCounts["HR"]));
    ui->leagueCountLabel->setText( QString::number(departmentCounts["League"]));
    ui->commerceCountLabel->setText( QString::number(departmentCounts["Commerce"]));
    ui->municipalityCountLabel->setText(  QString::number(departmentCounts["Municipality"]));
    ui->federationCountLabel->setText( QString::number(departmentCounts["Federation"]));
}







void employeePage::on_exportListButton_clicked()
{

    if (exportTableToCSV(ui->employeeTableWidget)) {
        QMessageBox::information(this, "Success", "Export Successful", QMessageBox::Ok);


    }

}

