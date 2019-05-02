#include "ClocksSettings.h"
#include "ui_ClocksSettings.h"
#include <QFont>

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
    return ui->Edit_FontSize->text().toInt();
}

void Clocks::on_fontComboBox_currentFontChanged(const QFont &f)
{
    QApplication::setFont(f);
    ChangedFont = true;
}
