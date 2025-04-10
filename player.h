#ifndef PLAYER_H
#define PLAYER_H

#include "qtablewidget.h"
#include <QString>

class Player {
private:
    int playerId;
    QString firstName;
    QString lastName;
    QString phoneNumber;
    QString position;
    QString status;
    int teamId;

    // New fields for IMG and NUM columns
    QString img;
    int number;

public:
    // Constructors
    Player();
    Player(int playerId, const QString &firstName, const QString &lastName,
           const QString &phoneNumber, const QString &position,
           const QString &status, int teamId,
           const QString &img = "", int number = 0);  // Include img and number

    // Getter and Setter methods
    int getPlayerId() const;
    void setPlayerId(int playerId);

    QString getFirstName() const;
    void setFirstName(const QString &firstName);

    QString getLastName() const;
    void setLastName(const QString &lastName);

    QString getPhoneNumber() const;
    void setPhoneNumber(const QString &phoneNumber);

    QString getPosition() const;
    void setPosition(const QString &position);

    QString getStatus() const;
    void setStatus(const QString &status);

    int getTeamId() const;
    void setTeamId(int teamId);

    // New getters and setters
    QString getImage() const;
    void setImage(const QString &img);

    int getNumber() const;
    void setNumber(int number);

    // CRUD Methods
    bool addPlayer(int selectedTeamId);
    void listPlayers(QTableWidget* table);
    static int generatePlayerId();
    bool deletePlayerUsingTeamID(const QString &firstName, const QString &lastName);
    bool updatePlayerUsingTeamID(int playerID, const QString& firstName, const QString& lastName, const QString& position, const QString& status, const QString& phoneNum, int teamID,int playerNum);
    bool updatePlayerDetails(int playerId, const QString &firstName, const QString &lastName, const QString &position, const QString &status, const QString &phoneNum, int teamID,int playerNum);

    // Method to get the team ID
    static int getTeamIdByName(const QString& teamName);

    void sortPlayersByName(QTableWidget* table);
    void searchPlayers(const QString &searchTerm, QTableWidget *tableWidget);
    void updatePlayerPerformance(const QString& firstName, const QString& lastName, bool isInterfaceClosed);
    void displayPerformanceStats();
    void exportPlayerListToPDF(const QString& filePath);
    void displayPlayerPerformance(const QString& firstName, const QString& lastName, QWidget* uiPage);
    void checkSuspensionStatus(const QString& firstName, const QString& lastName);

private slots:
    void on_delete_player_clicked(int row);  // Declaration of the function
    void resetPlayerId();
};

#endif // PLAYER_H
