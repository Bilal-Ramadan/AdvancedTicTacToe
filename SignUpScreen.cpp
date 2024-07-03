#include "SignUpScreen.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QDebug>

SignUpScreen::SignUpScreen(QWidget *parent) : QDialog(parent) {
    QVBoxLayout* mainLayout = new QVBoxLayout(this);

    QLabel* usernameLabel = new QLabel("Username:", this);
    usernameLineEdit = new QLineEdit(this);
    mainLayout->addWidget(usernameLabel);
    mainLayout->addWidget(usernameLineEdit);

    QLabel* passwordLabel = new QLabel("Password:", this);
    passwordLineEdit = new QLineEdit(this);
    passwordLineEdit->setEchoMode(QLineEdit::Password);
    mainLayout->addWidget(passwordLabel);
    mainLayout->addWidget(passwordLineEdit);

    signUpButton = new QPushButton("Sign Up", this);
    mainLayout->addWidget(signUpButton);

    setLayout(mainLayout);

    connect(signUpButton, &QPushButton::clicked, this, &SignUpScreen::signUp);
    QPixmap background(":/new/prefix1/Ingenious idea.png");
    QPalette palette;
    palette.setBrush(QPalette::Window, background);
    this->setPalette(palette);
}

void SignUpScreen::showMessage(const QString& message) {
    QMessageBox::information(this, "Info", message);
}

void SignUpScreen::signUp() {
    QString username = usernameLineEdit->text();
    QString password = passwordLineEdit->text();

    if (username.isEmpty() || password.isEmpty()) {
        showMessage("Please fill in both fields.");
    } else if (DatabaseManager::instance().userExists(username)) {
        showMessage("Username already exists.");
    } else {
        if (DatabaseManager::instance().addUser(username, password)) {
            showMessage("Account created successfully.");
            accept(); // Close the sign-up dialog
        } else {
            showMessage("Failed to create account.");
        }
    }
}
