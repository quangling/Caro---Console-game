TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        _Board.cpp \
        _Common.cpp \
        _Game.cpp \
        _Play.cpp \
        _Point.cpp \
        main.cpp

HEADERS += \
    _Board.h \
    _Common.h \
    _Game.h \
    _Play.h \
    _Point.h
