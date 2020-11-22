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
    virtual void addPage(QString key, QWidget* widget, bool isDefault);
    virtual void addItem(QString key, QString text);
    virtual void addItem(QString key, QString text, QIcon icon);
    virtual void addItem(QString key, QString text, QIcon icon, int width, int height);
    virtual void setContent(QString text);
    
public slots:
    virtual void slotItemClick();
    
signals:
    void emitItemClick();
};
//===============================================
#endif
//===============================================