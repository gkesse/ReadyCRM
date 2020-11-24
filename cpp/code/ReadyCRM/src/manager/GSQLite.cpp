//===============================================
#include "GSQLite.h"
#include "GManager.h"
//===============================================
GSQLite* GSQLite::m_instance = 0;
//===============================================
GSQLite::GSQLite() {

}
//===============================================
GSQLite::~GSQLite() {
    
}
//===============================================
GSQLite* GSQLite::Instance() {
    if(m_instance == 0) {
        m_instance = new GSQLite;
    }
    return m_instance;
}
//===============================================
void GSQLite::open() {
    sGApp* lApp = GManager::Instance()->getData()->app;
    QSqlDatabase lDb = QSqlDatabase::addDatabase("SQLITE");
    lDb.setDatabaseName(lApp->sqlite_db_path);
    int lOk = lDb.open();
    if(lOk == false) {
        qDebug() << "[error] echec de l'ouverture de la base de données";
        qDebug() << "[error] " << lApp->sqlite_db_path;
        qDebug() << "[error] " << lDb.lastError();
    }
}
//===============================================
