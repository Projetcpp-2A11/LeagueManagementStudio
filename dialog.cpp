#include "dialog.h"
#include "ui_dialog.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    // Définir la date par défaut (04/03/2025)
    QDate defaultDate(2025, 3, 4);  // Date par défaut : 4 mars 2025
    ui->startDateEdit->setDate(defaultDate);  // Appliquer à la date de début
    ui->endDateEdit->setDate(defaultDate);    // Appliquer à la date de fin

    // Charger les stades dans le ComboBox
    loadStadiumsIntoComboBox();

    // Connecter le bouton Appliquer les filtres à la méthode applyFilters
    connect(ui->applyFilterButton, &QPushButton::clicked, this, &Dialog::applyFilters);
}

Dialog::~Dialog()
{
    delete ui;
}

QDate Dialog::getStartDate() const {
    return ui->startDateEdit->date();  // Récupérer la date de début
}

QDate Dialog::getEndDate() const {
    return ui->endDateEdit->date();  // Récupérer la date de fin
}

QString Dialog::getSelectedStadium() const {
    return ui->stadiumComboBox->currentText();  // Récupérer le stade sélectionné
}

QString Dialog::getMatchResult() const
{
    if (ui->wonRadioButton->isChecked()) {
        return "Gagné";
    } else if (ui->lostRadioButton->isChecked()) {
        return "Perdu";
    } else if (ui->drawRadioButton->isChecked()) {
        return "Match nul";
    }
    return "";  // Retourner une chaîne vide si aucune option n'est sélectionnée
}

void Dialog::applyFilters() {
    // Obtenez les valeurs des filtres depuis l'UI
    QDate startDate = getStartDate();
    QDate endDate = getEndDate();
    QString stadium = getSelectedStadium();
    QString matchResult = getMatchResult();

    // Debug : Afficher les valeurs des filtres
    qDebug() << "Filtres appliqués :";
    qDebug() << "Date de début:" << startDate.toString("yyyy-MM-dd");
    qDebug() << "Date de fin:" << endDate.toString("yyyy-MM-dd");
    qDebug() << "Stade sélectionné:" << stadium;
    qDebug() << "Résultat du match:" << matchResult;

    // Créez une liste des filtres appliqués
    QList<QString> filters;
    filters.append(startDate.toString("yyyy-MM-dd"));
    filters.append(endDate.toString("yyyy-MM-dd"));
    filters.append(stadium);
    filters.append(matchResult);  // Ne pas ajouter de texte inutile

    qDebug() << "Liste des filtres envoyée :" << filters;

    // Émettre le signal avec les filtres
    emit filtersApplied(filters);

    // Fermer la fenêtre
    accept();
}


void Dialog::resetFilters() {
    // Réinitialiser les filtres dans l'UI
    ui->startDateEdit->clear();  // Réinitialiser la date de début
    ui->endDateEdit->clear();  // Réinitialiser la date de fin
    ui->stadiumComboBox->setCurrentIndex(0);  // Réinitialiser le stade au premier élément

    // Réinitialiser les boutons radio
    ui->wonRadioButton->setChecked(false);
    ui->lostRadioButton->setChecked(false);
    ui->drawRadioButton->setChecked(false);
}

void Dialog::loadStadiumsIntoComboBox() {
    QSqlQuery query;
    query.prepare("SELECT stadiumid, name FROM stadium");

    if (!query.exec()) {
        qDebug() << "Erreur lors du chargement des stades :" << query.lastError().text();
        return;
    }

    ui->stadiumComboBox->clear();  // Vider les éléments existants

    if (!query.next()) {
        qDebug() << "Aucun stade trouvé!";
        ui->stadiumComboBox->addItem("Aucun stade disponible");
        return;
    }

    do {
        int stadiumID = query.value(0).toInt();
        QString stadiumName = query.value(1).toString();
        ui->stadiumComboBox->addItem(stadiumName, stadiumID);  // Ajouter le nom du stade avec l'ID comme donnée utilisateur
    } while (query.next());
}

void Dialog::on_cancel_clicked()
{
    this->close();  // Fermer le formulaire sans enregistrer
}
