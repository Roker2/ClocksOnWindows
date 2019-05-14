#include "QTimeAlarm.h"

QTimeAlarm::QTimeAlarm(QObject *parent, QLabelClocks *Clocks) : QObject(parent)
{
    LabelClocks = Clocks;
    startTimer(1000);
}

void QTimeAlarm::timerEvent(QTimerEvent *)
{
    LabelClocks->SetCurrentTime();
    if (SettingsMenu->GetAlarmState())
    {
        if (QTime::currentTime().toString("hh:mm:ss") == SettingsMenu->AlarmTime().toString("hh:mm:ss"))
        {
            QMessageBox::information(nullptr, "Alarm", "Tutturu!");
            SettingsMenu->DisableAlarm();
        }
    }
}

void QTimeAlarm::SetSettingsMenu(Clocks *temp)
{
    SettingsMenu = temp;
}
