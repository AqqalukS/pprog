#include<stdio.h>
#include<gsl/gsl_sf.h>

int main(){
	double a=0, b=10, d=0.2;
	for(double x=a;x<=b;x+=d)
		printf("%9.3g\t %9.3g\t %9.3g \n",x
			,gsl_sf_bessel_J0(x)
			,gsl_sf_bessel_J1(x));
	return 0;
}
