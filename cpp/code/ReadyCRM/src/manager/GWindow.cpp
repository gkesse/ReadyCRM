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
    m_widgetId[lTitleBar] = "titlebar";
    
    GWidget* lAddressBar = GWidget::Create("addressbar");
    GWidget* lAddressKey = GWidget::Create("addresskey");
    
    QStackedWidget* lWorkspace = new QStackedWidget;
    lApp->page_map = lWorkspace;
    
    addPage("home", GWidget::Create("home"), 1);
    addPage("home/builder", GWidget::Create("builder"), 0);
    
    QVBoxLayout* lMainLatout = new QVBoxLayout;
    lMainLatout->addWidget(lTitleBar);
    lMainLatout->addWidget(lAddressBar);
    lMainLatout->addWidget(lAddressKey);
    lMainLatout->addWidget(lWorkspace, 1);
    
    setLayout(lMainLatout);
    
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    setWindowTitle(lApp->app_name);
    setWindowIcon(QIcon(lApp->img_map["logo"]));
    resize(lApp->win_width, lApp->win_height);
    
    connect(lTitleBar, SIGNAL(emitItemClick()), this, SLOT(slotItemClick()));
    connect(this, SIGNAL(emitItemClick()), lTitleBar, SLOT(slotItemUpdate()));
}
//===============================================
GWindow::~GWindow() {
    
}
//===============================================
// methods
//===============================================
void GWindow::addPage(QString key, QWidget* widget, bool isDefault) {
    sGApp* lApp = GManager::Instance()->getData()->app;
    int lWidgetId = lApp->page_map->count();
    lApp->page_id[key] = lWidgetId;
    lApp->page_map->addWidget(widget);
    if(isDefault == 1) {
        lApp->page_map->setCurrentIndex(lWidgetId);
    }
}
//===============================================
// slot
//===============================================
void GWindow::slotItemClick() {
    sGApp* lApp = GManager::Instance()->getData()->app;
    QWidget* lWidget = qobject_cast<QWidget*>(sender());
    QString lWidgetId = m_widgetId[lWidget];
    if(lWidgetId == "titlebar") {
        if(lApp->widget_id == "fullscreen") {
            if(windowState() != Qt::WindowFullScreen) {
                showFullScreen();
            }
            else {
                showNormal();
            }
        }
        else if(lApp->widget_id == "minimize") {
            showMinimized();
        }
        else if(lApp->widget_id == "maximize") {
            if(windowState() != Qt::WindowMaximized) {
                showMaximized();
            }
            else {
                showNormal();
            }
        }
        else if(lApp->widget_id == "close") {
            close();
        }
    }
    lApp->win_state = windowState();
    emit emitItemClick();
}
//===============================================
