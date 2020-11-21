//===============================================
#ifndef _GAddressBar_
#define _GAddressBar_
//===============================================
#include "GInclude.h"
#include "GWidget.h"
//===============================================
class GAddressBar : public GWidget {    
    Q_OBJECT

public:
    GAddressBar(QWidget* parent = 0);
    ~GAddressBar();
};
//===============================================
#endif
//===============================================