/*
==================================================
Problem:
Given an integer array nums, count the number of
inversions in the array.

An inversion is a pair of elements nums[i] and
nums[j] such that:

    i < j
    nums[i] > nums[j]

A sorted array has 0 inversions.

Constraints:
- Array may contain positive and negative values.
- The inversion count can be large, so long long
  is used for the answer.

Example:
Input:
nums = [2, 3, 7, 1, 3, 5]

Output:
5

Inversions:
(2, 1)
(3, 1)
(7, 1)
(7, 3)
(7, 5)

Approach:
Use Merge Sort.

During the merge step, both halves are already
sorted.

If:

    arr[left] <= arr[right]

then arr[left] does not form an inversion with
arr[right], so we take arr[left].

Otherwise:

    arr[left] > arr[right]

Since the left half is already sorted, every
remaining element from left to mid will also be
greater than arr[right].

Therefore, the number of new inversions is:

    mid - left + 1

We add this count and continue merging.

Time Complexity:
O(n log n)

Space Complexity:
O(n)

Key Idea:
Merge Sort allows us to count multiple inversions
at once instead of checking every pair.

Brute Force:
O(n^2)

Merge Sort:
O(n log n)
==================================================
*/

class Solution {
public:
    long long cnt = 0;

    void merge(vector<int>& arr, int low, int mid, int high) {
        vector<int> temp;
        int left = low;
        int right = mid + 1;

        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right]) {
                temp.push_back(arr[left]);
                left++;
            }
            else {
                temp.push_back(arr[right]);

                // All remaining elements in the left half
                // are greater than arr[right]
                cnt += (mid - left + 1);

                right++;
            }
        }

        while (left <= mid) {
            temp.push_back(arr[left]);
            left++;
        }

        while (right <= high) {
            temp.push_back(arr[right]);
            right++;
        }

        for (int i = low; i <= high; i++) {
            arr[i] = temp[i - low];
        }
    }

    void mergeSort(vector<int>& arr, int low, int high) {
        if (low >= high)
            return;

        int mid = low + (high - low) / 2;

        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);

        merge(arr, low, mid, high);
    }

    long long numberOfInversions(vector<int> nums) {
        cnt = 0;  // Important if the same Solution object is reused

        int n = nums.size();

        if (n <= 1)
            return 0;

        mergeSort(nums, 0, n - 1);

        return cnt;
    }
};


