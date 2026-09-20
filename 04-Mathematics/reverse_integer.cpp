```cpp
/*
==================================================
Problem:

Given a signed 32-bit integer n, reverse its digits
while preserving its sign.

If the reversed number goes outside the signed
32-bit integer range:

    [-2147483648, 2147483647]

return 0.

The solution must NOT use 64-bit integers for the
final result.

Example:

Input:
n = 1563847412

Reversed:
2147483651

Since:

2147483651 > 2147483647

the result overflows.

Output:
0


Approach:
Digit Extraction + Overflow Detection

We extract the last digit using:

    digit = n % 10

Then remove the last digit:

    n = n / 10

Before adding a new digit to the reversed number,
we check whether:

    reversed * 10 + digit

would overflow.

Instead of actually performing the multiplication
first, check the boundary beforehand.

For positive INT_MAX:

    INT_MAX = 2147483647

Before:

    reversed = reversed * 10 + digit

check:

    reversed > INT_MAX / 10

OR:

    reversed == INT_MAX / 10
    && digit > 7

For negative INT_MIN:

    INT_MIN = -2147483648

The safe boundary for the negative result is
different because INT_MIN has one extra negative
value.

A convenient approach is to extract the sign and
work with the magnitude while keeping the magnitude
inside the signed integer range carefully.

This implementation instead performs the overflow
check directly using INT_MAX and INT_MIN.

Important:
We check BEFORE performing:

    reversed * 10

so no overflowing integer operation is performed.

Time Complexity:
O(log10(n))

Space Complexity:
O(1)

==================================================
*/

class Solution {
public:
    int decodeReading(int n) {
        int sign = 1;

        if (n < 0) {
            sign = -1;
            n = -n;
        }

        int result = 0;

        while (n > 0) {
            int digit = n % 10;
            n = n / 10;

            // Check overflow before multiplication
            if (result > 214748364) {
                return 0;
            }

            if (result == 214748364 && digit > 7) {
                return 0;
            }

            result = result * 10 + digit;
        }

        return sign * result;
    }
};
