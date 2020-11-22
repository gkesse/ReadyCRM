//===============================================
#include "GHome.h"
#include "GWidget.h"
#include "GManager.h"
//===============================================
// constructor
//===============================================
GHome::GHome(QWidget* parent) : GWidget(parent) {
    setObjectName("GHome");
        
    GWidget* lListBox = GWidget::Create("listbox");
    
    lListBox->addItem("home", "Accueil");
    lListBox->addItem("home/builder", "Builder");
    
    QVBoxLayout* lMainLayout = new QVBoxLayout;
    lMainLayout->addWidget(lListBox);
    lMainLayout->setAlignment(Qt::AlignTop);
    lMainLayout->setMargin(0);
    lMainLayout->setSpacing(0);
    
    setLayout(lMainLayout);
}
//===============================================
GHome::~GHome() {
    
}
//===============================================
