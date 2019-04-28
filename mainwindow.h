#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QLabelClocks.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QLabelClocks *testClocks;

private:
    Ui::MainWindow *ui;
    Clocks *Settings;
};

#endif // MAINWINDOW_H
