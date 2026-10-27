/*
Problem: Reverse Integer with Overflow Detection

Description:
Given a signed 32-bit integer n, reverse its digits while
preserving its sign.

If the reversed number falls outside the signed 32-bit
integer range [-2^31, 2^31 - 1], return 0.

Example 1:
Input: n = 1563847412
Output: 0
Explanation: Reversal gives 2147483651, which exceeds
the maximum 32-bit signed integer value.

Example 2:
Input: n = -123
Output: -321

Example 3:
Input: n = 120
Output: 21

Approach:
1. Initialize rev = 0.
2. Extract the last digit using n % 10.
3. Remove the last digit using n /= 10.
4. Before appending the digit, check whether rev * 10 + digit
   would exceed the signed 32-bit integer range.
5. If overflow would occur, return 0.
6. Otherwise, append the digit and continue.
7. Return rev.

Overflow check:
INT_MAX =  2147483647
INT_MIN = -2147483648

Before rev = rev * 10 + digit:
- If rev > INT_MAX / 10, overflow.
- If rev == INT_MAX / 10 and digit > 7, overflow.
- If rev < INT_MIN / 10, overflow.
- If rev == INT_MIN / 10 and digit < -8, overflow.

Time Complexity: O(log10(|n|))
Space Complexity: O(1)

Note: No 64-bit integer is used.
*/


class Solution {
public:
    int decodeReading(int n) {
        int rev = 0;

        while (n != 0) {
            int digit = n % 10;
            n /= 10;

            if (rev > INT_MAX / 10 ||
                (rev == INT_MAX / 10 && digit > 7)) {
                return 0;
            }

            if (rev < INT_MIN / 10 ||
                (rev == INT_MIN / 10 && digit < -8)) {
                return 0;
            }

            rev = rev * 10 + digit;
        }

        return rev;
    }
};

