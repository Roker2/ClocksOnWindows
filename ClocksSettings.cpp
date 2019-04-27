#include "ClocksSettings.h"
#include "ui_clocks.h"
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
