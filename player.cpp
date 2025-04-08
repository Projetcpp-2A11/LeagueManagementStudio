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
#include "qlabel.h"
#include "qvalueaxis.h"
#include "ui_playerpage.h"
#include <QPrinter>
#include <QFileDialog>
#include <QTextDocument>
#include <QMessageBox>
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

    if (!regex.match(firstName.trimmed()).hasMatch() || firstName.trimmed().size() < 2) {
        QMessageBox::warning(nullptr, "Invalid Input", "Le prénom ne doit contenir que des lettres alphabétiques et doit comporter au moins 2 caractères.");
        return false;
    }

    if (lastName.trimmed().isEmpty() || lastName.trimmed().size() < 2) {
        QMessageBox::warning(nullptr, "Invalid Input", "Last Name must contain at least two letters.");
        return false;
    }

    if (phoneNumber.trimmed().isEmpty()) {
        QMessageBox::warning(nullptr, "Invalid Input", "Phone Number cannot be empty.");
        return false;
    }

    if (phoneNumber.length() != 8 || !phoneNumber.toLongLong()) {
        QMessageBox::warning(nullptr, "Invalid Input", "Phone Number must be an 8-digit number.");
        return false;
    }

    QStringList validPositions = {"GK", "CB", "RB", "LB", "CM", "RM", "LM", "RW", "LW", "ST"};

    if (!validPositions.contains(position)) {
        QMessageBox::warning(nullptr, "Invalid Input", "Position must be one of the following: GK, CB, RB, LB, CM, RM, LM, RW, LW, ST.");
        return false;
    }

    if (status.trimmed().isEmpty() || (status != "en forme" && status != "blessé")) {
        QMessageBox::warning(nullptr, "Invalid Input", "Status must be either 'en forme' or 'blessé'.");
        return false;
    }

    if (selectedTeamId == 0) {
        QMessageBox::warning(nullptr, "Invalid Input", "Please select a valid team.");
        return false;
    }

    // Generate player ID dynamically
    playerId = generatePlayerId();

    // 🆕 Prepare the SQL query including IMG and NUM
    query.prepare("INSERT INTO PLAYERS (PLAYERID, FNAME, LNAME, PHONENUM, POSITION, STATUS, TEAMID, IMG, NUM) "
                  "VALUES (:playerId, :firstName, :lastName, :phoneNumber, :position, :status, :teamId, :img, :num)");

    query.bindValue(":playerId", playerId);
    query.bindValue(":firstName", firstName);
    query.bindValue(":lastName", lastName);
    query.bindValue(":phoneNumber", phoneNumber);
    query.bindValue(":position", position);
    query.bindValue(":status", status);
    query.bindValue(":teamId", selectedTeamId);

    // 🆕 You must make sure `img` and `num` are member variables and properly set
    query.bindValue(":img", img);  // Set this to the file name of the player's image
    query.bindValue(":num", number);  // Set this to the player number (e.g., jersey number)

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













// player.cpp





bool Player::updatePlayerDetails(int playerId, const QString &firstName, const QString &lastName, const QString &position, const QString &status, const QString &phoneNum, int teamID)
{
    QSqlQuery query;

    // Prepare the SQL query to update the player details
    query.prepare("UPDATE PLAYERS SET FNAME = :firstName, LNAME = :lastName, "
                  "POSITION = :position, STATUS = :status, PHONENUM = :phoneNum, TEAMID = :teamID "
                  "WHERE TEAMID = :teamID");

    // Bind the values to the placeholders in the query
    query.bindValue(":firstName", firstName);
    query.bindValue(":lastName", lastName);
    query.bindValue(":position", position);
    query.bindValue(":status", status);
    query.bindValue(":phoneNum", phoneNum);
    query.bindValue(":teamID", teamID);
    query.bindValue(":playerID", playerId);

    // Execute the query and check if it was successful
    if (query.exec()) {
        qDebug() << "Player with teamID" << teamID << "updated successfully.";
        return true;
    } else {
        qDebug() << "Failed to update player with teamID" << teamID << ":" << query.lastError();
        return false;
    }
}

bool Player::updatePlayerUsingTeamID(int playerID, const QString& firstName, const QString& lastName, const QString& position, const QString& status, const QString& phoneNum, int teamID)
{
    QSqlQuery query;

    // Update query to include all fields, and filter by PLAYERID
    query.prepare("UPDATE PLAYERS SET FNAME = :firstName, LNAME = :lastName, POSITION = :position, STATUS = :status, PHONENUM = :phoneNum, TEAMID = :teamID WHERE PLAYERID = :playerID");
    query.bindValue(":firstName", firstName);
    query.bindValue(":lastName", lastName);
    query.bindValue(":position", position);
    query.bindValue(":status", status);
    query.bindValue(":phoneNum", phoneNum);
    query.bindValue(":teamID", teamID);
    query.bindValue(":playerID", playerID);  // Bind the playerID to the query

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
    table->clearContents();  // Clear existing table contents
    table->setRowCount(0);   // Reset row count
    table->verticalHeader()->setVisible(false);  // Hide vertical header

    // Query to retrieve players sorted by first name and last name
    QString queryStr = "SELECT PLAYERID, FNAME, LNAME, PHONENUM, POSITION, STATUS, TEAMID FROM PLAYERS ORDER BY FNAME ASC";
    QSqlQuery query;

    if (query.exec(queryStr)) {
        int row = 0;
        while (query.next()) {
            table->insertRow(row);

            //table->setItem(row, 0, new QTableWidgetItem(query.value(0).toString()));  // PLAYERID
            table->setItem(row, 0, new QTableWidgetItem(query.value(1).toString()));  // FNAME
            table->setItem(row, 1, new QTableWidgetItem(query.value(2).toString()));  // LNAME
           // table->setItem(row, 3, new QTableWidgetItem(query.value(3).toString()));  // PHONENUM
            table->setItem(row, 2, new QTableWidgetItem(query.value(4).toString()));  // POSITION
            table->setItem(row, 3, new QTableWidgetItem(query.value(5).toString()));  // STATUS
            table->setItem(row, 4, new QTableWidgetItem(query.value(6).toString()));  // TEAMID

            table->setRowHeight(row, 60);  // Ensure row height consistency

            ++row;
        }

        // Ensure column width consistency
        table->setColumnWidth(6, 250);

        // Add buttons to each row after populating the table
        //addButtonsToRows(table);
    } else {
        qDebug() << "Failed to fetch sorted data: " << query.lastError();
    }
}


void Player::searchPlayers(const QString &searchTerm, QTableWidget *tableWidget)
{
    QSqlQuery query;
    query.prepare("SELECT  FNAME, LNAME, POSITION, STATUS, TEAMID FROM Players WHERE FNAME LIKE :searchTerm OR LNAME LIKE :searchTerm");
    query.bindValue(":searchTerm", "%" + searchTerm + "%");

    if (query.exec()) {
        tableWidget->setRowCount(0); // Clear previous search results

        while (query.next()) {
            int rowCount = tableWidget->rowCount();
            tableWidget->insertRow(rowCount);

            for (int i = 0; i < 5; i++) {  // Adjust the loop to only loop through 6 columns (excluding PHONENUM)
                tableWidget->setItem(rowCount, i, new QTableWidgetItem(query.value(i).toString()));
            }

            tableWidget->setRowHeight(rowCount, 60);  // Ensure row height consistency
        }

        // Ensure column width consistency
        tableWidget->setColumnWidth(5, 250); // Adjust based on the last column (TEAMID)
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



void Player::updatePlayerPerformance(const QString& firstName, const QString& lastName)
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

    // Fetch current performance stats
    int currentGoals = 0;
    int currentAssists = 0;
    int currentSaves = 0;
    int currentYellowCards = 0;
    int currentRedCards = 0;
    int currentPlayTimeInMinutes = 0;

    QSqlQuery fetchQuery;
    fetchQuery.prepare("SELECT NUMGOALS, NUMASSISTS, NUMSAVES, NUMYELLOWCARDS, NUMREDCARDS, PLAYTIMEINMINUTES FROM PLAYERPERFORMANCE WHERE PLAYERID = :playerId");
    fetchQuery.bindValue(":playerId", playerId);

    if (fetchQuery.exec() && fetchQuery.next()) {
        currentGoals = fetchQuery.value("NUMGOALS").toInt();
        currentAssists = fetchQuery.value("NUMASSISTS").toInt();
        currentSaves = fetchQuery.value("NUMSAVES").toInt();
        currentYellowCards = fetchQuery.value("NUMYELLOWCARDS").toInt();
        currentRedCards = fetchQuery.value("NUMREDCARDS").toInt();
        currentPlayTimeInMinutes = fetchQuery.value("PLAYTIMEINMINUTES").toInt();
    }

    // New stats based on position
    int numGoals = 0;
    int numAssists = 0;
    int numSaves = 0;
    int numYellowCards = 0;
    int numRedCards = 0;
    int playTimeInMinutes = 0;

    // Assign new values based on the player's position
    if (position == "ST" || position == "RW" || position == "LW") {
        numGoals = QRandomGenerator::global()->bounded(1, 15);
        numAssists = QRandomGenerator::global()->bounded(0, 5);
        numYellowCards = QRandomGenerator::global()->bounded(0, 5);
        numRedCards = QRandomGenerator::global()->bounded(0, 1);
        playTimeInMinutes = QRandomGenerator::global()->bounded(540, 990);
    } else if (position == "CM" || position == "LM" || position == "RM") {
        numGoals = QRandomGenerator::global()->bounded(0, 5);
        numAssists = QRandomGenerator::global()->bounded(1, 7);
        numYellowCards = QRandomGenerator::global()->bounded(0, 4);
        numRedCards = QRandomGenerator::global()->bounded(0, 1);
        playTimeInMinutes = QRandomGenerator::global()->bounded(540, 990);
    } else if (position == "CB" || position == "RB" || position == "LB") {
        numGoals = QRandomGenerator::global()->bounded(0, 3);
        numAssists = QRandomGenerator::global()->bounded(0, 5);
        numYellowCards = QRandomGenerator::global()->bounded(0, 5);
        numRedCards = QRandomGenerator::global()->bounded(0, 2);
        playTimeInMinutes = QRandomGenerator::global()->bounded(540, 990);
    } else if (position == "GK") {
        numSaves = QRandomGenerator::global()->bounded(20, 36);
        numYellowCards = QRandomGenerator::global()->bounded(0, 2);
        numRedCards = QRandomGenerator::global()->bounded(0, 1);
        playTimeInMinutes = QRandomGenerator::global()->bounded(540, 990);
    }

    // Ensure the new stats are greater than the current ones
    numGoals += currentGoals;
    numAssists += currentAssists;
    numSaves += currentSaves;
    numYellowCards += currentYellowCards;
    numRedCards += currentRedCards;
    playTimeInMinutes += currentPlayTimeInMinutes;

    qDebug() << "Stats - Goals:" << numGoals << ", Assists:" << numAssists << ", Saves:" << numSaves
             << ", Yellow Cards:" << numYellowCards << ", Red Cards:" << numRedCards
             << ", Play Time:" << playTimeInMinutes << "minutes";

    // Update PLAYERPERFORMANCE table
    QSqlQuery updateQuery;
    updateQuery.prepare("UPDATE PLAYERPERFORMANCE SET NUMGOALS = :numGoals, NUMASSISTS = :numAssists, NUMSAVES = :numSaves, "
                        "NUMYELLOWCARDS = :numYellowCards, NUMREDCARDS = :numRedCards, PLAYTIMEINMINUTES = :playTimeInMinutes "
                        "WHERE PLAYERID = :playerId");

    updateQuery.bindValue(":numGoals", numGoals);
    updateQuery.bindValue(":numAssists", numAssists);
    updateQuery.bindValue(":numSaves", numSaves);
    updateQuery.bindValue(":numYellowCards", numYellowCards);
    updateQuery.bindValue(":numRedCards", numRedCards);
    updateQuery.bindValue(":playTimeInMinutes", playTimeInMinutes);
    updateQuery.bindValue(":playerId", playerId);

    if (!updateQuery.exec()) {
        qDebug() << "Error updating performance for player " << playerId << ": " << updateQuery.lastError().text();
    } else {
        qDebug() << "Player performance updated successfully for player " << playerId;
    }
}







