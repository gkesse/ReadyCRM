include(C:\Users\Admin\Downloads\Programs\ReadyLib\dev\qtawesome\4.7.0\mingw\QtAwesome.pri)

INCLUDEPATH +=\
    $$PWD/include
    
HEADERS +=\
    $$PWD/include/GManager.h \
    $$PWD/include/GMessageBox.h \
    $$PWD/include/GWidget.h \
    $$PWD/include/GLineEdit.h \
    $$PWD/include/GListBox.h \
    $$PWD/include/GListWidget.h \
    $$PWD/include/GTableWidget.h \
    $$PWD/include/GAddressBar.h \
    $$PWD/include/GAddressKey.h \
    $$PWD/include/GTitleBar.h \
    $$PWD/include/GLogin.h \
    $$PWD/include/GProfil.h \
    $$PWD/include/GUserAdd.h \
    $$PWD/include/GUserShow.h \
    $$PWD/include/GUserMap.h \
    $$PWD/include/GSchema.h \
    $$PWD/include/GWindow.h \
    $$PWD/include/GHome.h \
    $$PWD/include/GSQLiteTables.h \
    $$PWD/include/GHtmlEdit.h \
    $$PWD/include/GHtmlView.h \
    $$PWD/include/GPdfUi.h \
    $$PWD/include/GBuilder.h \
    
SOURCES +=\
    $$PWD/main.cpp \
    $$PWD/manager/GProcess.cpp \
    $$PWD/manager/GTest.cpp \
    $$PWD/manager/GManager.cpp \
    $$PWD/manager/GSQLite.cpp \
    $$PWD/manager/GPdf.cpp \
    $$PWD/manager/GQt.cpp \
    $$PWD/manager/GMessageBox.cpp \
    $$PWD/manager/GWidget.cpp \
    $$PWD/manager/GLineEdit.cpp \
    $$PWD/manager/GListBox.cpp \
    $$PWD/manager/GListWidget.cpp \
    $$PWD/manager/GTableWidget.cpp \
    $$PWD/manager/GAddressBar.cpp \
    $$PWD/manager/GAddressKey.cpp \
    $$PWD/manager/GTitleBar.cpp \
    $$PWD/manager/GLogin.cpp \
    $$PWD/manager/GProfil.cpp \
    $$PWD/manager/GUserAdd.cpp \
    $$PWD/manager/GUserShow.cpp \
    $$PWD/manager/GUserMap.cpp \
    $$PWD/manager/GSchema.cpp \
    $$PWD/manager/GWindow.cpp \
    $$PWD/manager/GHome.cpp \
    $$PWD/manager/GSQLiteTables.cpp \
    $$PWD/manager/GHtmlEdit.cpp \
    $$PWD/manager/GHtmlView.cpp \
    $$PWD/manager/GPdfUi.cpp \
    $$PWD/manager/GBuilder.cpp \

CONFIG += console release gnu++11
QT += widgets sql printsupport

QMAKE_CXXFLAGS +=\
    -Wno-unused-parameter \
    -Wno-deprecated-declarations \
