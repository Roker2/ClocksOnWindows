#include "ClocksSettings.h"
#include "ui_ClocksSettings.h"
#include "mainwindow.h"

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

void Clocks::on_Slider_Transparent_valueChanged(int value)
{

}
