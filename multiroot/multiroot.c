#include <stdio.h>
#include <assert.h>
#include <gsl/gsl_vector.h>
#include <gsl/gsl_multiroots.h>
#include <gsl/gsl_odeiv2.h>
#include <gsl/gsl_errno.h>
#include "multiroot.h"
#define FSOLVER gsl_multiroot_fsolver_hybrids

int deriv_rosen (const gsl_vector * v, void *params, gsl_vector *f)
{
	double x = gsl_vector_get (v,0);
	double y = gsl_vector_get (v,1);

	// f(x,y) = (1-x)^2 + 100(y-x^2)^2
	double fdx = 2*(x-1)-400*x*(y-x*x);	// df/dx
	double fdy = 200*(y-x*x);		// df/dx
	gsl_vector_set (f,0,fdx);
	gsl_vector_set (f,1,fdy);
	return GSL_SUCCESS;
}

int rosen_root ()
{
	// Rosenbrock function

	const int dim = 2;
	gsl_multiroot_function F;
	F.f = deriv_rosen;
	F.n = dim;
	F.params = NULL;

	gsl_multiroot_fsolver *s = 
		gsl_multiroot_fsolver_alloc (FSOLVER, dim);

	gsl_vector *start = gsl_vector_alloc (dim);
	gsl_vector_set (start, 0, 0.9); /* x start */
	gsl_vector_set (start, 1, 0.9); /* y start */

	gsl_multiroot_fsolver_set (s, &F, start);

	int iter=0,status;
	double acc=0.001;
	fprintf(stderr,"f(x,y) = (1-x)^2 + 100(y-x^2)^2 = 0\n");
	do{
		iter++;
		int flag = gsl_multiroot_fsolver_iterate (s);
		if(flag)break;
		status = gsl_multiroot_test_residual (s->f, acc);

		fprintf(stderr, "iter = %2i, ",iter);
		fprintf(stderr, "x= %g, ",gsl_vector_get (s->x, 0));
		fprintf(stderr, "y= %g,\n",gsl_vector_get (s->x, 1));
	}while(status == GSL_CONTINUE && iter < 99);
	

	gsl_vector_free (start);
	gsl_multiroot_fsolver_free (s);
	fprintf(stderr,"\n");
return 0;
}

int swave (double r, const double y[], double dydr[], void *params)
{
	double e = *(double*) params;
	dydr[0] = y[1];
	dydr[1] = 2 * (-1/r - e) *y[0];
	return GSL_SUCCESS;
}

double Fe (double e, double r)
{
	assert(r>=0);
	const double rmin = 1e-3;
	if (r < rmin) return r-r*r;

	gsl_odeiv2_system s;
	s.function = swave;
	s.jacobian = NULL;
	s.dimension = 2;
	s.params = (void*) &e;

	double acc = 1e-6, eps = 1e-6, hstart = copysign(0.01,r);
	gsl_odeiv2_driver *d = gsl_odeiv2_driver_alloc_y_new 
		(&s, gsl_odeiv2_step_rkf45, hstart, acc, eps);
	
	double t = rmin, y[2] = {t-t*t, 1-2*t};
	int status = gsl_odeiv2_driver_apply (d, &t, r, y);
	if (status != GSL_SUCCESS)
	{
		fprintf (stderr,"Fe, error: %d\n", status);
	}
	gsl_odeiv2_driver_free (d);
	return y[0];
}

int master (const gsl_vector *x, void *params, gsl_vector *f)
{
	double e = gsl_vector_get(x, 0);
	assert(e<0);

	double rmax = *(double*) params;
	double fval = Fe (e, rmax);
	gsl_vector_set (f, 0, fval);
	return GSL_SUCCESS;
}

double Fe_root (double rmax)
{
	int dim = 1;
	gsl_multiroot_fsolver *s =
		gsl_multiroot_fsolver_alloc (FSOLVER,dim);
	
	gsl_multiroot_function F;
	F.f = master;
	F.n = dim;
	F.params   = (void*) &rmax;

	gsl_vector *x = gsl_vector_alloc (dim);
	gsl_vector_set (x,0,-1);

	gsl_multiroot_fsolver_set (s, &F, x);

	int iter = 0, status;
	const double epsabs = 1e-3;

	do{
		iter++;
		status = gsl_multiroot_fsolver_iterate (s);
		if (status) break;

		status = gsl_multiroot_test_residual (s->f, epsabs);
		if (status == GSL_SUCCESS) fprintf (stderr, "converged\n");

		fprintf(stderr, "iter = %2i ", iter);
		fprintf(stderr, "e = %10g ", gsl_vector_get (s->x,0));
		fprintf(stderr, "f(rmax) = %10g\n", gsl_vector_get (s->f,0));
	} while (status == GSL_CONTINUE && iter < 99);
	double e = gsl_vector_get (s->x,0);
	
	gsl_multiroot_fsolver_free (s);
	gsl_vector_free (x);
	return e;
}
