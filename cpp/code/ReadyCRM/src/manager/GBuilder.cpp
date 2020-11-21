//===============================================
#include "GBuilder.h"
#include "GWidget.h"
#include "GManager.h"
//===============================================
// constructor
//===============================================
GBuilder::GBuilder(QWidget* parent) : GWidget(parent) {
    setObjectName("GBuilder");
        
    GWidget* lListBox = GWidget::Create("listbox");
        
    QVBoxLayout* lMainLatout = new QVBoxLayout;
    lMainLatout->addWidget(lListBox);
    lMainLatout->setAlignment(Qt::AlignTop);
    lMainLatout->setMargin(0);
    lMainLatout->setSpacing(0);
    
    setLayout(lMainLatout);
}
//===============================================
GBuilder::~GBuilder() {
    
}
//===============================================
