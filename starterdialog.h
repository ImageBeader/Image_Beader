#ifndef STARTERDIALOG_H
#define STARTERDIALOG_H

#include <QDialog>

class StarterDialog : public QDialog {
    Q_OBJECT

public:
    StarterDialog(QWidget *parent = nullptr);
    ~StarterDialog();

private:
    void setupUi();

private slots:
    void newImage();
};

#endif // STARTERDIALOG_H
