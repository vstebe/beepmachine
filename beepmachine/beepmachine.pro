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

INCLUDEPATH += /usr/local/include

LIBS += -L/usr/local/lib -lmidifile

SOURCES += main.cpp \
    note.cpp \
    sheet.cpp \
    player.cpp \
    beepplayer.cpp \
    sheetParser.cpp \
    debugplayer.cpp \
    exportbeepplayer.cpp \
    midiParser.cpp \
    playablenote.cpp

HEADERS += \
    note.h \
    sheet.h \
    config.h \
    player.h \
    beepplayer.h \
    sheetParser.h \
    debugplayer.h \
    exportbeepplayer.h \
    midiParser.h \
    parser.h \
    playablenote.h
