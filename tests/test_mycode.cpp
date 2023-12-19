#include <QtTest/QtTest>
#include "../src/mycode.h"

#include <sstream>
using namespace std;

class TestMyCode: public QObject {
    Q_OBJECT
private slots:
    // Тест, проверяющий приветствие по имени
    void testHelloWithName() {
        stringstream input;
        stringstream output;
        input << "Alice";

        hello(input, output);

        QCOMPARE(output.str(), string("hello Alice"));
    }

    // Тест, проверяющий приветствие для пустой строки
    void testHelloWithEmptyName() {
        stringstream input;
        stringstream output;
        input << "";

        hello(input, output);

        QCOMPARE(output.str(), string("Извините, имя не было введено."));
    }

    // Тест, проверяющий специальное приветствие для имени "Вася"
    void testHelloWithNameVasya() {
        stringstream input;
        stringstream output;
        input << "Вася";

        hello(input, output);

        QCOMPARE(output.str(), string("Привет, Вася!"));
    }
};

QTEST_MAIN(TestMyCode)
#include "test_mycode.moc"