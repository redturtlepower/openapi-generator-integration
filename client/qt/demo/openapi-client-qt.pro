QT += core gui widgets

CONFIG += c++11
CONFIG -= console

include($$PWD/../openapi/client/client.pri)
INCLUDEPATH += \
$$PWD/../openapi/client

include($$PWD/3rdParty/asyncfuture/asyncfuture.pri)

INCLUDEPATH += .

SOURCES += \
$$PWD\main.cpp \
$$PWD\ClientApiImpl.cpp \
$$PWD\mainwindow.cpp \
$$PWD\testserverdefinition.h

HEADERS += \
$$PWD\ClientApiInterface.h \
$$PWD\ClientApiImpl.h \
$$PWD\mainwindow.h

FORMS += \
$$PWD\mainwindow.ui
