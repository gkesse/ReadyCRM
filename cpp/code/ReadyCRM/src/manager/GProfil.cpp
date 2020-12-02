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
    
    QPushButton* lProfilPhoto = new QPushButton;
    lProfilPhoto->setObjectName("profil_photo");
    lProfilPhoto->setIcon(GManager::Instance()->loadPicto(fa::user, lApp->picto_color));
    lProfilPhoto->setIconSize(QSize(lApp->profil_size, lApp->profil_size));
    m_widgetId[lProfilPhoto] = "profil_photo";
    
    GWidget* lUsername = GWidget::Create("lineedit");
    lUsername->setObjectName("username");
    lUsername->setContent("label", "Nom d'utilisateur");
    lUsername->setContent("icon", fa::user, lApp->picto_color);
    lUsername->setOption("readonly", true);
    GManager::Instance()->setProperty(lUsername, "mode", "field");
    m_widgetId[lUsername] = "username";

    QVBoxLayout* lInfoLayout = new QVBoxLayout;
    lInfoLayout->addWidget(lUsername);
    lInfoLayout->setAlignment(Qt::AlignTop);
    lInfoLayout->setMargin(0);
    lInfoLayout->setSpacing(0);
    
    QHBoxLayout* lProfilLayout = new QHBoxLayout;
    lProfilLayout->addWidget(lProfilPhoto);
    lProfilLayout->addLayout(lInfoLayout);
    lProfilLayout->setAlignment(Qt::AlignLeft);
    lProfilLayout->setMargin(0);
    lProfilLayout->setSpacing(20);
    
    QVBoxLayout* lContentLayout = new QVBoxLayout;
    lContentLayout->addWidget(lProfilLabel);
    lContentLayout->addLayout(lProfilLayout);
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
