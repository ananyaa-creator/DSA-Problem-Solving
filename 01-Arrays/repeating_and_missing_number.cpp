/*
Problem: Find the Repeating and Missing Number

Description:
Given an array nums of size n containing numbers from 1 to n,
every number appears exactly once except:
- A appears twice (repeating number).
- B is missing.

Return an array of size 2:
result[0] = A (repeating number)
result[1] = B (missing number)

The original array must not be modified.

Example 1:
Input: nums = [3, 1, 2, 5, 3]

Output: [3, 4]

Explanation:
3 appears twice, and 4 is missing.

Approach: Mathematical Equations

Let:
A = repeating number
B = missing number

1. Calculate the expected sum of numbers from 1 to n:
   S = n * (n + 1) / 2

2. Calculate the expected sum of squares:
   P = n * (n + 1) * (2 * n + 1) / 6

3. Calculate the actual sum and sum of squares of the array.

4. Let:
   diff = actualSum - S = A - B

   squareDiff = actualSquareSum - P = A^2 - B^2

5. Using the identity:
   A^2 - B^2 = (A - B)(A + B)

   Therefore:
   A + B = squareDiff / diff

6. Solve:
   A = (diff + squareDiff / diff) / 2
   B = A - diff

7. Return {A, B}.

Time Complexity: O(n)
Space Complexity: O(1) auxiliary space.
The returned array requires O(1) space because it has exactly 2 elements.
*/

class Solution {
public:
    vector<int> findMissingRepeatingNumbers(vector<int>& nums) {
        long long n = nums.size();

        long long expectedSum = n * (n + 1) / 2;
        long long expectedSquareSum =
            n * (n + 1) * (2 * n + 1) / 6;

        long long actualSum = 0;
        long long actualSquareSum = 0;

        for (int num : nums) {
            actualSum += num;
            actualSquareSum += 1LL * num * num;
        }

        long long diff = actualSum - expectedSum;
        long long squareDiff = actualSquareSum - expectedSquareSum;

        long long sum = squareDiff / diff;

        long long repeating = (diff + sum) / 2;
        long long missing = repeating - diff;

        return {(int)repeating, (int)missing};
    }
};
