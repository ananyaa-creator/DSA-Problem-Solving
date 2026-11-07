/*
Problem: Insert a Node at Kth Position in a Doubly Linked List

Description:
Given the head of a doubly linked list, an integer k, and
an integer x, insert a new node containing x at the kth
position using 0-based indexing.

Examples:

Example 1:
Input:
List = 10 <-> 20 <-> 30 <-> 40
k = 2, x = 25

Output:
10 <-> 20 <-> 25 <-> 30 <-> 40

Example 2:
Input:
List = 10 <-> 20 <-> 30
k = 0, x = 5

Output:
5 <-> 10 <-> 20 <-> 30

Example 3:
Input:
List = 10 <-> 20 <-> 30
k = 3, x = 40

Output:
10 <-> 20 <-> 30 <-> 40

Example 4:
Input:
List = 10 <-> 20 <-> 30
k = 5, x = 40

Output:
10 <-> 20 <-> 30

Approach:
1. If k is negative, return the original head.
2. If k is 0:
   - Create a new node.
   - Connect it before the current head.
   - Update the current head's prev pointer.
   - Return the new node.
3. Otherwise, traverse to the node at position k-1.
4. If the node does not exist, return the original head.
5. Create a new node.
6. Connect the new node between the current node and
   its next node.
7. Update both next and prev pointers.
8. Return the original head.

Indexing: 0-based

Time Complexity: O(n)
Auxiliary Space Complexity: O(1)

Edge Cases:
- Empty list.
- Insertion at head.
- Insertion at tail.
- Invalid position greater than list length.
- Negative position.
- Single-node list.
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
    Node* insertKth(Node* head, int k, int x) {

        // Invalid negative position
        if (k < 0) {
            return head;
        }

        // Case 1: Insert at head (0-based indexing)
        if (k == 0) {

            Node* newNode = new Node(x);

            newNode->next = head;

            if (head != NULL) {
                head->prev = newNode;
            }

            return newNode;
        }

        // Case 2: Insert at any other position
        Node* temp = head;
        int count = 0;

        // Reach the node at position k-1
        while (temp != NULL && count < k - 1) {
            temp = temp->next;
            count++;
        }

        // Invalid position
        if (temp == NULL) {
            return head;
        }

        Node* newNode = new Node(x);

        // Connect new node with the next node
        newNode->next = temp->next;
        newNode->prev = temp;

        // Update previous link of the next node
        if (temp->next != NULL) {
            temp->next->prev = newNode;
        }

        // Update next link of the previous node
        temp->next = newNode;

        return head;
    }
};
