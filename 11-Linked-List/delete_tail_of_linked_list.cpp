/*
Problem: Delete Tail of a Linked List

Concepts:
- Singly Linked List
- Pointers
- Dynamic Memory Allocation
- Node Deletion
- Linked List Traversal

Description:
Given the head of a singly linked list, delete the last node
(tail node) and return the updated head of the linked list.

Handle the following cases:
1. Empty linked list: Return NULL.
2. Single-node linked list: Delete the only node and return NULL.
3. Multiple nodes: Delete the last node and return the original head.

Example 1:
Input:
linkedList = {10, 20, 30, 40}

Output:
{10, 20, 30}

Explanation:
Original Linked List:
10 -> 20 -> 30 -> 40

After deleting the tail node (40):
10 -> 20 -> 30

Example 2:
Input:
linkedList = {5}

Output:
NULL

Explanation:
The linked list contains only one node.
After deleting it, the list becomes empty.

Approach: Iterative Deletion
1. Check if the linked list is empty.
   If head is NULL, return NULL.
2. Check if the list contains only one node.
   If yes, delete it and set head to NULL.
3. Otherwise, initialize a temporary pointer with head.
4. Traverse until the second-last node is reached.
5. Delete the last node using temp->next.
6. Set temp->next = NULL.
7. Return the updated head.

Time Complexity: O(n)
Auxiliary Space Complexity: O(1)

Where n = Number of nodes in the linked list.
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
    ListNode* deleteTail(ListNode* &head) {

        // Empty linked list.
        if (head == NULL) {
            return NULL;
        }

        if (head->next == NULL) {
            delete head;
            head = NULL;
            return head;
        }

        ListNode* temp = head;

        while (temp->next->next != NULL) {
            temp = temp->next;
        }
      
        delete temp->next;
        temp->next = NULL;

        return head;
    }
};

