#include "QLabelClocks.h"

int QLabelClocks::LengthLabel()
{
    QFontMetrics FontInfo(fontMetrics());
    int temp = 0;
    QString str = SettingsMenu->GetTimerState() ? SettingsMenu->TimerValue().toString(ClocksType) : (QTime::currentTime().toString(ClocksType));
    for (int i = 0; i < str.length(); i++)
    {
        temp += FontInfo.width(str.at(i));
        /*temp += FontInfo.leftBearing(ClocksType.at(i));
        temp += FontInfo.rightBearing(ClocksType.at(i));*/
    }
    SettingsMenu->ClocksWidth = temp;
    return temp;
}

int QLabelClocks::HeightLabel()
{
    QFontMetrics FontInfo(fontMetrics());
    return FontInfo.height();
}

int QLabelClocks::HeightLabelMax()
{
    QFont temp = this->font();
    temp.setPixelSize(SettingsMenu->FontSizeMax());
    QFontMetrics FontInfo(temp);
    return FontInfo.height();
}

void QLabelClocks::timerEvent(QTimerEvent*)
{
    if (SettingsMenu)
    {
        if (red != SettingsMenu->RedValue() || green != SettingsMenu->GreenValue() || blue != SettingsMenu->BlueValue() || alpha != SettingsMenu->AlphaValue() || SettingsMenu->ChangedFont || FontSize != SettingsMenu->FontSizeValue() || SettingsMenu->TextCSSChanged || !SettingsMenu->UseCSS())
        {
            red = SettingsMenu->RedValue();
            green = SettingsMenu->GreenValue();
            blue = SettingsMenu->BlueValue();
            alpha = SettingsMenu->AlphaValue();
            FontSize = SettingsMenu->FontSizeValue();
            SettingsMenu->ChangedFont = false;
            MainMenuSetGeometry();
            if(SettingsMenu->UseCSS() == Qt::CheckState())
                changeColor();
            else
            {
                SetCSSStyle(SettingsMenu->ClocksCSSStyle());
                SettingsMenu->TextCSSChanged = false;
            }
            MainMenuSetGeometry();
        }
        if (ClocksType != SettingsMenu->GetTypeClocks())
        {
            ClocksType = SettingsMenu->GetTypeClocks();
            MainMenuSetGeometry();
        }
    }
    SetSizeAndPos();
    setGeometry(0, 0, LengthLabel(), HeightLabel());
}

void QLabelClocks::changeColor()
{
    setStyleSheet("QLabel {color : rgba(" + QString::number(red) + ", " + QString::number(green) + ", " + QString::number(blue) + ", " + QString::number(alpha) + "); font-size:" + QString::number(FontSize) + "px}"); //"QLabel {color : rgba(0, 0, 255, value); font-size:36px}"
}

void QLabelClocks::SetSizeAndPos()
{
    if (SettingsMenu)
    {
        if (x != SettingsMenu->Coordinate_x() || y != SettingsMenu->Coordinate_y())
        {
            x = SettingsMenu->Coordinate_x();
            y = SettingsMenu->Coordinate_y();
            MainMenuSetGeometry();
        }
    }
}

void QLabelClocks::MainMenuSetGeometry()
{
    MainMenu->setGeometry(x, y, LengthLabel(), HeightLabel());
}

void QLabelClocks::SetSettingsMenu(ClocksSettings *temp)
{
    SettingsMenu = temp;
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

void QLabelClocks::SetCSSStyle(QString CSSStyle)
{
    setStyleSheet("QLabel {" + CSSStyle + "font-size:" + QString::number(FontSize) + "px}");
}

QLabelClocks::QLabelClocks(QWidget *parent, ClocksSettings *Settings) :
    QLabel(parent)
{
    setStyleSheet("QLabel {color : rgba("+ QString::number(red) +", "+ QString::number(blue) +", "+ QString::number(green) +", "+ QString::number(alpha) +"); font-size:" + QString::number(FontSize) + "px}");
    setWindowFlag(Qt::WindowStaysOnTopHint);
    setWindowFlag(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);
    MainMenu = parent;
    SettingsMenu = Settings;
    QFontMetrics FontInfo(fontMetrics());
    startTimer(100);
}
