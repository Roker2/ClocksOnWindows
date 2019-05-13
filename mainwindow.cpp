#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Settings = new Clocks;
    LabelClocks = new QLabelClocks(this);
    connect(ui->Button_Open_Settings, SIGNAL(clicked()), Settings, SLOT(show()));
    LabelClocks->SetSettingsMenu(Settings);
    LabelClocks->SetSettingsButton(ui->Button_Open_Settings);
    TimeAlarm = new QTimeAlarm(this, LabelClocks);
    TimeAlarm->SetSettingsMenu(Settings);
}

MainWindow::~MainWindow()
{
    delete ui;
}
