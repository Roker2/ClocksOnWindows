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
    void EnableMusic();
    void DisableMusic();
    void SetClocks();
    QLabelClocks *LabelClocks;
    Clocks *SettingsMenu;
    QMediaPlayer *AlarmPlayer;
    QMediaPlaylist *AlarmMusic;
    QTime Timer;
    int ValueTimerEvent = 333;

signals:

public slots:
};

#endif // QTIMEALARM_H
