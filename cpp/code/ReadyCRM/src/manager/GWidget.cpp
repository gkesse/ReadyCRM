//===============================================
// widget
#include "GWidget.h"
#include "GLineEdit.h"
#include "GListBox.h"
#include "GTitleBar.h"
#include "GAddressBar.h"
#include "GAddressKey.h"
#include "GLogin.h"
#include "GUserAdd.h"
#include "GSchema.h"
// page
#include "GWindow.h"
#include "GHome.h"
#include "GSQLiteTables.h"
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
    if(key == "lineedit") return new GLineEdit(parent);
    if(key == "listbox") return new GListBox(parent);
    if(key == "titlebar") return new GTitleBar(parent);
    if(key == "addressbar") return new GAddressBar(parent);
    if(key == "addresskey") return new GAddressKey(parent);
    if(key == "login") return new GLogin(parent);
    if(key == "useradd") return new GUserAdd(parent);
    if(key == "schema") return new GSchema(parent);
    // page
    if(key == "window") return new GWindow(parent);
    if(key == "home") return new GHome(parent);
    if(key == "sqlitetables") return new GSQLiteTables(parent);
    if(key == "builder") return new GBuilder(parent);
    // default
    return new GWidget(parent);
}
//===============================================
// method
//===============================================
void GWidget::addPage(QString key, QString title, QWidget* widget, bool isDefault) {}
void GWidget::loadPage() {}
//
void GWidget::addItem(QString key, QString text) {}
void GWidget::addItem(QString key, QString text, int icon) {}
void GWidget::addItem(QString key, QString text, int icon, QLayout* layout) {}
//
void GWidget::removeItem(int index) {}
//
void GWidget::setContent(QString text) {}
void GWidget::setContent(QString key, int icon, QColor color) {}
void GWidget::setContent(QString key, QIcon icon) {}
//
void GWidget::setOption(int mode) {}
//
void GWidget::getData(QString& data) {}
//
void GWidget::reset() {}
//===============================================
// slot
//===============================================
void GWidget::slotItemClick() {}
void GWidget::slotPageOpen() {}
//===============================================
