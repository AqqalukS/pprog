#ifndef HAVE_INTEG_H

double intregrand (double x, void * params); 
double integral ();
double norm_integrand ();
double hamiltonian_integrand ();
double norm_integral ();
double hamiltonian_integral ();

#define INTEG_H
#endif
