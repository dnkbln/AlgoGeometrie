#-------------------------------------------------
#
# Project created by QtCreator 2013-06-27T21:55:37
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = AlgoGeometrie
TEMPLATE = app

SOURCES += main.cpp\
        widget.cpp \
    point2f.cpp \
    node.cpp \
    graphwidget.cpp \
    circle.cpp

HEADERS  += widget.h \
    point2f.h \
    node.h \
    graphwidget.h \
    circle.h

OTHER_FILES += \
    ReadMe.txt

