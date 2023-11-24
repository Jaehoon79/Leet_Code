#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    int top_index = 0;
    int bottom_index = numbersSize - 1;
    int sum_of_args = 0;
    int *res_val = (int *)malloc(2 * sizeof(int));
    
    printf("bottom index: %d \n", bottom_index);
    *returnSize = 2;
    
    while (top_index < bottom_index) {
        sum_of_args = numbers[top_index];
        sum_of_args += numbers[bottom_index];

        if (sum_of_args < target) top_index++;
        else if(sum_of_args > target) bottom_index--;
        else break;
    }

    printf("1st index %d, 2nd index %d \n", top_index, bottom_index);
    res_val[0] = top_index;
    res_val[1] = bottom_index;

    return res_val;
}


int main (void) {
    int numbers1[] = {2,7,11,15};
    int numbers2[] = {2,3,4};
    int numbers3[] = {-1,0};
    int target1 = 9, target2 = 6, target3 = -1;
    int *output1, *output2, *output3;
    int returnSize1 = 0, returnSize2 = 0, returnSize3 = 0;

    output1 = twoSum(numbers1, sizeof(numbers1)/sizeof(int), target1, &returnSize1);
    printf("1st output: [%d, %d]\n", output1[0], output1[1]);

    output2 = twoSum(numbers2, sizeof(numbers2)/sizeof(int), target2, &returnSize2);
    printf("2nd output: [%d, %d]\n", output2[0], output2[1]);

    output3 = twoSum(numbers3, sizeof(numbers3)/sizeof(int), target3, &returnSize3);
    printf("3rd output: [%d, %d]\n", output3[0], output3[1]);

    return 0;
}