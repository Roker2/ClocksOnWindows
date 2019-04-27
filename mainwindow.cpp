#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>
#include <QTime>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Settings = new Clocks;
    testClocks = new LabelClocks(this);
    testClocks->SettingsMenu = Settings;
    connect(ui->Button_Open_Settings, SIGNAL(clicked()), Settings, SLOT(show()));
}

MainWindow::~MainWindow()
{
    delete ui;
}
