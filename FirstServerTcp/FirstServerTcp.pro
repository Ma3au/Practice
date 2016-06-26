#-------------------------------------------------
#
# Project created by QtCreator 2016-06-21T07:34:12
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FirstServerTcp
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    server.cpp

QT      += widgets network

HEADERS  += mainwindow.h \
    server.h

FORMS    += mainwindow.ui
