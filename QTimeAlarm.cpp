#include "QTimeAlarm.h"

QTimeAlarm::QTimeAlarm(QWidget *parent, QLabelClocks *Clocks) : QObject(parent)
{
    LabelClocks = Clocks;
    startTimer(1);
}

void QTimeAlarm::timerEvent(QTimerEvent *)
{
    LabelClocks->SetCurrentTime();
}

void QTimeAlarm::SetSettingsMenu(Clocks *temp)
{
    SettingsMenu = temp;
}
