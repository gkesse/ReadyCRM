//===============================================
#include "GProcess.h"
#include "GTest.h"
#include "GQt.h"
//===============================================
GProcess* GProcess::m_instance = 0;
//===============================================
GProcess::GProcess() {

}
//===============================================
GProcess::~GProcess() {
    
}
//===============================================
GProcess* GProcess::Instance() {
    if(m_instance == 0) {
        m_instance = new GProcess;
    }
    return m_instance;
}
//===============================================
void GProcess::run(int argc, char** argv) {
    QString lKey = "";
    if(argc > 1) lKey = argv[1];
    if(lKey == "test") {runTest(argc, argv); return;}
    if(lKey == "gui") {runGui(argc, argv); return;}
    runTest(argc, argv);
}
//===============================================
void GProcess::runTest(int argc, char** argv) {
    GTest::Instance()->run(argc, argv);
}
//===============================================
void GProcess::runGui(int argc, char** argv) {
    GQt::Instance()->run(argc, argv);
}
//===============================================
