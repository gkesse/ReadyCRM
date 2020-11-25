//===============================================
#include "GLogin.h"
#include "GManager.h"
//===============================================
// constructor
//===============================================
GLogin::GLogin(QWidget* parent) : GWidget(parent) {
    setObjectName("GLogin");
    
    sGApp* lApp = GManager::Instance()->getData()->app;
    
    QPushButton* lProfil = new QPushButton;
    lProfil->setObjectName("profil");
    lProfil->setIcon(GManager::Instance()->loadPicto(fa::user, lApp->picto_color));
    lProfil->setIconSize(QSize(lApp->profil_size, lApp->profil_size));
    m_widgetId[lProfil] = "profil";
    
    QLabel* lMessage = new QLabel;
    m_message = lMessage;
    lMessage->setObjectName("message");
    lMessage->setAlignment(Qt::AlignCenter);
    m_widgetId[lMessage] = "message";
    
    GWidget* lUsername = GWidget::Create("lineedit");
    m_username = lUsername;
    lUsername->setObjectName("username");
    lUsername->setContent("icon", fa::user, lApp->picto_color);
    m_widgetId[lUsername] = "username";
    
    GWidget* lPassword = GWidget::Create("lineedit");
    m_password = lPassword;
    lPassword->setObjectName("password");
    lPassword->setContent("icon", fa::key, lApp->picto_color);
    lPassword->setOption(QLineEdit::Password);
    m_widgetId[lPassword] = "password";
        
    QPushButton* lCancel = new QPushButton;
    lCancel->setObjectName("cancel");
    lCancel->setText("AnnulerOk");
    lCancel->setCursor(Qt::PointingHandCursor);
    lCancel->setShortcut(QKeySequence(Qt::Key_Return));
    m_widgetId[lCancel] = "cancel";
        
    QPushButton* lLogin = new QPushButton;
    lLogin->setObjectName("login");
    lLogin->setText("Se Connecter");
    lLogin->setCursor(Qt::PointingHandCursor);
    m_widgetId[lLogin] = "login";
        
    QHBoxLayout* lButtonLayout = new QHBoxLayout;
    lButtonLayout->addWidget(lLogin);
    lButtonLayout->addWidget(lCancel);
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
    lContentLayout->addWidget(lMessage);
    lContentLayout->addWidget(lUsername);
    lContentLayout->addWidget(lPassword);
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
    connect(lPassword, SIGNAL(emitItemClick()), this, SLOT(slotItemClick()));
    connect(lLogin, SIGNAL(clicked()), this, SLOT(slotItemClick()));
    connect(lCancel, SIGNAL(clicked()), this, SLOT(slotItemClick()));
}
//===============================================
GLogin::~GLogin() {

}
//===============================================
// method
//===============================================
void GLogin::reset() {
    m_message->setText("");
    m_username->setContent("goto", QIcon());
    m_password->setContent("goto", QIcon());
}
//===============================================
// slot
//===============================================
void GLogin::slotItemClick() {
    QWidget* lWidget = qobject_cast<QWidget*>(sender());
    QString lWidgetId = m_widgetId[lWidget];
    if(lWidgetId == "cancel") {
        GManager::Instance()->setPage("home");
        return;
    }
    reset();
    QString lUsername; m_username->getData(lUsername);
    QString lPassword; m_password->getData(lPassword);
    if(lUsername == "") {
        m_message->setText("Le nom d'utilisateur est obligatoire");
        m_username->setContent("goto", fa::times, "red");
        return;
    }
    if(lPassword == "") {
        m_message->setText("Le mot de passe est obligatoire");
        m_password->setContent("goto", fa::times, "red");
        return;
    }
    QString lLogin = lUsername + "|" + lPassword;
    qDebug() << GManager::Instance()->getCrypto(lLogin);
}
//===============================================
