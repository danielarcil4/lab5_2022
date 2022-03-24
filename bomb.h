#ifndef BOMB_H
#define BOMB_H

#include <QTimer>
#include "basicobject.h"
#include "softblock.h"
#include "explotation.h"


class bomb:public basicObject
{
private:
    QTimer *timeBomb = new QTimer;
    explotation *central;
    explotation *top;
    explotation *below;
    explotation *right;
    explotation *left;
    int sec=0;

public:
    bomb(int height,int width,QString sprite);
    ~bomb();

    QList<explotation*> exploit(QList<explotation*> exploits);
    QTimer *getTimeBomb() const;

    int getSec() const;
    void setSec(int value);

public slots:
    void loadSprite();
};
#endif // BOMB_H
