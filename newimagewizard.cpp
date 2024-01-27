#include "newimagewizard.h"
#include "imagefileloadpage.h"

NewImageWizard::NewImageWizard(QWidget *parent) : QWizard(parent){

    //Adding pages
    //TODO: Add intro page
    this->addPage(new ImageFileLoadPage);
    //TODO: Add Configuration file.
    //TODO: Add Processing screen

    this->setWindowTitle(tr("ImageBeader - New image conversion"));
}

void NewImageWizard::accept() {

}
