/**
* @file matematics.h
*
* @brief Header file for aritmethic functions
* @author Lambdacorp
* In this file there are prototypes for arithmethic functions used in the calculator.
*/

#ifndef MATEMATICS_H
#define MATEMATICS_H


class matematics
{
public:
        double plus(double a, double b);
        double minus(double a, double b);

        double div(double a, double b);
        double multiple(double a, double b);

        double power(double a);
                               //unsigned ??
        double n_power(double a,double n);

        double modulo(double a, double b); // TODO double double
        double fact(double a);

        double logaritmus_ln(double x);
        int CF_ITER(double x, double eps); // pomocna funkcia
        double cfrac_log(double x, unsigned int n); // pomocna funkcia

};

#endif // MATEMATICS_H
