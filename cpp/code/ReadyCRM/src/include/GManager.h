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
};
//===============================================
#endif
//===============================================