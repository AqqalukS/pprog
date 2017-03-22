#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "my_math.h"

int main (int argc, char **argv)
{
double a = atof(argv[1]), b = atof(argv[2]), dx = atof(argv[3]);

for(double x = a; x <= b; x += dx)
{
	double y = my_arctan(x);
	printf("%g %g %g\n",x ,y ,atan(x));
}
return 0;
}
