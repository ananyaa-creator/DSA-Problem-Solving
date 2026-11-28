/*
Problem: Subset Sums

Description:
Given an array of integers nums of size N, find the sum of
every possible subset of the array.

Return a vector containing all the subset sums in
non-decreasing (sorted) order.

A subset is formed by selecting or not selecting each
element of the array. The order of elements does not matter.

Approach:
1. Use recursion with the Include and Exclude technique.
2. Maintain three parameters:
   - i: Current index in the array.
   - sum: Sum of the elements selected so far.
   - sumSub: Vector storing all subset sums.

3. Base Case:
   - If i == N, all elements have been considered.
   - Store the current sum in sumSub.
   - Return from the recursive function.

4. Recursive Calls:
   Include:
   - Select the current element.
   - Add arr[i] to the current sum.
   - Move to the next index.

   Exclude:
   - Skip the current element.
   - Keep the current sum unchanged.
   - Move to the next index.

5. Repeat the process until all possible subsets
   have been explored.

6. Sort the sumSub vector in ascending order.
7. Return the sorted vector.

Time Complexity: O(2^N * log(2^N))
- There are 2^N possible subsets.
- Each subset sum is calculated once.
- Sorting 2^N sums takes O(2^N * log(2^N)) time.

Auxiliary Space Complexity: O(N)
- Recursion depth is at most N.
- The recursion call stack requires O(N) space.

Output Space Complexity: O(2^N)
- There are 2^N possible subsets.
- Therefore, 2^N subset sums are stored.

Example 1:
Input:
nums = {2, 3}

Output:
{0, 2, 3, 5}

Explanation:
All possible subsets are:
{}       -> 0
{2}      -> 2
{3}      -> 3
{2, 3}   -> 5

After sorting, the subset sums are:
{0, 2, 3, 5}

Example 2:
Input:
nums = {1, 2, 3}

Output:
{0, 1, 2, 3, 3, 4, 5, 6}

Explanation:
There are 2^3 = 8 possible subsets, including
the empty subset.

Edge Cases:
1. Empty array: Returns {0}.
2. Array containing one element.
3. Array containing all zeroes.
4. Array containing duplicate elements.
5. Array containing negative elements.

Important Concepts:
1. Recursion
2. Include / Exclude technique
3. Subsets
4. Backtracking
5. Sorting
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void func(int i, int sum, vector<int>& arr, int N,
              vector<int>& sumSub) {
        if (i == N) {
            sumSub.push_back(sum);
            return;
        }
        func(i + 1, sum + arr[i], arr, N, sumSub);
        func(i + 1, sum, arr, N, sumSub);
    }

public:
    vector<int> subsetSums(vector<int>& nums) {
        vector<int> sumSubset;

        func(0, 0, nums, nums.size(), sumSubset);

        sort(sumSubset.begin(), sumSubset.end());

        return sumSubset;
    }
};

