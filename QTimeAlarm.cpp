#include "QTimeAlarm.h"

QTimeAlarm::QTimeAlarm(QObject *parent, QLabelClocks *Clocks) : QObject(parent)
{
    LabelClocks = Clocks;
    startTimer(ValueTimerEvent);
}

void QTimeAlarm::timerEvent(QTimerEvent *)
{
    if (SettingsMenu->GetAlarmState())
    {
        if (QTime::currentTime().toString("hh:mm:ss") == SettingsMenu->AlarmTime().toString("hh:mm:ss"))
        {
            EnableMusic();
            QMessageBox *info = new QMessageBox(QMessageBox::Information, "Alarm", "Current time is " + QTime::currentTime().toString("hh:mm:ss"), QMessageBox::Ok);
            info->exec();
            delete info;
            SettingsMenu->DisableAlarm();
            DisableMusic();
        }
    }
    if(SettingsMenu->TimerWasEnabled)
    {
        Timer = SettingsMenu->TimerValue();
        SettingsMenu->TimerWasEnabled = false;
    }
    if(SettingsMenu->GetTimerState())
    {
        SettingsMenu->TimerMinusTime(ValueTimerEvent);
        Timer = Timer.addMSecs(-ValueTimerEvent);
        if (Timer.toString("hh:mm:ss") == "00:00:00")
        {
            EnableMusic();
            QMessageBox *info = new QMessageBox(QMessageBox::Information, "Timer", "Timer over", QMessageBox::Ok);
            info->exec();
            delete info;
            SettingsMenu->DisableTimer();
            DisableMusic();
        }
    }
    SetClocks();
}

void QTimeAlarm::SetSettingsMenu(ClocksSettings *temp)
{
    SettingsMenu = temp;
}

void QTimeAlarm::EnableMusic()
{
    AlarmPlayer = new QMediaPlayer;
    AlarmMusic = new QMediaPlaylist;
    AlarmMusic->addMedia(QUrl::fromLocalFile(("sounds/AlarmMusic.mp3")));
    AlarmMusic->setPlaybackMode(QMediaPlaylist::Loop);
    AlarmPlayer->setPlaylist(AlarmMusic);
    AlarmPlayer->setVolume(100);
    AlarmPlayer->play();
}

void QTimeAlarm::DisableMusic()
{
    AlarmPlayer->stop();
    delete AlarmPlayer;
    delete AlarmMusic;
}

void QTimeAlarm::SetClocks()
{
    if(SettingsMenu->TimerOrClocks() == Qt::CheckState())
        LabelClocks->SetCurrentTime();
    else
        LabelClocks->SetTime(&Timer);
}
