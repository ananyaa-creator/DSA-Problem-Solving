/*
==================================================
Problem:

Given a sorted array prices and a target price,
find the index where target should be inserted
to keep the array sorted.

If target already exists, return the index of its
FIRST occurrence.

Example:

Input:
prices = [10, 20, 20, 20, 30, 40]
target = 20

Output:
1

Explanation:
20 first appears at index 1.

Therefore, index 1 is the required insertion
position.

Approach:
Binary Search

We need the first index where:

    prices[i] >= target

This is exactly the Lower Bound condition.

If:

    prices[mid] >= target

then mid can be the answer.

However, there may be another occurrence of target
or a smaller valid insertion position on the left.

Therefore:

    ans = mid
    high = mid - 1

If:

    prices[mid] < target

then target must be inserted to the right.

Therefore:

    low = mid + 1

If every element is smaller than target, ans
will become n, meaning target should be inserted
at the end.

Time Complexity:
O(log n)

Space Complexity:
O(1)

Key Idea:

Search Insert Position with first occurrence
= Lower Bound

Lower Bound:
    First index where arr[i] >= target

Important:
Using >= instead of > ensures that when duplicate
target values exist, we return the FIRST occurrence.

Example:

[10, 20, 20, 20, 30]
     ^
     first occurrence = 1
==================================================
*/


class Solution {
public:
    int findInsertPosition(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        int ans = n;

        while (low <= high) {
            int mid = (low + high) / 2;

            if (nums[mid] >= target) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return ans;
    }
};


