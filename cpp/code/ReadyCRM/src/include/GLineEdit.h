//===============================================
#ifndef _GLineEdit_
#define _GLineEdit_
//===============================================
#include "GInclude.h"
#include "GWidget.h"
//===============================================
class GLineEdit : public GWidget {    
    Q_OBJECT

public:
    GLineEdit(QWidget* parent = 0);
    ~GLineEdit();

public:
    void setContent(int icon1, int icon2);
    
public slots:
    void slotItemClick();

private:
    QMap<QWidget*, QString> m_widgetId;
    QPushButton* m_icon;
    QPushButton* m_goto;
};
//===============================================
#endif
//===============================================