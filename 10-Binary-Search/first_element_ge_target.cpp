/*
==================================================
Problem:

Given a sorted array capacities and a target value,
find the smallest index whose value is greater than
or equal to the target.

If no such element exists, return -1.

The array is sorted in non-decreasing order, so
duplicate values are allowed.

Constraints:
- 1 <= capacities.length <= 10^5
- capacities is sorted in ascending order
- Duplicate values are allowed
- -10^4 <= capacities[i], target <= 10^4

Example:

Input:
capacities = [10, 10, 15, 20, 25]
target = 16

Output:
3

Explanation:

capacities[0] = 10  < 16
capacities[1] = 10  < 16
capacities[2] = 15  < 16
capacities[3] = 20 >= 16

Therefore, the first valid index is 3.

Approach:
Binary Search — Lower Bound

We need the FIRST element satisfying:

    capacities[i] >= target

Whenever:

    capacities[mid] >= target

mid is a possible answer, but there might be another
valid element on the left.

Therefore:
    ans = mid
    high = mid - 1

If:

    capacities[mid] < target

then mid and everything to its left are too small.

Therefore:
    low = mid + 1

If no valid element is found, ans remains -1.

Time Complexity:
O(log n)

Space Complexity:
O(1)

Key Idea:
This is the Lower Bound pattern.

Lower Bound:
    First index i such that
    arr[i] >= target

Related Binary Search patterns:

1. Exact Search
   -> Find target

2. Lower Bound
   -> First element >= target

3. Upper Bound
   -> First element > target

4. Last occurrence
   -> Find the rightmost target

Important:
When a valid answer is found, do NOT stop.
Continue searching on the left to find the
smallest valid index.
==================================================
*/

class Solution {
public:
    int search(vector<int>& capacities, int target) {
        int low = 0;
        int high = capacities.size() - 1;
        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (capacities[mid] >= target) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};

