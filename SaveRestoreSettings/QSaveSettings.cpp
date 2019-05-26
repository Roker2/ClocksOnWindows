#include "QSaveSettings.h"

QSaveSettings::QSaveSettings(QObject *parent) : QObject(parent)
{

}

void QSaveSettings::Save()
{
    QDir PathToSave(QDir::currentPath());
    PathToSave.mkdir(SavePath);
    PathToSave.cd(SavePath);
    QFile SaveFile(PathToSave.path() + "/savesettings.save");
    if(SaveFile.exists())
    {
        SaveFile.remove();
    }
    SaveFile.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream stream(&SaveFile);
    stream << "Red=" << Red << endl;
    stream << "Green=" << Green << endl;
    stream << "Blue=" << Blue << endl;
    stream << "Alpha=" << Alpha << endl;
    stream << "X=" << X << endl;
    stream << "Y=" << Y << endl;
    stream << "ClocksType=" << ClocksType << endl;
    stream << "FontSize=" << FontSize << endl;
    SaveFile.close();
}

void QSaveSettings::SetRedValue(int *value)
{
    Red = (*value);
}

void QSaveSettings::SetGreenValue(int *value)
{
    Green = (*value);
}

void QSaveSettings::SetBlueValue(int *value)
{
    Blue = (*value);
}

void QSaveSettings::SetAlphaValue(int *value)
{
    Alpha = (*value);
}

void QSaveSettings::SetXValue(int value)
{
    X = value;
}

void QSaveSettings::SetYValue(int value)
{
    Y = value;
}

void QSaveSettings::SetClocksTypeValue(QString value)
{
    ClocksType = value;
}

void QSaveSettings::SetFontSize(int value)
{
    FontSize = value;
}
