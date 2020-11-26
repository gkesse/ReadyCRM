//===============================================
#include "GSchema.h"
#include "GWidget.h"
#include "GSQLite.h"
#include "GManager.h"
//===============================================
// constructor
//===============================================
GSchema::GSchema(QWidget* parent) : GWidget(parent) {
    setObjectName("GSchema");

    QTextEdit* lTextEdit = new QTextEdit;
    m_textEdit = lTextEdit;
    lTextEdit->setObjectName("text");
    lTextEdit->setReadOnly(true);
    
    QVBoxLayout* lMainLatout = new QVBoxLayout;
    lMainLatout->addWidget(lTextEdit);
    lMainLatout->setMargin(0);
    lMainLatout->setSpacing(0);
    
    setLayout(lMainLatout);
}
//===============================================
GSchema::~GSchema() {
    
}
//===============================================
// method
//===============================================
void GSchema::loadPage() {
    sGApp* lApp = GManager::Instance()->getData()->app;
    QStringList lMap = lApp->address_url.split("/");
    QString lTable = lMap[2];
    
    QString lQuery = QString("\
    select sql from sqlite_master \
    where name='%1';\
    ").arg(lTable);
    
    QString lSchema = GSQLite::Instance()->queryValue(lQuery);
    
    m_textEdit->setText(lSchema);
}
//===============================================