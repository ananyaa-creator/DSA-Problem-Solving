```cpp
/*
==================================================
Problem:
Given an array of request IDs, find all service IDs
that appear more than floor(n/3) times.

There can be at most two such elements.

The solution must use:
- O(n) time
- O(1) extra space (excluding the output array)

Constraints:
- 1 <= logs.length <= 5 * 10^4
- -10^9 <= logs[i] <= 10^9

Example:
Input:
logs = [7, 7, 5, 7, 5, 1, 5, 7, 9]

Output:
[7]

Explanation:
n = 9
floor(n/3) = 3

Frequency of 7 = 4  -> qualifies
Frequency of 5 = 3  -> does NOT qualify
Frequency of 1 = 1  -> does not qualify
Frequency of 9 = 1  -> does not qualify

Therefore, the answer is [7].

Approach:
Use the extended Moore's Voting Algorithm.

Since an element must appear more than n/3 times,
there can be at most two such elements.

Maintain two candidates and their counts.

First Pass:
Find the two possible candidates.

Second Pass:
Count the actual occurrences of both candidates
and verify whether they appear more than n/3 times.

Time Complexity:
O(n)

Space Complexity:
O(1) excluding the output array.

Key Idea:
For the n/3 case, keep two candidates instead
of one. Whenever both candidate slots are occupied
and a different element appears, decrease both
counts.

The first pass only identifies possible candidates.
A second pass is necessary to verify them.
==================================================
*/

class Solution {
public:
    vector<int> floodingServices(vector<int>& logs){
        int n = logs.size();
        int el1 = INT_MIN, el2 = INT_MAX; // sentinels that can't collide with real -1
        int cnt1 = 0, cnt2 = 0;

        for(int i = 0; i < n; i++){
            if(logs[i] == el1){
                cnt1++;
            }
            else if(logs[i] == el2){
                cnt2++;
            }
            else if(cnt1 == 0){
                el1 = logs[i];
                cnt1 = 1;
            }
            else if(cnt2 == 0){
                el2 = logs[i];
                cnt2 = 1;
            }
            else{
                cnt1--;
                cnt2--;
            }
        }

        int cnt1_final = 0, cnt2_final = 0;
        for(int i = 0; i < n; i++){
            if(logs[i] == el1) cnt1_final++;
            else if(logs[i] == el2) cnt2_final++;
        }

        vector<int> result;
        if(cnt1_final > n/3) result.push_back(el1);
        if(cnt2_final > n/3) result.push_back(el2);
        return result;
    }
};
