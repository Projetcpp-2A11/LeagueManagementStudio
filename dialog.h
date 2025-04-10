#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QDate>
#include <QList>
#include <QString>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

    // Méthodes pour obtenir les valeurs des filtres
    QDate getStartDate() const;
    QDate getEndDate() const;
    QString getSelectedStadium() const;

    // Méthode pour obtenir l'état du match (Gagné, Perdu, Nul)
    QString getMatchResult() const;

    // Méthode pour réinitialiser les filtres
    void resetFilters();

    // Méthode pour charger les stades dans le ComboBox
    void loadStadiumsIntoComboBox();

private slots:
    void applyFilters();  // Appliquer les filtres

    void on_cancel_clicked();

private:
    Ui::Dialog *ui;

signals:
    void filtersApplied(const QList<QString>& filters);  // Signal pour appliquer les filtres
};

#endif // DIALOG_H
