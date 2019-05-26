#ifndef CLOCKS_H
#define CLOCKS_H

#include <QWidget>
#include <QString>
#include <QDesktopWidget>
#include <SaveRestoreSettings/QSaveSettings.h>

namespace Ui {
class Clocks;
}

class Clocks : public QWidget
{
    Q_OBJECT

public:
    explicit Clocks(QWidget *parent = nullptr);
    ~Clocks();
    int RedValue();
    int GreenValue();
    int BlueValue();
    int AlphaValue();
    int Coordinate_x();
    int Coordinate_y();
    int FontSizeValue();
    int FontSizeMax();
    QTime AlarmTime();
    void DisableAlarm();
    bool GetAlarmState();
    void DisableTimer();
    bool GetTimerState();
    QString GetTypeClocks();
    void TimerMinusTime(int milisecunds);
    QTime TimerValue();
    Qt::CheckState TimerOrClocks();
    int ClocksWidth;
    bool ChangedFont = false;
    bool TimerWasEnabled = false;

protected:
    void EnableAlarm();
    void EnableTimer();
    bool AlarmState = false;
    bool TimerState = false;
    int Red = 255;
    int Green = 255;
    int Blue = 255;
    int Alpha = 80;

private slots:
    void on_Button_SetWhite_clicked();

    void on_Button_SetGrey_clicked();

    void on_Button_SetBlack_clicked();

    void on_fontComboBox_currentFontChanged(const QFont &f);

    void on_Button_RightUp_clicked();

    void on_Button_RightDown_clicked();

    void on_Button_LeftDown_clicked();

    void on_Button_LeftUp_clicked();

    void on_Button_Enable_Disable_Alarm_clicked();

    void on_Button_Enable_Disable_Timer_clicked();

    void on_Slider_Red_valueChanged(int value);

    void on_Slider_Green_valueChanged(int value);

    void on_Slider_Blue_valueChanged(int value);

    void on_Slider_Transparent_valueChanged(int value);

private:
    Ui::Clocks *ui;
};

#endif // CLOCKS_H
