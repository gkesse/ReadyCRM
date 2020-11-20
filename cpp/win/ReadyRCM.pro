TEMPLATE = app
TARGET = rdcrm
DESTDIR = bin
OBJECTS_DIR = build
MOC_DIR = build
UI_DIR = build
RCC_DIR = build
CONFIG += console release gnu++11
QT += widgets

QMAKE_CXXFLAGS +=\
    -Wno-unused-parameter \
    
include(../code/ReadyCRM/src/GMain.pri)
