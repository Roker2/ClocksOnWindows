#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QTime>
#include "ClocksSettings.h"

class LabelClocks : public QLabel
{
protected:
    virtual void timerEvent(QTimerEvent*)
    {
        QTime time = QTime::currentTime();
        setText(time.toString("h:mm:ss"));
    }
public:
    LabelClocks(QWidget *parent) :
        QLabel(parent)
    {
        setStyleSheet("QLabel {color : rgba(0, 0, 255, 122); font-size:36px}");
        setWindowFlag(Qt::WindowStaysOnTopHint);
        setWindowFlag(Qt::FramelessWindowHint);
        setAttribute(Qt::WA_TranslucentBackground);
        setGeometry(0, 0, 36*8, height());
        startTimer(1000);
    }
    void changeTransparent(int value)
    {
        setStyleSheet("QLabel {color : rgba(0, 0, 255, value); font-size:36px}");
    }
};

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    LabelClocks *testClocks;

private:
    Ui::MainWindow *ui;
    Clocks *Settings;
};

#endif // MAINWINDOW_H
