#include<stdio.h>
#include<math.h>
#include<complex.h>


int main ()
{
    double i = tgamma(5.);
    double j = j1(0.5);
    double complex c = csqrt(-2.);
    double complex ei = cpow(M_E,I);
    double complex eipi = cpow(M_E,I*M_PI);
    double complex ie = cpow(I,M_E);
    double x1 = 0.1111111111111111111111111111L;
    double x2 = 0.1111111111111111111111111111L;
    long double x3 = 0.111111111111111111111111111L;
    
    printf("tgamma(5)   = %lg\n",i);
    printf(" j1(0.5)    = %lg\n", j);
    printf("sqrt(-2)    = %lg + %lg i\n", creal(c), cimag(c));
    printf("e^i         = %g + %g i\n",creal(ei),cimag(ei));
    printf("e^i*pi      = %g + %g i\n", creal(eipi),cimag(eipi));
    printf("i^e         = %g + %g i\n", creal(ie),cimag(ie));
    printf("Print g     = %.25g\n", x1);
    printf("Print lg    = %.25lg\n", x2);
    printf("Print Lg    = %.25Lg\n", x3);
    return 0;
}
