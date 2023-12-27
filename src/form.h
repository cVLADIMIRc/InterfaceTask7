#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>

#include "boyermoresearch.h"

    namespace Ui {
    class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = nullptr);
    ~Form();

public slots:
    void start();

private:
    Ui::Form *ui;
    QLineEdit* getTextLineEdit() const;
    QLineEdit* getSubStringLineEdit() const;
    QPushButton* getSearchButton() const;
    QLabel* getResultLabel() const;
};

#endif // FORM_H
