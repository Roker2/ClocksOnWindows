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
            ShowMessage("Alarm", "Current time is " + QTime::currentTime().toString("hh:mm:ss"));
            SettingsMenu->DisableAlarm();
            DisableMusic();
        }
    }
    if(SettingsMenu->GetTimerState())
    {
        if(SettingsMenu->TimerWasEnabled)
        {
            Timer = SettingsMenu->TimerValue();
            SettingsMenu->TimerWasEnabled = false;
        }
        SettingsMenu->TimerMinusTime(ValueTimerEvent);
        Timer = Timer.addMSecs(-ValueTimerEvent);
        if (Timer.toString("hh:mm:ss") == "00:00:00")
        {
            EnableMusic();
            ShowMessage("Timer", "Timer over");
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

void QTimeAlarm::ShowMessage(QString header, QString message)
{
    QMessageBox *info = new QMessageBox(QMessageBox::Information, header, message, QMessageBox::Ok);
    info->setStyleSheet(SettingsMenu->getCSSStyle());
    info->exec();
    delete info;
}
