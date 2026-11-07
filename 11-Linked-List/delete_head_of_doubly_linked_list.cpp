
/*
    Problem: Delete the Head of a Doubly Linked List

    Description:
    Given the head of a doubly linked list, delete the
    first node and return the updated head.

    Each node contains:
    1. Data
    2. Pointer to the previous node (prev)
    3. Pointer to the next node (next)

    Example 1:
    Input:
    10 <-> 20 <-> 30 <-> 40

    Output:
    20 <-> 30 <-> 40

    Example 2:
    Input:
    10

    Output:
    NULL

    Example 3:
    Input:
    NULL

    Output:
    NULL

    Approach:
    1. If the list is empty, return NULL.
    2. Store the current head in a temporary pointer.
    3. Move head to the next node.
    4. Set the new head's prev pointer to NULL.
    5. Delete the old head node.
    6. Return the updated head.

    Concepts Used:
    - Doubly Linked List
    - Node Deletion
    - Pointer Manipulation
    - Dynamic Memory Deallocation

    Time Complexity: O(1)
    Auxiliary Space Complexity: O(1)



    Expected Output:

    Original Doubly Linked List: 10 <-> 20 <-> 30 <-> 40
    After Deleting Head: 20 <-> 30 <-> 40

    Complexity Analysis:

    Time Complexity:
    O(1) - Only pointer updates and deletion are performed.

    Auxiliary Space Complexity:
    O(1) - Only one temporary pointer is used.

    Edge Cases:
    1. Empty list: Returns NULL.
    2. Single-node list: Deletes the only node and returns NULL.
    3. Multiple-node list: Deletes head and updates prev of new head.
*/

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node() : data(0), next(NULL), prev(NULL) {}

    Node(int x) : data(x), next(NULL), prev(NULL) {}

    Node(int x, Node* next, Node* prev)
        : data(x), next(next), prev(prev) {}
};

class Solution {
public:
    Node* deleteHead(Node* head) {

        // If the linked list is empty
        if (head == NULL) {
            return NULL;
        }

        // Store the current head
        Node* temp = head;

        // Move head to the next node
        head = head->next;

        // Remove the backward link
        if (head != NULL) {
            head->prev = NULL;
        }

        // Delete the old head
        delete temp;

        return head;
    }
};


