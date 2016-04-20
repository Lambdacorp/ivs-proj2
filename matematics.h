/**
* @file matematics.h
* @version 2.4
* @date 19.04.2016
* @author Lambdacorp
* @copyright ©Lambdacorp
* @brief Header file for aritmethic functions
*
* In this file there are prototypes for arithmethic functions used in the calculator.
*/

#ifndef MATEMATICS_H
#define MATEMATICS_H

#include <math.h> //potrebne pre NAN a INF - detekcia chybovych stavov
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

/**
* @makro
*/
#define my_MAX 9999999999+1 /**< Maximum that can the calculator display */
#define my_MIN -9999999999-1 /**< Minimum that can the calculator display */
#define EPS 0.0000001  /**< odchylka pri ln TODO */

};

#endif // MATEMATICS_H
