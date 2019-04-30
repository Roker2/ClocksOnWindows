#ifndef QLABELCLOCKS_H
#define QLABELCLOCKS_H
#include <QLabel>
#include <QTime>
#include <QPushButton>
#include "ClocksSettings.h"

class QLabelClocks : public QLabel
{
protected:
    QString TypeClocks = "hh:mm:ss";
    Clocks *SettingsMenu = NULL;
    QPushButton *SettingsButton = NULL;
    virtual void timerEvent(QTimerEvent*)
    {
        if (SettingsMenu)
        {
            changeColor(SettingsMenu->RedValue(), SettingsMenu->GreenValue(), SettingsMenu->BlueValue(), SettingsMenu->AlphaValue());
        }
        else
        {
            changeColor(255, 255, 255, 80);
        }
        QTime time = QTime::currentTime();
        setText(time.toString(TypeClocks));
    }
    void changeColor(int red, int green, int blue, int alpha)
    {
        setStyleSheet("QLabel {color : rgba(" + QString::number(red) + ", " + QString::number(green) + ", " + QString::number(blue) + ", " + QString::number(alpha) + "); font-size:36px}"); //"QLabel {color : rgba(0, 0, 255, value); font-size:36px}"
        SettingsButton->setStyleSheet("QPushButton  {color : rgba(" + QString::number(red) + ", " + QString::number(green) + ", " + QString::number(blue) + ", " + QString::number(alpha) + "); background-color: rgba(" + QString::number(red) + ", " + QString::number(green) + ", " + QString::number(blue) + ", " + QString::number(alpha * 0.35) + "); border: none}");
    }
public:
    void SetSettingsMenu(Clocks *temp)
    {
        SettingsMenu = temp;
    }
    void SetSettingsButton(QPushButton *temp)
    {
        SettingsButton = temp;
    }
    QLabelClocks(QWidget *parent) :
        QLabel(parent)
    {
        setStyleSheet("QLabel {color : rgba(255, 255, 255, 80); font-size:36px}");
        setWindowFlag(Qt::WindowStaysOnTopHint);
        setWindowFlag(Qt::FramelessWindowHint);
        setAttribute(Qt::WA_TranslucentBackground);
        setGeometry(0, 0, width(), height());
        startTimer(1);
    }
};

#endif // QLABELCLOCKS_H
