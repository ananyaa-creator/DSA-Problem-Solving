/*
==================================================
Problem:
Given an array of packet checksums and a target
signature k, find:

1. The number of contiguous subarrays whose XOR
   is exactly equal to k.

2. The length of the longest such subarray.

Return both values.

Constraints:
- 1 <= checksums.length <= 2 * 10^5
- 0 <= checksums[i] <= 10^9
- 0 <= k <= 10^9

Example:
Input:
checksums = [4, 2, 2, 6, 4]
k = 6

Output:
(4, 5)

Explanation:
The valid segments are:

[4, 2]           -> XOR = 6, length = 2
[4, 2, 2, 6, 4]  -> XOR = 6, length = 5
[2, 2, 6]        -> XOR = 6, length = 3
[6]              -> XOR = 6, length = 1

Total valid segments = 4
Longest valid segment = 5

Approach:
Use Prefix XOR + Hashing.

Let prefixXOR[i] represent the XOR of all elements
from index 0 to i.

For a subarray from j+1 to i:

    XOR = prefixXOR[i] ^ prefixXOR[j]

We want:

    prefixXOR[i] ^ prefixXOR[j] = k

Therefore:

    prefixXOR[j] = prefixXOR[i] ^ k

For counting:
Store the frequency of every prefix XOR.
Every previous occurrence of the required XOR
represents one valid subarray.

For finding the longest segment:
Store the earliest index at which each prefix XOR
occurred.

The earliest occurrence gives the longest possible
subarray ending at the current index.

Time Complexity:
O(n) average

Space Complexity:
O(n)

Key Idea:
Prefix XOR converts the XOR of any subarray into
the XOR of two prefix XOR values.

Hashing lets us find the required previous prefix
XOR in O(1) average time.

Two separate maps are used:
- countMap -> counts valid subarrays
- firstIdx -> finds the longest valid subarray
==================================================
*/

class Solution{
public: 
    pair<int,int> cleanSegments(vector<int>& checksums, int k) {
    int n = checksums.size();
    unordered_map<int,int> firstIdx; // xor value -> earliest index
    firstIdx[0] = -1; // before array starts
    int xr = 0, cnt = 0, maxLen = 0;
    unordered_map<int,int> countMap; // for counting occurrences
    countMap[0] = 1;

    for (int i = 0; i < n; i++) {
        xr ^= checksums[i];
        int need = xr ^ k;

        if (countMap.count(need)) cnt += countMap[need];
        if (firstIdx.count(need)) maxLen = max(maxLen, i - firstIdx[need]);

        countMap[xr]++;
        if (!firstIdx.count(xr)) firstIdx[xr] = i; // only earliest
    }
    return {cnt, maxLen};
}


