//===============================================
#include "GUserShow.h"
#include "GWidget.h"
#include "GManager.h"
//===============================================
// constructor
//===============================================
GUserShow::GUserShow(QWidget* parent) : GWidget(parent) {
    setObjectName("GUserShow");
        
    GWidget* lWidget = GWidget::Create("widget");
        
    QVBoxLayout* lMainLatout = new QVBoxLayout;
    lMainLatout->addWidget(lWidget);
    lMainLatout->setAlignment(Qt::AlignTop);
    lMainLatout->setMargin(0);
    lMainLatout->setSpacing(0);
    
    setLayout(lMainLatout);
}
//===============================================
GUserShow::~GUserShow() {
    
}
//===============================================
