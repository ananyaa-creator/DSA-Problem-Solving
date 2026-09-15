/*
==================================================
Problem:

Given a sorted array nums and an integer x, find
the upper bound of x.

Upper Bound is the first and smallest index i such
that:

    nums[i] > x

If no such index exists, return the size of the
array.

Example:

Input:
nums = [1, 2, 2, 3]
x = 2

Output:
3

Explanation:

nums[0] = 1 <= 2
nums[1] = 2 <= 2
nums[2] = 2 <= 2
nums[3] = 3 > 2

Therefore, index 3 is the upper bound.

Approach:
Binary Search

Maintain:

    low = 0
    high = n - 1
    ans = n

We initialize ans to n because if no element is
greater than x, the answer should be n.

If:

    nums[mid] > x

then mid is a possible answer.

But there may be another valid index on the left.

Therefore:

    ans = mid
    high = mid - 1

If:

    nums[mid] <= x

then nums[mid] cannot be the answer.

Because the array is sorted, all elements to the
left are also <= x.

Therefore:

    low = mid + 1

Time Complexity:
O(log n)

Space Complexity:
O(1)

Key Difference:

Lower Bound:
    First index where nums[i] >= x

Upper Bound:
    First index where nums[i] > x

Lower Bound condition:
    nums[mid] >= x

Upper Bound condition:
    nums[mid] > x
==================================================
*/

class Solution{
public:
    int upperBound(vector<int> &nums, int x){
        int n = nums.size();
        int ans = n;
        int low = 0;
        int high = n-1;
        while(low<=high){
            int mid = (low+high)/2 ;
            if(nums[mid]>x){
                ans = mid;
                high = mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;

    }
};
