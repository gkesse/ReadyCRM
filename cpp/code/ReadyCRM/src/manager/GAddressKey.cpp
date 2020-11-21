//===============================================
#include "GAddressKey.h"
#include "GManager.h"
//===============================================
GAddressKey::GAddressKey(QWidget* parent) : GWidget(parent) {
    setObjectName("GAddressKey");
    
    QPushButton* lLogo = new QPushButton;
    lLogo->setObjectName("logo");
    lLogo->setText("logo");
    
    QHBoxLayout* lMainLayout = new QHBoxLayout;
    lMainLayout->addWidget(lLogo);
    lMainLayout->setMargin(0);
    lMainLayout->setSpacing(0);

    setLayout(lMainLayout);
}
//===============================================
GAddressKey::~GAddressKey() {
    
}
//===============================================
