QT += core network gui widgets

TARGET = QtSimpleChatServer
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

CONFIG += debug_and_release

HEADERS += \
    memoryblock.h \
    serverConnect.h \
    serverSends.h \
    serverwindow.h

SOURCES += \
    main.cpp \
    memoryblock.cpp \
    serverConnect.cpp \
    serverSends.cpp \
    serverwindow.cpp

FORMS += \
    serverwindow.ui
