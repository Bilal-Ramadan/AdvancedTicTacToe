#include "ui_mainwindow.h"
#include "HistoryScreen.h"
#include <QCryptographicHash>
#include <QDebug>
#include"mainwindow.h"
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
#include "DatabaseManager.h"
#include "Global.h"
#include"SignInScreen.h"
#include"SignUpScreen.h"


QString style;
QString currentPlayerText;
QString currentPlayerColor;
int saleh[9];





SignInScreen::SignInScreen(QWidget *parent) : QWidget(parent) {
    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    mainLayout->setContentsMargins(40, 40, 40, 40);  // Adjust margins as needed
    mainLayout->setSpacing(20);  // Adjust spacing as needed

    // Username section
    QHBoxLayout* usernameLayout = new QHBoxLayout();
    QLabel* usernameLabel = new QLabel("Username:", this);
    usernameLineEdit = new QLineEdit(this);
    usernameLayout->addWidget(usernameLabel);
    usernameLayout->addWidget(usernameLineEdit);
    mainLayout->addLayout(usernameLayout);

    // Password section
    QHBoxLayout* passwordLayout = new QHBoxLayout();
    QLabel* passwordLabel = new QLabel("Password:", this);
    passwordLineEdit = new QLineEdit(this);
    passwordLineEdit->setEchoMode(QLineEdit::Password);
    passwordLayout->addWidget(passwordLabel);
    passwordLayout->addWidget(passwordLineEdit);
    mainLayout->addLayout(passwordLayout);

    // Login and Sign Up buttons centered
    QHBoxLayout* buttonsLayout = new QHBoxLayout();
    loginButton = new QPushButton("Login", this);
    signUpButton = new QPushButton("Sign Up", this);
    buttonsLayout->addWidget(loginButton);
    buttonsLayout->addWidget(signUpButton);
    mainLayout->addLayout(buttonsLayout);

    // Set button sizes and alignment
    loginButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    signUpButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    buttonsLayout->setAlignment(Qt::AlignCenter);

    // Center the main layout
    mainLayout->setAlignment(Qt::AlignCenter);

    // Set fixed size for the widget
    setLayout(mainLayout);
    setFixedSize(400, 300);  // Adjust size as needed

    // Connect buttons to slots
    connect(loginButton, &QPushButton::clicked, this, &SignInScreen::login);
    connect(signUpButton, &QPushButton::clicked, this, &SignInScreen::openSignUpScreen);

    // Check database connection
    if (!DatabaseManager::instance().connectToDatabase()) {
        QMessageBox::critical(this, "Error", "Database connection failed.");
    }
}

void SignInScreen::showMessage(const QString& message) {
    QMessageBox::information(this, "Info", message);
}
void SignInScreen::login() {
    QString username = usernameLineEdit->text();
    QString password = passwordLineEdit->text();

    if (username.isEmpty() || password.isEmpty()) {
        showMessage("Please fill in both fields.");
    } else if (DatabaseManager::instance().userExists(username)) {
        int userId = DatabaseManager::instance().getUserId(username, password);
        if (userId != -1) {
            currentUserId = userId; // Update the global variable with the current user ID
            // DatabaseManager::instance().incrementGameCounter(currentUserId); // Increment game counter
            // QString::number(DatabaseManager::instance().getGameCounter(currentUserId));
            // DatabaseManager::instance().addGame(currentUserId,"ahmed",DatabaseManager::instance().getGameCounter(currentUserId));
            // DatabaseManager::instance().updateDraws(currentUserId);

            showMessage("Login successful.");
           emit goToGamePage();
        } else {
            showMessage("Incorrect username or password.");
        }
    } else {
        showMessage("Information does not exist, please sign up.");
    }
}

void SignInScreen::openSignUpScreen() {
    SignUpScreen* signUpScreen = new SignUpScreen;
    signUpScreen->show();
}

void SignInScreen::openEmptyScreen() {
    emit goToGamePage();
    close();
}

GameOverDialog::GameOverDialog(const QString &result, QWidget *parent)
    : QDialog(parent), resultLabel(new QLabel(result, this)),
    restartButton(new QPushButton("Restart", this)), homeButton(new QPushButton("Home", this)) {

    setMinimumSize(200, 250);
    setWindowTitle("Game Over");

    resultLabel->setAlignment(Qt::AlignCenter);
    resultLabel->setStyleSheet("font-size: 20px; font-weight: bold;");

    restartButton->setFixedSize(200, 50);
    restartButton->setStyleSheet("font-size: 18px;");

    homeButton->setFixedSize(200, 50);
    homeButton->setStyleSheet("font-size: 18px;");

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(resultLabel);
    layout->addWidget(restartButton);
    layout->addWidget(homeButton);
    layout->setContentsMargins(20, 20, 20, 20);
    layout->setSpacing(20);

    connect(restartButton, &QPushButton::clicked, this, &GameOverDialog::on_restartButton_clicked);
    connect(homeButton, &QPushButton::clicked, this, &GameOverDialog::on_homeButton_clicked);

    setLayout(layout);
}

GameOverDialog::~GameOverDialog() {}

void GameOverDialog::on_restartButton_clicked() {
    emit restartGame();
    close();
}

void GameOverDialog::on_homeButton_clicked() {
    emit goHome();
    close();
}

TicTacToeGame::TicTacToeGame(QObject *parent) : QObject(parent),turnLabel(nullptr), playerVsAI(false) {
    currentPlayer = Player::PlayerX;
    gameStatus = GameStatus::InProgress;

    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            board[row][col] = Player::None;
        }
    }

    turnLabel = nullptr;
    winnerLabel = nullptr;
}
void TicTacToeGame::disableButtons() {
    for (int i = 0; i < 9; ++i) {
        buttons[i]->setEnabled(false);
    }
}

void TicTacToeGame::enableButtons() {
    for (int i = 0; i < 9; ++i) {
        buttons[i]->setEnabled(true);
    }
}
void TicTacToeGame::setTurnLabel(QLabel *label) {
    turnLabel = label;
}

void TicTacToeGame::setWinnerLabel(QLabel *label) {
    winnerLabel = label;
}

void TicTacToeGame::setMode(bool isPlayerVsAI) {
    playerVsAI = isPlayerVsAI;
}

void TicTacToeGame::connectButtons() {
    for (int i = 0; i < 9; ++i) {
        QString buttonName = "pushButton_" + QString::number(i + 1);
        QPushButton *button = qobject_cast<QPushButton*>(parent()->findChild<QObject*>(buttonName));
        if (button) {
            buttons[i] = button;
            connect(button, &QPushButton::clicked, this, &TicTacToeGame::handleButtonClick);
        } else {
            qDebug() << "Button" << buttonName << "not found!";
        }
    }
}
void TicTacToeGame::animateButton(QPushButton* button) {
    QGraphicsOpacityEffect* opacityEffect = new QGraphicsOpacityEffect(button);
    button->setGraphicsEffect(opacityEffect);

    QPropertyAnimation* animation = new QPropertyAnimation(opacityEffect, "opacity");
    animation->setDuration(100); // Duration of the animation in milliseconds
    animation->setStartValue(0.0);
    animation->setEndValue(1.0);
    animation->setEasingCurve(QEasingCurve::InOutQuad);

    animation->start(QPropertyAnimation::DeleteWhenStopped);
}
void TicTacToeGame::resetGame() {
    for (int i = 0; i < 9; ++i) {
        buttons[i]->setText("");

        board[i / 3][i % 3] = Player::None;
    }
    currentPlayer = Player::PlayerX;
    gameStatus = GameStatus::InProgress;
    updateStatusLabel();
}

void TicTacToeGame::handleButtonClick() {
    QPushButton *buttonClicked = qobject_cast<QPushButton*>(sender());
    if (!buttonClicked) return;
        disableButtons();
    int index = -1;
    for (int i = 0; i < 9; ++i) {
        if (buttons[i] == buttonClicked) {
            index = i;
            saleh[i]=index;

            break;
        }
    }
    if (index == -1){
       enableButtons();
        return;
    }
    int row = index / 3;
    int col = index % 3;

    if (board[row][col] != Player::None || gameStatus != GameStatus::InProgress){
        enableButtons();
        return;
    }

    currentPlayerText = (currentPlayer == Player::PlayerX) ? "X" : "O";
    currentPlayerColor = (currentPlayer == Player::PlayerX) ? "red" : "green";
    style = QString(" font: 700 30pt \"Segoe UI\"; border: 6px rgb(63, 124, 171); font-weight: bold; color: %1;").arg(currentPlayerColor);

    buttonClicked->setText(currentPlayerText);
    buttonClicked->setStyleSheet(style);
    animateButton(buttonClicked);
    board[row][col] = currentPlayer;

    if (checkWinCondition()) {
        if (currentPlayer == Player::PlayerX) {
            gameStatus = GameStatus::PlayerXWins;
            DatabaseManager::instance().updateWins(currentUserId);
        } else {
            gameStatus = GameStatus::PlayerOWins;
             DatabaseManager::instance().updateLosses(currentUserId);
        }
        emit gameEnded(currentPlayer == Player::PlayerX ? "Player X wins!" : "Player O wins!");
        enableButtons();
    } else if (checkDrawCondition()) {
        DatabaseManager::instance().updateDraws(currentUserId);
        gameStatus = GameStatus::Draw;
        emit gameEnded("It's a draw!");
        enableButtons();
    } else {
        currentPlayer = (currentPlayer == Player::PlayerX) ? Player::PlayerO : Player::PlayerX;
        updateStatusLabel();
        if (playerVsAI && currentPlayer == Player::PlayerO && gameStatus == GameStatus::InProgress) {
            QTimer::singleShot(200, this, &TicTacToeGame::makeAIMove);
        } else {
            QTimer::singleShot(200, this, [this]() {
                enableButtons();

            });
        }
    }
}

bool TicTacToeGame::checkWinCondition() {
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != Player::None) {
            return true;
        }
    }

    for (int i = 0; i < 3; ++i) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != Player::None) {
            return true;
        }
    }

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != Player::None) {
        return true;
    }

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != Player::None) {
        return true;
    }

    return false;
}

bool TicTacToeGame::checkDrawCondition() {
    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            if (board[row][col] == Player::None) {
                return false;
            }
        }
    }
    return true;
}

void TicTacToeGame::updateStatusLabel() {
    if (turnLabel) {
        turnLabel->setText(QString("Player %1's turn").arg(currentPlayer == Player::PlayerX ? "X" : "O"));
    }
    if (winnerLabel) {
        if (gameStatus == GameStatus::InProgress) {
            winnerLabel->setText("");
        }
    }
}

int TicTacToeGame::minimax(Player board[3][3], int depth, bool maximizingPlayer) {
    GameStatus status = evaluate(board);

    if (status == GameStatus::PlayerXWins) return -10 + depth;
    if (status == GameStatus::PlayerOWins) return 10 - depth;
    if (status == GameStatus::Draw) return 0;

    if (maximizingPlayer) {
        int bestScore = -1000;
        for (int row = 0; row < 3; ++row) {
            for (int col = 0; col < 3; ++col) {
                if (board[row][col] == Player::None) {
                    board[row][col] = Player::PlayerO;
                    int score = minimax(board, depth + 1, false);
                    board[row][col] = Player::None;
                    bestScore = qMax(score, bestScore);
                }
            }
        }
        return bestScore;
    } else {
        int bestScore = 1000;
        for (int row = 0; row < 3; ++row) {
            for (int col = 0; col < 3; ++col) {
                if (board[row][col] == Player::None) {
                    board[row][col] = Player::PlayerX;
                    int score = minimax(board, depth + 1, true);
                    board[row][col] = Player::None;
                    bestScore = qMin(score, bestScore);
                }
            }
        }
        return bestScore;
    }
}

TicTacToeGame::GameStatus TicTacToeGame::evaluate(Player board[3][3]) {
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            if (board[i][0] == Player::PlayerX) return GameStatus::PlayerXWins;
            if (board[i][0] == Player::PlayerO) return GameStatus::PlayerOWins;
        }
    }

    for (int i = 0; i < 3; ++i) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            if (board[0][i] == Player::PlayerX) return GameStatus::PlayerXWins;
            if (board[0][i] == Player::PlayerO) return GameStatus::PlayerOWins;
        }
    }

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        if (board[0][0] == Player::PlayerX) return GameStatus::PlayerXWins;
        if (board[0][0] == Player::PlayerO) return GameStatus::PlayerOWins;
    }

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        if (board[0][2] == Player::PlayerX) return GameStatus::PlayerXWins;
        if (board[0][2] == Player::PlayerO) return GameStatus::PlayerOWins;
    }

    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            if (board[row][col] == Player::None) return GameStatus::InProgress;
        }
    }

    return GameStatus::Draw;
}

void TicTacToeGame::makeAIMove() {
    disableButtons();
    QTimer::singleShot(500, this, [this]() {
        int bestScore = -1000;
        int bestMove[2] = {-1, -1};

        for (int row = 0; row < 3; ++row) {
            for (int col = 0; col < 3; ++col) {
                if (board[row][col] == Player::None) {
                    board[row][col] = Player::PlayerO;
                    int score = minimax(board, 0, false);
                    board[row][col] = Player::None;
                    if (score > bestScore) {
                        bestScore = score;
                        bestMove[0] = row;
                        bestMove[1] = col;
                    }
                }
            }
        }

        if (bestMove[0] != -1 && bestMove[1] != -1) {
            board[bestMove[0]][bestMove[1]] = Player::PlayerO;

            int index = bestMove[0] * 3 + bestMove[1];
            buttons[index]->setText("O");
            buttons[index]->setStyleSheet("font: 700 30pt \"Segoe UI\"; border: 6px rgb(63, 124, 171); font-weight: bold; color: green;");
            animateButton(buttons[index]);
            if (checkWinCondition()) {

                gameStatus = GameStatus::PlayerOWins;
            DatabaseManager::instance().updateLosses(currentUserId);
                emit gameEnded("Player O wins!");
                enableButtons();
            } else if (checkDrawCondition()) {
                 DatabaseManager::instance().updateWins(currentUserId);
                gameStatus = GameStatus::Draw;
                emit gameEnded("It's a draw!");
                enableButtons();
            } else {

                currentPlayer = Player::PlayerX;
            }

            updateStatusLabel();
            enableButtons();
        }
    });
}


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), game(new TicTacToeGame(this)) {
    ui->setupUi(this);

    // Create SignInScreen and add it to page_4 of stackedWidget
    SignInScreen *signInScreen = new SignInScreen;
    ui->stackedWidget->addWidget(signInScreen);
 // Add SignInScreen as page_4

    // Set initial page to SignInScreen (page_4)
    ui->stackedWidget->setCurrentIndex(3);



    game->connectButtons();
    game->setMode(false); // Default mode is Player vs Player

    connect(game, &TicTacToeGame::gameEnded, this, &MainWindow::endGame);
    game->setTurnLabel(ui->turnLabel);
    connect(this, &MainWindow::restartGame, game, &TicTacToeGame::resetGame);


    // Create an instance of HistoryScreen


    connect(ui->pushButton_10, &QPushButton::clicked, this, &MainWindow::on_playerVsPlayerButton_clicked);
    connect(ui->pushButton_11, &QPushButton::clicked, this, &MainWindow::on_playerVsAIButton_clicked);

    connect(signInScreen, &SignInScreen::goToGamePage, this, &MainWindow::switchTohomepage);
    connect(ui->pushButton_home, &QPushButton::clicked, this, &MainWindow::on_pushButton_home_clicked);
    connect(ui->pushButton_restart, &QPushButton::clicked, this, &MainWindow::on_restartttGame);
    connect(ui->pushButton_13, &QPushButton::clicked, this, &MainWindow::gotoprofile);
    connect(ui->pushButton_Home_Profile, &QPushButton::clicked, this, &MainWindow::on_pushButton_home_clicked);

}
MainWindow::~MainWindow() {
    delete ui;
    delete game;
}

void MainWindow::endGame(const QString &result) {

    GameOverDialog *gameOverDialog = new GameOverDialog(result, this);
    connect(gameOverDialog, &GameOverDialog::restartGame, this, &MainWindow::on_restartGame);
    connect(gameOverDialog, &GameOverDialog::goHome, this, &::MainWindow::switchTohomepage);
    // Connect goHome signal
    gameOverDialog->exec();
}
void MainWindow::on_restartttGame(){
emit restartGame();
}
void MainWindow::on_restartGame() {
    emit restartGame();
}

void MainWindow::on_playerVsPlayerButton_clicked() {
    game->setMode(false);
    switchToGamePage();
}

void MainWindow::on_playerVsAIButton_clicked() {
    game->setMode(true);
    switchToGamePage();
}
void MainWindow::on_pushButton_home_clicked() {
    switchTohomepage(); // Assuming switchTohomepage() switches to the homepage
}
void MainWindow::switchToGamePage()
{
    ui->stackedWidget->setCurrentIndex(1); // Set current widget to page_2
    game->resetGame();
}

void MainWindow::switchTohomepage()
{
    ui->stackedWidget->setCurrentIndex(0); // Set current widget to page_1

}
void MainWindow::gotoprofile()
{ int userId = currentUserId;
    HistoryScreen* historyScreen =  new HistoryScreen(userId, ui, this);
    // Create an instance of HistoryScreen
    ui->stackedWidget->setCurrentIndex(2);
    connect(historyScreen, &HistoryScreen::movetoplayed, this, &MainWindow::movetoplayedgames);
}
void MainWindow::movetoplayedgames(){
    ui->stackedWidget->setCurrentIndex(3);

}
