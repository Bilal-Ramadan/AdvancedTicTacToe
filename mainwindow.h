#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QDialog>
#include <QVBoxLayout>
#include <QTimer>


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class GameOverDialog : public QDialog {
    Q_OBJECT

public:
    explicit GameOverDialog(const QString &result, QWidget *parent = nullptr);
    ~GameOverDialog();

signals:
    void restartGame();
void goHome();
private:
    QLabel *resultLabel;
    QPushButton *restartButton;

    QPushButton *homeButton;

private slots:
    void on_restartButton_clicked();
      void on_homeButton_clicked();
};

class TicTacToeGame : public QObject {
    Q_OBJECT

public:
    int win;
    int lose;
    int draw;
 enum class Player { None, PlayerX, PlayerO };
    enum class GameStatus { InProgress, PlayerXWins, PlayerOWins, Draw };
    GameStatus evaluate(Player board[3][3]);
    GameStatus gameStatus;
    explicit TicTacToeGame(QObject *parent = nullptr);
    void disableButtons();
    void enableButtons();
    void setTurnLabel(QLabel *label);
    void setWinnerLabel(QLabel *label);
    void connectButtons();
    void resetGame();
    void setMode(bool playerVsAI);
    void animateButton(QPushButton* button);

signals:
    void gameEnded(const QString &result);

public slots:
    void handleButtonClick();
    void makeAIMove();

private:



    Player currentPlayer;

    QLabel *turnLabel;
    QLabel *winnerLabel;
    QPushButton *buttons[9];
    Player board[3][3];
    QString style;
    QString currentPlayerText;
    QString currentPlayerColor;
    bool playerVsAI;
    bool checkWinCondition();
    bool checkDrawCondition();
    bool isPlayerTurn;
    void updateStatusLabel();
    int minimax(Player board[3][3], int depth, bool maximizingPlayer);

};







QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void movetoplayedgames();
private slots:
    void endGame(const QString &result);
    void on_restartttGame();
    void on_restartGame();
    void on_playerVsPlayerButton_clicked();
    void on_playerVsAIButton_clicked();
    void on_pushButton_home_clicked();
    void switchToGamePage();
    void switchTohomepage();
    void gotoprofile();

signals:
    void restartGame();

private:
    Ui::MainWindow *ui;
    TicTacToeGame *game;
};

#endif // MAINWINDOW_H
