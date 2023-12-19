QT += core
QT += gui widgets

CONFIG += c++11

TARGET = bigint
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += \
    bigint.cpp\
    form.cpp \
    main.cpp \
    mycode.cpp

HEADERS += \
    bigint.hpp \
    form.h \
    mycode.h

FORMS += \
    form.ui
