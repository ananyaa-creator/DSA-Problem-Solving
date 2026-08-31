/*
==================================================
Problem:
Given an array of temperature deviations containing
an equal number of positive and negative values,
reorder the array so that positive and negative
values alternate, starting with a positive value.

The relative order of positive values and the
relative order of negative values must be preserved.

Constraints:
- 2 <= deviations.length <= 2 * 10^5
- Array length is even
- Equal number of positive and negative values
- No zeros
- -10^5 <= deviations[i] <= 10^5

Example:
Input:
[3, -1, -2, 5, -7, 4]

Output:
[3, -1, 5, -2, 4, -7]

Explanation:
Positive values in original order:
[3, 5, 4]

Negative values in original order:
[-1, -2, -7]

Alternating them starting with positive:
[3, -1, 5, -2, 4, -7]

Approach:
Create a separate answer array.

Use:
    posIndex = 0
    negIndex = 1

Positive values are placed at even indices:
    0, 2, 4, ...

Negative values are placed at odd indices:
    1, 3, 5, ...

Since we traverse the original array from left to
right, the relative order of positive values and
negative values is automatically preserved.

Time Complexity:
O(n)

Space Complexity:
O(n)

Key Idea:
Use separate positions for positive and negative
values while traversing the original array once.
==================================================
*/

class Solution {
public:
    vector<int> reorder_deviations(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,0);
        int posIndex = 0;
        int negIndex = 1;
        for(int i=0;i<n;i++){
            if(nums[i]<0){
                ans[negIndex]=nums[i];
                negIndex+=2;
            }
            else{
                ans[posIndex]=nums[i];
                posIndex+=2;
            }
        }
        return ans;
    }
};


