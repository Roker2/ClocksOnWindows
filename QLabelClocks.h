#ifndef QLABELCLOCKS_H
#define QLABELCLOCKS_H
#include <QLabel>
#include <QTime>
#include <QPushButton>
#include <QFontMetrics>
#include "ClocksSettings.h"

class QLabelClocks : public QLabel
{
protected:
    int red = 255, green = 255, blue = 255, alpha = 80, x = 0, y = 0, FontSize = 36, pluswidth = -7;
    QString ClocksType = "hh:mm:ss";
    ClocksSettings *SettingsMenu = NULL;
    QWidget *MainMenu = NULL;
    int LengthLabel();
    int HeightLabel();
    virtual void timerEvent(QTimerEvent*);
    void changeColor();
    void SetSizeAndPos();
    void MainMenuSetGeometry();
    int HeightLabelMax();
    void SetCSSStyle(QString CSSStyle);

public:
    void SetSettingsMenu(ClocksSettings *temp);
    void SetCurrentTime();
    void SetTypeClocks(QString type);
    QLabelClocks(QWidget *parent, ClocksSettings *Settings);
    void SetTime(QTime *time);
};

#endif // QLABELCLOCKS_H
