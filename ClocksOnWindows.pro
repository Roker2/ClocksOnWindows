######################################################################
# Automatically generated by qmake (3.1) Sun Apr 28 04:13:59 2019
######################################################################

QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TEMPLATE = app
TARGET = ClocksOnWindows
INCLUDEPATH += .

# The following define makes your compiler warn you if you use any
# feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Input
HEADERS += ClocksSettings.h mainwindow.h QLabelClocks.h \
    QTimeAlarm.h \
    SaveRestoreSettings/QRestoreSettings.h \
    SaveRestoreSettings/QSaveSettings.h
FORMS += ClocksSettings.ui mainwindow.ui
SOURCES += ClocksSettings.cpp main.cpp mainwindow.cpp QLabelClocks.cpp \
    QTimeAlarm.cpp \
    SaveRestoreSettings/QRestoreSettings.cpp \
    SaveRestoreSettings/QSaveSettings.cpp

#Program Information
VERSION = 0.4.4
win32:RC_ICONS += icons/baseline_extension_white_48dp.ico
QMAKE_TARGET_PRODUCT = Clocks on windows
QMAKE_TARGET_DESCRIPTION = Program by Dmitry Minko (Roker2)
