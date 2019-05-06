#ifndef QLABELCLOCKS_H
#define QLABELCLOCKS_H
#include <QApplication>
#include <QLabel>
#include <QTime>
#include <QPushButton>
#include <QFontMetrics>
#include "ClocksSettings.h"

class QLabelClocks : public QLabel
{
protected:
    int red = 255, green = 255, blue = 255, alpha = 80, x = 0, y = 0, FontSize = 36, pluswidth = 13;
    QString ClocksType = "hh:mm:ss";
    Clocks *SettingsMenu = NULL;
    QPushButton *SettingsButton = NULL;
    QWidget *MainMenu = NULL;
    int LengthLabel()
    {
        QFontMetrics FontInfo(fontMetrics());
        int temp = (FontInfo.width("00:00:00") + FontInfo.leftBearing(':') * 2 + FontInfo.rightBearing(':') * 2);
        for (int i = 0; i < 6; i++)
        {
            temp += FontInfo.leftBearing('0');
            temp += FontInfo.rightBearing('0');
        }
        return temp;
    }
    virtual void timerEvent(QTimerEvent*)
    {
        if (SettingsMenu)
        {
            if (red != SettingsMenu->RedValue() || green != SettingsMenu->GreenValue() || blue != SettingsMenu->BlueValue() || alpha != SettingsMenu->AlphaValue() || SettingsMenu->ChangedFont || FontSize != SettingsMenu->FontSizeValue())
            {
                red = SettingsMenu->RedValue();
                green = SettingsMenu->GreenValue();
                blue = SettingsMenu->BlueValue();
                alpha = SettingsMenu->AlphaValue();
                FontSize = SettingsMenu->FontSizeValue();
                SettingsButton->setGeometry(SettingsButton->x(), 22 + 11 * FontSize / 36, 70 * FontSize / 36, 25 * FontSize / 36);
                SettingsMenu->ChangedFont = false;
                MainMenu->setGeometry(x, y, LengthLabel(), height() + FontSize + pluswidth);
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
                MainMenu->setGeometry(x, y, LengthLabel(), height() + FontSize + pluswidth);
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
        QFontMetrics FontInfo(fontMetrics());
        MainMenu->setGeometry(x, y, width() + (FontInfo.width('0') + FontInfo.rightBearing('0') + FontInfo.leftBearing('0')) * 6 + (FontInfo.rightBearing(':') + FontInfo.leftBearing(':')) * 2, height() + FontSize + pluswidth);
        startTimer(1);
    }
};

#endif // QLABELCLOCKS_H
