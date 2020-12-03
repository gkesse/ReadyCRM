//===============================================
#include "GTest.h"
//===============================================
GTest* GTest::m_instance = 0;
//===============================================
GTest::GTest() {

}
//===============================================
GTest::~GTest() {
    
}
//===============================================
GTest* GTest::Instance() {
    if(m_instance == 0) {
        m_instance = new GTest;
    }
    return m_instance;
}
//===============================================
void GTest::run(int argc, char** argv) {
    QString lKey = "";
    if(argc > 2) lKey = argv[2];
    if(lKey == "default") {runDefault(argc, argv); return;}
    runDefault(argc, argv);
}
//===============================================
void GTest::runDefault(int argc, char** argv) {

}
//===============================================
