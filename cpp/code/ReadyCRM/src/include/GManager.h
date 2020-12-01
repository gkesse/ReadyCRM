//===============================================
#ifndef _GManager_
#define _GManager_
//===============================================
#include "GInclude.h"
#include "GWidget.h"
//===============================================
// struct
//===============================================
typedef struct _sGManager sGManager;
typedef struct _sGApp sGApp;
//===============================================
// manager
//===============================================
class GManager : public QObject {
    Q_OBJECT
    
private:
    GManager(QObject* parent = 0);
    
public:
    ~GManager();
    static GManager* Instance(QObject* parent = 0);
    sGManager* getData();
    // style
    void loadStyle();
    // picto
    QIcon loadPicto(int picto, QColor color);
    // font
    void loadFont();
    // img
    void loadImg();
    // page
    void setPage(QString address);
    // layout
    void clearLayout(QLayout *layout);
    // crypto
    QString getCrypto(QString text);
    // message
    int showQuestion(QString text);
    int showInfo(QString text);
    // login
    int isLogin();
    // table
    QVector<QString> getTables();
    int countTableData(QString table);
    // config_data
    void saveData(QString key, QString value);
    QString loadData(QString key);
    int countData(QString key);
    void updateData(QString key, QString value);
    void insertData(QString key, QString value);
    // users
    int countUser(QString username);
    int countUser(QString username, QString password);
    void addUser(QString username, QString password);
    QVector<QVector<QString>> getUser();
    void deleteUser(QString username);

private:
    static GManager* m_instance;
    sGManager* mgr;
    QtAwesome* m_QtAwesome;
};
//===============================================
// struct
//===============================================
struct _sGManager {
    sGApp* app;
};
//===============================================
struct _sGApp {
    // app
    QString app_name;
    // style
    QString style_path;
    // win
    GWidget* win;
    int win_width;
    int win_height;
    // page
    QStackedWidget* page_map;
    QMap<QString, int> page_id;
    // widget
    QWidget* widget;
    QString widget_id;
    // font
    QString font_path;
    // img
    QString img_path;
    QMap<QString, QString> img_map;
    // picto
    QColor picto_color;
    // address
    QLineEdit* address;
    QString address_url;
    GWidget* address_key;
    // title
    QLabel* title;
    QMap<QString, QString> title_map;
    // profil
    int profil_size;
    // grip
    int grip_size;
    // login
    QString login_on;
    QPushButton* login_titlebar;
    QPushButton* login_home;
    // nok
    QColor nok_color;
    // sqlite
    QString sqlite_db_path;
};
//===============================================
#endif
//===============================================