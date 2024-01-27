#include "imagefileloadpage.h"

#include <QVBoxLayout>
#include <QHBoxLayout>

#include <QPushButton>

#include<QDebug>

ImageFileLoadPage::ImageFileLoadPage(QWidget *parent) : QWizardPage(parent) {

    this->setTitle(tr("Load Image File"));
    this->setLayout(new QVBoxLayout());

    //File browser
    this->filename_line = new QLineEdit();
    this->layout()->addWidget(this->filename_line);

    QPushButton *file_browse_btn = new QPushButton(tr("Browse"));
    this->connect(file_browse_btn,&QPushButton::clicked,this,&ImageFileLoadPage::browseFile);
    this->layout()->addWidget(file_browse_btn);

    this->image_preview = new QGraphicsView();
    this->layout()->addWidget(this->image_preview);
}

void ImageFileLoadPage::browseFile() {
    qDebug() << "browsing for files";
}
