/*
==================================================
Problem:

Given a sorted array nums and an integer x, find
the floor and ceil of x.

Floor:
    Largest element <= x

Ceil:
    Smallest element >= x

If floor or ceil does not exist, return -1.

Example:

Input:
nums = [3, 4, 4, 7, 8, 10]
x = 5

Output:
4 7

Explanation:

Floor of 5 = 4
Ceil of 5  = 7

Approach:
Binary Search

We can find both values in a single traversal.

For FLOOR:

We want the largest value <= x.

If:

    nums[mid] <= x

then nums[mid] is a possible floor.

But there might be a larger valid value on the
right.

Therefore:

    floor = nums[mid]
    low = mid + 1

If:

    nums[mid] > x

then nums[mid] is too large, so search left.

    high = mid - 1


For CEIL:

We want the smallest value >= x.

If:

    nums[mid] >= x

then nums[mid] is a possible ceil.

But there might be a smaller valid value on the
left.

Therefore:

    ceil = nums[mid]
    high = mid - 1

If:

    nums[mid] < x

then nums[mid] is too small, so search right.

    low = mid + 1

Time Complexity:
O(log n)

Space Complexity:
O(1)

Key Ideas:

Floor:
    Last index where nums[i] <= x

Ceil:
    First index where nums[i] >= x

Notice the connection with previous problems:

Lower Bound:
    First element >= x

Floor:
    Last element <= x

Ceil:
    First element >= x
    (same condition as Lower Bound)

==================================================
*/



class Solution {
public:
    vector<int> getFloorAndCeil(vector<int> nums, int x) {
        int n = nums.size();
        
        int low = 0;
        int high = n - 1;
        
        int floor = -1;
        int ceil = -1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (nums[mid] == x) {
                floor = nums[mid];
                ceil = nums[mid];
                break;
            }
            
            else if (nums[mid] < x) {
                floor = nums[mid];
                low = mid + 1;
            }
            
            else {
                ceil = nums[mid];
                high = mid - 1;
            }
        }
        
        return {floor, ceil};
    }
};

