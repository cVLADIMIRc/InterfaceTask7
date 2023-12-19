#include <QtTest/QtTest>
#include "../src/bigint.hpp"

Q_DECLARE_METATYPE(BigInt);

class TestBigInt: public QObject {
    Q_OBJECT
private slots:
    void plus();
    void plus_data();

    void minus();
    void minus_data();

    void mul();
    void mul_data();

    void div();
    void div_data();
    void divByZero();
};

void TestBigInt::plus_data() {
    QTest::addColumn<BigInt>("a");
    QTest::addColumn<BigInt>("b");
    QTest::addColumn<BigInt>("result");

    QTest::newRow("1+5") << BigInt(1) << BigInt(5) << BigInt(6);
    QTest::newRow("big numbers") << BigInt("99999999999999999999")
                                 << BigInt("999999999999999")
                                 << BigInt("100000999999999999998");
    QTest::newRow("1+(-5)") << BigInt("1") << BigInt("-5")<< BigInt("-4");
    QTest::newRow("(-1) + 5") << BigInt("-1") << BigInt("5")<< BigInt("4");
    QTest::newRow("(-1) + (-5)") << BigInt("-1") << BigInt("-5")<< BigInt("-6");
    QTest::newRow("(-1) + (1)") << BigInt("-1") << BigInt("1")<< BigInt("0");
}

void TestBigInt::plus() {
  QFETCH(BigInt, a);
  QFETCH(BigInt, b);
  QFETCH(BigInt, result);

  QCOMPARE(a + b, result);
}

void TestBigInt::minus_data() {
    QTest::addColumn<BigInt>("a");
    QTest::addColumn<BigInt>("b");
    QTest::addColumn<BigInt>("result");

    QTest::newRow("1-1") << BigInt(1) << BigInt(1) << BigInt(0);
    QTest::newRow("1-5") << BigInt(1) << BigInt(5) << BigInt(-4);
    QTest::newRow("5-1") << BigInt(5) << BigInt(1) << BigInt(4);
    QTest::newRow("big numbers") << BigInt("99999999999999999999")
                                 << BigInt("999999999999999")
                                 << BigInt("99999000000000000000");
    QTest::newRow("5 - (-4)") << BigInt("5") << BigInt("-4")<< BigInt("9");
    QTest::newRow("(-5) - (4)") << BigInt("-5") << BigInt("4")<< BigInt("-9");
    QTest::newRow("(-5) - (-4)") << BigInt("-5") << BigInt("-4") << BigInt("-1");
}

void TestBigInt::minus() {
  QFETCH(BigInt, a);
  QFETCH(BigInt, b);
  QFETCH(BigInt, result);

  QCOMPARE(a - b, result);
}

void TestBigInt::mul_data() {
    QTest::addColumn<BigInt>("a");
    QTest::addColumn<BigInt>("b");
    QTest::addColumn<BigInt>("result");

    QTest::newRow("1*5") << BigInt(1) << BigInt(5) << BigInt(5);
    QTest::newRow("big numbers") << BigInt("99999999999999999999")
                                 << BigInt("999999999999999")
                                 << BigInt("99999999999999899999000000000000001");
    QTest::newRow("5 * (-4)") << BigInt("5") << BigInt("-4")<< BigInt(-20);
    QTest::newRow("(-5) * (4)") << BigInt("-5") << BigInt("4")<< BigInt(-20);
    QTest::newRow("(-5) * (-4)") << BigInt("-5") << BigInt("-4") << BigInt(20);
}

void TestBigInt::mul() {
  QFETCH(BigInt, a);
  QFETCH(BigInt, b);
  QFETCH(BigInt, result);

  QCOMPARE(a * b, result);
}

void TestBigInt::div_data() {
    QTest::addColumn<BigInt>("a");
    QTest::addColumn<BigInt>("b");
    QTest::addColumn<BigInt>("result");

    QTest::newRow("(-5)/3") << BigInt(-5) << BigInt(3) << BigInt(-1);
    QTest::newRow("12368/56") << BigInt(12368) << BigInt(56) << BigInt(220);
    QTest::newRow("56/(-12368)") << BigInt(56) << BigInt(12368) << BigInt(0);
    QTest::newRow("56/56") << BigInt(56) << BigInt(56) << BigInt(1);
    QTest::newRow("(-0)/56") << BigInt("-0") << BigInt(56) << BigInt(0);
    QTest::newRow("5/1") << BigInt("5") << BigInt(1) << BigInt(5);
    QTest::newRow("(-56)/(-56)") << BigInt(-56) << BigInt(-56) << BigInt(1);
    QTest::newRow("(10^100) / 1") << BigInt("10000000000000000000000000000000000000000000000000000000000000000000"
                                           "000000000000000000000000000000000")
                                 << BigInt(1)
                                 << BigInt("10000000000000000000000000000000000000000000000000000000000000000000"
                                           "000000000000000000000000000000000");
}

void TestBigInt::div() {
  QFETCH(BigInt, a);
  QFETCH(BigInt, b);
  QFETCH(BigInt, result);

  QCOMPARE(a / b, result);
}

void TestBigInt::divByZero() {
  QVERIFY_EXCEPTION_THROWN(BigInt(123)/BigInt(0), std::overflow_error);
}


QTEST_MAIN(TestBigInt)
#include "test_bigint.moc"
