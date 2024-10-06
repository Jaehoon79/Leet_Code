#include <stdio.h>

int singleNumber(int* nums, int numsSize) {
    int uniqueN = 0, index = 0;
    for (index =0; index < numsSize; index++) {
        uniqueN ^= nums[index];
        printf("%d ", uniqueN);
    }
    printf("\n");

    return uniqueN;
}

int main () {
    int ret = 0;
    int nums_1[] = {2, 2, 1};
    int nums_2[] = {4, 1, 2, 1, 2};
#if 0
    ret = singleNumber(nums_1, sizeof(nums_1)/sizeof(int));
    printf("1.Answer of 1st-Q: %d \n", ret);
#endif 
    ret = singleNumber(nums_2, sizeof(nums_2)/sizeof(int));
    printf("2.Answer of 2nd-Q: %d \n", ret);

    return 0;   
}