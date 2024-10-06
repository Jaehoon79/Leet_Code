#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int removeDuplicates(int* nums, int numsSize) {
    int index = 0;
    int count = 0;

    if (numsSize == 1)
        return numsSize;

    while (numsSize > index) {
        nums[count] = nums[index];
        count++;
        index++;
        while ((numsSize > index) && (nums[index] == nums[index -1])) index++;
    }
    return count;
}

int main() {
    int nums_1[] = {1,1,2};
    int nums_2[] = {0,0,1,1,1,2,2,3,3,4};
    int ret = 0;

    ret = removeDuplicates(nums_1, sizeof(nums_1)/sizeof(nums_1[0]));
    printf("1.Answer: %d \n", ret);
    printf("%d %d %d \n", nums_1[0], nums_1[1], nums_1[2]);
    ret = removeDuplicates(nums_2, sizeof(nums_2)/sizeof(nums_2[0]));
    printf("2.Answer: %d \n", ret);

    return 0;
}