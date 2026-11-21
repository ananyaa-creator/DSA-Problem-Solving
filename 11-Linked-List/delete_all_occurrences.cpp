/*
Problem: Delete All Occurrences of a Given Value in a Doubly Linked List

Description:
Given the head of a doubly linked list and an integer k,
delete all nodes whose data is equal to k.

Approach:
1. Traverse the doubly linked list using a pointer temp.
2. If temp->data equals k:
   - Update head if the current node is the head.
   - Store the next and previous nodes.
   - Update the next node's prev pointer.
   - Update the previous node's next pointer.
   - Delete the current node.
   - Move temp to the next node.
3. Otherwise, move temp to the next node.
4. Return the updated head.

Time Complexity: O(n)
Auxiliary Space Complexity: O(1)

Example:
Input:  10 <-> 20 <-> 10 <-> 30 <-> 10 <-> 40
k = 10

Output: 20 <-> 30 <-> 40

Edge Cases:
1. Empty linked list.
2. No occurrence of k.
3. All nodes contain k.
4. Head node contains k.
5. Consecutive nodes contain k.
*/



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

// Function to delete all occurrences of k
Node* deleteAllOccurrences(Node* head, int k) {
    Node* temp = head;

    while (temp != NULL) {
        if (temp->data == k) {

            // Update head if the current node is the head
            if (temp == head) {
                head = temp->next;
            }

            Node* nextNode = temp->next;
            Node* prevNode = temp->prev;

            // Update the next node's previous pointer
            if (nextNode != NULL) {
                nextNode->prev = prevNode;
            }

            // Update the previous node's next pointer
            if (prevNode != NULL) {
                prevNode->next = nextNode;
            }

            // Delete the current node
            delete temp;

            // Move to the next node
            temp = nextNode;
        }
        else {
            temp = temp->next;
        }
    }

    return head;
}

