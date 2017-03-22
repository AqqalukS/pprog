#include "integ.h"
#include <stdio.h>
#include <math.h>

int main ()
{

double r1 = integral();
fprintf(stderr,"first integral = %g\n",r1);

double a = 0.1, b = 10, dalpha = 0.01;

for (double alpha = a; alpha < b; alpha += dalpha)
{
	double norm = norm_integral (alpha);
	double hami = hamiltonian_integral (alpha);
	printf("%g %g\n", alpha, hami/norm);
}

return 0;
}
