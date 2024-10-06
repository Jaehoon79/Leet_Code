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
#endif


int comfunc (const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

void swap(int *nums, int i, int largest) {
    nums[i] = nums[i]^nums[largest];
    nums[largest] = nums[i]^nums[largest];
    nums[i] = nums[i]^nums[largest];
}
#if 0
void heapify(int *nums, int numsSize, int i) {
  // Initialize largest as root
    int largest = i;

    // left = 2*i + 1
    int l = 2 * i + 1;

    // right = 2*i + 2
    int r = 2 * i + 2;

    // If left child is larger than root
    if (l < numsSize && nums[l] > nums[largest])
        largest = l;

    // If right child is larger than largest
    // so far
    if (r < numsSize && nums[r] > nums[largest])
        largest = r;

    // If largest is not root
    if (largest != i) {
        swap(nums, i, largest);
        // Recursively heapify the affected
        // sub-tree
        heapify(nums, numsSize, largest);
    }
}

void heapSort(int *nums, int numsSize) {
 // Build heap (rearrange array)
    for (int i = numsSize / 2 - 1; i >= 0; i--)
        heapify(nums, numsSize, i);

    // One by one extract an element
    // from heap
    for (int i = numsSize - 1; i > 0; i--) {
        // Move current root to end
        swap(nums, 0, i);
        // call max heapify on the reduced heap
        heapify(nums, i, 0);
    }
}
#endif


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
    for (int i = (numsSize - 1)/2; i >= 0; i--) {
        heapify(nums, numsSize, i);
    }
    for (int i = numsSize -1; i > 0; i--) {
        swap(nums, i, 0);
        heapify(nums, i, 0);
    }
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int *ans = (int *)calloc(sizeof(int), 2);
    (*returnSize) = 0;

    //qsort(nums, numsSize, sizeof(int), comfunc);
    heapSort(nums, numsSize);

    for(int i = 0; i < numsSize; i++)
        printf("%d ", nums[i]);
    printf("\n");

    return ans;
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