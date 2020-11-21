//===============================================
#include "GWidget.h"
#include "GWindow.h"
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
    if(key == "widget") return new GWidget(parent);
    if(key == "window") return new GWindow(parent);
    return new GWidget(parent);
}
//===============================================
// methods
//===============================================
void GWidget::addContent(QWidget* widget, QString key, bool isDefault) {}
//===============================================
