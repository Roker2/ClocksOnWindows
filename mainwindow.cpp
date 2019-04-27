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
    testClocks = new LabelClocks(this);
    Settings = new Clocks;
    connect(ui->Button_Open_Settings, SIGNAL(clicked()), Settings, SLOT(show()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    //QMessageBox::information(this, "Tutturu", "Tutturu!");
    Settings->show();
}
