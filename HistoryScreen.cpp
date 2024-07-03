#include "HistoryScreen.h"
#include "ui_mainwindow.h"
#include "mainwindow.h"
#include "HistoryScreen.h"
#include <QCryptographicHash>
#include <QDebug>
#include"DatabaseManager.h"
#include <QMessageBox>
#include <QDebug>
#include <QVBoxLayout>
#include <QThread>
#include <QPixmap>
#include "SignInScreen.h"
#include <QPropertyAnimation>
#include <QGraphicsOpacityEffect>
#include "GameOverDialog.h"
#include "GameOverDialog.h"
HistoryScreen::HistoryScreen(int userId, Ui::MainWindow *ui, QWidget *parent)
    : QWidget(parent), userId(userId), ui(ui) {

    QString username = DatabaseManager::instance().getUsername(userId);
    int gameCounter = DatabaseManager::instance().getGameCounter(userId);

    ui->lineEdit_username->setText(username);
    ui->lineEdit_userid->setText(QString::number(userId));
    ui->lineEdit_totalgame->setText(QString::number(gameCounter));

    QMap<QString, int> stats = DatabaseManager::instance().getUserStatistics(userId);
    ui->lineEdit_wins->setText(QString::number(stats["wins"]));
    ui->lineEdit_draws->setText(QString::number(stats["draws"]));
    ui->lineEdit_losses->setText(QString::number(stats["losses"]));
    ui->lineEdit_losses->setText(QString::number(stats["losses"]));


    connect(ui->pushButton_show, &QPushButton::clicked, this, &HistoryScreen::showGameDetails);

}

void HistoryScreen::showGameDetails() {

    int gameNumber = ui->lineEdit_enter_the_number->text().toInt();
    QSqlQuery query;
    query.prepare("SELECT moves FROM games WHERE user_id = :user_id AND game_number = :game_number");
    query.bindValue(":user_id", userId);
    query.bindValue(":game_number", gameNumber);

    if (query.exec() && query.next()) {
        emit movetoplayed();

    } else {
        ui->gameDetailsLabel->setText("No game found with the specified number.");
    }
}
