#include "score.h"

score::score()
{
    setPlainText(QString("SCORE: ")+QString::number(getPoints()));
    setDefaultTextColor(Qt::white);
    setFont(QFont("Times New Roman",30));
}

void score::updateScore()
{
    setPlainText(QString("SCORE: ")+QString::number(getPoints()));
}

int score::getPoints() const
{
    return points;
}

void score::setPoints(int value)
{
    points = value;
}
