/*
Problem: Mirror ID (Palindrome Number)

Description:
Given a non-negative integer n, check whether its digits
read the same forwards and backwards.

Do not convert the integer into a string or an array.

Examples:
Input: n = 12321
Output: True

Input: n = 123
Output: False

Input: n = 0
Output: True

Approach:
1. Store the original number.
2. Initialize rev = 0.
3. Extract each digit using n % 10.
4. Append the digit to rev using rev = rev * 10 + digit.
5. Remove the last digit using n /= 10.
6. Compare the reversed number with the original.
7. If equal, return true; otherwise, return false.

Time Complexity: O(log10(n)), for n > 0
Space Complexity: O(1)
*/


class Solution {
public:
    bool isMirrorID(int n) {
        int original = n;
        int rev = 0;

        while (n > 0) {
            int digit = n % 10;
            rev = rev * 10 + digit;
            n /= 10;
        }

        return rev == original;
    }
};

