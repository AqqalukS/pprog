#include<stdio.h>
#include <limits.h>
#include <float.h>

int main ()
{
	/* checking the max and min int */
	printf("my max int:\n");
	printf("INT_MAX       \t = %i \n", INT_MAX);
	
	switch(INT_MAX_EVAL)
	{
	case 0 :
		int n = 1;
		while (n+1>n){n++;}
		printf("while loop    \t = %i\n",n); break;
	case 1 :
		int j = 1;
		for(size_t i = 0; i < INT_MAX; ++i) j++;
		printf("for loop      \t = %i \n", j); break;
	case 2 :    
		int k = 1;
		do {k++;} while(k+1>k);
		printf("do while loop \t = %i \n", k); break;
	default : 
		printf("
	printf("\nmy min int:\n");
	printf("INT_MIN       \t = %i \n", INT_MIN);

	int i = 1;
    	while (i-1<i){i--;}
	printf("while loop    \t = %i \n", i);
	
	int h = 1;
	for(size_t i = 0; i > INT_MIN; --i) h--;
	printf("for loop      \t = %i \n", i);

	int g = 1;
	do{g--;} while(g-1<g);
	printf("do while loop \t = %i \n", g);
	
	/* checking the machines epsilon 
	define the method:
	while loop = 0, for loop = 1 and do while loop = 2*/
	int EPSILON_EVAL_METHOD = 1; 
	
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
	printf("long double epsilon\t = %Lg \n", ld);

return 0;
}
