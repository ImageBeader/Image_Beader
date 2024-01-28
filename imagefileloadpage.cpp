#include "imagefileloadpage.h"

#include <QVBoxLayout>
#include <QHBoxLayout>

#include <QPushButton>

#include<QDebug>
#include<QFileDialog>

ImageFileLoadPage::ImageFileLoadPage(QWidget *parent) : QWizardPage(parent) {

    this->setTitle(tr("Load Image File"));
    this->setLayout(new QVBoxLayout());

    //File browser
    QWidget *file_load_w = new QWidget();
    file_load_w->setLayout(new QHBoxLayout);
    this->layout()->addWidget(file_load_w);

    this->filename_line = new QLineEdit();
    this->filename_line->connect(this->filename_line,&QLineEdit::returnPressed, this, &ImageFileLoadPage::onInputFile);
    file_load_w->layout()->addWidget(this->filename_line);

    QPushButton *file_browse_btn = new QPushButton(tr("Browse"));
    this->connect(file_browse_btn,&QPushButton::clicked,this,&ImageFileLoadPage::onBrowseFile);
    file_load_w->layout()->addWidget(file_browse_btn);

    this->image_preview = new QGraphicsView();
    this->layout()->addWidget(this->image_preview);
}

void ImageFileLoadPage::onBrowseFile() {
    QString filename = QFileDialog::getOpenFileName(this
                                                   ,tr("Open Image File")
                                                   ,"/home"
                                                   ,tr("Image Files (*.png *.jpg *.bmp)"));

    if (!filename.isNull()){
        this->image_filepath = filename;
        this->filename_line->setText(filename);
        this->loadPreview();
    }
}

void ImageFileLoadPage::onInputFile() {
    QFile f = QFile(this->filename_line->text());

    if (f.exists()) {
        this->image_filepath = this->filename_line->text();
        this->loadPreview();
    } else{
        qDebug() << "Invalid file";
    }
}

void ImageFileLoadPage::loadPreview() {
    qDebug() << "load preview";
}
