```cpp
/*
==================================================
Problem:
Given a permutation delivery[] containing the
tracking IDs 1 to n, count the number of delay
pairs.

A delay pair is a pair (i, j) such that:

    i < j
    delivery[i] > delivery[j]

In other words, a package with a larger tracking ID
was delivered before a package with a smaller
tracking ID.

Constraints:
- 1 <= n <= 10^5
- delivery is a permutation of 1 to n
- Must run better than O(n^2)

Example:
Input:
delivery = [3, 1, 4, 2]

Output:
3

Inversions:
(3, 1)
(3, 2)
(4, 2)

Therefore:
Total delay pairs = 3

Approach:
Use Merge Sort and count inversions during the
merge step.

During merging, both the left and right halves
are already sorted.

If:

    arr[left] <= arr[right]

there is no inversion, so we take arr[left].

Otherwise:

    arr[left] > arr[right]

Since the left half is sorted, every element from
left to mid will also be greater than arr[right].

Therefore, all of these elements form delay pairs:

    mid - left + 1

Add this number to the answer.

Time Complexity:
O(n log n)

Space Complexity:
O(n)

Key Idea:
A delay pair is exactly an inversion.

Therefore, the standard inversion-counting
Merge Sort algorithm can be directly applied.

This is a good example of recognizing that two
different-looking problems have the same underlying
DSA pattern.
==================================================
*/

class Solution {
public:
    long long cnt = 0;
    vector<int> temp;

    void merge(vector<int>& arr, int low, int mid, int high) {
        int left = low, right = mid + 1, idx = 0;
        temp.resize(high - low + 1);

        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right]) {
                temp[idx++] = arr[left++];
            } else {
                temp[idx++] = arr[right++];
                cnt += (mid - left + 1);
            }
        }
        while (left <= mid)  temp[idx++] = arr[left++];
        while (right <= high) temp[idx++] = arr[right++];

        for (int i = low; i <= high; i++)
            arr[i] = temp[i - low];
    }

    void mergeSort(vector<int>& arr, int low, int high) {
        if (low >= high) return;
        int mid = low + (high - low) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }

    long long count_delay_pairs(vector<int> delivery) {
        cnt = 0;
        int n = delivery.size();
        if (n <= 1) return 0;
        mergeSort(delivery, 0, n - 1);
        return cnt;
    }
};

