#ifndef NEWIMAGEWIZARD_H
#define NEWIMAGEWIZARD_H

#include <QWizard>

class NewImageWizard : public QWizard
{
    Q_OBJECT

public:
    NewImageWizard(QWidget *parent = nullptr);

    void accept() override;
};

#endif // NEWIMAGEWIZARD_H
