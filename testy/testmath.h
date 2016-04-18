#ifndef TESTMATH_H
#define TESTMATH_H

#include <QObject>
//#include <QtTest/QTest>

class testiik : public QObject {
    Q_OBJECT

private slots:


    void test_plus();
    void test_plus_zero_zero();
    void test_plus_bignum();
    void test_plus_smallnum();

    void test_minus();
    void test_minus_zero();
    void test_minus_zero_zero();
    void test_minus_bignum();
    void test_minus_smallnum();

    void test_div_zero();
    void test_div();
    void test_div_max();
    void test_div_min();

    void test_multiple_max();
    void test_multiple_min();
    void test_multiple_zero();
    void test_multiple_num();

    void test_n_power_max();
    void test_n_power_min();
    void test_n_power_num();
    void test_n_power_zero();

    void test_power_zero();
    void test_power();
    void test_power_max();

    void test_fact_zero();
    void test_fact_num();
    void test_fact_max();

    void test_modulo();
    void test_modulo_num();
    void test_modulo_a0();
    void test_modulo_a1();
    void test_modulo_b0();
    void test_modulo_b1();

    void test_logaritmus_ln();
    void test_logaritmus_ln_zapor();
    void test_logaritmus_ln_jeden();
    void test_logaritmus_ln_des();
};

#endif // TESTMATH_H
