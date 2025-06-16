/*
Name: Blaine Swieder
LeetCode (C): Maximum Difference between Increasing Elements
Date: June 16th, 2025
*/

#include <stdio.h>

// Function prototype 
int maximumDifference(int* nums, int numsSize);

int main() {
    int nums1[] = {7, 1, 5, 4};
    int nums2[] = {9, 4, 3, 2};
    int nums3[] = {1, 5, 2, 10};

    printf("Example 1 Output: %d\n", maximumDifference(nums1, 4)); // Output: 4
    printf("Example 2 Output: %d\n", maximumDifference(nums2, 4)); // Output: -1
    printf("Example 3 Output: %d\n", maximumDifference(nums3, 4)); // Output: 9

    return 0;
}

// Define the function after main
int maximumDifference(int* nums, int numsSize) {
    int minVal = nums[0];
    int maxDiff = -1;
    int i;

    for (i = 1; i < numsSize; i++) {
        if (nums[i] > minVal) {
            int diff = nums[i] - minVal;
            if (diff > maxDiff) {
                maxDiff = diff;
            }
        } else {
            minVal = nums[i];
        }
    }

    return maxDiff;
}










