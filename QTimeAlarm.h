#ifndef QTIMEALARM_H
#define QTIMEALARM_H

#include <QObject>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QDir>
#include <QUrl>
#include "QLabelClocks.h"
#include "ClocksSettings.h"

class QTimeAlarm : public QObject
{
    Q_OBJECT
public:
    explicit QTimeAlarm(QObject *parent = nullptr, QLabelClocks *Clocks = NULL);
    void SetSettingsMenu(Clocks *temp);

protected:
    virtual void timerEvent(QTimerEvent*);
    QLabelClocks *LabelClocks;
    Clocks *SettingsMenu;
    QMediaPlayer *AlarmPlayer;
    QMediaPlaylist *AlarmMusic;
    void EnableMusic();
    void DisableMusic();
    QTime Timer;

signals:

public slots:
};

#endif // QTIMEALARM_H
