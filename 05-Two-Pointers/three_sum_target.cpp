/*
==================================================
Problem:
Given an array of item weights and a target
capacity, find all unique triplets whose sum is
exactly equal to the target.

The order of elements within a triplet does not
matter, and duplicate triplets must not be included.

Constraints:
- 3 <= weights.length <= 3000
- -10^5 <= weights[i] <= 10^5
- -10^5 <= target <= 10^5

Example:
Input:
weights = [4, -1, 3, 0, -2, 1]
target = 2

Output:
[
    [-2, -1, 5],
    [-2, 0, 4],
    [-2, 1, 3],
    [-1, 0, 3]
]

Note:
For the given input, [-2, -1, 5] is NOT a valid
triplet because 5 is not present in the array.

Therefore, the correct output is:

[
    [-2, 0, 4],
    [-2, 1, 3],
    [-1, 0, 3]
]

Explanation:
- -2 + 0 + 4 = 2
- -2 + 1 + 3 = 2
- -1 + 0 + 3 = 2

Approach:
1. Sort the array.
2. Fix one element using index i.
3. Use two pointers:
       left  = i + 1
       right = n - 1
4. Calculate the sum of the three elements.
5. If sum == target:
       Store the triplet.
       Move both pointers.
       Skip duplicate values.
6. If sum < target:
       Move left forward.
7. If sum > target:
       Move right backward.

Sorting allows the two-pointer technique to
efficiently find the required pair and also makes
duplicate removal straightforward.

Time Complexity:
O(n^2)

Space Complexity:
O(1) auxiliary space
(excluding the output array and sorting implementation
details).

Key Idea:
After fixing one element, the remaining problem
becomes a two-sum problem on a sorted array.

Duplicate values are skipped so that every unique
triplet appears only once.
==================================================
*/


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector <vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            int j = i+1;
            int k = n-1;
            while(j<k){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum < target){
                    j++;
                }
                else if(sum>target){
                    k--;
                }
                else{
                    vector<int> temp = {nums[i],nums[j],nums[k]};
                    ans.push_back(temp);
                    j++;
                    k--;
                    while(j<k && nums[j]==nums[j-1]) j++;
                    while(j<k && nums[k]==nums[k+1]) k--;
                }
            }
        }
        return ans;
    }
};

