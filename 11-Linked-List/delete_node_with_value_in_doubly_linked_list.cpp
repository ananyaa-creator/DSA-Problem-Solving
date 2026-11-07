/*
    Problem: Delete a Node with a Given Value in a Doubly Linked List

    Description:
    Given the head of a doubly linked list and an integer value,
    delete the first node containing the given value and return
    the updated head.

    Each node contains:
    1. Data
    2. Pointer to the previous node (prev)
    3. Pointer to the next node (next)

    Example 1:
    Input:
    10 <-> 20 <-> 30 <-> 40
    value = 30

    Output:
    10 <-> 20 <-> 40

    Example 2:
    Input:
    10 <-> 20 <-> 30
    value = 10

    Output:
    20 <-> 30

    Example 3:
    Input:
    10 <-> 20 <-> 30
    value = 50

    Output:
    10 <-> 20 <-> 30

    Approach:
    1. If the list is empty, return NULL.
    2. Traverse the list to find the first node containing
       the given value.
    3. If the value is not found, return the original head.
    4. If the node has a previous node, update its next pointer.
    5. Otherwise, update head because the first node is being deleted.
    6. If the node has a next node, update its prev pointer.
    7. Delete the node.
    8. Return the updated head.

    Concepts Used:
    - Doubly Linked List
    - Node Deletion
    - Pointer Manipulation
    - Linked List Traversal
    - Dynamic Memory Deallocation
    - Searching in a Linked List

    Time Complexity: O(n)
    Auxiliary Space Complexity: O(1)



    Expected Output:

    Original Doubly Linked List: 10 <-> 20 <-> 30 <-> 40
    After Deleting Value 30: 10 <-> 20 <-> 40

    Complexity Analysis:

    Time Complexity:
    O(n) - Traversal may be required to search the entire list.

    Auxiliary Space Complexity:
    O(1) - Only one temporary pointer is used.

    Edge Cases:
    1. Empty list: Returns NULL.
    2. Value at head: Deletes the head and updates the new head's prev.
    3. Value in middle: Deletes the matching node.
    4. Value at tail: Deletes the last node.
    5. Value not found: Original list remains unchanged.
    6. Duplicate values: Deletes only the first occurrence.
    7. Single-node list: Deletes the node if its value matches.
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
    Node* deleteValue(Node* head, int value) {

        // If the linked list is empty
        if (head == NULL) {
            return NULL;
        }

        // Search for the node containing the value
        Node* temp = head;

        while (temp != NULL && temp->data != value) {
            temp = temp->next;
        }

        // If value is not found
        if (temp == NULL) {
            return head;
        }

        // Update the previous node's next pointer
        if (temp->prev != NULL) {
            temp->prev->next = temp->next;
        }
        else {
            // If the head node is being deleted
            head = temp->next;
        }

        // Update the next node's prev pointer
        if (temp->next != NULL) {
            temp->next->prev = temp->prev;
        }

        // Delete the matching node
        delete temp;

        return head;
    }
};


