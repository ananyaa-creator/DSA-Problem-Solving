/*
==================================================
Problem:

Given a budget, find the maximum integer k such that:

    k^3 <= budget

Do not use:
- cbrt()
- pow()
- **
- Any built-in cube-root/power function

The cube must be calculated manually.

Example:

Input:
budget = 30

3^3 = 27 <= 30
4^3 = 64 > 30

Therefore:

Output:
3


Approach:
Binary Search

We need the largest k satisfying:

    k^3 <= budget

For a candidate mid:

    mid^3 <= budget

then mid is valid, so store it and search for
a larger answer:

    ans = mid
    low = mid + 1

Otherwise:

    high = mid - 1


IMPORTANT:
Do NOT calculate:

    mid * mid * mid

directly using int.

Although budget fits in a 32-bit integer, mid * mid
* mid can overflow a 32-bit integer.

Therefore, use division to safely check:

    mid^3 <= budget

Since:

    mid^3 <= budget

is equivalent to:

    mid^2 <= budget / mid

for mid > 0.

But mid * mid can still overflow, so we first
check:

    mid <= budget / mid

which guarantees:

    mid * mid <= budget

Then check:

    mid * mid <= budget / mid

This avoids overflowing multiplication.

For mid = 0, it is always valid.

Time Complexity:
O(log budget)

Space Complexity:
O(1)

Key Pattern:

This is Binary Search on the ANSWER.

Search space:

    k = 0 ... budget

For each k, check whether:

    k^3 <= budget

==================================================
*/

class Solution {
public:
    int maxUnits(int budget) {
        long long low = 0;
        long long high = min(1291LL, (long long)budget);
        long long ans = 0;

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            long long cube = mid * mid * mid;

            if (cube <= budget) {
                ans = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return ans;
    }
};

