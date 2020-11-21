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
    
    GWidget* lTitleBar = GWidget::Create("titlebar");
    GWidget* lAddressBar = GWidget::Create("addressbar");
    GWidget* lAddressKey = GWidget::Create("addresskey");
    
    QStackedWidget* lWorkspace = new QStackedWidget;
    lApp->page_map = lWorkspace;
    
    addContent(GWidget::Create("home"), "home", 0);
    addContent(GWidget::Create("builder"), "home/builder", 1);
    
    QVBoxLayout* lMainLatout = new QVBoxLayout;
    lMainLatout->addWidget(lTitleBar, 0);
    lMainLatout->addWidget(lAddressBar, 0);
    lMainLatout->addWidget(lAddressKey, 0);
    lMainLatout->addWidget(lWorkspace, 1);
    
    setLayout(lMainLatout);
    
    setWindowTitle(lApp->app_name);
    resize(lApp->win_width, lApp->win_height);
}
//===============================================
GWindow::~GWindow() {
    
}
//===============================================
// methods
//===============================================
void GWindow::addContent(QWidget* widget, QString key, bool isDefault) {
    sGApp* lApp = GManager::Instance()->getData()->app;
    int lWidgetId = lApp->page_map->count();
    lApp->page_id[key] = lWidgetId;
    lApp->page_map->addWidget(widget);
    if(isDefault == 1) {
        lApp->page_map->setCurrentIndex(lWidgetId);
    }
}
//===============================================
