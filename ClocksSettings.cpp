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
