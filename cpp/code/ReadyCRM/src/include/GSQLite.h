//===============================================
#ifndef _GSQLite_
#define _GSQLite_
//===============================================
#include "GInclude.h"
//===============================================
class GSQLite {
private:
    GSQLite();
    
public:
    ~GSQLite();
    static GSQLite* Instance();
    void open();

private:
    static GSQLite* m_instance;
};
//===============================================
#endif
//===============================================