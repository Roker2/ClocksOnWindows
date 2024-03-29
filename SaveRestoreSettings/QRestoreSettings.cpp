#include "QRestoreSettings.h"

QRestoreSettings::QRestoreSettings(QSaveRestoreBase *parent) : QSaveRestoreBase(parent)
{
    Restore();
    RestoreCSS();
}

QRestoreSettings::QRestoreSettings(QString FilePath)
{
    Restore(FilePath);
}

void QRestoreSettings::Restore()
{
    QDir PathToSave(QDir::currentPath());
    if (PathToSave.exists())
    {
        PathToSave.cd(SavePath);
        QFile SaveFile(PathToSave.path() + "/" + FileName);
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
                else if(list.at(0) == "UseCSS")
                    UseCSS = list.at(1).toInt();
                else if(list.at(0) == "FontName")
                {
                    FontName = list.at(1);
                    FontName.chop(1);//last char is '/n', this char unneeded
                }
            }
        }
        SaveFile.close();
    }
}

void QRestoreSettings::Restore(QString FilePath)
{
    QFile SaveFile(FilePath);
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
            else if(list.at(0) == "UseCSS")
                UseCSS = list.at(1).toInt();
            else if(list.at(0) == "FontName")
            {
                FontName = list.at(1);
                FontName.chop(1);//last char is '/n', this char unneeded
            }
        }
    }
    SaveFile.close();
}

void QRestoreSettings::RestoreCSS()
{
    QDir PathToSave(QDir::currentPath());
    if (PathToSave.exists())
    {
        PathToSave.cd(SavePath);
        QFile SaveFile(PathToSave.path() + "/" + FileNameCSS);
        if(SaveFile.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            ClocksCSSStyle = SaveFile.readAll();
        }
        SaveFile.close();
    }
}

QString *QRestoreSettings::RestoreClocksCSSStyle()
{
    return &ClocksCSSStyle;
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

int *QRestoreSettings::ReturnUseCSS()
{
    return &UseCSS;
}

QString *QRestoreSettings::RestoreFontName()
{
    return &FontName;
}
