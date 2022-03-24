#ifndef EXPLOTATION_H
#define EXPLOTATION_H

#include "basicobject.h"
#include "softblock.h"
#include "enemy.h"

class explotation:public basicObject
{

public:
    explotation(int height,int width,QString sprite,int x,int y);
    ~explotation();

    QList<softBlock*> doDamage(QList<softBlock*> softBlocks);
    QList<enemy*> doDamage(QList<enemy*> enemies);
};

#endif // EXPLOTATION_H
