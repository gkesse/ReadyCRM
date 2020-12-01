//===============================================
#include "GLineEdit.h"
#include "GManager.h"
//===============================================
GLineEdit::GLineEdit(QWidget* parent) : GWidget(parent) {
    setObjectName("GLineEdit");
        
    QPushButton* lIcon = new QPushButton;
    m_icon = lIcon;
    lIcon->setObjectName("icon");
    lIcon->setCursor(Qt::PointingHandCursor);
    m_widgetId[lIcon] = "icon";
    
    QLineEdit* lEdit = new QLineEdit;
    m_edit = lEdit;
    lEdit->setObjectName("edit");
    m_widgetId[lEdit] = "edit";
    
    QPushButton* lGoTo = new QPushButton;
    m_goto = lGoTo;
    lGoTo->setObjectName("goto");
    lGoTo->setCursor(Qt::PointingHandCursor);
    m_widgetId[lGoTo] = "goto";
        
    QHBoxLayout* lMainLayout = new QHBoxLayout;
    lMainLayout->addWidget(lIcon);
    lMainLayout->addWidget(lEdit, 1);
    lMainLayout->addWidget(lGoTo);
    lMainLayout->setMargin(0);
    lMainLayout->setSpacing(5);

    setLayout(lMainLayout);
    
    connect(lIcon, SIGNAL(clicked()), this, SLOT(slotItemClick()));
    connect(lEdit, SIGNAL(returnPressed()), this, SLOT(slotItemClick()));
    connect(lGoTo, SIGNAL(clicked()), this, SLOT(slotItemClick()));
}
//===============================================
GLineEdit::~GLineEdit() {
    
}
//===============================================
// method
//===============================================
void GLineEdit::setContent(QString text) {
    m_edit->setText(text);
}
//===============================================
void GLineEdit::setContent(QString key, int icon, QColor color) {
    QPushButton* lButton = 0;
    if(key == "icon") lButton = m_icon;
    else if(key == "goto") lButton = m_goto;
    if(lButton == 0) return;
    lButton->setIcon(GManager::Instance()->loadPicto(icon, color));
}
//===============================================
void GLineEdit::setContent(QString key, QIcon icon) {
    QPushButton* lButton = 0;
    if(key == "icon") lButton = m_icon;
    else if(key == "goto") lButton = m_goto;
    if(lButton == 0) return;
    lButton->setIcon(icon);
}
//===============================================
void GLineEdit::setOption(int mode) {
    m_edit->setEchoMode((QLineEdit::EchoMode)mode);
}
//===============================================
void GLineEdit::getData(QString& data) {
    data = m_edit->text();
}
//===============================================
// slot
//===============================================
void GLineEdit::slotItemClick() {
    sGApp* lApp = GManager::Instance()->getData()->app;
    QWidget* lWidget = qobject_cast<QWidget*>(sender());
    lApp->widget_id = m_widgetId[lWidget];
    emit emitItemClick();
}
//===============================================
