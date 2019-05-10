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

void Clocks::on_fontComboBox_currentFontChanged(const QFont &f)
{
    QApplication::setFont(f);
    ChangedFont = true;
}

void Clocks::on_Button_RightUp_clicked()
{
    QDesktopWidget temp;
    ui->Edit_coordinate_x->setText(QString::number(WidthScreen - ClocksWidth));
    ui->Edit_coordinate_y->setText("0");
}

void Clocks::on_Button_RightDown_clicked()
{
    QDesktopWidget temp;
    ui->Edit_coordinate_x->setText(QString::number(WidthScreen - ClocksWidth));
    ui->Edit_coordinate_y->setText(QString::number(HeightScreen - FontSizeValue()));
}

void Clocks::on_Button_LeftDown_clicked()
{
    QDesktopWidget temp;
    ui->Edit_coordinate_x->setText("0");
    ui->Edit_coordinate_y->setText(QString::number(HeightScreen - FontSizeValue()));
}

void Clocks::on_Button_LeftUp_clicked()
{
    ui->Edit_coordinate_x->setText("0");
    ui->Edit_coordinate_y->setText("0");
}
