#ifndef DOOR_H
#define DOOR_H

#include "basicobject.h"
#include "softblock.h"
#include "player.h"

class door:public basicObject
{
private:
    QTimer *timer = new QTimer;
    player *playerWin;
public:
    door(int height,int width,QString sprite);
    ~door();

    int addRamdomPos(QList<softBlock *> softBlocks);

    player *getPlayerWin() const;
    void setPlayerWin(player *value);

public slots:
    void win();

};

#endif // DOOR_H
