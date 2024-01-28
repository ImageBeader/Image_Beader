#include "imagefileloadpage.h"

#include <QVBoxLayout>
#include <QHBoxLayout>

#include <QPushButton>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QDebug>
#include <QFileDialog>
#include <QPixmap>
#include <QGraphicsPixmapItem>


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

    this->image_scene = new QGraphicsScene();
    QGraphicsView *preview_view = new QGraphicsView(image_scene);
    this->layout()->addWidget(preview_view);

    this->image_filepath_label = new QLabel(tr("Loaded Image: "));
    this->layout()->addWidget(this->image_filepath_label);
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
    this->image_filepath_label->setText(tr("Loaded Image: ") + this->image_filepath);
    QGraphicsPixmapItem *image_item = new QGraphicsPixmapItem(QPixmap(this->image_filepath));
    this->image_scene->clear();
    this->image_scene->addItem(image_item);
}
