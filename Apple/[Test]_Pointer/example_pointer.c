#include <stdio.h>

//basic init of pointers
int main (void) {

    int var = 10;
    int *ptr1, **ptr2;

    ptr1 = &var;
    ptr2 = &ptr1;

    printf("=== the address of var ===\n");
    printf("var(&var) = %p \n", &var);
    printf("ptr1(ptr1) = %p \n", ptr1);
    printf("ptr1(*ptr2) = %p \n", *ptr2);
    printf("\n");

    printf("=== the address of ptr1 ===\n");
    printf("ptr1(&ptr1) = %p \n", &ptr1);
    printf("ptr2(ptr2) = %p \n", ptr2);
    printf("\n");

    printf("=== the address of ptr2 ===\n");
    printf("ptr2(&ptr2) = %p \n", &ptr2);

    printf("=== the value ===\n");
    printf("var = %d\n", var);
    printf("ptr1(*ptr1) = %d \n", *ptr1);
    printf("ptr2(**ptr2) = %d \n", **ptr2);

    return 0;
}