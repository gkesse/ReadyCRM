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
    void createTables();
    void queryShow(QString sqlQuery);
    void queryWrite(QString sqlQuery);

private:
    static GSQLite* m_instance;
};
//===============================================
#endif
//===============================================