//===============================================
#ifndef _GWidget_
#define _GWidget_
//===============================================
#include "GInclude.h"
//===============================================
class GWidget : public QFrame {
    Q_OBJECT
    
public:
    GWidget(QWidget* parent = 0);
    ~GWidget();
    static GWidget* Create(QString key, QWidget* parent = 0);

public:
    virtual void addContent(QWidget* widget, QString key, bool isDefault);
};
//===============================================
#endif
//===============================================