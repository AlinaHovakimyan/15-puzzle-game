#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QtWidgets>
#include <QMediaPlayer>
#include <map>
#include "field.h"

struct Pair {
public:
    Pair(int x, int y):m_x(x),m_y(y){};
    bool operator<(const Pair& anotherPair) const;
private:
    int m_x;
    int m_y;
};

struct Time {
    bool operator=(int value) {
        hour = value;
        min = value;
        sec = value;
        return true;
    };
    int hour;
    int min;
    int sec;
};

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget* parent = nullptr);
    ~Dialog();

    void startGame();
private:
    enum {
        newGame,
        continueGame,
        other
    } windowType;
    enum State {
        showHelp,
        dontShowHelp,
        win
    };
private slots:
    void on_mixPiecesButton_clicked();
    void on_closeBurron_clicked();

    void on_newGame_clicked();
    void on_continueGame_clicked();
    void on_bestScores_clicked();
    void on_setLevel_clicked();
    void on_help_clicked();
    void on_aboutUs_clicked();
    void on_back_clicked();
    void on_backToMenu_clicked();

    void showTime();
    void showMenu();
    bool event(QEvent* event);

    void setOne(bool on);
    void setTwo(bool on);
    void setThree(bool on);
    void setFour(bool on);
private:
    //init functions
    void setInitVisibilites();
    void setInitStyles();
    void setInitGeometries();
    void createConnections();
    void createLevelButtons();
    void startTimer();

    // wark with labels
    void createLabels();
    void initLabels();
    void createLabelsWithImage();
    void recalculateField();
    void recalculateImgField();
    int getIndex(int x, int y) const;

    // win functions
    void handleWin();
    void cultivateScore();

    //set visibilities
    void setWinVisibilities();
    void setNewGameVisibilities();
    void setContinueGameVisibilities();
    void setBackToMenuVisibilities();

    // wark with files
    const char* getFileName();
    void readFile(const QString& fileName, bool readFirstLine = true);
    void readNthLine(std::istream& in, int n);
    void readPrevGameState(std::vector<int>& numbers);
    void readPrevGameStateInf();
    void writeGameState();
    void writeGameStateInf();

    // events
    void keyPressEvent(QKeyEvent* event);
    void mousePressEvent(QMouseEvent* event);
private:
    Ui::Dialog*    ui;
    QWidget*      m_menu;
    QMovie*       m_gif;
    QMediaPlayer* m_music;
    Field         field;
    int           m_level;
    int           m_prevLevel;
    unsigned int  m_emptyLabelIndex;
    std::map<Pair, int> m_coordinateToIndex;
    QLabel*       labels[16];
    QString       m_img;
    State         m_state;
    QTimer*       timer;
    Time          playingTime;
    static const QString m_filePath;
    static const int MAX_SCORES_COUNT = 5;
};

#endif // DIALOG_H
