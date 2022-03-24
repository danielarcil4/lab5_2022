#ifndef ENEMY_H
#define ENEMY_H

#include <QTimer>
#include "basicobject.h"
#include "solidblock.h"
#include "softblock.h"
#include "player.h"

class enemy: public basicObject
{
private:
    QTimer *move = new QTimer;
    int speed=1;
    QList<solidBlock*> collisionsSLB;
    QList<softBlock*> collisionsSFB;

public:
    enemy(int height,int width,QString sprite);
    ~enemy();

    void moving();

    int getSpeed() const;
    void setSpeed(int value);


    QList<solidBlock *> getCollisionsSLB() const;
    void setCollisionsSLB(const QList<solidBlock *> &value);

    QList<softBlock *> getCollisionsSFB() const;
    void setCollisionsSFB(const QList<softBlock *> &value);

public slots:
    void colliding();
};

#endif // ENEMY_H
