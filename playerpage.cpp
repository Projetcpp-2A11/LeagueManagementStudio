#include "playerpage.h"
//#include "playerupdateform.h"
#include "homepage.h"
#include "playerperformance.h"
#include "playerupdateform.h"
#include "qbarcategoryaxis.h"
#include "qbarseries.h"
#include "qbarset.h"
#include "qboxlayout.h"
#include "player.h"
#include "qchart.h"
#include "qchartview.h"
#include "qsqlquery.h"
#include "qvalueaxis.h"
#include "ui_playerpage.h"
#include <QMessageBox>
#include <QSqlError>
#include <QDebug>
#include <QFileDialog>




//QChart QtCharts;

playerPage::playerPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::playerPage)
{
    ui->setupUi(this);

    // Call the function from player.cpp to populate the teamComboBox
    populateTeamDropdown();
}

playerPage::~playerPage()
{
    delete ui;
}
void playerPage::populateTeamDropdown() {
    // Ensure the database connection is open before proceeding with the query
    if (!QSqlDatabase::database().isOpen()) {
        QMessageBox::critical(nullptr, "Error", "Database not connected.");
        return;
    }

    QSqlQuery query;
    query.prepare("SELECT TEAMID FROM TEAMS");  // Only selecting TEAMID

    if (query.exec()) {
        while (query.next()) {
            int teamId = query.value(0).toInt();  // Get TEAMID

            // Add teamId to the ComboBox (only the ID will be added)
            ui->teamID->addItem(QString::number(teamId), teamId);  // Display the TEAMID as text and store it as data
        }
    } else {
        QMessageBox::critical(nullptr, "Error", "Failed to load teams: " + query.lastError().text());
    }
}





void playerPage::setupPlayerTable() {
    // Assuming you have a QTableWidget named `playerTableWidget` in your player page UI
    // Populate the table with player data
    ui->playerTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

    // Create an instance of the player class
    player;
    // Call the listPlayers function to populate the table with player data
    player.listPlayers(ui->playerTableWidget);

    // Add action buttons to each row (modify, delete, etc.)
    addButtonsToRows(ui->playerTableWidget);
}
void playerPage::on_exitButton_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Exit Confirmation",
                                  "Are you sure you want to logout and exit?",
                                  QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        QApplication::quit();
    }

}


void playerPage::on_homeButton_clicked()
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


void playerPage::on_notifButton_clicked()
{

}


/*void playerPage::browseImage() {
    qDebug() << "Browse button clicked";

    // Open a file dialog to select the image file
    QString filePath = QFileDialog::getOpenFileName(this, tr("Select Player Image"), "", tr("Images (*.png *.jpg *.bmp *.jpeg)"));

    if (!filePath.isEmpty()) {
        qDebug() << "File selected: " << filePath;
        // Set the selected file path to the playerImage QLineEdit field
        ui->playerImage->setText(filePath);
    }
}*/


void playerPage::on_addPlayerButton_clicked() {
    // Get input values from UI
    QString firstName = ui->firstName1->text().trimmed();
    QString lastName = ui->lastName->text().trimmed();
    QString phoneNum = ui->phoneNum->text().trimmed();
    QString position = ui->positionComboBox->currentText().trimmed(); // Get selected position
    QString status = ui->status->text().trimmed();

    // Get the selected team ID from the combo box
   int selectedTeamId = ui->teamID->currentData().toInt(); // Get the selected TEAMID

    // Debugging: Print the selected team ID
    qDebug() << "Selected Team ID: " << selectedTeamId;

    // Get additional data for IMG and NUM
    QString playerImage = ui->playerImage->text().trimmed();  // Assuming you have a text field or path input for image
    int playerNumber = ui->playerNumber->text().toInt(); // Assuming there's a field to input player number

    // Validate input fields
    if (firstName.isEmpty() || lastName.isEmpty() || phoneNum.isEmpty() ||
        position.isEmpty() || status.isEmpty() || selectedTeamId == 0 || playerNumber == 0)
    {
        QMessageBox::warning(this, "Error", "Please fill all fields and select a valid team.");
        return;
    }

    // Generate Player ID
    int playerID = Player::generatePlayerId();

    // Create Player object with additional fields (IMG, NUM)
    Player newPlayer(playerID, firstName, lastName, phoneNum, position, status, selectedTeamId, playerImage, playerNumber);

    // Add Player to the database
    if (newPlayer.addPlayer(selectedTeamId)) {

        QMessageBox::information(this, "Success", "Player added successfully.");

        // Clear fields after successful insertion
        ui->firstName1->clear();
        ui->lastName->clear();
        ui->phoneNum->clear();
        ui->positionComboBox->setCurrentIndex(0); // Reset dropdown
        ui->status->clear();
        ui->teamID->setCurrentIndex(0); // Reset team selection
        ui->playerImage->clear();  // Clear the image field
        ui->playerNumber->clear(); // Clear the player number field
    } else {
        QMessageBox::critical(this, "Error", "Error adding player.");
    }
}


void playerPage::on_refreshButton_clicked()
{
    refresh();
}

void playerPage::addButtonsToRows(QTableWidget* table)
{
    // Iterate through each row in the table
    for (int row = 0; row < table->rowCount(); ++row) {
        // Create delete, update, performance, and suspension buttons
        QPushButton* deleteButton = new QPushButton("Delete");
        QPushButton* updateButton = new QPushButton("Update");
        QPushButton* performanceButton = new QPushButton("Player Performance");
        QPushButton* suspensionButton = new QPushButton("Suspension");  // New suspension button

        // Create a widget to hold the buttons
        QWidget* actionWidget = new QWidget();
        QHBoxLayout* actionLayout = new QHBoxLayout(actionWidget);
        actionLayout->setContentsMargins(0, 0, 0, 0);  // Remove margins
        actionLayout->setSpacing(10);  // Add spacing between the buttons

        // Add buttons to the layout
        actionLayout->addWidget(deleteButton);
        actionLayout->addWidget(updateButton);
        actionLayout->addWidget(performanceButton);
        actionLayout->addWidget(suspensionButton);  // Add the suspension button to the layout

        // Set the size policy for the action widget to allow expansion
        actionWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);

        // Set the action widget as the cell widget in the table
        table->setCellWidget(row, 7, actionWidget);  // Set buttons in the 7th column (index 6)

        // Connect buttons to their respective slots
        connect(deleteButton, &QPushButton::clicked, this, [this, row]() {
            on_delete_player_clicked(row);  // Pass the row index to the delete method
        });

        connect(updateButton, &QPushButton::clicked, this, [this, row]() {
            on_update_player_clicked(row);  // Pass the row index to the update method
        });

        connect(performanceButton, &QPushButton::clicked, this, [row, this]() {
            on_player_performance_clicked(row);  // Pass the row index to the performance method
        });

        connect(suspensionButton, &QPushButton::clicked, this, [row, this]() {
            on_suspension_clicked(row);  // Pass the row index to the suspension method
        });

        // Adjust the column and row size to ensure enough space for the buttons
        table->setColumnWidth(7, 600);  // Adjust column width for the actions column (button column)
        table->setRowHeight(row, 60);   // Set row height for the actions row
    }
}




void playerPage::on_update_player_clicked(int row)
{
    qDebug() << "Update clicked for player at row:" << row;

    // Retrieve the first name and last name from the row (assuming columns 1 and 2 are for first and last names)
    QString firstName = ui->playerTableWidget->item(row, 0)->text();  // Assuming FNAME is in the second column
    QString lastName = ui->playerTableWidget->item(row, 1)->text();   // Assuming LNAME is in the third column

    // Query the database to get the PLAYERID using the first and last names
    QSqlQuery query;
    query.prepare("SELECT PLAYERID FROM Players WHERE FNAME = :firstName AND LNAME = :lastName");
    query.bindValue(":firstName", firstName);
    query.bindValue(":lastName", lastName);

    if (query.exec() && query.next()) {
        int playerID = query.value(0).toInt();  // Retrieve the PLAYERID from the query result
        qDebug() << "Player ID for" << firstName << lastName << "is" << playerID;

        // Open the update page with the retrieved PLAYERID
        playerupdateform *updatePage = new playerupdateform(nullptr, playerID);
        updatePage->show();
    } else {
        qDebug() << "Failed to retrieve PLAYERID for" << firstName << lastName << ":"
                 << query.lastError();
    }
}


void playerPage::refresh()
{
    ui->playerTableWidget->clearContents();
    ui->playerTableWidget->setRowCount(0);  // Reset row count

    // Repopulate the table with updated employee data
    player.listPlayers(ui->playerTableWidget);
    addButtonsToRows(ui->playerTableWidget);
}

void playerPage::on_sortButton_clicked()
{
    Player player;
    player.sortPlayersByName(ui->playerTableWidget);  // Sort the table by player names
}


/*void playerPage::on_searchButton_clicked()
{

}
*/


void playerPage::on_searchLineEdit_cursorPositionChanged( int arg2)
{
    QString searchTerm = ui->searchLineEdit->text();  // Assuming you have a QLineEdit for search input
    Player player;
    player.searchPlayers(searchTerm, ui->playerTableWidget);


}

void playerPage::on_delete_player_clicked(int row)
{
    qDebug() << "Delete clicked for player at row:" << row;

    // Get the FNAME and LNAME from the table widget
    QString firstName = ui->playerTableWidget->item(row, 0)->text();  // Assuming FNAME is in column 1
    QString lastName = ui->playerTableWidget->item(row, 1)->text();   // Assuming LNAME is in column 2

    qDebug() << "Player Name: " << firstName << " " << lastName;

    // Show a confirmation message box
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Delete Confirmation",
                                  "Are you sure you want to delete this player?",
                                  QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        // Call the modified delete function with first and last name
        if (deletePlayerUsingTeamID(firstName, lastName)) {
            qDebug() << "Player with name" << firstName << lastName << "deleted successfully.";
        } else {
            qDebug() << "Failed to delete player with name" << firstName << lastName;
        }
    } else {
        qDebug() << "Deletion canceled by the user.";
    }
}



void playerPage::on_player_performance_clicked(int row)
{
    qDebug() << "Player Performance clicked for player at row:" << row;

    // Check if the row index is valid
    if (row < 0 || row >= ui->playerTableWidget->rowCount()) {
        qDebug() << "Invalid row index!";
        return;
    }

    // Get the first and last name from the table (assuming they are in the first and second columns)
    QString firstName = ui->playerTableWidget->item(row, 0)->text();
    QString lastName = ui->playerTableWidget->item(row, 1)->text();

    // Log the first and last name for debugging
    qDebug() << "First Name:" << firstName << "Last Name:" << lastName;

    // Check if the names are empty
    if (firstName.isEmpty() || lastName.isEmpty()) {
        qDebug() << "First name or last name is empty!";
        return;
    }

    // Now, create the PlayerPerformance widget and set the player's data
    PlayerPerformance *performanceWidget = new PlayerPerformance(this);  // Create the widget

    // Set the player performance data by calling setPlayer
    performanceWidget->setPlayer(firstName, lastName);

    // Log the player performance data being set
    qDebug() << "Setting player performance data for:" << firstName << lastName;

    // Call the updatePlayerPerformance function to update the stats in the database
    Player player;  // Ensure you have access to the Player class or instance
    player.updatePlayerPerformance(firstName, lastName, true);  // Pass true if the interface is closing
  // Update performance for the player

    // Show the PlayerPerformance widget
    performanceWidget->show();

    // Log the result (This log will run regardless of success/failure since the function is void)
    qDebug() << "Player performance updated for player:" << firstName << lastName;
}







void playerPage::on_statistiqueButton_clicked()
{
    qDebug() << "Statistique button clicked";
    displayPerformanceStats();
}


void playerPage::on_exportButton_clicked()
{
    qDebug() << "Export button clicked";

    QString filePath = QFileDialog::getSaveFileName(nullptr, "Save as PDF", "", "*.pdf");
    if (!filePath.isEmpty()) {
        Player p;
        p.exportPlayerListToPDF(filePath); // Pass the file path
    }
}



void playerPage::on_suspension_clicked(int row)
{
    qDebug() << "Suspension button clicked for row:" << row;

    // Check if the row index is valid
    if (row < 0 || row >= ui->playerTableWidget->rowCount()) {
        qDebug() << "Invalid row index!";
        return;
    }

    // Get the first and last name from the table (assuming they are in the first and second columns)
    QString firstName = ui->playerTableWidget->item(row, 0)->text();
    QString lastName = ui->playerTableWidget->item(row, 1)->text();

    // Log the first and last name for debugging
    qDebug() << "First Name:" << firstName << "Last Name:" << lastName;

    // Check if the names are empty
    if (firstName.isEmpty() || lastName.isEmpty()) {
        qDebug() << "First name or last name is empty!";
        return;
    }

    // Now, create the Player object and call the checkSuspensionStatus function
    Player player;
    player.checkSuspensionStatus(firstName, lastName);  // Call the function to check suspension status

    // Log the result
    qDebug() << "Suspension check complete for player:" << firstName << lastName;
}




void playerPage::on_BrowseImageButton_clicked()
{
    qDebug() << "Browse button clicked";

    // Open a file dialog to select the image file
    QString filePath = QFileDialog::getOpenFileName(this, tr("Select Player Image"), "", tr("Images (*.png *.jpg *.bmp *.jpeg)"));

    if (!filePath.isEmpty()) {
        qDebug() << "File selected: " << filePath;
        // Set the selected file path to the playerImage QLineEdit field
        ui->playerImage->setText(filePath);
    }
}

