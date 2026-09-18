/*
==================================================
Problem:

Given a rotated sorted array prices that may contain
duplicates, determine whether target exists in the
array.

The original array was sorted in non-decreasing order
and then rotated at an unknown pivot.

Example:

Input:
prices = [4, 4, 5, 6, 6, 7, 1, 2, 3, 4]
target = 3

Output:
true

Explanation:
3 exists at index 8.

Approach:
Binary Search on Rotated Sorted Array with Duplicates

Unlike the version without duplicates, duplicates can
make it impossible to determine which half is sorted.

For example:

    prices[low] == prices[mid] == prices[high]

In this situation, we cannot determine whether the
left or right half is sorted.

Therefore, safely remove the duplicate boundary
elements:

    low++;
    high--;

Then continue binary search.

Otherwise:

1. If left half is sorted:

       prices[low] <= prices[mid]

   Check whether target lies inside the left half.

2. Otherwise, the right half is sorted.

   Check whether target lies inside the right half.

Important:
Because duplicates are allowed, the worst-case
time complexity can become O(n).

Average case:
    O(log n)

Worst case:
    O(n)

Space Complexity:
    O(1)

Key Difference:

Rotated array WITHOUT duplicates:
    O(log n)

Rotated array WITH duplicates:
    Worst case O(n)

Why?

Duplicates can make it impossible to identify which
half is sorted.

==================================================
*/


class Solution {
public:
    bool priceExists(vector<int>& nums, int target) {
        int n = nums.size();

        int low = 0;
        int high = n - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            // Target found
            if (nums[mid] == target)
                return true;
            if(nums[low]==nums[mid]&&nums[mid]==nums[high]){
                low++;
                high--;
                continue;
            }

            // Left half is sorted
            if (nums[low] <= nums[mid]) {

                if (nums[low] <= target && target < nums[mid])
                    high = mid - 1;
                else
                    low = mid + 1;
            }

            // Right half is sorted
            else {

                if (nums[mid] < target && target <= nums[high])
                    low = mid + 1;
                else
                    high = mid - 1;
            }
        }

        return false;
    }
};
        


