#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Settings = new Clocks;
    testClocks = new QLabelClocks(this);
    connect(ui->Button_Open_Settings, SIGNAL(clicked()), Settings, SLOT(exec()));
    testClocks->SetSettingsMenu(Settings);
    testClocks->SetSettingsButton(ui->Button_Open_Settings);
}

MainWindow::~MainWindow()
{
    delete ui;
}
