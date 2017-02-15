#include <Stdio.h>

int main ()
{
	double x = 1.23;
	double* p = &x;
	printf("*p = %g\n", *p);
	return 0;
}