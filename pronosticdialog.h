
#ifndef PRONOSTICDIALOG_H
#define PRONOSTICDIALOG_H

#include <QDialog>
#include <QLabel>
#include <QHBoxLayout>
#include <QPushButton>
#include <QFrame>

class PronosticDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PronosticDialog(QWidget *parent = nullptr);
    void setPronosticData(const QDateTime &date,
                          const QString& stadium, // Nouveau paramètre

                          const QString& team1,
                          const QString& team2,
                          const QString& form1,
                          const QString& form2,
                          float cote1,
                          float coteX,
                          float cote2);

private:
    void createLayout();
    void updateForm(const QString& form, QHBoxLayout* layout);

    // Widgets
    QLabel *stadiumLabel; // Ajouter cette déclaration
    QLabel *cotesTitleLabel;
    QLabel *dateLabel;
    QLabel *team1Name;
    QLabel *team2Name;
    QLabel *cote1Label;
    QLabel *coteXLabel;
    QLabel *cote2Label;
    QLabel *cote1Arrow;
    QLabel *coteXArrow;
    QLabel *cote2Arrow;
    QFrame *form1Frame;
    QFrame *form2Frame;
    QHBoxLayout *form1Layout;
    QHBoxLayout *form2Layout;
};

#endif // PRONOSTICDIALOG_H

