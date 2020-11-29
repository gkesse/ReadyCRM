//===============================================
#include "GBuilder.h"
#include "GWidget.h"
#include "GManager.h"
//===============================================
// constructor
//===============================================
GBuilder::GBuilder(QWidget* parent) : GWidget(parent) {
    //setObjectName("GListWidget");
        
    QTableWidget* lWidget = new QTableWidget(5, 5);
    m_listWidget = lWidget;
    lWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    lWidget->setCursor(Qt::PointingHandCursor);
    lWidget->horizontalHeader()->setStretchLastSection(true);
    
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            QString lText = QString("Item %1 - %2").arg(i).arg(j);

            QPushButton* lButton = new QPushButton(lWidget);
            lButton->setObjectName("row");
            lButton->setText(lText);
                        
            lWidget->setCellWidget(i, j, lButton);
        }
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
