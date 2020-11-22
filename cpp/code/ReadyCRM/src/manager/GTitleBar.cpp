//===============================================
#include "GTitleBar.h"
#include "GManager.h"
//===============================================
GTitleBar::GTitleBar(QWidget* parent) : GWidget(parent) {
    setObjectName("GTitleBar");
    
    sGApp* lApp = GManager::Instance()->getData()->app;
    
    QPushButton* lLogo = new QPushButton;
    lLogo->setObjectName("logo");
    lLogo->setIcon(QIcon(lApp->img_map["logo"]));
    lLogo->setCursor(Qt::PointingHandCursor);
    m_widgetId[lLogo] = "logo";
    
    QLabel* lAppName = new QLabel;
    lAppName->setObjectName("app_name");
    lAppName->setText(lApp->app_name);
    
    QLabel* lTitle = new QLabel;
    lTitle->setObjectName("title");
    lTitle->setText("Acceuil");
    lTitle->setAlignment(Qt::AlignCenter);
    
    QPushButton* lFullscreen = new QPushButton;
    m_fullscreen = lFullscreen;
    lFullscreen->setObjectName("fullscreen");
    lFullscreen->setIcon(QIcon(lApp->img_map["fullscreen"]));
    lFullscreen->setCursor(Qt::PointingHandCursor);
    m_widgetId[lFullscreen] = "fullscreen";

    QPushButton* lMinimize = new QPushButton;
    lMinimize->setObjectName("minimize");
    lMinimize->setIcon(GManager::Instance()->loadPicto(fa::windowminimize, lApp->picto_color));
    lMinimize->setCursor(Qt::PointingHandCursor);
    m_widgetId[lMinimize] = "minimize";

    QPushButton* lMaximize = new QPushButton;
    m_maximize = lMaximize;
    lMaximize->setObjectName("maximize");
    lMaximize->setIcon(GManager::Instance()->loadPicto(fa::windowmaximize, lApp->picto_color));
    lMaximize->setCursor(Qt::PointingHandCursor);
    m_widgetId[lMaximize] = "maximize";
    
    QPushButton* lClose = new QPushButton;
    lClose->setObjectName("close");
    lClose->setIcon(GManager::Instance()->loadPicto(fa::times, lApp->picto_color));
    lClose->setCursor(Qt::PointingHandCursor);
    m_widgetId[lClose] = "close";
    
    QHBoxLayout* lMainLayout = new QHBoxLayout;
    lMainLayout->addWidget(lLogo);
    lMainLayout->addWidget(lAppName);
    lMainLayout->addWidget(lTitle, 1);
    lMainLayout->addWidget(lFullscreen);
    lMainLayout->addWidget(lMinimize);
    lMainLayout->addWidget(lMaximize);
    lMainLayout->addWidget(lClose);
    lMainLayout->setMargin(0);
    lMainLayout->setSpacing(2);

    setLayout(lMainLayout);
    
    connect(lLogo, SIGNAL(clicked()), this, SLOT(slotItemClick()));
    connect(lFullscreen, SIGNAL(clicked()), this, SLOT(slotItemClick()));
    connect(lMinimize, SIGNAL(clicked()), this, SLOT(slotItemClick()));
    connect(lMaximize, SIGNAL(clicked()), this, SLOT(slotItemClick()));
    connect(lClose, SIGNAL(clicked()), this, SLOT(slotItemClick()));
}
//===============================================
GTitleBar::~GTitleBar() {
    
}
//===============================================
// slot
//===============================================
void GTitleBar::slotItemClick() {
    sGApp* lApp = GManager::Instance()->getData()->app;
    QWidget* lWidget = qobject_cast<QWidget*>(sender());
    lApp->widget_id = m_widgetId[lWidget];
    emit emitItemClick();
}
//===============================================
void GTitleBar::slotItemUpdate() {
    sGApp* lApp = GManager::Instance()->getData()->app;
    if(lApp->widget_id == "maximize") {
        if(lApp->win_state != Qt::WindowMaximized) {
            m_maximize->setIcon(GManager::Instance()->loadPicto(fa::windowmaximize, lApp->picto_color));
        }
        else {
            m_maximize->setIcon(GManager::Instance()->loadPicto(fa::windowrestore, lApp->picto_color));
        }
    }
    else if(lApp->widget_id == "fullscreen") {
        if(lApp->win_state != Qt::WindowFullScreen) {
            m_fullscreen->setIcon(QIcon(lApp->img_map["fullscreen"]));
        }
        else {
            m_fullscreen->setIcon(QIcon(lApp->img_map["fullscreen_exit"]));
        }
    }
}
//===============================================
