QT += core network gui widgets

TARGET = QtSimpleChatServer
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

CONFIG += debug_and_release

HEADERS += \
    serverConnect.h \
    serverInterface.h \
    serverSends.h

SOURCES += \
    main.cpp \
    serverConnect.cpp \
    serverInterface.cpp \
    serverSends.cpp

FORMS += \
    serverInterface.ui
