include(C:\Users\Admin\Downloads\Programs\ReadyLib\dev\qtawesome\4.7.0\mingw\QtAwesome.pri)

INCLUDEPATH +=\
    $$PWD/include
    
HEADERS +=\
    $$PWD/include/GWidget.h \
    $$PWD/include/GListBox.h \
    $$PWD/include/GTitleBar.h \
    $$PWD/include/GAddressBar.h \
    $$PWD/include/GAddressKey.h \
    $$PWD/include/GWindow.h \
    $$PWD/include/GHome.h \
    $$PWD/include/GBuilder.h \
    
SOURCES +=\
    $$PWD/main.cpp \
    $$PWD/manager/GProcess.cpp \
    $$PWD/manager/GTest.cpp \
    $$PWD/manager/GManager.cpp \
    $$PWD/manager/GQt.cpp \
    $$PWD/manager/GWidget.cpp \
    $$PWD/manager/GListBox.cpp \
    $$PWD/manager/GAddressBar.cpp \
    $$PWD/manager/GAddressKey.cpp \
    $$PWD/manager/GTitleBar.cpp \
    $$PWD/manager/GWindow.cpp \
    $$PWD/manager/GHome.cpp \
    $$PWD/manager/GBuilder.cpp \
    