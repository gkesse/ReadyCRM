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
    m_listBox = lListBox;
    m_widgetId[lListBox] = "listbox";
    
    QVector<QString> lTables = GManager::Instance()->getTables();
    
    for(int i = 0; i < lTables.size(); i++) {
        QString lTable = lTables[i];

        int lCount = GManager::Instance()->countData(lTable);
        
        QPushButton* lShow = new QPushButton;
        m_showId[i] = lShow;
        lShow->setObjectName("show");
        lShow->setText(QString("%1").arg(lCount));
        lShow->setCursor(Qt::PointingHandCursor);
        lShow->setToolTip("Afficher");
        m_widgetId[lShow] = QString("show/%1/%2").arg(lTable).arg(i);

        QPushButton* lSchema = new QPushButton;
        lSchema->setObjectName("schema");
        lSchema->setIcon(GManager::Instance()->loadPicto(fa::cog, lApp->picto_color));
        lSchema->setCursor(Qt::PointingHandCursor);
        lSchema->setToolTip("Schéma");
        m_widgetId[lSchema] = QString("schema/%1/%2").arg(lTable).arg(i);
                
        QPushButton* lAdd = new QPushButton;
        lAdd->setObjectName("add");
        lAdd->setIcon(GManager::Instance()->loadPicto(fa::plus, lApp->picto_color));
        lAdd->setCursor(Qt::PointingHandCursor);
        lAdd->setToolTip("Ajouter");
        m_widgetId[lAdd] = QString("add/%1/%2").arg(lTable).arg(i);
        
        QPushButton* lDelete = new QPushButton;
        lDelete->setObjectName("delete");
        lDelete->setIcon(GManager::Instance()->loadPicto(fa::trash, lApp->picto_color));
        lDelete->setCursor(Qt::PointingHandCursor);
        lDelete->setToolTip("Supprimer");
        m_widgetId[lDelete] = QString("delete/%1/%2").arg(lTable).arg(i);
        
        QHBoxLayout* lActionLayout = new QHBoxLayout;
        lActionLayout->addWidget(lShow);
        lActionLayout->addWidget(lSchema);
        lActionLayout->addWidget(lAdd);
        lActionLayout->addWidget(lDelete);
        lActionLayout->setMargin(0);
        lActionLayout->setSpacing(10);
        
        QString lKey = QString("show/%1/%2").arg(lTable).arg(i);
        
        lListBox->addItem(lKey.toLower(), lTable.toUpper(), fa::database, lActionLayout);
        
        connect(lShow, SIGNAL(clicked()), this, SLOT(slotItemClick()));
        connect(lSchema, SIGNAL(clicked()), this, SLOT(slotItemClick()));
        connect(lAdd, SIGNAL(clicked()), this, SLOT(slotItemClick()));
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
// method
//===============================================
void GSQLiteTables::loadPage() {
    QVector<QString> lTables = GManager::Instance()->getTables();
    
    for(int i = 0; i < lTables.size(); i++) {
        QString lTable = lTables[i];
        int lCount = GManager::Instance()->countData(lTable);
        m_showId[i]->setText(QString("%1").arg(lCount));
    }
}
//===============================================
void GSQLiteTables::deleteTable(QString table, int index) {
    m_listBox->removeItem(index);
    QString lQuery = QString("\
    drop table %1 \
    ").arg(table);
    GSQLite::Instance()->queryWrite(lQuery);
}
//===============================================
// slot
//===============================================
void GSQLiteTables::slotItemClick() {
    QWidget* lWidget = qobject_cast<QWidget*>(sender());
    QString lWidgetId = m_widgetId[lWidget];
             
    if(lWidgetId == "listbox") {

    }
    else {
        QStringList lMap = lWidgetId.split("/");
        QString lKey = lMap[0];
        QString lTable = lMap[1];
        int lIndex = lMap[2].toInt();

        if(lKey == "schema") {
            QString lAddress = QString("home/sqlite/%1/schema")
            .arg(lTable.toLower());
            GManager::Instance()->setPage(lAddress);
        }
        else if(lKey == "add") {
            QString lAddress = QString("home/sqlite/%1/add")
            .arg(lTable.toLower());
            GManager::Instance()->setPage(lAddress);
        }
        else if(lKey == "delete") {
            QString lMessage = QString("Voulez-vous supprimer la table\n%1 ?").
            arg(lTable.toUpper());
            int lOk = GManager::Instance()->showQuestion(this, lMessage);
            if(lOk == QMessageBox::Ok) {
                deleteTable(lTable, lIndex);
            }
        }
    }
}
//===============================================
