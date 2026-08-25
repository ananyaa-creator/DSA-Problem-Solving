/*
==================================================
Problem:
Given a 32-bit signed integer `code`, reverse its
digits while preserving its sign.

If the reversed value exceeds the 32-bit signed
integer range [-2^31, 2^31 - 1], return 0.

Trailing zeros in the original number naturally
disappear when reversing because the result is an
integer.

Constraints:
- -2^31 <= code <= 2^31 - 1
- No string conversion
- 64-bit integers are not allowed
- Use only arithmetic operations such as / and %

Example:
Input:
code = -8463

Output:
-3648

Explanation:
8463 -> 3648
The original sign is reapplied:
-8463 -> -3648

Time Complexity:
O(log10(n))

Space Complexity:
O(1)

Key Idea:
Extract the last digit using % 10 and remove it
using / 10. Before adding a digit to the reversed
number, check whether doing so would cause a
32-bit signed integer overflow.
==================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rev(int x) {
        int sign = (x < 0) ? -1 : 1;
        x = abs(x);

        long long reversed = 0;

        while (x != 0) {
            int digit = x % 10;
            x /= 10;

            reversed = reversed * 10 + digit;

            if (reversed > INT_MAX)
                return 0;
        }

        return sign * reversed;
    }
};
