#ifndef LIVES_H
#define LIVES_H

#include <QGraphicsTextItem>
#include <QFont>
#include "player.h"

class lives:public QGraphicsTextItem
{
private:
    player *player1;
public:
    lives(player *player1);
    ~lives();

    void updateLives();

    player *getPlayer1() const;
    void setPlayer1(player *value);
};

#endif // LIVES_H
