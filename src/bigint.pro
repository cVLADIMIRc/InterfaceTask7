QT += core
QT += gui widgets

CONFIG += c++11

TARGET = bigint
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += \
    bigint.cpp\
    boyer.cpp \
    form.cpp \
    main.cpp \
    mycode.cpp

HEADERS += \
    bigint.hpp \
    boyer.h \
    form.h \
    mycode.h

FORMS += \
    form.ui
