#include "matematics.h"
#include <math.h>

#define my_MAX 9999999999+1
#define my_MIN -9999999999-1

double matematics::plus(double a, double b)
{
return (a+b < my_MAX && a+b > my_MIN) ? a+b : NAN;
}

double matematics::minus(double a, double b)
{
return (a-b < my_MAX && a-b > my_MIN ) ? a-b : NAN;;
}

double matematics::div(double a, double b)
{
    if(b==0)
        return INFINITY;

return (a/b < my_MAX && a/b > my_MIN ) ? a/b : NAN;
}

double matematics::multiple(double a, double b)
{
return  (a*b < my_MAX && a*b > my_MIN ) ? a*b : NAN;
}

double matematics::power(double a)
{
return  (a*a < my_MAX && a*a > my_MIN ) ? a*a : NAN;
}

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

