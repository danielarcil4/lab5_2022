#include "player.h"
#include <QDebug>


player::player(int height, int width, QString sprite)
{
    setHeight(height);
    setWidth(width);
    pixmap = new QPixmap(sprite);
    setPixmap(pixmap->copy(getCol(),getRow(),getWidth(),getHeight()));
    //connect(lostLive,&QTimer::timeout,this,&player::lost1Live);
}

player::~player()
{
    delete pixmap;
}

void player::walk(int key)
{
    switch (key) {
        case Qt::Key_W:
            setY(y()-10);
            if(getCol()>=300 or getCol()<180)
                setCol(120);
            updateSprite(getCol()+60,60);
            break;
        case Qt::Key_D:
            setX(x()+10);
            if(getCol()>=120)
                setCol(-60);
            updateSprite(getCol()+60,60);
            break;
        case Qt::Key_S:
            setY(y()+10);
            if(getCol()>=300 or getCol()<180)
                setCol(120);
            updateSprite(getCol()+60,-3);
            break;
        case Qt::Key_A:
            setX(x()-10);
            if(getCol()>=120)
                setCol(-60);
            updateSprite(getCol()+60,-3);
            break;
    }

}

void player::colliding(QList<solidBlock*> solidBlocks,QList<softBlock*> softBlocks,int key)
{
    for(short int i=0;i<solidBlocks.length();i++)
        if(abs(x()-solidBlocks[i]->x())<60 and abs(y()-solidBlocks[i]->y())<60){
            switch (key) {
                case Qt::Key_W:
                    setY(y()+10);
                    break;
                case Qt::Key_D:
                    setX(x()-10);
                    break;
                case Qt::Key_S:
                    setY(y()-10);
                    break;
                case Qt::Key_A:
                    setX(x()+10);
                    break;
            }
        }
    for(short int i=0;i<softBlocks.length();i++)
        if(abs(x()-softBlocks[i]->x())<60 and abs(y()-softBlocks[i]->y())<60){
            switch (key) {
                case Qt::Key_W:
                    setY(y()+10);
                    break;
                case Qt::Key_D:
                    setX(x()-10);
                    break;
                case Qt::Key_S:
                    setY(y()-10);
                    break;
                case Qt::Key_A:
                    setX(x()+10);
                    break;
            }
        }
    /*for(short int i=0;i<enemies.length();i++)
        if(abs(x()-enemies[i]->x())<60 and abs(y()-enemies[i]->y())<60){
            lostLive->start(1500);
    }*/

}

void player::lost1Live()
{
    setLives(getLives()-1);
    lostLive->stop();
}

QList<bomb*> player::putBomb(QList<bomb*> bombs)
{
    if(bombs.length()<3){
        bombs.push_back(new bomb(60,60,":/Sprites/bomb.png"));
        bombs.back()->setPos(int (x()/60)*60,int (y()/60)*60);
    }

    return bombs;
}

int player::getLives() const
{
    return lives;
}

void player::setLives(int value)
{
    lives = value;
}
