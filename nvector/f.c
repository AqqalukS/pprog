#include "stdio.h"
#include "math.h"

double square(double x){
	return x*x;
};

int main ()
{
	void print_f_of_1( double (*f)(double)){
		double y = f(1);
		printf("f_of_1 = %g \n",y);
	}
	double (*f)(double);
	f = &square;
	printf("%g\n", f(2));
	print_f_of_1(sin);
	return 0;
}