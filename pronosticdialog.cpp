#include "PronosticDialog.h"
#include <QDateTime>
#include <QFontDatabase>
#include <QFont>
#include <QScrollArea>
#include <QScrollBar>
#include <QPushButton>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QStringList>



PronosticDialog::PronosticDialog(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle("Football Expert");
    setFixedSize(1000, 800);
    setStyleSheet(
        "QDialog {"
        "   background: qlineargradient(x1:0, y1:0, x2:1, y2:1,"
        "               stop:0 #1a2f38, stop:1 #0d1a1f);" // Dégradé de verts profonds
        "   font-family: 'Arial Rounded MT Bold';"
        "}");
    createLayout();
}

void PronosticDialog::createLayout()
{
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->setContentsMargins(30, 20, 30, 30);
    mainLayout->setSpacing(15);


    // Carte principale
    QWidget *card = new QWidget();
    card->setStyleSheet(
        "QWidget {"
        "   background: rgba(255, 255, 255, 0.95);"
        "   border-radius: 15px;"
        "   padding: 20px;"
        "}");
    QVBoxLayout *cardLayout = new QVBoxLayout(card);;

    // Date
    dateLabel = new QLabel();
    dateLabel->setStyleSheet(
        "QLabel {"
        "color: #FFFFFF;"
        "font-size: 12px;"
        "font-weight: bold;"
        "margin-top: 10px;"
        "}"
        );
    dateLabel->setAlignment(Qt::AlignCenter);
    mainLayout->addWidget(dateLabel);

    // Dans createLayout(), ajouter après dateLabel :
    stadiumLabel = new QLabel();
    stadiumLabel->setStyleSheet(        "QLabel {"
                                "color: #FFFFFF;"
                                "font-size: 12px;"
                                "font-weight: bold;"
                                "margin-top: 5px;"
                                "}");
    mainLayout->addWidget(stadiumLabel, 0, Qt::AlignCenter);

    // Remplacer la section "Équipes" par ceci :

    // Équipes
    QWidget *teamsWidget = new QWidget();
    QHBoxLayout *teamsLayout = new QHBoxLayout(teamsWidget);
    teamsLayout->setContentsMargins(0, 0, 0, 0);
    teamsLayout->setSpacing(15);

    // Équipe 1
    QWidget *team1Container = new QWidget();
    QVBoxLayout *team1Vertical = new QVBoxLayout(team1Container);
    team1Vertical->setAlignment(Qt::AlignCenter);


    team1Name = new QLabel();
    team1Name->setStyleSheet(
        "QLabel {"
        "color: #FFFFFF;"
        "font-size: 20px;"
        "font-weight: bold;"
        "margin-top: 10px;"
        "}"
        );
    team1Vertical->addWidget(team1Name, 0, Qt::AlignCenter);

    // VS
    QLabel *vsLabel = new QLabel("VS");
    vsLabel->setStyleSheet(
        "QLabel {"
        "color: #FFFFFF;"
        "font-size: 20px;"
        "font-weight: bold;"
        "margin: 0 20px;"
        "}"
        );

    // Équipe 2
    QWidget *team2Container = new QWidget();
    QVBoxLayout *team2Vertical = new QVBoxLayout(team2Container);
    team2Vertical->setAlignment(Qt::AlignCenter);

    team2Name = new QLabel();
    team2Name->setStyleSheet(
        "QLabel {"
        "color: #FFFFFF;"
        "font-size: 20px;"
        "font-weight: bold;"
        "margin-top: 10px;"
        "}"
        );
    team2Vertical->addWidget(team2Name, 0, Qt::AlignCenter);

    // Organisation globale
    teamsLayout->addStretch();
    teamsLayout->addWidget(team1Container);
    teamsLayout->addWidget(vsLabel);
    teamsLayout->addWidget(team2Container);
    teamsLayout->addStretch();

    mainLayout->addWidget(teamsWidget);

    // Titre Cotes
    QLabel *cotesTitle = new QLabel("COTES");
    cotesTitle->setStyleSheet("font-size: 20px; color: #FFFFFF; font-weight: bold; margin-top: 20px;");
    mainLayout->addWidget(cotesTitle, 0, Qt::AlignCenter);


    // Cotes avec flèches
    QWidget *oddsWidget = new QWidget();
    // Inutile, car tu le fais juste après :
    QHBoxLayout *oddsLayout = new QHBoxLayout(oddsWidget);
    oddsLayout->setSpacing(30);

    // Cote 1 avec label "1"
    QWidget *cote1Widget = new QWidget();
    QVBoxLayout *cote1Layout = new QVBoxLayout(cote1Widget);
    QLabel *label1 = new QLabel("1");
    label1->setStyleSheet("font-size: 16px; color: #FFFFFF; font-weight: bold;");
    label1->setAlignment(Qt::AlignCenter);
    QLabel *arrow1 = new QLabel("↑");
    arrow1->setStyleSheet("color: #27AE60; font-weight: bold; font-size: 16px;");
    cote1Label = new QLabel();
    cote1Label->setStyleSheet("QLabel { background: #FFD700; color: black; padding: 15px 25px; border-radius: 8px; font-size: 20px; }");
    cote1Layout->addWidget(label1);
    cote1Layout->addWidget(arrow1, 0, Qt::AlignCenter);
    cote1Layout->addWidget(cote1Label, 0, Qt::AlignCenter);

    // Cote X avec label "X"
    QWidget *coteXWidget = new QWidget();
    QVBoxLayout *coteXLayout = new QVBoxLayout(coteXWidget);
    QLabel *labelX = new QLabel("X");
    labelX->setStyleSheet("font-size: 16px; color: #FFFFFF; font-weight: bold;");
    labelX->setAlignment(Qt::AlignCenter);
    QLabel *arrowX = new QLabel("→");
    arrowX->setStyleSheet("color: #666; font-weight: bold; font-size: 16px;");
    coteXLabel = new QLabel();
    coteXLabel->setStyleSheet("QLabel { background: #FFD700; color: black; padding: 15px 25px; border-radius: 8px; font-size: 20px; }");
    coteXLayout->addWidget(labelX);
    coteXLayout->addWidget(arrowX, 0, Qt::AlignCenter);
    coteXLayout->addWidget(coteXLabel, 0, Qt::AlignCenter);

    // Cote 2 avec label "2"
    QWidget *cote2Widget = new QWidget();
    QVBoxLayout *cote2Layout = new QVBoxLayout(cote2Widget);
    QLabel *label2 = new QLabel("2");
    label2->setStyleSheet("font-size: 16px; color: #FFFFFF; font-weight: bold;");
    label2->setAlignment(Qt::AlignCenter);
    QLabel *arrow2 = new QLabel("↓");
    arrow2->setStyleSheet("color: #E74C3C; font-weight: bold; font-size: 16px;");
    cote2Label = new QLabel();
    cote2Label->setStyleSheet("QLabel { background: #FFD700; color: black; padding: 15px 25px; border-radius: 8px; font-size: 20px; }");
    cote2Layout->addWidget(label2);
    cote2Layout->addWidget(arrow2, 0, Qt::AlignCenter);
    cote2Layout->addWidget(cote2Label, 0, Qt::AlignCenter);

    // Ajout au layout principal
    oddsLayout->addStretch();
    oddsLayout->addWidget(cote1Widget);
    oddsLayout->addWidget(coteXWidget);
    oddsLayout->addWidget(cote2Widget);
    oddsLayout->addStretch();

    mainLayout->addWidget(oddsWidget, 0, Qt::AlignCenter);

    // Titre Formes
    QLabel *formesTitle = new QLabel("FORME DES ÉQUIPES");
    formesTitle->setStyleSheet("font-size: 20px; color: #FFFFFF; font-weight: bold; margin-top: 20px;");
    mainLayout->addWidget(formesTitle, 0, Qt::AlignCenter);

    // Formes
    QWidget *formContainer = new QWidget();
    QHBoxLayout *formLayout = new QHBoxLayout(formContainer);
    formLayout->setSpacing(30);

    form1Frame = new QFrame();
    form1Frame->setStyleSheet("QFrame { background: #1a2f38; border-radius: 12px; padding: 10px; }");
    form1Layout = new QHBoxLayout(form1Frame);

    form2Frame = new QFrame();
    form2Frame->setStyleSheet("QFrame { background: #1a2f38; border-radius: 12px; padding: 10px; }");
    form2Layout = new QHBoxLayout(form2Frame);

    formLayout->addWidget(form1Frame);
    formLayout->addWidget(form2Frame);
    mainLayout->addWidget(formContainer);


    // Bouton Fermer
    QPushButton *btnClose = new QPushButton("Fermer");
    btnClose->setStyleSheet("QPushButton {"
                            "background: #3498DB;"
                            "color: white;"
                            "padding: 12px 30px;"
                            "border-radius: 6px;}"
                            "QPushButton:hover { background: #2980B9; }");
    connect(btnClose, &QPushButton::clicked, this, &QDialog::accept);
    mainLayout->addWidget(btnClose, 0, Qt::AlignCenter);
}

void PronosticDialog::setPronosticData(const QDateTime &date,
                                       const QString& stadium,

                                       const QString& team1,
                                       const QString& team2,
                                       const QString& form1,
                                       const QString& form2,
                                       float cote1,
                                       float coteX,
                                       float cote2)
{
    // Date
    dateLabel->setText(date.toString("dddd dd MMMM yyyy").toUpper());
    stadiumLabel->setText(stadium.toUpper());


    // Équipes
    team1Name->setText(team1);
    team2Name->setText(team2);

    // Cotes
    cote1Label->setText(QString::number(cote1, 'f', 2));
    coteXLabel->setText(QString::number(coteX, 'f', 2));
    cote2Label->setText(QString::number(cote2, 'f', 2));

    // Formes
    updateForm(form1, form1Layout);
    updateForm(form2, form2Layout);
}

void PronosticDialog::updateForm(const QString& form, QHBoxLayout* layout)
{
    // Nettoyer l'ancien contenu
    QLayoutItem* item;
    while ((item = layout->takeAt(0)) != nullptr) {
        delete item->widget();
        delete item;
    }

    // Splitter la chaîne de forme en utilisant les espaces
    QStringList formResults = form.split(' ', Qt::SkipEmptyParts);

    // Ajouter les indicateurs
    for (const QString& result : formResults) {
        if(result.length() != 1) continue; // Ignorer les entrées invalides

        QLabel *label = new QLabel();
        label->setFixedSize(40, 40);
        label->setAlignment(Qt::AlignCenter);

        QFont font;
        font.setBold(true);
        font.setPointSize(14);

        QString style;
        QString text = result;

        if (result == "W") {
            style = "background-color: #27AE60; color: white;";
        } else if (result == "L") {
            style = "background-color: #E74C3C; color: white;";
        } else if (result == "D") {
            style = "background-color: white; color: black; border: 2px solid #95A5A6;";
        } else {
            continue; // Ignorer les caractères invalides
        }

        label->setStyleSheet(QString(
                                 "QLabel {"
                                 "border-radius: 5px;"
                                 "%1"
                                 "padding: 4px;"
                                 "}").arg(style));

        label->setFont(font);
        label->setText(text);
        layout->addWidget(label);
        layout->addSpacing(5);
    }
}
