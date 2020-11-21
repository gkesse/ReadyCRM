//===============================================
// widget
#include "GWidget.h"
#include "GListBox.h"
#include "GTitleBar.h"
#include "GAddressBar.h"
#include "GAddressKey.h"
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
void GWidget::addPage(QString key, QWidget* widget, bool isDefault) {}
void GWidget::addItem(QString key, QString text) {}
void GWidget::addItem(QString key, QString text, QIcon icon) {}
void GWidget::addItem(QString key, QString text, QIcon icon, int width, int height) {}
//===============================================
// slot
//===============================================
void GWidget::slotItemClick() {}
//===============================================
