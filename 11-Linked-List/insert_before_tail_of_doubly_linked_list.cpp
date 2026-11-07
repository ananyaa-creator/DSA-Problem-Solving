/*
Problem: Insert Before Tail in a Doubly Linked List

Description:
Given the head of a doubly linked list and an integer x,
insert a new node containing x immediately before the tail
node and return the updated head.

Examples:

Example 1:
Input:
List = 10 <-> 20 <-> 30 <-> 40
x = 25

Output:
10 <-> 20 <-> 30 <-> 25 <-> 40

Example 2:
Input:
List = 10
x = 5

Output:
5 <-> 10

Example 3:
Input:
List = NULL
x = 5

Output:
5

Approach:
1. Create a new node containing x.
2. If the list is empty, return the new node.
3. If the list has only one node:
   - Connect the new node before the existing head.
   - Update the existing head's prev pointer.
   - Return the new node.
4. Otherwise, traverse to the tail node.
5. Store the previous node of the tail in back.
6. Connect the new node between back and the tail.
7. Update all next and prev pointers.
8. Return the original head.

Time Complexity: O(n)
Space Complexity: O(1) auxiliary space.

Edge Cases:
- Empty list.
- Single-node list.
- Two-node list.
- Multiple-node list.
*/

#include <iostream>
using namespace std;

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
    Node* insertBeforeTail(Node* head, int x) {

        Node* newNode = new Node(x);

        // Case 1: Empty list
        if (head == NULL) {
            return newNode;
        }

        // Case 2: Only one node
        if (head->next == NULL) {
            newNode->next = head;
            head->prev = newNode;

            return newNode;
        }

        // Case 3: Multiple nodes
        Node* temp = head;

        // Traverse to the tail
        while (temp->next != NULL) {
            temp = temp->next;
        }

        // Previous node of the tail
        Node* back = temp->prev;

        // Insert new node before the tail
        newNode->next = temp;
        newNode->prev = back;

        back->next = newNode;
        temp->prev = newNode;

        return head;
    }
};
