#include <Stdio.h>

void init(int n, double* a){
	for(size_t i = 0; i < n; i++)
	{
		a[i] = 1;
	}
}

int main (int argc, char const *argv[])
{
	int n = 9;
	double a[n];
	init(n,a);
	printf("\na = ");
		for(size_t i = 0; i < n; i++)
		{
			printf("%g ",*(a+i));
		}
		printf("\n\n");
	return 0;
}