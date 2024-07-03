/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *page1;
    QPushButton *pushButton_13;
    QPushButton *pushButton_11;
    QPushButton *pushButton_12;
    QPushButton *pushButton_10;
    QWidget *page2;
    QLabel *turnLabel;
    QPushButton *pushButton_5;
    QPushButton *pushButton_home;
    QPushButton *pushButton_restart;
    QPushButton *pushButton_1;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QWidget *page4;
    QLabel *label_losses;
    QLabel *label_wins;
    QLineEdit *lineEdit_draws;
    QLabel *gameDetailsLabel;
    QLineEdit *lineEdit_userid;
    QLineEdit *lineEdit_wins;
    QLineEdit *lineEdit_username;
    QLabel *label_draws;
    QLabel *label_username;
    QLineEdit *lineEdit_losses;
    QPushButton *pushButton_show;
    QLabel *label_user_id;
    QLabel *label_total_game;
    QLineEdit *lineEdit_enter_the_number;
    QLineEdit *lineEdit_totalgame;
    QWidget *page5;
    QPushButton *pushButton_17;
    QPushButton *pushButton_19;
    QPushButton *pushButton_replay;
    QPushButton *pushButton_20;
    QPushButton *pushButton_18;
    QPushButton *pushButton_16;
    QPushButton *pushButton_21;
    QPushButton *pushButton_14;
    QPushButton *pushButton_15;
    QPushButton *pushButton_previous;
    QLineEdit *lineEdit;
    QPushButton *pushButton_22;
    QLabel *label_5;
    QPushButton *pushButton_next;
    QMenuBar *menubar;
    QMenu *menuTicTacToe;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(845, 1060);
        MainWindow->setMinimumSize(QSize(0, 900));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(70, 10, 751, 991));
        stackedWidget->setStyleSheet(QString::fromUtf8(""));
        page1 = new QWidget();
        page1->setObjectName("page1");
        page1->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/WhatsApp Image 2024-06-26 at 8.08.09 AM.jpeg);"));
        pushButton_13 = new QPushButton(page1);
        pushButton_13->setObjectName("pushButton_13");
        pushButton_13->setGeometry(QRect(280, 520, 261, 81));
        pushButton_13->setStyleSheet(QString::fromUtf8("border-image: url(:/new/prefix1/images/Screenshot 2024-06-27 012516.png);"));
        pushButton_11 = new QPushButton(page1);
        pushButton_11->setObjectName("pushButton_11");
        pushButton_11->setGeometry(QRect(280, 710, 261, 81));
        pushButton_11->setStyleSheet(QString::fromUtf8("border-image: url(:/new/prefix1/images/WhatsApp Image 2024-06-26 at 8.08.11 AM.jpeg);"));
        pushButton_12 = new QPushButton(page1);
        pushButton_12->setObjectName("pushButton_12");
        pushButton_12->setGeometry(QRect(280, 800, 261, 81));
        pushButton_12->setStyleSheet(QString::fromUtf8("border-image: url(:/new/prefix1/images/WhatsApp Image 2024-06-26 at 4.04.36 PM.jpeg);"));
        pushButton_10 = new QPushButton(page1);
        pushButton_10->setObjectName("pushButton_10");
        pushButton_10->setGeometry(QRect(280, 620, 261, 71));
        pushButton_10->setStyleSheet(QString::fromUtf8("border-image: url(:/new/prefix1/images/WhatsApp Image 2024-06-26 at 8.08.10 AM.jpeg);"));
        stackedWidget->addWidget(page1);
        page2 = new QWidget();
        page2->setObjectName("page2");
        page2->setMaximumSize(QSize(16777215, 700));
        page2->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/images/WhatsApp Image 2024-06-26 at 8.21.18 AM.jpeg);\n"
""));
        turnLabel = new QLabel(page2);
        turnLabel->setObjectName("turnLabel");
        turnLabel->setGeometry(QRect(260, 40, 321, 51));
        turnLabel->setStyleSheet(QString::fromUtf8("font: 700 20pt \"Segoe UI\";\n"
" "));
        pushButton_5 = new QPushButton(page2);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(310, 290, 121, 121));
        pushButton_5->setStyleSheet(QString::fromUtf8("font: 700 20pt \"Segoe UI\";\n"
"    border: 6px rgb(63, 124, 171);\n"
""));
        pushButton_home = new QPushButton(page2);
        pushButton_home->setObjectName("pushButton_home");
        pushButton_home->setGeometry(QRect(90, 20, 91, 51));
        pushButton_home->setStyleSheet(QString::fromUtf8("border-image: url(:/new/prefix1/images/WhatsApp Image 2024-06-26 at 4.35.35 PM.jpeg);"));
        pushButton_restart = new QPushButton(page2);
        pushButton_restart->setObjectName("pushButton_restart");
        pushButton_restart->setGeometry(QRect(550, 20, 91, 51));
        pushButton_restart->setStyleSheet(QString::fromUtf8("border-image: url(:/new/prefix1/images/WhatsApp Image 2024-06-26 at 4.23.45 PM.jpeg);"));
        pushButton_1 = new QPushButton(page2);
        pushButton_1->setObjectName("pushButton_1");
        pushButton_1->setGeometry(QRect(150, 130, 121, 121));
        pushButton_1->setStyleSheet(QString::fromUtf8("font: 700 20pt \"Segoe UI\";\n"
"    border: 6px rgb(63, 124, 171);\n"
""));
        pushButton_2 = new QPushButton(page2);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(310, 130, 121, 121));
        pushButton_2->setStyleSheet(QString::fromUtf8("font: 700 20pt \"Segoe UI\";\n"
"    border: 6px rgb(63, 124, 171);\n"
""));
        pushButton_3 = new QPushButton(page2);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(470, 130, 121, 121));
        pushButton_3->setStyleSheet(QString::fromUtf8("font: 700 20pt \"Segoe UI\";\n"
"    border: 6px rgb(63, 124, 171);\n"
""));
        pushButton_4 = new QPushButton(page2);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(150, 290, 121, 121));
        pushButton_4->setStyleSheet(QString::fromUtf8("font: 700 20pt \"Segoe UI\";\n"
"    border: 6px rgb(63, 124, 171);\n"
""));
        pushButton_6 = new QPushButton(page2);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(470, 290, 121, 121));
        pushButton_6->setStyleSheet(QString::fromUtf8("font: 700 20pt \"Segoe UI\";\n"
"    border: 6px rgb(63, 124, 171);\n"
""));
        pushButton_7 = new QPushButton(page2);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setGeometry(QRect(150, 440, 121, 121));
        pushButton_7->setStyleSheet(QString::fromUtf8("font: 700 20pt \"Segoe UI\";\n"
"    border: 6px rgb(63, 124, 171);\n"
""));
        pushButton_8 = new QPushButton(page2);
        pushButton_8->setObjectName("pushButton_8");
        pushButton_8->setGeometry(QRect(310, 440, 121, 121));
        pushButton_8->setStyleSheet(QString::fromUtf8("font: 700 20pt \"Segoe UI\";\n"
"    border: 6px rgb(63, 124, 171);\n"
""));
        pushButton_9 = new QPushButton(page2);
        pushButton_9->setObjectName("pushButton_9");
        pushButton_9->setGeometry(QRect(470, 450, 121, 121));
        pushButton_9->setStyleSheet(QString::fromUtf8("font: 700 20pt \"Segoe UI\";\n"
"    border: 6px rgb(63, 124, 171);\n"
""));
        stackedWidget->addWidget(page2);
        page4 = new QWidget();
        page4->setObjectName("page4");
        label_losses = new QLabel(page4);
        label_losses->setObjectName("label_losses");
        label_losses->setGeometry(QRect(200, 340, 71, 21));
        label_wins = new QLabel(page4);
        label_wins->setObjectName("label_wins");
        label_wins->setGeometry(QRect(210, 280, 71, 21));
        lineEdit_draws = new QLineEdit(page4);
        lineEdit_draws->setObjectName("lineEdit_draws");
        lineEdit_draws->setGeometry(QRect(290, 310, 41, 20));
        gameDetailsLabel = new QLabel(page4);
        gameDetailsLabel->setObjectName("gameDetailsLabel");
        gameDetailsLabel->setGeometry(QRect(450, 330, 91, 16));
        lineEdit_userid = new QLineEdit(page4);
        lineEdit_userid->setObjectName("lineEdit_userid");
        lineEdit_userid->setGeometry(QRect(290, 210, 31, 20));
        lineEdit_wins = new QLineEdit(page4);
        lineEdit_wins->setObjectName("lineEdit_wins");
        lineEdit_wins->setGeometry(QRect(290, 280, 41, 20));
        lineEdit_username = new QLineEdit(page4);
        lineEdit_username->setObjectName("lineEdit_username");
        lineEdit_username->setGeometry(QRect(290, 170, 131, 21));
        label_draws = new QLabel(page4);
        label_draws->setObjectName("label_draws");
        label_draws->setGeometry(QRect(200, 310, 71, 21));
        label_username = new QLabel(page4);
        label_username->setObjectName("label_username");
        label_username->setGeometry(QRect(200, 170, 71, 21));
        lineEdit_losses = new QLineEdit(page4);
        lineEdit_losses->setObjectName("lineEdit_losses");
        lineEdit_losses->setGeometry(QRect(290, 340, 41, 20));
        pushButton_show = new QPushButton(page4);
        pushButton_show->setObjectName("pushButton_show");
        pushButton_show->setGeometry(QRect(230, 410, 80, 18));
        label_user_id = new QLabel(page4);
        label_user_id->setObjectName("label_user_id");
        label_user_id->setGeometry(QRect(200, 210, 71, 21));
        label_total_game = new QLabel(page4);
        label_total_game->setObjectName("label_total_game");
        label_total_game->setGeometry(QRect(190, 250, 91, 21));
        lineEdit_enter_the_number = new QLineEdit(page4);
        lineEdit_enter_the_number->setObjectName("lineEdit_enter_the_number");
        lineEdit_enter_the_number->setGeometry(QRect(230, 380, 161, 20));
        lineEdit_totalgame = new QLineEdit(page4);
        lineEdit_totalgame->setObjectName("lineEdit_totalgame");
        lineEdit_totalgame->setGeometry(QRect(290, 250, 41, 20));
        stackedWidget->addWidget(page4);
        page5 = new QWidget();
        page5->setObjectName("page5");
        pushButton_17 = new QPushButton(page5);
        pushButton_17->setObjectName("pushButton_17");
        pushButton_17->setGeometry(QRect(290, 270, 51, 41));
        pushButton_19 = new QPushButton(page5);
        pushButton_19->setObjectName("pushButton_19");
        pushButton_19->setGeometry(QRect(390, 270, 51, 41));
        pushButton_replay = new QPushButton(page5);
        pushButton_replay->setObjectName("pushButton_replay");
        pushButton_replay->setGeometry(QRect(340, 390, 51, 18));
        pushButton_20 = new QPushButton(page5);
        pushButton_20->setObjectName("pushButton_20");
        pushButton_20->setGeometry(QRect(290, 310, 51, 41));
        pushButton_18 = new QPushButton(page5);
        pushButton_18->setObjectName("pushButton_18");
        pushButton_18->setGeometry(QRect(340, 270, 51, 41));
        pushButton_16 = new QPushButton(page5);
        pushButton_16->setObjectName("pushButton_16");
        pushButton_16->setGeometry(QRect(390, 230, 51, 41));
        pushButton_21 = new QPushButton(page5);
        pushButton_21->setObjectName("pushButton_21");
        pushButton_21->setGeometry(QRect(340, 310, 51, 41));
        pushButton_14 = new QPushButton(page5);
        pushButton_14->setObjectName("pushButton_14");
        pushButton_14->setGeometry(QRect(290, 230, 51, 41));
        pushButton_15 = new QPushButton(page5);
        pushButton_15->setObjectName("pushButton_15");
        pushButton_15->setGeometry(QRect(340, 230, 51, 41));
        pushButton_previous = new QPushButton(page5);
        pushButton_previous->setObjectName("pushButton_previous");
        pushButton_previous->setGeometry(QRect(200, 260, 61, 31));
        lineEdit = new QLineEdit(page5);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(310, 360, 113, 20));
        pushButton_22 = new QPushButton(page5);
        pushButton_22->setObjectName("pushButton_22");
        pushButton_22->setGeometry(QRect(390, 310, 51, 41));
        label_5 = new QLabel(page5);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(140, 160, 471, 41));
        QFont font;
        font.setFamilies({QString::fromUtf8("Sakkal Majalla")});
        font.setPointSize(26);
        font.setBold(true);
        label_5->setFont(font);
        pushButton_next = new QPushButton(page5);
        pushButton_next->setObjectName("pushButton_next");
        pushButton_next->setGeometry(QRect(470, 260, 41, 31));
        stackedWidget->addWidget(page5);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 845, 25));
        menuTicTacToe = new QMenu(menubar);
        menuTicTacToe->setObjectName("menuTicTacToe");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuTicTacToe->menuAction());

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton_13->setText(QString());
        pushButton_11->setText(QString());
        pushButton_12->setText(QString());
        pushButton_10->setText(QString());
        turnLabel->setText(QString());
        pushButton_5->setText(QString());
        pushButton_home->setText(QString());
        pushButton_restart->setText(QString());
        pushButton_1->setText(QString());
        pushButton_2->setText(QString());
        pushButton_3->setText(QString());
        pushButton_4->setText(QString());
        pushButton_6->setText(QString());
        pushButton_7->setText(QString());
        pushButton_8->setText(QString());
        pushButton_9->setText(QString());
        label_losses->setText(QCoreApplication::translate("MainWindow", "Losses", nullptr));
        label_wins->setText(QCoreApplication::translate("MainWindow", "wins :", nullptr));
        gameDetailsLabel->setText(QCoreApplication::translate("MainWindow", "gameDetailsLabel", nullptr));
        label_draws->setText(QCoreApplication::translate("MainWindow", "Draws:", nullptr));
        label_username->setText(QCoreApplication::translate("MainWindow", "User name:", nullptr));
        pushButton_show->setText(QCoreApplication::translate("MainWindow", "Show", nullptr));
        label_user_id->setText(QCoreApplication::translate("MainWindow", "User id :", nullptr));
        label_total_game->setText(QCoreApplication::translate("MainWindow", "Total Game:", nullptr));
        pushButton_17->setText(QCoreApplication::translate("MainWindow", "o", nullptr));
        pushButton_19->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        pushButton_replay->setText(QCoreApplication::translate("MainWindow", "Reply", nullptr));
        pushButton_20->setText(QCoreApplication::translate("MainWindow", "o", nullptr));
        pushButton_18->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        pushButton_16->setText(QCoreApplication::translate("MainWindow", "o", nullptr));
        pushButton_21->setText(QCoreApplication::translate("MainWindow", "o", nullptr));
        pushButton_14->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        pushButton_15->setText(QCoreApplication::translate("MainWindow", "o", nullptr));
        pushButton_previous->setText(QCoreApplication::translate("MainWindow", "previous", nullptr));
        lineEdit->setText(QString());
        pushButton_22->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Watch & Reply Previous Matches", nullptr));
        pushButton_next->setText(QCoreApplication::translate("MainWindow", "next", nullptr));
        menuTicTacToe->setTitle(QCoreApplication::translate("MainWindow", "TicTacToe", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
