#include "explotation.h"
#include "QDebug"

explotation::explotation(int height, int width, QString sprite,int x,int y)
{
    setHeight(height);
    setWidth(width);
    pixmap = new QPixmap(sprite);
    setPixmap(pixmap->copy(getCol(),getRow(),getWidth(),getHeight()));
    setPos(x,y);
}

explotation::~explotation()
{
    delete pixmap;
}


QList<softBlock*> explotation::doDamage(QList<softBlock*> softBlocks)
{
    for(short int i=0;i<softBlocks.length();i++)
        if(abs(y()-softBlocks[i]->y())<60 and abs(x()-softBlocks[i]->x())<60){
            //softBlocks[i]->~softBlock();
            delete softBlocks[i];
            softBlocks.removeAt(i);
        }
    return softBlocks;
}

QList<enemy *> explotation::doDamage(QList<enemy *> enemies)
{
    for(short int i=0;i<enemies.length();i++)
            if(abs(y()-enemies[i]->y())<60 and abs(x()-enemies[i]->x())<60){
                //enemies[i]->~enemies();
                delete enemies[i];
                enemies.removeAt(i);
            }
        return enemies;
}

