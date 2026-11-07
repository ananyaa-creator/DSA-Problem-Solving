/*
    Problem: Delete the Tail of a Doubly Linked List

    Description:
    Given the head of a doubly linked list, delete the
    last node (tail) and return the updated head.

    Each node contains:
    1. Data
    2. Pointer to the previous node (prev)
    3. Pointer to the next node (next)

    Example 1:
    Input:
    10 <-> 20 <-> 30 <-> 40

    Output:
    10 <-> 20 <-> 30

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
    2. If the list contains only one node, delete it
       and return NULL.
    3. Otherwise, traverse the list until the last node.
    4. Set the next pointer of the second-last node to NULL.
    5. Delete the last node.
    6. Return the original head.

    Concepts Used:
    - Doubly Linked List
    - Node Deletion
    - Pointer Manipulation
    - Linked List Traversal
    - Dynamic Memory Deallocation

    Time Complexity: O(n)
    Auxiliary Space Complexity: O(1)



    Expected Output:

    Original Doubly Linked List: 10 <-> 20 <-> 30 <-> 40
    After Deleting Tail: 10 <-> 20 <-> 30

    Complexity Analysis:

    Time Complexity:
    O(n) - Traversal is required to reach the last node.

    Auxiliary Space Complexity:
    O(1) - Only one temporary pointer is used.

    Edge Cases:
    1. Empty list: Returns NULL.
    2. Single-node list: Deletes the only node and returns NULL.
    3. Multiple-node list: Deletes the last node and sets
       the second-last node's next pointer to NULL.
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
    Node* deleteTail(Node* head) {

        // If the linked list is empty
        if (head == NULL) {
            return NULL;
        }

        // If the list contains only one node
        if (head->next == NULL) {
            delete head;
            return NULL;
        }

        // Traverse to the last node
        Node* temp = head;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        // Remove the link to the last node
        temp->prev->next = NULL;

        // Delete the last node
        delete temp;

        return head;
    }
};
