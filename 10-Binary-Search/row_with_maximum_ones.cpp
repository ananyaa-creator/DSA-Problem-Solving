/*
Problem: Row With Maximum Number of Ones

Concepts:
- Binary Search
- First Occurrence of an Element
- 2D Arrays / Matrices

Description:
Given a binary matrix where every row is sorted in ascending order,
find the index of the row containing the maximum number of ones.

If multiple rows have the same number of ones, return the row
with the smaller index.

If no 1 exists in the matrix, return -1.

Example 1:
Input:
mat = {
    {1, 1, 1},
    {0, 0, 1},
    {0, 0, 0}
}

Output: 0

Explanation:
Row 0 contains 3 ones.
Row 1 contains 1 one.
Row 2 contains 0 ones.

Therefore, row 0 has the maximum number of ones.

Approach: Binary Search on Each Row
1. Traverse every row of the matrix.
2. Apply binary search to find the first occurrence of 1.
3. If firstOne is the index of the first 1,
   the number of ones is m - firstOne.
4. Update maxOnes and ans if the current row
   contains strictly more ones than the previous maximum.
5. Return ans.

Time Complexity: O(n * log(m))
Auxiliary Space Complexity: O(1)

Where:
n = Number of rows
m = Number of columns
*/

class Solution {
public:
    int rowWithMax1s(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        int maxOnes = 0;
        int ans = -1;

        for (int i = 0; i < n; i++) {
            int low = 0, high = m - 1;
            int firstOne = m;

            // Binary search for first occurrence of 1.
            while (low <= high) {
                int mid = low + (high - low) / 2;

                if (mat[i][mid] == 1) {
                    firstOne = mid;
                    high = mid - 1;
                }
                else {
                    low = mid + 1;
                }
            }

            // Count the number of ones in the current row.
            int count = m - firstOne;

            // Update only if the count is strictly greater.
            // This preserves the smaller index in case of a tie.
            if (count > maxOnes) {
                maxOnes = count;
                ans = i;
            }
        }

        return ans;
    }
};

