QT += core
QT -= gui
QT+=testlib

CONFIG += c++11

TARGET = test
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    matematics.cpp \
    testmath.cpp

HEADERS += \
    matematics.h \
    testmath.h
