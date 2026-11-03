/*
Problem: Search an Element in a Linked List

Concepts:
- Singly Linked List
- Pointers
- Linear Search
- Linked List Traversal

Description:
Given the head of a singly linked list and an integer key,
search for the key in the linked list.

Return true if the key is present.
Otherwise, return false.

Example 1:
Input:
linkedList = {10, 20, 30, 40, 50}
key = 30

Output: true

Explanation:
The element 30 is present in the linked list.

Example 2:
Input:
linkedList = {10, 20, 30, 40}
key = 60

Output: false

Explanation:
The element 60 is not present in the linked list.

Approach: Linear Search
1. Initialize a temporary pointer with head.
2. Traverse the linked list while temp is not NULL.
3. Compare the current node's value with key.
4. If both are equal, return true.
5. Otherwise, move to the next node.
6. If the traversal ends without finding key, return false.

Time Complexity: O(n)
Auxiliary Space Complexity: O(1)

Where n = Number of nodes in the linked list.
*/

class ListNode {
public:
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    bool searchKey(ListNode* head, int key) {

        ListNode* temp = head;

        // Traverse the linked list.
        while (temp != NULL) {

            // Check if the current node contains key.
            if (temp->val == key) {
                return true;
            }

            temp = temp->next;
        }

        // Key was not found.
        return false;
    }
};

