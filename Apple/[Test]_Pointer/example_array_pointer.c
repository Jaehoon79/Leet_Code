#include <stdio.h>
#include <stdlib.h>

int main (void) {
    int index = 0;
    int **A = (int **)malloc(sizeof(int *) *3);
    
    for (index = 0; index < 3; index++) {
        *(A + index) = (int *)malloc(sizeof(int) * 4);
        //A[index] 
    }

    A[0][0] = 5;
    A[2][0] = 2;
    A[2][3] = 100;

    printf("1st : %d \n", A[0][0]);
    printf("2nd : %d \n", A[2][0]);
    printf("3rd : %d \n", A[2][3]);

    return 0;
}