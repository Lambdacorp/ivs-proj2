/**
* @file matematics.cpp
*
* @brief Arithmetic functions
* @author Lambdacorp
* In this file there are all functions used for computing in the calculator
*/

#include "matematics.h"
//#include <math.h>

#define my_MAX 9999999999+1 /**< Maximum that can the calculator display */
#define my_MIN -9999999999-1 /**< Minimum that can the calculator display */

/**
* @brief Plus function
* @param a first number
* @param b second number
* @return Returns result after addition
*
* Adds two numbers together (if the result is from the accepted range)
*/
double matematics::plus(double a, double b)
{
return (a+b < my_MAX && a+b > my_MIN) ? a+b : NAN;
}

/**
* @brief Minus function
* @param a first number
* @param b second number
* @return Returns result after subtraction
*
* Subtracts two numbers (if the result is from the accepted range)
*/
double matematics::minus(double a, double b)
{
return (a-b < my_MAX && a-b > my_MIN ) ? a-b : NAN;;
}

/**
* @brief Division function
* @param a first number
* @param b second number
* @return Returns result after division
*
* Divides two numbers (if the result is from the accepted range)
*/
double matematics::div(double a, double b)
{
    if(b==0)
        return INFINITY; /**< Cannot divide by zero! Equals infinity*/

return (a/b < my_MAX && a/b > my_MIN ) ? a/b : NAN;
}

/**
* @brief Multiplation function
* @param a first number
* @param b second number
* @return Returns result after multiplation
*
* Multiplies two numbers (if the result is from the accepted range)
*/
double matematics::multiple(double a, double b)
{
return  (a*b < my_MAX && a*b > my_MIN ) ? a*b : NAN;
}

/**
* @brief N squared
* @param a number
* @return Returns the original number squared
*
* Multiplies the original number by itself (if the result is from the accepted range)
*/
double matematics::power(double a)
{
return  (a*a < my_MAX && a*a > my_MIN ) ? a*a : NAN;
}

/**
* @brief N to the power of M
* @param a first number (N)
* @param b second number (M)
* @return Returns result of N to the power of M
*
* Calculates N to the power of M (if the result is from the accepted range)
*/
double matematics::n_power(double a, double b)
{
    double result=1;
    unsigned long long check= b;
    if(b==check && b>=0)
    {
        for (int i=b ; i>=1 ; i--)
        {
            result=result*a;
        }
    }
    else
        return NAN;

    return (result < my_MAX && result > my_MIN ) ? result : NAN;
}

/*
double matematics::square(double a)
{

return sqrt(a);
}
*/

/**
* @brief Factorial function
* @param a number
* @return Returns factorial of the original number
*
* Calculates factorial (if the result is from the accepted range)
*/
double matematics::fact(double a)
{
    unsigned long long result=1;

    unsigned int check= a;
    if(a==check && a>=0 && a<60 ) //cca fact 60 max for double
    {

        for ( unsigned long long i=a; i>1 ;i--)
        {
            result=result*i;
        }
    }
    else
    {
        return NAN;
    }
//                  result je unsigned  minimum kontrolovat nemusim
return (result < my_MAX ) ? result : NAN;
}

