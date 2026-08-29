```cpp
/*
==================================================
Problem:
Given an array `prices` where each element represents
the profit or loss of a trade, find the maximum sum
of any contiguous subarray whose length is at most k.

Also return the length of the subarray that produces
this maximum sum.

Constraints:
- 1 <= prices.length <= 10^5
- -10^4 <= prices[i] <= 10^4
- 1 <= k <= prices.length

Example:
Input:
prices = [2, -1, 3, -4, 5, -2, 6]
k = 3

Output:
(9, 3)

Explanation:
The subarray [5, -2, 6] has:
5 + (-2) + 6 = 9

Its length is 3, which is within the allowed limit.

Approach:
1. Build a prefix sum array.

   prefix[i] = sum of the first i elements.

2. The sum of subarray [j, i-1] is:

   prefix[i] - prefix[j]

3. For a subarray of length <= k:

   i - j <= k

   Therefore:

   j >= i - k

4. For every ending position i, we need the smallest
   prefix[j] among the valid range of j values.

5. Use a monotonic deque to maintain indices of prefix
   sums in increasing order.

6. The front of the deque always gives the smallest
   valid prefix sum, allowing us to calculate the
   maximum subarray sum efficiently.

Time Complexity:
O(n)

Space Complexity:
O(n)

Key Idea:
Prefix sums convert subarray-sum calculation into a
difference of two prefix sums.

A monotonic deque efficiently maintains the minimum
prefix sum among the previous k valid positions.
==================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    pair<int,int> maxBoundedSubarray(vector<int>& prices, int k) {
        // returns {max_sum, length_of_subarray}
        
        int n = prices.size();

        // Prefix sum
        vector<long long> prefix(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + prices[i];
        }

        deque<int> dq;

        long long maximum = LLONG_MIN;
        int bestLength = 0;

        // prefix[j] - prefix[i]
        // length = j - i
        for (int j = 0; j <= n; j++) {

            // Remove indices that make length > k
            while (!dq.empty() && dq.front() < j - k) {
                dq.pop_front();
            }

            // Calculate maximum sum using the smallest prefix
            if (!dq.empty()) {
                long long currentSum = prefix[j] - prefix[dq.front()];
                int currentLength = j - dq.front();

                if (currentSum > maximum) {
                    maximum = currentSum;
                    bestLength = currentLength;
                }
            }

            // Maintain increasing prefix sums
            while (!dq.empty() && prefix[dq.back()] >= prefix[j]) {
                dq.pop_back();
            }

            dq.push_back(j);
        }

        return {(int)maximum, bestLength};
    }
};
