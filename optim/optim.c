#include <stdio.h>
#include <gsl/gsl_vector.h>
#include <gsl/gsl_multimin.h>
#include "optim.h"
#define ALG gsl_multimin_fminimizer_nmsimplex2

struct experimental_data {int n; double *t,*y,*e;};

double rosen_func (const gsl_vector * v, void *params)
{
	double x = gsl_vector_get (v,0);
	double y = gsl_vector_get (v,1);
	return pow(1-x,2) + 100 * pow(y-pow(x,2),2); 	
}


double least_square_fit (const gsl_vector *x, void *params) {
	double  A = gsl_vector_get(x,0);
	double  T = gsl_vector_get(x,1);
	double  B = gsl_vector_get(x,2);
	struct experimental_data *p = 
		(struct experimental_data*) params;
	int     n = p->n;
	double *t = p->t;
	double *y = p->y;
	double *e = p->e;
	double sum=0;
	#define f(t) A*exp(-(t)/T) + B
	for(int i=0;i<n;i++) sum += 
		pow( (f(t[i]) - y[i] )/e[i] ,2);
	return sum;
}

int rosen_optim ()
{
	// Rosenbrock function

	size_t dim = 2;
	gsl_multimin_function F;
	F.f = rosen_func;
	F.n = dim;
	F.params = NULL;

	gsl_multimin_fminimizer * state =
		gsl_multimin_fminimizer_alloc (ALG, dim);

	gsl_vector *start = gsl_vector_alloc (dim);
	gsl_vector_set (start, 0, 2); /* x start */
	gsl_vector_set (start, 1, 2); /* y start */

	gsl_vector *step = gsl_vector_alloc (dim);
	gsl_vector_set_all (step, 0.05);

	gsl_multimin_fminimizer_set (state, &F, start, step);

	int iter=0,status;
	double acc=0.001;
	fprintf(stderr,"Rosenbrock function\n");
	do{
		iter++;
		int flag = gsl_multimin_fminimizer_iterate (state);
		if(flag!=0)break;
		status = gsl_multimin_test_size (state->size, acc);
		if (status == GSL_SUCCESS) fprintf (stderr, "converged\n");
		fprintf(stderr,
			"iter=%2i, x= %8f, y= %8f, f(x,y)= %8g, size= %8g\n",
			iter,
			gsl_vector_get (state->x, 0),
			gsl_vector_get (state->x, 1),
			state->fval,
			state->size);
	}while(status == GSL_CONTINUE && iter < 99);
	

	gsl_vector_free (start);
	gsl_vector_free (step);
	gsl_multimin_fminimizer_free (state);
	fprintf(stderr,"\n");
return 0;
}
double *least_square_optim ()
{
	// Least-squares fit

	double t[]= {0.47,1.41,2.36,3.30,4.24,5.18,6.13,7.07,8.01,8.95};
	double y[]= {5.49,4.08,3.54,2.61,2.09,1.91,1.55,1.47,1.45,1.25};
	double e[]= {0.26,0.12,0.27,0.10,0.15,0.11,0.13,0.07,0.15,0.09};
	int n = sizeof(t)/sizeof(t[0]);

	size_t d = 3;
	struct experimental_data params;
	params.n = n;
	params.t = t;
	params.y = y;
	params.e = e;
	
	
	gsl_multimin_function F;
	F.f = least_square_fit;
	F.n = d;
	F.params = (void *) &params;

	gsl_vector *start = gsl_vector_alloc (F.n);
	gsl_vector_set (start, 0, 3);
	gsl_vector_set (start, 1, 2);
	gsl_vector_set (start, 2, 0);
	
	gsl_vector *step = gsl_vector_alloc (F.n);
	gsl_vector_set (step, 0, 2);
	gsl_vector_set (step, 1, 2);
	gsl_vector_set (step, 2, 2);

	gsl_multimin_fminimizer * state =
		gsl_multimin_fminimizer_alloc (ALG, F.n);

	gsl_multimin_fminimizer_set (state, &F, start, step);


	int iter=0,status;
	double acc=0.00001;
	fprintf(stderr,"Least square fit\n");
	do{
		iter++;
		int flag = gsl_multimin_fminimizer_iterate (state);
		if(flag!=0) break;
		status = gsl_multimin_test_size (state->size, acc);
		if (status == GSL_SUCCESS) fprintf (stderr, "converged\n");
		fprintf(stderr,
			"iter=%2i, A= %8f, T= %8f, B= %8g, size= %8g\n",
			iter,
			gsl_vector_get (state->x, 0),
			gsl_vector_get (state->x, 1),
			gsl_vector_get (state->x, 2),
			state->size);
	}while(status == GSL_CONTINUE && iter < 99);
	
	double *res = malloc(sizeof(double)*3);
	res[0] = gsl_vector_get (state->x, 0); // A
	res[1] = gsl_vector_get (state->x, 1); // T
	res[2] = gsl_vector_get (state->x, 2); // B

return res;
}
