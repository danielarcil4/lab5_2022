#include "enemy.h"
#include "QDebug"

enemy::enemy(int height,int width,QString sprite)
{
    setHeight(height);
    setWidth(width);
    pixmap = new QPixmap(sprite);
    setPixmap(pixmap->copy(getCol(),getRow(),getWidth(),getHeight()));
    connect(move,&QTimer::timeout,this,&enemy::colliding);
    move->start(10);
}

enemy::~enemy()
{
    delete pixmap;
    delete move;
}

void enemy::moving()
{
    setX(x()+getSpeed());
}

void enemy::colliding()
{
    moving();
    for(short int i=0;i<getCollisionsSFB().length();i++)
        if(abs(x()-getCollisionsSFB()[i]->x())<60 and abs(y()-getCollisionsSFB()[i]->y())<60){
            setSpeed(getSpeed()*-1);
        }
    for(short int i=0;i<getCollisionsSLB().length();i++)
        if(abs(x()-getCollisionsSLB()[i]->x())<60 and abs(y()-getCollisionsSLB()[i]->y())<60){
            setSpeed(getSpeed()*-1);
        }   
}


int enemy::getSpeed() const
{
    return speed;
}

void enemy::setSpeed(int value)
{
    speed = value;
}

QList<solidBlock *> enemy::getCollisionsSLB() const
{
    return collisionsSLB;
}

void enemy::setCollisionsSLB(const QList<solidBlock *> &value)
{
    collisionsSLB = value;
}

QList<softBlock *> enemy::getCollisionsSFB() const
{
    return collisionsSFB;
}

void enemy::setCollisionsSFB(const QList<softBlock *> &value)
{
    collisionsSFB = value;
}

