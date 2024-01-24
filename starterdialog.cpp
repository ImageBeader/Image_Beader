#include "starterdialog.h"
#include <QDebug>

#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>

StarterDialog::StarterDialog(QWidget *parent) : QDialog(parent) {
    setupUi();
}

void StarterDialog::setupUi() {
    qDebug() << "Setting up Dialog UI";

    QVBoxLayout *layout = new QVBoxLayout();
    this->setLayout(layout);

    QLabel *title = new QLabel("Image Beader");
    layout->addWidget(title);

    QPushButton *create_new_btn = new QPushButton("Convert from a new Image.");
    layout->addWidget(create_new_btn);

    /*
    QPushButton *open_file_btn = new QPushButton("Open existing converted file");
    layout->addWidget(open_file_btn);
    */
}

StarterDialog::~StarterDialog(){}
