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

//      double square(double a);
        double fact(double a);

};

#endif // MATEMATICS_H
