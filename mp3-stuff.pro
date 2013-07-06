TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += src/main.cpp \
    src/mp3file.cpp \
    src/datafile.cpp

HEADERS += \
    src/mp3file.h \
    src/datafile.h

QMAKE_CXXFLAGS += -std=c++0x
