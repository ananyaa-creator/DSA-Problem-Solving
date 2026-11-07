/*
    Problem: Insert a Node Before the Head of a Doubly Linked List

    Description:
    Given the head of a doubly linked list and an integer x,
    insert a new node containing x before the current head
    and return the updated head.

    Each node contains:
    1. Data
    2. Pointer to the previous node (prev)
    3. Pointer to the next node (next)

    Example 1:
    Input:
    10 <-> 20 <-> 30 <-> 40
    x = 5

    Output:
    5 <-> 10 <-> 20 <-> 30 <-> 40

    Example 2:
    Input:
    10
    x = 5

    Output:
    5 <-> 10

    Example 3:
    Input:
    NULL
    x = 5

    Output:
    5

    Approach:
    1. Create a new node containing x.
    2. Set the new node's next pointer to the current head.
    3. If the list is not empty, set the current head's
       prev pointer to the new node.
    4. Return the new node as the updated head.

    Concepts Used:
    - Doubly Linked List
    - Insertion at Head
    - Pointer Manipulation
    - Dynamic Memory Allocation
    - Updating prev and next Pointers

    Time Complexity: O(1)
    Auxiliary Space Complexity: O(1)
    New Node Space: O(1)



    Expected Output:

    Original Doubly Linked List: 10 <-> 20 <-> 30 <-> 40
    After Insertion Before Head: 5 <-> 10 <-> 20 <-> 30 <-> 40

    Complexity Analysis:

    Time Complexity:
    O(1) - Only a constant number of pointer operations
    are performed.

    Auxiliary Space Complexity:
    O(1) - No extra data structure is used.

    New Node Space:
    O(1) - One new node is dynamically allocated.

    Edge Cases:
    1. Empty list: New node becomes the head.
    2. Single-node list: New node is inserted before the
       existing node.
    3. Multiple-node list: New node becomes the new head.
*/

// Definition of a Doubly Linked List Node
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
    Node* insertBeforeHead(Node* head, int x) {

        // Create a new node
        Node* newNode = new Node(x);

        // Connect new node to the current head
        newNode->next = head;

        // Update the previous pointer of the old head
        if (head != NULL) {
            head->prev = newNode;
        }

        // Return the new head
        return newNode;
    }
};

