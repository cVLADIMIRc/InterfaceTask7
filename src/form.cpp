#include "form.h"
#include "ui_form.h"

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);

    connect(ui->pushButton, SIGNAL(clicked()),
            this, SLOT(start()));
}

Form::~Form()
{
    delete ui;
}

void Form::start() {
    QString str = ui->str->text();
    QString sub_str = ui->sub_str->text();

    ui->result->setText("result.....");
}
