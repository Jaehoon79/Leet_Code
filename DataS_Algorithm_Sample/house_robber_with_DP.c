#include <stdio.h>
#include <string.h>

int dp_proc(int *nums, int *status_stash, int numsSize)
{
    int dp_1 = 0, dp_2 = 0;

    // Pre-processing: Just for checking
    // the number of houses
    if (numsSize == 0)
        return nums[0];
    if (numsSize == 1)
        return (nums[0] > nums[1])?nums[0]:nums[1];

    if (status_stash[numsSize] == -1) {
        dp_1 = dp_proc(nums, status_stash, numsSize - 1);
        dp_2 = (dp_proc(nums, status_stash, numsSize -2) + nums[numsSize]);
        status_stash[numsSize] = (dp_1 > dp_2)?dp_1:dp_2;
    }
    
    return status_stash[numsSize];
}

int rob(int* nums, int numsSize)
{
    int status_stash[numsSize];

    memset(status_stash, -1, numsSize * sizeof(int));
    
    return dp_proc (nums, status_stash, numsSize -1);
}

int main()
{
    int input_1[] = {1, 2, 3, 1};
    int input_2[] = {2, 7, 9, 3, 1};

    int output_1 = 0, output_2 = 0;

    output_1 = rob(input_1, sizeof(input_1)/sizeof(input_1[0]));
    output_2 = rob(input_2, sizeof(input_2)/sizeof(input_2[0]));

    printf("TEST Result 1: %d, Result 2: %d \n", output_1, output_2);

    return 0;
}