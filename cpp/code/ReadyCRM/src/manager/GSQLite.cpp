//===============================================
#include "GSQLite.h"
#include "GManager.h"
//===============================================
GSQLite* GSQLite::m_instance = 0;
//===============================================
GSQLite::GSQLite() {
    open();
    createTables();
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
    QSqlDatabase lDb = QSqlDatabase::addDatabase("QSQLITE");
    lDb.setDatabaseName(lApp->sqlite_db_path);
    bool lOk = lDb.open();
    if(lOk == false) {
        qDebug() << "[error] GSQLite::open()";
        qDebug() << "[error] " << lApp->sqlite_db_path;
        qDebug() << "[error] " << lDb.lastError();
    }
}
//===============================================
void GSQLite::createTables() {
    sGApp* lApp = GManager::Instance()->getData()->app;
    QString lQuery;
    // config_data
    lQuery = "\
    create table if not exists config_data (\n\
        config_key text unique not null,\n\
        config_value text\n\
    )\n\
    ";
    queryWrite(lQuery);
    // users
    lQuery = "\
    create table if not exists users (\n\
        username text unique not null,\n\
        password text,\n\
        active text default 'on',\n\
        groups text default 'user',\n\
        date_create datetime default current_timestamp,\n\
        date_update datetime default current_timestamp\n\
    )\n\
    ";
    queryWrite(lQuery);
    // root
    lQuery = QString("\
    insert into users (username, password) \
    values ('%1', '%2') \
    ").arg(lApp->root_user).arg(lApp->root_pass);
    queryWrite(lQuery);
}
//===============================================
void GSQLite::queryShow(QString sqlQuery) {
    QSqlQuery lSqlQuery;
    bool lOk = lSqlQuery.exec(sqlQuery);
    if(lOk == false) {
        qDebug() << "[error] GSQLite::queryShow()";
        qDebug() << "[error] " << lSqlQuery.lastError();
    }
    int lCount = lSqlQuery.record().count();
    int lWidth = 20;
    //
    printf("+-");
    for(int i = 0; i < lCount; i++) {
        if(i != 0) printf("-+-");
        for(int j = 0; j < lWidth; j++) {
            printf("-");
        }
    }
    printf("-+");
    printf("\n");
    //
    printf("| ");
    for(int i = 0; i < lCount; i++) {
        if(i != 0) printf(" | ");
        const char* lField = lSqlQuery.record().field(i).name().toStdString().c_str();
        printf("%*s", -lWidth, lField);
    }
    printf(" |");
    printf("\n");
    //
    printf("+-");
    for(int i = 0; i < lCount; i++) {
        if(i != 0) printf("-+-");
        for(int j = 0; j < lWidth; j++) {
            printf("-");
        }
    }
    printf("-+");
    printf("\n");
    //
    while(lSqlQuery.next()) {
        printf("| ");
        for(int i = 0; i < lCount; i++) {
            if(i != 0) printf(" | ");
            const char* lValue = lSqlQuery.value(i).toString().toStdString().c_str();
            printf("%*s", -lWidth, lValue);
        }
        printf(" |");
        printf("\n");
    }
    //
    printf("+-");
    for(int i = 0; i < lCount; i++) {
        if(i != 0) printf("-+-");
        for(int j = 0; j < lWidth; j++) {
            printf("-");
        }
    }
    printf("-+");
    printf("\n");
}
//===============================================
void GSQLite::queryWrite(QString sqlQuery) {
    QSqlQuery lSqlQuery;
    bool lOk = lSqlQuery.exec(sqlQuery);
    if(lOk == false) {
        qDebug() << "[error] GSQLite::queryWrite()";
        qDebug() << "[error] " << lSqlQuery.lastError();
    }
}
//===============================================
QString GSQLite::queryValue(QString sqlQuery) {
    QSqlQuery lSqlQuery;
    bool lOk = lSqlQuery.exec(sqlQuery);
    if(lOk == false) {
        qDebug() << "[error] GSQLite::queryValue()";
        qDebug() << "[error] " << lSqlQuery.lastError();
    }
    QString lValue = "";
    while(lSqlQuery.next()) {
        lValue = lSqlQuery.value(0).toString();
        break;
    }
    return lValue;
}
//===============================================
QVector<QString> GSQLite::queryCol(QString sqlQuery) {
    QSqlQuery lSqlQuery;
    bool lOk = lSqlQuery.exec(sqlQuery);
    if(lOk == false) {
        qDebug() << "[error] GSQLite::queryValue()";
        qDebug() << "[error] " << lSqlQuery.lastError();
    }
    QVector<QString> lDataMap;
    while(lSqlQuery.next()) {
        QString lValue = lSqlQuery.value(0).toString();
        lDataMap.push_back(lValue);
    }
    return lDataMap;
}
//===============================================
QVector<QString> GSQLite::queryRow(QString sqlQuery) {
    QSqlQuery lSqlQuery;
    bool lOk = lSqlQuery.exec(sqlQuery);
    if(lOk == false) {
        qDebug() << "[error] GSQLite::queryValue()";
        qDebug() << "[error] " << lSqlQuery.lastError();
    }
    int lCount = lSqlQuery.record().count();
    QVector<QString> lDataMap;
    while(lSqlQuery.next()) {
        for(int i = 0; i < lCount; i++) {
            QString lValue = lSqlQuery.value(i).toString();
            lDataMap.push_back(lValue);
        }
        break;
    }
    return lDataMap;
}
//===============================================
QVector<QVector<QString>> GSQLite::queryMap(QString sqlQuery) {
    QSqlQuery lSqlQuery;
    bool lOk = lSqlQuery.exec(sqlQuery);
    if(lOk == false) {
        qDebug() << "[error] GSQLite::queryValue()";
        qDebug() << "[error] " << lSqlQuery.lastError();
    }
    int lCount = lSqlQuery.record().count();
    QVector<QVector<QString>> lDataMap;
    while(lSqlQuery.next()) {
        QVector<QString> lData;
        for(int i = 0; i < lCount; i++) {
            QString lValue = lSqlQuery.value(i).toString();
            lData.push_back(lValue);
        }
        lDataMap.push_back(lData);
    }
    return lDataMap;
}
//===============================================
