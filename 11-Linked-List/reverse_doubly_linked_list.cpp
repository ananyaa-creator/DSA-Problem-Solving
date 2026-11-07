/*
Problem: Reverse a Doubly Linked List

Description:
Given the head of a doubly linked list, reverse the list
and return the new head.

Examples:

Example 1:
Input:
10 <-> 20 <-> 30 <-> 40

Output:
40 <-> 30 <-> 20 <-> 10

Example 2:
Input:
10 <-> 20

Output:
20 <-> 10

Example 3:
Input:
10

Output:
10

Example 4:
Input:
NULL

Output:
NULL

Approach:
1. If the list is empty or contains only one node,
   return the original head.
2. Initialize curr = head and temp = NULL.
3. Traverse the list.
4. For every node:
   - Store curr->prev in temp.
   - Swap curr->prev and curr->next.
   - Move curr to curr->prev.
5. Update head using temp->prev.
6. Return the new head.

Time Complexity: O(n)
Space Complexity: O(1)

Edge Cases:
- Empty list.
- Single-node list.
- Two-node list.
- Multiple-node list.
*/

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int x) {
        data = x;
        next = NULL;
        prev = NULL;
    }
};

class Solution {
public:
    Node* reverseDLL(Node* head) {

        // Empty list or single-node list
        if (head == NULL || head->next == NULL) {
            return head;
        }

        Node* curr = head;
        Node* temp = NULL;

        // Reverse the links of every node
        while (curr != NULL) {

            // Store the original previous node
            temp = curr->prev;

            // Swap next and prev pointers
            curr->prev = curr->next;
            curr->next = temp;

            // Move to the next node in original list
            curr = curr->prev;
        }

        // Update head to the original tail
        if (temp != NULL) {
            head = temp->prev;
        }

        return head;
    }
};

