#-------------------------------------------------
#
# Project created by QtCreator 2016-06-21T17:51:57
#
#-------------------------------------------------

QT       += core gui widgets network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TcpClient
TEMPLATE = app


SOURCES += main.cpp\
    Controller/client.cpp \
    Controller/nmea.cpp \
    View/clientgui.cpp \
    Controller/controller.cpp \
    View/masterview.cpp \
    Controller/mrk.cpp \
    View/mrkgui.cpp \
    coordinate.cpp

HEADERS  += \
    Controller/client.h \
    Controller/nmea.h \
    View/clientgui.h \
    Controller/controller.h \
    View/masterview.h \
    Controller/mrk.h \
    View/mrkgui.h \
    coordinate.h

FORMS    += \
    View/clientgui.ui \
    View/mrkgui.ui \
    View/masterview.ui
