#include "QTimeAlarm.h"

QTimeAlarm::QTimeAlarm(QObject *parent, QLabelClocks *Clocks) : QObject(parent)
{
    LabelClocks = Clocks;
    startTimer(ValueTimerEvent);
}

void QTimeAlarm::timerEvent(QTimerEvent *)
{
    if(SettingsMenu->TimerOrClocks() == Qt::CheckState())
        LabelClocks->SetCurrentTime();
    if (SettingsMenu->GetAlarmState())
    {
        if (QTime::currentTime().toString("hh:mm:ss") == SettingsMenu->AlarmTime().toString("hh:mm:ss"))
        {
            EnableMusic();
            QMessageBox::information(nullptr, "Alarm", "Current time is " + QTime::currentTime().toString("hh:mm:ss"));
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
        QTime temp_time(0, 0, 0, 0);
        SettingsMenu->TimerMinusTime(ValueTimerEvent);
        Timer = Timer.addMSecs(-ValueTimerEvent);
        if (Timer <= temp_time)
        {
            EnableMusic();
            QMessageBox::information(nullptr, "Timer", "Timer over");
            SettingsMenu->DisableTimer();
            DisableMusic();
        }
    }
    if(SettingsMenu->TimerOrClocks() != Qt::CheckState())
        LabelClocks->SetTime(&Timer);
}

void QTimeAlarm::SetSettingsMenu(Clocks *temp)
{
    SettingsMenu = temp;
}

void QTimeAlarm::EnableMusic()
{
    AlarmPlayer = new QMediaPlayer;
    AlarmMusic = new QMediaPlaylist;
    AlarmMusic->addMedia(QUrl::fromLocalFile(QDir::toNativeSeparators(QDir::current().path() + "/sounds/AlarmMusic.mp3")));
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
