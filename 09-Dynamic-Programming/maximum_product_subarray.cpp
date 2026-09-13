/*
==================================================
Problem:

Given an array of daily return multipliers, find
the maximum product of any non-empty contiguous
subarray.

The array can contain:
- Positive values
- Negative values
- Zero

Constraints:
- 1 <= n <= 2 * 10^4
- -10 <= nums[i] <= 10
- nums[i] can be 0
- Answer fits within the required range

Example:

Input:
[1.5, -2, 0.5, -3, 1]

Output:
4.5

Explanation:

The subarray:

[1.5, -2, 0.5, -3]

has product:

1.5 * (-2) * 0.5 * (-3) = 4.5

Approach:
Dynamic Programming

At every index, maintain two values:

    maxProd = maximum product of a subarray
              ending at the current index

    minProd = minimum product of a subarray
              ending at the current index

We need both because multiplying by a negative
number can turn the minimum product into the
maximum product.

Example:

    minProd = -6
    current = -2

    -6 * -2 = 12

So the previous minimum becomes useful when the
current number is negative.

If nums[i] is negative, swap maxProd and minProd
before updating them.

Then:

    maxProd = max(nums[i], maxProd * nums[i])

    minProd = min(nums[i], minProd * nums[i])

The global answer is the maximum maxProd obtained
during the traversal.

Zero:
Zero automatically breaks the previous product
chain. The next element can start a new subarray.

Time Complexity:
O(n)

Space Complexity:
O(1)

Key Idea:
Maximum Product Subarray is solved using Dynamic
Programming by maintaining BOTH the maximum and
minimum product ending at every position.

This is NOT the standard Kadane's Algorithm.

Standard Kadane's:
    Maximum Sum Subarray

This problem:
    Maximum Product Subarray
    -> Dynamic Programming
    -> Track maximum + minimum
==================================================
*/

class Solution {
public:
    double maxReturn(vector<double>& nums) {
    int n = nums.size();
    double pre = 1, suff = 1;
    double ans = -1e18;
    for (int i = 0; i < n; i++) {
        if (pre == 0) pre = 1;
        if (suff == 0) suff = 1;
        pre *= nums[i];
        suff *= nums[n-i-1];
        ans = max(ans, max(pre, suff));
    }
    return ans;
}
};

