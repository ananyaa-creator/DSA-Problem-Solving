/*
    Problem: Delete the Kth Node of a Doubly Linked List

    Description:
    Given the head of a doubly linked list and an integer k,
    delete the kth node from the beginning and return the
    updated head.

    Each node contains:
    1. Data
    2. Pointer to the previous node (prev)
    3. Pointer to the next node (next)

    Position k is 1-indexed.

    Example 1:
    Input:
    10 <-> 20 <-> 30 <-> 40
    k = 3

    Output:
    10 <-> 20 <-> 40

    Example 2:
    Input:
    10 <-> 20 <-> 30
    k = 1

    Output:
    20 <-> 30

    Example 3:
    Input:
    10 <-> 20 <-> 30
    k = 3

    Output:
    10 <-> 20

    Approach:
    1. If the list is empty or k <= 0, return the original head.
    2. Traverse the linked list to reach the kth node.
    3. If the kth node does not exist, return the original head.
    4. If the node has a previous node, update its next pointer.
    5. Otherwise, update head because the first node is being deleted.
    6. If the node has a next node, update its prev pointer.
    7. Delete the kth node.
    8. Return the updated head.

    Concepts Used:
    - Doubly Linked List
    - Node Deletion
    - Pointer Manipulation
    - Linked List Traversal
    - Dynamic Memory Deallocation
    - 1-Based Indexing

    Time Complexity: O(n)
    Auxiliary Space Complexity: O(1)



    Expected Output:

    Original Doubly Linked List: 10 <-> 20 <-> 30 <-> 40
    After Deleting Position 3: 10 <-> 20 <-> 40

    Complexity Analysis:

    Time Complexity:
    O(n) - Traversal is required to reach the kth node.

    Auxiliary Space Complexity:
    O(1) - Only a temporary pointer and a counter are used.

    Edge Cases:
    1. Empty list: Returns NULL.
    2. k <= 0: No deletion takes place.
    3. k = 1: Deletes the head and updates the new head's prev.
    4. k = length: Deletes the tail.
    5. Single-node list: Deletes the only node and returns NULL.
    6. k > length: No deletion takes place.
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
    Node* deleteKth(Node* head, int k) {

        // If the list is empty or position is invalid
        if (head == NULL || k <= 0) {
            return head;
        }

        // Traverse to the kth node
        Node* temp = head;
        int count = 1;

        while (temp != NULL && count < k) {
            temp = temp->next;
            count++;
        }

        // If kth node does not exist
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

        // Delete the kth node
        delete temp;

        return head;
    }
};



