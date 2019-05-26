#include "QRestoreSettings.h"

QRestoreSettings::QRestoreSettings(QObject *parent) : QObject(parent)
{

}

void QRestoreSettings::Restore()
{
    QDir PathToSave(QDir::currentPath());
    PathToSave.mkdir(SavePath);
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
            else if(list.at(0) == "Alapha")
                Alpha = list.at(1).toInt();
            else if(list.at(0) == "X")
                X = list.at(1).toInt();
            else if(list.at(0) == "Y")
                Y = list.at(1).toInt();
            else if(list.at(0) == "ClocksType")
                ClocksType = list.at(1);
            else if(list.at(0) == "FontSize")
                FontSize = list.at(1).toInt();
        }
    }
    SaveFile.close();
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
