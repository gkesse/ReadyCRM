//===============================================
#include "GQt.h"
//===============================================
GQt* GQt::m_instance = 0;
//===============================================
GQt::GQt() {

}
//===============================================
GQt::~GQt() {
    
}
//===============================================
GQt* GQt::Instance() {
    if(m_instance == 0) {
        m_instance = new GQt;
    }
    return m_instance;
}
//===============================================
void GQt::run(int argc, char** argv) {
    QString lKey = "";
    if(argc > 1) lKey = argv[1];
    if(lKey == "test") {runTest(argc, argv); return;}
    if(lKey == "gui") {runGui(argc, argv); return;}
    runTest(argc, argv);
}
//===============================================
