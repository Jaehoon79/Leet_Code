#include <stdio.h>
#include <stdlib.h>

int cmpfunc (const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int *tot_nums = (int *)malloc(sizeof(int) * (nums1Size + nums2Size));
    int index = 0;
    double median = 0.0;

    for (index = 0; index < nums1Size; index++)
        tot_nums[index] = nums1[index];
    
    for (index = 0; index < nums2Size; index++)
        tot_nums[nums1Size + index] = nums2[index];
    
    qsort(tot_nums, nums1Size + nums2Size, sizeof(int), cmpfunc);

    for (index = 0; index < nums1Size + nums2Size; index++)
        printf("%d \n", tot_nums[index]);

    if (((nums1Size + nums2Size) % 2) == 0) {
        index = (nums1Size + nums2Size)/2 - 1;
        median = (float)(tot_nums[index] + tot_nums[index + 1])/2;
        printf("AAAA\n");
    }
    else {
        median = (float)tot_nums[(nums1Size + nums2Size)/2];
        printf("BBBB\n");
    }

    return median;
}

int main() {
    int nums1[] = {1,3};
    int nums2[] = {2};

    int nums1_2[] = {1,2};
    int nums2_2[] = {3,4};

    printf("1.Answer of 1-Q: %lf \n",
        findMedianSortedArrays(nums1, sizeof(nums1)/sizeof(int), nums2, sizeof(nums2)/sizeof(int)));

    printf("2.Answer of 2-Q: %lf \n",
        findMedianSortedArrays(nums1_2, sizeof(nums1_2)/sizeof(int), nums2_2, sizeof(nums2_2)/sizeof(int)));
    return 0;
}