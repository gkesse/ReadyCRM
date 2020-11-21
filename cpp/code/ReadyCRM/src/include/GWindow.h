//===============================================
#ifndef _GWindow_
#define _GWindow_
//===============================================
#include "GInclude.h"
#include "GWidget.h"
//===============================================
class GWindow : public GWidget {    
    Q_OBJECT

public:
    GWindow(QWidget* parent = 0);
    ~GWindow();

public:
    void addContent(QWidget* widget, QString key, bool isDefault);
};
//===============================================
#endif
//===============================================