#ifndef QTIMEALARM_H
#define QTIMEALARM_H

#include <QObject>

class QTimeAlarm : public QObject
{
    Q_OBJECT
public:
    explicit QTimeAlarm(QObject *parent = nullptr);

protected:
    virtual void timerEvent(QTimerEvent*);

signals:

public slots:
};

#endif // QTIMEALARM_H
