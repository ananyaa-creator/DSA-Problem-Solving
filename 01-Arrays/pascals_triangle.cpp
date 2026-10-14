/*
Problem: Pascal's Triangle

Description:
Given an integer n, return the first n rows (1-indexed)
of Pascal's Triangle.

Rules:
1. The first row contains only 1.
2. Each row has one more element than the previous row.
3. The first and last elements of every row are 1.
4. Every other element is the sum of the two elements
   directly above it in the previous row.

Example 1:
Input: n = 5

Output:
[
    [1],
    [1, 1],
    [1, 2, 1],
    [1, 3, 3, 1],
    [1, 4, 6, 4, 1]
]

Approach:
1. Create an empty 2D vector to store the triangle.
2. Iterate from row 0 to row n-1.
3. Create a row containing row+1 elements, initialized to 1.
4. For every inner position j, calculate:
   currentRow[j] = previousRow[j-1] + previousRow[j]
5. Add the completed row to the triangle.
6. Return the triangle.

Time Complexity: O(n^2)
Space Complexity: O(n^2), including the output.
*/

class Solution {
public:
    vector<vector<int>> pascalTriangleIII(int n) {
        vector<vector<int>> ans;

        for (int row = 1; row <= n; row++) {
            long long val = 1;
            vector<int> ansRow;

            ansRow.push_back(1);

            for (int col = 1; col < row; col++) {
                val = val * (row - col);
                val = val / col;

                ansRow.push_back(val);
            }

            ans.push_back(ansRow);
        }

        return ans;
    }
};
