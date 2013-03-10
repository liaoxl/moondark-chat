#-------------------------------------------------
#
# Project created by QtCreator 2013-03-05T00:41:57
#
#-------------------------------------------------

QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = chat
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    tcpserver.cpp \
    tcpclient.cpp

HEADERS  += widget.h \
    tcpserver.h \
    tcpclient.h

FORMS    += widget.ui \
    tcpserver.ui \
    tcpclient.ui

RESOURCES += \
    imgs.qrc
