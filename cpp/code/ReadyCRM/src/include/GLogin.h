//===============================================
#ifndef _GLogin_
#define _GLogin_
//===============================================
#include "GInclude.h"
#include "GWidget.h"
//===============================================
class GLogin : public GWidget {    
    Q_OBJECT

public:
    GLogin(QWidget* parent = 0);
    ~GLogin();
    
public slots:
    void slotItemClick();

private:
    QMap<QWidget*, QString> m_widgetId;
};
//===============================================
#endif
//===============================================