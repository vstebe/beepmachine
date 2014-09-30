#-------------------------------------------------
#
# Project created by QtCreator 2014-09-30T11:29:49
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = beepmachine
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    note.cpp \
    sheet.cpp \
    player.cpp \
    beepplayer.cpp
    sheetParser.cpp

HEADERS += \
    note.h \
    sheet.h \
    config.h \
    player.h \
    beepplayer.h
    sheetParser.h
