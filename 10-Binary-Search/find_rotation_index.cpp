/*
==================================================
Problem:

Given a rotated sorted array of distinct integers,
find the index of the minimum element.

The original array was strictly increasing and was
rotated at an unknown pivot.

The index of the minimum element represents the
rotation/reset point.

Example:

Input:
temps = [7, 9, 12, 1, 3, 5]

Output:
3

Explanation:

The original sorted array was:

[1, 3, 5, 7, 9, 12]

After rotation:

[7, 9, 12, 1, 3, 5]
          ^
          |
       minimum

The minimum value 1 is at index 3.

Therefore, the rotation index is 3.


Approach:
Binary Search

We compare nums[mid] with nums[high].

If:

    nums[mid] > nums[high]

then the minimum must be in the RIGHT half.

Therefore:

    low = mid + 1

Otherwise:

    nums[mid] < nums[high]

The minimum could be at mid or somewhere in the
LEFT half.

Therefore:

    high = mid

Notice that we use:

    high = mid

instead of:

    high = mid - 1

because mid itself can be the minimum.

When low == high, we have found the minimum element.

Therefore:

    return low


Special Case:

If the array is not rotated:

    [1, 3, 5, 7, 9]

The minimum is at index 0.

The same binary search correctly returns 0.

Time Complexity:
O(log n)

Space Complexity:
O(1)

Key Idea:

For a rotated sorted array with DISTINCT values:

    nums[mid] > nums[high]
            ↓
    minimum is on the RIGHT

    nums[mid] < nums[high]
            ↓
    minimum is at mid or on the LEFT

==================================================
*/

class Solution{
public:
    int findRotationIndex(vector<int>& temps){
        int low = 0;
        int high = temps.size() - 1;

        while (low < high){
            int mid = low + (high - low) / 2;

            if (temps[mid] > temps[high]){
               low = mid + 1;
            }
            else{
                high = mid;
            }
        }
        return low;
    }
};

