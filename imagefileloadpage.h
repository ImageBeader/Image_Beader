#ifndef IMAGEFILELOADPAGE_H
#define IMAGEFILELOADPAGE_H

#include <QWizardPage>
#include <QGraphicsScene>
#include <QLineEdit>
#include <QString>
#include <QLabel>

class ImageFileLoadPage : public QWizardPage
{
    Q_OBJECT

private:
    QString image_filepath;

    QLineEdit *filename_line;
    QLabel *image_filepath_label;
    QGraphicsScene *image_scene;

    void onBrowseFile();
    void onInputFile();
    void loadPreview();

public:
    ImageFileLoadPage(QWidget *parent = nullptr);
};

#endif // IMAGEFILELOADPAGE_H
