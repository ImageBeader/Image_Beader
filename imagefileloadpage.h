#ifndef IMAGEFILELOADPAGE_H
#define IMAGEFILELOADPAGE_H

#include <QWizardPage>
#include <QLineEdit>
#include <QGraphicsView>
#include <QString>

class ImageFileLoadPage : public QWizardPage
{
    Q_OBJECT

private:
    QLineEdit *filename_line;
    QGraphicsView *image_preview;
    QString image_filepath;


    void onBrowseFile();
    void onInputFile();
    void loadPreview();

public:
    ImageFileLoadPage(QWidget *parent = nullptr);
};

#endif // IMAGEFILELOADPAGE_H
