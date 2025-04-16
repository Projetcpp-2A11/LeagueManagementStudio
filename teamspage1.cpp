#include "teamspage1.h"
#include "ui_teamspage1.h"
#include <QMessageBox>
#include <QVBoxLayout>
#include <QTableWidget>
#include <QPushButton>
#include <connection.h>
#include <teams.h>
#include <QTimer>
#include <QFileInfo>
#include <QFileDialog>
#include <QPrinter>
#include <QPainter>
#include <QPageLayout>
#include <QFileDialog>
#include <QSqlRecord>
#include <QRegularExpressionValidator>
#include <QRegularExpression>
#include "teamtypeform.h"
#include <QUiLoader>
#include <QFile>
#include <QBuffer>


teamsPage::teamsPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::teamsPage)
{
    ui->setupUi(this);
    setMinimumSize(1000, 800);
    resize(800, 600);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(ui->listTeams);
    setLayout(layout);

    teams team;
    refresh();
    setupTeamsTable();
    team.listTeams(ui->listTeams);
    addButtonsToRows(ui->listTeams);

    QRegularExpression regex("[^0-9]+");
    QRegularExpressionValidator *validator = new QRegularExpressionValidator(regex, this);
    ui->teamsName->setValidator(validator);

    connect(ui->listTeams, &QTableWidget::cellClicked, this, &teamsPage::on_cellClicked);

    ui->Stats->setObjectName("Stats");
    connect(ui->tabWidgetTeams, &QTabWidget::currentChanged, this, [this](int index) {
        qDebug() << "Tab changed to index:" << index;
        qDebug() << "Tab text:" << ui->tabWidgetTeams->tabText(index);

        if (ui->tabWidgetTeams->widget(index) == ui->Stats) {
            qDebug() << "Stats tab selected, updating charts";
            teams team;
            team.displayTeamStats(ui->Stats);
        }
    });
}

teamsPage::~teamsPage()
{
    delete ui;
}




void teamsPage::setupTeamsTable() {
    ui->listTeams->setEditTriggers(QAbstractItemView::DoubleClicked | QAbstractItemView::EditKeyPressed);
    ui->listTeams->setSelectionBehavior(QAbstractItemView::SelectRows);
    teams team;
    team.listTeams(ui->listTeams);
    addButtonsToRows(ui->listTeams);
}
void teamsPage::on_exitButton_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Exit Confirmation",
                                  "Are you sure you want to logout and exit?",
                                  QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        QApplication::quit();
    }
}

void teamsPage::on_homeButton_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Dashboard Confirmation",
                                  "Are you sure you want to return to the dashboard? All unsaved work will be lost.",
                                  QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {

        this->close();
    }
}

void teamsPage::on_notifButton_clicked()
{
    QMessageBox::information(this, "Notifications", "No new notifications.");
}

void teamsPage::on_aboutButton_clicked()
{
    QMessageBox::information(this, "About This Page", "This is the Teams Page, here you can manage the teams and perform basic CRUD operations.\n\nVersion 1.0\n\nDeveloped by TechSpire.",
                             QMessageBox::Ok);
}

void teamsPage::on_addTeamsButton_clicked() {

    ui->errerName->clear();
    ui->errerCountry->clear();
    ui->errerLogo->clear();
    ui->errerKit->clear();

    QString name = ui->teamsName->text().trimmed();
    QString country = ui->teamsNationality->text().trimmed();
    QString logo = ui->teamsLogo->text().trimmed();
    int subscribers = ui->teamsNbf->value();
    QString kit = ui->teamsKit->text().trimmed();
    int matchesPlayed = ui->teamsMP->value();
    QPalette palette = ui->errerName->palette();
    palette.setColor(ui->errerName->foregroundRole(), Qt::red);
    ui->errerName->setPalette(palette);
    ui->errerKit->setPalette(palette);
    ui->errerCountry->setPalette(palette);
    ui->errerLogo->setPalette(palette);

    if (name.isEmpty() || name.length() < 5 ) {
        ui->errerName->setText("Le nom doit contenir au moins 5 caractères.");
        return;
    }

    QStringList gouvernoratsTunisie = {
        "Ariana", "Beja", "Ben Arous", "Bizerte", "Gabes", "Gafsa", "Jendouba", "Kairouan",
        "Kasserine", "Kebili", "Kef", "Mahdia", "Manouba", "Médenine", "Monastir",
        "Nabeul", "Sfax", "Sidi Bouzid", "Siliana", "Sousse", "Tataouine", "Tozeur",
        "Tunis", "Zaghouan"
    };

    if (country.isEmpty() || !gouvernoratsTunisie.contains(country, Qt::CaseInsensitive)) {
        ui->errerCountry->setText("Veuillez entrer une gouvernorat valide de la Tunisie.");
        return;
    }

    QFileInfo logoFile(logo);
    if (logo.isEmpty() || !logoFile.exists() || !logoFile.isFile()) {
        ui->errerLogo->setText("Le logo doit être un chemin de fichier valide.");
        return;
    }

    QFileInfo kitFile(kit);
    if (kit.isEmpty() || !kitFile.exists() || !kitFile.isFile()) {
        ui->errerKit->setText("Le kit doit être un chemin de fichier valide.");
        return;
    }

    teams tm(name, country, logo, subscribers, kit, matchesPlayed);

    if (tm.addTeams()) {
        QMessageBox::information(this, "Success", "Team added successfully.");
        clearInputFields();
        setupTeamsTable();
    } else {
        QMessageBox::critical(this, "Error", "Failed to add team.");
    }
}
void teamsPage::refresh() {
    ui->listTeams->clearContents();
    ui->listTeams->setRowCount(0);
    teams team;
    team.listTeams(ui->listTeams);
    addButtonsToRows(ui->listTeams);
}
void teamsPage::on_refreshButton_clicked()
{
    if (!ui->listTeams) {
        qDebug() << "teamsTable is null!";
        return;
    }

    refresh();
}

void teamsPage::on_delete_team_clicked(int row)
{
    qDebug() << "Delete clicked for row:" << row;


    int teamID = ui->listTeams->item(row, 0)->text().toInt();


    teams team;


    if (team.deleteTeamsUsingTeamID(teamID)) {
        qDebug() << "Team with TEAMID" << teamID << "was deleted successfully.";
        setupTeamsTable();
    } else {
        qDebug() << "Failed to delete team with TEAMID" << teamID;
    }
}


void teamsPage::addButtonsToRows(QTableWidget* table)
{
    if (!table) {
        qDebug() << "Table is null!";
        return;
    }

    for (int row = 0; row < table->rowCount(); ++row) {
        QWidget* existingWidget = table->cellWidget(row, 7);
        if (existingWidget) {
            table->removeCellWidget(row, 7);
            delete existingWidget;
        }
    }

    // Add new buttons to each row
    for (int row = 0; row < table->rowCount(); ++row) {
        QPushButton* deleteButton = new QPushButton("Delete");
        QPushButton* updateButton = new QPushButton("Update");

        QWidget* actionWidget = new QWidget();
        QHBoxLayout* actionLayout = new QHBoxLayout(actionWidget);
        actionLayout->setContentsMargins(0, 0, 0, 0);
        actionLayout->setSpacing(10);

        actionLayout->addWidget(deleteButton);
        actionLayout->addWidget(updateButton);

        actionWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        table->setCellWidget(row, 7, actionWidget);

        connect(deleteButton, &QPushButton::clicked, this, [this, row]() {
            on_delete_team_clicked(row);
        });

        connect(updateButton, &QPushButton::clicked, this, [this, row]() {
            on_update_team_clicked(row);
        });

        table->setColumnWidth(7, 200);
        table->setRowHeight(row, 60);
    }
}

void teamsPage::on_addKitButton_clicked()
{

    QString kitPath = QFileDialog::getOpenFileName(this, "Select Kit File", "", "Images (*.png *.jpg *.jpeg *.bmp)");

    if (!kitPath.isEmpty()) {
        ui->teamsKit->setText(kitPath);
    }
}


void teamsPage::on_addLogoButton_clicked()
{
    QString logoPath = QFileDialog::getOpenFileName(this, "Select Logo File", "", "Images (*.png *.jpg *.jpeg *.bmp)");

    if (!logoPath.isEmpty()) {
        ui->teamsLogo->setText(logoPath);
    }
}

void teamsPage::clearInputFields()
{
    ui->teamsName->clear();
    ui->teamsNationality->clear();
    ui->teamsLogo->clear();
    ui->teamsNbf->clear();
    ui->teamsKit->clear();
    ui->teamsMP->clear();
}

void teamsPage::searchTeams(const QString& searchTerm)
{
    // Clear the table
    ui->listTeams->setRowCount(0);

    // Build the SQL query based on the search term
    QString queryStr = "SELECT TEAMID, NAME, COUNTRY, LOGO, NBSUBSCRIBERS, KIT, MATCHESPLAYED FROM TEAMS";
    if (!searchTerm.isEmpty()) {
        queryStr += " WHERE LOWER(NAME) LIKE LOWER(:searchTerm) OR LOWER(COUNTRY) LIKE LOWER(:searchTerm)";
    }

    QSqlQuery query;
    query.prepare(queryStr);

    if (!searchTerm.isEmpty()) {
        query.bindValue(":searchTerm", "%" + searchTerm + "%");
    }

    if (query.exec()) {
        int row = 0;
        while (query.next()) {
            ui->listTeams->insertRow(row);

            ui->listTeams->setItem(row, 0, new QTableWidgetItem(query.value(0).toString()));

            ui->listTeams->setItem(row, 1, new QTableWidgetItem(query.value(1).toString()));

            ui->listTeams->setItem(row, 2, new QTableWidgetItem(query.value(2).toString()));

            QString logoPath = query.value(3).toString();
            QPixmap logoPixmap(logoPath);
            if (!logoPixmap.isNull()) {
                QTableWidgetItem* logoItem = new QTableWidgetItem();
                logoItem->setData(Qt::DecorationRole, logoPixmap.scaled(50, 50, Qt::KeepAspectRatio));
                ui->listTeams->setItem(row, 3, logoItem);
            } else {
                ui->listTeams->setItem(row, 3, new QTableWidgetItem("No Image"));
            }

            ui->listTeams->setItem(row, 4, new QTableWidgetItem(query.value(4).toString()));

            QString kitPath = query.value(5).toString();
            QPixmap kitPixmap(kitPath);
            if (!kitPixmap.isNull()) {
                QTableWidgetItem* kitItem = new QTableWidgetItem();
                kitItem->setData(Qt::DecorationRole, kitPixmap.scaled(50, 50, Qt::KeepAspectRatio));
                ui->listTeams->setItem(row, 5, kitItem);
            } else {
                ui->listTeams->setItem(row, 5, new QTableWidgetItem("No Image"));
            }

            ui->listTeams->setItem(row, 6, new QTableWidgetItem(query.value(6).toString()));

            ++row;
        }

        addButtonsToRows(ui->listTeams);

        ui->listTeams->setColumnHidden(0, true);
    } else {
        qDebug() << "Failed to fetch data: " << query.lastError();
    }
}

void teamsPage::on_searchButton_clicked()
{
    QString searchTerm = ui->searchTeamsInput->text().trimmed();
    searchTeams(searchTerm);
}


void teamsPage::on_cellClicked(int row, int column)
{
    if (column == 3 || column == 5) {
        QString filePath = QFileDialog::getOpenFileName(this, "Select Image", "", "Images (*.png *.jpg *.jpeg *.bmp)");
        if (!filePath.isEmpty()) {

            QPixmap newPixmap(filePath);
            if (!newPixmap.isNull()) {
                QTableWidgetItem* imageItem = new QTableWidgetItem();
                imageItem->setData(Qt::DecorationRole, newPixmap.scaled(50, 50, Qt::KeepAspectRatio));
                ui->listTeams->setItem(row, column, imageItem);

                int teamID = ui->listTeams->item(row, 0)->text().toInt();
                QString fieldName = (column == 3) ? "LOGO" : "KIT";

                QSqlQuery query;
                QString updateQuery = QString("UPDATE TEAMS SET %1 = :filePath WHERE TEAMID = :teamID").arg(fieldName);
                query.prepare(updateQuery);
                query.bindValue(":filePath", filePath);
                query.bindValue(":teamID", teamID);

                if (query.exec()) {
                    qDebug() << "Image updated successfully for TEAMID:" << teamID;
                } else {
                    qDebug() << "Failed to update image:" << query.lastError();
                }
            } else {
                QMessageBox::warning(this, "Error", "Failed to load the selected image.");
            }
        } else {
            qDebug() << "No image selected.";
        }
    }
}


void teamsPage::on_update_team_clicked(int row)
{
    if (!ui->listTeams) {
        qDebug() << "teamsTable is null!";
        return;
    }

    int teamID = ui->listTeams->item(row, 0)->text().toInt();

    QString name = ui->listTeams->item(row, 1)->text().trimmed();
    QString country = ui->listTeams->item(row, 2)->text().trimmed();
    QString logo = ui->listTeams->item(row, 3)->text().trimmed();
    QString subscribersText = ui->listTeams->item(row, 4)->text().trimmed();
    QString kit = ui->listTeams->item(row, 5)->text().trimmed();
    QString matchesPlayedText = ui->listTeams->item(row, 6)->text().trimmed();

    QRegularExpression nameRegex("^[A-Za-z\\s]+$");
    if (!nameRegex.match(name).hasMatch()) {
        QMessageBox::warning(this, "Error", "Le nom ne doit contenir que des lettres et des espaces (pas de chiffres ou de caractères spéciaux).");
        return;
    }
    QStringList gouvernoratsTunisie = {
        "Ariana", "Beja", "Ben Arous", "Bizerte", "Gabes", "Gafsa", "Jendouba", "Kairouan",
        "Kasserine", "Kebili", "Kef", "Mahdia", "Manouba", "Médenine", "Monastir",
        "Nabeul", "Sfax", "Sidi Bouzid", "Siliana", "Sousse", "Tataouine", "Tozeur",
        "Tunis", "Zaghouan"
    };

    bool ok1, ok2;
    int subscribers = subscribersText.toInt(&ok1);
    int matchesPlayed = matchesPlayedText.toInt(&ok2);

    if (!ok1 || !ok2) {
        QMessageBox::warning(this, "Error", "Subscribers and Matches Played must be valid numbers.");
        return;
    }

    if (subscribers < 0 || matchesPlayed < 0) {
        QMessageBox::warning(this, "Error", "Subscribers and Matches Played cannot be negative.");
        return;
    }

    if (name.isEmpty() ) {
        QMessageBox::warning(this, "Error", "Please fill all required fields (Name).");
        return;
    }

    if (country.isEmpty() || !gouvernoratsTunisie.contains(country, Qt::CaseInsensitive)) {
        QMessageBox::warning(this, "Error","Veuillez entrer une gouvernorat valide de la Tunisie.");
        return;
    }

    if (name.length() > 10 || country.length() > 10 || logo.length() > 200 || kit.length() > 200) {
        QMessageBox::warning(this, "Error", "Input exceeds maximum length for one or more fields.");
        return;
    }

    teams team;
    if (team.updateTeamsUsingTeamId(teamID, name, country, logo, subscribers, kit, matchesPlayed)) {
        QMessageBox::information(this, "Success", "Team updated successfully.");
        setupTeamsTable();
    } else {
        QMessageBox::critical(this, "Error", "Failed to update team.");
    }
}

void teamsPage::sortTableByColumn(int column, Qt::SortOrder order)
{
    QTableWidget* listTeamsTable = ui->listTeams;
    listTeamsTable->sortItems(column, order);
}

void teamsPage::on_filtreTeams_currentIndexChanged(int index)
{
    switch (index) {
    case 0:
        sortTableByColumn(0, Qt::AscendingOrder);
        break;

    case 1:
        sortTableByColumn(1, Qt::AscendingOrder);
        break;

    case 2:
        sortTableByColumn(1, Qt::DescendingOrder);
        break;

    case 3:
        sortTableByColumn(6, Qt::AscendingOrder);
        break;

    case 4:
        sortTableByColumn(6, Qt::DescendingOrder);
        break;

    case 5:
        sortTableByColumn(4, Qt::AscendingOrder);
        break;

    case 6:
        sortTableByColumn(4, Qt::DescendingOrder);
        break;

    case 7:
        sortTableByColumn(0, Qt::DescendingOrder);
        break;

    default:
        break;
    }
}


void teamsPage::on_exportListButton_clicked() {
    QString fileName = QFileDialog::getSaveFileName(this, tr("Export PDF"),
                                                    QDir::homePath() + "/teams_list.pdf",
                                                    tr("PDF Files (*.pdf)"));

    if (fileName.isEmpty()) {
        return;
    }

    if (!fileName.endsWith(".pdf", Qt::CaseInsensitive)) {
        fileName += ".pdf";
    }

    QSqlDatabase db = QSqlDatabase::database();
    if (!db.isOpen()) {
        QMessageBox::warning(this, tr("Database Error"), tr("Database connection is not open."));
        return;
    }

    QSqlQuery query;
    if (!query.exec("SELECT * FROM teams")) {
        QMessageBox::warning(this, tr("Query Error"),
                             tr("Failed to execute query: %1").arg(query.lastError().text()));
        return;
    }

    if (!query.first()) {
        QMessageBox::warning(this, tr("Export Error"), tr("No teams found in the database."));
        return;
    }

    // Create a printer
    QPrinter printer(QPrinter::HighResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(fileName);
    printer.setPageOrientation(QPageLayout::Landscape);

    QPainter painter;
    if (!painter.begin(&printer)) {
        QMessageBox::warning(this, tr("Export Error"),
                             tr("Failed to open PDF file for writing."));
        return;
    }

    QFont titleFont = painter.font();
    titleFont.setPointSize(16);
    titleFont.setBold(true);
    painter.setFont(titleFont);


    painter.drawText(QRect(0, 100, printer.width(), 50),
                     Qt::AlignHCenter | Qt::AlignTop,
                     tr("Teams List"));

    QStringList columnNames;
    columnNames << "ID" << "Name" << "Country" << "Logo" << "Subscribers" << "Kit" << "Matches Played";

    int numColumns = columnNames.size();

    int logoColumnIndex = 3;
    int kitColumnIndex = 5;

    qDebug() << "Using logo column:" << logoColumnIndex << "and kit column:" << kitColumnIndex;

    int rowHeight = 480;
    int tableWidth = printer.width() - 100;
    int tableX = 50;
    int tableY = 200;

    QVector<int> columnWidths(numColumns);
    for (int col = 0; col < numColumns; ++col) {
        columnWidths[col] = tableWidth / numColumns;
    }

    // Draw table header
    QFont headerFont = painter.font();
    headerFont.setBold(true);
    headerFont.setPointSize(12);
    painter.setFont(headerFont);

    int xPos = tableX;
    for (int col = 0; col < numColumns; ++col) {
        QRect headerRect(xPos, tableY, columnWidths[col], rowHeight);
        painter.drawRect(headerRect);
        painter.drawText(headerRect, Qt::AlignCenter, columnNames[col]);
        xPos += columnWidths[col];
    }

    // Draw table content
    QFont contentFont = painter.font();
    contentFont.setBold(false);
    contentFont.setPointSize(10);
    painter.setFont(contentFont);

    int row = 0;

    do {
        xPos = tableX;
        int yPos = tableY + (row + 1) * rowHeight;

        if (yPos + rowHeight > printer.height() - 50) {
            printer.newPage();
            yPos = 50;
            tableY = 0;
        }

        for (int col = 0; col < numColumns; ++col) {
            QRect cellRect(xPos, yPos, columnWidths[col], rowHeight);
            painter.drawRect(cellRect);

            QVariant value = query.value(col);
            QString text = value.toString();

            if ((col == logoColumnIndex || col == kitColumnIndex) && !text.isEmpty()) {
                qDebug() << "Processing image path from database:" << text << "in column" << col;

                QPixmap pixmap;
                bool loaded = false;

                if (pixmap.load(text)) {
                    qDebug() << "Successfully loaded image with direct path";
                    loaded = true;
                } else {
                    qDebug() << "Failed to load with direct path, trying absolute path";

                    QString absolutePath = QDir::current().absoluteFilePath(text);
                    if (pixmap.load(absolutePath)) {
                        qDebug() << "Successfully loaded image with absolute path:" << absolutePath;
                        loaded = true;
                    } else {
                        qDebug() << "Failed to load with absolute path too";

                        if (text.startsWith(":")) {
                            if (pixmap.load(text)) {
                                qDebug() << "Successfully loaded image from resources";
                                loaded = true;
                            } else {
                                qDebug() << "Failed to load from resources";
                            }
                        }
                    }
                }

                if (loaded && !pixmap.isNull()) {
                    QSize imageSize = pixmap.size();
                    qDebug() << "Original image size:" << imageSize;


                    int scaledWidth = imageSize.width() * 2;
                    int scaledHeight = imageSize.height() * 2;
                    qDebug() << "Doubled image size:" << scaledWidth << "x" << scaledHeight;

                    int maxWidth = cellRect.width() - 20;
                    int maxHeight = cellRect.height() - 20;
                    qDebug() << "Max allowed size in cell:" << maxWidth << "x" << maxHeight;

                    if (scaledWidth > maxWidth || scaledHeight > maxHeight) {
                        qDebug() << "Doubled size exceeds cell dimensions, scaling down";
                        pixmap = pixmap.scaled(maxWidth, maxHeight, Qt::KeepAspectRatio, Qt::SmoothTransformation);
                    } else {
                        qDebug() << "Using doubled size";
                        pixmap = pixmap.scaled(scaledWidth, scaledHeight, Qt::KeepAspectRatio, Qt::SmoothTransformation);
                    }

                    qDebug() << "Final image size:" << pixmap.size();

                    int imgX = cellRect.x() + (cellRect.width() - pixmap.width()) / 2;
                    int imgY = cellRect.y() + (cellRect.height() - pixmap.height()) / 2;

                    painter.drawPixmap(imgX, imgY, pixmap);
                } else {
                    painter.drawText(cellRect, Qt::AlignCenter, text);
                }
            } else {
                painter.drawText(cellRect, Qt::AlignCenter, text);
            }

            xPos += columnWidths[col];
        }

        row++;
    } while (query.next());

    painter.end();

    QMessageBox::information(this, tr("Export Successful"),
                             tr("The table has been exported to PDF successfully."));
}

void teamsPage::on_prevPageTable_clicked()
{

}


void teamsPage::on_TeamType_clicked()
{
    QString uiFilePath = "../../teamstype.ui";
    QFile file(uiFilePath);

    if (!file.exists()) {
        QStringList possiblePaths;
        possiblePaths << "teamstype.ui"
                      << QCoreApplication::applicationDirPath() + "/teamstype.ui"
                      << QDir::currentPath() + "/teamstype.ui"
                      << "../teamstype.ui";

        for (const QString& path : possiblePaths) {
            file.setFileName(path);
            if (file.exists()) {
                uiFilePath = path;
                break;
            }
        }
    }

    if (!file.exists()) {
        QMessageBox::warning(this, tr("Error"), tr("Could not find UI file: teamstype.ui"));
        return;
    }

    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::warning(this, tr("Error"), tr("Could not open UI file: %1").arg(file.errorString()));
        return;
    }

    QUiLoader loader;
    QWidget* formWidget = loader.load(&file, this);
    file.close();

    if (!formWidget) {
        QMessageBox::warning(this, tr("Error"), tr("Could not load UI file: %1").arg(loader.errorString()));
        return;
    }

    QDialog* teamTypeDialog = new QDialog(this);
    teamTypeDialog->setWindowTitle("Teams Type aka The GOATS of the league");

    QVBoxLayout* mainLayout = new QVBoxLayout(teamTypeDialog);
    mainLayout->addWidget(formWidget);
    mainLayout->setContentsMargins(0, 0, 0, 0);

    QLabel* pitchLabel = formWidget->findChild<QLabel*>("pitchLabel");
    if (pitchLabel) {
        QStringList pitchImagePaths;
        pitchImagePaths << "textures/pitchimg.png"
                        << "../../textures/pitchimg.png"
                        << "../textures/pitchimg.png"
                        << QCoreApplication::applicationDirPath() + "/textures/pitchimg.png";

        bool pitchImageLoaded = false;
        for (const QString& path : pitchImagePaths) {
            QPixmap pitchPixmap(path);
            if (!pitchPixmap.isNull()) {
                pitchLabel->setPixmap(pitchPixmap);
                qDebug() << "Image pitch loaded ou haw lpath:" << path;
                pitchImageLoaded = true;
                break;
            }
        }

        if (!pitchImageLoaded) {
            qDebug() << "L'image matekhdemch barra salah codek";
        }
    } else {
        qDebug() << "Bro haw mafamech image aslan yekhi tet9ouheb";
    }


    QLabel* GKlabel = formWidget->findChild<QLabel*>("GK");
    QLabel* LBlabel = formWidget->findChild<QLabel*>("LB");
    QLabel* CB1label = formWidget->findChild<QLabel*>("CB1");
    QLabel* CB2label = formWidget->findChild<QLabel*>("CB2");
    QLabel* RBlabel = formWidget->findChild<QLabel*>("RB");
    QLabel* CM1label = formWidget->findChild<QLabel*>("CM1");
    QLabel* CM2label = formWidget->findChild<QLabel*>("CM2");
    QLabel* CAMlabel = formWidget->findChild<QLabel*>("CAM");
    QLabel* LWlabel = formWidget->findChild<QLabel*>("LW");
    QLabel* STlabel = formWidget->findChild<QLabel*>("ST");
    QLabel* RWlabel = formWidget->findChild<QLabel*>("RW");


    QLabel* GKnameLabel = formWidget->findChild<QLabel*>("GKname");
    QLabel* LBnameLabel = formWidget->findChild<QLabel*>("LBname");
    QLabel* CB1nameLabel = formWidget->findChild<QLabel*>("CB1name");
    QLabel* CB2nameLabel = formWidget->findChild<QLabel*>("CB2name");
    QLabel* RBnameLabel = formWidget->findChild<QLabel*>("RBname");
    QLabel* CM1nameLabel = formWidget->findChild<QLabel*>("CM1name");
    QLabel* CM2nameLabel = formWidget->findChild<QLabel*>("CM2name");
    QLabel* CAMnameLabel = formWidget->findChild<QLabel*>("CAMname");
    QLabel* LWnameLabel = formWidget->findChild<QLabel*>("LWname");
    QLabel* STnameLabel = formWidget->findChild<QLabel*>("STname");
    QLabel* RWnameLabel = formWidget->findChild<QLabel*>("RWname");



    QLabel* GKrateLabel = formWidget->findChild<QLabel*>("GKrate");
    QLabel* LBrateLabel = formWidget->findChild<QLabel*>("LBrate");
    QLabel* CB1rateLabel = formWidget->findChild<QLabel*>("CB1rate");
    QLabel* CB2rateLabel = formWidget->findChild<QLabel*>("CB2rate");
    QLabel* RBrateLabel = formWidget->findChild<QLabel*>("RBrate");
    QLabel* CM1rateLabel = formWidget->findChild<QLabel*>("CM1rate");
    QLabel* CM2rateLabel = formWidget->findChild<QLabel*>("CM2rate");
    QLabel* CAMrateLabel = formWidget->findChild<QLabel*>("CAMrate");
    QLabel* LWrateLabel = formWidget->findChild<QLabel*>("LWrate");
    QLabel* STrateLabel = formWidget->findChild<QLabel*>("STrate");
    QLabel* RWrateLabel = formWidget->findChild<QLabel*>("RWrate");



    QLabel* GKfaceLabel = formWidget->findChild<QLabel*>("GKface");
    QLabel* LBfaceLabel = formWidget->findChild<QLabel*>("LBface");
    QLabel* CB1faceLabel = formWidget->findChild<QLabel*>("CB1face");
    QLabel* CB2faceLabel = formWidget->findChild<QLabel*>("CB2face");
    QLabel* RBfaceLabel = formWidget->findChild<QLabel*>("RBface");
    QLabel* CM1faceLabel = formWidget->findChild<QLabel*>("CM1face");
    QLabel* CM2faceLabel = formWidget->findChild<QLabel*>("CM2face");
    QLabel* CAMfaceLabel = formWidget->findChild<QLabel*>("CAMface");
    QLabel* LWfaceLabel = formWidget->findChild<QLabel*>("LWface");
    QLabel* STfaceLabel = formWidget->findChild<QLabel*>("STface");
    QLabel* RWfaceLabel = formWidget->findChild<QLabel*>("RWface");



    const QVector<QPair<QString, QString>> positionLabels = {
        {"GK", "GKface"},
        {"LB", "LBface"},
        {"CB1", "CB1face"},
        {"CB2", "CB2face"},
        {"RB", "RBface"},
        {"CM1", "CM1face"},
        {"CM2", "CM2face"},
        {"CAM", "CAMface"},
        {"LW", "LWface"},
        {"ST", "STface"},
        {"RW", "RWface"}
    };

    for (const auto& pair : positionLabels) {
        if (QLabel* label = formWidget->findChild<QLabel*>(pair.second)) {
            playerFaceLabels[pair.first] = label;
        }
    }

    if (GKfaceLabel) playerFaceLabels["GK"] = GKfaceLabel;
    if (LBfaceLabel) playerFaceLabels["LB"] = LBfaceLabel;
    if (CB1faceLabel) playerFaceLabels["CB1"] = CB1faceLabel;
    if (CB2faceLabel) playerFaceLabels["CB2"] = CB2faceLabel;
    if (RBfaceLabel) playerFaceLabels["RB"] = RBfaceLabel;
    if (CM1faceLabel) playerFaceLabels["CM1"] = CM1faceLabel;
    if (CM2faceLabel) playerFaceLabels["CM2"] = CM2faceLabel;
    if (CAMfaceLabel) playerFaceLabels["CAM"] = CAMfaceLabel;
    if (LWfaceLabel) playerFaceLabels["LW"] = LWfaceLabel;
    if (STfaceLabel) playerFaceLabels["ST"] = STfaceLabel;
    if (RWfaceLabel) playerFaceLabels["RW"] = RWfaceLabel;

    QPixmap playerCardPixmap;
    bool playerCardLoaded = false;

    QStringList playerCardPaths;
    playerCardPaths << "textures/image_2025-03-25_044501900-removebg-preview.png"
                    << "../../textures/image_2025-03-25_044501900-removebg-preview.png"
                    << "../textures/image_2025-03-25_044501900-removebg-preview.png"
                    << QCoreApplication::applicationDirPath() + "/textures/image_2025-03-25_044501900-removebg-preview.png";

    for (const QString& path : playerCardPaths) {
        playerCardPixmap = QPixmap(path);
        if (!playerCardPixmap.isNull()) {
            qDebug() << "Taswira bta3 lcarta tekhdem ou haw lpath:" << path;
            playerCardLoaded = true;
            break;
        }
    }

    if (!playerCardLoaded) {
        qDebug() << "Rani tellement kesah hatitha tloady mel position bte3ha fel dossier";

        QStringList altPaths;
        altPaths << "image_2025-03-25_044501900-removebg-preview.png"
                 << "../../image_2025-03-25_044501900-removebg-preview.png"
                 << "../image_2025-03-25_044501900-removebg-preview.png"
                 << QCoreApplication::applicationDirPath() + "/image_2025-03-25_044501900-removebg-preview.png"
                 << QDir::currentPath() + "/image_2025-03-25_044501900-removebg-preview.png";

        for (const QString& path : altPaths) {
            playerCardPixmap = QPixmap(path);
            if (!playerCardPixmap.isNull()) {
                qDebug() << "Redundency tekhdem ou haw lpath:" << path;
                playerCardLoaded = true;
                break;
            }
        }
    }

    if (playerCardLoaded) {
        QList<QLabel*> playerLabels;
        playerLabels << GKlabel << LBlabel << CB1label << CB2label << RBlabel
                     << CM1label << CM2label << CAMlabel << LWlabel << STlabel << RWlabel;

        for (QLabel* label : playerLabels) {
            if (label) {
                QPixmap scaledPixmap = playerCardPixmap.scaled(label->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
                label->setPixmap(scaledPixmap);
            }
        }
    } else {
        qDebug() << "Ken yjini ldebug hetha w9ayet nbatel l'info";
    }

    QMap<QString, QLabel*> playerNameLabels;
    QMap<QString, QLabel*> playerRateLabels;


    if (GKnameLabel) playerNameLabels["GK"] = GKnameLabel;
    if (LBnameLabel) playerNameLabels["LB"] = LBnameLabel;
    if (CB1nameLabel) playerNameLabels["CB1"] = CB1nameLabel;
    if (CB2nameLabel) playerNameLabels["CB2"] = CB2nameLabel;
    if (RBnameLabel) playerNameLabels["RB"] = RBnameLabel;
    if (CM1nameLabel) playerNameLabels["CM1"] = CM1nameLabel;
    if (CM2nameLabel) playerNameLabels["CM2"] = CM2nameLabel;
    if (CAMnameLabel) playerNameLabels["CAM"] = CAMnameLabel;
    if (LWnameLabel) playerNameLabels["LW"] = LWnameLabel;
    if (STnameLabel) playerNameLabels["ST"] = STnameLabel;
    if (RWnameLabel) playerNameLabels["RW"] = RWnameLabel;


    if (GKrateLabel) playerRateLabels["GK"] = GKrateLabel;
    if (LBrateLabel) playerRateLabels["LB"] = LBrateLabel;
    if (CB1rateLabel) playerRateLabels["CB1"] = CB1rateLabel;
    if (CB2rateLabel) playerRateLabels["CB2"] = CB2rateLabel;
    if (RBrateLabel) playerRateLabels["RB"] = RBrateLabel;
    if (CM1rateLabel) playerRateLabels["CM1"] = CM1rateLabel;
    if (CM2rateLabel) playerRateLabels["CM2"] = CM2rateLabel;
    if (CAMrateLabel) playerRateLabels["CAM"] = CAMrateLabel;
    if (LWrateLabel) playerRateLabels["LW"] = LWrateLabel;
    if (STrateLabel) playerRateLabels["ST"] = STrateLabel;
    if (RWrateLabel) playerRateLabels["RW"] = RWrateLabel;

    // Configure and style the name labels
    QString nameStyle = "QLabel { color: white; font-weight: bold; font-size: 14px; text-shadow: 1px 1px 2px black; }";

    for (QLabel* label : playerNameLabels.values()) {
        if (label) {
            label->setWordWrap(true);

            label->setAlignment(Qt::AlignHCenter | Qt::AlignTop);

            label->setStyleSheet(nameStyle);
        }
    }

    QSqlDatabase db = QSqlDatabase::database();
    if (!db.isOpen()) {
        QMessageBox::warning(this, tr("Database Error"), tr("Database connection is not open."));
        delete teamTypeDialog;
        return;
    }

    QString ratingStyle = "color: white; font-size: 16px; font-weight: bold;";


    QSqlQuery gkQuery;
    gkQuery.prepare("SELECT p.FNAME || ' ' || p.LNAME as FULLNAME, "
                    "p.PLAYERID, "
                    "p.FACEIMG, "
                    "COALESCE(SUM(pp.NUMSAVES), 0) as TOTAL_SAVES, "
                    "COALESCE(SUM(pp.NUMGOALS), 0) as GOALS_CONCEDED, "
                    "COALESCE(SUM(pp.NUMYELLOWCARDS), 0) as YELLOW_CARDS, "
                    "COALESCE(SUM(pp.NUMREDCARDS), 0) as RED_CARDS, "
                    "COALESCE(SUM(pp.PLAYTIMEINMINUTES), 0) as MINUTES_PLAYED "
                    "FROM PLAYERS p "
                    "LEFT JOIN PLAYERPERFORMANCE pp ON p.PLAYERID = pp.PLAYERID "
                    "WHERE p.POSITION = 'GK' "
                    "GROUP BY p.FNAME, p.LNAME, p.PLAYERID, p.FACEIMG "
                    "ORDER BY TOTAL_SAVES DESC, p.PLAYERID");

    QList<QString> goalkeepers;
    QList<double> goalkeeperRatings;
    QList<QString> goalkeeperFaceImages;

    if (gkQuery.exec()) {
        while (gkQuery.next()) {
            QString playerName = gkQuery.value("FULLNAME").toString();
            goalkeepers.append(playerName);

            goalkeeperFaceImages.append(gkQuery.value("FACEIMG").toString());

            int saves = gkQuery.value("TOTAL_SAVES").toInt();
            int goalsConceded = gkQuery.value("GOALS_CONCEDED").toInt();
            int yellowCards = gkQuery.value("YELLOW_CARDS").toInt();
            int redCards = gkQuery.value("RED_CARDS").toInt();
            int minutesPlayed = qMax(1, gkQuery.value("MINUTES_PLAYED").toInt());

            double matchesWorth = static_cast<double>(minutesPlayed) / 90.0;
            double rating = 6.0 +
                            (saves/matchesWorth*0.5) -
                            (goalsConceded/matchesWorth*0.8) -
                            (yellowCards/matchesWorth*0.2) -
                            (redCards/matchesWorth*0.5);
            rating = qBound(1.0, rating, 10.0);

            goalkeeperRatings.append(rating);
        }
    } else {
        qDebug() << "Ya bhim query ghalta (gk):" << gkQuery.lastError().text();
    }

    if (goalkeepers.size() >= 1 && playerNameLabels.contains("GK")) {
        playerNameLabels["GK"]->setText(goalkeepers[0]);

        if (playerRateLabels.contains("GK")) {
            playerRateLabels["GK"]->setText(QString::number(goalkeeperRatings[0], 'f', 1));
            playerRateLabels["GK"]->setStyleSheet(ratingStyle);
        }

        if (playerFaceLabels.contains("GK") && !goalkeeperFaceImages.isEmpty()) {
            QString imagePath = goalkeeperFaceImages[0];
            QPixmap pixmap(imagePath);

            if (!pixmap.isNull()) {
                playerFaceLabels["GK"]->setPixmap(pixmap.scaled(
                    playerFaceLabels["GK"]->size(),
                    Qt::KeepAspectRatio,
                    Qt::SmoothTransformation
                    ));
            } else {
                pixmap.load(":/images/default_player.png");
                if (!pixmap.isNull()) {
                    playerFaceLabels["GK"]->setPixmap(pixmap.scaled(
                        playerFaceLabels["GK"]->size(),
                        Qt::KeepAspectRatio,
                        Qt::SmoothTransformation
                        ));
                }
            }
        }
    } else if (playerNameLabels.contains("GK")) {
        playerNameLabels["GK"]->setText("No player found");

        if (playerRateLabels.contains("GK")) {
            playerRateLabels["GK"]->setText("--");
            playerRateLabels["GK"]->setStyleSheet(ratingStyle);
        }

        if (playerFaceLabels.contains("GK")) {
            playerFaceLabels["GK"]->clear();
        }
    }

    QSqlQuery dfQuery;
    dfQuery.prepare("SELECT p.FNAME || ' ' || p.LNAME as FULLNAME, "
                    "p.PLAYERID, "
                    "p.FACEIMG, "
                    "COALESCE(SUM(pp.NUMGOALS), 0) as TOTAL_GOALS, "
                    "COALESCE(SUM(pp.NUMASSISTS), 0) as TOTAL_ASSISTS, "
                    "COALESCE(SUM(pp.NUMYELLOWCARDS), 0) as YELLOW_CARDS, "
                    "COALESCE(SUM(pp.NUMREDCARDS), 0) as RED_CARDS, "
                    "COALESCE(SUM(pp.PLAYTIMEINMINUTES), 0) as MINUTES_PLAYED "
                    "FROM PLAYERS p "
                    "LEFT JOIN PLAYERPERFORMANCE pp ON p.PLAYERID = pp.PLAYERID "
                    "WHERE p.POSITION = 'DF' "
                    "GROUP BY p.FNAME, p.LNAME, p.PLAYERID, p.FACEIMG "
                    "ORDER BY (SUM(pp.NUMYELLOWCARDS) + SUM(pp.NUMREDCARDS) * 2) ASC, p.PLAYERID");

    QList<QString> defenders;
    QList<double> defenderRatings;
    QList<QString> defenderFaceImages;


    if (dfQuery.exec()) {
        while (dfQuery.next()) {
            QString playerName = dfQuery.value("FULLNAME").toString();
            defenders.append(playerName);

            defenderFaceImages.append(dfQuery.value("FACEIMG").toString());

            int goals = dfQuery.value("TOTAL_GOALS").toInt();
            int assists = dfQuery.value("TOTAL_ASSISTS").toInt();
            int yellowCards = dfQuery.value("YELLOW_CARDS").toInt();
            int redCards = dfQuery.value("RED_CARDS").toInt();
            int minutesPlayed = qMax(1, dfQuery.value("MINUTES_PLAYED").toInt());

            double matchesWorth = static_cast<double>(minutesPlayed) / 90.0;
            double rating = 6.0 + (goals/matchesWorth*0.3) + (assists/matchesWorth*0.2)
                            - (yellowCards/matchesWorth*0.4) - (redCards/matchesWorth*1.0);
            rating = qBound(1.0, rating, 10.0);

            defenderRatings.append(rating);
        }
    } else {
        qDebug() << "Ya bhim query ghalta (df):" << dfQuery.lastError().text();
    }

    auto displayPlayer = [&](const QString& position, int index) {
        if (index >= defenders.size()) {
            if (playerNameLabels.contains(position)) {
                playerNameLabels[position]->setText("No player found");
            }
            if (playerRateLabels.contains(position)) {
                playerRateLabels[position]->setText("--");
                playerRateLabels[position]->setStyleSheet(ratingStyle);
            }
            if (playerFaceLabels.contains(position)) {
                playerFaceLabels[position]->clear();
            }
            return;
        }

        if (playerNameLabels.contains(position)) {
            playerNameLabels[position]->setText(defenders[index]);
        }
        if (playerRateLabels.contains(position)) {
            playerRateLabels[position]->setText(QString::number(defenderRatings[index], 'f', 1));
            playerRateLabels[position]->setStyleSheet(ratingStyle);
        }
        if (playerFaceLabels.contains(position) && index < defenderFaceImages.size()) {
            QString imagePath = defenderFaceImages[index];
            QPixmap pixmap(imagePath);

            if (!pixmap.isNull()) {
                playerFaceLabels[position]->setPixmap(pixmap.scaled(
                    playerFaceLabels[position]->size(),
                    Qt::KeepAspectRatio,
                    Qt::SmoothTransformation
                    ));
            } else {
                pixmap.load(":/images/default_player.png");
                if (!pixmap.isNull()) {
                    playerFaceLabels[position]->setPixmap(pixmap.scaled(
                        playerFaceLabels[position]->size(),
                        Qt::KeepAspectRatio,
                        Qt::SmoothTransformation
                        ));
                }
            }
        }
    };

    displayPlayer("CB1", 0);
    displayPlayer("CB2", 1);
    displayPlayer("LB", 2);
    displayPlayer("RB", 3);

    QSqlQuery mfQuery;
    mfQuery.prepare("SELECT p.FNAME || ' ' || p.LNAME as FULLNAME, "
                    "p.PLAYERID, "
                    "p.FACEIMG, "
                    "COALESCE(SUM(pp.NUMGOALS), 0) as TOTAL_GOALS, "
                    "COALESCE(SUM(pp.NUMASSISTS), 0) as TOTAL_ASSISTS, "
                    "COALESCE(SUM(pp.NUMSAVES), 0) as TOTAL_SAVES, "
                    "COALESCE(SUM(pp.NUMYELLOWCARDS), 0) as YELLOW_CARDS, "
                    "COALESCE(SUM(pp.NUMREDCARDS), 0) as RED_CARDS, "
                    "COALESCE(SUM(pp.PLAYTIMEINMINUTES), 0) as MINUTES_PLAYED "
                    "FROM PLAYERS p "
                    "LEFT JOIN PLAYERPERFORMANCE pp ON p.PLAYERID = pp.PLAYERID "
                    "WHERE p.POSITION = 'MF' "
                    "GROUP BY p.FNAME, p.LNAME, p.PLAYERID, p.FACEIMG "
                    "ORDER BY TOTAL_ASSISTS DESC, p.PLAYERID");

    QList<QString> midfielders;
    QList<double> midfielderRatings;
    QList<QString> midfielderFaceImages;

    if (mfQuery.exec()) {
        while (mfQuery.next()) {
            QString playerName = mfQuery.value("FULLNAME").toString();
            midfielders.append(playerName);

            midfielderFaceImages.append(mfQuery.value("FACEIMG").toString());

            int goals = mfQuery.value("TOTAL_GOALS").toInt();
            int assists = mfQuery.value("TOTAL_ASSISTS").toInt();
            int yellowCards = mfQuery.value("YELLOW_CARDS").toInt();
            int redCards = mfQuery.value("RED_CARDS").toInt();
            int minutesPlayed = qMax(1, mfQuery.value("MINUTES_PLAYED").toInt());

            double matchesWorth = static_cast<double>(minutesPlayed) / 90.0;
            double rating = 6.0 +
                            (goals/matchesWorth*0.5) +
                            (assists/matchesWorth*0.5) -
                            (yellowCards/matchesWorth*0.2) -
                            (redCards/matchesWorth*0.5);
            rating = qBound(1.0, rating, 10.0);

            midfielderRatings.append(rating);
        }
    } else {
        qDebug() << "Ya bhim query ghalta (mf):" << mfQuery.lastError().text();
    }

    auto displayMidfielder = [&](const QString& position, int index) {
        if (index >= midfielders.size()) {
            if (playerNameLabels.contains(position)) {
                playerNameLabels[position]->setText("No player found");
            }
            if (playerRateLabels.contains(position)) {
                playerRateLabels[position]->setText("--");
                playerRateLabels[position]->setStyleSheet(ratingStyle);
            }
            if (playerFaceLabels.contains(position)) {
                playerFaceLabels[position]->clear();
            }
            return;
        }

        if (playerNameLabels.contains(position)) {
            playerNameLabels[position]->setText(midfielders[index]);
        }
        if (playerRateLabels.contains(position)) {
            playerRateLabels[position]->setText(QString::number(midfielderRatings[index], 'f', 1));
            playerRateLabels[position]->setStyleSheet(ratingStyle);
        }
        if (playerFaceLabels.contains(position) && index < midfielderFaceImages.size()) {
            QString imagePath = midfielderFaceImages[index];
            QPixmap pixmap(imagePath);

            if (!pixmap.isNull()) {
                playerFaceLabels[position]->setPixmap(pixmap.scaled(
                    playerFaceLabels[position]->size(),
                    Qt::KeepAspectRatio,
                    Qt::SmoothTransformation
                    ));
            } else {
                pixmap.load(":/images/default_player.png");
                if (!pixmap.isNull()) {
                    playerFaceLabels[position]->setPixmap(pixmap.scaled(
                        playerFaceLabels[position]->size(),
                        Qt::KeepAspectRatio,
                        Qt::SmoothTransformation
                        ));
                }
            }
        }
    };

    displayMidfielder("CM1", 0);
    displayMidfielder("CM2", 1);
    displayMidfielder("CAM", 2);

    QSqlQuery fwQuery;
    fwQuery.prepare("SELECT p.FNAME || ' ' || p.LNAME as FULLNAME, "
                    "p.PLAYERID, "
                    "p.FACEIMG, "
                    "COALESCE(SUM(pp.NUMGOALS), 0) as TOTAL_GOALS, "
                    "COALESCE(SUM(pp.NUMASSISTS), 0) as TOTAL_ASSISTS, "
                    "COALESCE(SUM(pp.NUMSAVES), 0) as TOTAL_SAVES, "
                    "COALESCE(SUM(pp.NUMYELLOWCARDS), 0) as YELLOW_CARDS, "
                    "COALESCE(SUM(pp.NUMREDCARDS), 0) as RED_CARDS, "
                    "COALESCE(SUM(pp.PLAYTIMEINMINUTES), 0) as MINUTES_PLAYED "
                    "FROM PLAYERS p "
                    "LEFT JOIN PLAYERPERFORMANCE pp ON p.PLAYERID = pp.PLAYERID "
                    "WHERE p.POSITION = 'FW' "
                    "GROUP BY p.FNAME, p.LNAME, p.PLAYERID, p.FACEIMG "
                    "ORDER BY TOTAL_GOALS DESC, p.PLAYERID");

    QList<QString> forwards;
    QList<double> forwardRatings;
    QList<QString> forwardFaceImages;

    if (fwQuery.exec()) {
        while (fwQuery.next()) {
            QString playerName = fwQuery.value("FULLNAME").toString();
            forwards.append(playerName);

            // Store face image path
            forwardFaceImages.append(fwQuery.value("FACEIMG").toString());

            // Calculate forward rating
            int goals = fwQuery.value("TOTAL_GOALS").toInt();
            int assists = fwQuery.value("TOTAL_ASSISTS").toInt();
            int yellowCards = fwQuery.value("YELLOW_CARDS").toInt();
            int redCards = fwQuery.value("RED_CARDS").toInt();
            int minutesPlayed = qMax(1, fwQuery.value("MINUTES_PLAYED").toInt());

            double matchesWorth = static_cast<double>(minutesPlayed) / 90.0;
            double rating = 6.0 +
                            (goals/matchesWorth*0.8) +
                            (assists/matchesWorth*0.3) -
                            (yellowCards/matchesWorth*0.2) -
                            (redCards/matchesWorth*0.5);
            rating = qBound(1.0, rating, 10.0);

            forwardRatings.append(rating);
        }
    } else {
        qDebug() << "Ya bhim query ghalta (fw):" << fwQuery.lastError().text();
    }

    // Helper function to display player info
    auto displayForward = [&](const QString& position, int index) {
        if (index >= forwards.size()) {
            if (playerNameLabels.contains(position)) {
                playerNameLabels[position]->setText("No player found");
            }
            if (playerRateLabels.contains(position)) {
                playerRateLabels[position]->setText("--");
                playerRateLabels[position]->setStyleSheet(ratingStyle);
            }
            if (playerFaceLabels.contains(position)) {
                playerFaceLabels[position]->clear();
            }
            return;
        }

        if (playerNameLabels.contains(position)) {
            playerNameLabels[position]->setText(forwards[index]);
        }
        if (playerRateLabels.contains(position)) {
            playerRateLabels[position]->setText(QString::number(forwardRatings[index], 'f', 1));
            playerRateLabels[position]->setStyleSheet(ratingStyle);
        }
        if (playerFaceLabels.contains(position) && index < forwardFaceImages.size()) {
            QString imagePath = forwardFaceImages[index];
            QPixmap pixmap(imagePath);

            if (!pixmap.isNull()) {
                playerFaceLabels[position]->setPixmap(pixmap.scaled(
                    playerFaceLabels[position]->size(),
                    Qt::KeepAspectRatio,
                    Qt::SmoothTransformation
                    ));
            } else {
                pixmap.load(":/images/default_player.png");
                if (!pixmap.isNull()) {
                    playerFaceLabels[position]->setPixmap(pixmap.scaled(
                        playerFaceLabels[position]->size(),
                        Qt::KeepAspectRatio,
                        Qt::SmoothTransformation
                        ));
                }
            }
        }
    };

    displayForward("ST", 0);
    displayForward("LW", 1);
    displayForward("RW", 2);


    QPushButton* closeButton = new QPushButton("Close", teamTypeDialog);
    mainLayout->addWidget(closeButton);
    connect(closeButton, &QPushButton::clicked, teamTypeDialog, &QDialog::accept);

    teamTypeDialog->setMinimumSize(formWidget->size());
    teamTypeDialog->exec();

    delete teamTypeDialog;
}

