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
    void addPage(QString key, QWidget* widget, bool isDefault);
        
private:
    QMap<QWidget*, QString> m_widgetId;
};
//===============================================
#endif
//===============================================