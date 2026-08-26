/*
==================================================
Problem:
Given an array of ticket prices and a budget,
find two tickets whose combined cost is exactly
equal to the budget.

Return the indices of the two tickets.

Constraints:
- 2 <= prices.length <= 10^4
- -10^9 <= prices[i] <= 10^9
- Exactly one valid pair exists

Example:
Input:
prices = [220, 400, 150, 330]
budget = 550

Output:
[0, 3]

Explanation:
prices[0] + prices[3] = 220 + 330 = 550

Approach:
Use a hash map to store each price and its index.

For every price, calculate the value needed to
reach the budget:

    required = budget - prices[i]

If the required value already exists in the hash
map, we have found the required pair.

Otherwise, store the current price and its index.

Time Complexity:
O(n)

Space Complexity:
O(n)

Key Idea:
Instead of checking every possible pair using
nested loops, use hashing to find the required
complement in O(1) average time.
==================================================
*/

class Solution {
public:
    vector<int> find_ticket_pair(vector<int>& prices, int budget) {
        int n = prices.size();
        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++) {
            int complement = budget - prices[i];
            if (mp.count(complement)) {
                return {mp[complement], i};
            }
            mp[prices[i]] = i;
        }
        return {};
    }
};
