#include "QTimeAlarm.h"

QTimeAlarm::QTimeAlarm(QObject *parent, QLabelClocks *Clocks) : QObject(parent)
{
    LabelClocks = Clocks;
    startTimer(1);
}

void QTimeAlarm::timerEvent(QTimerEvent *)
{
    LabelClocks->SetCurrentTime();
    if (SettingsMenu->AlarmState)
    {
        if (QTime::currentTime() == SettingsMenu->AlarmTime())
        {
            QMessageBox::information(nullptr, "Tutturu!", "Alarm");
            SettingsMenu->DisableAlarm();
        }
    }
}

void QTimeAlarm::SetSettingsMenu(Clocks *temp)
{
    SettingsMenu = temp;
}
