//===============================================
#include "GSQLiteTables.h"
#include "GWidget.h"
#include "GSQLite.h"
#include "GManager.h"
//===============================================
// constructor
//===============================================
GSQLiteTables::GSQLiteTables(QWidget* parent) : GWidget(parent) {
    setObjectName("GSQLiteTables");
    
    sGApp* lApp = GManager::Instance()->getData()->app;

    GWidget* lListBox = GWidget::Create("listbox");
    m_widgetId[lListBox] = "listbox";
    
    QVector<QString> lTables = GSQLite::Instance()->queryCol("\
    select name from sqlite_master \
    where type='table' \
    order by name \
    ");
    
    for(int i = 0; i < lTables.size(); i++) {
        QPushButton* lDelete = new QPushButton;
        lDelete->setObjectName("delete");
        lDelete->setIcon(GManager::Instance()->loadPicto(fa::trash, lApp->picto_color));
        lDelete->setCursor(Qt::PointingHandCursor);
        lDelete->setToolTip("Supprimer");
        m_widgetId[lDelete] = QString("%1/delete").arg(i);
        
        QHBoxLayout* lActionLayout = new QHBoxLayout;
        lActionLayout->addWidget(lDelete);
        lActionLayout->setMargin(0);
        lActionLayout->setSpacing(0);
        
        QString lTable = lTables[i];
        QString lKey = QString("%1/%2").arg(i).arg(lTable);
        lListBox->addItem(lKey.toLower(), lTable.toUpper(), fa::database, lActionLayout);
        
        connect(lDelete, SIGNAL(clicked()), this, SLOT(slotItemClick()));
    }

    QVBoxLayout* lMainLatout = new QVBoxLayout;
    lMainLatout->addWidget(lListBox);
    lMainLatout->setAlignment(Qt::AlignTop);
    lMainLatout->setMargin(0);
    lMainLatout->setSpacing(0);
    
    setLayout(lMainLatout);
    
    connect(lListBox, SIGNAL(emitItemClick()), this, SLOT(slotItemClick()));
}
//===============================================
GSQLiteTables::~GSQLiteTables() {
    
}
//===============================================
// slot
//===============================================
void GSQLiteTables::slotItemClick() {
    sGApp* lApp = GManager::Instance()->getData()->app;
    QWidget* lWidget = qobject_cast<QWidget*>(sender());
    QString lKey = m_widgetId[lWidget];
    
    QString lIndex = lKey.split("/").first();
    QString lWidgetId = lKey.split("/").last();
    
    if(lWidgetId == "listbox") {
        qDebug() << lApp->widget_id;
    }
    else {
        if(lWidgetId == "delete") {
            int lOk = GManager::Instance()->showQuestion(this, 
            "Voulez-vous supprimer la table ?");
            qDebug() << lWidgetId << lOk;
        }
    }
}
//===============================================
