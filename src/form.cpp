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

    // Поиск подстроки в строке
    bool found = str.contains(sub_str, Qt::CaseInsensitive); // Игнорирование регистра при поиске

    // Вывод результата
    if (found) {
        ui->result->setText("yes");
    } else {
        ui->result->setText("no");
    }
}
