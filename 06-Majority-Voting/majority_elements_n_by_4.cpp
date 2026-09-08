/*
==================================================
Problem:
Given an array of jersey numbers representing
votes, return all numbers that appear more than
n/4 times.

There can be at most 3 such elements.

The solution must use O(n) time and O(1) extra
space, excluding the output array.

Constraints:
- 1 <= votes.length <= 5 * 10^4
- -10^9 <= votes[i] <= 10^9

Example:
Input:
votes = [1, 2, 2, 3, 2, 1, 1, 3, 3, 1]

Output:
[1, 2, 3]

Explanation:
n = 10
n / 4 = 2.5

Frequency:
1 -> 4 times  -> qualifies
2 -> 3 times  -> qualifies
3 -> 3 times  -> qualifies

Therefore:
[1, 2, 3]

Approach:
Use the generalized Moore's Voting Algorithm.

For elements appearing more than n/4 times, there
can be at most 3 valid candidates.

Maintain:
    candidate1, candidate2, candidate3
    count1, count2, count3

During the first pass, identify possible candidates.

If the current number matches a candidate,
increase its count.

If an empty candidate slot exists, assign the
current number to it.

Otherwise, decrease all three counts.

After the first pass, the candidates are only
POSSIBLE candidates.

Perform a second pass to count their actual
frequencies and verify whether each appears more
than n/4 times.

Time Complexity:
O(n)

Space Complexity:
O(1) excluding the output array.

Key Idea:
For a threshold of n/k, there can be at most
k - 1 elements satisfying the condition.

Therefore:
    More than n/2  -> 1 candidate
    More than n/3  -> 2 candidates
    More than n/4  -> 3 candidates
    More than n/5  -> 4 candidates

This is the generalized form of Moore's Voting
Algorithm.
==================================================
*/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int cnt1 = 0, cnt2 = 0, cnt3 = 0;
        int el1 = INT_MIN, el2 = INT_MIN, el3 = INT_MIN;

        // Phase 1: find up to 3 candidates
        for (int i = 0; i < n; i++) {
            if (cnt1 == 0 && el2 != nums[i] && el3 != nums[i]) {
                cnt1 = 1; el1 = nums[i];
            }
            else if (cnt2 == 0 && el1 != nums[i] && el3 != nums[i]) {
                cnt2 = 1; el2 = nums[i];
            }
            else if (cnt3 == 0 && el1 != nums[i] && el2 != nums[i]) {
                cnt3 = 1; el3 = nums[i];
            }
            else if (nums[i] == el1) cnt1++;
            else if (nums[i] == el2) cnt2++;
            else if (nums[i] == el3) cnt3++;
            else {
                cnt1--; cnt2--; cnt3--;
            }
        }

        // Phase 2: verify actual counts
        int verifyCnt1 = 0, verifyCnt2 = 0, verifyCnt3 = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == el1) verifyCnt1++;
            else if (nums[i] == el2) verifyCnt2++;
            else if (nums[i] == el3) verifyCnt3++;
        }

        int threshold = n / 4 + 1;
        vector<int> result;
        if (verifyCnt1 >= threshold) result.push_back(el1);
        if (verifyCnt2 >= threshold) result.push_back(el2);
        if (verifyCnt3 >= threshold) result.push_back(el3);

        sort(result.begin(), result.end());
        return result;
    }
};
