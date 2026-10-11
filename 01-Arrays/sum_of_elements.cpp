/*
Problem: Sum of Array Elements

Description:
Given an array arr of size n, find and return the sum
of all its elements.

Example 1:
Input:
n = 5
arr = [1, 2, 3, 4, 5]

Output: 15

Explanation:
1 + 2 + 3 + 4 + 5 = 15

Approach:
1. Initialize sum = 0.
2. Traverse the array using a loop.
3. Add each element to sum.
4. Return sum.

Time Complexity: O(n)
Space Complexity: O(1), excluding the input array.
*/


class Solution {
public:
    int arraySum(vector<int>& arr) {
        int sum = 0;

        for (int i = 0; i < arr.size(); i++) {
            sum += arr[i];
        }

        return sum;
    }
};

