//===============================================
#include "GProcess.h"
#include "GSQLite.h"
//===============================================
int main(int argc, char** argv) {
    GSQLite::Instance();
    GProcess::Instance()->run(argc, argv);
    return 0;
}
//===============================================

