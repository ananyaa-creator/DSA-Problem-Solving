/*
==================================================
Problem:

Given a non-negative integer n, determine whether
it is a "mirror ID" — a number that reads the same
forwards and backwards.

Do NOT convert the integer to a string.

Do NOT use an array.

Example:

Input:
n = 12321

Output:
true

Explanation:

Original:
1 2 3 2 1

Reversed:
1 2 3 2 1

Both are the same, so n is a palindrome.

Approach:
Reverse the digits mathematically.

We repeatedly extract the last digit:

    digit = n % 10

Then remove that digit:

    n = n / 10

Build the reversed number:

    reversed = reversed * 10 + digit

Finally compare the reversed number with the
original number.

Important:
Store the original value before modifying n.

Example:

n = 12321

original = 12321

Reverse:

digit = 1
reversed = 1

digit = 2
reversed = 12

digit = 3
reversed = 123

digit = 2
reversed = 1232

digit = 1
reversed = 12321

Since:

    original == reversed

the number is a palindrome.

Time Complexity:
O(log10(n))

Space Complexity:
O(1)

==================================================
*/

class Solution {
public:
    bool isMirrorID(int n) {
        int original = n;
        int reversed = 0;

        while (n > 0) {
            int digit = n % 10;
            reversed = reversed * 10 + digit;
            n = n / 10;
        }

        return original == reversed;
    }
};
