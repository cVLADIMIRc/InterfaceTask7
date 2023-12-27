#ifndef FORM_H
#define FORM_H
#include "ui_form.h"

#include <QWidget>
#include <QMap>
#include <QVector>

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

private:

    QVector<int> prefix_func(const QString &s);
    int find(const QString &s, const QString &t);
};

#endif // FORM_H
