#-------------------------------------------------
#
# Project created by QtCreator 2018-02-24T17:19:37
#
#-------------------------------------------------

QT       += core network

QT       -= gui

TARGET = NServer
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    NSocket.cpp \
    NServer.cpp \
    check.cpp \
    md5.cpp

QMAKE_CXXFLAGS += -std=gnu++11

HEADERS += \
    NSocket.h \
    NServer.h \
    md5.h
