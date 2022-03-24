#include "door.h"
#include "QDebug"



player *door::getPlayerWin() const
{
    return playerWin;
}

void door::setPlayerWin(player *value)
{
    playerWin = value;
}

door::door(int height, int width, QString sprite)
{
    setHeight(height);
    setWidth(width);
    setPlayerWin(playerWin);
    pixmap = new QPixmap(sprite);
    setPixmap(pixmap->copy(getCol(),getRow(),getWidth(),getHeight()));
    connect(timer,&QTimer::timeout,this,&door::win);
    timer->start(1000);
}

door::~door()
{
    delete pixmap;
}

int door::addRamdomPos(QList<softBlock *> softBlocks)
{
     int randomBlock = rand()%softBlocks.length();
     setPos(softBlocks[randomBlock]->x(),softBlocks[randomBlock]->y());
     return randomBlock;
}


void door::win()
{
    if(abs(getPlayerWin()->x()-x())<=0 and abs(getPlayerWin()->y()-y())<=0){
        qDebug()<<"winner";
    }
}

