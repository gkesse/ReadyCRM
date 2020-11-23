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
void GLineEdit::setContent(int icon1, int icon2) {
    sGApp* lApp = GManager::Instance()->getData()->app;
    m_icon->setIcon(GManager::Instance()->loadPicto(icon1, lApp->picto_color));
    m_goto->setIcon(GManager::Instance()->loadPicto(icon2, lApp->picto_color));
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
