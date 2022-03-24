#include "ownClock.h"

ownClock::ownClock()
{
    setPlainText(QString("TIME: ")+QString::number(getTimeClock()));
    setDefaultTextColor(Qt::white);
    setFont(QFont("Times New Roman",30));
    connect(timer,&QTimer::timeout,this,&ownClock::counting);
    timer->start(1000);
}

void ownClock::counting()
{
    setTimeClock(getTimeClock()-1);
    setPlainText(QString("TIME: ")+QString::number(getTimeClock()));
}

int ownClock::getTimeClock() const
{
    return timeClock;
}

void ownClock::setTimeClock(int value)
{
    timeClock = value;
}
