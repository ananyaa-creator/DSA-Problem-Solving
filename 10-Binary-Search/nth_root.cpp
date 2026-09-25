/*
==================================================
Problem:

Given two integers N and M, find the Nth root of M.

We need to find an integer X such that:

    X^N = M

If no integer X exists, return -1.

Example 1:

Input:
N = 3
M = 27

Output:
3

Because:

    3^3 = 27


Example 2:

Input:
N = 4
M = 69

Output:
-1

Because there is no integer X such that:

    X^4 = 69


Approach:
Binary Search on Answer

The answer X lies between:

    1 and M

For every candidate mid, calculate:

    mid^N

We need to determine whether:

    mid^N == M
    mid^N <  M
    mid^N >  M

We use a helper function:

    powerCheck(mid, N, M)

Return:
    1  -> mid^N == M
    0  -> mid^N < M
    2  -> mid^N > M


If:

    mid^N == M

we found the answer.

If:

    mid^N < M

we need a larger value:

    low = mid + 1

If:

    mid^N > M

we need a smaller value:

    high = mid - 1


IMPORTANT:
We must avoid overflow while calculating mid^N.

We stop immediately if the current result becomes
greater than M.

Therefore, we never need to calculate the complete
power once it is already too large.


Time Complexity:
O(N * log M)

Space Complexity:
O(1)


Key Pattern:

This is Binary Search on Answer.

Search space:

    1 ... M

Condition:

    mid^N compared with M

This is similar to the integer cube root problem,
but the exponent N is variable.

==================================================
*/

class Solution {
public:
  int func(int mid, int n, int m){
    long long ans = 1;
    for(int i=1;i<=n;i++){
        ans = ans*mid;
        if(ans>m) return 2;
    }
    if(ans == m) return 1;
    return 0;
  } 

  int NthRoot(int N, int M) {
     int low = 1;
     int high = M;
     while(low<=high){
        int mid = (low+high)/2;
        int midN = func(mid,N,M);
        if(midN==1) return mid;
        else if(midN==0) low=mid+1;
        else high = mid-1;
     }
     return -1;  
    }
};
