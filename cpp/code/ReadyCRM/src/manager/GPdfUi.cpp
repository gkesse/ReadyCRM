//===============================================
#include "GPdfUi.h"
#include "GWidget.h"
#include "GManager.h"
//===============================================
// constructor
//===============================================
GPdfUi::GPdfUi(QWidget* parent) : GWidget(parent) {
    setObjectName("GPdfUi");
    
    QTextEdit* lTextEdit = new QTextEdit;
    
    QVBoxLayout* lMainLatout = new QVBoxLayout;
    lMainLatout->addWidget(lTextEdit);
    lMainLatout->setAlignment(Qt::AlignTop);
    lMainLatout->setMargin(0);
    lMainLatout->setSpacing(0);
    
    setLayout(lMainLatout);
}
//===============================================
GPdfUi::~GPdfUi() {
    
}
//===============================================
