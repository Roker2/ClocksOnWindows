#include "QRestoreSettings.h"

QRestoreSettings::QRestoreSettings(QObject *parent) : QObject(parent)
{
    Restore();
}

void QRestoreSettings::Restore()
{
    QDir PathToSave(QDir::currentPath());
    if (PathToSave.exists())
    {
        PathToSave.cd(SavePath);
        QFile SaveFile(PathToSave.path() + "/savesettings.save");
        if(SaveFile.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            while(!SaveFile.atEnd())
            {
                QString str = SaveFile.readLine();
                QStringList list = str.split("=");
                if(list.at(0) == "Red")
                    Red = list.at(1).toInt();
                else if(list.at(0) == "Green")
                    Green = list.at(1).toInt();
                else if(list.at(0) == "Blue")
                    Blue = list.at(1).toInt();
                else if(list.at(0) == "Alpha")
                    Alpha = list.at(1).toInt();
                else if(list.at(0) == "X")
                    X = list.at(1).toInt();
                else if(list.at(0) == "Y")
                    Y = list.at(1).toInt();
                else if(list.at(0) == "ClocksType")
                {
                    ClocksType = list.at(1);
                    ClocksType.chop(1);//last char is '/n', this char unneeded
                }
                else if(list.at(0) == "FontSize")
                    FontSize = list.at(1).toInt();
            }
        }
        SaveFile.close();
    }
}

int *QRestoreSettings::ReturnRedValue()
{
    return &Red;
}

int *QRestoreSettings::ReturnGreenValue()
{
    return &Green;
}

int *QRestoreSettings::ReturnBlueValue()
{
    return &Blue;
}

int *QRestoreSettings::ReturnAlphaValue()
{
    return &Alpha;
}

int *QRestoreSettings::ReturnXValue()
{
    return &X;
}

int *QRestoreSettings::ReturnYValue()
{
    return &Y;
}

QString *QRestoreSettings::ReturnClocksTypeValue()
{
    return &ClocksType;
}

int *QRestoreSettings::ReturnFontSizeValue()
{
    return &FontSize;
}
