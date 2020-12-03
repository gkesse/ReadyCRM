//===============================================
#ifndef _GBuilder_
#define _GBuilder_
//===============================================
#include "GInclude.h"
#include "GWidget.h"
//===============================================
class GBuilder : public GWidget {    
    Q_OBJECT

public:
    GBuilder(QWidget* parent = 0);
    ~GBuilder();
    
public slots:
    void slotItemClick();
    
private:
    QTableWidget* m_listWidget;
};
//===============================================
#endif
//===============================================