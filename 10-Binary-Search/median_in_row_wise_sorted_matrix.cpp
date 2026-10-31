/*
Problem: Median in a Row-Wise Sorted Matrix

Concepts:
- Binary Search on Answers
- Upper Bound
- 2D Arrays / Matrices
- Counting Elements in Sorted Arrays

Description:
Given a matrix where every row is sorted in ascending order,
find the median of the matrix.

The matrix contains an odd number of elements.

Example 1:
Input:
matrix = {
    {1, 4, 9},
    {2, 5, 6},
    {3, 7, 8}
}

Output: 5

Explanation:
Sorted array = {1, 2, 3, 4, 5, 6, 7, 8, 9}
Median = 5

Example 2:
Input:
matrix = {
    {1, 3, 8},
    {2, 3, 4},
    {1, 2, 5}
}

Output: 3

Explanation:
Sorted array = {1, 1, 2, 2, 3, 3, 4, 5, 8}
Median = 3

Approach: Binary Search on Answers
1. Find the minimum element in the first column.
2. Find the maximum element in the last column.
3. Apply binary search between these two values.
4. For every mid, count the number of elements <= mid
   using upper_bound in each row.
5. If count <= (rows * cols) / 2,
   search in the right half.
6. Otherwise, search in the left half.
7. When low == high, that value is the median.

Time Complexity: O(rows * log(cols) * log(max - min + 1))
Auxiliary Space Complexity: O(1)
*/


class Solution {
public:
    int findMedian(vector<vector<int>>& matrix) {

        int rows = matrix.size();
        int cols = matrix[0].size();

        int low = matrix[0][0];
        int high = matrix[0][cols - 1];

        for (int i = 1; i < rows; i++) {
            low = min(low, matrix[i][0]);
            high = max(high, matrix[i][cols - 1]);
        }

        int required = (rows * cols) / 2;

        while (low < high) {

            int mid = low + (high - low) / 2;
            int count = 0;

            for (int i = 0; i < rows; i++) {
                count += upper_bound(
                    matrix[i].begin(),
                    matrix[i].end(),
                    mid
                ) - matrix[i].begin();
            }

            if (count <= required) {
                low = mid + 1;
            }
            else {
                high = mid;
            }
        }

        return low;
    }
};
