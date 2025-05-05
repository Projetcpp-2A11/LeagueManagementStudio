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
#include <QtCharts>
#include <numeric>
#include <algorithm>

teamsPage::teamsPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::teamsPage)
{
    ui->setupUi(this);
    setMinimumSize(1000, 800);
    resize(800, 600);

    // Créer un widget conteneur pour les boutons
    QWidget* buttonContainer = new QWidget(this);
    buttonContainer->setObjectName("buttonContainer");
    buttonContainer->setFixedHeight(130); // Hauteur augmentée pour accueillir deux boutons
    buttonContainer->setContentsMargins(10, 0, 0, 10);

    // Layout vertical pour contenir les deux boutons
    QVBoxLayout* buttonContainerLayout = new QVBoxLayout(buttonContainer);
    buttonContainerLayout->setContentsMargins(0, 0, 0, 0);
    buttonContainerLayout->setSpacing(10); // Espacement entre les boutons

    // Créer le premier bouton (Afficher les Matchs)
    QPushButton* showMatchesButton = new QPushButton("Teams Form", buttonContainer);
    showMatchesButton->setFixedSize(90, 40);
    showMatchesButton->setStyleSheet(
        "QPushButton {"
        "   background-color: #e74c3c;"
        "   color: white;"
        "   font-weight: bold;"
        "   font-size: 12px;"
        "   border: none;"
        "   border-radius: 4px;"
        "}"
        "QPushButton:hover {"
        "   background-color: #c0392b;"
        "}"
        "QPushButton:pressed {"
        "   background-color: #a93226;"
        "}"
        );

    // Créer le deuxième bouton (Teams Form)
    QPushButton* teamTypeButton = new QPushButton("Teams Type", buttonContainer);
    teamTypeButton->setFixedSize(90, 40);
    teamTypeButton->setStyleSheet(
        "QPushButton {"
        "   background-color: #e74c3c;"
        "   color: white;"
        "   font-weight: bold;"
        "   font-size: 12px;"
        "   border: none;"
        "   border-radius: 4px;"
        "}"
        "QPushButton:hover {"
        "   background-color: #c0392b;"
        "}"
        "QPushButton:pressed {"
        "   background-color: #a93226;"
        "}"
        );

    // Ajouter les boutons au layout vertical
    buttonContainerLayout->addWidget(showMatchesButton);
    buttonContainerLayout->addWidget(teamTypeButton);
    buttonContainerLayout->addStretch(1); // Pousse les boutons vers le haut du conteneur

    // Positionner le conteneur des boutons
    int offset = 300;
    buttonContainer->move(0, height() - buttonContainer->height() - offset);

    // Le reste du code reste inchangé
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

    connect(ui->tabWidgetTeams, &QTabWidget::currentChanged, this, [buttonContainer](int index) {
        // Afficher les boutons uniquement sur l'onglet TeamsList (supposé être l'index 0)
        buttonContainer->setVisible(index == 0);
    });

    connect(ui->tabWidgetTeams, &QTabWidget::currentChanged, this, [this](int index) {
        if (ui->tabWidgetTeams->widget(index) == ui->Stats) {
            teams team;
            team.displayTeamStats(ui->Stats);
        }
    });

    // Connecter le premier bouton à la fonction d'affichage des matchs
    connect(showMatchesButton, &QPushButton::clicked, this, []() {
        teams team;
        team.displayMatchesWithScores();
    });

    // Connecter le deuxième bouton à la fonction TeamType
    connect(teamTypeButton, &QPushButton::clicked, this, &teamsPage::on_TeamType_clicked);

    // Initialiser la visibilité des boutons
    buttonContainer->setVisible(ui->tabWidgetTeams->currentIndex() == 0);
    buttonContainer->raise();
}

// Méthode resizeEvent inchangée
void teamsPage::resizeEvent(QResizeEvent* event)
{
    QWidget::resizeEvent(event);

    // Mettre à jour la position du conteneur des boutons
    QWidget* buttonContainer = findChild<QWidget*>("buttonContainer");
    if (buttonContainer) {
        int offset = 300;
        buttonContainer->move(0, height() - buttonContainer->height() - offset);
    }
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



// trying something new
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
        QPushButton* teamFormButton = new QPushButton("Team Form"); // Nouveau bouton

        QWidget* actionWidget = new QWidget();
        QHBoxLayout* actionLayout = new QHBoxLayout(actionWidget);
        actionLayout->setContentsMargins(0, 0, 0, 0);
        actionLayout->setSpacing(5); // Réduire l'espacement pour accommoder 3 boutons

        actionLayout->addWidget(deleteButton);
        actionLayout->addWidget(updateButton);
        actionLayout->addWidget(teamFormButton); // Ajouter le nouveau bouton

        actionWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        table->setCellWidget(row, 7, actionWidget);

        connect(deleteButton, &QPushButton::clicked, this, [this, row]() {
            on_delete_team_clicked(row);
        });

        connect(updateButton, &QPushButton::clicked, this, [this, row]() {
            on_update_team_clicked(row);
        });

        // Connecter le nouveau bouton à la fonction qui affiche les matchs de l'équipe
        connect(teamFormButton, &QPushButton::clicked, this, [this, row, table]() {
            // Récupérer l'ID de l'équipe à partir de la première colonne (supposée être l'ID)
            QTableWidgetItem* idItem = table->item(row, 0);
            if (idItem) {
                int teamId = idItem->text().toInt();
                displayTeamFormMatches(teamId);
            }
        });

        table->setColumnWidth(7, 300); // Augmenter la largeur pour accommoder 3 boutons
        table->setRowHeight(row, 60);
    }
}

// Nouvelle fonction pour afficher les matchs d'une équipe spécifique
void teamsPage::displayTeamFormMatches(int teamId)
{
    // Créer une nouvelle fenêtre
    QDialog* matchWindow = new QDialog(this);
    matchWindow->setWindowTitle("Matchs de l'équipe");
    matchWindow->setMinimumSize(1000, 700);

    // Créer un layout principal pour la fenêtre
    QVBoxLayout* mainLayout = new QVBoxLayout(matchWindow);

    // Récupérer le nom de l'équipe
    QSqlQuery teamQuery;
    teamQuery.prepare("SELECT NAME FROM TEAMS WHERE TEAMID = :teamId");
    teamQuery.bindValue(":teamId", teamId);

    QString teamName = "Équipe #" + QString::number(teamId);
    if (teamQuery.exec() && teamQuery.next()) {
        teamName = teamQuery.value("NAME").toString();
    }

    // Créer un titre
    QLabel* titleLabel = new QLabel("Matchs joués par " + teamName, matchWindow);
    QFont titleFont = titleLabel->font();
    titleFont.setPointSize(16);
    titleFont.setBold(true);
    titleLabel->setFont(titleFont);
    titleLabel->setAlignment(Qt::AlignCenter);
    mainLayout->addWidget(titleLabel);

    // Créer un widget de défilement pour contenir tous les matchs
    QScrollArea* scrollArea = new QScrollArea(matchWindow);
    scrollArea->setWidgetResizable(true);
    QWidget* scrollContent = new QWidget();
    QVBoxLayout* scrollLayout = new QVBoxLayout(scrollContent);

    // Requête SQL pour récupérer les matchs de cette équipe
    QSqlQuery matchQuery;
    matchQuery.prepare(
        "SELECT m.MATCHID, m.SCORE, m.MATCHDATE, "
        "t1.TEAMID as TEAM1ID, t1.NAME as TEAM1_NAME, t1.LOGO as TEAM1_LOGO, "
        "t2.TEAMID as TEAM2ID, t2.NAME as TEAM2_NAME, t2.LOGO as TEAM2_LOGO "
        "FROM MATCHES m "
        "JOIN TEAMS t1 ON m.TEAM1ID = t1.TEAMID "
        "JOIN TEAMS t2 ON m.TEAM2ID = t2.TEAMID "
        "WHERE m.TEAM1ID = :teamId OR m.TEAM2ID = :teamId "
        "ORDER BY m.MATCHDATE DESC"
        );
    matchQuery.bindValue(":teamId", teamId);

    if (!matchQuery.exec()) {
        qDebug() << "Erreur lors de la récupération des matchs: " << matchQuery.lastError().text();
        QMessageBox::critical(matchWindow, "Erreur", "Impossible de récupérer les données des matchs: " + matchQuery.lastError().text());
        return;
    }

    // Initialiser un compteur pour les matchs
    int currentMatch = 0;

    // Parcourir les matchs
    while (matchQuery.next()) {
        // Ajouter un séparateur avant chaque match sauf le premier
        if (currentMatch > 0) {
            QFrame* line = new QFrame();
            line->setFrameShape(QFrame::HLine);
            line->setFrameShadow(QFrame::Sunken);
            scrollLayout->addWidget(line);
        }

        currentMatch++;

        int matchId = matchQuery.value("MATCHID").toInt();
        QString score = matchQuery.value("SCORE").toString();
        QDateTime matchDate = matchQuery.value("MATCHDATE").toDateTime();

        int team1Id = matchQuery.value("TEAM1ID").toInt();
        QString team1Name = matchQuery.value("TEAM1_NAME").toString();
        QString team1Logo = matchQuery.value("TEAM1_LOGO").toString();

        int team2Id = matchQuery.value("TEAM2ID").toInt();
        QString team2Name = matchQuery.value("TEAM2_NAME").toString();
        QString team2Logo = matchQuery.value("TEAM2_LOGO").toString();

        // Créer un widget pour ce match
        QWidget* matchWidget = new QWidget();
        QVBoxLayout* matchLayout = new QVBoxLayout(matchWidget);

        // Créer un cadre pour le match
        QFrame* matchFrame = new QFrame();
        matchFrame->setFrameShape(QFrame::StyledPanel);
        matchFrame->setFrameShadow(QFrame::Raised);

        // Mettre en évidence l'équipe sélectionnée
        if (team1Id == teamId) {
            matchFrame->setStyleSheet("QFrame { background-color: #e8f4fc; border-radius: 8px; padding: 10px; border-left: 5px solid #3498db; }");
        } else {
            matchFrame->setStyleSheet("QFrame { background-color: #f5f5f5; border-radius: 8px; padding: 10px; }");
        }

        QVBoxLayout* frameLayout = new QVBoxLayout(matchFrame);

        // En-tête du match (date et ID)
        QLabel* matchHeader = new QLabel(QString("Match #%1 - %2")
                                             .arg(matchId)
                                             .arg(matchDate.toString("dd/MM/yyyy")));
        matchHeader->setAlignment(Qt::AlignCenter);
        QFont headerFont = matchHeader->font();
        headerFont.setBold(true);
        headerFont.setPointSize(12);
        matchHeader->setFont(headerFont);
        frameLayout->addWidget(matchHeader);

        // Widget pour les équipes et le score
        QWidget* teamsWidget = new QWidget();
        QHBoxLayout* teamsLayout = new QHBoxLayout(teamsWidget);

        // Équipe 1
        QWidget* team1Widget = new QWidget();
        QVBoxLayout* team1Layout = new QVBoxLayout(team1Widget);

        // Logo de l'équipe 1
        QLabel* team1LogoLabel = new QLabel();
        if (!team1Logo.isEmpty()) {
            QPixmap pixmap(team1Logo);
            if (!pixmap.isNull()) {
                team1LogoLabel->setPixmap(pixmap.scaled(100, 100, Qt::KeepAspectRatio, Qt::SmoothTransformation));
            } else {
                team1LogoLabel->setText("Logo non disponible");
            }
        } else {
            team1LogoLabel->setText("Logo non disponible");
        }
        team1LogoLabel->setAlignment(Qt::AlignCenter);
        team1Layout->addWidget(team1LogoLabel);

        // Nom de l'équipe 1
        QLabel* team1NameLabel = new QLabel(team1Name);
        team1NameLabel->setAlignment(Qt::AlignCenter);
        QFont teamFont = team1NameLabel->font();
        teamFont.setBold(true);
        teamFont.setPointSize(11);
        team1NameLabel->setFont(teamFont);

        // Mettre en évidence l'équipe sélectionnée
        if (team1Id == teamId) {
            team1NameLabel->setStyleSheet("color: #3498db;");
        }

        team1Layout->addWidget(team1NameLabel);

        teamsLayout->addWidget(team1Widget);

        // Score
        QLabel* scoreLabel = new QLabel(score);
        scoreLabel->setAlignment(Qt::AlignCenter);
        QFont scoreFont = scoreLabel->font();
        scoreFont.setBold(true);
        scoreFont.setPointSize(16);
        scoreLabel->setFont(scoreFont);
        scoreLabel->setStyleSheet("color: #d32f2f;");
        teamsLayout->addWidget(scoreLabel);

        // Équipe 2
        QWidget* team2Widget = new QWidget();
        QVBoxLayout* team2Layout = new QVBoxLayout(team2Widget);

        // Logo de l'équipe 2
        QLabel* team2LogoLabel = new QLabel();
        if (!team2Logo.isEmpty()) {
            QPixmap pixmap(team2Logo);
            if (!pixmap.isNull()) {
                team2LogoLabel->setPixmap(pixmap.scaled(100, 100, Qt::KeepAspectRatio, Qt::SmoothTransformation));
            } else {
                team2LogoLabel->setText("Logo non disponible");
            }
        } else {
            team2LogoLabel->setText("Logo non disponible");
        }
        team2LogoLabel->setAlignment(Qt::AlignCenter);
        team2Layout->addWidget(team2LogoLabel);

        // Nom de l'équipe 2
        QLabel* team2NameLabel = new QLabel(team2Name);
        team2NameLabel->setAlignment(Qt::AlignCenter);
        team2NameLabel->setFont(teamFont);

        // Mettre en évidence l'équipe sélectionnée
        if (team2Id == teamId) {
            team2NameLabel->setStyleSheet("color: #3498db;");
        }

        team2Layout->addWidget(team2NameLabel);

        teamsLayout->addWidget(team2Widget);

        frameLayout->addWidget(teamsWidget);

        // Récupérer les performances des équipes pour ce match
        QSqlQuery perfQuery;
        perfQuery.prepare(
            "SELECT tp.TEAMID, t.NAME, tp.POSSESSION, tp.RESULT, tp.NUMSHOT, "
            "tp.CORNERS, tp.TEAMYELLOWCARDS, tp.TEAMREDCARDS "
            "FROM TEAMPERFORMANCE tp "
            "JOIN TEAMS t ON tp.TEAMID = t.TEAMID "
            "WHERE tp.MATCHID = :matchId"
            );
        perfQuery.bindValue(":matchId", matchId);

        if (!perfQuery.exec()) {
            qDebug() << "Erreur lors de la récupération des performances: " << perfQuery.lastError().text();
            continue;
        }

        // Tableau des statistiques
        QWidget* statsWidget = new QWidget();
        QGridLayout* statsLayout = new QGridLayout(statsWidget);

        // En-têtes du tableau
        QStringList headers = {"Équipe", "Possession", "Résultat", "Tirs", "Corners", "Cartons Jaunes", "Cartons Rouges"};
        for (int i = 0; i < headers.size(); ++i) {
            QLabel* headerLabel = new QLabel(headers[i]);
            headerLabel->setAlignment(Qt::AlignCenter);
            QFont font = headerLabel->font();
            font.setBold(true);
            headerLabel->setFont(font);
            statsLayout->addWidget(headerLabel, 0, i);
        }

        int row = 1;
        while (perfQuery.next()) {
            int perfTeamId = perfQuery.value("TEAMID").toInt();
            QString teamName = perfQuery.value("NAME").toString();
            double possession = perfQuery.value("POSSESSION").toDouble();
            QString result = perfQuery.value("RESULT").toString();
            int numShot = perfQuery.value("NUMSHOT").toInt();
            int corners = perfQuery.value("CORNERS").toInt();
            int yellowCards = perfQuery.value("TEAMYELLOWCARDS").toInt();
            int redCards = perfQuery.value("TEAMREDCARDS").toInt();

            // Ajouter les données à la ligne
            QLabel* teamLabel = new QLabel(teamName);
            teamLabel->setAlignment(Qt::AlignCenter);

            // Mettre en évidence l'équipe sélectionnée
            if (perfTeamId == teamId) {
                teamLabel->setStyleSheet("color: #3498db; font-weight: bold;");
            }

            statsLayout->addWidget(teamLabel, row, 0);

            QLabel* possessionLabel = new QLabel(QString::number(possession, 'f', 1) + "%");
            possessionLabel->setAlignment(Qt::AlignCenter);
            statsLayout->addWidget(possessionLabel, row, 1);

            QLabel* resultLabel = new QLabel(result);
            resultLabel->setAlignment(Qt::AlignCenter);
            if (result == "WIN") {
                resultLabel->setStyleSheet("color: green; font-weight: bold;");
            } else if (result == "LOSE") {
                resultLabel->setStyleSheet("color: red;");
            } else {
                resultLabel->setStyleSheet("color: orange;");
            }
            statsLayout->addWidget(resultLabel, row, 2);

            QLabel* numShotLabel = new QLabel(QString::number(numShot));
            numShotLabel->setAlignment(Qt::AlignCenter);
            statsLayout->addWidget(numShotLabel, row, 3);

            QLabel* cornersLabel = new QLabel(QString::number(corners));
            cornersLabel->setAlignment(Qt::AlignCenter);
            statsLayout->addWidget(cornersLabel, row, 4);

            QLabel* yellowCardsLabel = new QLabel(QString::number(yellowCards));
            yellowCardsLabel->setAlignment(Qt::AlignCenter);
            statsLayout->addWidget(yellowCardsLabel, row, 5);

            QLabel* redCardsLabel = new QLabel(QString::number(redCards));
            redCardsLabel->setAlignment(Qt::AlignCenter);
            statsLayout->addWidget(redCardsLabel, row, 6);

            row++;
        }

        frameLayout->addWidget(statsWidget);

        // Ajouter le cadre au layout du match
        matchLayout->addWidget(matchFrame);

        // Ajouter le widget du match au layout de défilement
        scrollLayout->addWidget(matchWidget);
    }

    // Si aucun match n'a été trouvé
    if (currentMatch == 0) {
        QLabel* noMatchesLabel = new QLabel("Aucun match trouvé pour cette équipe.");
        noMatchesLabel->setAlignment(Qt::AlignCenter);
        QFont font = noMatchesLabel->font();
        font.setPointSize(14);
        noMatchesLabel->setFont(font);
        scrollLayout->addWidget(noMatchesLabel);
    }

    // Ajouter un widget vide extensible à la fin pour pousser tout vers le haut
    scrollLayout->addStretch();

    // Configurer la zone de défilement
    scrollArea->setWidget(scrollContent);
    mainLayout->addWidget(scrollArea);

    // Ajouter un bouton pour fermer la fenêtre
    QHBoxLayout* buttonLayout = new QHBoxLayout();
    QPushButton* closeButton = new QPushButton("Fermer", matchWindow);
    closeButton->setMinimumWidth(120);
    buttonLayout->addStretch();
    buttonLayout->addWidget(closeButton);
    buttonLayout->addStretch();
    mainLayout->addLayout(buttonLayout);

    // Connecter le bouton à la fermeture de la fenêtre
    connect(closeButton, &QPushButton::clicked, matchWindow, &QDialog::accept);

    // Afficher la fenêtre
    matchWindow->exec();

    // Nettoyer la mémoire après la fermeture
    delete matchWindow;
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
    // Ask the user where to save the PDF file
    QString fileName = QFileDialog::getSaveFileName(this, tr("Export PDF"),
                                                    QDir::homePath() + "/teams_list.pdf",
                                                    tr("PDF Files (*.pdf)"));

    if (fileName.isEmpty()) {
        return; // User canceled the dialog
    }

    // Make sure the filename ends with .pdf
    if (!fileName.endsWith(".pdf", Qt::CaseInsensitive)) {
        fileName += ".pdf";
    }

    // Get database connection
    QSqlDatabase db = QSqlDatabase::database();
    if (!db.isOpen()) {
        QMessageBox::warning(this, tr("Database Error"), tr("Database connection is not open."));
        return;
    }

    // Execute query to get all teams
    QSqlQuery query;
    if (!query.exec("SELECT * FROM teams")) {
        QMessageBox::warning(this, tr("Query Error"),
                             tr("Failed to execute query: %1").arg(query.lastError().text()));
        return;
    }

    // Check if we have results by moving to the first record
    if (!query.first()) {
        QMessageBox::warning(this, tr("Export Error"), tr("No teams found in the database."));
        return;
    }

    // Create a printer
    QPrinter printer(QPrinter::HighResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(fileName);
    printer.setPageOrientation(QPageLayout::Landscape); // Better for tables

    // Create a painter to paint on the printer
    QPainter painter;
    if (!painter.begin(&printer)) {
        QMessageBox::warning(this, tr("Export Error"),
                             tr("Failed to open PDF file for writing."));
        return;
    }

    // Set up the document
    QFont titleFont = painter.font();
    titleFont.setPointSize(16);
    titleFont.setBold(true);
    painter.setFont(titleFont);

    // Draw a title
    painter.drawText(QRect(0, 100, printer.width(), 50),
                     Qt::AlignHCenter | Qt::AlignTop,
                     tr("Teams List"));

    // Manually define column names based on your database schema
    QStringList columnNames;
    columnNames << "ID" << "Name" << "Country" << "Logo" << "Subscribers" << "Kit" << "Matches Played";

    int numColumns = columnNames.size();

    // Find logo and kit column indices
    int logoColumnIndex = 3;  // Assuming logo is at index 3
    int kitColumnIndex = 5;   // Assuming kit is at index 5

    qDebug() << "Using logo column:" << logoColumnIndex << "and kit column:" << kitColumnIndex;

    // Calculate table dimensions
    int rowHeight = 480; // Increased row height to accommodate larger images
    int tableWidth = printer.width() - 100; // Margins
    int tableX = 50; // Left margin
    int tableY = 200; // Top margin after title

    // Calculate column widths proportionally
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

    // Process the first record (we're already positioned at it from query.first())
    do {
        xPos = tableX;
        int yPos = tableY + (row + 1) * rowHeight;

        // Check if we need a new page
        if (yPos + rowHeight > printer.height() - 50) {
            printer.newPage();
            yPos = 50; // Reset to top of new page
            tableY = 0;
        }

        for (int col = 0; col < numColumns; ++col) {
            QRect cellRect(xPos, yPos, columnWidths[col], rowHeight);
            painter.drawRect(cellRect);

            // Get cell value
            QVariant value = query.value(col);
            QString text = value.toString();

            // Check if this is a logo or kit column
            if ((col == logoColumnIndex || col == kitColumnIndex) && !text.isEmpty()) {
                qDebug() << "Processing image path from database:" << text << "in column" << col;

                // Try to load the image from the path
                QPixmap pixmap;
                bool loaded = false;

                // Try direct path
                if (pixmap.load(text)) {
                    qDebug() << "Successfully loaded image with direct path";
                    loaded = true;
                } else {
                    qDebug() << "Failed to load with direct path, trying absolute path";

                    // Try with absolute path
                    QString absolutePath = QDir::current().absoluteFilePath(text);
                    if (pixmap.load(absolutePath)) {
                        qDebug() << "Successfully loaded image with absolute path:" << absolutePath;
                        loaded = true;
                    } else {
                        qDebug() << "Failed to load with absolute path too";

                        // Try with resource path if it starts with ":"
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
                    // Calculate image size to fit in the cell while maintaining aspect ratio
                    QSize imageSize = pixmap.size();
                    qDebug() << "Original image size:" << imageSize;

                    // Double the original image size
                    int scaledWidth = imageSize.width() * 2;
                    int scaledHeight = imageSize.height() * 2;
                    qDebug() << "Doubled image size:" << scaledWidth << "x" << scaledHeight;

                    // Ensure the scaled image fits within the cell (with padding)
                    int maxWidth = cellRect.width() - 20;  // 10px padding on each side
                    int maxHeight = cellRect.height() - 20; // 10px padding on each side
                    qDebug() << "Max allowed size in cell:" << maxWidth << "x" << maxHeight;

                    // If the doubled size exceeds the cell dimensions, scale it down
                    if (scaledWidth > maxWidth || scaledHeight > maxHeight) {
                        qDebug() << "Doubled size exceeds cell dimensions, scaling down";
                        pixmap = pixmap.scaled(maxWidth, maxHeight, Qt::KeepAspectRatio, Qt::SmoothTransformation);
                    } else {
                        qDebug() << "Using doubled size";
                        pixmap = pixmap.scaled(scaledWidth, scaledHeight, Qt::KeepAspectRatio, Qt::SmoothTransformation);
                    }

                    qDebug() << "Final image size:" << pixmap.size();

                    // Calculate position to center the image in the cell
                    int imgX = cellRect.x() + (cellRect.width() - pixmap.width()) / 2;
                    int imgY = cellRect.y() + (cellRect.height() - pixmap.height()) / 2;

                    // Draw the image (centered in the cell)
                    painter.drawPixmap(imgX, imgY, pixmap);
                } else {
                    // If image loading failed, just draw the text
                    painter.drawText(cellRect, Qt::AlignCenter, text);
                }
            } else {
                // For non-image columns, just draw the text
                painter.drawText(cellRect, Qt::AlignCenter, text);
            }

            xPos += columnWidths[col];
        }

        row++;
    } while (query.next());

    // End painting
    painter.end();

    // Inform the user
    QMessageBox::information(this, tr("Export Successful"),
                             tr("The table has been exported to PDF successfully."));
}

void teamsPage::on_TeamType_clicked()
{
    // Use the path that we know works
    QString uiFilePath = "../../teamstype.ui";
    QFile file(uiFilePath);

    if (!file.exists()) {
        // Fallback to other possible locations if needed
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

    // Open the UI file
    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::warning(this, tr("Error"), tr("Could not open UI file: %1").arg(file.errorString()));
        return;
    }

    // Load the UI file
    QUiLoader loader;
    QWidget* formWidget = loader.load(&file, this);
    file.close();

    if (!formWidget) {
        QMessageBox::warning(this, tr("Error"), tr("Could not load UI file: %1").arg(loader.errorString()));
        return;
    }

    // Create a dialog to display the form
    QDialog* teamTypeDialog = new QDialog(this);
    teamTypeDialog->setWindowTitle("Teams Type aka The GOATS of the league");

    // Set up the dialog layout
    QVBoxLayout* mainLayout = new QVBoxLayout(teamTypeDialog);
    mainLayout->addWidget(formWidget);
    mainLayout->setContentsMargins(0, 0, 0, 0);

    // Find the pitch label and set its pixmap
    QLabel* pitchLabel = formWidget->findChild<QLabel*>("pitchLabel");
    if (pitchLabel) {
        // Try different paths for the pitch image
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

    // Find all the player position labels in the loaded UI
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

    // Find all the player name labels in the loaded UI
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

    // Find all the player rating labels in the loaded UI
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

    // Find all the player face labels in the loaded UI
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

    // Create a map to store player face labels
    QMap<QString, QLabel*> playerFaceLabels;

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

    // Store the face labels in the map
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

    // Load player card image using the same approach as the pitch image
    QPixmap playerCardPixmap;
    bool playerCardLoaded = false;

    // Try different paths for the player card image (same folder as pitchimg.png)
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

        // Try alternative locations
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

    // Set player card pixmaps
    if (playerCardLoaded) {
        // Scale the pixmap to fit the labels if needed
        QList<QLabel*> playerLabels;
        playerLabels << GKlabel << LBlabel << CB1label << CB2label << RBlabel
                     << CM1label << CM2label << CAMlabel << LWlabel << STlabel << RWlabel;

        for (QLabel* label : playerLabels) {
            if (label) {
                // Scale the pixmap to fit the label
                QPixmap scaledPixmap = playerCardPixmap.scaled(label->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
                label->setPixmap(scaledPixmap);
            }
        }
    } else {
        qDebug() << "Ken yjini ldebug hetha w9ayet nbatel l'info";
    }

    // Create a map to store player name labels
    QMap<QString, QLabel*> playerNameLabels;
    QMap<QString, QLabel*> playerRateLabels;

    // Store the name labels in the map
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

    // Store the rating labels in the map
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
            // Enable word wrap to handle long names
            label->setWordWrap(true);

            // Center text horizontally, but align to top vertically to allow for wrapping
            label->setAlignment(Qt::AlignHCenter | Qt::AlignTop);

            // Apply style
            label->setStyleSheet(nameStyle);
        }
    }

    // Query the database to find the best players for each position
    QSqlDatabase db = QSqlDatabase::database();
    if (!db.isOpen()) {
        QMessageBox::warning(this, tr("Database Error"), tr("Database connection is not open."));
        delete teamTypeDialog;
        return;
    }

    // Set style for all rating labels (bigger text size + white color)
    QString ratingStyle = "color: white; font-size: 16px; font-weight: bold;";  // Increased from default size

    // Helper function to display player info
    auto displayPlayer = [&](const QString& position, const QString& playerName, double rating, const QString& faceImagePath) {
        if (playerNameLabels.contains(position)) {
            playerNameLabels[position]->setText(playerName.isEmpty() ? "No player found" : playerName);
        }

        if (playerRateLabels.contains(position)) {
            playerRateLabels[position]->setText(playerName.isEmpty() ? "--" : QString::number(rating, 'f', 1));
            playerRateLabels[position]->setStyleSheet(ratingStyle);
        }

        if (playerFaceLabels.contains(position) && !playerName.isEmpty()) {
            QPixmap pixmap(faceImagePath);

            if (!pixmap.isNull()) {
                playerFaceLabels[position]->setPixmap(pixmap.scaled(
                    playerFaceLabels[position]->size(),
                    Qt::KeepAspectRatio,
                    Qt::SmoothTransformation
                ));
            } else {
                // Load default image if specified path is invalid
                pixmap.load(":/img/default_player.png");
                if (!pixmap.isNull()) {
                    playerFaceLabels[position]->setPixmap(pixmap.scaled(
                        playerFaceLabels[position]->size(),
                        Qt::KeepAspectRatio,
                        Qt::SmoothTransformation
                    ));
                }
            }
        } else if (playerFaceLabels.contains(position)) {
            playerFaceLabels[position]->clear();
        }
    };

    // Function to calculate player rating based on position and stats
    auto calculateRating = [](const QString& position, int goals, int assists, int saves, int yellowCards, int redCards, int minutesPlayed) -> double {
        double matchesWorth = static_cast<double>(minutesPlayed) / 90.0;
        if (matchesWorth < 0.1) matchesWorth = 0.1; // Avoid division by zero or very small numbers

        double rating = 6.0; // Base rating

        if (position == "GK") {
            rating += (saves/matchesWorth*0.5) - (goals/matchesWorth*0.8) - (yellowCards/matchesWorth*0.2) - (redCards/matchesWorth*0.5);
        } else if (position == "CB1" || position == "CB2") {
            rating += (goals/matchesWorth*0.2) + (assists/matchesWorth*0.1) - (yellowCards/matchesWorth*0.4) - (redCards/matchesWorth*1.0);
        } else if (position == "LB" || position == "RB") {
            rating += (goals/matchesWorth*0.3) + (assists/matchesWorth*0.3) - (yellowCards/matchesWorth*0.4) - (redCards/matchesWorth*1.0);
        } else if (position == "CM1" || position == "CM2") {
            rating += (goals/matchesWorth*0.4) + (assists/matchesWorth*0.5) - (yellowCards/matchesWorth*0.2) - (redCards/matchesWorth*0.5);
        } else if (position == "CAM") {
            rating += (goals/matchesWorth*0.5) + (assists/matchesWorth*0.6) - (yellowCards/matchesWorth*0.2) - (redCards/matchesWorth*0.5);
        } else if (position == "LW" || position == "RW") {
            rating += (goals/matchesWorth*0.7) + (assists/matchesWorth*0.4) - (yellowCards/matchesWorth*0.2) - (redCards/matchesWorth*0.5);
        } else if (position == "ST") {
            rating += (goals/matchesWorth*1.0) + (assists/matchesWorth*0.2) - (yellowCards/matchesWorth*0.2) - (redCards/matchesWorth*0.5);
        }

        return qBound(1.0, rating, 10.0); // Ensure rating is between 1 and 10
    };

    // Query for GK position
    {
        QSqlQuery gkQuery;
        gkQuery.prepare(
            "SELECT p.FNAME || ' ' || p.LNAME as FULLNAME, "
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
            "WHERE p.POSITION = 'GK' "
            "GROUP BY p.FNAME, p.LNAME, p.PLAYERID, p.FACEIMG "
            "ORDER BY TOTAL_SAVES DESC, MINUTES_PLAYED DESC"
        );

        if (gkQuery.exec()) {
            if (gkQuery.next()) {
                QString playerName = gkQuery.value("FULLNAME").toString();
                QString faceImg = gkQuery.value("FACEIMG").toString();
                int goals = gkQuery.value("TOTAL_GOALS").toInt();
                int assists = gkQuery.value("TOTAL_ASSISTS").toInt();
                int saves = gkQuery.value("TOTAL_SAVES").toInt();
                int yellowCards = gkQuery.value("YELLOW_CARDS").toInt();
                int redCards = gkQuery.value("RED_CARDS").toInt();
                int minutesPlayed = gkQuery.value("MINUTES_PLAYED").toInt();

                double rating = calculateRating("GK", goals, assists, saves, yellowCards, redCards, minutesPlayed);

                displayPlayer("GK", playerName, rating, faceImg);
            } else {
                displayPlayer("GK", "", 0.0, "");
            }
        } else {
            qDebug() << "Query error for GK:" << gkQuery.lastError().text();
            displayPlayer("GK", "", 0.0, "");
        }
    }

    // Query for LB position
    {
        QSqlQuery lbQuery;
        lbQuery.prepare(
            "SELECT p.FNAME || ' ' || p.LNAME as FULLNAME, "
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
            "WHERE p.POSITION = 'LB' "
            "GROUP BY p.FNAME, p.LNAME, p.PLAYERID, p.FACEIMG "
            "ORDER BY (YELLOW_CARDS + RED_CARDS * 2) ASC, MINUTES_PLAYED DESC"
        );

        if (lbQuery.exec()) {
            if (lbQuery.next()) {
                QString playerName = lbQuery.value("FULLNAME").toString();
                QString faceImg = lbQuery.value("FACEIMG").toString();
                int goals = lbQuery.value("TOTAL_GOALS").toInt();
                int assists = lbQuery.value("TOTAL_ASSISTS").toInt();
                int saves = lbQuery.value("TOTAL_SAVES").toInt();
                int yellowCards = lbQuery.value("YELLOW_CARDS").toInt();
                int redCards = lbQuery.value("RED_CARDS").toInt();
                int minutesPlayed = lbQuery.value("MINUTES_PLAYED").toInt();

                double rating = calculateRating("LB", goals, assists, saves, yellowCards, redCards, minutesPlayed);

                displayPlayer("LB", playerName, rating, faceImg);
            } else {
                displayPlayer("LB", "", 0.0, "");
            }
        } else {
            qDebug() << "Query error for LB:" << lbQuery.lastError().text();
            displayPlayer("LB", "", 0.0, "");
        }
    }

    // Query for CB positions
    {
        QSqlQuery cbQuery;
        cbQuery.prepare(
            "SELECT p.FNAME || ' ' || p.LNAME as FULLNAME, "
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
            "WHERE p.POSITION = 'CB' "
            "GROUP BY p.FNAME, p.LNAME, p.PLAYERID, p.FACEIMG "
            "ORDER BY (YELLOW_CARDS + RED_CARDS * 2) ASC, MINUTES_PLAYED DESC"
        );

        if (cbQuery.exec()) {
            // First CB
            if (cbQuery.next()) {
                QString playerName = cbQuery.value("FULLNAME").toString();
                QString faceImg = cbQuery.value("FACEIMG").toString();
                int goals = cbQuery.value("TOTAL_GOALS").toInt();
                int assists = cbQuery.value("TOTAL_ASSISTS").toInt();
                int saves = cbQuery.value("TOTAL_SAVES").toInt();
                int yellowCards = cbQuery.value("YELLOW_CARDS").toInt();
                int redCards = cbQuery.value("RED_CARDS").toInt();
                int minutesPlayed = cbQuery.value("MINUTES_PLAYED").toInt();

                double rating = calculateRating("CB1", goals, assists, saves, yellowCards, redCards, minutesPlayed);

                displayPlayer("CB1", playerName, rating, faceImg);
            } else {
                displayPlayer("CB1", "", 0.0, "");
            }

            // Second CB
            if (cbQuery.next()) {
                QString playerName = cbQuery.value("FULLNAME").toString();
                QString faceImg = cbQuery.value("FACEIMG").toString();
                int goals = cbQuery.value("TOTAL_GOALS").toInt();
                int assists = cbQuery.value("TOTAL_ASSISTS").toInt();
                int saves = cbQuery.value("TOTAL_SAVES").toInt();
                int yellowCards = cbQuery.value("YELLOW_CARDS").toInt();
                int redCards = cbQuery.value("RED_CARDS").toInt();
                int minutesPlayed = cbQuery.value("MINUTES_PLAYED").toInt();

                double rating = calculateRating("CB2", goals, assists, saves, yellowCards, redCards, minutesPlayed);

                displayPlayer("CB2", playerName, rating, faceImg);
            } else {
                displayPlayer("CB2", "", 0.0, "");
            }
        } else {
            qDebug() << "Query error for CB:" << cbQuery.lastError().text();
            displayPlayer("CB1", "", 0.0, "");
            displayPlayer("CB2", "", 0.0, "");
        }
    }

    // Query for RB position
    {
        QSqlQuery rbQuery;
        rbQuery.prepare(
            "SELECT p.FNAME || ' ' || p.LNAME as FULLNAME, "
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
            "WHERE p.POSITION = 'RB' "
            "GROUP BY p.FNAME, p.LNAME, p.PLAYERID, p.FACEIMG "
            "ORDER BY (YELLOW_CARDS + RED_CARDS * 2) ASC, MINUTES_PLAYED DESC"
        );

        if (rbQuery.exec()) {
            if (rbQuery.next()) {
                QString playerName = rbQuery.value("FULLNAME").toString();
                QString faceImg = rbQuery.value("FACEIMG").toString();
                int goals = rbQuery.value("TOTAL_GOALS").toInt();
                int assists = rbQuery.value("TOTAL_ASSISTS").toInt();
                int saves = rbQuery.value("TOTAL_SAVES").toInt();
                int yellowCards = rbQuery.value("YELLOW_CARDS").toInt();
                int redCards = rbQuery.value("RED_CARDS").toInt();
                int minutesPlayed = rbQuery.value("MINUTES_PLAYED").toInt();

                double rating = calculateRating("RB", goals, assists, saves, yellowCards, redCards, minutesPlayed);

                displayPlayer("RB", playerName, rating, faceImg);
            } else {
                displayPlayer("RB", "", 0.0, "");
            }
        } else {
            qDebug() << "Query error for RB:" << rbQuery.lastError().text();
            displayPlayer("RB", "", 0.0, "");
        }
    }

    // Query for CM positions
    {
        QSqlQuery cmQuery;
        cmQuery.prepare(
            "SELECT p.FNAME || ' ' || p.LNAME as FULLNAME, "
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
            "WHERE p.POSITION = 'CM' "
            "GROUP BY p.FNAME, p.LNAME, p.PLAYERID, p.FACEIMG "
            "ORDER BY TOTAL_ASSISTS DESC, TOTAL_GOALS DESC, MINUTES_PLAYED DESC"
        );

        if (cmQuery.exec()) {
            // First CM
            if (cmQuery.next()) {
                QString playerName = cmQuery.value("FULLNAME").toString();
                QString faceImg = cmQuery.value("FACEIMG").toString();
                int goals = cmQuery.value("TOTAL_GOALS").toInt();
                int assists = cmQuery.value("TOTAL_ASSISTS").toInt();
                int saves = cmQuery.value("TOTAL_SAVES").toInt();
                int yellowCards = cmQuery.value("YELLOW_CARDS").toInt();
                int redCards = cmQuery.value("RED_CARDS").toInt();
                int minutesPlayed = cmQuery.value("MINUTES_PLAYED").toInt();

                double rating = calculateRating("CM1", goals, assists, saves, yellowCards, redCards, minutesPlayed);

                displayPlayer("CM1", playerName, rating, faceImg);
            } else {
                displayPlayer("CM1", "", 0.0, "");
            }

            // Second CM
            if (cmQuery.next()) {
                QString playerName = cmQuery.value("FULLNAME").toString();
                QString faceImg = cmQuery.value("FACEIMG").toString();
                int goals = cmQuery.value("TOTAL_GOALS").toInt();
                int assists = cmQuery.value("TOTAL_ASSISTS").toInt();
                int saves = cmQuery.value("TOTAL_SAVES").toInt();
                int yellowCards = cmQuery.value("YELLOW_CARDS").toInt();
                int redCards = cmQuery.value("RED_CARDS").toInt();
                int minutesPlayed = cmQuery.value("MINUTES_PLAYED").toInt();

                double rating = calculateRating("CM2", goals, assists, saves, yellowCards, redCards, minutesPlayed);

                displayPlayer("CM2", playerName, rating, faceImg);
            } else {
                displayPlayer("CM2", "", 0.0, "");
            }
        } else {
            qDebug() << "Query error for CM:" << cmQuery.lastError().text();
            displayPlayer("CM1", "", 0.0, "");
            displayPlayer("CM2", "", 0.0, "");
        }
    }

    // Query for CAM position
    {
        // Now we know the position is stored as "MF" in the database
        QSqlQuery camQuery;
        camQuery.prepare(
            "SELECT p.FNAME || ' ' || p.LNAME as FULLNAME, "
            "p.PLAYERID, "
            "p.POSITION, "
            "p.FACEIMG, "
            "COALESCE(SUM(pp.NUMGOALS), 0) as TOTAL_GOALS, "
            "COALESCE(SUM(pp.NUMASSISTS), 0) as TOTAL_ASSISTS, "
            "COALESCE(SUM(pp.NUMSAVES), 0) as TOTAL_SAVES, "
            "COALESCE(SUM(pp.NUMYELLOWCARDS), 0) as YELLOW_CARDS, "
            "COALESCE(SUM(pp.NUMREDCARDS), 0) as RED_CARDS, "
            "COALESCE(SUM(pp.PLAYTIMEINMINUTES), 0) as MINUTES_PLAYED "
            "FROM PLAYERS p "
            "LEFT JOIN PLAYERPERFORMANCE pp ON p.PLAYERID = pp.PLAYERID "
            "WHERE UPPER(TRIM(p.POSITION)) = 'MF' "
            "GROUP BY p.FNAME, p.LNAME, p.PLAYERID, p.POSITION, p.FACEIMG "
            "ORDER BY TOTAL_ASSISTS DESC, TOTAL_GOALS DESC, MINUTES_PLAYED DESC"
            );

        if (camQuery.exec()) {

            // Find the best attacking midfielder
            if (camQuery.next()) {
                QString playerName = camQuery.value("FULLNAME").toString();
                QString position = camQuery.value("POSITION").toString();
                QString faceImg = camQuery.value("FACEIMG").toString();
                int goals = camQuery.value("TOTAL_GOALS").toInt();
                int assists = camQuery.value("TOTAL_ASSISTS").toInt();
                int saves = camQuery.value("TOTAL_SAVES").toInt();
                int yellowCards = camQuery.value("YELLOW_CARDS").toInt();
                int redCards = camQuery.value("RED_CARDS").toInt();
                int minutesPlayed = camQuery.value("MINUTES_PLAYED").toInt();

                double rating = calculateRating("CAM", goals, assists, saves, yellowCards, redCards, minutesPlayed);

                // Display as CAM even though stored as MF
                displayPlayer("CAM", playerName, rating, faceImg);
            } else {
                qDebug() << "No MF players found in database";

                // Fallback to direct query for player ID 5 since we know he exists
                QSqlQuery directQuery;
                directQuery.prepare(
                    "SELECT p.FNAME || ' ' || p.LNAME as FULLNAME, "
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
                    "WHERE p.PLAYERID = 5 "  // Directly query player ID 5
                    "GROUP BY p.FNAME, p.LNAME, p.PLAYERID, p.FACEIMG"
                    );

                if (directQuery.exec() && directQuery.next()) {
                    QString playerName = directQuery.value("FULLNAME").toString();
                    QString faceImg = directQuery.value("FACEIMG").toString();
                    int goals = directQuery.value("TOTAL_GOALS").toInt();
                    int assists = directQuery.value("TOTAL_ASSISTS").toInt();
                    int saves = directQuery.value("TOTAL_SAVES").toInt();
                    int yellowCards = directQuery.value("YELLOW_CARDS").toInt();
                    int redCards = directQuery.value("RED_CARDS").toInt();
                    int minutesPlayed = directQuery.value("MINUTES_PLAYED").toInt();

                    qDebug() << "Using direct player ID 5 as CAM:" << playerName;

                    double rating = calculateRating("CAM", goals, assists, saves, yellowCards, redCards, minutesPlayed);
                    displayPlayer("CAM", playerName, rating, faceImg);
                } else {
                    displayPlayer("CAM", "No CAM found", 0.0, "");
                }
            }
        } else {
            qDebug() << "Query error for CAM:" << camQuery.lastError().text();
            displayPlayer("CAM", "Query Error", 0.0, "");
        }
    }

    // Query for LW position
    {
        QSqlQuery lwQuery;
        lwQuery.prepare(
            "SELECT p.FNAME || ' ' || p.LNAME as FULLNAME, "
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
            "WHERE p.POSITION = 'LW' "
            "GROUP BY p.FNAME, p.LNAME, p.PLAYERID, p.FACEIMG "
            "ORDER BY TOTAL_GOALS DESC, TOTAL_ASSISTS DESC, MINUTES_PLAYED DESC"
        );

        if (lwQuery.exec()) {
            if (lwQuery.next()) {
                QString playerName = lwQuery.value("FULLNAME").toString();
                QString faceImg = lwQuery.value("FACEIMG").toString();
                int goals = lwQuery.value("TOTAL_GOALS").toInt();
                int assists = lwQuery.value("TOTAL_ASSISTS").toInt();
                int saves = lwQuery.value("TOTAL_SAVES").toInt();
                int yellowCards = lwQuery.value("YELLOW_CARDS").toInt();
                int redCards = lwQuery.value("RED_CARDS").toInt();
                int minutesPlayed = lwQuery.value("MINUTES_PLAYED").toInt();

                double rating = calculateRating("LW", goals, assists, saves, yellowCards, redCards, minutesPlayed);

                displayPlayer("LW", playerName, rating, faceImg);
            } else {
                displayPlayer("LW", "", 0.0, "");
            }
        } else {
            qDebug() << "Query error for LW:" << lwQuery.lastError().text();
            displayPlayer("LW", "", 0.0, "");
        }
    }

    // Query for ST position
    {
        QSqlQuery stQuery;
        stQuery.prepare(
            "SELECT p.FNAME || ' ' || p.LNAME as FULLNAME, "
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
            "WHERE p.POSITION = 'ST' "
            "GROUP BY p.FNAME, p.LNAME, p.PLAYERID, p.FACEIMG "
            "ORDER BY TOTAL_GOALS DESC, TOTAL_ASSISTS DESC, MINUTES_PLAYED DESC"
        );

        if (stQuery.exec()) {
            if (stQuery.next()) {
                QString playerName = stQuery.value("FULLNAME").toString();
                QString faceImg = stQuery.value("FACEIMG").toString();
                int goals = stQuery.value("TOTAL_GOALS").toInt();
                int assists = stQuery.value("TOTAL_ASSISTS").toInt();
                int saves = stQuery.value("TOTAL_SAVES").toInt();
                int yellowCards = stQuery.value("YELLOW_CARDS").toInt();
                int redCards = stQuery.value("RED_CARDS").toInt();
                int minutesPlayed = stQuery.value("MINUTES_PLAYED").toInt();

                double rating = calculateRating("ST", goals, assists, saves, yellowCards, redCards, minutesPlayed);

                displayPlayer("ST", playerName, rating, faceImg);
            } else {
                displayPlayer("ST", "", 0.0, "");
            }
        } else {
            qDebug() << "Query error for ST:" << stQuery.lastError().text();
            displayPlayer("ST", "", 0.0, "");
        }
    }

    // Query for RW position
    {
        QSqlQuery rwQuery;
        rwQuery.prepare(
            "SELECT p.FNAME || ' ' || p.LNAME as FULLNAME, "
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
            "WHERE p.POSITION = 'RW' "
            "GROUP BY p.FNAME, p.LNAME, p.PLAYERID, p.FACEIMG "
            "ORDER BY TOTAL_GOALS DESC, TOTAL_ASSISTS DESC, MINUTES_PLAYED DESC"
        );

        if (rwQuery.exec()) {
            if (rwQuery.next()) {
                QString playerName = rwQuery.value("FULLNAME").toString();
                QString faceImg = rwQuery.value("FACEIMG").toString();
                int goals = rwQuery.value("TOTAL_GOALS").toInt();
                int assists = rwQuery.value("TOTAL_ASSISTS").toInt();
                int saves = rwQuery.value("TOTAL_SAVES").toInt();
                int yellowCards = rwQuery.value("YELLOW_CARDS").toInt();
                int redCards = rwQuery.value("RED_CARDS").toInt();
                int minutesPlayed = rwQuery.value("MINUTES_PLAYED").toInt();

                double rating = calculateRating("RW", goals, assists, saves, yellowCards, redCards, minutesPlayed);

                displayPlayer("RW", playerName, rating, faceImg);
            } else {
                displayPlayer("RW", "", 0.0, "");
            }
        } else {
            qDebug() << "Query error for RW:" << rwQuery.lastError().text();
            displayPlayer("RW", "", 0.0, "");
        }
    }

    // Add a close button
    QPushButton* closeButton = new QPushButton("Close", teamTypeDialog);
    mainLayout->addWidget(closeButton);
    connect(closeButton, &QPushButton::clicked, teamTypeDialog, &QDialog::accept);

    // Show the dialog
    teamTypeDialog->setMinimumSize(formWidget->size());
    teamTypeDialog->exec();

    // Clean up
    delete teamTypeDialog;
}


void teamsPage::on_prevPageTable_clicked()
{

}


