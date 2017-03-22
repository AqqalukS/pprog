#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<gsl/gsl_errno.h>
#include<gsl/gsl_odeiv2.h>
#define PI  3.14159265358979323846

int diff_equation (double x, const double u[], double uprime[], void *params)
{
	double con = *(double *) params;
	uprime[0] = con*exp(-pow(x,2));

return GSL_SUCCESS;
}

int main (int argc, char **argv)
{
double a = atof(argv[1]), b = atof(argv[2]), dx = atof(argv[3]);

double con = 2/sqrt(PI);

gsl_odeiv2_system sys;
sys.function = diff_equation;
sys.jacobian = NULL;
sys.dimension = 1;
sys.params = (void *) &con; 

for (double x = a; x < b; x += dx)
{
double hstart = copysign(1e-3,x), epsabs = 1e-6, epsrel = 1e-6;

gsl_odeiv2_driver *driver = 
	gsl_odeiv2_driver_alloc_y_new
		(&sys, gsl_odeiv2_step_rk8pd, hstart, epsabs, epsrel);

double t =0, u[1] = {0};

	
	int status = gsl_odeiv2_driver_apply (driver, &t, x, u);
	printf ("%g %g\n", x, u[0]);
	if (status != GSL_SUCCESS) fprintf (stderr, "status = %i", status);

gsl_odeiv2_driver_free (driver);
}
printf("\n\n");

return EXIT_SUCCESS;
}
