/*
Problem: Remove Duplicates from a Sorted Doubly Linked List

Description:
Given the head of a sorted doubly linked list, remove all
duplicate nodes so that each distinct value appears only once.

Approach:
1. Start traversing the list using temp.
2. Store the next node in nextNode.
3. While nextNode exists and contains the same value as temp:
   - Store the duplicate node.
   - Move nextNode forward.
   - Delete the duplicate node.
4. Connect temp->next to the first non-duplicate node.
5. Update the prev pointer of that node.
6. Move temp forward and repeat.
7. Return the updated head.

Time Complexity: O(n)
Auxiliary Space Complexity: O(1)

Example:
Input:  1 <-> 1 <-> 2 <-> 3 <-> 3 <-> 4 <-> 4
Output: 1 <-> 2 <-> 3 <-> 4

Edge Cases:
1. Empty linked list.
2. List containing only one node.
3. List containing no duplicates.
4. All nodes contain the same value.
5. Duplicates at the beginning or end.
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

// Function to remove duplicates from a sorted DLL
Node* removeDuplicates(Node* head) {
    Node* temp = head;

    while (temp != NULL && temp->next != NULL) {

        Node* nextNode = temp->next;

        // Delete all consecutive duplicate nodes
        while (nextNode != NULL && nextNode->data == temp->data) {

            Node* duplicate = nextNode;
            nextNode = nextNode->next;

            delete duplicate;
        }

        // Connect the current node to the next distinct node
        temp->next = nextNode;

        // Update the previous pointer
        if (nextNode != NULL) {
            nextNode->prev = temp;
        }

        temp = temp->next;
    }

    return head;
}
