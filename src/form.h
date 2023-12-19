#ifndef FORM_H
#define FORM_H
#include "ui_form.h"

#include <QWidget>

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    Ui::Form *ui;
    explicit Form(QWidget *parent = nullptr);
    ~Form();

public slots:
    void start();
};

#endif // FORM_H
