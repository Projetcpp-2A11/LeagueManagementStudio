#ifndef PARTNERPAGE_H
#define PARTNERPAGE_H

#include <QWidget>
#include "employee.h"
#include "ui_partnerpage.h"
#include "partner.h"


// Inclus le fichier correct pour PartnerPage

namespace Ui {
class partnerpage;  // Changement du nom de classe
}

class PartnerPage : public QWidget
{
    Q_OBJECT

public:
    explicit PartnerPage(QWidget *parent = nullptr, employee * loggedInEmployee = nullptr);
    ~PartnerPage();
    void loadTeams();


    void loadStadiums();
    void loadPartners();
    int getPartnerIdByName(const QString& partnerName) const;
    int getTeamIdByName(const QString &teamName) const;
    Partner getPartnerById(int partnerId);  // Déclaration de la méthode
    QList<int> getAllTeamIds();
    void showTeamRatings();
    QVector<bool> getMatchResultsForTeam(int teamId);
    void recommendBestTeam();
    //*************


    QPair<int, int> getTeamWinStats(int teamId);
    QString recommendBestTeam(const QList<int> &teamIds);


private slots:
    void on_addPartnerButton_clicked();  // Méthode mise à jour pour ajouter un partenaire

    void on_addPartnerandSponsor_clicked();

    void on_refrechebutton_clicked();

    void on_searchButton_clicked();





    void on_filterButton_clicked();

    void on_exportListButton_clicked();
    //void showAverageSponsorshipDuration();
    void on_start_clicked();
    void on_deletepartner_clicked();
    //void on_updatePartner_clicked() ;




    void on_updatepartner_clicked();



    void on_recommend_2_clicked();  // déjà présent
    void recommendAndDisplayBestTeam();  // déjà présent
    //void showRecommendationDialog(const QList<QMap<QString, QVariant>> &statsList, const QString &bestTeamName);




    void on_homeButton_clicked();

    void on_exitButton_clicked();

private:
    Ui::partnerpage *ui;  // Changement du nom de la variable pour PartnerPage
    QVector<bool> getTeamMatchResults(int teamId);
    int calculateRecommendationScore(const QVector<bool>& results);
    // QString recommendBestTeam(const QList<int>& teamIds);
    QString getTeamNameById(int teamId);      // Supposée pour récupérer le nom de l'équipe
    employee *loggedIneEmp;


};

#endif // PARTNERPAGE_H
