#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
int main ()
{
    // The value cannot be change.
    const int * x;
    int const * z;

    // The address cannot be changed.
    int * const y = (int *)malloc(sizeof(int));

    int a = 1;
    int b = 2;

    // Test1
#if 0
    x = &a;
    z = &a;
    printf("1. X value(%d) \n", *x);

    *x = 10;
    *z = 10;
    printf("2. X value(%d) \n", *x);
#endif

    y = &b;
    printf("1. Y Value(%d) \n", *y);

    *y = 10;
    printf("2. Y Value(%d) \n", *y);


    const int * y;
    int const * y;
    
    int * const y;
}