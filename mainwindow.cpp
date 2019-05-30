#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Settings = new ClocksSettings;
    LabelClocks = new QLabelClocks(this, Settings);
    connect(ui->Button_Open_Settings, SIGNAL(clicked()), Settings, SLOT(show()));
    LabelClocks->SetSettingsButton(ui->Button_Open_Settings);
    TimeAlarm = new QTimeAlarm(this, LabelClocks);
    TimeAlarm->SetSettingsMenu(Settings);
}

MainWindow::~MainWindow()
{
    delete Settings;
    delete LabelClocks;
    delete TimeAlarm;
    delete ui;
}
