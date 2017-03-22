#include <gsl/gsl_integration.h>
#include <gsl/gsl_errno.h>
#include <math.h>
#include "my_math.h"

double arctan_integrand (double z, void *params){
	return 1/(pow(z,2) + 1);
}

double my_arctan (double x){
	if(x<0) return - my_arctan(-x);
	if(x>1) return M_PI/2 - my_arctan(1/x); 
	if(x==0) return 0;

	gsl_function f;
	f.function = arctan_integrand;
	f.params = NULL;

	int limit = 100;
	double a = 0, b = x, epsabs = 1e-9, epsrel = 1e-9, result, error;
	gsl_integration_workspace *w =
		gsl_integration_workspace_alloc (limit);
	int status = gsl_integration_qags
		(&f, a, b, epsabs, epsrel, limit, w, &result, &error);
	gsl_integration_workspace_free (w);
	if(status != GSL_SUCCESS) return NAN;
	else return result; 
}
