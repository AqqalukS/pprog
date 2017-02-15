#include <Stdio.h>

typedef struct {double re, im;} komplex;


void init (komplex* z){
	(*z).re = 0;
	z -> im = 1; 
}

int main ()
{
	komplex x = {2,3};
	printf("%g\n", x.im);
	return 0;
}