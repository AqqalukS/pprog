#include <gsl/gsl_integration.h>
#include <gsl/gsl_errno.h>
#include <math.h>
#include "integ.h"

double integrand (double x, void *params)
{
	return log(x)/sqrt(x);
}

double integral ()
{
	gsl_function f;
	f.function = integrand;
	f.params = NULL;

	int limit = 100;
	double a = 0, b = 1, epsabs = 1e-7, epsrel = 1e-7,result,error;
	
	gsl_integration_workspace *w =
		gsl_integration_workspace_alloc (limit);

	int status = 
		gsl_integration_qags
			( &f, a, b, epsabs, epsrel, limit, w, &result, &error);
	gsl_integration_workspace_free (w);

	if(status!=GSL_SUCCESS) return NAN;
	else return result;
}

double norm_integrand ( double x, void *params)
{
	double alpha = *(double*) params;
	return exp(-alpha * pow(x,2));
}

double hamiltonian_integrand (double x, void *params)
{
	double alpha = *(double*) params;
	return (-pow(alpha,2) * pow(x,2) / 2 
		+ alpha/2 + pow(x,2)/2)*exp(-alpha*pow(x,2));
}

double norm_integral (double alpha)
{
	gsl_function f;
	f.function = norm_integrand;
	f.params = (void*) &alpha;
	
	int limit = 100;

	double a = 0, b = 0, epsabs = 1e-7, epsrel = 1e-7,resiu,resil,erriu, erril;
	
	gsl_integration_workspace 
		*w_iu =
			gsl_integration_workspace_alloc (limit),
		*w_il =
			gsl_integration_workspace_alloc (limit);


	int status_iu = 
		gsl_integration_qagiu
			( &f, a, epsabs, epsrel, limit, w_iu, &resiu, &erriu);

	int status_il = 
		gsl_integration_qagil
			( &f, b, epsabs, epsrel, limit, w_il, &resil, &erril);

	gsl_integration_workspace_free (w_iu);
	gsl_integration_workspace_free (w_il);
	if (status_iu != GSL_SUCCESS | status_il != GSL_SUCCESS) return NAN;
	else return resiu+resil;
}

double hamiltonian_integral (double alpha)
{
	gsl_function f;
	f.function = hamiltonian_integrand;
	f.params = (void*) &alpha;
	
	int limit = 100;

	double a = 0, b = 0, epsabs = 1e-7, epsrel = 1e-7,resiu,resil,erriu, erril;
	
	gsl_integration_workspace 
		*w_iu =
			gsl_integration_workspace_alloc (limit),
		*w_il =
			gsl_integration_workspace_alloc (limit);


	int status_iu = 
		gsl_integration_qagiu
			( &f, a, epsabs, epsrel, limit, w_iu, &resiu, &erriu);

	int status_il = 
		gsl_integration_qagil
			( &f, b, epsabs, epsrel, limit, w_il, &resil, &erril);

	gsl_integration_workspace_free (w_iu);
	gsl_integration_workspace_free (w_il);
	if (status_iu != GSL_SUCCESS | status_il != GSL_SUCCESS) return NAN;
	else return resiu+resil;
}
