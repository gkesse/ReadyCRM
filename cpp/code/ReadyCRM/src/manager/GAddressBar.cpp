//===============================================
#include "GAddressBar.h"
#include "GManager.h"
//===============================================
GAddressBar::GAddressBar(QWidget* parent) : GWidget(parent) {
    setObjectName("GAddressBar");
    
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
GAddressBar::~GAddressBar() {
    
}
//===============================================
