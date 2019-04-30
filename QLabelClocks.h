#ifndef QLABELCLOCKS_H
#define QLABELCLOCKS_H
#include <QLabel>
#include <QTime>
#include <QPushButton>
#include "ClocksSettings.h"

class QLabelClocks : public QLabel
{
protected:
    int red = 255, green = 255, blue = 255, alpha = 80;
    QString ClocksType = "hh:mm:ss";
    Clocks *SettingsMenu = NULL;
    QPushButton *SettingsButton = NULL;
    virtual void timerEvent(QTimerEvent*)
    {
        if (SettingsMenu)
        {
            if (red != SettingsMenu->RedValue() || green != SettingsMenu->GreenValue() || blue != SettingsMenu->BlueValue() || alpha != SettingsMenu->AlphaValue())
            {
                changeColor(SettingsMenu->RedValue(), SettingsMenu->GreenValue(), SettingsMenu->BlueValue(), SettingsMenu->AlphaValue());
                red = SettingsMenu->RedValue();
                green = SettingsMenu->GreenValue();
                blue = SettingsMenu->BlueValue();
                alpha = SettingsMenu->AlphaValue();
            }
        }
        else
        {
            changeColor(red, green, blue, alpha);
        }
        QTime time = QTime::currentTime();
        setText(time.toString(ClocksType));
        SetSizeAndPos();
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
    void SetSizeAndPos()
    {
        setGeometry(0, 0, width()*1.5, height());
    }
    QLabelClocks(QWidget *parent) :
        QLabel(parent)
    {
        setStyleSheet("QLabel {color : rgba(255, 255, 255, 80); font-size:36px}");
        setWindowFlag(Qt::WindowStaysOnTopHint);
        setWindowFlag(Qt::FramelessWindowHint);
        setAttribute(Qt::WA_TranslucentBackground);
        startTimer(1);
    }
};

#endif // QLABELCLOCKS_H
