#-------------------------------------------------
#
# Project created by QtCreator 2015-11-11T21:13:34
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets multimedia


TARGET = Fifteens
TEMPLATE = app


SOURCES += main.cpp\
        dialog.cpp \
    field.cpp \
    design.cpp \
    slots.cpp

HEADERS  += dialog.h \
    field.h

FORMS    += dialog.ui

RESOURCES += \
    images.qrc
