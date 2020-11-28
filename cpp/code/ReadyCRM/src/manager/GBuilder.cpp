//===============================================
#include "GBuilder.h"
#include "GWidget.h"
#include "GManager.h"
//===============================================
// constructor
//===============================================
GBuilder::GBuilder(QWidget* parent) : GWidget(parent) {
    setObjectName("GListWidget");
        
    QListWidget* lWidget = new QListWidget;
    m_listWidget = lWidget;
    lWidget->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
    lWidget->setCursor(Qt::PointingHandCursor);
    
    for(int i = 0; i < 50; i++) {
        QString lText = QString("Item %1").arg(i);

        QPushButton* lButton = new QPushButton(lWidget);
        lButton->setObjectName("irow");
        lButton->setText(lText);
        
        QListWidgetItem* lItem = new QListWidgetItem(lWidget);
        
        lWidget->addItem(lItem);
        lWidget->setItemWidget(lItem, lButton);
    }
    
    QVBoxLayout* lMainLatout = new QVBoxLayout;
    lMainLatout->addWidget(lWidget);
    lMainLatout->setAlignment(Qt::AlignTop);
    lMainLatout->setMargin(0);
    lMainLatout->setSpacing(0);
    
    setLayout(lMainLatout);
}
//===============================================
GBuilder::~GBuilder() {
    
}
//===============================================
// slot
//===============================================
void GBuilder::slotItemClick() {
    /*int lCount = m_listWidget->count();
    for(int i = 0; i < lCount; i++) {
        QListWidgetItem* lItem = m_listWidget->item(i);
        lItem->setSizeHint(QSize(width, 40));
    }*/
}
//===============================================
