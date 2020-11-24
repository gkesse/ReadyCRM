//===============================================
#ifndef _GManager_
#define _GManager_
//===============================================
#include "GInclude.h"
#include "GWidget.h"
//===============================================
// struct
//===============================================
typedef struct _sGManager sGManager;
typedef struct _sGApp sGApp;
//===============================================
// manager
//===============================================
class GManager {
private:
    GManager();
    
public:
    ~GManager();
    static GManager* Instance();
    // data
    sGManager* getData();
    // style
    void loadStyle();
    // picto
    QIcon loadPicto(int picto, QColor color);
    // font
    void loadFont();
    // img
    void loadImg();
    // page
    void setPage(QString address);
    // layout
    void clearLayout(QLayout *layout);

private:
    static GManager* m_instance;
    sGManager* mgr;
    QtAwesome* m_QtAwesome;
};
//===============================================
// struct
//===============================================
struct _sGManager {
    sGApp* app;
};
//===============================================
struct _sGApp {
    // app
    QString app_name;
    // style
    QString style_path;
    // win
    GWidget* win;
    int win_width;
    int win_height;
    // page
    QStackedWidget* page_map;
    QMap<QString, int> page_id;
    // widget
    QString widget_id;
    // font
    QString font_path;
    // img
    QString img_path;
    QMap<QString, QString> img_map;
    // picto
    QColor picto_color;
    // address
    QLineEdit* address;
    QString address_url;
    GWidget* address_key;
    // title
    QLabel* title;
    QMap<QString, QString> title_map;
    // profil
    int profil_size;
    // grip
    int grip_size;
    // check
    int check_ok;
    int check_nok;
    // ok
    QColor ok_color;
    // nok
    QColor nok_color;
};
//===============================================
#endif
//===============================================