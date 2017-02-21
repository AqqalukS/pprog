#include <stdio.h>
#include <gsl/gsl_eigen.h>
#include <gsl/gsl_matrix.h>
#include <gsl/gsl_vector.h>

const double pi = 3.14159265358979323844;

int main(void)
{
	/* copy from the hints */
	/* Hamiltonian matrix  H′*/
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
	
	/* Diagonalization of the matrix */
	gsl_eigen_symmv_workspace* w =  gsl_eigen_symmv_alloc (n);
	gsl_vector* eval = gsl_vector_alloc(n);
	gsl_matrix* evec = gsl_matrix_calloc(n,n);
	gsl_eigen_symmv(H,eval,evec,w);
	
	/* Sort the eigenvalues and eigenvectors. */
	gsl_eigen_symmv_sort(eval,evec,GSL_EIGEN_SORT_VAL_ASC);
	
	/* Check that your energies are correct */
	fprintf (stderr, "i   exact   calculated\n");
	for (int k=0; k < n/3; k++){
	    double exact = pi*pi*(k+1)*(k+1);
	    double calculated = gsl_vector_get(eval,k);
	    fprintf (stderr, "%i   %g   %g\n", k, exact, calculated);
	}
	return 0;
}
