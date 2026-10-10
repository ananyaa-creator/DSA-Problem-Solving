/*
Problem: Count Odd Digits

Description:
Given an integer n, return the number of odd digits present in n.
The number has no leading zeroes, except when n itself is 0.

Examples:
Input: n = 5
Output: 1
Explanation: The digit 5 is odd.

Input: n = 25
Output: 1
Explanation: Only the digit 5 is odd.

Input: n = 13579
Output: 5

Approach:
1. Extract the last digit using n % 10.
2. Check whether the digit is odd using digit % 2 != 0.
3. If it is odd, increment the count.
4. Remove the last digit using n /= 10.
5. Repeat until n becomes 0.
6. Return the count.

Time Complexity: O(d), where d is the number of digits.
Space Complexity: O(1).
*/

class Solution {
public:
    int countOddDigit(int n) {
        int count = 0;

        while (n > 0) {
            int digit = n % 10;

            if (digit % 2 != 0) {
                count++;
            }

            n /= 10;
        }

        return count;
    }
};
