//===============================================
#include "GListBox.h"
#include "GManager.h"
//===============================================
GListBox::GListBox(QWidget* parent) : GWidget(parent) {
    setObjectName("GListBox");
    
    QVBoxLayout* lScrollLayout = new QVBoxLayout;
    m_scrollLayout = lScrollLayout;
    lScrollLayout->setAlignment(Qt::AlignTop);
    lScrollLayout->setMargin(0);
    lScrollLayout->setSpacing(0);

    QFrame* lScrollWidget = new QFrame;
    lScrollWidget->setLayout(lScrollLayout);

    QScrollArea* lScrollArea = new QScrollArea;
    lScrollArea->setWidget(lScrollWidget);
    lScrollArea->setWidgetResizable(true);

    QVBoxLayout* lMainLayout = new QVBoxLayout;
    lMainLayout->addWidget(lScrollArea);
    lMainLayout->setAlignment(Qt::AlignTop);
    lMainLayout->setMargin(0);
    lMainLayout->setSpacing(0);

    setLayout(lMainLayout);
}
//===============================================
GListBox::~GListBox() {
    
}
//===============================================
void GListBox::addItem(QString key, QString text) {
    QPushButton* lButton = new QPushButton;
    lButton->setObjectName("item");
    lButton->setText(text);
    lButton->setCursor(Qt::PointingHandCursor);
    m_scrollLayout->addWidget(lButton);
    m_widgetId[lButton] = key;
    connect(lButton, SIGNAL(clicked()), this, SLOT(slotItemClick()));
}
//===============================================
void GListBox::addItem(QString key, QString text, QIcon icon) {
    QPushButton* lButton = new QPushButton;
    lButton->setObjectName("item");
    lButton->setText(text);
    lButton->setIcon(icon);
    lButton->setCursor(Qt::PointingHandCursor);
    m_scrollLayout->addWidget(lButton);
    m_widgetId[lButton] = key;
    connect(lButton, SIGNAL(clicked()), this, SLOT(slotItemClick()));
}
//===============================================
void GListBox::addItem(QString key, QString text, QIcon icon, int width, int height) {
    QPushButton* lButton = new QPushButton;
    lButton->setObjectName("item");
    lButton->setText(text);
    lButton->setIcon(icon);
    lButton->setIconSize(QSize(width, height));
    lButton->setCursor(Qt::PointingHandCursor);
    m_scrollLayout->addWidget(lButton);
    m_widgetId[lButton] = key;
    connect(lButton, SIGNAL(clicked()), this, SLOT(slotItemClick()));
}
//===============================================
void GListBox::slotItemClick() {
    sGApp* lApp = GManager::Instance()->getData()->app;
    QWidget* lWidget = qobject_cast<QWidget*>(sender());
    lApp->widget_id = m_widgetId[lWidget];
    emit emitItemClick();
}
//===============================================