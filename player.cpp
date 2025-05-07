#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QRandomGenerator>
#include <QDebug>
#include "playerpage.h"
#include "qbarcategoryaxis.h"
#include "qbarseries.h"
#include "qbarset.h"
#include "qboxlayout.h"
#include "qchart.h"
#include "qchartview.h"
#include "qheaderview.h"
#include "qlabel.h"
#include "qserialport.h"
#include "qvalueaxis.h"
#include "ui_playerpage.h"
#include <QPrinter>
#include <QFileDialog>
#include <QTextDocument>
#include <QMessageBox>
#include <player.h>
// Default constructor
Player::Player()
    : playerId(0), firstName(""), lastName(""), phoneNumber(""),
    position(""), status(""), teamId(0), img(""), number(0)  // Initialize new fields
{}

// Parametrized constructor
Player::Player(int playerId, const QString &firstName, const QString &lastName,
               const QString &phoneNumber, const QString &position,
               const QString &status, int teamId, const QString &img, int number)
    : playerId(playerId), firstName(firstName), lastName(lastName),
    phoneNumber(phoneNumber), position(position), status(status), teamId(teamId),
    img(img), number(number)  // Initialize new fields
{}

int Player::getPlayerId() const
{
    return playerId;
}

QString Player::getFirstName() const {
    return firstName;
}

QString Player::getLastName() const {
    return lastName;
}

int Player::getTeamId() const {
    return teamId;
}


// Definition of generatePlayerId function
int Player::generatePlayerId() {
    // Generate a unique player ID, for example, you can use a random number or a counter
    // For this example, I will simply return a random number between 1 and 10000
    return rand() % 10000 + 1;
}

// Add player to the database
bool Player::addPlayer(int selectedTeamId) {
    QSqlQuery query;
    QRegularExpression regex("^[a-zA-Z]+$");

    // First Name validation
    if (!regex.match(firstName.trimmed()).hasMatch() || firstName.trimmed().size() < 2) {
        QMessageBox::warning(nullptr, "Invalid Input", "Le prénom ne doit contenir que des lettres alphabétiques et doit comporter au moins 2 caractères.");
        return false;
    }

    // Last Name validation
    if (lastName.trimmed().isEmpty() || lastName.trimmed().size() < 2) {
        QMessageBox::warning(nullptr, "Invalid Input", "Last Name must contain at least two letters.");
        return false;
    }

    // Phone Number validation
    if (phoneNumber.trimmed().isEmpty()) {
        QMessageBox::warning(nullptr, "Invalid Input", "Phone Number cannot be empty.");
        return false;
    }

    if (phoneNumber.length() != 8 || !phoneNumber.toLongLong()) {
        QMessageBox::warning(nullptr, "Invalid Input", "Phone Number must be an 8-digit number.");
        return false;
    }

    // Position validation
    QStringList validPositions = {"GK", "CB", "RB", "LB", "CM", "RM", "LM", "RW", "LW", "ST"};

    if (!validPositions.contains(position)) {
        QMessageBox::warning(nullptr, "Invalid Input", "Position must be one of the following: GK, CB, RB, LB, CM, RM, LM, RW, LW, ST.");
        return false;
    }

    // Status validation
    if (status.trimmed().isEmpty() || (status != "en forme" && status != "blessé")) {
        QMessageBox::warning(nullptr, "Invalid Input", "Status must be either 'en forme' or 'blessé'.");
        return false;
    }

    // Team selection validation
    if (selectedTeamId == 0) {
        QMessageBox::warning(nullptr, "Invalid Input", "Please select a valid team.");
        return false;
    }

    // Validate player number (num should be between 1 and 100)
    if (number < 1 || number > 100) {
        QMessageBox::warning(nullptr, "Invalid Input", "Player number must be between 1 and 100.");
        return false;
    }

    // Validate image (img must not be empty)
    if (img.trimmed().isEmpty()) {
        QMessageBox::warning(nullptr, "Invalid Input", "Player image must not be empty.");
        return false;
    }

    // Generate player ID dynamically
    playerId = generatePlayerId();

    // Prepare the SQL query
    query.prepare("INSERT INTO PLAYERS (PLAYERID, FNAME, LNAME, PHONENUM, POSITION, STATUS, TEAMID, IMG, NUM) "
                  "VALUES (:playerId, :firstName, :lastName, :phoneNumber, :position, :status, :teamId, :img, :num)");

    query.bindValue(":playerId", playerId);
    query.bindValue(":firstName", firstName);
    query.bindValue(":lastName", lastName);
    query.bindValue(":phoneNumber", phoneNumber);
    query.bindValue(":position", position);
    query.bindValue(":status", status);
    query.bindValue(":teamId", selectedTeamId);

    // Bind image and number to the query
    query.bindValue(":img", img);  // Set this to the file name of the player's image
    query.bindValue(":num", number);  // Set this to the player number (e.g., jersey number)

    // Execute the query
    if (!query.exec()) {
        qDebug() << "Error inserting player: " << query.lastError().text();
        return false;
    }

    // Insert into PLAYERPERFORMANCE table
    QSqlQuery perfQuery;
    perfQuery.prepare("INSERT INTO PLAYERPERFORMANCE (PLAYERID) VALUES (:playerId)");
    perfQuery.bindValue(":playerId", playerId);

    if (!perfQuery.exec()) {
        qDebug() << "Error inserting player performance: " << perfQuery.lastError().text();
        return false;
    }

    return true;
}


void Player::listPlayers(QTableWidget* table)
{
    table->clearContents();  // Clear existing table contents
    table->setRowCount(0);    // Reset row count
    table->verticalHeader()->setVisible(false);  // Hide vertical header

    // Update table to have 8 columns (add columns for IMG and NUM)
    table->setColumnCount(8);  // FNAME, LNAME, POSITION, STATUS, TEAMID, IMG, NUM, ACTIONS

    // Set headers for the new columns
    table->setHorizontalHeaderLabels({"FNAME", "LNAME", "POSITION", "STATUS", "TEAMID", "IMG", "NUM", "ACTIONS"});

    // SQL query to fetch data including IMG and NUM
    QString queryStr = "SELECT PLAYERID, FNAME, LNAME, PHONENUM, POSITION, STATUS, TEAMID, IMG, NUM FROM PLAYERS";
    QSqlQuery query;

    if (query.exec(queryStr)) {
        int row = 0;
        while (query.next()) {
            table->insertRow(row);

            // Insert data into the table
            table->setItem(row, 0, new QTableWidgetItem(query.value(1).toString()));  // FNAME
            table->setItem(row, 1, new QTableWidgetItem(query.value(2).toString()));  // LNAME
            table->setItem(row, 2, new QTableWidgetItem(query.value(4).toString()));  // POSITION
            table->setItem(row, 3, new QTableWidgetItem(query.value(5).toString()));  // STATUS
            table->setItem(row, 4, new QTableWidgetItem(query.value(6).toString()));  // TEAMID

            // Insert IMG (image path) and NUM (player number) into the table
            QString imgPath = query.value(7).toString(); // Path of the image
            if (!imgPath.isEmpty()) {
                QPixmap pixmap(imgPath);  // Load image from the path

                // Get the width and height of the "IMG" column
                int columnWidth = table->columnWidth(5);  // Get the width of the "IMG" column
                int rowHeight = table->rowHeight(row);    // Get the height of the current row

                // Ensure column and row sizes are large enough
                table->setColumnWidth(5, 100);  // Set column width to a fixed size
                table->setRowHeight(row, 100);  // Set row height to a fixed size

                // Scale the image to fit the cell's width and height (stretch to fill)
                pixmap = pixmap.scaled(columnWidth, rowHeight, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);  // Scale the image to fit the cell

                // Use a QWidget to hold the image and set it in the cell
                QWidget *imageWidget = new QWidget();
                QVBoxLayout *layout = new QVBoxLayout(imageWidget);
                QLabel *imageLabel = new QLabel(imageWidget);
                imageLabel->setPixmap(pixmap);
                layout->addWidget(imageLabel);
                layout->setAlignment(Qt::AlignCenter);  // Center the image within the cell
                layout->setContentsMargins(0, 0, 0, 0); // Ensure no extra margins/padding

                // Set the image widget in the IMG column
                table->setCellWidget(row, 5, imageWidget);  // Set image in column 5 (IMG column)
            }

            // Set the NUM value (player number) in the NUM column
            table->setItem(row, 6, new QTableWidgetItem(query.value(8).toString()));  // NUM

            ++row;
        }

    } else {
        qDebug() << "Failed to fetch data: " << query.lastError();
    }
}


















bool Player::updatePlayerDetails(int playerId, const QString &firstName, const QString &lastName, const QString &position, const QString &status, const QString &phoneNum, int teamID, int playerNum)
{
    QSqlQuery query;

    // Prepare the SQL query to update the player details, including the NUM field
    query.prepare("UPDATE PLAYERS SET FNAME = :firstName, LNAME = :lastName, "
                  "POSITION = :position, STATUS = :status, PHONENUM = :phoneNum, TEAMID = :teamID, NUM = :playerNum "
                  "WHERE PLAYERID = :playerId");

    // Bind the values to the placeholders in the query
    query.bindValue(":firstName", firstName);
    query.bindValue(":lastName", lastName);
    query.bindValue(":position", position);
    query.bindValue(":status", status);
    query.bindValue(":phoneNum", phoneNum);
    query.bindValue(":teamID", teamID);
    query.bindValue(":playerNum", playerNum);  // Bind the player's number (NUM)
    query.bindValue(":playerId", playerId);    // Bind the playerID to the query

    // Execute the query and check if it was successful
    if (query.exec()) {
        qDebug() << "Player with PLAYERID" << playerId << "updated successfully.";
        return true;
    } else {
        qDebug() << "Failed to update player with PLAYERID" << playerId << ":" << query.lastError();
        return false;
    }
}


bool Player::updatePlayerUsingTeamID(int playerID, const QString& firstName, const QString& lastName, const QString& position, const QString& status, const QString& phoneNum, int teamID, int playerNum)
{
    QSqlQuery query;


    query.prepare("UPDATE PLAYERS SET FNAME = :firstName, LNAME = :lastName, POSITION = :position, STATUS = :status, PHONENUM = :phoneNum, TEAMID = :teamID, NUM = :playerNum WHERE PLAYERID = :playerID");

    // Bind the values to the query placeholders
    query.bindValue(":firstName", firstName);
    query.bindValue(":lastName", lastName);
    query.bindValue(":position", position);
    query.bindValue(":status", status);
    query.bindValue(":phoneNum", phoneNum);
    query.bindValue(":teamID", teamID);
    query.bindValue(":playerNum", playerNum);  // Bind the player's number (NUM)
    query.bindValue(":playerID", playerID);    // Bind the playerID to the query

    // Execute the query and check if it was successful
    if (query.exec()) {
        qDebug() << "Player with PLAYERID" << playerID << "updated successfully.";
        return true;
    } else {
        qDebug() << "Failed to update player with PLAYERID" << playerID << ":" << query.lastError();
        return false;
    }
}

void Player::sortPlayersByName(QTableWidget* table)
{
    table->clearContents();
    table->setRowCount(0);
    table->verticalHeader()->setVisible(false);

    QString queryStr = "SELECT IMG, FNAME, LNAME, POSITION, STATUS, TEAMID, NUM FROM PLAYERS ORDER BY FNAME ASC";
    QSqlQuery query;

    if (query.exec(queryStr)) {
        int row = 0;
        while (query.next()) {
            table->insertRow(row);


            QString imagePath = query.value(0).toString();  // IMG
            QLabel* imgLabel = new QLabel();
            QPixmap pix(imagePath);
            if (!pix.isNull())
                imgLabel->setPixmap(pix.scaled(50, 50, Qt::KeepAspectRatio));
            else
                imgLabel->setText("No Img");
            table->setCellWidget(row, 5, imgLabel);

            // Set remaining values
            table->setItem(row, 0, new QTableWidgetItem(query.value(1).toString())); // FNAME
            table->setItem(row, 1, new QTableWidgetItem(query.value(2).toString())); // LNAME
            table->setItem(row, 2, new QTableWidgetItem(query.value(3).toString())); // POSITION
            table->setItem(row, 3, new QTableWidgetItem(query.value(4).toString())); // STATUS
            table->setItem(row, 4, new QTableWidgetItem(query.value(5).toString())); // TEAMID
            table->setItem(row, 6, new QTableWidgetItem(query.value(6).toString())); // NUM

            table->setRowHeight(row, 60);
            row++;
        }


    } else {
        qDebug() << "Failed to fetch sorted data: " << query.lastError();
    }
}




void Player::searchPlayers(const QString &searchTerm, QTableWidget *tableWidget)
{
    QSqlQuery query;
    query.prepare("SELECT IMG, FNAME, LNAME, POSITION, STATUS, TEAMID, NUM FROM PLAYERS WHERE FNAME LIKE :term OR LNAME LIKE :term");
    query.bindValue(":term", "%" + searchTerm + "%");

    if (query.exec()) {
        tableWidget->setRowCount(0);

        while (query.next()) {
            int rowCount = tableWidget->rowCount();
            tableWidget->insertRow(rowCount);

            // Display image
            QString imagePath = query.value(0).toString();
            QLabel* imgLabel = new QLabel();
            QPixmap pix(imagePath);
            if (!pix.isNull())
                imgLabel->setPixmap(pix.scaled(50, 50, Qt::KeepAspectRatio));
            else
                imgLabel->setText("No Img");
            tableWidget->setCellWidget(rowCount, 5, imgLabel);

            // Set remaining values
            tableWidget->setItem(rowCount, 0, new QTableWidgetItem(query.value(1).toString())); // FNAME
            tableWidget->setItem(rowCount, 1, new QTableWidgetItem(query.value(2).toString())); // LNAME
            tableWidget->setItem(rowCount, 2, new QTableWidgetItem(query.value(3).toString())); // POSITION
            tableWidget->setItem(rowCount, 3, new QTableWidgetItem(query.value(4).toString())); // STATUS
            tableWidget->setItem(rowCount, 4, new QTableWidgetItem(query.value(5).toString())); // TEAMID
            tableWidget->setItem(rowCount, 6, new QTableWidgetItem(query.value(6).toString())); // NUM

            tableWidget->setRowHeight(rowCount, 60);
        }

        for (int col = 0; col < 7; col++) {
            tableWidget->setColumnWidth(col, 120);
        }
    } else {
        qDebug() << "Search query failed: " << query.lastError();
    }
}





bool playerPage::deletePlayerUsingTeamID(const QString &firstName, const QString &lastName)
{
    // First, query the PLAYERID based on the first name and last name
    QSqlQuery query;
    query.prepare("SELECT PLAYERID FROM Players WHERE FNAME = :firstName AND LNAME = :lastName");
    query.bindValue(":firstName", firstName);
    query.bindValue(":lastName", lastName);

    if (query.exec() && query.next()) {
        int playerId = query.value(0).toInt();  // Retrieve the PLAYERID from the query result
        qDebug() << "PlayerID for" << firstName << lastName << "is" << playerId;

        // Now, perform the delete operation using the PLAYERID
        QSqlQuery deleteQuery;
        deleteQuery.prepare("DELETE FROM Players WHERE PLAYERID = :playerId");
        deleteQuery.bindValue(":playerId", playerId);

        if (deleteQuery.exec()) {
            qDebug() << "Player with PLAYERID" << playerId << "deleted successfully.";
            return true;
        } else {
            qDebug() << "Failed to delete player with PLAYERID" << playerId << ":" << deleteQuery.lastError();
            return false;
        }
    } else {
        qDebug() << "Failed to retrieve PLAYERID for" << firstName << lastName << ":" << query.lastError();
        return false;
    }
}







void Player::exportPlayerListToPDF(const QString& filePath) // Match header file
{
    if (filePath.isEmpty()) {
        return;
    }

    QString html;
    html += "<h2>Player List</h2>";
    html += "<table border='1' cellspacing='0' cellpadding='4'>";
    html += "<thead><tr>";
    QStringList headers = {"PLAYERID", "FNAME", "LNAME", "PHONENUM", "POSITION", "STATUS", "TEAMID"};
    for (const QString &header : headers) {
        html += QString("<th>%1</th>").arg(header);
    }
    html += "</tr></thead>";

    QSqlQuery query("SELECT PLAYERID, FNAME, LNAME, PHONENUM, POSITION, STATUS, TEAMID FROM PLAYERS");
    html += "<tbody>";
    while (query.next()) {
        html += "<tr>";
        for (int i = 0; i < headers.size(); ++i) {
            QString cellData = query.value(i).toString();
            html += QString("<td>%1</td>").arg(cellData);
        }
        html += "</tr>";
    }
    html += "</tbody></table>";

    QTextDocument document;
    document.setHtml(html);

    QPrinter printer(QPrinter::HighResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(filePath);
    document.print(&printer);

    QMessageBox::information(nullptr, "Success", "Player list exported as PDF successfully!");
}

void playerPage::displayPerformanceStats()
{
    QSqlQuery query;

    // Query for Top Scorers (Best 10)
    query.prepare(R"(
        SELECT PLAYERID, TOTAL_GOALS FROM (
            SELECT PLAYERID, SUM(NUMGOALS) AS TOTAL_GOALS
            FROM PLAYERPERFORMANCE
            WHERE PLAYERID NOT IN (SELECT PLAYERID FROM PLAYERS WHERE POSITION = 'GK')
            GROUP BY PLAYERID
            ORDER BY TOTAL_GOALS DESC
        )
        WHERE ROWNUM <= 10
    )");

    if (!query.exec()) {
        qDebug() << "Error fetching top scorers: " << query.lastError().text();
        return;
    }

    // Prepare series for Top Scorers
    QBarSet *topScorersSet = new QBarSet("Top Scorers (Goals)");
    QBarSeries *topScorersSeries = new QBarSeries();
    QStringList playerNames;

    while (query.next()) {
        int playerId = query.value("PLAYERID").toInt();
        int totalGoals = query.value("TOTAL_GOALS").toInt();

        playerNames << QString("Player %1").arg(playerId);
        *topScorersSet << totalGoals;
    }
    topScorersSeries->append(topScorersSet);

    // Query for Assist Leaders (Best 10)
    query.prepare(R"(
        SELECT PLAYERID, TOTAL_ASSISTS FROM (
            SELECT PLAYERID, SUM(NUMASSISTS) AS TOTAL_ASSISTS
            FROM PLAYERPERFORMANCE
            WHERE PLAYERID NOT IN (SELECT PLAYERID FROM PLAYERS WHERE POSITION = 'GK')
            GROUP BY PLAYERID
            ORDER BY TOTAL_ASSISTS DESC
        )
        WHERE ROWNUM <= 10
    )");

    if (!query.exec()) {
        qDebug() << "Error fetching assist leaders: " << query.lastError().text();
        return;
    }

    // Prepare series for Assist Leaders
    QBarSet *assistLeadersSet = new QBarSet("Assist Leaders (Assists)");
    QBarSeries *assistLeadersSeries = new QBarSeries();

    while (query.next()) {
        int totalAssists = query.value("TOTAL_ASSISTS").toInt();
        *assistLeadersSet << totalAssists;
    }
    assistLeadersSeries->append(assistLeadersSet);

    // Create the chart and add the series
    QChart *chart = new QChart();
    chart->addSeries(topScorersSeries);
    chart->addSeries(assistLeadersSeries);
    chart->setTitle("Player Performance Stats");

    // Set the X-axis labels to player names
    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(playerNames);
    chart->addAxis(axisX, Qt::AlignBottom);
    topScorersSeries->attachAxis(axisX);
    assistLeadersSeries->attachAxis(axisX);

    // Set the Y-axis
    QValueAxis *axisY = new QValueAxis();
    axisY->setRange(0, 100); // Adjust range based on actual data
    chart->addAxis(axisY, Qt::AlignLeft);
    topScorersSeries->attachAxis(axisY);
    assistLeadersSeries->attachAxis(axisY);

    // Create the chart view and display it
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->resize(800, 600);
    chartView->show();
}



void Player::updatePlayerPerformance(const QString& firstName, const QString& lastName, bool isInterfaceClosed)
{
    qDebug() << "Updating performance for player with name " << firstName << lastName;

    // Query the database to get the playerId using the first name and last name
    QSqlQuery query;
    query.prepare("SELECT PLAYERID FROM Players WHERE FNAME = :firstName AND LNAME = :lastName");
    query.bindValue(":firstName", firstName);
    query.bindValue(":lastName", lastName);

    int playerId = -1;  // Default value in case the query fails
    if (query.exec() && query.next()) {
        playerId = query.value(0).toInt();  // Retrieve the playerId from the query result
        qDebug() << "Player ID for" << firstName << lastName << "is" << playerId;
    } else {
        qDebug() << "Failed to retrieve player ID for" << firstName << lastName << ":" << query.lastError();
        return;  // Exit the function if player ID isn't found
    }

    // Insert a new match into MATCHES table
    QSqlQuery matchInsertQuery;
    if (!matchInsertQuery.exec("INSERT INTO MATCHES (MATCHDATE) VALUES (SYSDATE)")) {
        qDebug() << "Failed to insert match:" << matchInsertQuery.lastError();
        return;
    }

    // Retrieve the last MATCHID generated in this session
    QSqlQuery getMatchIdQuery;
    int matchId = -1;
    if (getMatchIdQuery.exec("SELECT Match_Seq.CURRVAL FROM DUAL") && getMatchIdQuery.next()) {
        matchId = getMatchIdQuery.value(0).toInt();
        qDebug() << "Inserted new match with MATCHID:" << matchId;
    } else {
        qDebug() << "Failed to retrieve MATCHID:" << getMatchIdQuery.lastError();
        return;
    }

    // Fetch the player's position
    query.prepare("SELECT POSITION FROM PLAYERS WHERE PLAYERID = :playerId");
    query.bindValue(":playerId", playerId);

    if (!query.exec()) {
        qDebug() << "Error fetching position for player " << playerId << ": " << query.lastError().text();
        return;
    }

    if (!query.next()) {
        qDebug() << "No position found for player " << playerId;
        return;
    }

    QString position = query.value("POSITION").toString();
    qDebug() << "Player position: " << position;

    // New stats based on position
    int numGoals = 0;
    int numAssists = 0;
    int numSaves = 0;
    int numYellowCards = 0;
    int numRedCards = 0;
    int playTimeInMinutes = 0;

    // Reset the values (don't add previous stats)
    numYellowCards = 0;
    numRedCards = 0;

    if (position == "ST" || position == "RW" || position == "LW") {
        numGoals = QRandomGenerator::global()->bounded(0, 4);
        numAssists = QRandomGenerator::global()->bounded(0, 5);
        numYellowCards = QRandomGenerator::global()->bounded(0, 3);
        numRedCards = QRandomGenerator::global()->bounded(0, 2);
        // Setting a minimum and maximum for playtime, with min as 60 minutes and max as 90 minutes
        playTimeInMinutes = QRandomGenerator::global()->bounded(10, 94);
    } else if (position == "CM" || position == "LM" || position == "RM") {
        numGoals = QRandomGenerator::global()->bounded(0, 5);
        numAssists = QRandomGenerator::global()->bounded(1, 7);
        numYellowCards = QRandomGenerator::global()->bounded(0, 3);
        numRedCards = QRandomGenerator::global()->bounded(0, 2);
        // Setting a minimum and maximum for playtime, with min as 60 minutes and max as 90 minutes
        playTimeInMinutes = QRandomGenerator::global()->bounded(10, 94);
    } else if (position == "CB" || position == "RB" || position == "LB") {
        numGoals = QRandomGenerator::global()->bounded(0, 3);
        numAssists = QRandomGenerator::global()->bounded(0, 5);
        numYellowCards = QRandomGenerator::global()->bounded(0, 3);
        numRedCards = QRandomGenerator::global()->bounded(0, 2);
        // Setting a minimum and maximum for playtime, with min as 90 minutes and max as 120 minutes
        playTimeInMinutes = QRandomGenerator::global()->bounded(10, 94);
    } else if (position == "GK") {
        numSaves = QRandomGenerator::global()->bounded(4,10);
        numYellowCards = QRandomGenerator::global()->bounded(0, 3);
        numRedCards = QRandomGenerator::global()->bounded(0, 2);
        // Goalkeepers typically play the entire match, setting a minimum of 90 minutes
        playTimeInMinutes = QRandomGenerator::global()->bounded(10, 94);
    }

    numYellowCards = qMin(numYellowCards, 2);
    numRedCards = qMin(numRedCards, 1);

    if (numYellowCards == 2) {
        numRedCards = 1; // Two yellow cards automatically result in a red card
    }

    // Logic to ensure no yellow cards if a red card is already issued
    if (numRedCards > 0) {
        numYellowCards = 0; // No yellow cards if red card is issued
    }
    // Calculate the total number of yellow and red cards (just based on the current match)
    int totalYellowCards = numYellowCards;
    int totalRedCards = numRedCards;

    qDebug() << "Stats - Goals:" << numGoals << ", Assists:" << numAssists << ", Saves:" << numSaves
             << ", Yellow Cards:" << numYellowCards << ", Red Cards:" << numRedCards
             << ", Play Time:" << playTimeInMinutes << "minutes";

    if (numYellowCards >= 2 || numRedCards > 0) {
        qDebug() << "Player is suspended due to yellow/red cards.";
    }

    // === Calculate Rating ===
    double rating = 6.0;
    int goalsConceded = QRandomGenerator::global()->bounded(0, 5); // Replace with actual if available

    qDebug() << "Goals conceded:" << goalsConceded;  // Debugging the conceded goals value

    if (position == "GK") {
        rating += (static_cast<double>(numSaves) * 0.3)   // Bonus for saves
                  - (static_cast<double>(goalsConceded) * 1.0) // Penalty for goals conceded
                  - (static_cast<double>(numYellowCards) * 0.3)  // Penalty for yellow cards
                  - (static_cast<double>(numRedCards) * 0.6);    // Penalty for red cards
    } else if ( position == "RB" || position == "LB" || position == "CB") {  // Defenders
        rating += (static_cast<double>(playTimeInMinutes) / 90.0 * 0.5)
                  + (static_cast<double>(numAssists) * 0.2)
                  - (static_cast<double>(numYellowCards) * 0.2)
                  - (static_cast<double>(numRedCards) * 0.5);
    } else if ( position == "CM" || position == "LM" || position == "RM") {  // Midfielders
        rating += (static_cast<double>(playTimeInMinutes) / 90.0 * 0.5)
                  + (static_cast<double>(numGoals) * 0.3)
                  + (static_cast<double>(numAssists) * 0.3)
                  - (static_cast<double>(numYellowCards) * 0.2)
                  - (static_cast<double>(numRedCards) * 0.5);
    } else if (position == "ST" || position == "RW" || position == "LW") {  // Attackers
        rating += (static_cast<double>(playTimeInMinutes) / 90.0 * 0.5)
                  + (static_cast<double>(numGoals) * 0.5)
                  + (static_cast<double>(numAssists) * 0.3)
                  - (static_cast<double>(numYellowCards) * 0.2)
                  - (static_cast<double>(numRedCards) * 0.5);
    } else {
        // Default fallback if position is unknown
        rating += (static_cast<double>(numGoals) * 0.2)
                  + (static_cast<double>(numAssists) * 0.2);
    }

    // Ensure rating stays within a valid range (1.0 to 10.0)
    rating = qBound(1.0, rating, 10.0);

    // Output the calculated rating
    qDebug() << "Calculated rating:" << rating;


    // === Insert a new row for player performance ===
    QSqlQuery insertQuery;
    insertQuery.prepare("INSERT INTO PLAYERPERFORMANCE (PLAYERID, MATCHID, NUMGOALS, NUMASSISTS, NUMSAVES, NUMYELLOWCARDS, "
                        "NUMREDCARDS, PLAYTIMEINMINUTES, TOTALYELLOWCARDS, TOTALREDCARDS, RATE) "
                        "VALUES (:playerId, :matchId, :numGoals, :numAssists, :numSaves, :numYellowCards, :numRedCards, "
                        ":playTimeInMinutes, :totalYellowCards, :totalRedCards, :rate)");

    insertQuery.bindValue(":playerId", playerId);
    insertQuery.bindValue(":matchId", matchId);  // Use the MATCHID we just inserted
    insertQuery.bindValue(":numGoals", numGoals);
    insertQuery.bindValue(":numAssists", numAssists);
    insertQuery.bindValue(":numSaves", numSaves);
    insertQuery.bindValue(":numYellowCards", numYellowCards);
    insertQuery.bindValue(":numRedCards", numRedCards);
    insertQuery.bindValue(":playTimeInMinutes", playTimeInMinutes);
    insertQuery.bindValue(":totalYellowCards", totalYellowCards);
    insertQuery.bindValue(":totalRedCards", totalRedCards);
    insertQuery.bindValue(":rate", rating);

    if (insertQuery.exec()) {
        qDebug() << "New player performance inserted successfully for player" << playerId;

        // After the insert, fetch the MATCHID you just inserted
        QSqlQuery getMatchIdQuery;
        if (getMatchIdQuery.exec("SELECT Match_Seq.CURRVAL FROM DUAL") && getMatchIdQuery.next()) {
            matchId = getMatchIdQuery.value(0).toInt();  // Store the latest MATCHID
            qDebug() << "Inserted match with MATCHID:" << matchId;
        } else {
            qDebug() << "Failed to retrieve MATCHID after insertion:" << getMatchIdQuery.lastError();
        }

        // Fetch the latest performance after insertion to verify
        QSqlQuery fetchPerfQuery;
        fetchPerfQuery.prepare("SELECT MATCHID, NUMYELLOWCARDS, NUMREDCARDS, NUMGOALS, NUMASSISTS, NUMSAVES, PLAYTIMEINMINUTES, RATE "
                               "FROM PLAYERPERFORMANCE "
                               "WHERE PLAYERID = :playerId AND MATCHID = :matchId");

        fetchPerfQuery.bindValue(":playerId", playerId);
        fetchPerfQuery.bindValue(":matchId", matchId);

        if (fetchPerfQuery.exec()) {
            if (fetchPerfQuery.next()) {
                qDebug() << "Fetched Performance for MATCHID:" << fetchPerfQuery.value("MATCHID").toInt()
                << "Goals:" << fetchPerfQuery.value("NUMGOALS").toInt()
                << "Assists:" << fetchPerfQuery.value("NUMASSISTS").toInt()
                << "Saves:" << fetchPerfQuery.value("NUMSAVES").toInt()
                << "Yellows:" << fetchPerfQuery.value("NUMYELLOWCARDS").toInt()
                << "Reds:" << fetchPerfQuery.value("NUMREDCARDS").toInt()
                << "PlayTime:" << fetchPerfQuery.value("PLAYTIMEINMINUTES").toInt()
                << "Rate:" << fetchPerfQuery.value("RATE").toDouble();
            }
        } else {
            qDebug() << "Failed to fetch player performance:" << fetchPerfQuery.lastError().text();
        }
    } else {
        qDebug() << "Error inserting player performance: " << insertQuery.lastError();
    }
}







void Player::checkSuspensionStatus(const QString& firstName, const QString& lastName)
{
    qDebug() << "Checking suspension status for player " << firstName << lastName;

    // Query to get the player ID using the first and last name
    QSqlQuery query;
    query.prepare("SELECT PLAYERID FROM PLAYERS WHERE FNAME = :firstName AND LNAME = :lastName");
    query.bindValue(":firstName", firstName);
    query.bindValue(":lastName", lastName);

    int playerId = -1;
    if (query.exec() && query.next()) {
        playerId = query.value(0).toInt();
        qDebug() << "Player ID for" << firstName << lastName << "is" << playerId;
    } else {
        qDebug() << "Failed to retrieve player ID for" << firstName << lastName << ":" << query.lastError().text();
        return;
    }

    // Query to get the second-to-last match (previous match) based on MATCHID, assuming MATCHID is sequential
    query.prepare("SELECT NUMYELLOWCARDS, NUMREDCARDS "
                  "FROM PLAYERPERFORMANCE "
                  "WHERE PLAYERID = :playerId "
                  "AND MATCHID = (SELECT MAX(MATCHID) - 1 FROM PLAYERPERFORMANCE WHERE PLAYERID = :playerId)");
    query.bindValue(":playerId", playerId);

    int yellowCards = 0;
    int redCards = 0;

    if (query.exec() && query.next()) {
        yellowCards = query.value(0).toInt();
        redCards = query.value(1).toInt();
        qDebug() << "Yellow cards for the previous match: " << yellowCards;
        qDebug() << "Red cards for the previous match: " << redCards;
    } else {
        qDebug() << "Failed to retrieve yellow/red card data for player " << playerId << ": " << query.lastError().text();
        return;
    }

    // Check if the player is suspended based on yellow/red cards from the previous match
    bool isSuspended = false;

    // If the player has a red card or has accumulated 2 yellow cards (which result in a red card)
    if (redCards > 0 || yellowCards == 2) {
        isSuspended = true;
    }

    // Check if the player has 3 or more yellow cards
    if (yellowCards >= 3) {
        isSuspended = true;
    }

    // Log suspension status to console
    if (isSuspended) {
        qDebug() << "Player is suspended due to yellow/red card rules.";
        // Display a message box to notify the user
        QMessageBox::warning(nullptr, "Suspension Status", "Player is suspended due to yellow/red card rules.");
    } else {
        qDebug() << "Player is not suspended.";
        // Display a message box to notify the user
        QMessageBox::information(nullptr, "Suspension Status", "Player is not suspended.");
    }
}

Player Player::getPlayerByNum(int num)
{
    QSqlQuery query;
    query.prepare("SELECT PLAYERID, FNAME, LNAME, PHONENUM, POSITION, STATUS, TEAMID, NUM FROM PLAYERS WHERE NUM = :num");
    query.bindValue(":num", num);

    if (!query.exec()) {
        qDebug() << "Error executing query:" << query.lastError().text();
        return Player(-1, "", "", "", "", "", -1);  // Return an invalid/default player
    }

    if (query.next()) {
        int playerId = query.value("PLAYERID").toInt();
        QString firstName = query.value("FNAME").toString();
        QString lastName = query.value("LNAME").toString();
        QString phoneNumber = query.value("PHONENUM").toString();
        QString position = query.value("POSITION").toString();
        QString status = query.value("STATUS").toString();
        int teamId = query.value("TEAMID").toInt();
        int number = query.value("NUM").toInt();

        return Player(playerId, firstName, lastName, phoneNumber, position, status, teamId, "", number);
    } else {
        qDebug() << "No player found with number:" << num;
        return Player(-1, "", "", "", "", "", -1);
    }
}

bool Player::addPenaltyToPlayer(int penaltyType , int playerID)
{
    QSqlQuery query;

    if ( penaltyType == RED) {
        query.prepare("UPDATE PLAYERPERFORMANCE SET NUMREDCARDS = NUMREDCARDS + 1 WHERE PLAYERID = :playerID");
    } else if ( penaltyType==YELLOW) {
       query.prepare("UPDATE PLAYERPERFORMANCE SET NUMYELLOWCARDS = NUMYELLOWCARDS + 1 WHERE PLAYERID = :playerID");
    }

    query.bindValue(":playerID", playerID);
    if (!query.exec()) {
        qDebug() << "Failed to increment  cards:" << query.lastError().text();
        return false;
    } else {

        qDebug() << " card count incremented for player ID:" << playerID;
        return true;
    }

}



#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QSerialPort>

bool Player::checkAndTriggerBuzzer(int playerID, QSerialPort *serialPort)
{
    QSqlQuery query;
    query.prepare("SELECT NUMYELLOWCARDS, NUMREDCARDS FROM PLAYERPERFORMANCE WHERE PLAYERID = :playerID");
    query.bindValue(":playerID", playerID);

    if (!query.exec()) {
        qDebug() << "Failed to retrieve card counts:" << query.lastError().text();
        return false;
    }

    if (query.next()) {
        int yellowCards = query.value("NUMYELLOWCARDS").toInt();
        int redCards = query.value("NUMREDCARDS").toInt();

        qDebug() << "Yellow:" << yellowCards << " Red:" << redCards;

        if (yellowCards > 3 || redCards > 1) {
            if (serialPort && serialPort->isWritable()) {
                serialPort->write("BUZZ\n"); // Signal to Arduino
                qDebug() << "Buzzer triggered for player ID:" << playerID;
            } else {
                qDebug() << "Serial port not writable";
            }
        } else {
            qDebug() << "Card limits not exceeded, no buzzer.";
        }

        return true;
    } else {
        qDebug() << "No record found for PLAYERID:" << playerID;
        return false;
    }

}
