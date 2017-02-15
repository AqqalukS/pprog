#include "nvector.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>

nvector *nvector_alloc(int n)
{
	nvector *v = (nvector *) malloc(sizeof(nvector));
	(*v).size = n;
	(*v).data = (double *) malloc(n * sizeof(double));
	if (v == NULL)
		fprintf(stderr, "error in nvector_alloc\n");
	return v;
}


void nvector_free (nvector* v)
{
	free(v->data);
	free(v);
	v = NULL;
}

void nvector_set (nvector* v, int i, double value)
{
	assert(0<=i && i<v->size);
	(*v).data[i] = value;
}

double nvector_get (nvector* v, int i)
{
	assert(0<=i && i<v->size);
	return v->data[i];
}

double nvector_dot_product (nvector* u, nvector* v)
{
	assert(u->size == v->size);
	
	int n = (*v).size;
	double result = 0.0;
	
	for(size_t i = 0; i < n; ++i)
	{
		result += (*u).data[i]*(*v).data[i];
	}
	return result;
}

void nvector_print (char *s, nvector * v)
{
	printf("%s",s);
	for(size_t i = 0; i < v->size; ++i)
	{
		printf("%g ", v->data[i]);
	}
	printf("\n");
}
