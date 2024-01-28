#include "newimagewizard.h"
#include "imagefileloadpage.h"
#include "imageconfigurationpage.h"

#include <QDebug>

NewImageWizard::NewImageWizard(QWidget *parent) : QWizard(parent){

    //Adding pages
    //TODO: Add intro page
    this->addPage(new ImageFileLoadPage);
    this->addPage(new ImageConfigurationPage);
    //TODO: Add Processing screen

    this->setWindowTitle(tr("ImageBeader - New image conversion"));
}

void NewImageWizard::accept() {
    qDebug() << "accepted Wizard";
}
