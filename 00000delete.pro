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
    helpwindow.cpp

HEADERS  += mainwindow.h \
    matematics.h \
    about.h \
    helpwindow.h

FORMS    += mainwindow.ui \
    about.ui \
    helpwindow.ui

RESOURCES += images.qrc
