#include "stadium.h"
//#include "staduimpage.h"
#include "qboxlayout.h"
#include "qcontainerfwd.h"
#include "qheaderview.h"
#include "qpushbutton.h"
#include "qsqlerror.h"
#include <QMessageBox>
#include <QPrinter>
#include <QPainter>
#include <QFileDialog>
#include <QDateTime>
#include <QDebug>
#include <QtCharts/QPieSeries>
#include <QtCharts/QChartView>
#include <QSqlQuery>
#include <QSqlError>
#include <QVBoxLayout>
#include <QDialog>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QNetworkRequest>
#include <QLineEdit>



int Stadium::getStadiumID() const
{
    return id;
}

void Stadium::setStadiumID(int newStadiumID)
{
    id = newStadiumID;
}

QString Stadium::getName() const
{
    return name;
}

void Stadium::setName(const QString &newName)
{
    name = newName;
}

QString Stadium::getAddress() const
{
    return address;
}

void Stadium::setAddress(const QString &newAddress)
{
    address = newAddress;
}

int Stadium::getCapacity() const
{
    return capacity;
}

void Stadium::setCapacity(int newCapacity)
{
    capacity = newCapacity;
}

QString Stadium::getStatus() const {
    return status;
}

void Stadium::setStatus(const QString &newStatus) {
    status = newStatus;
}


Stadium::Stadium() {}

Stadium::Stadium(const QString &name, const QString &address, int capacity, const QString &status):
    name(name),
    address(address),
    capacity(capacity),
    status(status)

{}

#include <QMessageBox>

bool Stadium::addStadium() {

    // Préparer la requête SQL
    QSqlQuery query;
    query.prepare("INSERT INTO Stadium (name, address, capacity, status) "
                  "VALUES (:name, :address, :capacity, :status)");

    query.bindValue(":name", name);
    query.bindValue(":address", address);
    query.bindValue(":capacity", capacity);
    query.bindValue(":status", status);

    // Exécuter la requête
    if (query.exec()) {
        qDebug() << "Stadium added successfully!";
        return true;
    } else {
        qDebug() << "Error adding stadium:" << query.lastError().text();
        QMessageBox::critical(nullptr, "Erreur", "Échec de l'ajout du stade: " + query.lastError().text());
        return false;
    }
}


void Stadium::listStadiums(QTableWidget* table)
{
    table->clearContents();
    table->setRowCount(0);
    table->verticalHeader()->setVisible(false);

    QString queryStr = "SELECT  STADIUMID, NAME, ADDRESS, CAPACITY ,STATUS FROM STADIUM";
    QSqlQuery query;

    if (query.exec(queryStr)) {
        int row = 0;
        while (query.next()) {
            table->insertRow(row);
            table->setItem(row, 0, new QTableWidgetItem(query.value(0).toString()));
            table->setItem(row, 1, new QTableWidgetItem(query.value(1).toString()));
            table->setItem(row, 2, new QTableWidgetItem(query.value(2).toString()));
            table->setItem(row, 3, new QTableWidgetItem(query.value(3).toString()));
            table->setItem(row, 4, new QTableWidgetItem(query.value(4).toString()));
            table->setColumnWidth(5, 200);
            table->setRowHeight(row, 60);



            ++row;
        }
    } else {
        qDebug() << "Failed to fetch data: " << query.lastError();
    }
}

bool Stadium::updateStadium(int stadiumID, const QString &newName, const QString &newAddress, int newCapacity, const QString &newStatus)
{
    QSqlQuery query;

    // Prepare the SQL query to update the stadium details
    query.prepare("UPDATE stadium SET NAME = :newName, ADDRESS = :newAddress, CAPACITY = :newCapacity, STATUS = :newStatus WHERE STADIUMID = :stadiumID");

    // Bind the values to the placeholders in the query
    query.bindValue(":newName", newName);
    query.bindValue(":newAddress", newAddress);
    query.bindValue(":newCapacity", newCapacity);
    query.bindValue(":newStatus", newStatus);
    query.bindValue(":stadiumID", stadiumID);

    if (query.exec()) {
        qDebug() << "stadium with id" << stadiumID << "updated successfully.";
        return true;
    } else {
        qDebug() << "Failed to update stadium with id" << stadiumID << ":" << query.lastError();
        return false;
    }
}
bool Stadium::deleteStadium(int id)
{
    QSqlQuery query;
    query.prepare("DELETE FROM Stadium WHERE STADIUMID = :id");
    query.bindValue(":id", id);

    if (query.exec()) {
        qDebug() << "Stadium with ID" << id << "deleted successfully!";
        return true;
    } else {
        qDebug() << "Error deleting stadium:" << query.lastError().text();
        return false;
    }
}

bool Stadium::searchStadiums(const QString &searchText, QTableWidget *tableWidget)
{
    QSqlQuery query;
    query.prepare("SELECT STADIUMID, NAME, ADDRESS, CAPACITY, STATUS FROM STADIUM WHERE NAME LIKE :searchText OR ADDRESS LIKE :searchText");
    query.bindValue(":searchText", "%" + searchText + "%"); // Partial search

    if (!query.exec()) {
        qDebug() << "Search failed: " << query.lastError().text();
        return false;
    }

    // Clear table and reset row count
    tableWidget->clearContents();
    tableWidget->setRowCount(0);
    tableWidget->verticalHeader()->setVisible(false);

    int row = 0;
    while (query.next()) {
        tableWidget->insertRow(row);
        for (int col = 0; col < 5; col++) {
            tableWidget->setItem(row, col, new QTableWidgetItem(query.value(col).toString()));
        }
        row++;
    }

    return true;
}

bool Stadium::filterStadiums(int index, QTableWidget *tableWidget) {
    QString queryStr;

    switch (index) {
    case 1:
        queryStr = "SELECT STADIUMID, NAME, ADDRESS, CAPACITY, STATUS FROM STADIUM ORDER BY NAME ";
        break;
    case 2:
        queryStr = "SELECT STADIUMID, NAME, ADDRESS, CAPACITY, STATUS FROM STADIUM ORDER BY NAME DESC";
        break;
    case 3:
        queryStr = "SELECT STADIUMID, NAME, ADDRESS, CAPACITY, STATUS FROM STADIUM ORDER BY CAPACITY ASC";
        break;
    case 4:
        queryStr = "SELECT STADIUMID, NAME, ADDRESS, CAPACITY, STATUS FROM STADIUM ORDER BY CAPACITY DESC";
        break;
    default:
        qDebug() << "Invalid filter option selected!";
        return false;  // No valid filter
    }

    QSqlQuery query;
    if (!query.exec(queryStr)) {
        qDebug() << "Sorting failed:" << query.lastError().text();
        return false;
    }

    // ✅ Clear the table before adding new results
    tableWidget->clearContents();
    tableWidget->setRowCount(0);
    tableWidget->verticalHeader()->setVisible(false);

    int row = 0;
    while (query.next()) {
        tableWidget->insertRow(row);
        tableWidget->setItem(row, 0, new QTableWidgetItem(query.value(0).toString())); // Stadium ID
        tableWidget->setItem(row, 1, new QTableWidgetItem(query.value(1).toString())); // Name
        tableWidget->setItem(row, 2, new QTableWidgetItem(query.value(2).toString())); // Address
        tableWidget->setItem(row, 3, new QTableWidgetItem(query.value(3).toString())); // Capacity
        tableWidget->setItem(row, 4, new QTableWidgetItem(query.value(4).toString())); // Status

        row++;
    }

    return true; // ✅ Sorting applied successfully
}
#include <QTextDocument>
#include <QPrinter>
#include <QFileDialog>
#include <QDesktopServices>
#include <QUrl>
void Stadium::exportListToPDF(QTableWidget *tableWidget, const QString &fileName) {
    if (tableWidget->rowCount() == 0) {
        qDebug() << "Table is empty, nothing to export.";
        return;
    }

    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(fileName);
    printer.setPageMargins(QMarginsF(15, 15, 15, 15));

    QPainter painter(&printer);

    int rowCount = tableWidget->rowCount();
    int colCount = tableWidget->columnCount() - 1;  // Exclude last column if needed

    int startX = 20;
    int startY = 100;
    int cellWidth = 100;
    int cellHeight = 30;

    // Title
    painter.setFont(QFont("Helvetica", 16, QFont::Bold));
    painter.drawText(startX, 60, "🏟️ Stadium List Export");

    // Header Styling
    painter.setFont(QFont("Arial", 10, QFont::Bold));
    painter.setBrush(QColor("#1976d2")); // Blue background
    painter.setPen(Qt::white);

    for (int col = 0; col < colCount; ++col) {
        QRect rect(startX + col * cellWidth, startY, cellWidth, cellHeight);
        painter.drawRect(rect);
        painter.drawText(rect, Qt::AlignCenter, tableWidget->horizontalHeaderItem(col)->text());
    }

    // Table Content
    painter.setFont(QFont("Arial", 9));
    for (int row = 0; row < rowCount; ++row) {
        for (int col = 0; col < colCount; ++col) {
            QRect rect(startX + col * cellWidth, startY + (row + 1) * cellHeight, cellWidth, cellHeight);

            // Alternate row background color
            painter.setBrush((row % 2 == 0) ? QColor("#f1f1f1") : Qt::white);
            painter.setPen(Qt::black);
            painter.drawRect(rect);

            if (tableWidget->item(row, col)) {
                painter.drawText(rect.adjusted(3, 0, -3, 0), Qt::AlignVCenter | Qt::AlignLeft,
                                 tableWidget->item(row, col)->text());
            }
        }
    }

    painter.end();
    qDebug() << "PDF successfully exported to:" << fileName;
    QDesktopServices::openUrl(QUrl::fromLocalFile(fileName));


}

void Stadium::showStadiumStatusChart(QTableWidget *tableWidget) {
    if (!tableWidget) {
        qDebug() << "Table widget is null!";
        return;
    }

    QMap<QString, int> statusCounts;

    // Get status column index (Assuming it's the second to last column)
    int statusColumn = tableWidget->columnCount() - 2;
    int rowCount = tableWidget->rowCount();

    // Count stadiums by status
    for (int row = 0; row < rowCount; ++row) {
        if (tableWidget->item(row, statusColumn)) {
            QString status = tableWidget->item(row, statusColumn)->text();
            statusCounts[status]++;
        }
    }

    // Total count
    int total = 0;
    for (auto count : statusCounts.values()) {
        total += count;
    }

    // Create the pie chart with percentage labels
    QPieSeries *series = new QPieSeries();
    for (auto it = statusCounts.begin(); it != statusCounts.end(); ++it) {
        double percentage = (double(it.value()) / total) * 100;
        QString label = QString("%1: %2 (%3%)")
                            .arg(it.key())
                            .arg(it.value())
                            .arg(QString::number(percentage, 'f', 1));
        series->append(label, it.value());
    }

    // Optional: Make labels visible directly on the pie chart
    for (QPieSlice *slice : series->slices()) {
        slice->setLabelVisible(true);
    }

    // Customize the chart
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Stadium Status Distribution");
    chart->legend()->setAlignment(Qt::AlignBottom);

    // Create the chart view
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    // Show the chart in a new window
    QDialog *chartDialog = new QDialog();
    QVBoxLayout *layout = new QVBoxLayout(chartDialog);
    layout->addWidget(chartView);
    chartDialog->setLayout(layout);
    chartDialog->resize(600, 400);
    chartDialog->exec();
}

void Stadium::showTopStadiumsByCapacity(QTableWidget *tableWidget) {
    if (!tableWidget || tableWidget->rowCount() == 0) {
        qDebug() << "Table is empty or invalid.";
        return;
    }

    // **Extract stadium names and capacities**
    QVector<QPair<QString, int>> stadiums;
    for (int row = 0; row < tableWidget->rowCount(); ++row) {
        if (tableWidget->item(row, 0) && tableWidget->item(row, 3)) {  // Ensure items exist
            QString name = tableWidget->item(row, 0)->text().trimmed();
            int capacity = tableWidget->item(row, 3)->text().toInt();
            stadiums.append(qMakePair(name, capacity));
        }
    }

    // **Sort in descending order (highest capacity first)**
    std::sort(stadiums.begin(), stadiums.end(), [](const QPair<QString, int> &a, const QPair<QString, int> &b) {
        return a.second > b.second;
    });

    // **Take top 5 stadiums**
    QVector<QString> categories;
    QBarSet *set = new QBarSet("Capacity");
    int count = qMin(5, stadiums.size());
    for (int i = 0; i < count; ++i) {
        categories.append(stadiums[i].first);
        *set << stadiums[i].second;
    }
    for (const auto &stadium : stadiums) {
        qDebug() << "Stadium:" << stadium.first << "Capacity:" << stadium.second;
    }


    // **Create Bar Chart**
    QBarSeries *series = new QBarSeries();
    series->append(set);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Top 5 Stadiums by Capacity");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    // **X-Axis (Stadium Names)**
    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    // **Y-Axis (Capacity)**
    QValueAxis *axisY = new QValueAxis();
    axisY->setTitleText("Capacity");
    // Determine max capacity
    int maxCapacity = 0;
    for (const auto &stadium : stadiums) {
        maxCapacity = qMax(maxCapacity, stadium.second);
    }

    // Adjust Y-Axis dynamically
    axisY->setRange(0, maxCapacity + (maxCapacity * 0.1));  // Add 10% padding
    axisY->setLabelFormat("%d");  // Format as integers
    axisY->setTickCount(6);  // Ensure multiple ticks for better readability
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    // **Display in a Dialog**
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    QDialog *dialog = new QDialog();
    QVBoxLayout *layout = new QVBoxLayout(dialog);
    layout->addWidget(chartView);

    dialog->setMinimumSize(600, 400);
    dialog->exec();
}

void Stadium::generatePdfReport(const QString &stadiumName, const QString &address, const QString &status,
                                const QString &date, const QString &weather, const QString &decision, QWidget *parent) {
    QTextDocument doc;

    QString html = R"(
        <html>
        <head>
        <style>
            body { font-family: 'Arial'; padding: 20px; }
            h1 { color: #2E8B57; }
            p { font-size: 14px; }
            .label { font-weight: bold; }
            .good { color: green; }
            .bad { color: red; }
            .container { border: 1px solid #ccc; border-radius: 8px; padding: 20px; background: #f9f9f9; }
        </style>
        </head>
        <body>
        <div class='container'>
            <h1>Stadium Practicality Report</h1>
            <p><span class='label'>Stadium:</span> %1</p>
            <p><span class='label'>Address:</span> %2</p>

            <p><span class='label'>Match Date:</span> %4</p>
            <p><span class='label'>Weather:</span> %5</p>
            <p><span class='label'>Decision:</span> <span class='%6'>%7</span></p>
            <p><span class='label'>Status:</span> %3</p>
        </div>
        </body>
        </html>
    )";

    QString styled = html.arg(
        stadiumName,
        address,
        status,
        date,
        weather,
        (decision.contains("Not") ? "bad" : "good"),
        decision
        );

    doc.setHtml(styled);

    QString filePath = QFileDialog::getSaveFileName(parent, "Save Report", "", "PDF Files (*.pdf)");
    if (filePath.isEmpty()) return;

    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(filePath);
    printer.setPageMargins(QMarginsF(15, 15, 15, 15));
    doc.print(&printer);

    QDesktopServices::openUrl(QUrl::fromLocalFile(filePath));
}


bool Stadium::isStadiumAvailable(int stadiumID) {
    QSqlQuery query;
    query.prepare("SELECT STATUS FROM STADIUM WHERE STADIUMID = :stadiumID");
    query.bindValue(":stadiumID", stadiumID);

    if (!query.exec()) {
        qDebug() << "Database error: " << query.lastError().text();
        return false;
    }

    if (query.next()) {
        QString status = query.value(0).toString();
        return (status == "available"); // If the stadium status is "Open", it's available
    }

    return false; // Stadium not found
}

QString Stadium::getWeatherForDate(const QDate &date, const QString &location) {
    QNetworkAccessManager manager;

    // ✅ Your API key for OpenWeatherMap
    QString apiKey = "2507821a1d91fadd915c4e4eba7cb6ad";

    // Build the URL for current weather by city name
    QUrl url(QString("https://api.openweathermap.org/data/2.5/weather?q=%1&appid=%2")
                 .arg(location, apiKey));

    QNetworkRequest request(url);
    QNetworkReply *reply = manager.get(request);

    // Use event loop to wait synchronously for the response
    QEventLoop loop;
    QObject::connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();

    // Error handling
    if (reply->error() != QNetworkReply::NoError) {
        qDebug() << "Network error:" << reply->errorString();
        reply->deleteLater();
        return "Condition: Unknown | Temperature: 100";
    }

    QByteArray data = reply->readAll();
    qDebug() << "API Response:" << data;
    reply->deleteLater();

    QJsonParseError parseError;
    QJsonDocument jsonResponse = QJsonDocument::fromJson(data, &parseError);
    if (parseError.error != QJsonParseError::NoError) {
        qDebug() << "JSON parse error:" << parseError.errorString();
        return "Condition: Unknown | Temperature: 100";
    }

    QJsonObject jsonObject = jsonResponse.object();

    // Check and extract weather and temperature info
    if (!jsonObject.contains("weather") || !jsonObject.contains("main")) {
        qDebug() << "Missing weather or temperature in response";
        return "Condition: Unknown | Temperature: 100";
    }

    QString condition = jsonObject["weather"].toArray()[0].toObject()["description"].toString();
    double temperatureKelvin = jsonObject["main"].toObject()["temp"].toDouble();
    double temperatureCelsius = temperatureKelvin - 273.15; // Convert from Kelvin to Celsius

    return QString("Condition: %1 | Temperature: %2°C")
        .arg(condition)
        .arg(QString::number(temperatureCelsius, 'f', 1));
}


#include <QRegularExpression>


void Stadium::checkStadiumPracticality(int stadiumID, const QDate &matchDate, QWidget *parent) {
    QString stadiumName = "";
    QString location = "unknown";
    QString condition = "Unknown";
    double temperature = 100.0;
    QString status = "Unknown";
    QString reason = "";

    // Check stadium availability
    if (!isStadiumAvailable(stadiumID)) {
        QMessageBox::warning(parent, "Stadium Not Practical", "The stadium is not available.");
        status = "Unavailable";
        reason = "Stadium not available";
    } else {
        // Get stadium name and address
        QSqlQuery query;
        query.prepare("SELECT ADDRESS, NAME FROM STADIUM WHERE STADIUMID = :id");
        query.bindValue(":id", stadiumID);

        if (!query.exec()) {
            QMessageBox::warning(parent, "Error", "Database query error.");
            reason = "Database error";
        } else if (query.next()) {
            location = query.value(0).toString();
            stadiumName = query.value(1).toString();

            // Get weather
            QString weatherCondition = getWeatherForDate(matchDate, location);

            // Extract condition and temperature
            QRegularExpression regex("Condition:\\s*(.+)\\s*\\|\\s*Temperature:\\s*(-?\\d+(\\.\\d+)?)");
            QRegularExpressionMatch match = regex.match(weatherCondition);
            if (match.hasMatch()) {
                condition = match.captured(1);
                temperature = match.captured(2).toDouble();
            }

            bool badWeather = condition.contains("Rain", Qt::CaseInsensitive) ||
                              condition.contains("Storm", Qt::CaseInsensitive) ||
                              condition.contains("Snow", Qt::CaseInsensitive) ||
                              temperature < 0;

            if (badWeather) {
                reason = temperature < 0 ? "Too cold" : "Bad weather";
                status = "Not Practical";
                QMessageBox::warning(parent, "Stadium Not Practical",
                                     reason + " detected in " + location + ": " +
                                         condition + " (" + QString::number(temperature) + "°C)");
            } else {
                status = "Practical";
                reason = "Stadium and weather conditions are acceptable";
                QMessageBox::information(parent, "Stadium Practical",
                                         "Stadium '" + stadiumName + "' is available and the weather in " + location +
                                             " is fine on " + matchDate.toString("dd/MM/yyyy") + ".");
            }
        } else {
            QMessageBox::warning(parent, "Error", "Could not find the stadium address.");
            reason = "Stadium not found in database";
        }
    }

    // Generate the PDF report in all cases
    generatePdfReport(stadiumName, location, status,
                      matchDate.toString("dd/MM/yyyy"),
                      QString("%1 (%2°C)").arg(condition).arg(temperature),
                      reason, parent);
}
#include <QSet>
#include <QRandomGenerator>
#include <QLayoutItem>
#include <QtMath>

#include <QSet>
#include <QRandomGenerator>
#include <QLayoutItem>
#include <QtMath>
#include <algorithm> // for std::shuffle

// Helper function to determine people per square
int Stadium::calculatePeoplePerSquare(int capacity)
{
    // Validate input
    capacity = qMax(1, capacity); // Ensure minimum capacity of 1

    // Detailed scaling tiers with explanations
    int peoplePerSquare;
    QString sizeCategory;

    if (capacity <= 500) {         // Small clubs/theaters
        peoplePerSquare = 1;
        sizeCategory = "Small Venue (1:1)";
    }
    else if (capacity <= 2000) {   // Medium clubs/small arenas
        peoplePerSquare = 2;
        sizeCategory = "Club (1:2)";
    }
    else if (capacity <= 5000) {    // Large clubs/medium arenas
        peoplePerSquare = 5;
        sizeCategory = "Arena (1:5)";
    }
    else if (capacity <= 15000) {   // Small stadiums
        peoplePerSquare = 10;
        sizeCategory = "Stadium (1:10)";
    }
    else if (capacity <= 35000) {  // Medium stadiums
        peoplePerSquare = 20;
        sizeCategory = "Mid Stadium (1:20)";
    }
    else if (capacity <= 70000) {  // Large stadiums
        peoplePerSquare = 35;
        sizeCategory = "Large Stadium (1:35)";
    }
    else {                         // Mega stadiums
        peoplePerSquare = qBound(50, capacity/1400, 200); // Dynamic scaling for huge venues
        sizeCategory = QString("Mega Stadium (1:%1)").arg(peoplePerSquare);
    }

    return peoplePerSquare;
}

QString Stadium::getStadiumNameById(int id)
{
    QSqlQuery query;
    query.prepare("SELECT NAME FROM STADIUM WHERE STADIUMID= :id");
    query.bindValue(":id", id);
    if (!query.exec()) {
        qDebug("No stadium Found");
        return "";
    } else if ( query.next() ){
        return query.value(0).toString();

    }




}


void Stadium::checkMatchAndShowSeats(const QString &matchIDRaw, QWidget *topWidget, QWidget *bottomWidget,
                                     QWidget *leftWidget, QWidget *rightWidget, QLineEdit *attendanceLabel,
                                     QLineEdit *matchider)
{
    // 1. Initial Validation
    if (!topWidget || !bottomWidget || !leftWidget || !rightWidget || !attendanceLabel || !matchider) {
        qDebug() << "Error: Null widget passed";
        return;
    }

    QString matchID = matchIDRaw.trimmed();
    if (matchID.isEmpty()) {
        matchider->setText("Error: Empty Match ID");
        return;
    }

    // 2. Database Query
    QSqlQuery query;
    query.prepare("SELECT STADIUMID, ATTENDANCE FROM MATCHES WHERE MATCHID = :matchID");

    bool ok;
    int matchIDInt = matchID.toInt(&ok);
    query.bindValue(":matchID", ok ? QVariant(matchIDInt) : QVariant(matchID)); // FIXED: Using QVariant for type consistency

    if (!query.exec()) {
        matchider->setText("Database Error");
        qDebug() << "Query error:" << query.lastError().text();
        return;
    }

    if (!query.next()) {
        matchider->setText("Match Not Found");
        return;
    }

    int stadiumID = query.value("STADIUMID").toInt();
    int attendance = query.value("ATTENDANCE").toInt();

    // 3. Get Stadium Capacity
    QSqlQuery stadiumQuery;
    stadiumQuery.prepare("SELECT CAPACITY FROM STADIUM WHERE STADIUMID = :stadiumID");
    stadiumQuery.bindValue(":stadiumID", stadiumID);

    if (!stadiumQuery.exec() || !stadiumQuery.next()) {
        qDebug() << "Stadium query failed:" << stadiumQuery.lastError().text();
        matchider->setText("Invalid Stadium");
        return;
    }

    int capacity = stadiumQuery.value("CAPACITY").toInt();

    // Validate data
    capacity = qMax(1, capacity);
    attendance = qBound(0, attendance, capacity);

    // 4. Calculate Visualization Parameters
    int peoplePerSquare = calculatePeoplePerSquare(capacity);

    const int sections = 4;
    int sectionCapacity = qCeil(capacity / static_cast<double>(sections));
    int baseAttendance = attendance / sections;
    int remaining = attendance % sections;

    // 5. Generate Seat Grids
    auto generateSection = [&](QWidget* widget, int extra) {
        int sectionPeople = baseAttendance + extra;
        generateSeatGrid(20, 20, peoplePerSquare, sectionCapacity, sectionPeople, widget);
    };

    generateSection(topWidget,    remaining > 0 ? 1 : 0);
    generateSection(bottomWidget, remaining > 1 ? 1 : 0);
    generateSection(leftWidget,   remaining > 2 ? 1 : 0);
    generateSection(rightWidget,  0);

    // 6. Update UI Labels
    attendanceLabel->setText(QString("Attendance: %1/%2 (Avg %3 people/seat)")
                                 .arg(attendance)
                                 .arg(capacity)
                                 .arg(peoplePerSquare));
    matchider->clear();
}

void Stadium::generateSeatGrid(int rows, int cols, int peoplePerSquare, int totalPeople,
                               int occupiedPeople, QWidget *seatGridWidget)
{
    if (!seatGridWidget || rows <= 0 || cols <= 0) return;

    // Clean old layout
    QLayout *oldLayout = seatGridWidget->layout();
    if (oldLayout) {
        QLayoutItem *item;
        while ((item = oldLayout->takeAt(0)) != nullptr) {
            if (item->widget()) item->widget()->deleteLater();
            delete item;
        }
        delete oldLayout;
    }

    // Create new layout
    QGridLayout *gridLayout = new QGridLayout(seatGridWidget);
    gridLayout->setSpacing(1);
    gridLayout->setContentsMargins(1, 1, 1, 1);

    const int totalSquares = rows * cols;
    const int maxRepresentablePeople = totalSquares * peoplePerSquare;
    occupiedPeople = qMin(occupiedPeople, maxRepresentablePeople);

    // Calculate how many squares to fill (at least 1 person per square)
    const int squaresToFill = qCeil(static_cast<double>(occupiedPeople) / peoplePerSquare);
    const int fullSquares = occupiedPeople / peoplePerSquare;
    const int remainingPeople = occupiedPeople % peoplePerSquare;

    // Create and shuffle indices for random distribution
    QVector<int> allIndices;
    allIndices.reserve(totalSquares);
    for (int i = 0; i < totalSquares; ++i) {
        allIndices.append(i);
    }
    std::shuffle(allIndices.begin(), allIndices.end(), *QRandomGenerator::global());
    int greenSquaresPlaced = 0;

    // Mark which squares are occupied
    QHash<int, int> squareOccupancy; // key: index, value: people in square
    for (int i = 0; i < squaresToFill; ++i) {
        const int people = (i < fullSquares) ? peoplePerSquare :
                               (i == fullSquares ? remainingPeople : 0);
        if (people > 0) {
            greenSquaresPlaced++;

            squareOccupancy[allIndices[i]] = people;
        }
    }
    // Create the visual grid
    for (int i = 0; i < totalSquares; ++i) {
        QLabel *seat = new QLabel(seatGridWidget);
        seat->setFixedSize(12, 12); // Smaller size for 20x20 grid
        seat->setAlignment(Qt::AlignCenter);

        if (squareOccupancy.contains(i)) {
            const int people = squareOccupancy[i];
            seat->setToolTip(QString("%1 people").arg(people));

            // Different green shades based on occupancy density
            const int darkness = 200 - (150 * people/peoplePerSquare);
            seat->setStyleSheet(QString(
                                    "background-color: rgb(%1, 255, %1);"
                                    "border: 1px solid #555;"
                                    "border-radius: 2px;"
                                    ).arg(darkness));
        } else {
            seat->setStyleSheet(
                "background-color: #ffcccc;"
                "border: 1px solid #555;"
                "border-radius: 2px;"
                );
        }

        gridLayout->addWidget(seat, i / cols, i % cols);
    }
    // Debug output after placement
    qDebug() << "Actually placed" << greenSquaresPlaced << "green squares";
    qDebug() << "Grid breakdown:";
    qDebug() << "- Full squares:" << fullSquares << "(@" << peoplePerSquare << "people each)";
    qDebug() << "- Partial square:" << (remainingPeople > 0 ? 1 : 0) << "(@" << remainingPeople << "people)";
    qDebug() << "- Empty squares:" << (totalSquares - greenSquaresPlaced);
}
