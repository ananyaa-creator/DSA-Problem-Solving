/*
Problem: Delete Head of a Linked List

Concepts:
- Singly Linked List
- Pointers
- Dynamic Memory Allocation
- Node Deletion

Description:
Given the head of a singly linked list, delete the first node
(head node) and return the new head of the linked list.

If the linked list is empty, return NULL.

Example 1:
Input:
linkedList = {10, 20, 30, 40}

Output:
{20, 30, 40}

Explanation:
Original Linked List:
10 -> 20 -> 30 -> 40

After deleting the head node (10):
20 -> 30 -> 40

Example 2:
Input:
linkedList = {5}

Output:
NULL

Explanation:
The linked list contains only one node.
After deleting it, the list becomes empty.

Approach: Iterative Deletion
1. Check if head is NULL.
2. If the list is empty, return NULL.
3. Store the current head in a temporary pointer.
4. Move head to the next node.
5. Delete the old head node to free memory.
6. Return the updated head.

Time Complexity: O(1)
Auxiliary Space Complexity: O(1)
*/

class ListNode {
public:
    int data;
    ListNode* next;

    ListNode() : data(0), next(nullptr) {}

    ListNode(int x) : data(x), next(nullptr) {}

    ListNode(int x, ListNode* next) : data(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteHead(ListNode* head) {

        // If the linked list is empty.
        if (head == NULL) {
            return NULL;
        }

        // Store the current head.
        ListNode* temp = head;

        // Move head to the next node.
        head = head->next;

        // Delete the old head.
        delete temp;

        return head;
    }
};


