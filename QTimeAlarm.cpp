#include "QTimeAlarm.h"

QTimeAlarm::QTimeAlarm(QObject *parent, QLabelClocks *Clocks) : QObject(parent)
{
    LabelClocks = Clocks;
    startTimer(1);
}

void QTimeAlarm::timerEvent(QTimerEvent *)
{
    LabelClocks->SetCurrentTime();
}
