#ifndef QTIMEALARM_H
#define QTIMEALARM_H

#include <QObject>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QDir>
#include <QUrl>
#include <QMessageBox>
#include "QLabelClocks.h"
#include "ClocksSettings.h"

class QTimeAlarm : public QObject
{
    Q_OBJECT
public:
    explicit QTimeAlarm(QObject *parent = nullptr, QLabelClocks *Clocks = NULL);
    void SetSettingsMenu(ClocksSettings *temp);

protected:
    virtual void timerEvent(QTimerEvent*);
    void EnableMusic();
    void DisableMusic();
    void SetClocks();
    void ShowMessage(QString header, QString message);
    QLabelClocks *LabelClocks;
    ClocksSettings *SettingsMenu;
    QMediaPlayer *AlarmPlayer;
    QMediaPlaylist *AlarmMusic;
    QTime Timer;
    int ValueTimerEvent = 333;

signals:

public slots:
};

#endif // QTIMEALARM_H
