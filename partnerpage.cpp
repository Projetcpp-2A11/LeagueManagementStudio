#include "partnerpage.h"
#include "homepage.h"
#include "ui_partnerpage.h"
#include "partner.h"
#include "connection.h"
#include <QVBoxLayout>
#include <QMessageBox>
#include <QPdfWriter>
#include <QPainter>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QFileDialog>
#include <QMessageBox>
#include <QtCharts>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include "chatbot.h"
#include "chatbotdialog.h"

#include "connection.h"
#include <QLabel>


PartnerPage::PartnerPage(QWidget *parent, employee *loggedInEmployee)
    : QWidget(parent)
    , ui(new Ui::partnerpage),
    loggedIneEmp(loggedIneEmp)
{
    setWindowTitle("Partner Page");  // Changer le titre de la fenêtre
    ui->setupUi(this);
    QPushButton* chatbotButton = new QPushButton("Chatbot", this);
    connect(chatbotButton, &QPushButton::clicked, this, [=]() {
        ChatbotDialog* dialog = new ChatbotDialog(this);
        dialog->exec();
    });

    setMinimumSize(1000, 800);
    resize(800, 600);

    // Appliquer un layout pour assurer un bon redimensionnement
    QVBoxLayout *layout = new QVBoxLayout(this);
    setLayout(layout);
    loadTeams();
    loadStadiums();
    loadPartners();
    Partner p;
    p.listSponsorshipsInTable(ui->partnersTable);
    //****************


}

PartnerPage::~PartnerPage()
{
    delete ui;
}

void PartnerPage::on_addPartnerButton_clicked()
{
    qDebug("add clicked");

    // Récupérer les valeurs des champs
    QString name = ui->name->text().trimmed();
    QDate startDate = ui->startDate->date(); // Exemple: récupérer la date de début depuis un QDateEdit
    QDate endDate = ui->endDate->date();     // Exemple: récupérer la date de fin depuis un QDateEdit

    // Vérification que le champ 'name' n'est pas vide
    if (name.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez remplir le champ 'Nom' !");
        return;
    }

    // Vérification que la date de début est supérieure à aujourd'hui
    if (startDate < QDate::currentDate()) {
        QMessageBox::warning(this, "Erreur", "La date de début doit être supérieure ou égale à aujourd'hui !");
        return;
    }

    // Vérification que la date de fin est supérieure à la date de début
    if (endDate <= startDate) {
        QMessageBox::warning(this, "Erreur", "La date de fin doit être supérieure à la date de début !");
        return;
    }

    // Création et ajout du partenaire
    Partner p(name);
    if (p.ajouter()) {
        QMessageBox::information(this, "Succès", "Partenaire ajouté avec succès !");

        // Mettre à jour l'affichage de la table
        // ui->partnersTableView->setModel(p.afficher());

        // Réinitialiser les champs
        ui->name->clear();
        ui->startDate->clear();  // Si vous utilisez un QDateEdit pour la date de début
        ui->endDate->clear();    // Si vous utilisez un QDateEdit pour la date de fin
    } else {
        qDebug("not added");
        QMessageBox::critical(this, "Erreur", "Échec de l'ajout du partenaire.");
    }
}


void PartnerPage::loadTeams()
{
    if (!ui || !ui->teamList) {
        qDebug() << "Erreur : ui ou teamList est null !";
        return;
    }

    ui->teamList->clear(); // Clear before adding items

    QSqlQuery query;
    if (!query.exec("SELECT teamid, name FROM teams")) {
        qDebug() << "Erreur SQL : " << query.lastError().text();
        return;
    }

    bool hasData = false;
    while (query.next()) {
        int teamID = query.value(0).toInt();
        QString teamName = query.value(1).toString();
        qDebug() << "Équipe trouvée : " << teamName << " avec ID: " << teamID;

        // Store ID as userData while displaying Name
        ui->teamList->addItem(teamName, teamID);
        hasData = true;
    }

    if (!hasData) {
        qDebug() << "Aucune équipe trouvée dans la base de données.";
    }
}



void PartnerPage::loadStadiums()
{
    if (!ui || !ui->stadiumList) {
        qDebug() << "Erreur : ui ou stadiumList est null !";
        return;
    }

    ui->stadiumList->clear(); // Clear before adding items

    QSqlQuery query;
    if (!query.exec("SELECT stadiumid, name FROM stadium")) {
        qDebug() << "Erreur SQL : " << query.lastError().text();
        return;
    }

    bool hasData = false;
    while (query.next()) {
        int stadiumID = query.value(0).toInt();
        QString stadiumName = query.value(1).toString();
        qDebug() << "Stade trouvé : " << stadiumName << " avec ID: " << stadiumID;

        // Store ID as userData while displaying Name
        ui->stadiumList->addItem(stadiumName, stadiumID);
        hasData = true;
    }

    if (!hasData) {
        qDebug() << "Aucune stade trouvée dans la base de données.";
    }
}
void PartnerPage::loadPartners()
{
    if (!ui || !ui->stadiumList) {
        qDebug() << "Erreur : ui ou stadiumList est null !";
        return;
    }

    ui->partnerList->clear(); // Clear before adding items

    QSqlQuery query;
    if (!query.exec("SELECT partnerid, name FROM partners")) {
        qDebug() << "Erreur SQL : " << query.lastError().text();
        return;
    }

    bool hasData = false;
    while (query.next()) {
        int partnerId = query.value(0).toInt();
        QString partnerName = query.value(1).toString();
        qDebug() << "Partner  " << partnerName << " avec ID: " << partnerId;

        // Store ID as userData while displaying Name
        ui->partnerList->addItem(partnerName, partnerId);
        hasData = true;
    }

    if (!hasData) {
        qDebug() << "Aucune stade trouvée dans la base de données.";
    }
}


void PartnerPage::on_addPartnerandSponsor_clicked()
{
    int partnerID = ui->partnerList->currentData().toInt();
    int teamID = ui->teamList->currentData().toInt();
    int stadiumID = ui->stadiumList->currentData().toInt();
    QDate startDate = ui->startDate->date();
    QDate endDate = ui->endDate->date();



    if (teamID == 0 && stadiumID == 0) {
        QMessageBox::warning(this, "Input Error", "Please select at least a team or a stadium.");
        return;
    }

    Partner partner;

    if (partner.addSponsorship(teamID, stadiumID, partnerID, startDate, endDate)) {
        QMessageBox::information(this, "Success", "Sponsorship added successfully!");
        ui->name->clear();
    } else {
        QMessageBox::critical(this, "Error", "Failed to add sponsorship.");
    }


}




void PartnerPage::on_refrechebutton_clicked()
{
    // Clear existing table data
    ui->partnersTable->clearContents();
    ui->partnersTable->setRowCount(0);

    // Reload sponsorships
    Partner partner;
    partner.listSponsorshipsInTable(ui->partnersTable);
}


void PartnerPage::on_searchButton_clicked()
{
    QString searchText = ui->searchpartner->text().trimmed();  // Supposons que vous avez un QLineEdit pour entrer le texte de recherche

    if (searchText.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer un texte de recherche.");
        return;
    }

    QSqlQuery query;
    query.prepare(R"(
        SELECT p.name AS partner_name,
               t.name AS team_name,
               s.name AS stadium_name,
               sp.sponsorshipstartdate AS start_date,
               sp.sponsorshipenddate AS end_date
        FROM sponsorships sp
        JOIN partners p ON sp.partnerid = p.partnerid
        JOIN teams t ON sp.teamid = t.teamid
        LEFT JOIN stadium s ON sp.stadiumid = s.stadiumid
        WHERE p.name LIKE :searchText
    )");
    query.bindValue(":searchText", "%" + searchText + "%");  // Recherche avec LIKE

    if (query.exec()) {
        ui->partnersTable->setRowCount(0);  // Réinitialiser les lignes du tableau avant d'ajouter les nouveaux résultats
        int row = 0;
        while (query.next()) {
            ui->partnersTable->insertRow(row);
            ui->partnersTable->setItem(row, 0, new QTableWidgetItem(query.value("partner_name").toString()));
            ui->partnersTable->setItem(row, 1, new QTableWidgetItem(query.value("team_name").toString()));
            ui->partnersTable->setItem(row, 2, new QTableWidgetItem(query.value("stadium_name").toString()));
            ui->partnersTable->setItem(row, 3, new QTableWidgetItem(query.value("start_date").toDate().toString("yyyy-MM-dd")));
            ui->partnersTable->setItem(row, 4, new QTableWidgetItem(query.value("end_date").toDate().toString("yyyy-MM-dd")));
            row++;
        }
    } else {
        qDebug() << "Erreur lors de la recherche : " << query.lastError().text();
    }
}

void PartnerPage::on_filterButton_clicked()
{
    // Créer une requête SQL pour récupérer les données triées par la date de fin de la sponsorisation la plus proche
    QSqlQuery query;
    query.prepare("SELECT P.NAME AS PARTNERNAME, T.NAME AS TEAMNAME, ST.NAME AS STADIUMNAME, "
                  "S.SPONSORSHIPSTARTDATE, S.SPONSORSHIPENDDATE "
                  "FROM SPONSORSHIPS S "
                  "JOIN TEAMS T ON S.TEAMID = T.TEAMID "
                  "JOIN STADIUM ST ON S.STADIUMID = ST.STADIUMID "
                  "JOIN PARTNERS P ON S.PARTNERID = P.PARTNERID "
                  "ORDER BY S.SPONSORSHIPENDDATE ASC");  // Tri par la date de fin la plus proche

    if (!query.exec()) {
        qDebug() << "Erreur lors de la récupération des données: " << query.lastError().text();
        return;
    }

    // Effacer le contenu du tableau existant
    ui->partnersTable->clearContents();
    ui->partnersTable->setRowCount(0);

    // Remplir le tableau avec les données récupérées et triées
    int row = 0;
    while (query.next()) {
        ui->partnersTable->insertRow(row);

        // Récupérer et afficher les noms depuis la base de données
        ui->partnersTable->setItem(row, 0, new QTableWidgetItem(query.value("PARTNERNAME").toString()));  // Nom du partenaire
        ui->partnersTable->setItem(row, 1, new QTableWidgetItem(query.value("TEAMNAME").toString()));  // Nom de l'équipe
        ui->partnersTable->setItem(row, 2, new QTableWidgetItem(query.value("STADIUMNAME").toString()));  // Nom du stade
        ui->partnersTable->setItem(row, 3, new QTableWidgetItem(query.value("SPONSORSHIPSTARTDATE").toDate().toString("yyyy-MM-dd")));  // Date de début
        ui->partnersTable->setItem(row, 4, new QTableWidgetItem(query.value("SPONSORSHIPENDDATE").toDate().toString("yyyy-MM-dd")));  // Date de fin

        ++row;
    }

    // Optionnel : Trier par date après insertion (si nécessaire)
    ui->partnersTable->sortItems(4, Qt::AscendingOrder);  // Trier par la colonne 4 (SPONSORSHIPENDDATE)
}


void PartnerPage::on_exportListButton_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Enregistrer en PDF"), "", tr("Fichiers PDF (*.pdf)"));
    if (fileName.isEmpty())
        return;

    QPdfWriter writer(fileName);
    writer.setPageSize(QPageSize::A4);
    writer.setResolution(300);
    writer.setTitle("Liste des Sponsorships");

    QPainter painter(&writer);
    if (!painter.isActive()) {
        QMessageBox::warning(this, "Erreur", "Impossible de créer le fichier PDF.");
        return;
    }

    // Configuration des polices
    QFont titleFont("Arial", 16, QFont::Bold);
    QFont headerFont("Arial", 10, QFont::Bold);
    QFont cellFont("Arial", 9);

    // Marges et dimensions
    const int margin = 40;
    const int rowHeight = 25;
    const int headerHeight = 30;
    int currentPage = 1;

    // Couleurs
    const QColor headerColor(70, 130, 180); // Bleu acier
    const QColor borderColor(200, 200, 200);
    const QColor textColor(0, 0, 0);
    const QColor headerTextColor(255, 255, 255);

    int rowCount = ui->partnersTable->rowCount();
    int colCount = ui->partnersTable->columnCount();

    if (rowCount == 0 || colCount == 0) {
        QMessageBox::warning(this, "Erreur", "Le tableau est vide.");
        painter.end();
        return;
    }

    // Calcul des largeurs de colonnes
    QVector<int> colWidths(colCount);
    int totalWidth = 0;
    for (int col = 0; col < colCount; ++col) {
        colWidths[col] = (writer.width() - 2 * margin) / colCount;
        totalWidth += colWidths[col];
    }

    // Position de départ
    int x = margin;
    int y = margin;

    // Titre principal
    painter.setFont(titleFont);
    painter.setPen(textColor);
    painter.drawText(QRect(0, y, writer.width(), 30), Qt::AlignCenter, "LISTE DES SPONSORSHIPS");
    y += 40;

    // Date
    painter.setFont(cellFont);
    painter.drawText(QRect(0, y, writer.width(), 20), Qt::AlignCenter,
                     QDateTime::currentDateTime().toString("dd/MM/yyyy hh:mm"));
    y += 30;

    // En-têtes de colonnes
    painter.setFont(headerFont);
    painter.setPen(Qt::NoPen);
    painter.setBrush(headerColor);

    x = margin;
    for (int col = 0; col < colCount; ++col) {
        QRect headerRect(x, y, colWidths[col], headerHeight);
        painter.drawRect(headerRect);

        painter.setPen(headerTextColor);
        QString header = ui->partnersTable->horizontalHeaderItem(col)->text();
        painter.drawText(headerRect, Qt::AlignCenter | Qt::TextWordWrap, header);
        painter.setPen(Qt::NoPen);

        x += colWidths[col];
    }
    y += headerHeight;

    // Données des lignes
    painter.setFont(cellFont);
    for (int row = 0; row < rowCount; ++row) {
        x = margin;

        for (int col = 0; col < colCount; ++col) {
            QRect cellRect(x, y, colWidths[col], rowHeight);

            // Fond de la cellule (alternance de couleurs)
            painter.setPen(Qt::NoPen);
            painter.setBrush((row % 2) ? QColor(240, 240, 240) : Qt::white);
            painter.drawRect(cellRect);

            // Bordure de la cellule
            painter.setPen(borderColor);
            painter.drawRect(cellRect);

            // Texte de la cellule
            painter.setPen(textColor);
            QTableWidgetItem *item = ui->partnersTable->item(row, col);
            if (item) {
                QRect textRect = cellRect.adjusted(5, 0, -5, 0);
                painter.drawText(textRect, Qt::AlignLeft | Qt::AlignVCenter | Qt::TextWordWrap, item->text());
            }

            x += colWidths[col];
        }
        y += rowHeight;

        // Pagination
        if (y > writer.height() - margin && row < rowCount - 1) {
            // Pied de page
            painter.setFont(cellFont);
            painter.setPen(Qt::gray);
            painter.drawText(QRect(0, writer.height() - 20, writer.width(), 15),
                             Qt::AlignRight, QString("Page %1").arg(currentPage));

            writer.newPage();
            currentPage++;
            y = margin;

            // Répéter les en-têtes
            painter.setFont(headerFont);
            painter.setPen(Qt::NoPen);
            painter.setBrush(headerColor);

            x = margin;
            for (int col = 0; col < colCount; ++col) {
                QRect headerRect(x, y, colWidths[col], headerHeight);
                painter.drawRect(headerRect);

                painter.setPen(headerTextColor);
                QString header = ui->partnersTable->horizontalHeaderItem(col)->text();
                painter.drawText(headerRect, Qt::AlignCenter | Qt::TextWordWrap, header);
                painter.setPen(Qt::NoPen);

                x += colWidths[col];
            }
            y += headerHeight;
        }
    }

    // Pied de page final
    painter.setFont(cellFont);
    painter.setPen(Qt::gray);
    painter.drawText(QRect(0, writer.height() - 20, writer.width(), 15),
                     Qt::AlignRight, QString("Page %1").arg(currentPage));

    painter.end();
    QMessageBox::information(this, "Exportation PDF", "Le fichier PDF a été créé avec succès !");
}


void PartnerPage::on_start_clicked()
{
    QSqlQuery query;

    // Préparer la requête SQL pour récupérer le partenaire ayant le plus de contrats
    query.prepare("SELECT PARTNERID, COUNT(*) AS ContractCount "
                  "FROM SPONSORSHIPS "
                  "GROUP BY PARTNERID "
                  "ORDER BY ContractCount DESC");

    // Vérifier si la requête s'exécute correctement
    if (!query.exec()) {
        qDebug() << "Erreur SQL:" << query.lastError().text();
        return;
    }

    // Créer un graphique en barres
    QBarSeries *series = new QBarSeries();
    QBarSet *contractCounts = new QBarSet("Nombre de contrats");

    QStringList partnerLabels;

    // Récupérer les résultats de la requête et les ajouter aux données du graphique
    while (query.next()) {
        int partnerId = query.value("PARTNERID").toInt();
        int contractCount = query.value("ContractCount").toInt();

        // Récupérer le nom du partenaire
        QSqlQuery partnerQuery;
        partnerQuery.prepare("SELECT NAME FROM PARTNERS WHERE PARTNERID = ?");
        partnerQuery.addBindValue(partnerId);

        QString partnerName = QString("Partenaire %1").arg(partnerId);  // Valeur par défaut

        if (partnerQuery.exec() && partnerQuery.next()) {
            partnerName = partnerQuery.value(0).toString();
        }

        // Ajouter les données au graphique
        *contractCounts << contractCount;
        partnerLabels << partnerName;

        qDebug() << "Partenaire:" << partnerName << " Nombre de contrats:" << contractCount;
    }

    // Ajouter les données au graphique
    series->append(contractCounts);

    // Créer le graphique
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Nombre de contrats par partenaire");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    // Ajouter les axes
    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(partnerLabels);
    axisX->setTitleText("Partenaires");

    QValueAxis *axisY = new QValueAxis();
    axisY->setTitleText("Nombre de contrats");
    axisY->setLabelFormat("%d");
    axisY->setTickInterval(1);

    // Attacher les axes au graphique
    chart->addAxis(axisX, Qt::AlignBottom);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisX);
    series->attachAxis(axisY);

    // Afficher la légende
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    // Créer un QChartView pour afficher le graphique
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setMinimumSize(800, 600);
    chartView->show();
}






int PartnerPage::getPartnerIdByName(const QString& partnerName) const
{
    QSqlQuery query;
    query.prepare("SELECT PARTNERID FROM PARTNERS WHERE NAME = :partnerName");
    query.bindValue(":partnerName", partnerName);

    if (query.exec() && query.next()) {
        return query.value(0).toInt();  // Retourner l'ID du partenaire
    }
    return -1;  // Si le partenaire n'est pas trouvé
}

int PartnerPage::getTeamIdByName(const QString& teamName) const
{
    QSqlQuery query;
    query.prepare("SELECT TEAMID FROM TEAMS WHERE NAME = :teamName");
    query.bindValue(":teamName", teamName);

    if (query.exec() && query.next()) {
        return query.value(0).toInt();  // Retourner l'ID de l'équipe
    }
    return -1;  // Si l'équipe n'est pas trouvée
}

void PartnerPage::on_deletepartner_clicked()
{
    bool ok;
    QString partnerName = QInputDialog::getText(this, "Supprimer Sponsorship", "Nom du partenaire :", QLineEdit::Normal, "", &ok);
    if (!ok || partnerName.isEmpty()) return;

    QString teamName = QInputDialog::getText(this, "Supprimer Sponsorship", "Nom de l'équipe :", QLineEdit::Normal, "", &ok);
    if (!ok || teamName.isEmpty()) return;

    // Conversion des noms en IDs
    int partnerId = getPartnerIdByName(partnerName);
    if (partnerId == -1) {
        QMessageBox::warning(this, "Erreur", "Partenaire introuvable.");
        return;
    }

    int teamId = getTeamIdByName(teamName);
    if (teamId == -1) {
        QMessageBox::warning(this, "Erreur", "Équipe introuvable.");
        return;
    }

    // Créer une instance de Partner et appeler deleteSponsorship
    Partner partner;  // Créer une instance locale de Partner
    if (partner.deleteSponsorship(partnerId, teamId)) {
        QMessageBox::information(this, "Succès", "Sponsorship supprimé.");
        on_refrechebutton_clicked();
            // Mettre à jour l'affichage des sponsors si nécessaire
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la suppression.");
    }
}




void PartnerPage::on_updatepartner_clicked()
{
    bool ok;
    QString partnerName = QInputDialog::getText(this, "Modifier Partenaire", "Nom du partenaire :", QLineEdit::Normal, "", &ok);
    if (!ok || partnerName.isEmpty()) return;

    int partnerId = getPartnerIdByName(partnerName);
    if (partnerId == -1) {
        QMessageBox::warning(this, "Erreur", "Partenaire introuvable.");
        return;
    }

    // Récupérer les informations existantes du partenaire
    Partner currentPartner = getPartnerById(partnerId);  // Assurez-vous d'avoir une fonction qui récupère le partenaire par ID
    if (currentPartner.getNom().isEmpty()) {  // Remplacez getName() par getNom()
        QMessageBox::warning(this, "Erreur", "Les informations du partenaire ne sont pas disponibles.");
        return;
    }

    // Créer un dialogue pour modifier les informations du partenaire
    QDialog dialog(this);
    dialog.setWindowTitle("Modifier les informations du partenaire");

    QFormLayout* formLayout = new QFormLayout(&dialog);
    QLineEdit* nameEdit = new QLineEdit(currentPartner.getNom());  // Remplacez getName() par getNom()
    QLineEdit* teamIdEdit = new QLineEdit(currentPartner.getTeamName());  // Assurez-vous que getTeamName() existe
    QLineEdit* stadiumIdEdit = new QLineEdit(currentPartner.getStadiumName());  // Assurez-vous que getStadiumName() existe
    QDateEdit* startDateEdit = new QDateEdit(currentPartner.getStartDate());
    QDateEdit* endDateEdit = new QDateEdit(currentPartner.getEndDate());

    // Ajouter les champs au formulaire
    formLayout->addRow("Nom :", nameEdit);
    formLayout->addRow("Nom de l'équipe :", teamIdEdit);
    formLayout->addRow("Nom du stade :", stadiumIdEdit);
    formLayout->addRow("Date de début :", startDateEdit);
    formLayout->addRow("Date de fin :", endDateEdit);

    // Ajouter les boutons OK/Annuler
    QDialogButtonBox* buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);
    formLayout->addWidget(buttonBox);
    QObject::connect(buttonBox, &QDialogButtonBox::accepted, &dialog, &QDialog::accept);
    QObject::connect(buttonBox, &QDialogButtonBox::rejected, &dialog, &QDialog::reject);

    // Afficher le dialogue et récupérer les données si accepté
    if (dialog.exec() == QDialog::Accepted) {
        QString newName = nameEdit->text();
        QString newTeamName = teamIdEdit->text();
        QString newStadiumName = stadiumIdEdit->text();
        QDate newStartDate = startDateEdit->date();
        QDate newEndDate = endDateEdit->date();

        // Appeler la méthode updatePartnerInfo avec les nouvelles valeurs
        Partner partner;
        if (partner.updatePartnerInfo(partnerId, newName, newTeamName, newStadiumName, newStartDate, newEndDate)) {
            QMessageBox::information(this, "Succès", "Les informations du partenaire ont été mises à jour.");
        } else {
            QMessageBox::critical(this, "Erreur", "Échec de la mise à jour des informations.");
        }
    }
}
Partner PartnerPage::getPartnerById(int partnerId)
{
    // Utilisation de la base de données pour récupérer les informations du partenaire
    QSqlDatabase db = QSqlDatabase::database();
    QSqlQuery query(db);

    // Préparer la requête pour récupérer un partenaire par son ID
    query.prepare("SELECT * FROM PARTNERS WHERE PARTNERID = :partnerId");
    query.bindValue(":partnerId", partnerId);

    if (query.exec() && query.next()) {
        Partner partner;
        partner.setID(query.value("PARTNERID").toInt());
        partner.setNom(query.value("NAME").toString());  // Utilisez setNom ici
        partner.setTeamName(query.value("TEAMNAME").toString());  // Assurez-vous que TEAMNAME existe dans votre table
        partner.setStadiumName(query.value("STADIUMNAME").toString());  // Assurez-vous que STADIUMNAME existe
        partner.setStartDate(query.value("SPONSORSHIPSTARTDATE").toDate());
        partner.setEndDate(query.value("SPONSORSHIPENDDATE").toDate());
        return partner;
    }

    return Partner();  // Retourner un objet Partner vide si l'ID n'a pas été trouvé
}



QString PartnerPage::getTeamNameById(int teamId)
{
    QSqlQuery query;
    query.prepare("SELECT NAME FROM TEAMS WHERE TEAMID = :teamId");
    query.bindValue(":teamId", teamId);
    if (query.exec() && query.next()) {
        return query.value(0).toString();
    }
    qDebug() << "Erreur SQL :" << query.lastError().text();
    return "Unknown Team";
}
QList<int> PartnerPage::getAllTeamIds()
{
    QList<int> teamIds;
    QSqlQuery query("SELECT TEAMID FROM TEAMS");
    while (query.next()) {
        teamIds.append(query.value(0).toInt());
    }
    return teamIds;
}


//**************************************************************************************************************************************************
void PartnerPage::on_recommend_2_clicked()
{
    recommendAndDisplayBestTeam();
}
void PartnerPage::recommendAndDisplayBestTeam()
{
    qDebug() << "🔍 Début de la recommandation d'équipe";

    QSqlQuery teamsQuery;

    if (!teamsQuery.prepare("SELECT TEAMID, NAME FROM TEAMS")) {
        QString errorMessage = teamsQuery.lastError().text();
        qDebug() << "❌ Erreur de préparation requête TEAMS :" << errorMessage;
        QMessageBox::warning(this, "Erreur", "Échec de la préparation de la requête des équipes: " + errorMessage);
        return;
    }

    if (!teamsQuery.exec()) {
        QString errorMessage = teamsQuery.lastError().text();
        qDebug() << "❌ Erreur d'exécution requête TEAMS :" << errorMessage;
        QMessageBox::warning(this, "Erreur", "Échec de l'exécution de la requête des équipes: " + errorMessage);
        return;
    }

    QString recommendationText;
    int bestScore = -1;
    QString bestTeamName;

    if (!teamsQuery.next()) {
        qDebug() << "ℹ️ Aucune équipe trouvée dans la base de données";
        QMessageBox::information(this, "Aucune équipe", "Aucune équipe trouvée dans la base de données.");
        return;
    }

    do {
        int teamId = teamsQuery.value("TEAMID").toInt();
        QString teamName = teamsQuery.value("NAME").toString();

        qDebug() << "📌 Équipe trouvée :" << teamName << "| ID =" << teamId;

        auto stats = getTeamWinStats(teamId); // Retourne {totalWins, consecutiveWins}
        int totalWins = stats.first;
        int consecutiveWins = stats.second;

        int score = totalWins + 2 * consecutiveWins;

        // ✅ Debug des statistiques
        qDebug() << "   ➤ totalWins =" << totalWins
                 << "| consecutiveWins =" << consecutiveWins
                 << "| score final =" << score;

        recommendationText += QString("🟢 %1 : %2 victoires | %3 victoires consécutives\n")
                                  .arg(teamName)
                                  .arg(totalWins)
                                  .arg(consecutiveWins);

        if (score > bestScore) {
            bestScore = score;
            bestTeamName = teamName;
        }

    } while (teamsQuery.next());

    if (!bestTeamName.isEmpty()) {
        recommendationText = "✅ Équipe recommandée : " + bestTeamName + "\n\n" + recommendationText;

        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Recommandation des équipes",
                                      recommendationText + "\n\nVoulez-vous choisir cette équipe ?",
                                      QMessageBox::Yes | QMessageBox::No);

        if (reply == QMessageBox::Yes) {
            for (int i = 0; i < ui->teamList->count(); ++i) {
                if (ui->teamList->itemText(i) == bestTeamName) {
                    ui->teamList->setCurrentIndex(i);
                    qDebug() << "✅ Équipe sélectionnée dans QComboBox :" << bestTeamName;
                    break;
                }
            }
        }
    } else {
        QMessageBox::information(this, "Aucune donnée", "Aucune équipe avec des statistiques disponibles.");
        qDebug() << "⚠️ Aucune équipe recommandable trouvée.";
    }

    qDebug() << "🔚 Fin de la recommandation";
}


QPair<int, int> PartnerPage::getTeamWinStats(int teamId)
{
    int totalWins = 0;
    int consecutiveWins = 0;
    bool streakEnded = false;

    QSqlQuery query;
    query.prepare("SELECT TEAMID, TEAM2ID, SCORE FROM MATCHES WHERE TEAMID = :id OR TEAM2ID = :id ORDER BY MATCHDATE DESC");
    query.bindValue(":id", teamId);

    if (query.exec()) {
        while (query.next()) {
            int team1 = query.value(0).toInt();
            int team2 = query.value(1).toInt();
            QString score = query.value(2).toString();

            QStringList parts = score.split("-");
            if (parts.size() != 2)
                continue;

            int score1 = parts[0].toInt();
            int score2 = parts[1].toInt();

            bool isWin = (team1 == teamId && score1 > score2) ||
                         (team2 == teamId && score2 > score1);

            if (isWin) {
                totalWins++;
                if (!streakEnded)
                    consecutiveWins++;
            } else {
                streakEnded = true; // on continue à compter totalWins, mais plus la série
            }
        }
    }

    return qMakePair(totalWins, consecutiveWins);
}

void PartnerPage::on_homeButton_clicked()
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


void PartnerPage::on_exitButton_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Exit Confirmation",
                                  "Are you sure you want to logout and exit?",
                                  QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        QApplication::quit();
    }
}

