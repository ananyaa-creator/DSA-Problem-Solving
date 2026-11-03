/*
Problem: Delete Kth Node of a Linked List

Concepts:
- Singly Linked List
- Pointers
- Dynamic Memory Allocation
- Node Deletion
- Linked List Traversal

Description:
Given the head of a singly linked list and an integer k,
delete the kth node (1-indexed) from the linked list
and return the updated head.

Handle the following cases:
1. Empty linked list: Return NULL.
2. Invalid k (k <= 0): Return the original list.
3. k = 1: Delete the head node.
4. k greater than the number of nodes: Return the original list.
5. Otherwise, delete the kth node.

Example 1:
Input:
linkedList = {10, 20, 30, 40, 50}
k = 3

Output:
{10, 20, 40, 50}

Explanation:
Original Linked List:
10 -> 20 -> 30 -> 40 -> 50

The 3rd node contains 30.
After deleting it:
10 -> 20 -> 40 -> 50

Example 2:
Input:
linkedList = {5, 10, 15}
k = 1

Output:
{10, 15}

Explanation:
The first node (5) is deleted.

Approach: Iterative Deletion
1. Check if the list is empty or k is invalid.
2. If k == 1, delete the head node and update head.
3. Otherwise, initialize a temporary pointer with head.
4. Traverse until the (k-1)th node is reached.
5. Check whether the kth node exists.
6. Store the kth node in delNode.
7. Update the previous node's next pointer to skip delNode.
8. Delete delNode to free memory.
9. Return the updated head.

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
    ListNode* deleteKthNode(ListNode* &head, int k) {

        if (head == NULL || k <= 0) {
            return head;
        }

        if (k == 1) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }

        ListNode* temp = head;

        for (int i = 1; i < k - 1; i++) {
            if (temp->next == NULL) {
                return head;
            }

            temp = temp->next;
        }

        if (temp->next == NULL) {
            return head;
        }


        ListNode* delNode = temp->next;
        temp->next = temp->next->next;

        delete delNode;

        return head;
    }
};



