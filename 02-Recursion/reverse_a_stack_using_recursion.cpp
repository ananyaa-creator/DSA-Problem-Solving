/*
Problem: Reverse a Stack Using Recursion

Description:
Given a stack of integers, reverse the stack using recursion.
No additional stack or other data structure should be used.

Approach:
Two recursive functions are used:

1. insertAtBottom(stack<int>& st, int x):
   - If the stack is empty, push x.
   - Otherwise, store and remove the top element.
   - Recursively insert x at the bottom.
   - Push the stored element back.

2. reverseStack(stack<int>& st):
   - If the stack is empty, return.
   - Store and remove the top element.
   - Recursively reverse the remaining stack.
   - Insert the stored element at the bottom.

Time Complexity: O(n^2)
Auxiliary Space Complexity: O(n)

Example:
Input Stack (Top to Bottom): 4, 3, 2, 1
Output Stack (Top to Bottom): 1, 2, 3, 4

Edge Cases:
1. Empty stack.
2. Stack containing one element.
3. Stack containing multiple elements.
4. Stack containing duplicate elements.
*/


class Solution {
public:

    // Function to insert an element at the bottom
    void insertAtBottom(stack<int>& st, int x) {

        if (st.empty()) {
            st.push(x);
            return;
        }

        int temp = st.top();
        st.pop();

        insertAtBottom(st, x);

        st.push(temp);
    }

    // Function to reverse the stack
    void reverseStack(stack<int>& st) {

        if (st.empty()) {
            return;
        }

        int temp = st.top();
        st.pop();

        reverseStack(st);

        insertAtBottom(st, temp);
    }
};

