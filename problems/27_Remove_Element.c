#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(int *nums, int a, int b) {
    int tmp = nums[a];
    nums[a] = nums[b];
    nums[b] = tmp;
}

int removeElement(int* nums, int numsSize, int val) {
    int index = 0;
    int count = 0;

    for (index = 0; index < numsSize; index++) {
        if (nums[index] == val) continue;
        nums[count++] = nums[index];
    }

    return count;
}

int main() {
    int nums_1[] = {3,2,2,3};
    int val_1 = 3;

    int nums_2[] = {0,1,2,2,3,0,4,2};
    int val_2 = 2;
    int index = 0;
    int ret = 0;

    ret = removeElement(nums_1, sizeof(nums_1)/sizeof(nums_1[0]), val_1);
    printf("1.Answer: %d \n", ret);
    for (index = 0; index < ret; index++) {
        printf("%d ", nums_1[index]);
    }
    printf("\n");
    ret = removeElement(nums_2, sizeof(nums_2)/sizeof(nums_2[0]), val_2);
    printf("2.Answer: %d \n", ret);
    for (index = 0; index < ret; index++) {
        printf("%d ", nums_2[index]);
    }
    printf("\n");

    return 0;
}