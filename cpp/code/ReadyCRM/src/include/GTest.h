//===============================================
#ifndef _GTest_
#define _GTest_
//===============================================
#include "GInclude.h"
//===============================================
class GTest {
private:
    GTest();
    
public:
    ~GTest();
    static GTest* Instance();
    void run(int argc, char** argv);
    void runDefault(int argc, char** argv);

private:
    static GTest* m_instance;
};
//===============================================
#endif
//===============================================