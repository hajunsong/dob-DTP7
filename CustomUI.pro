#-------------------------------------------------
#
# Project created by QtCreator 2018-09-10T23:14:23
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TEMPLATE = lib

CONFIG += plugin

cg3300|cg3300_dbg {
    TARGET = CustomUI
}

DESTDIR = ../lib

target.path = /mnt/mtd5
INSTALLS += target

INCLUDEPATH += ../coreDev/include ../coreDev/cui/include


SOURCES +=\
        formcuimain.cpp \
    main.c \
    dob.cpp

HEADERS  += formcuimain.h \
    dob.h

FORMS    += formcuimain.ui
