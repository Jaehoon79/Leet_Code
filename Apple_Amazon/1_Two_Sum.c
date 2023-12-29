#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#if 0
/* Qsort Exmaple */
int cmpfunc (const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int *ret = (int *)malloc(sizeof(int) * 2);
    int index = 0;
    int i = 0;
    int j = numsSize - 1;

    (*returnSize) = 2;

    qsort(nums, numsSize, sizeof(int), cmpfunc);

    while (i != j) {
        int sum = nums[i] + nums[j];
        if (target == sum) {
            ret[0] = nums[i];
            ret[1] = nums[j];
            break;
        }

        else if (target < sum) j--;

        else i++;
    }

    return ret;
}
#endif

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int *ret = (int *)malloc(2 * sizeof(int));
    int ind_x = 0;
    int ind_y = 0;

    (*returnSize) = 2;

    for (ind_x = 0; ind_x < numsSize - 1; ind_x++) {
        for (ind_y = ind_x + 1; ind_y < numsSize; ind_y++) {
            if (target == (nums[ind_x] + nums[ind_y])) {
                ret[0] = ind_x;
                ret[1] = ind_y;
                return ret; 
            }
        }
    }

    return ret;
}

int main (void) {
    int input1[] = {3, 2, 4};
    int target = 6;
    int index = 0;

    int *ret;
    int *returnSize = (int *)malloc(sizeof(int));

    ret = twoSum(input1, sizeof(input1)/sizeof(input1[0]), target, returnSize);

    printf("-- Result -- \n");

    for (index = 0; index < *(returnSize); index++) {
        printf("%d ", ret[index]);
    }

    printf("\n");

    return 0;
}