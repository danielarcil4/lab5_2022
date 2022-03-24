#include "lives.h"


lives::lives(player *player1)
{
    setPlayer1(player1);
    setPlainText(QString("LIVES: ")+QString::number(player1->getLives()));
    setDefaultTextColor(Qt::white);
    setFont(QFont("Times New Roman",30));
}

void lives::updateLives()
{
    setPlainText(QString("LIVES: ")+QString::number(player1->getLives()));
}

player *lives::getPlayer1() const
{
    return player1;
}

void lives::setPlayer1(player *value)
{
    player1 = value;
}

