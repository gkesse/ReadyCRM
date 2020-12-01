//===============================================
#include "GProfil.h"
#include "GManager.h"
//===============================================
// constructor
//===============================================
GProfil::GProfil(QWidget* parent) : GWidget(parent) {
    setObjectName("GProfil");
    
    sGApp* lApp = GManager::Instance()->getData()->app;
    
    QPushButton* lProfilLabel = new QPushButton;
    lProfilLabel->setObjectName("profil_label");
    lProfilLabel->setIcon(GManager::Instance()->loadPicto(fa::user, lApp->picto_color));
    lProfilLabel->setText("Profil");
    m_widgetId[lProfilLabel] = "profil_label";
    
    QVBoxLayout* lContentLayout = new QVBoxLayout;
    lContentLayout->addWidget(lProfilLabel);
    lContentLayout->setAlignment(Qt::AlignTop);
    lContentLayout->setMargin(0);
    lContentLayout->setSpacing(10);

    QFrame* lContent = new QFrame;
    lContent->setObjectName("content");
    lContent->setLayout(lContentLayout);
    
    QVBoxLayout* lMainLayout = new QVBoxLayout;
    lMainLayout->addWidget(lContent);
    lMainLayout->setMargin(0);
    lMainLayout->setSpacing(0);

    setLayout(lMainLayout);
    
    //connect(lProfil, SIGNAL(clicked()), this, SLOT(slotItemClick()));
}
//===============================================
GProfil::~GProfil() {

}
//===============================================
// method
//===============================================
int GProfil::loadPage() {
    if(!GManager::Instance()->isLogin()) return 0;
    return 1;
}
//===============================================
// slot
//===============================================
void GProfil::slotItemClick() {
    QWidget* lWidget = qobject_cast<QWidget*>(sender());
    QString lWidgetId = m_widgetId[lWidget];

}
//===============================================
