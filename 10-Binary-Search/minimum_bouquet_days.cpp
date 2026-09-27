/*
==================================================
Problem:

A gardener has n flowers arranged in a CIRCLE.

growTime[i] = day on which flower i blooms.

One bouquet requires exactly k circularly adjacent
flowers that have already bloomed.

A flower cannot be reused in another bouquet.

Find the minimum number of days required to make
at least m bouquets.

Return -1 if it is impossible.

Example:

growTime = [1, 10, 3, 10, 2]
m = 3
k = 1

Since k = 1, every bloomed flower can form one
bouquet.

By day 10:

    all 5 flowers have bloomed

Therefore, 3 bouquets can be formed.

Answer = 10


Approach:
Binary Search on Answer

The answer is a DAY.

Minimum possible day:

    min(growTime)

Maximum possible day:

    max(growTime)

For a particular day `day`, determine whether we
can form at least m bouquets.

A flower is bloomed if:

    growTime[i] <= day


For k = 1:

    every bloomed flower forms one bouquet.


For k > 1:

We need k consecutive bloomed flowers.

Because the flowers are arranged in a circle,
the first and last positions are also adjacent.

We can handle the circular array by checking the
linear array while keeping track of the prefix and
suffix lengths of consecutive bloomed flowers.

An easier approach is to try every possible starting
position and greedily count bouquets, but that would
be O(n^2).

Instead, we use a doubled-array style traversal over
at most 2n positions and ensure that each flower is
considered only once for bouquet formation.

However, there is an important observation:

If m * k <= n, we only need to determine whether
there are enough non-overlapping circular groups of
k bloomed flowers.

We can handle the circular boundary by trying two
cases:

1. Do not connect the last and first flower.
2. Connect a possible suffix + prefix run.

The implementation below uses a simple circular
greedy check:

- Start from every possible boundary only when
  necessary.
- For each candidate day, process the circle in
  O(n).

Since binary search performs O(log(maxDay))
checks, total complexity remains:

    O(n log(maxDay))


Time Complexity:
O(n log(max(growTime)))

Space Complexity:
O(1)


IMPORTANT:

Before binary search, if:

    m * k > n

then it is impossible to make the required number
of bouquets because flowers cannot be reused.

Return -1 immediately.


Key Pattern:

Binary Search on Answer

    day = min(growTime) ... max(growTime)

Check:

    Can we make at least m bouquets by this day?

YES -> try an earlier day
NO  -> try a later day

==================================================
*/

class Solution {
public:
    bool possible(vector<int>& a, int day, int m, int k) {
        int n = a.size();

        int prefix = 0;
        while (prefix < n && a[prefix] <= day)
            prefix++;

        if (prefix == n)
            return n / k >= m;

        int suffix = 0;
        while (suffix < n && a[n - 1 - suffix] <= day)
            suffix++;

        int bouquets = 0;
        int cnt = 0;

        for (int i = prefix; i < n - suffix; i++) {
            if (a[i] <= day) {
                cnt++;
            } else {
                bouquets += cnt / k;
                cnt = 0;
            }
        }

        bouquets += cnt / k;

        if (prefix > 0 && suffix > 0) {
            bouquets += (prefix + suffix) / k;
        } else if (prefix > 0) {
            bouquets += prefix / k;
        } else if (suffix > 0) {
            bouquets += suffix / k;
        }

        return bouquets >= m;
    }

    int minDays(vector<int>& growTime, int m, int k) {
        int n = growTime.size();

        if (1LL * m * k > n)
            return -1;

        int low = *min_element(growTime.begin(), growTime.end());
        int high = *max_element(growTime.begin(), growTime.end());

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (possible(growTime, mid, m, k))
                high = mid - 1;
            else
                low = mid + 1;
        }

        return low;
    }
};

