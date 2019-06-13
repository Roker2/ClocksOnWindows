#ifndef CLOCKS_H
#define CLOCKS_H

#include <QWidget>
#include <QString>
#include <QDesktopWidget>
#include <QSystemTrayIcon>
#include <QIcon>
#include <SaveRestoreSettings/QSaveSettings.h>
#include <SaveRestoreSettings/QRestoreSettings.h>

namespace Ui {
class ClocksSettings;
}

class ClocksSettings : public QWidget
{
    Q_OBJECT

public:
    explicit ClocksSettings(QWidget *parent = nullptr);
    ~ClocksSettings();
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
    QString getCSSStyle();

protected:
    void EnableAlarm();
    void EnableTimer();
    bool AlarmState = false;
    bool TimerState = false;
    int Red = 255;
    int Green = 255;
    int Blue = 255;
    int Alpha = 80;
    QString CSSStyle;

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
    void iconActivated(QSystemTrayIcon::ActivationReason reason);

private:
    Ui::ClocksSettings *ui;
    QSystemTrayIcon         * trayIcon;
};

#endif // CLOCKS_H
