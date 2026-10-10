/*
Problem: Intersection of Two Sorted Arrays

Description:
Given two sorted arrays nums1 and nums2, return their intersection.
Each element must appear min(x, y) times, where x and y are
its frequencies in nums1 and nums2, respectively.

Example 1:
Input:
nums1 = [1, 2, 2, 3]
nums2 = [2, 2, 4]

Output: [2, 2]

Example 2:
Input:
nums1 = [1, 2, 3, 4]
nums2 = [2, 4, 6]

Output: [2, 4]

Approach: Two Pointers
1. Initialize pointers i and j at the beginning of both arrays.
2. If nums1[i] == nums2[j], add the element to the result
   and increment both pointers.
3. If nums1[i] < nums2[j], increment i.
4. Otherwise, increment j.
5. Continue until either array is exhausted.

Time Complexity: O(n + m)
Space Complexity: O(k) for the result, excluding input arrays,
where k is the size of the intersection.
*/

class Solution {
public:
    vector<int> intersectionArray(vector<int>& nums1, vector<int>& nums2) {
         vector<int> ans;
        int i = 0, j = 0;

        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] == nums2[j]) {
                ans.push_back(nums1[i]);
                i++;
                j++;
            }
            else if (nums1[i] < nums2[j]) {
                i++;
            }
            else {
                j++;
            }
        }

        return ans;
    }
};
