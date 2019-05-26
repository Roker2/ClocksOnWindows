#ifndef QRESTORESETTINGS_H
#define QRESTORESETTINGS_H

#include <QObject>
#include <QFile>
#include <QDir>
#include <QString>
#include <QTextStream>

class QRestoreSettings : public QObject
{
    Q_OBJECT
public:
    explicit QRestoreSettings(QObject *parent = nullptr);
    void Restore();
    int *ReturnRedValue();
    int *ReturnGreenValue();
    int *ReturnBlueValue();
    int *ReturnAlphaValue();
    int *ReturnXValue();
    int *ReturnYValue();
    QString *ReturnClocksTypeValue();
    int *ReturnFontSizeValue();

protected:
    int Red = 255;
    int Green = 255;
    int Blue = 255;
    int Alpha = 80;
    int X = 0;
    int Y = 0;
    int FontSize = 36;
    QString ClocksType = "hh:mm:ss";
    QString SavePath = "save";

signals:

public slots:
};

#endif // QRESTORESETTINGS_H
