#include "QSaveRestoreBase.h"

QSaveRestoreBase::QSaveRestoreBase(QObject *parent) : QObject(parent)
{

}

void QSaveRestoreBase::setFileName(QString temp)
{
    FileName = temp;
}
