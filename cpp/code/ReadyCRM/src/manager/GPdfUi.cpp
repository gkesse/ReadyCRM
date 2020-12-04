//===============================================
#include "GPdfUi.h"
#include "GWidget.h"
#include "GManager.h"
//===============================================
// constructor
//===============================================
GPdfUi::GPdfUi(QWidget* parent) : GWidget(parent) {
    setObjectName("GPdfUi");
    
    QPushButton* lEdit = new QPushButton;
    lEdit->setObjectName("edit");
    lEdit->setText("Editer");
    lEdit->setCursor(Qt::PointingHandCursor);
    m_widgetId[lEdit] = "edit";
    
    QPushButton* lPreview = new QPushButton;
    lPreview->setObjectName("preview");
    lPreview->setText("Visualiser");
    lPreview->setCursor(Qt::PointingHandCursor);
    m_widgetId[lPreview] = "preview";
    
    QHBoxLayout* lActionLatout = new QHBoxLayout;
    lActionLatout->addWidget(lEdit);
    lActionLatout->addWidget(lPreview);
    lActionLatout->setAlignment(Qt::AlignLeft);
    lActionLatout->setMargin(0);
    lActionLatout->setSpacing(10);

    QTextEdit* lTextEdit = new QTextEdit;
        
    QVBoxLayout* lMainLatout = new QVBoxLayout;
    lMainLatout->addLayout(lActionLatout);
    lMainLatout->addWidget(lTextEdit, 1);
    lMainLatout->setAlignment(Qt::AlignTop);
    lMainLatout->setMargin(0);
    lMainLatout->setSpacing(10);
    
    setLayout(lMainLatout);
}
//===============================================
GPdfUi::~GPdfUi() {
    
}
//===============================================
