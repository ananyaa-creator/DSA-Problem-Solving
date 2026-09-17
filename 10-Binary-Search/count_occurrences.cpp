/*
==================================================
Problem:

Given a sorted array arr and an integer target,
find the number of times target appears in arr.

Example:

Input:
arr = [0, 0, 1, 1, 1, 2, 3]
target = 1

Output:
3

Explanation:
The first occurrence of 1 is at index 2.
The last occurrence of 1 is at index 4.

Therefore:

    Count = last - first + 1
          = 4 - 2 + 1
          = 3

Approach:
Binary Search

Since the array is sorted, we can find:

1. First occurrence of target
2. Last occurrence of target

Then:

    count = last - first + 1

If target does not exist:

    return 0

Time Complexity:
O(log n)

Space Complexity:
O(1)

Alternative approach:

Using Lower Bound and Upper Bound:

    first = lowerBound(arr, target)
    last  = upperBound(arr, target)

Then:

    count = upperBound - lowerBound

because:

    upperBound = first index where arr[i] > target

==================================================
*/


class Solution {
public:
    int countOccurrences(vector<int>& arr, int target) {
        int n = arr.size();

        // Find first occurrence
        int low = 0, high = n - 1;
        int first = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] == target) {
                first = mid;
                high = mid - 1;   // search left
            }
            else if (arr[mid] < target) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        // Target not present
        if (first == -1)
            return 0;

        // Find last occurrence
        low = 0;
        high = n - 1;
        int last = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] == target) {
                last = mid;
                low = mid + 1;    // search right
            }
            else if (arr[mid] < target) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return last - first + 1;
    }
};
