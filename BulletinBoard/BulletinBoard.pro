TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    bboard.cpp \
    user.cpp \
    message.cpp

HEADERS += \
    bboard.h \
    user.h \
    message.h
