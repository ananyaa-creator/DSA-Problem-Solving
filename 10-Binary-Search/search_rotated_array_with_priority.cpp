```cpp
/*
==================================================
Problem:

Given a rotated sorted array ids and a parallel
array priority, find the priority associated with
a given target ID.

If target does not exist, return -1.

The ids array:
- Was originally strictly increasing
- Has been rotated at some point
- Contains no duplicates

The priority array stores the priority corresponding
to each ID at the same index.

Example:

ids      = [9, 12, 17, 2, 4, 6, 8]
priority = [50, 10, 30, 90, 20, 60, 15]
target   = 4

4 is present at index 4.

Therefore:

priority[4] = 20

Output:
20

Approach:
Binary Search on a Rotated Sorted Array

At every step, one half of the array is guaranteed
to be sorted.

Check:

    if ids[low] <= ids[mid]

Then the LEFT half is sorted.

Otherwise, the RIGHT half is sorted.

Once we know which half is sorted, check whether
the target lies inside that sorted range.

If the target lies in the sorted half:
    search that half.

Otherwise:
    search the other half.

When:

    ids[mid] == target

we have found the ID.

Return:

    priority[mid]

No extra data structure is required because the
priority is stored at the same index as its ID.

Time Complexity:
O(log n)

Space Complexity:
O(1)

Key Idea:

Search the ID using binary search and use the same
index to access its corresponding priority.

    ids[mid] == target
          ↓
    return priority[mid]

Important:
The two arrays must remain parallel.

If:

    ids[i] = X

then:

    priority[i] = priority associated with X

==================================================
*/



class Solution {
public:
    int findPriority(vector<int>& ids, vector<int>& priority, int target){
        
        int n = ids.size();
        int low = 0;
        int high = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (ids[mid] == target)
                return priority[mid];

            // Left half is sorted
            if (ids[low] <= ids[mid]) {

                if (ids[low] <= target && target < ids[mid])
                    high = mid - 1;
                else
                    low = mid + 1;
            }

            // Right half is sorted
            else {

                if (ids[mid] < target && target <= ids[high])
                    low = mid + 1;
                else
                    high = mid - 1;
            }
        }

        return -1;
    }
};


