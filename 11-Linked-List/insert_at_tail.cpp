
/*
    Problem: Insert a Node at the Tail of a Linked List

    Description:
    Given the head of a singly linked list and an integer val,
    insert a new node containing val at the end of the linked list.

    Return the head of the updated linked list.

    Example 1:
    Input:
    Linked List = 10 -> 20 -> 30 -> 40
    val = 50

    Output:
    10 -> 20 -> 30 -> 40 -> 50

    Example 2:
    Input:
    Linked List = 10 -> 20
    val = 30

    Output:
    10 -> 20 -> 30

    Example 3:
    Input:
    Linked List = NULL
    val = 10

    Output:
    10

    Approach:
    1. Create a new node containing val.
    2. If the linked list is empty, return the new node.
    3. Otherwise, traverse the linked list until the last node.
    4. Connect the last node to the new node.
    5. Return the original head.

    Concepts Used:
    - Singly Linked List
    - Dynamic Memory Allocation
    - Pointer Traversal
    - Insertion at Tail

    Time Complexity: O(n)
    Auxiliary Space Complexity: O(1)
    New Node Space: O(1)

    Expected Output:

    Original Linked List: 10 20 30 40
    After Insertion at Tail: 10 20 30 40 50

    Complexity Analysis:

    Time Complexity:
    O(n) - We traverse the linked list to reach the last node.

    Auxiliary Space Complexity:
    O(1) - Only a temporary pointer is used.

    New Node Space:
    O(1) - One new node is dynamically allocated.

    Edge Cases:
    1. Empty linked list: New node becomes the head.
    2. Single-node linked list: New node is attached after the head.
    3. Multiple-node linked list: New node is attached after the last node.
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
    ListNode* insertAtTail(ListNode* head, int val) {

        // Create a new node
        ListNode* newNode = new ListNode(val);

        // If the linked list is empty
        if (head == NULL) {
            return newNode;
        }

        // Traverse to the last node
        ListNode* temp = head;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        // Attach the new node at the end
        temp->next = newNode;

        return head;
    }
};
