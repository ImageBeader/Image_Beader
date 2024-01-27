#ifndef IMAGEFILELOADPAGE_H
#define IMAGEFILELOADPAGE_H

#include <QWizardPage>
#include <QLineEdit>
#include <QGraphicsView>


class ImageFileLoadPage : public QWizardPage
{
    Q_OBJECT

private:
    QLineEdit *filename_line;
    QGraphicsView *image_preview;

    void browseFile();

public:
    ImageFileLoadPage(QWidget *parent = nullptr);
};

#endif // IMAGEFILELOADPAGE_H
