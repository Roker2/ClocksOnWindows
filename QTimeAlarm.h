#ifndef QTIMEALARM_H
#define QTIMEALARM_H

#include <QObject>
#include "QLabelClocks.h"
#include "ClocksSettings.h"

class QTimeAlarm : public QObject
{
    Q_OBJECT
public:
    explicit QTimeAlarm(QObject *parent = nullptr, QLabelClocks *Clocks = NULL);

protected:
    virtual void timerEvent(QTimerEvent*);
    QLabelClocks *LabelClocks;
    Clocks *SeetingsMenu;

signals:

public slots:
};

#endif // QTIMEALARM_H
