#include "nvector.h"
#include "stdio.h"
#include "stdlib.h"
#include <assert.h>
#define RND (double)rand()/RAND_MAX

int main (int argc, char const *argv[])
{
	int n = 5;
	
	nvector *v = nvector_alloc(n);
	nvector *u = nvector_alloc(n);
	nvector *w = nvector_alloc(n);
	
	assert(v!=NULL);
	printf("test success\n");
	
	for(size_t i = 0; i < n; ++i)
	{
		double x = RND, y = RND;
		nvector_set(v, i, x);
		nvector_set(u, i, y);
		nvector_set(w, i, y+x);
	}
	
	nvector_print("v+u	= ", w);
	nvector_print("v	= ", v);
	nvector_print("u	= ", u);
	return 0;
}