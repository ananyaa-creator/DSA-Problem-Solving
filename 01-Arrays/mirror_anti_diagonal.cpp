/*
==================================================
Problem:
Given an n x n grid representing a warehouse's
shelf layout, mirror the grid across its
anti-diagonal (top-right to bottom-left).

Modify the matrix in-place.

Constraints:
- 1 <= n <= 1000
- 0 <= grid[i][j] <= 10^6
- Must modify the matrix in-place
- O(1) extra space

Example:

Input:
[[1, 2, 3],
 [4, 5, 6],
 [7, 8, 9]]

Output:
[[9, 6, 3],
 [8, 5, 2],
 [7, 4, 1]]

Approach:
For every element above the anti-diagonal, swap it
with its corresponding element across the
anti-diagonal.

The element at:
    matrix[i][j]

is swapped with:
    matrix[n-j-1][n-i-1]

Only elements where:
    j < n-i-1

need to be swapped.

This avoids unnecessary swaps and keeps the
operation completely in-place.

Time Complexity:
O(n^2)

Space Complexity:
O(1)

Key Idea:
To mirror a matrix across the anti-diagonal,
swap each element with its reflected position:

    (i, j) -> (n-j-1, n-i-1)

The anti-diagonal itself remains unchanged.
==================================================
*/


class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n-i-1;j++){
                swap(matrix[i][j],matrix[n-j-1][n-i-1]);
            }
        }
    }
};

