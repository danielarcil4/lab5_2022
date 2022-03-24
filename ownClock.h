#ifndef OWNCLOCK_H
#define OWNCLOCK_H

#include <QGraphicsTextItem>
#include <QFont>
#include<QTimer>

class ownClock: public QGraphicsTextItem
{
private:
    int timeClock=100;
    QTimer *timer = new QTimer;
public:
    ownClock();
    int getTimeClock() const;
    void setTimeClock(int value);

signals:
public slots:
    void counting();
};

#endif // OWNCLOCK_H
