#include "ClocksSettings.h"
#include "ui_ClocksSettings.h"

ClocksSettings::ClocksSettings(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ClocksSettings)
{
    ui->setupUi(this);
    RestoreSetings();
    QFile CSSFile("themes/" + ThemeName+ "/" + ThemeName + ".css");
    if(CSSFile.open(QIODevice::ReadOnly))
    {
        CSSStyle = CSSFile.readAll();
        CSSFile.close();
        setStyleSheet(CSSStyle);
    }
    trayIcon = new QSystemTrayIcon(this);
    QIcon Icon("icons/baseline_schedule_white_48dp.png");
    trayIcon->setIcon(Icon);
    trayIcon->setToolTip("Clocks On Windows Settings");
    trayIcon->show();
    connect(trayIcon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)),
            this, SLOT(iconActivated(QSystemTrayIcon::ActivationReason)));
}

ClocksSettings::~ClocksSettings()
{
    SaveSettings();
    delete  trayIcon;
    delete ui;
}

int ClocksSettings::RedValue()
{
    return Red;
}

int ClocksSettings::GreenValue()
{
    return Green;
}

int ClocksSettings::BlueValue()
{
    return Blue;
}

int ClocksSettings::AlphaValue()
{
    return Alpha;
}

void ClocksSettings::on_Button_SetWhite_clicked()
{
    ui->Slider_Red->setValue(255);
    ui->Slider_Green->setValue(255);
    ui->Slider_Blue->setValue(255);
}

void ClocksSettings::on_Button_SetGrey_clicked()
{
    ui->Slider_Red->setValue(122);
    ui->Slider_Green->setValue(122);
    ui->Slider_Blue->setValue(122);
}

void ClocksSettings::on_Button_SetBlack_clicked()
{
    ui->Slider_Red->setValue(0);
    ui->Slider_Green->setValue(0);
    ui->Slider_Blue->setValue(0);
}

int ClocksSettings::Coordinate_x()
{
    return ui->Edit_coordinate_x->text().toInt();
}

int ClocksSettings::Coordinate_y()
{
    return ui->Edit_coordinate_y->text().toInt();
}

int ClocksSettings::FontSizeValue()
{
    return ui->Slider_FontSize->value();
}
int ClocksSettings::FontSizeMax()
{
    return ui->Slider_FontSize->maximum();
}

void ClocksSettings::on_fontComboBox_currentFontChanged(const QFont &f)
{
    QApplication::setFont(f);
    ChangedFont = true;
}

void ClocksSettings::on_Button_RightUp_clicked()
{
    ui->Edit_coordinate_x->setText(QString::number(QApplication::desktop()->width() - ClocksWidth));
    ui->Edit_coordinate_y->setText("0");
}

void ClocksSettings::on_Button_RightDown_clicked()
{
    ui->Edit_coordinate_x->setText(QString::number(QApplication::desktop()->width() - ClocksWidth));
    ui->Edit_coordinate_y->setText(QString::number(QApplication::desktop()->height() - FontSizeValue()));
}

void ClocksSettings::on_Button_LeftDown_clicked()
{
    ui->Edit_coordinate_x->setText("0");
    ui->Edit_coordinate_y->setText(QString::number(QApplication::desktop()->height() - FontSizeValue()));
}

void ClocksSettings::on_Button_LeftUp_clicked()
{
    ui->Edit_coordinate_x->setText("0");
    ui->Edit_coordinate_y->setText("0");
}

QTime ClocksSettings::AlarmTime()
{
    return ui->timeEdit_Alarm->time();
}

void ClocksSettings::EnableAlarm()
{
    ui->Button_Enable_Disable_Alarm->setText("Disable Alarm");
    AlarmState = true;
}

void ClocksSettings::DisableAlarm()
{
    ui->Button_Enable_Disable_Alarm->setText("Enable Alarm");
    AlarmState = false;
}

void ClocksSettings::on_Button_Enable_Disable_Alarm_clicked()
{
    if(!AlarmState)
    {
        EnableAlarm();
    }
    else
    {
        DisableAlarm();
    }
}

bool ClocksSettings::GetAlarmState()
{
    return AlarmState;
}

QString ClocksSettings::GetTypeClocks()
{
    return ui->Edit_ClocksType->text();
}

void ClocksSettings::on_Button_Enable_Disable_Timer_clicked()
{
    if(!TimerState)
    {
        EnableTimer();
    }
    else
    {
        DisableTimer();
    }
}

bool ClocksSettings::GetTimerState()
{
    return TimerState;
}

void ClocksSettings::EnableTimer()
{
    ui->Button_Enable_Disable_Timer->setText("Disable Timer");
    TimerState = true;
    TimerWasEnabled = true;
    ui->timeEdit_Timer->setReadOnly(true);
    ui->checkBox_clocks_or_timer->setCheckable(true);
}

void ClocksSettings::DisableTimer()
{
    ui->Button_Enable_Disable_Timer->setText("Enable Timer");
    TimerState = false;
    ui->timeEdit_Timer->setReadOnly(false);
    ui->checkBox_clocks_or_timer->setCheckable(false);
}

void ClocksSettings::TimerMinusTime(int milisecunds)
{
    ui->timeEdit_Timer->setTime(TimerValue().addMSecs(-milisecunds));
}

QTime ClocksSettings::TimerValue()
{
    return ui->timeEdit_Timer->time();
}

Qt::CheckState ClocksSettings::TimerOrClocks()
{
    return ui->checkBox_clocks_or_timer->checkState();
}

void ClocksSettings::on_Slider_Red_valueChanged(int value)
{
    Red = value;
}

void ClocksSettings::on_Slider_Green_valueChanged(int value)
{
    Green = value;
}

void ClocksSettings::on_Slider_Blue_valueChanged(int value)
{
    Blue = value;
}


void ClocksSettings::on_Slider_Transparent_valueChanged(int value)
{
    Alpha = value;
}

QString ClocksSettings::getCSSStyle()
{
    return CSSStyle;
}

void ClocksSettings::iconActivated(QSystemTrayIcon::ActivationReason reason)
{
    switch (reason) {
    case QSystemTrayIcon::Trigger:
        if(!this->isVisible())
            this->show();
        break;
    default:
        break;
    }
}

void ClocksSettings::RestoreSetings()
{
    QRestoreSettings RestoreSettings;
    ui->Slider_Red->setValue((*RestoreSettings.ReturnRedValue()));
    ui->Slider_Green->setValue((*RestoreSettings.ReturnGreenValue()));
    ui->Slider_Blue->setValue((*RestoreSettings.ReturnBlueValue()));
    ui->Slider_Transparent->setValue((*RestoreSettings.ReturnAlphaValue()));
    ui->Edit_coordinate_x->setText(QString::number(*RestoreSettings.ReturnXValue()));
    ui->Edit_coordinate_y->setText(QString::number(*RestoreSettings.ReturnYValue()));
    ui->Edit_ClocksType->setText((*RestoreSettings.ReturnClocksTypeValue()));
    ui->Slider_FontSize->setValue((*RestoreSettings.ReturnFontSizeValue()));
}

void ClocksSettings::SaveSettings()
{
    QSaveSettings SaveSettings;
    SaveSettings.SetRedValue(&Red);
    SaveSettings.SetGreenValue(&Green);
    SaveSettings.SetBlueValue(&Blue);
    SaveSettings.SetAlphaValue(&Alpha);
    SaveSettings.SetXValue(Coordinate_x());
    SaveSettings.SetYValue(Coordinate_y());
    SaveSettings.SetClocksTypeValue(GetTypeClocks());
    SaveSettings.SetFontSize(FontSizeValue());
    SaveSettings.Save();
}
