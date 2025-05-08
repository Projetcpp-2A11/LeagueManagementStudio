#include "matchpage.h"
#include "employee.h"
#include "homepage.h"
#include "match.h"
#include <QVBoxLayout>
#include <QMessageBox>
#include <QSqlError>
#include "matchesupdateform.h"
#include "ui_matchpage.h"
#include "dialog.h"
#include "DialogPronostic.h"


#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QDesktopServices>
#include <QUrl>
#include <QHeaderView>
#include <QStandardPaths>
#include <QDir>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarSeries>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>
#include <QProcess>




MatchPage::MatchPage(QWidget *parent, employee *loggedInEmployee)
    : QWidget(parent)
    , ui(new Ui::MatchPage),
    loggedIneEmp(loggedInEmployee)

{
    setWindowTitle("Match Page");  // Mise à jour du titre de la fenêtre
    ui->setupUi(this);

    setMinimumSize(1000, 800);
    resize(800, 600);

    // Appliquer un layout pour assurer un bon redimensionnement
    QVBoxLayout *layout = new QVBoxLayout(this);
    setLayout(layout);
    loadTeamsIntoComboBox();
    loadStadiumsIntoComboBox();
    //loadMatches();
    Match m;
    m.listMatchesInTable(ui->matchsTable);
    addButtonsToRows(ui->matchsTable);

}

MatchPage::~MatchPage()
{
    delete ui;
}

void MatchPage::on_addMatchButton_clicked()
{
    // Réinitialiser les messages d'erreur
    ui->messscore->clear();
    ui->messscore->setVisible(false);

    ui->messstaduim->clear();
    ui->messstaduim->setVisible(false);
    ui->messteam->clear();
    ui->messteam->setVisible(false);
    ui->messteam_2->clear();
    ui->messteam_2->setVisible(false);
    ui->messdate->clear();
    ui->messdate->setVisible(false);

    QString score = ui->score->text().trimmed();
    QDate date = ui->datematch->date();
    int stadiumID = ui->stade->currentData().toInt();
    int team1ID = ui->team1->currentData().toInt();
    int team2ID = ui->team2->currentData().toInt();

    bool hasError = false;

    // Vérifier si le champ score est vide ou mal formaté
    QRegularExpression scoreRegExp("^\\d+-\\d+$");  // Utilisation de QRegularExpression au lieu de QRegExp
    if (score.isEmpty()) {
        ui->messscore->setText("<b><font color='red'>Please enter a score.</font></b>");
        ui->messscore->setVisible(true);  // Afficher le message d'erreur
        hasError = true;
    } else if (!scoreRegExp.match(score).hasMatch()) {  // Remplacez "exactMatch" par "match"
        ui->messscore->setText("<b><font color='red'>Please enter a valid score in the format score-score.</font></b>");
        ui->messscore->setVisible(true);  // Afficher le message d'erreur
        hasError = true;
    }

    // Vérifier si les équipes sont sélectionnées et ne sont pas identiques
    if (team1ID == 0) {
        ui->messteam->setText("<b><font color='red'>Please select team 1.</font></b>");
        ui->messteam->setVisible(true);
        hasError = true;
    }
    if (team2ID == 0) {
        ui->messteam_2->setText("<b><font color='red'>Please select team 2.</font></b>");
        ui->messteam_2->setVisible(true);
        hasError = true;
    }

    if (team1ID == team2ID) {
        ui->messteam->setText("<b><font color='red'>Team 1 and Team 2 cannot be the same.</font></b>");
        ui->messteam->setVisible(true);
        hasError = true;
    }

    // Vérifier si le stade est sélectionné
    if (stadiumID == 0) {
        ui->messstaduim->setText("<b><font color='red'>Please select a stadium.</font></b>");
        ui->messstaduim->setVisible(true);
        hasError = true;
    }

    // Vérifier si la date est après le 04-03-2025
    QDate validDate(2025, 3, 4);  // Date minimum autorisée
    if (date < validDate) {
        ui->messdate->setText("<b><font color='red'>The date must be after 04-03-2025.</font></b>");
        ui->messdate->setVisible(true);
        hasError = true;
    }

    // Si des erreurs sont présentes, ne pas ajouter le match
    if (hasError) {
        QMessageBox::warning(this, "Error", "Please fill all fields correctly");
        return;
    }

    // Vérifier si le match existe déjà dans la base de données
    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT COUNT(*) FROM MATCHES WHERE TEAM1ID = :team1ID AND TEAM2ID = :team2ID AND MATCHDATE = :matchDate AND SCORE = :score");
    checkQuery.bindValue(":team1ID", team1ID);
    checkQuery.bindValue(":team2ID", team2ID);
    checkQuery.bindValue(":matchDate", date);
    checkQuery.bindValue(":score", score);

    if (!checkQuery.exec()) {
        qDebug() << "Error checking for duplicate match: " << checkQuery.lastError().text();
        return;
    }

    checkQuery.next();
    int count = checkQuery.value(0).toInt();
    if (count > 0) {
        QMessageBox::warning(this, "Duplicate Match", "This match already exists in the database.");
        return;  // Sortir si le match est déjà existant
    }


    // Si aucun match dupliqué n'est trouvé, ajouter le match
    Match match(team1ID, team2ID, date, score, stadiumID);
    if (match.ajouter()) {
        QMessageBox::information(this, "Success", "Match added successfully");
        qDebug() << "Match successfully added to the database.";
        refresh();
    } else {
        QMessageBox::critical(this, "Error", "Error adding match");
        qDebug() << "Error adding match to the database.";
    }
}

void MatchPage::on_delete_match_clicked(int row)
{
    qDebug() << "delete clicked";
    int matchID = ui->matchsTable->item(row, 0)->data(Qt::UserRole).toInt();  // Get MatchID from the first column
    Match m;
    if (m.supprimer(matchID)) {
        qDebug("supp");
        refresh();

    }


}

void MatchPage::on_update_match_clicked(int row)
{

    qDebug() << "update clicked" << row;
    int matchID =  ui->matchsTable->item(row, 0)->data(Qt::UserRole).toInt();
    matchesUpdateForm * updatePage = new matchesUpdateForm(nullptr,matchID);
    updatePage->show();


}





void MatchPage::loadTeamsIntoComboBox() {
    QSqlQuery query;
    query.prepare("SELECT teamid, name FROM teams");

    if (!query.exec()) {
        qDebug() << "Erreur lors du chargement des équipes :" << query.lastError().text();
        return;
    }

    qDebug("executing query");

    if (!query.next()) {  // Check if there is at least one result
        qDebug() << "No teams found!";
        return;
    }

    ui->team1->clear();
    ui->team2->clear();

    do {  // Use a do-while loop since we've already called next() once
        int teamID = query.value(0).toInt();
        QString teamName = query.value(1).toString();
        qDebug() << "Team: " << teamName << " ID: " << teamID;

        ui->team1->addItem(teamName, teamID);
        ui->team2->addItem(teamName, teamID);
    } while (query.next());
}
void MatchPage::loadStadiumsIntoComboBox() {
    QSqlQuery query;
    query.prepare("SELECT stadiumid, name FROM stadium");

    if (!query.exec()) {
        qDebug() << "Erreur lors du chargement des stades :" << query.lastError().text();
        return;
    }

    qDebug("executing query");

    if (!query.next()) {  // Check if there is at least one result
        qDebug() << "No stadiums found!";
        return;
    }

    ui->stade->clear();  // Assuming the combo box for stadium is called "stadiumComboBox"

    do {  // Use a do-while loop since we've already called next() once
        int stadiumID = query.value(0).toInt();
        QString stadiumName = query.value(1).toString();
        qDebug() << "Stadium: " << stadiumName << " ID: " << stadiumID;

        ui->stade->addItem(stadiumName, stadiumID);  // Adding stadium name and ID as user data
    } while (query.next());
}


void MatchPage::addButtonsToRows(QTableWidget* table)
{
    for (int row = 0; row < table->rowCount(); ++row) {
        QPushButton* deleteButton = new QPushButton("Delete");
        QPushButton* updateButton = new QPushButton("Update");
        QPushButton* pronosticButton = new QPushButton("Pronostic");
        QPushButton* simulationButton = new QPushButton("Simulation"); // Nouveau bouton


        // Récupération du MATCHID depuis la table
        QTableWidgetItem *idItem = table->item(row, 0);
        int matchID = idItem->data(Qt::UserRole).toInt();

        // Stocker le MATCHID dans le bouton
        pronosticButton->setProperty("matchID", matchID);
        simulationButton->setProperty("matchID", matchID);


        QWidget* actionWidget = new QWidget();
        QHBoxLayout* actionLayout = new QHBoxLayout(actionWidget);
        actionLayout->setContentsMargins(0, 0, 0, 0);
        actionLayout->setSpacing(10);

        actionLayout->addWidget(deleteButton);
        actionLayout->addWidget(updateButton);
        actionLayout->addWidget(pronosticButton);
        actionLayout->addWidget(simulationButton); // Ajout du bouton simulation


        actionWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        table->setCellWidget(row, 5, actionWidget);

        // Connexion avec gestion dynamique du MATCHID
        connect(deleteButton, &QPushButton::clicked, [this, row]() {
            on_delete_match_clicked(row);
        });

        connect(updateButton, &QPushButton::clicked, [this, row]() {
            on_update_match_clicked(row);
        });
        connect(pronosticButton, &QPushButton::clicked, [this, matchID]() {
            DialogPronostic::ShowPronostic(matchID, this);
        });;
        connect(simulationButton, &QPushButton::clicked, [this, matchID]() {
            on_simulate_match_clicked(matchID); // Méthode que tu dois créer
        }) ;;

        // Adjust the column and row size to ensure enough space for the buttons
        table->setColumnWidth(4, 100);  // Adjust column width for the actions column
        table->setRowHeight(row, 60);   // Set row height for the actions row


    }
}

void MatchPage::refresh()
{
    ui->matchsTable->clearContents();
    ui->matchsTable->setRowCount(0);  // Reset row count

    // Repopulate the table with updated employee data
    m.listMatchesInTable(ui->matchsTable) ;
    addButtonsToRows(ui->matchsTable);
}
void MatchPage::on_simulate_match_clicked(int matchID)
{
    QString program = QCoreApplication::applicationFilePath();
    QStringList arguments;
    arguments << "--simulate" << QString::number(matchID);

    QProcess* process = new QProcess(this);
    process->start(program, arguments);
}


void MatchPage::on_refresh_clicked()
{
    refresh();
}

void MatchPage::on_searchButton_clicked()
{
    QString searchText = ui->searchMatchInput->text().trimmed();

    if (searchText.isEmpty()) {
        QMessageBox::information(this, "Info", "Please enter a team name to search.");
        return;
    }

    // Créer une liste pour les filtres à appliquer
    QList<QString> filters;

    // Ajouter les filtres nécessaires ici
    // Exemple : Vous pouvez les récupérer depuis des éléments d'interface utilisateur comme des champs de dates ou de stade
    filters.append("");  // Ajoutez la date de début (par exemple, un champ de texte ou un sélecteur)
    filters.append("");  // Ajoutez la date de fin
    filters.append("");  // Ajoutez le nom du stade
    filters.append("");  // Ajoutez le résultat du match (gagné, perdu, match nul)

    // Appel de la fonction pour effectuer la recherche
    Match match;  // Vous pouvez également appeler la fonction en tant que méthode statique si vous préférez
    match.searchMatches(searchText, filters, ui->matchsTable);

    // Appel de la fonction pour ajouter les boutons
    addButtonsToRows(ui->matchsTable);
}


void MatchPage::connectFilterDialog()
{
    Dialog *filterDialog = new Dialog(this);

    // Connecter le signal filtersApplied du Dialog à la fonction de mise à jour des matchs
    connect(filterDialog, &Dialog::filtersApplied, this, &MatchPage::updateFilteredMatches);

    filterDialog->exec();  // Afficher la fenêtre de dialogue
}

void MatchPage::on_filterButton_clicked()
{
    // Créer une instance de Dialog
    Dialog filterDialog(this);

    // Connecter le signal filtersApplied du Dialog au slot pour traiter les filtres
    connect(&filterDialog, &Dialog::filtersApplied, this, &MatchPage::updateFilteredMatches);

    // Afficher la boîte de dialogue
    filterDialog.exec();  // `exec()` bloque jusqu'à ce que l'utilisateur ferme la boîte de dialogue
}


void MatchPage::updateFilteredMatches(const QList<QString>& filters)
{
    QString selectedStartDate = filters.value(0, "").trimmed();
    QString selectedEndDate = filters.value(1, "").trimmed();
    QString selectedStadium = filters.value(2, "").trimmed();
    QString matchResult = filters.value(3, "").trimmed();
    QString searchText = ui->searchMatchInput->text().trimmed();
    QString sortOrder = filters.size() > 4 ? filters[4] : "DESC";

    QString queryString = R"(
        SELECT M.MATCHID, T1.NAME AS TEAM1, T2.NAME AS TEAM2,
               M.MATCHDATE, M.SCORE, ST.NAME AS STADIUMNAME
        FROM MATCHES M
        JOIN TEAMS T1 ON M.TEAM1ID = T1.TEAMID
        JOIN TEAMS T2 ON M.TEAM2ID = T2.TEAMID
        JOIN STADIUM ST ON M.STADIUMID = ST.STADIUMID
        WHERE 1=1
    )";

    if (!searchText.isEmpty()) {
        queryString += " AND (UPPER(T1.NAME) LIKE UPPER(:searchText) OR UPPER(T2.NAME) LIKE UPPER(:searchText))";
    }
    if (!selectedStartDate.isEmpty()) {
        queryString += " AND M.MATCHDATE >= TO_DATE(:startDate, 'YYYY-MM-DD')";
    }
    if (!selectedEndDate.isEmpty()) {
        queryString += " AND M.MATCHDATE <= TO_DATE(:endDate, 'YYYY-MM-DD')";
    }
    if (!selectedStadium.isEmpty()) {
        queryString += " AND UPPER(ST.NAME) LIKE UPPER(:stadiumName)";
    }

    QString scoreLogic;
    if (!matchResult.isEmpty()) {
        scoreLogic = QString(R"(
            (
                (UPPER(T1.NAME) LIKE UPPER(:searchText) AND
                    (%1)
                )
                OR
                (UPPER(T2.NAME) LIKE UPPER(:searchText) AND
                    (%2)
                )
            )
        )")
                         .arg(
                             (matchResult == "Gagné") ? "CAST(SUBSTR(M.SCORE, 1, INSTR(M.SCORE, '-') - 1) AS INTEGER) > CAST(SUBSTR(M.SCORE, INSTR(M.SCORE, '-') + 1) AS INTEGER)"
                             : (matchResult == "Perdu") ? "CAST(SUBSTR(M.SCORE, 1, INSTR(M.SCORE, '-') - 1) AS INTEGER) < CAST(SUBSTR(M.SCORE, INSTR(M.SCORE, '-') + 1) AS INTEGER)"
                                                        : "CAST(SUBSTR(M.SCORE, 1, INSTR(M.SCORE, '-') - 1) AS INTEGER) = CAST(SUBSTR(M.SCORE, INSTR(M.SCORE, '-') + 1) AS INTEGER)"
                             )
                         .arg(
                             (matchResult == "Gagné") ? "CAST(SUBSTR(M.SCORE, INSTR(M.SCORE, '-') + 1) AS INTEGER) > CAST(SUBSTR(M.SCORE, 1, INSTR(M.SCORE, '-') - 1) AS INTEGER)"
                             : (matchResult == "Perdu") ? "CAST(SUBSTR(M.SCORE, INSTR(M.SCORE, '-') + 1) AS INTEGER) < CAST(SUBSTR(M.SCORE, 1, INSTR(M.SCORE, '-') - 1) AS INTEGER)"
                                                        : "CAST(SUBSTR(M.SCORE, INSTR(M.SCORE, '-') + 1) AS INTEGER) = CAST(SUBSTR(M.SCORE, 1, INSTR(M.SCORE, '-') - 1) AS INTEGER)"
                             );

        queryString += " AND (" + scoreLogic + ")";
    }



    // 🔹 Debugging
    qDebug() << "Requête SQL générée : " << queryString;
    qDebug() << "Start Date:" << selectedStartDate;
    qDebug() << "End Date:" << selectedEndDate;
    qDebug() << "Stadium:" << selectedStadium;
    qDebug() << "Search Text:" << searchText;
    qDebug() << "Match Result:" << matchResult;
    queryString += QString(" ORDER BY M.MATCHDATE %1").arg(sortOrder);

    qDebug() << "Requête finale:" << queryString;

    // 🔹 Exécution de la requête
    QSqlQuery query;
    query.prepare(queryString);

    if (!searchText.isEmpty()) {
        query.bindValue(":searchText", "%" + searchText + "%");
    }
    if (!selectedStartDate.isEmpty()) {
        query.bindValue(":startDate", selectedStartDate);
    }
    if (!selectedEndDate.isEmpty()) {
        query.bindValue(":endDate", selectedEndDate);
    }
    if (!selectedStadium.isEmpty()) {
        query.bindValue(":stadiumName", "%" + selectedStadium + "%");
    }

    if (!query.exec()) {
        qDebug() << "Échec de la requête SQL: " << query.lastError().text();
        return;
    }



    if (!query.exec()) {
        qDebug() << "Erreur SQL:" << query.lastError().text();
        return;
    }
    // 🔹 Mise à jour du tableau
    ui->matchsTable->clearContents();
    ui->matchsTable->setRowCount(0);

    int row = 0;
    while (query.next()) {
        ui->matchsTable->insertRow(row);
        ui->matchsTable->setItem(row, 0, new QTableWidgetItem(query.value(1).toString()));
        ui->matchsTable->setItem(row, 1, new QTableWidgetItem(query.value(2).toString()));
        ui->matchsTable->setItem(row, 2, new QTableWidgetItem(query.value(3).toDate().toString("yyyy-MM-dd")));
        ui->matchsTable->setItem(row, 3, new QTableWidgetItem(query.value(4).toString()));
        ui->matchsTable->setItem(row, 4, new QTableWidgetItem(query.value(5).toString()));

        ui->matchsTable->item(row, 0)->setData(Qt::UserRole, query.value(0).toInt());
        ++row;
    }

    // 🔹 Ajouter les boutons
    addButtonsToRows(ui->matchsTable);


}


void MatchPage::on_exportListButton_clicked()
{
    // Sélection du fichier de sortie
    QString fileName = QFileDialog::getSaveFileName(
        this,
        "Exporter les matchs",
        "",
        "Fichiers CSV (*.csv)"
        );

    if (fileName.isEmpty()) return;

    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "Erreur", "Impossible de créer le fichier");
        return;
    }

    QTextStream stream(&file);
    stream.setEncoding(QStringConverter::Utf8);
    stream.setGenerateByteOrderMark(true); // Important pour Excel

    // Écriture de l'en-tête
    stream << "Team 1;Team 2;Date;Score;Stadium\n";

    // Parcours des lignes du tableau
    for (int row = 0; row < ui->matchsTable->rowCount(); ++row) {
        QStringList rowData;

        // Team 1 (colonne 0)
        rowData << ui->matchsTable->item(row, 0)->text();

        // Team 2 (colonne 1)
        rowData << ui->matchsTable->item(row, 1)->text();

        // Date (colonne 2)
        rowData << ui->matchsTable->item(row, 2)->text();

        // Score (colonne 3) - Correction du format
        QString score = ui->matchsTable->item(row, 3)->text();

        /*// 1. Supprimer les suffixes de date (ex: "janv", "févr")
        score.replace(QRegularExpression("[^0-9-]"), "");*/

        // 2. Forcer le format "X-Y" (ex: "6-7")
        score = QString::number(score.section('-', 0, 0).toInt()) + "-"
                + QString::number(score.section('-', 1, 1).toInt());

        // 3. Ajouter un préfixe pour Excel
        rowData << "\t" + score; // Le caractère \t force le format texte

        // Stadium (colonne 4)
        rowData << ui->matchsTable->item(row, 4)->text();

        stream << rowData.join(";") << "\n";
    }

    file.close();
    QDesktopServices::openUrl(QUrl::fromLocalFile(fileName));
}



void MatchPage::on_statButton_clicked()
{
    // Call the function to display the match counts for teams
    m.displayTeamGoalStats();
}


void MatchPage::on_homeButton_clicked()
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


void MatchPage::on_exitButton_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Exit Confirmation",
                                  "Are you sure you want to logout and exit?",
                                  QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        QApplication::quit();
    }
}

