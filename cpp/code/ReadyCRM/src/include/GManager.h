//===============================================
#ifndef _GManager_
#define _GManager_
//===============================================
#include "GInclude.h"
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
    // qt_style
    void loadStyle();

private:
    static GManager* m_instance;
    sGManager* mgr;
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
    int win_width;
    int win_height;
    // page
    QStackedWidget* page_map;
    QMap<QString, int> page_id;
};
//===============================================
#endif
//===============================================