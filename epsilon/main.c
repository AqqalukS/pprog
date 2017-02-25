#include<stdio.h>
#include<limits.h>
#include<float.h>
#include"equal.h"

int main ()
{
	/* checking the max and min int */
	printf("my max int:\n");
	printf("INT_MAX            \t = %i \n", INT_MAX);
	
	int EVAL_MODE = 2;	
	
	int n = 1;
	switch(EVAL_MODE)
	{
		case 0 :
			while (n+1>n){n++;}
			printf("while loop       \t = %i\n",n); break;
		case 1 :
			for(size_t i = 0; i < INT_MAX; ++i) n++;
			printf("for loop         \t = %i \n", n); break;
		case 2 :    
			do {n++;} while(n+1>n);
			printf("do while loop    \t = %i \n", n); break;
		default : 
			printf("indeterminated");
	}

	printf("\nmy min int:\n");
	printf("INT_MIN            \t = %i \n", INT_MIN);
	
	int m = 1;
	switch(EVAL_MODE)
	{
		case 0 :	
			while (m-1<m){m--;}
			printf("while loop       \t = %i \n", m); break;
		case 1 :
			for(size_t i = 0; i > INT_MIN; --i) m--;
			printf("for loop         \t = %i \n", m); break;
    	case 2 :	
			do{m--;} while(m-1<m);
			printf("do while loop    \t = %i \n", m); break;
		default : 
			printf("indeterminated");
	}
	
	/* checking the machines epsilon 
	define the method:
	while loop = 0, for loop = 1 and do while loop = 2*/
	
	int EPSILON_EVAL_METHOD = 2; 
	
	float f = 1.0f;
	double d = 1.0;
	long double ld = 1.0L;	
	printf("\nEvaluate epsilon ");
	switch(EPSILON_EVAL_METHOD)
	{
	case 0 : 
		printf("using while loop.\n\n");
		while(1+f!=1){f/=2;} f*=2;

		while(1+d!=1){d/=2;} d*=2;

		while(1+ld!=1){ld/=2;} ld*=2; break;
	case 1 :
		printf("using for loop.\n\n");
		for(f = 1; 1+f!=1; f/=2){} f*=2;

		for(d = 1; 1+d!=1; d/=2){} d*=2;

		for(ld = 1; 1+ld!=1; ld/=2){} ld*=2; break;
	case 2 :
		printf("using do while loop.\n\n");
		do {f/=2;} while(1+f!=1); f*=2;

		do {d/=2;} while(1+d!=1); d*=2;
		
		do {ld/=2;} while(1+ld!=1); ld*=2; break;
	default :
		 printf("indeterminated\n\n");
	}

	printf("FLT_EPSILON        \t = %g \n", FLT_EPSILON);
	printf("float epsilon      \t = %g \n", f);
	printf("DBL_EPSILON        \t = %g \n", DBL_EPSILON);
	printf("double epsilon     \t = %g \n", d);
	printf("LDBL_EPSILON       \t = %Lg \n", LDBL_EPSILON);
	printf("long double epsilon\t = %Lg \n\n", ld);

	int max = INT_MAX/2;
	
	float suf = 0.0f, sdf = 0.0f, sf = 1.0f;
	double sud = 0.0L, sdd = 0.0L, sd = 1.0L;
	
	for(int i = 0; i < max; i++)
	{
		suf += sf/(i+1);
		sud += sd/(i+1);
		sdf += sf/(max-i);
		sdd += sd/(max-i);
	}
	printf("max                \t = %d\n", max);
	printf("sum_up_float       \t = %g\n", suf);
	printf("sum_up_double      \t = %g\n", sud);
	printf("sum_down_float     \t = %g\n", sdf);
	printf("sum_down_double    \t = %g\n\n", sdd);
	
	double a = 2.5 , b = 2.3 , tau = 0.1 , epsilon = 0.1;

	int EQ = equal(a,b,tau,epsilon);
	switch(EQ)
	{
	case 0 :
		printf("%g != %g with precision tau = %g or epsilon %g\n", a, b, tau, epsilon); break;
	case 1 :
		printf("%g = %g with precision tau = %g or epsilon = %g\n", a, b, tau, epsilon); break;
	default :
		printf("indeterminated\n\n");
	}
return 0;
}
