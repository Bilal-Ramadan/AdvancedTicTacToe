#include "DatabaseManager.h"
#include <QCryptographicHash>
#include <QDebug>

DatabaseManager::DatabaseManager() {
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("saed.sqlite");
}

DatabaseManager& DatabaseManager::instance() {
    static DatabaseManager instance;
    return instance;
}

bool DatabaseManager::connectToDatabase() {
    if (!db.open()) {
        qWarning() << "Error opening database connection:" << db.lastError().text();
        return false;
    }

    QSqlQuery query;
    if (!query.exec("CREATE TABLE IF NOT EXISTS users (id INTEGER PRIMARY KEY AUTOINCREMENT, username TEXT,wins INTEGER DEFAULT 0, draws INTEGER DEFAULT 0, losses INTEGER DEFAULT 0,password TEXT,game_counter INTEGER DEFAULT 0)")) {
        qWarning() << "Error creating users table:" << query.lastError().text();
        return false;
    }

    if (!query.exec("CREATE TABLE IF NOT EXISTS games (id INTEGER PRIMARY KEY AUTOINCREMENT, user_id INTEGER, moves INTEGER , Game_number INTEGER, FOREIGN KEY(user_id) REFERENCES users(id))")) {
        qWarning() << "Error creating games table:" << query.lastError().text();
        return false;
    }

    return true;
}

int DatabaseManager::getUserId(const QString& username, const QString& password) {
    QSqlQuery query;
    query.prepare("SELECT id, password FROM users WHERE username = :username");
    query.bindValue(":username", username);
    if (query.exec() && query.next()) {
        QString storedPassword = query.value("password").toString();
        QString hashedPassword = QString(QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256).toHex());
        if (storedPassword == hashedPassword) {
            return query.value("id").toInt();
        }
    }
    return -1;
}

bool DatabaseManager::userExists(const QString& username, const QString& password) {
    QSqlQuery query;
    query.prepare("SELECT password FROM users WHERE username = :username");
    query.bindValue(":username", username);
    if (query.exec() && query.next()) {
        if (password.isEmpty()) {
            return true;
        } else {
            QString storedPassword = query.value(0).toString();
            QString hashedPassword = QString(QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256).toHex());
            return storedPassword == hashedPassword;
        }
    }
    return false;
}

bool DatabaseManager::addUser(const QString& username, const QString& password) {
    QString hashedPassword = QString(QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256).toHex());
    QSqlQuery query;
    query.prepare("INSERT INTO users (username, password) VALUES (:username, :password)");
    query.bindValue(":username", username);
    query.bindValue(":password", hashedPassword);

    if (query.exec()) {
        return true;
    } else {
        qWarning() << "Error inserting data:" << query.lastError().text();
        return false;
    }
}

bool DatabaseManager::addGame(int userId, const QString& moves ,int Game_number) {
    QSqlQuery query;
    query.prepare("INSERT INTO games (user_id, moves,Game_number ) VALUES (:user_id, :moves,:Game_number)");
    query.bindValue(":user_id", userId);
    query.bindValue(":moves", moves);
    query.bindValue(":Game_number", Game_number);

    if (query.exec()) {
        return true;
    } else {
        qWarning() << "Error inserting game data:" << query.lastError().text();
        return false;
    }
}

bool DatabaseManager::updateTotalGames(int userId, int totalGames) {
    QSqlQuery query;
    query.prepare("UPDATE users SET total_games = :total_games WHERE id = :id");
    query.bindValue(":total_games", totalGames);
    query.bindValue(":id", userId);

    if (query.exec()) {
        return true;
    } else {
        qWarning() << "Error updating total games:" << query.lastError().text();
        return false;
    }
}

int DatabaseManager::getGameCounter(int userId) {
    QSqlQuery query;
    query.prepare("SELECT game_counter FROM users WHERE id = :id");
    query.bindValue(":id", userId);
    if (query.exec() && query.next()) {
        return query.value("game_counter").toInt();
    }
    return -1;
}

bool DatabaseManager::incrementGameCounter(int userId) {
    QSqlQuery query;
    query.prepare("UPDATE users SET game_counter = game_counter + 1 WHERE id = :id");
    query.bindValue(":id", userId);
    return query.exec();
}

QString DatabaseManager::getUsername(int userId) {
    QSqlQuery query;
    query.prepare("SELECT username FROM users WHERE id = :id");
    query.bindValue(":id", userId);
    if (query.exec() && query.next()) {
        return query.value("username").toString();
    }
    return QString();
}

QString DatabaseManager::getGameMoves(int userId, int gameNumber) {
    QSqlQuery query;
    query.prepare("SELECT moves FROM games WHERE user_id = :user_id AND Game_number = :Game_number");
    query.bindValue(":user_id", userId);
    query.bindValue(":Game_number", gameNumber);
    if (query.exec() && query.next()) {
        return query.value("moves").toString();
    }
    return QString();
}



bool DatabaseManager::updateWins(int userId) {
    QSqlQuery query;
    query.prepare("UPDATE users SET wins = wins + 1 WHERE id = :id");
    query.bindValue(":id", userId);
    return query.exec();
}


bool DatabaseManager::updateDraws(int userId) {
    QSqlQuery query;
    query.prepare("UPDATE users SET draws = draws + 1 WHERE id = :id");
    query.bindValue(":id", userId);
    return query.exec();
}

bool DatabaseManager::updateLosses(int userId) {
    QSqlQuery query;
    query.prepare("UPDATE users SET losses = losses + 1 WHERE id = :id");
    query.bindValue(":id", userId);
    return query.exec();
}

int DatabaseManager::getwins(int userId) {
    QSqlQuery query;
    query.prepare("SELECT wins FROM users WHERE id = :id");
    query.bindValue(":id", userId);
    if (query.exec() && query.next()) {
        return query.value("wins").toInt();
    }
    return -1;
}
int DatabaseManager::getdraws(int userId) {
    QSqlQuery query;
    query.prepare("SELECT draws FROM users WHERE id = :id");
    query.bindValue(":id", userId);
    if (query.exec() && query.next()) {
        return query.value("draws").toInt();
    }
    return -1;
}
int DatabaseManager::getlosses(int userId) {
    QSqlQuery query;
    query.prepare("SELECT losses FROM users WHERE id = :id");
    query.bindValue(":id", userId);
    if (query.exec() && query.next()) {
        return query.value("losses").toInt();
    }
    return -1;
}











QMap<QString, int> DatabaseManager::getUserStatistics(int userId) {
    QSqlQuery query;
    query.prepare("SELECT wins, draws, losses FROM users WHERE id = :id");
    query.bindValue(":id", userId);

    QMap<QString, int> stats;
    if (query.exec() && query.next()) {
        stats["wins"] = query.value("wins").toInt();
        stats["draws"] = query.value("draws").toInt();
        stats["losses"] = query.value("losses").toInt();
    }
    return stats;
}
