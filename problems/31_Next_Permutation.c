#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap (int *nums, int a, int b) {
    int tmp = nums[a];
    nums[a] = nums[b];
    nums[b] = tmp;
}

void nextPermutation(int* nums, int numsSize) {
    int a = numsSize -2;
    int b = numsSize -1;
    int start, end;
    while ((a >= 0) && (nums[a] >= nums[a+1])) a--;
    printf("a: %d\n", a);
    if (a >= 0) {
        while (nums[a] >= nums[b]) b--;
        swap(nums, a, b);
        start = a+1;
        end = numsSize -1;
        while ((start < end) && (nums[start] > nums[end])) swap(nums, start++, end--);
    }
    else {
        start = 0;
        end = numsSize -1;
        while ((start < end) && (nums[start] > nums[end])) swap(nums, start++, end--);
    }
}

int main() {
    int nums_1[] = {1,2,3};
    int nums_2[] = {3,2,1};
    int nums_3[] = {1,1,5};
    int nums_4[] = {2,3,1};
    int index = 0;

    printf("1.Answer \n");
    nextPermutation(nums_1, sizeof(nums_1)/sizeof(nums_1[0]));
    for (index = 0; index < 3; index++) {
        printf("%d ", nums_1[index]);
    }
    printf("\n");

    printf("2.Answer \n");
    nextPermutation(nums_2, sizeof(nums_2)/sizeof(nums_2[0]));
    for (index = 0; index < 3; index++) {
        printf("%d ", nums_2[index]);
    }
    printf("\n");

    printf("3.Answer \n");
    nextPermutation(nums_3, sizeof(nums_3)/sizeof(nums_3[0]));
    for (index = 0; index < 3; index++) {
        printf("%d ", nums_3[index]);
    }
    printf("\n");

    printf("4.Answer \n");
    nextPermutation(nums_4, sizeof(nums_4)/sizeof(nums_4[0]));
    for (index = 0; index < 3; index++) {
        printf("%d ", nums_4[index]);
    }
    printf("\n");


    return 0;
}