#include <QtTest/QtTest>
#include "../src/mycode.h"

#include <sstream>
using namespace std;

class TestMyCode: public QObject {
    Q_OBJECT
private slots:
    void testIvan();
};

void TestMyCode::testIvan() {
    std::stringstream sstr;
    stringstream isst;
    isst << "Ivan";

    hello(isst, sstr);

    string str;
    getline(sstr, str);

    QCOMPARE(str == "hello Ivan", true);
}

QTEST_MAIN(TestMyCode)
#include "test_mycode.moc"
