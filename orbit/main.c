#include<stdio.h>
#include<math.h>
#include<gsl/gsl_errno.h>
#include<gsl/gsl_odeiv2.h>

int logistic_equation (double x, const double y[], double dydx[], void *params){
	(void)(x);
	dydx[0] = y[0]*(1-y[0]);
return GSL_SUCCESS;
}

int orbit_equation (double phi, const double y[], double yprime[], void *params)
{
	double epsilon = *(double *) params;
	yprime[0] = y[1];
	yprime[1] = 1 - y[0] + epsilon * y[0] * y[0];

return GSL_SUCCESS;
}

int main (int argc, char **argv)
{

gsl_odeiv2_system logic;
logic.function 	= logistic_equation;	
logic.jacobian 	= NULL;	
logic.dimension	= 1;	
logic.params	= NULL;	

double xmax = 3, dx = xmax/30, epsabs = 1e-6, epsrel = 1e-6, hstart = 1e-3;

gsl_odeiv2_driver *driver =
	gsl_odeiv2_driver_alloc_y_new
		(&logic, gsl_odeiv2_step_rk8pd, hstart, epsabs, epsrel);

double t = 0, y[1] = {0.5};

for (double x = 0; x < xmax; x += dx)
{
	int status = gsl_odeiv2_driver_apply (driver, &t, x, y);
	printf ("%g %g\n", x, y[0]);
	if (status != GSL_SUCCESS) fprintf (stderr, "status = %i", status);
}
gsl_odeiv2_driver_free (driver);
printf("\n\n");


double epsilon[3] = {0., 0., 0.01}, uprime[3] = {0, -0.5, -0.5};

for (int i = 0; i < 3; i++)
{
	gsl_odeiv2_system orbit;
	orbit.function	= orbit_equation;
	orbit.jacobian	= NULL;
	orbit.dimension	= 2;
	orbit.params	= (void *) &epsilon[i];

	double hstart = 1e-3, epsabs = 1e-6, epsrel = 1e-6;
	double phi_max =50.5 * M_PI, delta_phi = 0.05;

	gsl_odeiv2_driver *driver = 
		gsl_odeiv2_driver_alloc_y_new
			(&orbit, gsl_odeiv2_step_rk8pd, hstart, epsabs, epsrel);

	double t = 0, y[2] = { 1, uprime[i] };

	for (double phi = 0; phi < phi_max; phi += delta_phi)
	{
		int status = gsl_odeiv2_driver_apply (driver, &t, phi, y);
		printf ("%g %g\n", phi, y[0]);
		if (status != GSL_SUCCESS) fprintf (stderr, "status = %i", status);
	}

gsl_odeiv2_driver_free (driver);
printf("\n\n");
}
return EXIT_SUCCESS;
}
