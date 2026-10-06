/*
==================================================
Problem:

Given n stall positions and k aggressive cows,
place the cows in different stalls such that the
MINIMUM distance between any two cows is as LARGE
as possible.

Return the maximum possible minimum distance.

Example:

stalls = [0, 3, 4, 7, 10, 9]
k = 4

After sorting:

[0, 3, 4, 7, 9, 10]

One optimal placement:

[0, 3, 7, 10]

Distances:

3, 4, 3

Minimum distance = 3

Therefore:

Answer = 3


APPROACH:
Binary Search on Answer

We are NOT directly searching for a stall.

We are searching for the answer:

    minimum possible distance

Possible distance:

    1 ... maxStall - minStall


For a candidate distance `d`, check whether it is
possible to place at least k cows such that every
two consecutive cows are at least d apart.

Greedy strategy:

1. Put the first cow at the first stall.
2. For every next stall:
       If

           currentStall - lastCow >= d

       place another cow.
3. If we can place k cows, distance d is possible.


MONOTONIC PROPERTY:

Suppose distance 3 is possible.

Then distance 1 and 2 will also be possible.

If distance 5 is impossible,
then distances 6, 7, 8, ... are also impossible.

So:

    possible possible possible | impossible impossible
                              ↑
                         maximum answer


Since we want the MAXIMUM valid distance:

    possible -> move RIGHT
    impossible -> move LEFT


Therefore:

    if canWePut(mid):
        low = mid + 1
    else:
        high = mid - 1

At the end:

    high = maximum valid distance


IMPORTANT:
The stalls must first be sorted.

Otherwise, checking:

    stalls[i] - last

would not represent increasing physical distance.

Time Complexity:

Sorting:
    O(n log n)

Binary Search:
    O(log(maxPosition))

Each feasibility check:
    O(n)

Total:
    O(n log n + n log(maxPosition))


Space Complexity:
    O(1) extra space apart from the sorting
    implementation's internal requirements.


==================================================
*/

class Solution {
public:
    bool canWePut(vector<int> &stalls, int distance, int cows) {
        int n = stalls.size();
        int cnt = 1;
        int last = stalls[0];

        for (int i = 1; i < n; i++) {
            if (stalls[i] - last >= distance) {
                cnt++;
                last = stalls[i];
            }

            if (cnt >= cows)
                return true;
        }

        return false;
    }

    int aggressiveCows(vector<int> &nums, int k) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int low = 1;
        int high = nums[n - 1] - nums[0];

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (canWePut(nums, mid, k)) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return high;
    }
};
