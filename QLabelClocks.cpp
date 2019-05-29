#include "QLabelClocks.h"

int QLabelClocks::LengthLabel()
{
    QFontMetrics FontInfo(fontMetrics());
    int temp = 0;
    for (int i = 0; i < ClocksType.length(); i++)
    {
        temp += FontInfo.width(ClocksType.at(i));
        /*temp += FontInfo.leftBearing(ClocksType.at(i));
        temp += FontInfo.rightBearing(ClocksType.at(i));*/
    }
    SettingsMenu->ClocksWidth = temp;
    return temp;
}

void QLabelClocks::timerEvent(QTimerEvent*)
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
            SettingsButton->setGeometry(SettingsButton->x(), 22 + 11 * FontSize / SettingsMenu->FontSizeMax(), 70 * FontSize / SettingsMenu->FontSizeMax(), 25 * FontSize / SettingsMenu->FontSizeMax());
            SettingsMenu->ChangedFont = false;
            MainMenu->setGeometry(x, y, LengthLabel(), height() + FontSize + pluswidth);
            changeColor();
            setGeometry(0, 0, LengthLabel(), height());
        }
        if (ClocksType != SettingsMenu->GetTypeClocks())
        {
            ClocksType = SettingsMenu->GetTypeClocks();
            setGeometry(0, 0, LengthLabel(), height());
            MainMenu->setGeometry(x, y, LengthLabel(), height() + FontSize + pluswidth);
        }
    }
    SetSizeAndPos();
}

void QLabelClocks::changeColor()
{
    setStyleSheet("QLabel {color : rgba(" + QString::number(red) + ", " + QString::number(green) + ", " + QString::number(blue) + ", " + QString::number(alpha) + "); font-size:" + QString::number(FontSize) + "px}"); //"QLabel {color : rgba(0, 0, 255, value); font-size:36px}"
    SettingsButton->setStyleSheet("QPushButton  {color : rgba(" + QString::number(red) + ", " + QString::number(green) + ", " + QString::number(blue) + ", " + QString::number(alpha) + "); background-color: rgba(" + QString::number(red) + ", " + QString::number(green) + ", " + QString::number(blue) + ", " + QString::number(alpha * 0.35) + "); border: none}");
}

void QLabelClocks::SetSizeAndPos()
{
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

void QLabelClocks::SetSettingsMenu(ClocksSettings *temp)
{
    SettingsMenu = temp;
}

void QLabelClocks::SetSettingsButton(QPushButton *temp)
{
    SettingsButton = temp;
}

void QLabelClocks::SetCurrentTime()
{
    setText(QTime::currentTime().toString(ClocksType));
}

void QLabelClocks::SetTypeClocks(QString type)
{
    ClocksType = type;
}

void QLabelClocks::SetTime(QTime *time)
{
    setText(time->toString(ClocksType));
}

QLabelClocks::QLabelClocks(QWidget *parent) :
    QLabel(parent)
{
    setStyleSheet("QLabel {color : rgba("+ QString::number(red) +", "+ QString::number(blue) +", "+ QString::number(green) +", "+ QString::number(alpha) +"); font-size:" + QString::number(FontSize) + "px}");
    setWindowFlag(Qt::WindowStaysOnTopHint);
    setWindowFlag(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);
    MainMenu = parent;
    QFontMetrics FontInfo(fontMetrics());
    MainMenu->setGeometry(x, y, width() + (FontInfo.width('0') + FontInfo.rightBearing('0') + FontInfo.leftBearing('0')) * 6 + (FontInfo.rightBearing(':') + FontInfo.leftBearing(':')) * 2 + 6, height() + FontSize + pluswidth);
    startTimer(100);
}
