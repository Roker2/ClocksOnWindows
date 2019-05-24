#include "ClocksSettings.h"
#include "ui_ClocksSettings.h"

Clocks::Clocks(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Clocks)
{
    ui->setupUi(this);
}

Clocks::~Clocks()
{
    delete ui;
}

int Clocks::RedValue()
{
    return ui->Slider_Red->value();
}

int Clocks::GreenValue()
{
    return ui->Slider_Green->value();
}

int Clocks::BlueValue()
{
    return ui->Slider_Blue->value();
}

int Clocks::AlphaValue()
{
    return ui->Slider_Transparent->value();
}

void Clocks::on_Button_SetWhite_clicked()
{
    ui->Slider_Red->setValue(255);
    ui->Slider_Green->setValue(255);
    ui->Slider_Blue->setValue(255);
}

void Clocks::on_Button_SetGrey_clicked()
{
    ui->Slider_Red->setValue(122);
    ui->Slider_Green->setValue(122);
    ui->Slider_Blue->setValue(122);
}

void Clocks::on_Button_SetBlack_clicked()
{
    ui->Slider_Red->setValue(0);
    ui->Slider_Green->setValue(0);
    ui->Slider_Blue->setValue(0);
}

int Clocks::Coordinate_x()
{
    return ui->Edit_coordinate_x->text().toInt();
}

int Clocks::Coordinate_y()
{
    return ui->Edit_coordinate_y->text().toInt();
}

int Clocks::FontSizeValue()
{
    return ui->Slider_FontSize->value();
}
int Clocks::FontSizeMax()
{
    return ui->Slider_FontSize->maximum();
}


void Clocks::on_fontComboBox_currentFontChanged(const QFont &f)
{
    QApplication::setFont(f);
    ChangedFont = true;
}

void Clocks::on_Button_RightUp_clicked()
{
    ui->Edit_coordinate_x->setText(QString::number(QApplication::desktop()->width() - ClocksWidth));
    ui->Edit_coordinate_y->setText("0");
}

void Clocks::on_Button_RightDown_clicked()
{
    ui->Edit_coordinate_x->setText(QString::number(QApplication::desktop()->width() - ClocksWidth));
    ui->Edit_coordinate_y->setText(QString::number(QApplication::desktop()->height() - FontSizeValue()));
}

void Clocks::on_Button_LeftDown_clicked()
{
    ui->Edit_coordinate_x->setText("0");
    ui->Edit_coordinate_y->setText(QString::number(QApplication::desktop()->height() - FontSizeValue()));
}

void Clocks::on_Button_LeftUp_clicked()
{
    ui->Edit_coordinate_x->setText("0");
    ui->Edit_coordinate_y->setText("0");
}

QTime Clocks::AlarmTime()
{
    return ui->timeEdit_Alarm->time();
}

void Clocks::EnableAlarm()
{
    ui->Button_Enable_Disable_Alarm->setText("Disable Alarm");
    AlarmState = true;
}

void Clocks::DisableAlarm()
{
    ui->Button_Enable_Disable_Alarm->setText("Enable Alarm");
    AlarmState = false;
}

void Clocks::on_Button_Enable_Disable_Alarm_clicked()
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

bool Clocks::GetAlarmState()
{
    return AlarmState;
}

QString Clocks::GetTypeClocks()
{
    return ui->Edit_ClocksType->text();
}

void Clocks::on_Button_Enable_Disable_Timer_clicked()
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

bool Clocks::GetTimerState()
{
    return TimerState;
}

void Clocks::EnableTimer()
{
    ui->Button_Enable_Disable_Timer->setText("Disable Timer");
    TimerState = true;
    TimerWasEnabled = true;
    ui->timeEdit_Timer->setReadOnly(true);
}

void Clocks::DisableTimer()
{
    ui->Button_Enable_Disable_Timer->setText("Enable Timer");
    TimerState = false;
    ui->timeEdit_Timer->setReadOnly(false);
}

void Clocks::TimerMinusTime(int milisecunds)
{
    ui->timeEdit_Timer->setTime(TimerValue().addMSecs(-milisecunds));
}

QTime Clocks::TimerValue()
{
    return ui->timeEdit_Timer->time();
}
