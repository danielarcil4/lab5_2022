#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QMediaPlayer>

#include "player.h"
#include "explotation.h"
#include "ownClock.h"
#include "enemy.h"
#include "score.h"
#include "door.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void keyPressEvent(QKeyEvent *event);
    void createMap();

    void createEnemies();

    int getSec() const;
    void setSec(int value);

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    player *player1;
    int sec=0;
    //door *door1;
    enemy *enemy1;

    QList<solidBlock*> solidBlocks;
    QList<softBlock*> softBlocks;
    QList<bomb*> bombs;
    QList<explotation*> exploits;
    QList<enemy*> enemies;
    QTimer *timerBomb = new QTimer;
    ownClock *timeGame;
    score *points;

    QMediaPlayer *musicInGame;
    QMediaPlayer *bombExplosion;

public slots:
    void timerBombs();
};
#endif // MAINWINDOW_H
