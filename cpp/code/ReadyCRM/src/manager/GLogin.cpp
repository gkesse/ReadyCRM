//===============================================
#include "GLogin.h"
#include "GManager.h"
//===============================================
GLogin::GLogin(QWidget* parent) : GWidget(parent) {
    setObjectName("GLogin");
    
    sGApp* lApp = GManager::Instance()->getData()->app;
    
    QPushButton* lProfil = new QPushButton;
    lProfil->setObjectName("profil");
    lProfil->setIcon(GManager::Instance()->loadPicto(fa::user, lApp->picto_color));
    lProfil->setIconSize(QSize(lApp->profil_size, lApp->profil_size));
    m_widgetId[lProfil] = "profil";
    
    GWidget* lUsername = GWidget::Create("lineedit");
    lUsername->setObjectName("username");
    lUsername->setContent(fa::user, fa::check);
    m_widgetId[lUsername] = "username";
    
    GWidget* lPassowrd = GWidget::Create("lineedit");
    lPassowrd->setObjectName("password");
    lPassowrd->setContent(fa::key, fa::check);
    m_widgetId[lPassowrd] = "password";
        
    QPushButton* lCancel = new QPushButton;
    lCancel->setObjectName("cancel");
    lCancel->setText("Annuler");
    lCancel->setCursor(Qt::PointingHandCursor);
    m_widgetId[lCancel] = "cancel";
        
    QPushButton* lLogin = new QPushButton;
    lLogin->setObjectName("login");
    lLogin->setText("Se Connecter");
    lLogin->setCursor(Qt::PointingHandCursor);
    m_widgetId[lLogin] = "login";
        
    QHBoxLayout* lButtonLayout = new QHBoxLayout;
    lButtonLayout->addWidget(lCancel);
    lButtonLayout->addWidget(lLogin);
    lButtonLayout->setAlignment(Qt::AlignRight);
    lButtonLayout->setMargin(0);
    lButtonLayout->setSpacing(10);

    QHBoxLayout* lProfilLayout = new QHBoxLayout;
    lProfilLayout->addWidget(lProfil);
    lProfilLayout->setAlignment(Qt::AlignCenter);
    lProfilLayout->setMargin(0);
    lProfilLayout->setSpacing(0);

    QVBoxLayout* lContentLayout = new QVBoxLayout;
    lContentLayout->addLayout(lProfilLayout);
    lContentLayout->addWidget(lUsername);
    lContentLayout->addWidget(lPassowrd);
    lContentLayout->addLayout(lButtonLayout);
    lContentLayout->setAlignment(Qt::AlignCenter);
    lContentLayout->setMargin(0);
    lContentLayout->setSpacing(10);

    QFrame* lContent = new QFrame;
    lContent->setObjectName("content");
    lContent->setLayout(lContentLayout);
    
    QVBoxLayout* lMainLayout = new QVBoxLayout;
    lMainLayout->addWidget(lContent);
    lMainLayout->setAlignment(Qt::AlignCenter);
    lMainLayout->setMargin(0);
    lMainLayout->setSpacing(0);

    setLayout(lMainLayout);
    
    connect(lProfil, SIGNAL(clicked()), this, SLOT(slotItemClick()));
    connect(lUsername, SIGNAL(emitItemClick()), this, SLOT(slotItemClick()));
    connect(lPassowrd, SIGNAL(emitItemClick()), this, SLOT(slotItemClick()));
    connect(lLogin, SIGNAL(clicked()), this, SLOT(slotItemClick()));
    connect(lCancel, SIGNAL(clicked()), this, SLOT(slotItemClick()));
}
//===============================================
GLogin::~GLogin() {
    
}
//===============================================
// slot
//===============================================
void GLogin::slotItemClick() {
    QWidget* lWidget = qobject_cast<QWidget*>(sender());
    QString lWidgetId = m_widgetId[lWidget];
}
//===============================================
