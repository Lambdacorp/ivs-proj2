/**
  *@file testmath.cpp
  *@version 2.4
  *@date 19.04.2016
  *@author Lambdacorp
  *@copyright ©Lambdacorp
  *@brief Tests for arithmethic functions
  */

#include "testmath.h"
#include "matematics.h"
#include <math.h>
#include <QtTest/QTest>
#include <stdlib.h>

matematics M;

/**
 * @brief Test na scitanie dvoch cisel
 */
void testiik::test_plus()
{

    QCOMPARE(M.plus(2,3) , (double) 5);
}

/**
 * @brief Test na scitanie a overenie najvacsieho cisla
 */
void testiik::test_plus_bignum()
{

    QVERIFY( std::isnan(M.plus(HIGH_LIMIT,1) ) );
}
/**
 * @brief Test na scitanie a overenie najmensieho cisla
 */
void testiik::test_plus_smallnum()
{

    QVERIFY( std::isnan(M.plus(DOWN_LIMIT,-1) ) );
}
/**
 * @brief Test na scitanie dvoch nul
 */
void testiik::test_plus_zero_zero()
{
    QCOMPARE(M.plus(0,0), (double) 0);
}


/**
 * @brief Test na odcitanie dvoch cisel
 */
void testiik::test_minus()
{
    double a=999999;
    QCOMPARE(M.minus(a,111111), (double) 888888);
}
/**
 * @brief Test na odcitanie dvoch rovnakych cisel
 */
void testiik::test_minus_zero()
{
    double a=rand() %HIGH_LIMIT;
    QCOMPARE(M.minus(a,a), (double) 0);
}
/**
 * @brief Test na odcitanie dvoch nul
 */
void testiik::test_minus_zero_zero()
{
    QCOMPARE(M.minus(0,0), (double) 0);
}
/**
 * @brief Test na odcitanie a overenie najvacsieho cisla
 */
void testiik::test_minus_bignum()
{

    QVERIFY( std::isnan(M.minus(DOWN_LIMIT,1) ) );
}
/**
 * @brief Test na odcitanie a overenie najmensieho cisla
 */
void testiik::test_minus_smallnum()
{

    QVERIFY( std::isnan(M.minus(DOWN_LIMIT,1) ) );
}


/**
 * @brief Test na delenie nulou
 */
void testiik::test_div_zero()
{
    double a=rand() %HIGH_LIMIT;
    QVERIFY(std::isinf(M.div(a,0) ));
}
/**
 * @brief Test na delenie dvoch cisel
 */
void testiik::test_div()
{
    double a=15;
    QCOMPARE(M.div(a,3), (double) 5);
}
/**
 * @brief Test na delenie dvoch najvacsich cisel
 */
void testiik::test_div_max()
{
    QCOMPARE((M.div(HIGH_LIMIT,HIGH_LIMIT) ),(double)1);
}
/**
 * @brief Test na delenie dvoch najmensich cisel
 */
void testiik::test_div_min()
{
    QVERIFY(std::isnan(M.div(DOWN_LIMIT-1,1) ));
}


/**
 * @brief Test na nasobenie a overenie najvacsieho cisla
 */
void testiik::test_multiple_max()
{
    QVERIFY(std::isnan(M.multiple(rand() %HIGH_LIMIT,HIGH_LIMIT) ));
}
/**
 * @brief Test na nasobenie a overenie najmensieho cisla
 */
void testiik::test_multiple_min()
{
    QVERIFY(std::isnan(M.multiple(rand() %DOWN_LIMIT,DOWN_LIMIT) ));
}
/**
 * @brief Test na nasobenie nulou
 */
void testiik::test_multiple_zero()
{
    double a=rand() %HIGH_LIMIT;
    QCOMPARE(M.multiple(a,0), (double)0 );
}
/**
 * @brief Test na nasobenie dvoch cisel
 */
void testiik::test_multiple_num()
{
    QCOMPARE(M.multiple(10,5), (double)50 );
}



/**
 * @brief Test na n-tu mocnicu a overenie najvacsieho cisla
 */
void testiik::test_n_power_max()
{
    QVERIFY(std::isnan(M.n_power(rand() %HIGH_LIMIT,0.25) ));
}
/**
 * @brief Test na n-tu mocninu a overenie najmensieho cisla
 */
void testiik::test_n_power_min()
{
    QVERIFY(std::isnan(M.n_power(rand() %DOWN_LIMIT,DOWN_LIMIT) ));
}
/**
 * @brief Test na n-tu mocninu
 */
void testiik::test_n_power_num()
{
    QCOMPARE(M.n_power(2,5), (double)32 );
}
/**
 * @brief Test na n-tu mocninu kde n=0
 */
void testiik::test_n_power_zero()
{
    double a=rand() %HIGH_LIMIT;
    QCOMPARE(M.n_power(a,0), (double)1 );
}


/**
 * @brief Test na mocninu, kde umocnujeme cislom 0
 */
void testiik::test_power_zero()
{
    QCOMPARE(M.power(0) , double (0));
}
/**
 * @brief Test na mocninu
 */
void testiik::test_power()
{
    QCOMPARE(M.power(5) , double (25));
}
/**
 * @brief Test na mocninu a overenie najvacsieho cisla
 */
void testiik::test_power_max()
{
    QVERIFY(std::isnan(M.power(rand() %HIGH_LIMIT) ));
}


/**
 * @brief Test na faktorial cisla 0
 */
void testiik::test_fact_zero()
{
    double a = 0;
    QCOMPARE(M.fact(a) , double (1));
}
/**
 * @brief Test na faktorial cisla
 */
void testiik::test_fact_num()
{
    double a = 3;
    QCOMPARE(M.fact(a) , double (6));
}
/**
 * @brief Test na faktorial cisla a overenie najvacsieho cisla
 */
void testiik::test_fact_max()
{
    QVERIFY(std::isnan(M.fact(rand() %HIGH_LIMIT) ));
}


/**
 * @brief Test na modulo dvoch rovnakych cisel
 */
void testiik::test_modulo()
{
    QCOMPARE(M.modulo(3,3) , double (0));
}
/**
 * @brief Test na modulo, ak b=0
 */
void testiik::test_modulo_b0()
{
    double a=rand() %HIGH_LIMIT;
    QVERIFY(std::isinf(M.modulo(a,0)));
}
/**
 * @brief Test na modulo, ak b=1
 */
void testiik::test_modulo_b1()
{
    double a=rand() %HIGH_LIMIT;
    QCOMPARE(M.modulo(a,1) , double (0));
}
/**
 * @brief Test na modulo, ak a=0
 */
void testiik::test_modulo_a0()
{
    double b=rand() %HIGH_LIMIT;
    QCOMPARE(M.modulo(0,b) , double (0));
}
/**
 * @brief Test na modulo, ak a=1
 */
void testiik::test_modulo_a1()
{
    double b=rand() %HIGH_LIMIT;
    QCOMPARE(M.modulo(1,b) , double (1));
}
/**
 * @brief Test na modulo dvoch roznych cisel
 */
void testiik::test_modulo_num()
{
    QCOMPARE(M.modulo(10,3) , double (1));
}


/**
 * @brief Test na prirodzeny logaritmus cisla 0
 */
void testiik::test_logaritmus_ln()
{
    QVERIFY(std::isinf(M.logaritmus_ln(0)));
}
/**
 * @brief Test na prirodzeny logaritmus zaporneho cisla
 */
void testiik::test_logaritmus_ln_zapor()
{
    QVERIFY(std::isnan(M.logaritmus_ln(-56)));
}
/**
 * @brief Test na prirodzeny logaritmus cisla 1
 */
void testiik::test_logaritmus_ln_jeden()
{
    QCOMPARE(M.logaritmus_ln(1) , double (1));
}
/**
 * @brief Test na prirodzeny logaritmus desatinneho cisla
 * @bug Odchylka je 0.0000001
 */
void testiik::test_logaritmus_ln_des()
{
    QCOMPARE(M.logaritmus_ln(0.32) , log(0.32));
}

