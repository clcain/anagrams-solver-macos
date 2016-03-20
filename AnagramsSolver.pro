#-------------------------------------------------
#
# Project created by QtCreator 2016-03-19T00:18:40
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = AnagramsSolver
TEMPLATE = app

CONFIG += c++11

SOURCES += main.cpp\
        mainwindow.cpp \
    anagramssolvermodel.cpp

HEADERS  += mainwindow.h \
    anagramssolvermodel.h

DISTFILES +=

RESOURCES += \
    resources.qrc
