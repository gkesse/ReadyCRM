//===============================================
#include "GMessageBox.h"
#include "GManager.h"
//===============================================
// constructor
//===============================================
GMessageBox::GMessageBox(QMessageBox::Icon icon, const QString &title, const QString &text, QMessageBox::StandardButtons buttons, QWidget *parent, Qt::WindowFlags f) :
QMessageBox(icon, title, text, buttons, parent, f) {
    setObjectName("GMessageBox");
}
//===============================================
GMessageBox::GMessageBox(QWidget* parent) : QMessageBox(parent) {
    setObjectName("GMessageBox");
}
//===============================================
GMessageBox::~GMessageBox() {
    
}
//===============================================
