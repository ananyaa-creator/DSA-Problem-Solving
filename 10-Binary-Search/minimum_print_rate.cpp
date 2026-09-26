/*
==================================================
Problem:

Given an array pages where pages[i] represents
the number of pages in document i, find the minimum
printing rate r such that all documents can be
completed within h hours.

The printer:

- Can work on only ONE document per hour.
- Prints at most r pages in that hour.
- If a document finishes before the hour ends,
  the remaining time cannot be used for another
  document.
- The same rate r is used for every document.

Example:

pages = [25, 12, 8, 14]
h = 6

For r = 14:

25 pages -> ceil(25 / 14) = 2 hours
12 pages -> ceil(12 / 14) = 1 hour
8 pages  -> ceil(8 / 14)  = 1 hour
14 pages -> ceil(14 / 14) = 1 hour

Total = 5 hours

Since 5 <= 6, rate 14 works.

The minimum valid rate is:

14


Approach:
Binary Search on Answer

The possible printing rate lies between:

    1 and max(pages)

Why?

Minimum possible rate:
    1 page/hour

Maximum necessary rate:
    max(pages)

At rate r, the number of hours required for a
document with p pages is:

    ceil(p / r)

We can calculate this without floating point:

    (p + r - 1) / r

OR, more safely for large values:

    p / r + (p % r != 0)


Now calculate the total hours required.

If:

    totalHours <= h

then r is sufficient.

But we want the MINIMUM valid rate, so search LEFT:

    high = mid - 1

If:

    totalHours > h

then r is too slow, so search RIGHT:

    low = mid + 1


Time Complexity:
O(n log(max(pages)))

Space Complexity:
O(1)


Key Pattern:

Binary Search on Answer

    rate = 1 ... max(pages)

Check:

    Can this rate finish all documents
    within h hours?

If YES:
    try a smaller rate

If NO:
    increase the rate

==================================================
*/


class Solution {
public:
    int minPrintRate(vector<int>& pages, int h) {
        int low = 1;
        int high = *max_element(pages.begin(), pages.end());

        while (low < high) {
            int mid = low + (high - low) / 2;

            long long hours = 0;

            for (int page: pages) {
                hours += ((long long)page + mid - 1) / mid;
            }

            if (hours <= h) {
                // mid is a valid speed, try smaller
                high = mid;
            } else {
                // mid is too slow
                low = mid + 1;
            }
        }

        return low;
    }
};


