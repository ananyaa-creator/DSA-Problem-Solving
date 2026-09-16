/*
==================================================
Problem:

Given a sorted array checkins and a target time t,
find the first and last index where t occurs.

If t does not exist in the array, return {-1, -1}.

Example:

Input:
checkins = [420, 420, 480, 480, 480, 540]
t = 480

Output:
[2, 4]

Explanation:
480 first appears at index 2
480 last appears at index 4

Approach:
Binary Search

We perform TWO binary searches:

1. Find the FIRST occurrence
2. Find the LAST occurrence

FIRST OCCURRENCE:

If:

    nums[mid] == target

then mid is a possible first occurrence.

Store it and continue searching LEFT:

    ans = mid
    high = mid - 1

If nums[mid] < target:
    search right

If nums[mid] > target:
    search left


LAST OCCURRENCE:

If:

    nums[mid] == target

then mid is a possible last occurrence.

Store it and continue searching RIGHT:

    ans = mid
    low = mid + 1

If nums[mid] < target:
    search right

If nums[mid] > target:
    search left

Time Complexity:
O(log n)

Space Complexity:
O(1)

Key Idea:

First occurrence:
    When target is found, move LEFT.

Last occurrence:
    When target is found, move RIGHT.

This is closely related to:

Lower Bound:
    First index where nums[i] >= target

Upper Bound:
    First index where nums[i] > target

Another way to find the range is:

    first = lowerBound(nums, target)

    last = upperBound(nums, target) - 1

provided that first exists.

==================================================
*/

class Solution {
public:
    vector<int> checkin_range(vector<int>& nums, int target) {
        int n = nums.size();

        int first = -1;
        int last = -1;

        // Find first occurrence
        int low = 0, high = n - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                first = mid;
                high = mid - 1;   // search on left
            }
            else if (nums[mid] < target) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        // Find last occurrence
        low = 0;
        high = n - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                last = mid;
                low = mid + 1;    // search on right
            }
            else if (nums[mid] < target) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return {first, last};
    }
};

