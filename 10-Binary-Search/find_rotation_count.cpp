/*
==================================================
Problem:

Given an array nums of distinct integers that was
originally sorted in ascending order and then
RIGHT rotated between 0 and n-1 times, find the
number of rotations.

The number of right rotations is equal to the
index of the minimum element.

Example:

Input:
nums = [4, 5, 6, 7, 0, 1, 2, 3]

Original:
[0, 1, 2, 3, 4, 5, 6, 7]

After 4 right rotations:
[4, 5, 6, 7, 0, 1, 2, 3]

Minimum element = 0
Index of minimum = 4

Therefore:

Output = 4


Approach:
Binary Search

We need to find the index of the minimum element.

Compare nums[mid] with nums[high].

If:

    nums[mid] > nums[high]

then the minimum must be in the RIGHT half.

Therefore:

    low = mid + 1

Otherwise:

    nums[mid] < nums[high]

The minimum is at mid or somewhere in the
LEFT half.

Therefore:

    high = mid

When:

    low == high

we have found the minimum element.

Its index is also the number of RIGHT rotations.

Special Case:

If the array is already sorted:

    [0, 1, 2, 3, 4]

the minimum is at index 0.

Therefore:

    rotations = 0

Time Complexity:
O(log n)

Space Complexity:
O(1)

Key Idea:

For a right-rotated sorted array:

    number of rotations
            =
    index of minimum element

==================================================
*/

class Solution {
public:
    int findKRotation(vector<int> &nums) {
        int n = nums.size();
        int low = 0, high = n - 1;
        int index = 0;

        while (low <= high) {
            // If the current search space is already sorted
            if (nums[low] <= nums[high]) {
                index = low;
                break;
            }

            int mid = low + (high - low) / 2;

            // Left half is sorted
            if (nums[low] <= nums[mid]) {
                // Minimum can be at low
                if (nums[low] < nums[index] || low == 0)
                    index = low;

                low = mid + 1;
            }
            // Right half is sorted
            else {
                // Minimum can be at mid
                if (nums[mid] < nums[index] || index == 0)
                    index = mid;

                high = mid - 1;
            }
        }

        return index;
    }
};


