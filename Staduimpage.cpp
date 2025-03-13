#include "Staduimpage.h"
#include "ui_Staduimpage.h"
#include <QMessageBox>
#include <QVBoxLayout>
#include "stadium.h"
stadiumPage::stadiumPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Staduimpage)
{
    setWindowTitle("Stadium Page");
    ui->setupUi(this);

    setMinimumSize(1000, 800);
    resize(800, 600);

    // Apply a layout to ensure resizing works properly
    QVBoxLayout *layout = new QVBoxLayout(this);
    setLayout(layout);


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
    QString name = ui->Name->text();
    QString address = ui->Adress->text();
    int capacity = ui->capacity->text().toInt();
    QString status = ui->status->text();

    // Create a new Stadium object to add
    Stadium newStadium(name, address, capacity, status);

    // Attempt to add the stadium to the database
    if (newStadium.addStadium()) {
        QMessageBox::information(this, "Success", "Stadium added successfully.");
        refreshStadiumList(); // Refresh the table to show the new stadium
    } else {
        QMessageBox::warning(this, "Error", "Failed to add stadium.");
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
    qDebug() << " update clicked";
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




