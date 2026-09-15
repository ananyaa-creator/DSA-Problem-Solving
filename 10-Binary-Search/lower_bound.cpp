/*
==================================================
Problem:

Given a sorted array nums and an integer x, find
the lower bound of x.

Lower Bound is the first and smallest index i such
that:

    nums[i] >= x

If no such index exists, return the size of the
array.

Constraints:
- nums is sorted in non-decreasing order
- Duplicate values are allowed

Example:

Input:
nums = [1, 2, 2, 3]
x = 2

Output:
1

Explanation:

nums[0] = 1 < 2
nums[1] = 2 >= 2

Therefore, index 1 is the first valid index.

Approach:
Binary Search

Maintain:

    low = 0
    high = n - 1
    ans = n

We initialize ans to n because if no element
satisfies nums[i] >= x, the required answer is n.

If:

    nums[mid] >= x

then mid is a possible answer.

But there may be another valid index on the left.

Therefore:

    ans = mid
    high = mid - 1

If:

    nums[mid] < x

then mid cannot be the answer, and because the
array is sorted, no element to its left can be
the answer either.

Therefore:

    low = mid + 1

Time Complexity:
O(log n)

Space Complexity:
O(1)

Key Idea:

Lower Bound = first index where:

    nums[index] >= x

Template:

    if (nums[mid] >= x)
    {
        ans = mid;
        high = mid - 1;
    }
    else
    {
        low = mid + 1;
    }

Difference from "first element >= target" variation:
- Lower Bound problem -> return n if not found
- Search-style problem -> may return -1 if not found
==================================================
*/
class Solution{
public:
    int lowerBound(vector<int> &nums, int x){
        int n = nums.size();
        int ans = n;
        int low = 0;
        int high = n-1;
        while(low<=high){
            int mid = (low+high)/2 ;
            if(nums[mid]>=x){
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
