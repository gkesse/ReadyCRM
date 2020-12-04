//===============================================
#include "GHtmlUi.h"
#include "GWidget.h"
#include "GManager.h"
//===============================================
// constructor
//===============================================
GHtmlUi::GHtmlUi(QWidget* parent) : GWidget(parent) {
    setObjectName("GHtmlUi");
        
    QVBoxLayout* lMainLatout = new QVBoxLayout;
    //lMainLatout->addWidget(lWidget);
    lMainLatout->setAlignment(Qt::AlignTop);
    lMainLatout->setMargin(0);
    lMainLatout->setSpacing(0);
    
    setLayout(lMainLatout);
}
//===============================================
GHtmlUi::~GHtmlUi() {
    
}
//===============================================
