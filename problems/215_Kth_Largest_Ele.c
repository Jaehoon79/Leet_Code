#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int cmpfunc (const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int findKthLargest(int* nums, int numsSize, int k) {
    int index = 0;

    printf("nums_size: %d \n", numsSize);
    qsort(nums, numsSize, sizeof(int), cmpfunc);

    for (index = 0; index < numsSize; index++) {
        printf("%d ", nums[index]);
    }

    printf("\n");

    return nums[numsSize - k];
}

int main () {
    int nums_1[] = {3,2,1,5,6,4};
    int k_1 = 2;
    
    int nums_2[] = {3,2,3,1,2,4,5,5,6};
    int k_2 = 4;

    int ret = 0;

    ret = findKthLargest(nums_1, sizeof(nums_1)/sizeof(int), k_1);
    printf("1. Answer of 1st-Q: %d \n", ret);

    ret = findKthLargest(nums_2, sizeof(nums_2)/sizeof(int), k_2);
    printf("2. Answer of 2nd-Q: %d \n", ret);

    return 0;
}