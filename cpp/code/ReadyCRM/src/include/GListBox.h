//===============================================
#ifndef _GListBox_
#define _GListBox_
//===============================================
#include "GInclude.h"
#include "GWidget.h"
//===============================================
class GListBox : public GWidget {    
    Q_OBJECT

public:
    GListBox(QWidget* parent = 0);
    ~GListBox();

public:
    void addItem(QString key, QString text);
    void addItem(QString key, QString text, QIcon icon);
    void addItem(QString key, QString text, QIcon icon, int width, int height);
    
public slots:
    void slotItemClick();
    
private:
    QVBoxLayout* m_scrollLayout;
    QMap<QWidget*, QString> m_widgetId;
};
//===============================================
#endif
//===============================================