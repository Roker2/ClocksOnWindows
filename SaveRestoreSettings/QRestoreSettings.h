#ifndef QRESTORESETTINGS_H
#define QRESTORESETTINGS_H

#include "SaveRestoreSettings/QSaveRestoreBase.h"

class QRestoreSettings : public QSaveRestoreBase
{
    Q_OBJECT
public:
    explicit QRestoreSettings(QSaveRestoreBase *parent = nullptr);
    QRestoreSettings(QString FilePath);
    void Restore();
    void Restore(QString FilePath);
    int *ReturnRedValue();
    int *ReturnGreenValue();
    int *ReturnBlueValue();
    int *ReturnAlphaValue();
    int *ReturnXValue();
    int *ReturnYValue();
    QString *ReturnClocksTypeValue();
    int *ReturnFontSizeValue();

signals:

public slots:
};

#endif // QRESTORESETTINGS_H
