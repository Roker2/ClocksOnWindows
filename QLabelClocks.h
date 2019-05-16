#ifndef QLABELCLOCKS_H
#define QLABELCLOCKS_H
#include <QLabel>
#include <QTime>
#include <QPushButton>
#include <QFontMetrics>
#include <QMessageBox>
#include "ClocksSettings.h"

class QLabelClocks : public QLabel
{
protected:
    int red = 255, green = 255, blue = 255, alpha = 80, x = 0, y = 0, FontSize = 36, pluswidth = -7;
    QString ClocksType = "hh:mm:ss";
    Clocks *SettingsMenu = NULL;
    QPushButton *SettingsButton = NULL;
    QWidget *MainMenu = NULL;
    int LengthLabel();
    virtual void timerEvent(QTimerEvent*);
    void changeColor();
    void SetSizeAndPos();

public:
    void SetSettingsMenu(Clocks *temp);
    void SetSettingsButton(QPushButton *temp);
    void SetCurrentTime();
    void SetTypeClocks(QString type);
    QLabelClocks(QWidget *parent);
};

#endif // QLABELCLOCKS_H
