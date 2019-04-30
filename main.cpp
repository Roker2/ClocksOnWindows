#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowFlag(Qt::WindowStaysOnTopHint);
    w.setWindowFlag(Qt::FramelessWindowHint);//SplashScreen FramelessWindowHint
    w.setAttribute(Qt::WA_TranslucentBackground);
    w.setGeometry(0, 0, w.width(), w.height());
    w.show();

    return a.exec();
}
