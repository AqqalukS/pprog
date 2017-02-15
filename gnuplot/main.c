#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.1415926536
#define MAX(a,b) (a)>(b)?(a):(b)
#define RND (double)rand()/RAND_MAX
#define TRACE(args...) fprintf(stderr, args);

int main ()
{
	TRACE("MAX(0,1)= %g", MAX(0.0,1.0));
	
	double x,a=0,b=20,dx=0.1;
	for(x=a;x<=b;x+=dx)
	{
		printf("%g \t %g\n",x,sin(x));
	}
	return 0;
}