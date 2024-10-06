#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void swap (int *nums, int a, int b) {
    nums[a] = nums[a]^nums[b];
    nums[b] = nums[a]^nums[b];
    nums[a] = nums[a]^nums[b];
}

void heapify(int *nums, int numsSize, int index) {
    int max = index;
    int l = index * 2 + 1;
    int r = index * 2 + 2;

    if (numsSize > l && nums[l] > nums[max])
        max = l;
    if (numsSize > r && nums[r] > nums[max])
        max = r;
    
    if (max != index) {
        swap(nums, max, index);
        heapify(nums, numsSize, max);
    }
}

void heapSort(int *nums, int numsSize) {
    for (int i = (numsSize -1)/2; i >= 0; i--)
        heapify(nums, numsSize, i);
    
    for (int i = numsSize - 1; i > 0; i--) {
        swap(nums, i, 0);
        heapify(nums, i, 0);
    }
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int **ans = NULL;
    (*returnSize) = 0;

    heapSort(nums, numsSize);

    for (int pivot_ind = 0; pivot_ind < (numsSize -2); pivot_ind++) {
        int sum2_top = pivot_ind + 1;
        int sum2_bottom = numsSize - 1;

        if (pivot_ind == 0 || nums[pivot_ind] != nums[pivot_ind -1]) {
            while (sum2_top <= sum2_bottom) {
                int temp_sum = nums[pivot_ind] + nums[sum2_top] + nums[sum2_bottom];
                if (temp_sum < 0) sum2_top++;
                else if (temp_sum > 0) sum2_bottom--;
                else {
                    ans = (int **)realloc(ans, sizeof(int *) * ((*returnSize) + 1));
                    ans[(*returnSize)] = (int *)malloc(sizeof(int) * 3);
                    ans[(*returnSize)][0] = nums[pivot_ind];
                    ans[(*returnSize)][1] = nums[sum2_top];
                    ans[(*returnSize)][2] =  nums[sum2_bottom];
                    (*returnSize)++;
                    
                    sum2_top++; sum2_bottom--;
                    while (sum2_top < sum2_bottom && nums[sum2_top] == nums[sum2_top-1])
                        sum2_top++;
                    while (sum2_top < sum2_bottom && nums[sum2_bottom] == nums[sum2_bottom+1])
                        sum2_top--;
                }
            }
        }
    }

    (*returnColumnSizes) = (int *)malloc(sizeof(int) * (*returnSize));
    for (int i = 0; i < (*returnSize); i++) {
        (*returnColumnSizes)[i] = 3;
    }

    return ans;
}


int main () {
    int nums_1[] = {-1,0,1,2,-1,-4};
    int *returnSize = (int *)malloc(sizeof(int));
    int **retColumSize = (int **)malloc(sizeof(int *));
    int **ret;
    int index;

    int numSize = sizeof(nums_1)/sizeof(nums_1[0]);
    ret = threeSum(nums_1, numSize, returnSize, retColumSize);

    for (index = 0; index < (*returnSize); index++) {
        if ((*retColumSize)[index] == 3) {
            printf("[%d, %d, %d]\n",ret[index][0], ret[index][1], ret[index][2]);
        }
    }

    return 0;
}