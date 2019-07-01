#ifndef QSAVERESTOREBASE_H
#define QSAVERESTOREBASE_H

#include <QObject>
#include <QFile>
#include <QDir>
#include <QString>
#include <QTextStream>

class QSaveRestoreBase : public QObject
{
    Q_OBJECT
public:
    explicit QSaveRestoreBase(QObject *parent = nullptr);
    void setFileName(QString temp);

protected:
    int Red = 255;
    int Green = 255;
    int Blue = 255;
    int Alpha = 80;
    int X = 0;
    int Y = 0;
    int FontSize = 36;
    int UseCSS = 0;
    QString ClocksType = "hh:mm:ss";
    QString SavePath = "save";
    QString FileName = "savesettings.save";
    QString FileNameCSS = "clocks.css";
    QString ClocksCSSStyle = "";

signals:

public slots:
};

#endif // QSAVERESTOREBASE_H
