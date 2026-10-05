/*
==================================================
Problem:

Seats are numbered consecutively starting from `first`:

    first, first + 1, first + 2, ...

Some seats are reserved.

Given a query k, find the k-th FREE seat.

Example:

first = 5
reserved = [6, 8, 9, 12]

Seats:

5  6  7  8  9  10  11  12  13 ...
F  R  F  R  R   F   F   R   F

Free seats:

5, 7, 10, 11, 13, ...

Therefore:

k = 1 -> 5
k = 3 -> 10
k = 4 -> 11


Approach:
Binary Search on Answer

For a candidate seat `x`, calculate the number of
FREE seats from `first` through `x`.

Total seats:

    x - first + 1

Reserved seats within this range can be found using
upper_bound:

    reserved.begin() ... first reserved seat > x

Let:

    reservedCount = number of reserved seats <= x

Then:

    freeCount = totalSeats - reservedCount


For the k-th free seat, we need:

    freeCount >= k

This condition is monotonic.

Example:

seat x        5   6   7   8   9   10   11
freeCount     1   1   2   2   2    3    4

Once freeCount becomes >= k, it will remain >= k
for every larger seat.

Therefore, binary search for the SMALLEST x such that:

    freeCount >= k


Search Range:

LOW:

    first

HIGH:

The k-th free seat can be at most:

    first + k - 1 + number of reserved seats

So we can safely use:

    first + k + reserved.size()

This is still within long long.


Complexity for ONE query:

    O(log n + log range)

Since upper_bound takes O(log n), and the answer
binary search also takes O(log range).

For q queries:

    O(q * (log n + log range))

Space:

    O(1) extra space
    (excluding the input/output)


Important:
Use long long because seat numbers and queries can
reach 10^9, and the calculated upper bound can be
larger than a normal int.

==================================================
*/

class Solution {
public:
    vector<int> kthFreeSeats(int first, vector<int>& reserved, vector<int>& queries) {
        int n = reserved.size();
        vector<int> res;
        res.reserve(queries.size());
        for (int k : queries) {
            // find count of reserved[i] with free-before-it < k
            int lo = 0, hi = n;
            while (lo < hi) {
                int mid = lo + (hi - lo) / 2;
                long long freeBefore = (long long)reserved[mid] - first - mid;
                if (freeBefore < k) lo = mid + 1;
                else hi = mid;
            }
            res.push_back((int)((long long)first + k - 1 + lo));
        }
        return res;
    }
};

