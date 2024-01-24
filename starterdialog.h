#ifndef STARTERDIALOG_H
#define STARTERDIALOG_H

#include <QDialog>

class StarterDialog : public QDialog {
private:
    void setupUi();
public:
    StarterDialog(QWidget *parent = nullptr);
    ~StarterDialog();
};

#endif // STARTERDIALOG_H
