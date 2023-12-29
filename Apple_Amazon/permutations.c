#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int **ret_perm = (int **)malloc(sizeof(int *));
    printf("size: %d \n", numsSize);
    return ret_perm;
}

#define INPUT1  3
#define INPUT2  2

int main (void) {
    int test1[INPUT1] = {1, 2, 3};
    int test2[INPUT2] = {0, 1};
    int **returnColumnSizes;
    int returnsize;
    int index = 0;

    permute(test1, sizeof(test1)/sizeof(test1[0]), &returnsize, returnColumnSizes);
    permute(test2, sizeof(test2)/sizeof(test2[0]), &returnsize, returnColumnSizes);

    return 0;
}