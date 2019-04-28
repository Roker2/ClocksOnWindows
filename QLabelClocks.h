#ifndef QLABELCLOCKS_H
#define QLABELCLOCKS_H
#include <QLabel>
#include <QTime>
#include <QPushButton>
#include "ClocksSettings.h"

class QLabelClocks : public QLabel
{
protected:
    virtual void timerEvent(QTimerEvent*)
    {
        if (SettingsMenu)
        {
            changeTransparent("{color : rgba(255, 255, 255, " + QString::number(SettingsMenu->TransparentValue()) + ");");
        }
        else
        {
            changeTransparent("QLabel {color : rgba(255, 255, 255, 80); font-size:36px}");
        }
        QTime time = QTime::currentTime();
        setText(time.toString("h:mm:ss"));
    }
public:
    Clocks *SettingsMenu = NULL;
    QPushButton *SettingsButton = NULL;
    QLabelClocks(QWidget *parent) :
        QLabel(parent)
    {
        setStyleSheet("QLabel {color : rgba(255, 255, 255, 80); font-size:36px}");
        setWindowFlag(Qt::WindowStaysOnTopHint);
        setWindowFlag(Qt::FramelessWindowHint);
        setAttribute(Qt::WA_TranslucentBackground);
        setGeometry(0, 0, 36*8, height());
        startTimer(1);
    }
    void changeTransparent(QString style)
    {
        setStyleSheet("QLabel " + style + " font-size:36px}"); //"QLabel {color : rgba(0, 0, 255, value); font-size:36px}"
        SettingsButton->setStyleSheet("QPushButton " + style + " background-color: rgba(255, 255, 255, 0); border: none}");
    }
};

#endif // QLABELCLOCKS_H
