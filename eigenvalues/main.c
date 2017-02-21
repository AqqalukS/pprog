#include <stdio.h>
#include <gsl/gsl_matrix.h>
#include <gsl/gsl_math.h>
#include <gsl/gsl_eigen.h>

int main ()
{
	int n=20;
	double s=1/(n+1);

	gsl_matrix *H = gsl_matrix_calloc(n,n);
	
	for(int i=0;i<n-1;i++){
		gsl_matrix_set(H, i, i, -2);
		gsl_matrix_set(H, i, i+1, 1);
		gsl_matrix_set(H, i+1, i, 1);
	}
	
	gsl_matrix_set(H,n-1,n-1,-2);
	gsl_matrix_scale(H,-1/s/s);
	return 0;
}
