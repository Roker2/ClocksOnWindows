#ifndef QSAVESETTINGS_H
#define QSAVESETTINGS_H

#include "SaveRestoreSettings/QSaveRestoreBase.h"

class QSaveSettings : public QSaveRestoreBase
{
    Q_OBJECT
public:
    explicit QSaveSettings(QSaveRestoreBase *parent = nullptr);
    void SetRedValue(int *value);
    void SetGreenValue(int *value);
    void SetBlueValue(int *value);
    void SetAlphaValue(int *value);
    void SetXValue(int value);
    void SetYValue(int value);
    void SetClocksTypeValue(QString value);
    void SetFontSize(int value);
    void SetClocksCSSStyle(QString value);
    void SetUseCSS(int value);
    void SetFontName(QString value);
    void Save();
    void Save(QString FilePath);
    void SaveCSS();

signals:

public slots:
};

#endif // QSAVESETTINGS_H
