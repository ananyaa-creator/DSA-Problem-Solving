/*
Problem: Delete Node with Value X

Concepts:
- Singly Linked List
- Pointers
- Dynamic Memory Allocation
- Node Deletion
- Linked List Traversal

Description:
Given the head of a singly linked list and an integer X,
delete the first node containing the value X and return
the updated head of the linked list.

Handle the following cases:
1. Empty linked list: Return NULL.
2. Head contains X: Delete the head node.
3. X exists elsewhere: Delete the first node containing X.
4. X does not exist: Return the original linked list.

Example 1:
Input:
linkedList = {10, 20, 30, 40, 50}
X = 30

Output:
{10, 20, 40, 50}

Explanation:
The node containing 30 is deleted.

Original:
10 -> 20 -> 30 -> 40 -> 50

After deletion:
10 -> 20 -> 40 -> 50

Example 2:
Input:
linkedList = {10, 20, 30}
X = 10

Output:
{20, 30}

Explanation:
The head node contains X, so it is deleted.

Approach: Iterative Search and Deletion
1. Check if the linked list is empty.
2. If the head contains X:
   - Store head in a temporary pointer.
   - Move head to the next node.
   - Delete the old head.
3. Otherwise, traverse the list until the node
   just before the node containing X is found.
4. Check whether X exists in the list.
5. If found:
   - Store the target node in delNode.
   - Update the previous node's next pointer.
   - Delete delNode.
6. Return the updated head.

Time Complexity: O(n)
Auxiliary Space Complexity: O(1)

Where n = Number of nodes in the linked list.
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
    ListNode* deleteNodeWithValueX(ListNode* &head, int X) {

        // Empty linked list.
        if (head == NULL) {
            return NULL;
        }

        // If head contains X.
        if (head->data == X) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }

        ListNode* temp = head;

        // Search for the node containing X.
        while (temp->next != NULL && temp->next->data != X) {
            temp = temp->next;
        }

        // If X is found, delete that node.
        if (temp->next != NULL) {
            ListNode* delNode = temp->next;
            temp->next = temp->next->next;
            delete delNode;
        }

        return head;
    }
};



