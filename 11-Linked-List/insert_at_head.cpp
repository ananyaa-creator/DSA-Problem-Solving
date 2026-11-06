/*
Problem: Insert a Node at the Head of a Linked List

Concepts:
- Singly Linked List
- Pointers
- Dynamic Memory Allocation
- Node Insertion

Description:
Given the head of a singly linked list and an integer val,
insert a new node containing val at the beginning (head)
of the linked list and return the updated head.

Example 1:
Input:
linkedList = {10, 20, 30, 40}
val = 5

Output:
{5, 10, 20, 30, 40}

Explanation:
Original Linked List:
10 -> 20 -> 30 -> 40

After inserting 5 at the head:
5 -> 10 -> 20 -> 30 -> 40

Example 2:
Input:
linkedList = {}
val = 10

Output:
{10}

Explanation:
Since the linked list is empty, the new node becomes
the head of the linked list.

Approach: Pointer Manipulation
1. Create a new node containing val.
2. Connect the new node to the current head.
3. Update head to point to the new node.
4. Return the updated head.

Time Complexity: O(1)
Auxiliary Space Complexity: O(1)

Note: O(1) auxiliary space excludes the newly allocated node.
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
    ListNode* insertAtHead(ListNode* head, int val) {

        // Create a new node.
        ListNode* newNode = new ListNode(val);

        // Connect new node to the current head.
        newNode->next = head;

        // Update head.
        head = newNode;

        return head;
    }
};

