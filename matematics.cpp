/**
* @file matematics.ccp
* @version 2.4
* @date 19.04.2016
* @author Lambdacorp
* @copyright ©Lambdacorp
* @brief Arithmetic functions
*
* In this file there are all functions used for computing in the calculator
*/

#include "matematics.h"
#include <math.h> //potrebne pre NAN a INF - detekcia chybovych stavov


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
/** TODO
 * @brief matematics::modulo
 * @param a
 * @param b
 * @return
 */
double matematics::modulo(double a, double b) // TODO problem double a double | vlastne modulo urobit div int * - compare 'a' = result ==ok?
{
    double result=0;
    if (b == 0)
        return INFINITY; // nulou sa neda delit
    else if (a == 0 || b == 1|| a == b)
        return result;
    else if (a == 1) //
        return result=1;
    else
    {
        int helpint= a/b;
        result= a-(helpint*b);
    }

    return (result < my_MAX && result > my_MIN) ? result : NAN; // TODO zbytocna podmienka ??
}

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


/** TODO
 * @brief calc logarithm
 * @param number
 * @return ln of number 'x' +-EPS
 */
double matematics::logaritmus_ln(double x) //TODO testy urobit pre to
{
    double result;
    if ( x < 0)
        return NAN;
    else if (x == 0)
        return INFINITY;
    else if (x == 1)
        return 0;
    else
    {
        int iterr=CF_ITER(x,EPS);
        result=cfrac_log(x,iterr);
    }

    return (result < my_MAX && result > my_MIN ) ? result : NAN;
}

//TODO upravit odsadenie textu (je to nakopirovane )

/**
 * @brief ... // pomocna funkcia na vypocet poctu iteracii (pomocou puleni intervalu) ...
 * @param x
 * @param eps
 * @return numer of iteration
 */
int matematics::CF_ITER(double x, double eps)
// funkcia na vyhladavanie poctu iteraci pomocou puleni intervalu
{
  //double math_log;
  //math_log=log(x);

    bool ok=false;
    int a=0;             // pociatocna hodnota rozsahu
    int b=100;           // koncova hodnota rozsahu long int aby som porovnal kedy prekroci rozsah intu
    int i;           // prostredna hodnota rozsahu

    int n=0;
    int j=1;

    double divergence;

    while (ok!=true)
    {
        if (x<=0)
        {
            n=-1;
            break;
        }

        if (x==1)
        {
            n=0;
            break;
        }

        i=(b-a)/2;
       // divergence=math_log - cfrac_log(x,(a+i));
        divergence= cfrac_log(x,(a+i+1)) - cfrac_log(x,(a+i));

        if(divergence<0)
            divergence=divergence*-1;

        if (divergence< eps)
        {
            b=b-i;  // ak je odchylka mensia ako eps znizime rozsah vyhladavania - konecnu hodnotu o polovicu intervalu
        }
        else
            a=a+i; // ak je odchylka vacsia ako eps zvacsime pociatocnu hodnotu rozsahu vyhladavania o polovicu intervalu

        if(i==0) // ak sa dostaneme delenim na nulu ukoncime cyklus
        {
            ok=true;
            n=a+1; // Pripocitame jednotku nakoniec

              if (n==100*j) // ak vysledna hodnota sa bude rovnat nasobku pociatocnej hodnoty konca intervalu
              {                                   //  t.j. 100 zvacsime interval a hladame znova
                  j++;
                  ok=false;
                  a=n;
                  b=n+100;
              }
        }
    }

    return n;
}
/**
 * @brief matematics::cfrac_log
 * @param number
 * @param number od iteration
 * @return ln of number 'x' +-EPS
 */
double matematics::cfrac_log(double x, unsigned int n)
{
    double z;
    double divisor;
    int a;
    double result;

  /*
  if (x==0)
    result=-1.0 / 0.0; //INF +- chyba ?
  else if(x<0)
    result=0.0 / 0.0; //NAN +- chyba ?
  else
  */

    if (n==0)
        result=x;
    else
    {
        z=(x-1)/(x+1);  // vypocet 'z' pomocou odvodenia zo vzorca
        a=2*n -1;  // hodnota vypocitana podla n-tej iteracie
        //divisor=a-(((n*n)*(z*z))/(a+1));
        //divisor=a-((n*n)*(z*z));
        divisor=a; // delitel
        while(a>1)
        {
            a=a-2; // 'a' kazdou iteraciou znizujeme
            n--;
            divisor=(z*z*n*n)/divisor;  // rozdiel medzi ' z*z*n*n ' a ' n*n*z*z '
            divisor=a-divisor;
        }
        result=(2*z)/divisor;
    }

    return result ;
}


