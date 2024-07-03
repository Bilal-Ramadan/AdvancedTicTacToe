#ifndef SIGNUPSCREEN_H
#define SIGNUPSCREEN_H

#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>
#include "DatabaseManager.h"

class SignUpScreen : public QDialog {
    Q_OBJECT

public:
    explicit SignUpScreen(QWidget *parent = nullptr);

private slots:
    void signUp();

private:
    QLineEdit* usernameLineEdit;
    QLineEdit* passwordLineEdit;
    QPushButton* signUpButton;

    void showMessage(const QString& message);
};

#endif // SIGNUPSCREEN_H
