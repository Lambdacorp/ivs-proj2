#-------------------------------------------------
#
# Project created by QtCreator 2016-04-03T00:58:56
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 00000delete
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    matematics.cpp \
    about.cpp \
    helpwindow.cpp \
    help.cpp

HEADERS  += mainwindow.h \
    matematics.h \
    about.h \
    helpwindow.h \
    help.h

FORMS    += mainwindow.ui \
    about.ui \
    helpwindow.ui \
    help.ui

RESOURCES += images.qrc
