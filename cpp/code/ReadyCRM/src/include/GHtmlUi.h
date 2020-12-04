//===============================================
#ifndef _GHtmlUi_
#define _GHtmlUi_
//===============================================
#include "GInclude.h"
#include "GWidget.h"
//===============================================
class GHtmlUi : public GWidget {    
    Q_OBJECT

public:
    GHtmlUi(QWidget* parent = 0);
    ~GHtmlUi();
};
//===============================================
#endif
//===============================================