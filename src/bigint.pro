QT += core
QT += gui widgets

CONFIG += c++11

TARGET = bigint
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += \
    LevelsFacade.cpp \
    bigint.cpp\
    form.cpp \
    main.cpp \
    mycode.cpp

HEADERS += \
    bigint.hpp \
    form.h \
    levelsfacade.h \
    mycode.h

FORMS += \
    form.ui
