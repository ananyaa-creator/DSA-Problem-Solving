/*
Problem: Check if a Subsequence with Sum K Exists

Description:
Given an array nums and an integer k, determine whether
there exists a subsequence whose sum is exactly equal to k.

A subsequence is formed by selecting elements from the array
while maintaining their original relative order. We can either
pick or skip each element.

Return true if at least one valid subsequence exists;
otherwise, return false.

Approach:
1. Use recursion with the Pick and Not Pick technique.
2. Start with index = 0 and sum = 0.
3. For every element, consider two choices:

   Pick:
   - Include the current element in the subsequence.
   - Add nums[index] to the current sum.
   - Move to the next index.

   Not Pick:
   - Skip the current element.
   - Keep the sum unchanged.
   - Move to the next index.

4. Base Cases:
   - If sum == k, return true because the required sum
     has been achieved.
   - If index == nums.size(), return false because
     all elements have been processed.

5. Return the logical OR of the Pick and Not Pick calls.
   If either choice gives a valid subsequence, return true.

Time Complexity: O(2^n)
- Every element has two choices: Pick or Not Pick.
- Therefore, there can be up to 2^n possible subsequences.

Auxiliary Space Complexity: O(n)
- The maximum recursion depth is n.
- The recursion call stack requires O(n) space.

Example 1:
Input:
nums = {1, 2, 3, 4}
k = 5

Output: true

Explanation:
Valid subsequences include {1, 4} and {2, 3}.
Both have a sum equal to 5.

Example 2:
Input:
nums = {2, 4, 6}
k = 5

Output: false

Explanation:
No subsequence has a sum equal to 5.

Edge Cases:
1. Empty array.
2. Array containing only one element.
3. No subsequence has the required sum.
4. Entire array forms the required sum.
5. Target sum k = 0 (the empty subsequence has sum 0).

Note:
This implementation assumes all array elements and k are
non-negative. With negative elements, the early sum == k
base case must be removed because subsequent elements
can change the current sum.
*/


class Solution {
private:
    bool solve(int index, int sum, vector<int>& nums, int k) {

        // Base case: Required sum achieved
        if (sum == k) {
            return true;
        }

        // Base case: All elements have been processed
        if (index == nums.size()) {
            return false;
        }

        // Pick the current element
        bool pick = solve(index + 1, sum + nums[index], nums, k);

        // Do not pick the current element
        bool notPick = solve(index + 1, sum, nums, k);

        return pick || notPick;
    }

public:
    bool checkSubsequenceSum(vector<int>& nums, int k) {
        return solve(0, 0, nums, k);
    }
};
