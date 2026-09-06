/*
==================================================
Problem:
Given an m x n grid, traverse the grid in spiral
order starting from the top-left corner.

The spiral moves:
    Right -> Down -> Left -> Up

However, the drone can scan only a maximum of
k complete layers (rings).

After completing the k-th layer, stop immediately
and ignore all remaining cells.

Return the elements in the exact order in which
they are scanned.

Constraints:
- 1 <= m, n <= 200
- -100 <= grid[i][j] <= 100
- 1 <= k <= ceil(min(m, n) / 2)

Example:
Input:
[
 [1, 2, 3, 4],
 [5, 6, 7, 8],
 [9, 10, 11, 12],
 [13, 14, 15, 16]
]

k = 2

Output:
[1, 2, 3, 4, 8, 12, 16, 15,
 14, 13, 9, 5, 6, 7, 11, 10]

Explanation:

Layer 1:
1 -> 2 -> 3 -> 4 -> 8 -> 12 -> 16
-> 15 -> 14 -> 13 -> 9 -> 5

Layer 2:
6 -> 7 -> 11 -> 10

After completing 2 layers, the traversal stops.

Approach:
Maintain four boundaries:

    top
    bottom
    left
    right

For each layer:
1. Traverse the top row from left to right.
2. Traverse the right column from top to bottom.
3. Traverse the bottom row from right to left.
4. Traverse the left column from bottom to top.

After completing a layer, move all four boundaries
inward.

Stop after k layers.

Special care is needed for single-row or single-column
remaining regions to avoid visiting cells twice.

Time Complexity:
O(k * (m + n)) in terms of traversed cells,
and O(m * n) in the worst case.

Space Complexity:
O(m * n) for the output array.

Key Idea:
Represent each spiral ring using four boundaries
and process exactly k complete layers instead of
traversing the entire matrix.
==================================================
*/

class Solution {
public:
    vector<int> spiral_scan(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int m = matrix[0].size();

        int left = 0, right = m - 1;
        int top = 0, bottom = n - 1;
        int count = 0;

        vector<int> ans;

        while (top <= bottom && left <= right&& count<k) {

            // Traverse top row
            for (int i = left; i <= right; i++) {
                ans.push_back(matrix[top][i]);
            }
            top++;

            // Traverse right column
            for (int i = top; i <= bottom; i++) {
                ans.push_back(matrix[i][right]);
            }
            right--;

            // Traverse bottom row
            if (top <= bottom) {
                for (int i = right; i >= left; i--) {
                    ans.push_back(matrix[bottom][i]);
                }
                bottom--;
            }

            // Traverse left column
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
            count++;
        }

        return ans;
    }
};



