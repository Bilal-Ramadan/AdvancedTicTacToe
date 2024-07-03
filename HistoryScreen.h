#ifndef HISTORYSCREEN_H
#define HISTORYSCREEN_H

#include <QWidget>
#include <QMap>
#include <QSqlQuery>
#include "DatabaseManager.h"
#include "ui_mainwindow.h"

class HistoryScreen : public QWidget {
    Q_OBJECT

public:
    explicit HistoryScreen(int userId, Ui::MainWindow *ui, QWidget *parent = nullptr);

private slots:
    void showGameDetails();
signals:
    void movetoplayed();
private:
    int userId;
    Ui::MainWindow *ui;
};

#endif // HISTORYSCREEN_H
