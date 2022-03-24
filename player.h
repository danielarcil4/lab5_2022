#ifndef PLAYER_H
#define PLAYER_H

#include "basicobject.h"
#include "solidblock.h"
#include "softblock.h"
#include "bomb.h"
#include "enemy.h"

class player:public basicObject
{
/*private:
    int lives=3;
    QTimer *lostLive = new QTimer;*/
public :
    player(int height,int width,QString sprite);
    ~player();

    void walk(int key);
    void colliding(QList<solidBlock*> solidBlocks,QList<softBlock*> softBlocks,int key);
    QList<bomb*> putBomb(QList<bomb*> bombs);

    int getLives() const;
    void setLives(int value);


/*public slots:
    void lost1Live();*/
};

#endif // PLAYER_H
