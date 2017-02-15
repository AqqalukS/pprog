#include<stdio.h>
#include <limits.h>
#include <float.h>

int main ()
{
    int i = 1;
    while (i+1>i)
    {
        i++;
    }
    printf("while i = %i\n",i);
    int n = 1;
    for(size_t i = 0; i < INT_MAX; ++i)
    {
        n++;
    }
    printf("for i = %i \n",n);
    
    int j=1;
    do {
        j++;
    } while(j+1>j);
    printf("do while = %i\n", j);
}