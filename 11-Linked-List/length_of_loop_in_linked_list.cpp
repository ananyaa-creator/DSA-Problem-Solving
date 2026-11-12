/*
Problem: Find Length of Loop in a Linked List

Description:
Given the head of a singly linked list, find the length
of the loop present in the linked list.

If no loop exists, return 0.

Examples:

Example 1:
Input:
1 -> 2 -> 3 -> 4 -> 5
Node 5 points back to Node 3.

Output:
3

Example 2:
Input:
1 -> 2 -> 3 -> 4 -> NULL

Output:
0

Example 3:
Input:
1 -> 2 -> 3
Node 3 points back to Node 1.

Output:
3

Example 4:
Input:
1 -> 2 -> 3
Node 3 points back to itself.

Output:
1

Approach: Floyd's Cycle Detection Algorithm

1. Initialize slow and fast pointers at the head.
2. Move slow by one step and fast by two steps.
3. If fast or fast->next becomes NULL, no loop exists.
4. If slow and fast meet, a loop is detected.
5. Keep slow fixed at the meeting point.
6. Initialize count = 1.
7. Move fast one node at a time until it reaches slow again.
8. Return the count.

Time Complexity: O(n)
Space Complexity: O(1)

Edge Cases:
- Empty linked list.
- No loop.
- Self-loop.
- Loop starting at the head.
- Loop starting in the middle.
- Loop containing all nodes.
*/


// Singly Linked List Node
struct ListNode {
    int val;
    ListNode* next;

    ListNode() {
        val = 0;
        next = NULL;
    }

    ListNode(int data1) {
        val = data1;
        next = NULL;
    }

    ListNode(int data1, ListNode* next1) {
        val = data1;
        next = next1;
    }
};

class Solution {
public:
    int findLength(ListNode* slow, ListNode* fast) {
        int cnt = 1;
        fast = fast->next;
        while (slow != fast) {
            cnt++;
            fast = fast->next;
        }
        return cnt;
    }

    int findLengthOfLoop(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                return findLength(slow, fast);
            }
        }
        return 0;
    }
};
