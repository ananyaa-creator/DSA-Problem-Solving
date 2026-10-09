/*
==================================================
Problem: Perfect Number

Given an integer n, determine whether it is a
perfect number.

A perfect number is a number whose proper divisors
(excluding itself) add up to the number itself.

Example 1:
Input: n = 6

Proper divisors: 1, 2, 3

Sum = 1 + 2 + 3 = 6

Output: true

Example 2:
Input: n = 28

Proper divisors: 1, 2, 4, 7, 14

Sum = 1 + 2 + 4 + 7 + 14 = 28

Output: true


Approach: Divisor Pairing

Instead of checking every number from 1 to n-1,
we only need to check divisors up to sqrt(n).

If i divides n, then n/i is also a divisor.

For example, for n = 28:

i = 2
Divisors: 2 and 28/2 = 14

We add both divisors, avoiding double-counting
when i * i == n.

The number itself is excluded.


Time Complexity: O(sqrt(n))
Space Complexity: O(1)
==================================================
*/

class Solution {
public:
    bool isPerfect(int n) {
        int sum = 0;
        for(int i=1;i<n;i++){
            if(n%i==0){
                sum+=i;
            }
        }
        if(sum==n) return true;
        return false;
    }
};
