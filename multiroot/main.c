#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "multiroot.h"

int main (int argc, char** argv)
{
	/* Exercise 1: Rosenbrock */
	rosen_root ();

	/* exercise 2 */
	double rmax[] = 
	{atof(argv[1]),atof(argv[2]),atof(argv[3]),atof(argv[4]),atof(argv[5])};
	for (int i = 0; i < 5; i++)
	{
		double e = Fe_root (rmax[i]);
		printf("# r, Fe(e,r), exact, for rmax = %g\n",rmax[i]);
		for (double r = 0; r <= rmax[i]; r += rmax[i]/100)
		{
			double F = Fe(e,r);
			printf("%g %g %g\n", r, F, r*exp(-r));
		}
		printf("\n\n");
	}
}
