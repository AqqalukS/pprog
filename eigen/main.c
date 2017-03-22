#include <stdio.h>
#include <gsl/gsl_linalg.h>
#include <gsl/gsl_eigen.h>
#include <gsl/gsl_matrix.h>
#include <gsl/gsl_vector.h>

const double pi = 3.14159265358979323844;

int main()
{
	/* Exercise 1 */
	double a[] = {	6.13,-2.90,5.86,
			8.08,-6.31,3.89,
			-4.36,1.00,0.19};
	double b[] = {	6.23, 5.37, 2.29};
	
	gsl_matrix_view A = gsl_matrix_view_array (a, 3, 3);

	gsl_vector_view B = gsl_vector_view_array (b, 3);

	gsl_vector *x = gsl_vector_alloc (3);

	gsl_linalg_HH_solve (&A.matrix, &B.vector, x);

	printf ("# x = \n");

	gsl_vector_fprintf (stdout, x, "# %g");
	
	gsl_vector_free (x);

	/* exercise 2 */
	/* copies from the hints */

	/* Hamiltonian matrix  H′*/
	printf("\n\n");
	
	int n=20;
	double s=1.0/(n+1);
	gsl_matrix *H = gsl_matrix_calloc(n,n);
	for(int i=0;i<n-1;i++){
		gsl_matrix_set(H,i,i,-2);
		gsl_matrix_set(H,i,i+1,1);
		gsl_matrix_set(H,i+1,i,1);
	}
	gsl_matrix_set(H,n-1,n-1,-2);
	gsl_matrix_scale(H,-1/s/s);

	gsl_eigen_symmv_workspace* w =  gsl_eigen_symmv_alloc (n);
	gsl_vector* eval = gsl_vector_alloc(n);
	gsl_matrix* evec = gsl_matrix_calloc(n,n);
	gsl_eigen_symmv(H,eval,evec,w);

	gsl_eigen_symmv_sort(eval,evec,GSL_EIGEN_SORT_VAL_ASC);

	fprintf (stderr, "i   exact   calculated\n");
	for (int k=0; k < n/3; k++){
		double exact = pi*pi*(k+1)*(k+1);
		double calculated = gsl_vector_get(eval,k);
		fprintf (stderr, "%i   %g   %g\n", k, exact, calculated);
	}

	for(int k=0;k<3;k++){
		printf("%g %g\n",0.0,0.0);
		for(int i=0;i<n;i++) printf("%g %g\n",(i+1.0)/(n+1),gsl_matrix_get(evec,i,k));
		printf("%g %g\n",1.0,0.0);
		printf("\n\n");
	}

gsl_vector_free (eval);
gsl_matrix_free (H);
gsl_matrix_free (evec);
gsl_eigen_symmv_free (w);
return 0; 
}
