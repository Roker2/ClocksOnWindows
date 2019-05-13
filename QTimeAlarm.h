#ifndef QTIMEALARM_H
#define QTIMEALARM_H

#include <QObject>

class QTimeAlarm : public QObject
{
    Q_OBJECT
public:
    explicit QTimeAlarm(QObject *parent = nullptr);

signals:

public slots:
};

#endif // QTIMEALARM_H
