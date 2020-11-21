//===============================================
#include "GTitleBar.h"
#include "GManager.h"
//===============================================
GTitleBar::GTitleBar(QWidget* parent) : GWidget(parent) {
    setObjectName("GTitleBar");
    
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
GTitleBar::~GTitleBar() {
    
}
//===============================================
