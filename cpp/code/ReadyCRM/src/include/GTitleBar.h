//===============================================
#ifndef _GTitleBar_
#define _GTitleBar_
//===============================================
#include "GInclude.h"
#include "GWidget.h"
//===============================================
class GTitleBar : public GWidget {    
    Q_OBJECT

public:
    GTitleBar(QWidget* parent = 0);
    ~GTitleBar();
};
//===============================================
#endif
//===============================================