#include <QtTest/QtTest>
#include "../src/mycode.h"

#include <sstream>
using namespace std;

class TestMyCode: public QObject {
    Q_OBJECT
private slots:
    void test();
};

void TestMyCode::test() {
    std::stringstream sstr;
    stringstream isst;
    isst << "Vova";

    hello(isst, sstr);

    string str;
    getline(sstr, str);

    QCOMPARE(str == "hello Vova", true);
}

QTEST_MAIN(TestMyCode)
#include "test_mycode.moc"
