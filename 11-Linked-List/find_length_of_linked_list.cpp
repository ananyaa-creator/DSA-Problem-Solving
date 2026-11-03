/*
Problem: Find Length of a Linked List

Concepts:
- Singly Linked List
- Pointers
- Linked List Traversal
- Counting Nodes

Description:
Given the head of a singly linked list, find and return
the total number of nodes present in the linked list.

If the linked list is empty, return 0.

Example 1:
Input:
linkedList = {10, 20, 30, 40, 50}

Output: 5

Explanation:
The linked list contains 5 nodes:
10 -> 20 -> 30 -> 40 -> 50

Example 2:
Input:
linkedList = {5, 10, 15}

Output: 3

Explanation:
The linked list contains 3 nodes.

Example 3:
Input:
linkedList = {}

Output: 0

Explanation:
The linked list is empty.

Approach: Iterative Traversal
1. Initialize a temporary pointer with head.
2. Initialize a counter cnt = 0.
3. Traverse the linked list while temp is not NULL.
4. Increment cnt for every node visited.
5. Move temp to the next node.
6. Return cnt after reaching the end.

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
    int getLength(ListNode* head) {

        ListNode* temp = head;
        int cnt = 0;

        // Traverse and count every node.
        while (temp != NULL) {
            cnt++;
            temp = temp->next;
        }

        return cnt;
    }
};

   
