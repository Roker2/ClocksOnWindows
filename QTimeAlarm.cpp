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
            QMediaPlayer *AlarmPlayer = new QMediaPlayer;
            QMediaPlaylist *AlarmMusic = new QMediaPlaylist;
            AlarmMusic->addMedia(QUrl::fromLocalFile(QDir::toNativeSeparators(QDir::current().path() + "/sounds/AlarmMusic.mp3")));
            AlarmMusic->setPlaybackMode(QMediaPlaylist::Loop);
            AlarmPlayer->setPlaylist(AlarmMusic);
            AlarmPlayer->setVolume(100);
            AlarmPlayer->play();
            QMessageBox::information(nullptr, "Alarm", "Current time is " + QTime::currentTime().toString("hh:mm:ss"));
            SettingsMenu->DisableAlarm();
            AlarmPlayer->stop();
            delete AlarmPlayer;
            delete AlarmMusic;
        }
    }
}

void QTimeAlarm::SetSettingsMenu(Clocks *temp)
{
    SettingsMenu = temp;
}
