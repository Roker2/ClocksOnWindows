#ifndef QLABELCLOCKS_H
#define QLABELCLOCKS_H
#include <QApplication>
#include <QLabel>
#include <QTime>
#include <QPushButton>
#include <QFont>
#include "ClocksSettings.h"

class QLabelClocks : public QLabel
{
protected:
    int red = 255, green = 255, blue = 255, alpha = 80, x = 0, y = 0, FontSize = 36;
    QString ClocksType = "hh:mm:ss";
    Clocks *SettingsMenu = NULL;
    QPushButton *SettingsButton = NULL;
    QWidget *MainMenu = NULL;
    virtual void timerEvent(QTimerEvent*)
    {
        if (SettingsMenu)
        {
            if (red != SettingsMenu->RedValue() || green != SettingsMenu->GreenValue() || blue != SettingsMenu->BlueValue() || alpha != SettingsMenu->AlphaValue() || SettingsMenu->ChangedFont)
            {
                red = SettingsMenu->RedValue();
                green = SettingsMenu->GreenValue();
                blue = SettingsMenu->BlueValue();
                alpha = SettingsMenu->AlphaValue();
                SettingsMenu->ChangedFont = false;
                changeColor();
            }
        }
        else
        {
            changeColor();
        }
        QTime time = QTime::currentTime();
        setText(time.toString(ClocksType));
        SetSizeAndPos();
    }
    void changeColor()
    {
        setStyleSheet("QLabel {color : rgba(" + QString::number(red) + ", " + QString::number(green) + ", " + QString::number(blue) + ", " + QString::number(alpha) + "); font-size:" + QString::number(FontSize) + "px}"); //"QLabel {color : rgba(0, 0, 255, value); font-size:36px}"
        SettingsButton->setStyleSheet("QPushButton  {color : rgba(" + QString::number(red) + ", " + QString::number(green) + ", " + QString::number(blue) + ", " + QString::number(alpha) + "); background-color: rgba(" + QString::number(red) + ", " + QString::number(green) + ", " + QString::number(blue) + ", " + QString::number(alpha * 0.35) + "); border: none}");
    }
    void SetSizeAndPos()
    {
        setGeometry(0, 0, width()*1.5, height());
        if (SettingsMenu)
        {
            if (x != SettingsMenu->Coordinate_x() || y != SettingsMenu->Coordinate_y())
            {
                x = SettingsMenu->Coordinate_x();
                y = SettingsMenu->Coordinate_y();
                MainMenu->setGeometry(x, y, MainMenu->width(), MainMenu->height());
            }
        }
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
        setStyleSheet("QLabel {color : rgba("+ QString::number(red) +", "+ QString::number(blue) +", "+ QString::number(green) +", "+ QString::number(alpha) +"); font-size:" + QString::number(FontSize) + "px}");
        setWindowFlag(Qt::WindowStaysOnTopHint);
        setWindowFlag(Qt::FramelessWindowHint);
        setAttribute(Qt::WA_TranslucentBackground);
        MainMenu = parent;
        MainMenu->setGeometry(x, y, MainMenu->width(), MainMenu->height());
        startTimer(1);
    }
};

#endif // QLABELCLOCKS_H
