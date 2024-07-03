#ifndef SIGNINSCREEN_H
#define SIGNINSCREEN_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>
#include "DatabaseManager.h"

class SignInScreen : public QWidget {
    Q_OBJECT
signals:
    void loginSuccessful();
    void   goToGamePage();
public:
    explicit SignInScreen(QWidget *parent = nullptr);

private slots:
    void login();
    void openSignUpScreen();

private:
    QLineEdit* usernameLineEdit;
    QLineEdit* passwordLineEdit;
    QPushButton* loginButton;
    QPushButton* signUpButton;

    void showMessage(const QString& message);
    void openEmptyScreen();
};

#endif // SIGNINSCREEN_H
