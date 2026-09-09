/*
==================================================
Problem:
Given an array of package weights and a target
capacity, find all unique combinations of exactly
4 values whose sum is equal to the target.

The same combination of values must not appear more
than once in the output.

Constraints:
- 1 <= weights.length <= 200
- -10^9 <= weights[i] <= 10^9
- -10^9 <= target <= 10^9
- Duplicate combinations are not allowed.

Example:
Input:
weights = [2, 2, 2, 2, 2]
target = 8

Output:
[[2, 2, 2, 2]]

Explanation:
Any 4 selected values are:
2 + 2 + 2 + 2 = 8

Although there are multiple ways to choose indices,
they represent the same combination of values, so
only one result is returned.

Approach:
1. Sort the array.
2. Fix the first element using index i.
3. Fix the second element using index j.
4. Use two pointers:
       left  = j + 1
       right = n - 1
5. Calculate the sum of the four elements.
6. If sum == target:
       Store the combination.
       Move both pointers.
       Skip duplicate values.
7. If sum < target:
       Move left forward.
8. If sum > target:
       Move right backward.

Duplicate values are skipped at every fixed position
so that the same combination is not added multiple
times.

Time Complexity:
O(n^3)

Space Complexity:
O(1) auxiliary space
(excluding the output array and sorting implementation).

Key Idea:
After fixing two elements, the remaining problem
becomes a Two-Sum problem that can be solved using
two pointers on the sorted array.

This is the 4-Sum extension of the 3-Sum pattern.
==================================================
*/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            for(int j=i+1;j<n;j++){
                if(j!=(i+1) && nums[j]==nums[j-1]) continue;
                int k = j+1;
                int l = n-1;
                while(k<l){
                    long long sum = nums[i];
                    sum += nums[j];
                    sum += nums[k];
                    sum += nums[l];
                    if(sum == target){
                        vector<int> temp = {nums[i],nums[j],nums[k],nums[l]};
                        ans.push_back(temp);
                        k++;
                        l--;
                        while(k<l && nums[k]==nums[k-1]) k++;
                        while(k<l && nums[l]==nums[l+1]) l--;
                    }
                    else if(sum<target) k++;
                    else l--;
                }
            }
        }
        return ans;
    }
};

