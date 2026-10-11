/*
Problem: Count Odd Elements in an Array

Description:
Given an array of n elements, return the count of odd numbers
present in the array.

Example 1:
Input:
n = 5
arr = [1, 2, 3, 4, 5]

Output: 3

Explanation:
The odd elements are 1, 3, and 5.

Approach:
1. Initialize count = 0.
2. Traverse every element of the array.
3. If arr[i] % 2 != 0, increment count.
4. Return count.

Time Complexity: O(n)
Space Complexity: O(1), excluding the input array.
*/


class Solution {
public:
    int countOdd(vector<int>& arr) {
        int count = 0;

        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] % 2 != 0) {
                count++;
            }
        }

        return count;
    }
};

