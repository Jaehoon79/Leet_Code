#include <stdio.h>
#include <stdlib.h>

#if 0
int search(int* nums, int numsSize, int target) {
    int upper = numsSize -1;
    int lower = 0;

    while (lower <= upper) {
        int mid = (int)(upper + lower)/2;

        if (nums[mid] == target)
            return mid;
        else {
            if (nums[mid] > target)
                upper = mid - 1;
            else
                lower = mid + 1;
        }
    }
    return -1;
}
#endif

int search(int* nums, int numsSize, int target) {
    int high = numsSize -1;
    int low = 0;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (target == nums[mid]) return mid;
        if (target > nums[mid]) low = mid + 1;
        else high = mid -1;
    }
    return -1;
}

int main() {
    int nums[] = {-1,0,3,5,9,12};
    int target1 = 9, target2 = 2;

    printf("1. Answer of Q: %d\n", search(nums, 6, target1));
    printf("2. Answer of Q: %d\n", search(nums, 6, target2));

    return 0;
}