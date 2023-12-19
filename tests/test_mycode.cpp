#include <QtTest/QtTest>
#include "../src/form.h"

class TestMyCode : public QObject {
    Q_OBJECT

private slots:
    // Новые тесты для формы
    void testSubstringPresent();
    void testSubstringNotPresent();
};

void TestMyCode::testSubstringPresent() {
    Form form;
    QString str = "Hello, World!";
    QString sub_str = "World";

    form.ui->str->setText(str);
    form.ui->sub_str->setText(sub_str);

    form.start();

    // Дополнительный вывод для отслеживания прохождения теста
    qDebug() << "Test Substring Present Result:" << form.ui->result->text();

    QCOMPARE(form.ui->result->text(), QString("yes"));
}

void TestMyCode::testSubstringNotPresent() {
    Form form;
    QString str = "Hello, World!";
    QString sub_str = "Universe";

    form.ui->str->setText(str);
    form.ui->sub_str->setText(sub_str);

    form.start();

    // Дополнительный вывод для отслеживания прохождения теста
    qDebug() << "Test Substring Not Present Result:" << form.ui->result->text();

    QCOMPARE(form.ui->result->text(), QString("no"));
}


QTEST_MAIN(TestMyCode)
#include "test_mycode.moc"
