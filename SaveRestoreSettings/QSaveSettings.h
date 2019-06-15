#ifndef QSAVESETTINGS_H
#define QSAVESETTINGS_H

#include <QObject>
#include <QFile>
#include <QDir>
#include <QString>
#include <QTextStream>

class QSaveSettings : public QObject
{
    Q_OBJECT
public:
    explicit QSaveSettings(QObject *parent = nullptr);
    void SetRedValue(int *value);
    void SetGreenValue(int *value);
    void SetBlueValue(int *value);
    void SetAlphaValue(int *value);
    void SetXValue(int value);
    void SetYValue(int value);
    void SetClocksTypeValue(QString value);
    void SetFontSize(int value);
    void Save();

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
    QString FileName = "savesettings.save";

signals:

public slots:
};

#endif // QSAVESETTINGS_H
