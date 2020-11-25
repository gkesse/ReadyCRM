//===============================================
#include "GWindow.h"
#include "GWidget.h"
#include "GManager.h"
//===============================================
// constructor
//===============================================
GWindow::GWindow(QWidget* parent) : GWidget(parent) {
    setObjectName("GWindow");
    
    sGApp* lApp = GManager::Instance()->getData()->app;
    
    lApp->win = this;

    GWidget* lTitleBar = GWidget::Create("titlebar");
    m_widgetId[lTitleBar] = "titlebar";
    
    GWidget* lAddressBar = GWidget::Create("addressbar");
    
    GWidget* lAddressKey = GWidget::Create("addresskey");
    lApp->address_key = lAddressKey;
    
    QStackedWidget* lWorkspace = new QStackedWidget;
    lApp->page_map = lWorkspace;
    
    addPage("home", "Accueil", GWidget::Create("home"), 1);
    addPage("home/login", "Connexion", GWidget::Create("login"), 1);
    addPage("home/user/add", "Ajout d'un utilisateur", GWidget::Create("useradd"), 1);
    addPage("home/sqlite/tables", "Liste des tables", GWidget::Create("sqlitetables"), 1);
    addPage("home/builder", "Builder", GWidget::Create("builder"), 0);
        
    QVBoxLayout* lMainLayout = new QVBoxLayout;
    lMainLayout->addWidget(lTitleBar);
    lMainLayout->addWidget(lAddressBar);
    lMainLayout->addWidget(lAddressKey);
    lMainLayout->addWidget(lWorkspace, 1);
    lMainLayout->setMargin(10);
    lMainLayout->setSpacing(10);
    
    setLayout(lMainLayout);
    
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    setWindowTitle(lApp->app_name);
    setWindowIcon(QIcon(lApp->img_map["logo"]));
    resize(lApp->win_width, lApp->win_height);

    m_sizeGrip = new QSizeGrip(this);
}
//===============================================
GWindow::~GWindow() {
    
}
//===============================================
// methods
//===============================================
void GWindow::addPage(QString key, QString title, QWidget* widget, bool isDefault) {
    sGApp* lApp = GManager::Instance()->getData()->app;
    int lWidgetId = lApp->page_map->count();
    lApp->page_id[key] = lWidgetId;
    lApp->title_map[key] = title;
    lApp->page_map->addWidget(widget);
    if(isDefault == 1) {
        GManager::Instance()->setPage(key);
    }
}
//===============================================
// callback
//===============================================
void GWindow::resizeEvent(QResizeEvent *event) {
    sGApp* lApp = GManager::Instance()->getData()->app;
    m_sizeGrip->move(width() - lApp->grip_size, height() - lApp->grip_size);
    m_sizeGrip->resize(lApp->grip_size, lApp->grip_size);
}
//===============================================
