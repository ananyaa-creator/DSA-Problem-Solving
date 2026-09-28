/*
==================================================
Problem:

A backup service uploads n files.

sizes[i]   = size of file i
weights[i] = cost of each request for file i

We choose ONE chunk size c for all files.

For file i:

    requests = ceil(sizes[i] / c)

Cost contributed by file i:

    requests * weights[i]

Total cost:

    sum(ceil(sizes[i] / c) * weights[i])

Find the SMALLEST c in [1, maxChunk] such that:

    total cost <= budget

If no such c exists, return -1.


Example:

sizes   = [10, 20]
weights = [2, 1]
c = 6

File 1:
ceil(10 / 6) = 2 requests
cost = 2 * 2 = 4

File 2:
ceil(20 / 6) = 4 requests
cost = 4 * 1 = 4

Total cost = 8


Approach:
Binary Search on Answer

The answer is the chunk size c.

Search space:

    1 ... maxChunk

For a fixed c:

    requests = ceil(size / c)

We can calculate ceiling division without
floating point:

    (size + c - 1) / c

However, since size <= 1e9 and c <= 1e9,
this is safe in long long.

The total cost can be as large as 1e15,
so we MUST use long long for totalCost.

Monotonic property:

As c increases:

    number of requests decreases
        ↓
    total cost decreases or stays the same

Therefore:

    small c → possibly too expensive
    large c → cheaper

If a particular c works:

    totalCost <= budget

then every larger chunk size will also work.

Since we want the SMALLEST valid c:

    valid → search LEFT
    invalid → search RIGHT


IMPORTANT:
We stop calculating as soon as totalCost exceeds
budget. This avoids unnecessary work and prevents
the running total from growing beyond what we need.


Time Complexity:
O(n log(maxChunk))

Space Complexity:
O(1)


Key Pattern:

Binary Search on Answer

    c = 1 ... maxChunk

Check:

    weighted request cost <= budget ?

YES → try smaller c
NO  → increase c

==================================================
*/

class Solution {
public:

    long long totalCost(vector<int>& sizes, vector<int>& weights, int c) {
        long long cost = 0;

        for (int i = 0; i < sizes.size(); i++) {
            long long chunks = (sizes[i] + c - 1LL) / c;
            cost += chunks * weights[i];

            // Optional early stopping
            if (cost > 1000000000000000LL)
                return cost;
        }

        return cost;
    }

    int smallestChunkSize(vector<int>& sizes,
                           vector<int>& weights,
                           int maxChunk,
                           long long budget) {

        // Even the largest allowed chunk is too expensive
        if (totalCost(sizes, weights, maxChunk) > budget)
            return -1;

        int low = 1;
        int high = maxChunk;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (totalCost(sizes, weights, mid) <= budget) {
                // mid works, try a smaller chunk size
                high = mid - 1;
            }
            else {
                // mid is too small, need a larger chunk
                low = mid + 1;
            }
        }

        return low;
    }
};

