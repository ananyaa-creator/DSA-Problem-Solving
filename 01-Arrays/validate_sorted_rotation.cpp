/*
Problem: Find Oldest Index in a Ring Buffer

Concepts:
- Rotated sorted arrays
- Array traversal
- Validation with duplicates

Description:
Given an array buf containing a rotation of a non-decreasing
array, find the index where the original sorted order begins.

Return:
- The index where the sorted order begins.
- 0 if the array is already non-decreasing.
- -1 if the array is not a valid rotation of a non-decreasing array.

Duplicates are allowed.

Example:
Input: buf = [6, 7, 9, 2, 2, 4]
Output: 3

Explanation:
Starting at index 3 and wrapping around gives:
[2, 2, 4, 6, 7, 9]

Approach:
1. Traverse the array and compare each element with the next.
2. Count every position where buf[i] > buf[(i + 1) % n].
3. If more than one such position exists, return -1.
4. If exactly one exists, return the index immediately after it.
5. If none exists, return 0.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int findOldestIndex(vector<int>& buf) {
        int n = buf.size();
        int dropIndex = -1;
        int drops = 0;

        for (int i = 0; i < n; i++) {
            if (buf[i] > buf[(i + 1) % n]) {
                drops++;

                if (drops > 1) {
                    return -1;
                }

                dropIndex = (i + 1) % n;
            }
        }

        return dropIndex == -1 ? 0 : dropIndex;
    }
};

