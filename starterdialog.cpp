#include "starterdialog.h"
#include "newimagewizard.h"

#include <QDebug>

#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>

StarterDialog::StarterDialog(QWidget *parent) : QDialog(parent) {
    setupUi();
}

void StarterDialog::setupUi() {

    QVBoxLayout *layout = new QVBoxLayout();
    this->setLayout(layout);

    QLabel *title = new QLabel(tr("Image Beader"));
    layout->addWidget(title);

    QPushButton *create_new_btn = new QPushButton(tr("Convert from a new Image"));
    connect(create_new_btn, &QPushButton::clicked, this, &StarterDialog::newImage);
    layout->addWidget(create_new_btn);

    /*
    QPushButton *open_file_btn = new QPushButton("Open existing converted file");
    layout->addWidget(open_file_btn);
    */
}

void StarterDialog::newImage(){
    NewImageWizard *new_image_wizard = new NewImageWizard(this);
    new_image_wizard->show();
}


StarterDialog::~StarterDialog(){}
