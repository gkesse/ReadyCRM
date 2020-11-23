//===============================================
// widget
#include "GWidget.h"
#include "GListBox.h"
#include "GTitleBar.h"
#include "GAddressBar.h"
#include "GAddressKey.h"
#include "GLogin.h"
#include "GLineEdit.h"
// page
#include "GWindow.h"
#include "GHome.h"
#include "GBuilder.h"
//===============================================
// constructor
//===============================================
GWidget::GWidget(QWidget* parent) : QFrame(parent) {
    setObjectName("GWidget");
}
//===============================================
GWidget::~GWidget() {
    
}
//===============================================
GWidget* GWidget::Create(QString key, QWidget* parent) {
    // widget
    if(key == "widget") return new GWidget(parent);
    if(key == "listbox") return new GListBox(parent);
    if(key == "titlebar") return new GTitleBar(parent);
    if(key == "addressbar") return new GAddressBar(parent);
    if(key == "addresskey") return new GAddressKey(parent);
    if(key == "login") return new GLogin(parent);
    if(key == "lineedit") return new GLineEdit(parent);
    // page
    if(key == "window") return new GWindow(parent);
    if(key == "home") return new GHome(parent);
    if(key == "builder") return new GBuilder(parent);
    // default
    return new GWidget(parent);
}
//===============================================
// method
//===============================================
void GWidget::addPage(QString key, QString title, QWidget* widget, bool isDefault) {}
//
void GWidget::addItem(QString key, QString text) {}
void GWidget::addItem(QString key, QString text, QIcon icon) {}
void GWidget::addItem(QString key, QString text, QIcon icon, int width, int height) {}
//
void GWidget::setContent(QString text) {}
void GWidget::setContent(int icon1, int icon2) {}
//===============================================
// slot
//===============================================
void GWidget::slotItemClick() {}
//===============================================
