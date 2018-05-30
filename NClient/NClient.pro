#-------------------------------------------------
#
# Project created by QtCreator 2018-02-24T18:41:58
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = NClient
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    ndialog.cpp \
    auth.cpp

HEADERS  += widget.h \
    ndialog.h \
    auth.h

FORMS    += widget.ui \
    ndialog.ui \
    auth.ui

QMAKE_CXXFLAGS += -std=gnu++11
