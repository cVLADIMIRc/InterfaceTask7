#include "form.h"
#include "qdebug.h"
#include "qelapsedtimer.h"
#include "ui_Form.h"
#include "boyermoresearch.h"
#include "QVector"

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

    QElapsedTimer timer;
    timer.start();

    QVector<int> bmResult = search(str, sub_str);

    qint64 bmElapsedNanos = timer.nsecsElapsed();
    timer.restart();

    QVector<int> idxResult;
    int pos = 0;
    while ((pos = str.indexOf(sub_str, pos)) != -1) {
        idxResult.append(pos);
        pos += sub_str.size();
    }

    qint64 idxElapsedNanos = timer.nsecsElapsed();

    if (bmResult.isEmpty() && idxResult.isEmpty()) {
        ui->result->setText("Substring not found");
    } else {
        QString resultString;
        for (int i : idxResult) {
            resultString.append(QString::number(i) + " ");
        }
        ui->result->setText(resultString);
        qDebug() << "Time taken by Boyer-Moore: " << bmElapsedNanos << " ns";
            qDebug() << "Time taken by indexOf: " << idxElapsedNanos << " ns";
    }
}

QLineEdit* Form::getTextLineEdit() const{
    return ui->str;
}

QLineEdit* Form::getSubStringLineEdit() const{
    return ui->sub_str;
}

QPushButton* Form::getSearchButton() const{
    return ui->pushButton;
}

QLabel* Form::getResultLabel() const{
    return ui->result;
}
