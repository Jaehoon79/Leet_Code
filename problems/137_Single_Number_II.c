#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int singleNumber(int* nums, int numsSize) {
    int in_bit = 0, in_arr = 0;
    int result = 0;

    for (in_bit = 0; in_bit < 32; in_bit++) {
        int bit = 0;
        for (in_arr = 0; in_arr < numsSize; in_arr++) {
            if(nums[in_arr] & (1u << in_bit)) bit++;
        }
        result |= (((unsigned int)(bit%3)) << in_bit);
    }

    return result;
}

int main() {
    int ret;
    int nums_1[] = {2,2,3,2};
    int nums_2[] = {0,1,0,1,0,1,99};
    int nums_3[] = {-2,-2,1,1,4,1,4,4,-4,-2};

    ret = singleNumber(nums_1, sizeof(nums_1)/sizeof(int));
    printf("1.Answer of 1st-Q: %d \n", ret);

    ret = singleNumber(nums_2, sizeof(nums_2)/sizeof(int));
    printf("2.Answer of 2nd-Q: %d \n", ret);
    
    ret = singleNumber(nums_3, sizeof(nums_3)/sizeof(int));
    printf("3.Answer of 3rd-Q: %d \n", ret);

    return 0;
}