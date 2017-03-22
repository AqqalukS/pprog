#include <stdio.h>
#include <math.h>
#include <gsl/gsl_vector.h>
#include <gsl/gsl_multimin.h>
#include "optim.h"

int main ()
{
rosen_optim ();

double *res = least_square_optim ();

double A = res[0];
double T = res[1];
double B = res[2];
free(res);

double t[]= {0.47,1.41,2.36,3.30,4.24,5.18,6.13,7.07,8.01,8.95};
double y[]= {5.49,4.08,3.54,2.61,2.09,1.91,1.55,1.47,1.45,1.25};
double e[]= {0.26,0.12,0.27,0.10,0.15,0.11,0.13,0.07,0.15,0.09};
int n = sizeof(t)/sizeof(t[0]);

printf("# t[i], y[i], e[i]\n");
for(int i = 0; i < n; i++)
{
	printf("%g %g %g\n", t[i], y[i], e[i]);
}
printf("\n\n"); // for index seperation in gnuplot

double dt = (t[1]-t[0])/30;
printf("# ti A*exp(-ti/T)+B\n");

for(double ti = t[0]; ti < t[n-1]; ti += dt)
{
printf("%g %g\n", ti, A*exp(-ti/T)+B);
}
return 0;
}
