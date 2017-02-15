#include <Stdio.h>
#include <math.h>
#include <complex.h>

typedef struct {double re,im;} komplex;

void komplex_set (komplex* z,double x, double y){
	z -> re = x;
	z -> im = y;
}

komplex komplex_new (double x, double y){
	komplex result = {x,y};
	return result;
}

komplex komplex_add (komplex a, komplex b){
	komplex res = {a.re + b.re , a.im + b.im};
	return res;
}

komplex komplex_sub (komplex a, komplex b){
	komplex res = {a.re - b.re , a.im - b.im};
	return res;
}

komplex komplex_conjugate (komplex z){
	komplex res = {z.re , conj(z.im)};
	return res;
} 

int main ()
{
	komplex a;
	komplex b;
	komplex c;
	komplex d;
	komplex e;
	
	double complex i = csqrt(-2);
	
	b = komplex_new(i,);
	
	komplex_set(&a,i,i);
	
	c = komplex_add(a,b);
	
	d = komplex_sub(a,b);
	
	e = komplex_conjugate(b);
	
	printf("a = %g + %gi\n",a.re,a.im);
	printf("b = %g + %gi\n",b.re,b.im);
	printf("a+b = %g + %gi\n",c.re,c.im);
	printf("a-b = %g + %gi\n",d.re,d.im);
	printf("conj(b) = %g \n",e.re+e.im);
	return 0;
}