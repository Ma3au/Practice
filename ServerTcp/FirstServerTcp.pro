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
    Controller/controller.cpp \
    Controller/server.cpp \
    View/masterview.cpp \
    View/server_gui.cpp

QT      += widgets network

HEADERS  += \
    Controller/controller.h \
    Controller/server.h \
    View/masterview.h \
    View/server_gui.h

FORMS    += \
    View/server_gui.ui

RESOURCES += \
    resourses.qrc
