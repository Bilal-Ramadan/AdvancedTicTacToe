#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QtSql>
#include <QString>

class DatabaseManager {
public:
    static DatabaseManager& instance();

    bool connectToDatabase();
    bool userExists(const QString& username, const QString& password = "");
    bool addUser(const QString& username, const QString& password);
    bool addGame(int userId, const QString& moves ,int Game_number);
    bool updateTotalGames(int userId, int totalGames);
    int getUserId(const QString& username, const QString& password);
    int getGameCounter(int userId);
    bool incrementGameCounter(int userId);
    QString getUsername(int userId);
    QString getGameMoves(int userId, int gameNumber);

    bool updateWins(int userId);
    bool updateDraws(int userId);
    bool updateLosses(int userId);

    int getwins(int userId);
    int getdraws(int userId);
    int getlosses(int userId);


    QMap<QString, int> getUserStatistics(int userId);


private:
    DatabaseManager();
    QSqlDatabase db;
};

#endif // DATABASEMANAGER_H
