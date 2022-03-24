#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>
#include <QFont>

class score: public QGraphicsTextItem
{
private:
    int points=0;
public:
    score();

    void updateScore();
    int getPoints() const;
    void setPoints(int value);
};

#endif // SCORE_H
