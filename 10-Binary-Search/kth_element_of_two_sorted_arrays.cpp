/*
Problem: Kth Element of Two Sorted Arrays

Concepts:
- Binary Search
- Partitioning Two Sorted Arrays
- Binary Search on Answers / Partitions

Description:
Given two sorted arrays a and b of sizes m and n,
find the kth element of the final sorted array.

k is 1-indexed.

Example 1:
Input:
a = {2, 3, 6, 7, 9}
b = {1, 4, 8, 10}
k = 5

Output: 6

Explanation:
Merged array = {1, 2, 3, 4, 6, 7, 8, 9, 10}
The 5th element is 6.

Approach: Binary Search on Partitions
1. Always binary-search the smaller array.
2. Choose how many elements to take from array a.
3. Take the remaining k - mid1 elements from array b.
4. Identify the left and right boundary values of both partitions.
5. If max(left boundaries) <= min(right boundaries),
   the kth element is max(left boundaries).
6. If the left partition of a is too large, move left.
   Otherwise, move right.

Time Complexity: O(log(min(m, n)))
Auxiliary Space Complexity: O(1)
*/

class Solution {
public:
    int kthElement(vector<int>& a, vector<int>& b, int k) {
        int n1 = a.size();
        int n2 = b.size();

        // Binary search on the smaller array.
        if (n1 > n2) {
            return kthElement(b, a, k);
        }

        // Number of elements selected from array a.
        int low = max(0, k - n2);
        int high = min(k, n1);

        while (low <= high) {
            int mid1 = low + (high - low) / 2;
            int mid2 = k - mid1;

            int l1 = (mid1 == 0) ? INT_MIN : a[mid1 - 1];
            int l2 = (mid2 == 0) ? INT_MIN : b[mid2 - 1];

            int r1 = (mid1 == n1) ? INT_MAX : a[mid1];
            int r2 = (mid2 == n2) ? INT_MAX : b[mid2];

            if (l1 <= r2 && l2 <= r1) {
                return max(l1, l2);
            }
            else if (l1 > r2) {
                high = mid1 - 1;
            }
            else {
                low = mid1 + 1;
            }
        }

        return -1; // Invalid k or invalid input.
    }
};

