#include "form.h"
#include "ui_form.h"

// 0. Положить проект в git, дописать код в form.cpp,
//       оформить в виде отдельного коммита
// 1. Написать модульные тесты к коду (код переписать)
//       (решение создавать в отдельной ветке git)
// 2. В другой ветке написать UI тесты к коду
// 3. В коде из предыдущей работы написать тесты к фасаду
//      (код из предыдущей работы поместить в еще одну ветку)
// { в качестве ответа на задание крепим ссылку на публичный
//   git-репозиторий }
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