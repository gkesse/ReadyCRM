//===============================================
#include "GManager.h"
//===============================================
GManager* GManager::m_instance = 0;
//===============================================
// constructor
//===============================================
GManager::GManager() {
    // manager
    mgr = new sGManager;
    // app
    mgr->app = new sGApp;
    mgr->app->app_name = "ReadyApp";
    mgr->app->style_path = "data/css/style.css";
    mgr->app->win_width = 640;
    mgr->app->win_height = 480;
    mgr->app->font_path = "data/font";
    mgr->app->img_path = "data/img";
    mgr->app->picto_color = "white";
    mgr->app->address_url = "";   
    mgr->app->profil_size = 150;
    mgr->app->grip_size = 16;
    mgr->app->check_ok = fa::check;
    mgr->app->check_nok = fa::times;
    mgr->app->ok_color = "lime";
    mgr->app->nok_color = "red";
    mgr->app->login_on = "off";
    // picto
    m_QtAwesome = new QtAwesome(qApp);
}
//===============================================
GManager::~GManager() {
    
}
//===============================================
GManager* GManager::Instance() {
    if(m_instance == 0) {
        m_instance = new GManager;
    }
    return m_instance;
}
//===============================================
// data
//===============================================
sGManager* GManager::getData() {
    return mgr;
}
//===============================================
// style
//===============================================
void GManager::loadStyle() {
    QFile lFile(mgr->app->style_path);
    lFile.open(QFile::ReadOnly);
    QString lStyleSheet = QLatin1String(lFile.readAll());
    qApp->setStyleSheet(lStyleSheet);
}
//===============================================
// picto
//===============================================
QIcon GManager::loadPicto(int picto, QColor color) {
    m_QtAwesome->initFontAwesome();
    m_QtAwesome->setDefaultOption("color", color);
    m_QtAwesome->setDefaultOption("color-active", color);
    return  m_QtAwesome->icon(picto);
}
//===============================================
// font
//===============================================
void GManager::loadFont()  {
    QDirIterator lDirIterator(mgr->app->font_path, QDir::Files, QDirIterator::NoIteratorFlags);
    while (lDirIterator.hasNext()) {
        QString lFile = lDirIterator.next();
        QFontDatabase::addApplicationFont(lFile);
    }
}
//===============================================
// img
//===============================================
void GManager::loadImg()  {
    QDirIterator lDirIterator(mgr->app->img_path, QDir::Files, QDirIterator::NoIteratorFlags);
    while (lDirIterator.hasNext()) {
        QString lFile = lDirIterator.next();
        QString lKey = QFileInfo(lFile).baseName();
        mgr->app->img_map[lKey] = lFile;
    }
}
//===============================================
// page
//===============================================
void GManager::setPage(QString address)  {
    int lPageId = mgr->app->page_id.value(address, -1);
    if(lPageId == -1) {
        mgr->app->address->setText(mgr->app->address_url);
        return;
    }
    mgr->app->page_map->setCurrentIndex(lPageId);
    mgr->app->address->setText(address);
    mgr->app->address_url = address;
    mgr->app->address_key->setContent(address);
    mgr->app->title->setText(mgr->app->title_map[address]);
}
//===============================================
// layout
//===============================================
void GManager::clearLayout(QLayout *layout) {
    if(layout) {
        while(layout->count() > 0) {
            QLayoutItem* lItem = layout->takeAt(0);
            QWidget* lWidget = lItem->widget();
            if(lWidget) delete lWidget;
            delete lItem;
        }
    }
}
//===============================================
