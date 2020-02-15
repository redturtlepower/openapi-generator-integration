QT += core gui widgets network

CONFIG += c++11
CONFIG -= console

include($$PWD/../qhttpengine/src/qhttpengine.pri)
INCLUDEPATH += $$PWD/../qhttpengine/src/include

include($$PWD/../openapi/server/server.pri)
INCLUDEPATH += \
$$PWD/../openapi/server/src \
$$PWD/../openapi/server/src/handlers \
$$PWD/../openapi/server/src/models \
$$PWD/../openapi/server/src/requests

INCLUDEPATH += .

SOURCES += \
$$PWD\main.cpp \
$$PWD\mainwindow.cpp \
    serverapiimpl.cpp

HEADERS += \
$$PWD\mainwindow.h \
    customapirouter.h \
    custompetsapihandler.h \
    logger.h \
    serverapiimpl.h \
    testserverdefinition.h

FORMS += \
$$PWD\mainwindow.ui
