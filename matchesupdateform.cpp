#include "matchesupdateform.h"
#include "qsqlerror.h"
#include "qsqlquery.h"
#include "ui_matchesupdateform.h"
#include <QMessageBox>

matchesUpdateForm::matchesUpdateForm(QWidget *parent, int matchID) :
    QWidget(parent),
    ui(new Ui::matchesUpdateForm)
{
    ui->setupUi(this);
    ui->matchIDLabel->setText(QString::number(matchID));






    QSqlQuery query;
    query.prepare(R"(
    SELECT m.matchid, m.team1id, m.team2id, m.score, m.stadiumid, m.matchdate,
           t1.name AS team1_name, t2.name AS team2_name, s.name AS stadium_name
    FROM matches m
    JOIN teams t1 ON m.team1id = t1.teamid
    JOIN teams t2 ON m.team2id = t2.teamid
    JOIN stadium s ON m.stadiumid = s.stadiumid
    WHERE m.matchid = :matchID
)");

    query.bindValue(":matchID", matchID);




    if (query.exec() && query.next()) {
        ui->score->setText(query.value("score").toString());
        ui->dateEdit->setDate(query.value("matchdate").toDate());

        // Set combo boxes with the team names and stadium name
        ui->team1->addItem(query.value("team1_name").toString(), query.value("team1id").toInt());
        ui->team2->addItem(query.value("team2_name").toString(), query.value("team2id").toInt());
        ui->stadium->addItem(query.value("stadium_name").toString(), query.value("stadiumid").toInt());

    } else {
        qDebug() << "Failed to fetch matches data for matchId" << matchID << ":" << query.lastError();
    }

    QSqlQuery teamQuery("SELECT teamid, name FROM teams");
    while (teamQuery.next()) {
        ui->team1->addItem(teamQuery.value("name").toString(), teamQuery.value("teamid"));
        ui->team2->addItem(teamQuery.value("name").toString(), teamQuery.value("teamid"));
    }

    // Load stadiums into the stadium combo box
    QSqlQuery stadiumQuery("SELECT stadiumid, name FROM stadium");
    while (stadiumQuery.next()) {
        ui->stadium->addItem(stadiumQuery.value("name").toString(), stadiumQuery.value("stadiumid"));
    }



}

matchesUpdateForm::~matchesUpdateForm()
{
    delete ui;
}

void matchesUpdateForm::on_save_exit_clicked()
{
    // Réinitialiser les messages d'erreur
    ui->mesupscore->clear();
    ui->mesupscore->setVisible(false);
    ui->mesupstaduim->clear();
    ui->mesupstaduim->setVisible(false);
    ui->mesupteam->clear();
    ui->mesupteam->setVisible(false);
    ui->mesupteam2->clear();
    ui->mesupteam2->setVisible(false);
    ui->mesupdate->clear();
    ui->mesupdate->setVisible(false);


    // Récupérer les valeurs mises à jour depuis l'interface utilisateur
    int matchID = ui->matchIDLabel->text().toInt();
    QString score = ui->score->text().trimmed();
    QDate matchDate = ui->dateEdit->date();
    int team1ID = ui->team1->currentData().toInt();
    int team2ID = ui->team2->currentData().toInt();
    int stadiumID = ui->stadium->currentData().toInt();

    bool hasError = false;

    // Vérifier si le champ score est vide ou mal formaté
    QRegularExpression scoreRegExp("^\\d+-\\d+$");  // Format du score (ex: 2-1)
    if (score.isEmpty()) {
        ui->mesupscore->setText("<b><font color='red'>Please enter a score.</font></b>");
        ui->mesupscore->setVisible(true);  // Afficher le message d'erreur
        hasError = true;
    } else if (!scoreRegExp.match(score).hasMatch()) {  // Vérifier que le score respecte le format
        ui->mesupscore->setText("<b><font color='red'>Please enter a valid score in the format number-number (score-score).</font></b>");
        ui->mesupscore->setVisible(true);  // Afficher le message d'erreur
        hasError = true;
    }



    // Vérifier si les équipes sont sélectionnées et ne sont pas identiques
    if (team1ID == 0) {
        ui->mesupteam->setText("<b><font color='red'>Please select team 1.</font></b>");
        ui->mesupteam->setVisible(true);  // Afficher le message d'erreur
        hasError = true;
    }
    if (team2ID == 0) {
        ui->mesupteam2->setText("<b><font color='red'>Please select team 2.</font></b>");
        ui->mesupteam2->setVisible(true);  // Afficher le message d'erreur
        hasError = true;
    }

    if (team1ID == team2ID) {
        ui->mesupteam->setText("<b><font color='red'>Team 1 and Team 2 cannot be the same.</font></b>");
        ui->mesupteam->setVisible(true);  // Afficher le message d'erreur
        hasError = true;
    }

    // Vérifier si le stade est sélectionné
    if (stadiumID == 0) {
        ui->mesupstaduim->setText("<b><font color='red'>Please select a stadium.</font></b>");
        ui->mesupstaduim->setVisible(true);  // Afficher le message d'erreur
        hasError = true;
    }
    QDate validDate(2025, 3, 4);  // Date minimum autorisée
    if (matchDate < validDate) {
        ui->mesupdate->setText("<b><font color='red'>The date must be after 04-03-2025.</font></b>");
        ui->mesupdate->setVisible(true);  // Afficher le message d'erreur pour la date
        hasError = true;
    }


    // Si des erreurs sont présentes, ne pas mettre à jour le match
    if (hasError) {
        QMessageBox::warning(this, "Error", "Please fill all fields correctly");
        return;
    }

    // Mise à jour des détails du match dans la base de données
    QSqlQuery query;
    query.prepare("UPDATE matches SET score = :score, matchdate = :matchDate, "
                  "team1id = :team1ID, team2id = :team2ID, stadiumid = :stadiumID "
                  "WHERE matchid = :matchID");

    query.bindValue(":score", score);
    query.bindValue(":matchDate", matchDate);
    query.bindValue(":team1ID", team1ID);
    query.bindValue(":team2ID", team2ID);
    query.bindValue(":stadiumID", stadiumID);
    query.bindValue(":matchID", matchID);

    // Exécution de la requête et vérification du succès
    if (query.exec()) {
        QMessageBox::information(this, "Success", "Match details updated successfully.");
        this->close();  // Fermer le formulaire de mise à jour après l'enregistrement
    } else {
        QMessageBox::warning(this, "Failure", "Failed to update match details.");
        qDebug() << "Error updating match:" << query.lastError();
    }
}

void matchesUpdateForm::on_cancel_clicked()
{
    this->close();  // Fermer le formulaire sans enregistrer
}
