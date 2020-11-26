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
    
    lListBox->addItem("home/login", "Connexion");
    lListBox->addItem("home/sqlite", "SQLite");
    
    QVBoxLayout* lMainLayout = new QVBoxLayout;
    lMainLayout->addWidget(lListBox);
    lMainLayout->setAlignment(Qt::AlignTop);
    lMainLayout->setMargin(0);
    lMainLayout->setSpacing(0);
    
    setLayout(lMainLayout);
    
    connect(lListBox, SIGNAL(emitItemClick()), this, SLOT(slotItemClick()));
}
//===============================================
GHome::~GHome() {
    
}
//===============================================
// slot
//===============================================
void GHome::slotItemClick() {
    sGApp* lApp = GManager::Instance()->getData()->app;
    GManager::Instance()->setPage(lApp->widget_id);
}
//===============================================
