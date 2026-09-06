/*
==================================================
Problem:
Given an array of earnings and an integer d, count
the number of non-empty contiguous subarrays whose
sum is divisible by d.

A sum of zero is also considered divisible by d.

Constraints:
- 1 <= earnings.length <= 3 * 10^4
- -10^4 <= earnings[i] <= 10^4
- 1 <= d <= 10^4

Example:
Input:
earnings = [4, 5, 0, -2, -3, 1]
d = 5

Output:
7

Explanation:
The subarrays whose sums are divisible by 5 are:

[4, 5, 0, -2, -3]
[5]
[5, 0]
[5, 0, -2, -3]
[0]
[-2, -3]
[4, 5, 0, -2, -3, 1]

Total = 7

Approach:
Use prefix sums and a frequency array.

Let prefixSum be the sum of elements from the
beginning up to the current position.

For a subarray to have a sum divisible by d:

    (prefixSum[i] - prefixSum[j]) % d == 0

This means:

    prefixSum[i] % d == prefixSum[j] % d

Therefore, whenever the same remainder appears
again, all previous occurrences of that remainder
form a valid subarray ending at the current position.

Store the frequency of each remainder.

Important:
C++ can produce a negative remainder for negative
prefix sums, so normalize it using:

    remainder = (prefixSum % d + d) % d

Initialize frequency[0] = 1 because a prefix sum
whose remainder is 0 itself represents a valid
subarray starting from index 0.

Time Complexity:
O(n)

Space Complexity:
O(d)

Key Idea:
Two prefix sums with the same remainder when divided
by d have a difference that is divisible by d.

This converts the subarray-sum problem into a
remainder-frequency problem.
==================================================
*/

class Solution {
public:
    int countDivisibleSubarrays(vector<int>& earings, int k) {
        unordered_map<int,int> mpp;
        int n = earings.size();
        mpp[0]=1;
        int preSum = 0; 
        int cnt = 0;
        for(int i=0;i<n;i++){
            preSum += earings[i];
            int remove = ((preSum % k) + k) % k;
            cnt += mpp[remove];
            mpp[remove] += 1;
        }
        return cnt;
    }
};

