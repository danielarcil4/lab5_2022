#include "bomb.h"
#include <QDebug>


bomb::bomb(int height, int width, QString sprite)
{
    setHeight(height);
    setWidth(width);
    pixmap = new QPixmap(sprite);
    setPixmap(pixmap->copy(getCol(),getRow(),getWidth(),getHeight()));
    connect(timeBomb,&QTimer::timeout,this,&bomb::loadSprite);
    timeBomb->start(500);
}

bomb::~bomb()
{
    delete pixmap;
    delete timeBomb;
    /*delete top;
    delete below;
    delete right;
    delete left;*/
}

QList<explotation*> bomb::exploit(QList<explotation*> exploits)
{
    exploits.push_back(central = new explotation(60,60,":/Sprites/explotion.png",x(),y()));
    exploits.push_back(top = new explotation(60,60,":/Sprites/explotion.png",x(),y()-60));
    exploits.push_back(below = new explotation(60,60,":/Sprites/explotion.png",x(),y()+60));
    exploits.push_back(right = new explotation(60,60,":/Sprites/explotion.png",x()+60,y()));
    exploits.push_back(left = new explotation(60,60,":/Sprites/explotion.png",x()-60,y()));

    central->updateSprite(450,450);
    top->updateSprite(450,320);
    below->updateSprite(450,580);
    right->updateSprite(580,450);
    left->updateSprite(320,450);

    return exploits;
}

void bomb::loadSprite()
{
    setSec(getSec()+1);
    if(getCol()>=120) setCol(-60);
    updateSprite(getCol()+60,0);
}

QTimer *bomb::getTimeBomb() const
{
    return timeBomb;
}

int bomb::getSec() const
{
    return sec;
}

void bomb::setSec(int value)
{
    sec = value;
}
