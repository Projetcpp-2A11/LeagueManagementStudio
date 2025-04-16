#include "Staduimpage.h"
#include "ui_Staduimpage.h"
#include <QMessageBox>
#include <QVBoxLayout>
#include "stadium.h"
#include "homepage.h"
#include "stadiumupdateform.h"
#include <qsqlerror.h>
#include <QFileDialog>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>

stadiumPage::stadiumPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Staduimpage)
{
    setWindowTitle("Stadium Page");
    ui->setupUi(this);
    QPixmap field(":/textures/textures/football_field.png");

    // Get full size of the widget
    QSize fullSize = ui->football_field->size();

    // Scale it fully by width, then height will adjust to maintain aspect ratio
    QPixmap scaled = field.scaled(fullSize.width(), fullSize.height(), Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation);

    QLabel *imageLabel = new QLabel(ui->football_field);
    imageLabel->setPixmap(scaled);
    imageLabel->setAlignment(Qt::AlignCenter);
    imageLabel->setGeometry(0, 0, ui->football_field->width(), ui->football_field->height());
    imageLabel->show();


    setMinimumSize(1000, 800);
    resize(800, 600);


    // Apply a layout to ensure resizing works properly
    QVBoxLayout *layout = new QVBoxLayout(this);
    setLayout(layout);


    //connect(ui->checkSeatsButton, &QPushButton::clicked, this, &::stadiumPage::on_checkSeatsButton_clicked);

   Stadium s;
    refreshStadiumList(); // Refresh the stadium list



}




stadiumPage::~stadiumPage()
{
    delete ui;
}




void stadiumPage::refreshStadiumList() {
    stadium.listStadiums(ui->tableWidget);
    addButtonsToRows(ui->tableWidget);
}




void stadiumPage::on_AddStadium_clicked()
{
    // Clear previous error messages
    ui->NameER->clear();
    ui->AdressER->clear();
    ui->capacityER->clear();
    ui->statusER->clear();

    bool valid = true; // Assume inputs are valid initially

    // Stadium Name Validation
    QString name = ui->Name->text().trimmed();
    QRegularExpression nameRegex("^(?=.*[A-Za-z])[A-Za-z0-9 ]+$");
    if (name.isEmpty()) {
        ui->NameER->setText("The stadium name cannot be empty.");
        valid = false;
    } else if (name.length() < 3) {
        ui->NameER->setText("Must be at least 3 characters.");
        valid = false;
    }else if (!nameRegex.match(name).hasMatch()) {
        ui->NameER->setText("Name must contain letters and can include numbers.");
        valid = false;
    } else {
        ui->NameER->clear(); // Clear error if valid
    }

    // Address Validation
    QString address = ui->Adress->text().trimmed();
    QRegularExpression addressRegex("^(?=.*[A-Za-z])[A-Za-z0-9 ,.-]+$"); // Must contain at least one letter, allows letters, numbers, spaces, commas, dots, and hyphens
    if (address.isEmpty()) {
        ui->AdressER->setText("The stadium address cannot be empty.");
        valid = false;
    } else if (address.length() < 5) {
        ui->AdressER->setText("Must be at least 5 characters.");
        valid = false;
    } else if (!addressRegex.match(address).hasMatch()) {
        ui->AdressER->setText("Address must contain letters and can include numbers.");
        valid = false;
    } else {
        ui->AdressER->clear(); // Clear error if valid
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

    // Stop execution if any input is invalid
    if (!valid) {
        return;
    }

    // Create a new Stadium object to add
    Stadium newStadium(name, address, capacity, status);

    // Attempt to add the stadium to the database
    if (newStadium.addStadium()) {
        QMessageBox::information(this, "Success", "Stadium added successfully.");
        ui->Name->clear();
        ui->Adress->clear();
        ui->capacity->clear();
        ui->status->clear();
        refreshStadiumList(); // Refresh the table to show the new stadium
    } else {
        QMessageBox::warning(this, "Error", "Failed to add stadium.");
        ui->Name->clear();
        ui->Adress->clear();
        ui->capacity->clear();
        ui->status->clear();
    }
}


void stadiumPage::on_delete_stadium_clicked(int row)
{
    qDebug() << "delete clicked";
    int id = ui->tableWidget->item(row, 0)->text().toInt();
    if (stadium.deleteStadium(id)) {
        qDebug() << "stadium was deleted.";
        refreshStadiumList();
    } else {
        qDebug() << "Failed to delete stadium ";
    }
}

void stadiumPage::on_update_stadium_clicked(int row)
{
    qDebug() << "update clicked" << row;
    int stadiumid = ui->tableWidget->item(row, 0)->text().toInt();
    if (stadiumid < 0) {
        QMessageBox::warning(this, "Selection Error", "Please select a stadium to update.");
        return;
    }
    stadiumupdateform *updateForm = new stadiumupdateform(this, stadiumid);
    updateForm->show();
    refreshStadiumList();
}


void stadiumPage::addButtonsToRows(QTableWidget* table)
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
        table->setCellWidget(row, 5, actionWidget);

        // Connect buttons to their respective slots
        connect(deleteButton, &QPushButton::clicked, this, [this, row]() {
            on_delete_stadium_clicked(row);  // Pass the row index to the delete method
        });

        connect(updateButton, &QPushButton::clicked, this, [this, row]() {
            on_update_stadium_clicked(row);  // Pass the row index to the update method
        });

        // Adjust the column and row size to ensure enough space for the buttons
        table->setColumnWidth(5, 200);  // Adjust column width for the actions column
        table->setRowHeight(row, 60);   // Set row height for the actions row
    }
}





void stadiumPage::on_refresh_clicked()
{
    refreshStadiumList();
}


void stadiumPage::on_homeButton_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Dashboard Confirmation",
                                  "Are you sure you want to return to the dashboard? All unsaved work will be lost.",
                                  QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        homepage *HomePage = new homepage(nullptr);
        HomePage->show();

        this->close();
    }

}


void stadiumPage::on_notifButton_clicked()
{

}


void stadiumPage::on_aboutButton_clicked()
{
    QMessageBox::information(this, "About This Page", "This is the Stadium Page,here you can manage the stadium and perform basic CRUD operations.\n\nVersion 1.0\n\nDeveloped by TechSpire.",
                             QMessageBox::Ok);

}


void stadiumPage::on_exitButton_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Exit Confirmation",
                                  "Are you sure you want to logout and exit?",
                                  QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        QApplication::quit();
    }

}


void stadiumPage::on_searchButton_clicked()
{
    QString searchText = ui->searchStaduimInput->text().trimmed();

    // 📌 Call the search function from Stadium class
    Stadium stadium;
    if (stadium.searchStadiums(searchText, ui->tableWidget)) {
        addButtonsToRows(ui->tableWidget); // Pass stadium ID
        qDebug() << "Search successful";
    } else {
        qDebug() << "Search failed";
    }
}


void stadiumPage::on_exportListButton_clicked() {
    QString fileName = QFileDialog::getSaveFileName(this, "Save PDF", "", "*.pdf");
    if (fileName.isEmpty()) return;

    stadium;
    stadium.exportListToPDF(ui->tableWidget, fileName);
}



void stadiumPage::on_filter_currentIndexChanged(int index)
{
    qDebug() << "Filter index selected:" << index;

    if (index == 0) return; // Skip filtering if default option is selected

    Stadium stadium;
    if (stadium.filterStadiums(index, ui->tableWidget)) {
        addButtonsToRows(ui->tableWidget); // Pass stadium ID
        qDebug() << "Filter applied successfully.";
    } else {
        qDebug() << "Failed to apply filter or no filter selected.";
    }
}

void stadiumPage::on_showChartButton_clicked() {
    stadium.showStadiumStatusChart(ui->tableWidget);
}



void stadiumPage::on_showTopStadiumsButton_clicked()
{
    stadium.showTopStadiumsByCapacity(ui->tableWidget);
}


void stadiumPage::on_checkButton_clicked() {
    int stadiumID = ui->stadiumidinput->text().toInt();
    QDate matchDate = ui->dateinput->date();

    if (stadiumID == 0) {
        ui->IDER->setText("Invalid Stadium ID.");
        return;
    } else {
        ui->IDER->clear();
    }

    if (matchDate < QDate::currentDate()) {
        ui->DATEER->setText("Date must be in the future.");
        return;
    } else {
        ui->DATEER->clear();
    }

    Stadium stadiumObj;
    stadiumObj.checkStadiumPracticality(stadiumID, matchDate, this);
}


void stadiumPage::on_checkSeatsButton_clicked()
{
    QString matchID = ui->matchidInput->text();
    Stadium stadium;

    stadium.checkMatchAndShowSeats(matchID,
                                   ui->topSeatsWidget,
                                   ui->bottomSeatsWidget,
                                   ui->leftSeatsWidget,
                                   ui->rightSeatsWidget,
                                   ui->attendanceLabel,
                                   ui->matchider);
}
