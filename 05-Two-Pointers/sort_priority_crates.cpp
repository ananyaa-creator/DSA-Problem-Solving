/*
==================================================
Problem:
A warehouse conveyor holds crates tagged with
priority levels:
    1 = Urgent
    2 = Standard
    3 = Low

Given an array of crates in random order, rearrange
the array in-place so that all 1s come first,
followed by 2s, and then 3s.

Constraints:
- 1 <= crates.length <= 10^5
- crates[i] ∈ {1, 2, 3}
- Must be solved in one pass
- O(1) extra space
- No built-in sorting functions
- No counting arrays

Example:
Input:
[2, 1, 3, 3, 2, 1]

Output:
[1, 1, 2, 2, 3, 3]

Explanation:
Urgent (1) crates are placed at the beginning,
standard (2) crates in the middle, and low (3)
crates at the end.

Approach:
Use three pointers:
    low   -> position for 1
    mid   -> current element
    high  -> position for 3

If crates[mid] == 1:
    Swap it with crates[low] and move both low
    and mid forward.

If crates[mid] == 2:
    It is already in the correct region, so
    move mid forward.

If crates[mid] == 3:
    Swap it with crates[high] and move high
    backward. Do not immediately move mid because
    the swapped element still needs to be checked.

Time Complexity:
O(n)

Space Complexity:
O(1)

Key Idea:
Divide the array into three regions and use
three pointers to rearrange the elements in-place
in a single traversal.

This is commonly known as the Dutch National Flag
algorithm.
==================================================
*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
      int n = nums.size();
      int low =0,mid=0,high =n-1;
      while(mid<=high){
        if(nums[mid]==1){
            swap(nums[low],nums[mid]);
            low++;
            mid++;
        }
        else if(nums[mid]==2){
            mid++;
        }
        else{
            swap(nums[mid],nums[high]);
            high--;
        }
      }  
    }
};
