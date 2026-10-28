```cpp
/*
Problem: Remove Duplicate Magnitudes In-Place

Concepts:
- Arrays
- Two Pointers
- In-place Modification
- Absolute Value

Description:
Given an array readings sorted in non-decreasing order of
absolute value, keep only the first reading for each distinct
magnitude, preserving the original order.

Modify the array in place and return k, the number of
kept elements. The first k positions must contain the result.

Example:
Input:
readings = {-1, -1, 1, 2, -2, 3, 3, -3, 5}

Output:
k = 4
readings = {-1, 2, 3, 5, ...}

Explanation:
Distinct magnitudes are 1, 2, 3, and 5.
The first occurrence of each magnitude is retained.

Approach: Two Pointers
1. Use write to track the next position for a unique magnitude.
2. Traverse the array from left to right.
3. Compare the absolute value of the current element with
   the absolute value of the last kept element.
4. If the magnitudes differ, keep the current element.
5. Return write, the number of kept elements.

Time Complexity: O(n)
Space Complexity: O(1)
*/


class Solution {
public:
    int removeDuplicateMagnitudes(vector<int>& readings) {
        int n = readings.size();

        if (n == 0) {
            return 0;
        }

        int write = 1;

        for (int read = 1; read < n; read++) {
            if (abs(readings[read]) != abs(readings[write - 1])) {
                readings[write] = readings[read];
                write++;
            }
        }

        return write;
    }
};

