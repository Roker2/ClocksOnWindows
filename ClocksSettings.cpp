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

int Clocks::TransparentValue()
{
    return ui->Slider_Transparent->value();
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
