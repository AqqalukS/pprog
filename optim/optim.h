#ifndef OPTIM_H

double rosen_func (const gsl_vector * x, void *params);
double least_square_fit (const gsl_vector * x, void *params);
int rosen_optim ();
double *least_square_optim ();

#define OPTIM_H
#endif
