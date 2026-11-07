/*
Problem: Insert Before a Given Value in a Doubly Linked List

Description:
Given the head of a doubly linked list, an integer value,
and an integer x, insert a new node containing x immediately
before the first occurrence of the node containing value.

Return the updated head of the list.

Examples:

Example 1:
Input:
List = 10 <-> 20 <-> 30 <-> 40
value = 30, x = 25

Output:
10 <-> 20 <-> 25 <-> 30 <-> 40

Example 2:
Input:
List = 10 <-> 20 <-> 30
value = 10, x = 5

Output:
5 <-> 10 <-> 20 <-> 30

Example 3:
Input:
List = 10 <-> 20 <-> 30
value = 50, x = 5

Output:
10 <-> 20 <-> 30

Example 4:
Input:
List = NULL
value = 10, x = 5

Output:
NULL

Approach:
1. If the list is empty, return the original head.
2. Traverse the list to find the first node containing value.
3. If the value is not found, return the original head.
4. Create a new node containing x.
5. Connect the new node before the target node.
6. If the target has a previous node, update its next pointer.
7. Otherwise, update head to the new node.
8. Update the target node's prev pointer.
9. Return the updated head.

Time Complexity: O(n)
Auxiliary Space Complexity: O(1)

Edge Cases:
- Empty list.
- Target value at head.
- Target value in the middle.
- Target value at tail.
- Target value not found.
- Duplicate values (first occurrence is considered).
*/

// Doubly Linked List Node
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
    Node* insertBeforeValue(Node* head, int value, int x) {

        // Empty list
        if (head == NULL) {
            return head;
        }

        Node* temp = head;

        // Search for the first occurrence of value
        while (temp != NULL && temp->data != value) {
            temp = temp->next;
        }

        // Value not found
        if (temp == NULL) {
            return head;
        }

        // Create new node
        Node* newNode = new Node(x);

        // Connect new node before the target node
        newNode->next = temp;
        newNode->prev = temp->prev;

        // Update previous node's next pointer
        if (temp->prev != NULL) {
            temp->prev->next = newNode;
        }
        else {
            // Target node is the head
            head = newNode;
        }

        // Update target node's previous pointer
        temp->prev = newNode;

        return head;
    }
};
