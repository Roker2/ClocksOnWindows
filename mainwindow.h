#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QLabelClocks.h"
#include "QTimeAlarm.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    QLabelClocks *LabelClocks;
    QTimeAlarm *TimeAlarm;

private:
    Ui::MainWindow *ui;
    Clocks *Settings;
};

#endif // MAINWINDOW_H
