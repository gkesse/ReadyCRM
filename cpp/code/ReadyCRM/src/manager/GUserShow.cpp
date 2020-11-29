//===============================================
#include "GUserShow.h"
#include "GWidget.h"
#include "GSQLite.h"
#include "GManager.h"
//===============================================
// constructor
//===============================================
GUserShow::GUserShow(QWidget* parent) : GWidget(parent) {
    setObjectName("GUserShow");
    
    sGApp* lApp = GManager::Instance()->getData()->app;

    GWidget* lListBox = GWidget::Create("listbox");
    m_listBox = lListBox;
    m_widgetId[lListBox] = "listbox";
        
    QVector<QVector<QString>> lDataMap = GManager::Instance()->getTableData("users");
        
    for(int i = 0; i < lDataMap.size(); i++) {
        QVector<QString> lDataRow = lDataMap[i];
        
        QString lData = QString("%1 - %2 - %3").arg(lDataRow[0])
        .arg(lDataRow[2]).arg(lDataRow[3]);

        QPushButton* lTitle = new QPushButton;
        lTitle->setObjectName("title");
        lTitle->setText(lData);
        lTitle->setIcon(GManager::Instance()->loadPicto(fa::user, lApp->picto_color));
        lTitle->setCursor(Qt::PointingHandCursor);
        m_widgetId[lTitle] = QString("show/%1/%2").arg(lData).arg(i);

        QHBoxLayout* lRowLayout = new QHBoxLayout;
        lRowLayout->addWidget(lTitle);
        lRowLayout->setMargin(0);
        lRowLayout->setSpacing(0);

        lListBox->addItem(lRowLayout);
        
        connect(lTitle, SIGNAL(clicked()), this, SLOT(slotItemClick()));
    }

    QVBoxLayout* lMainLatout = new QVBoxLayout;
    lMainLatout->addWidget(lListBox);
    lMainLatout->setAlignment(Qt::AlignTop);
    lMainLatout->setMargin(0);
    lMainLatout->setSpacing(0);
    
    setLayout(lMainLatout);
}
//===============================================
GUserShow::~GUserShow() {
    
}
//===============================================
// method
//===============================================
void GUserShow::loadPage() {

}
//===============================================
void GUserShow::deleteTable(QString table, int index) {

}
//===============================================
// slot
//===============================================
void GUserShow::slotItemClick() {

}
//===============================================
