
/*
    Problem: Insert a Node Before a Given Value

    Description:
    Given the head of a singly linked list, an integer val,
    and an integer target, insert a new node containing val
    immediately before the first node containing target.

    Return the head of the updated linked list.

    If the target does not exist, return the original list.

    Example 1:
    Input:
    Linked List = 10 -> 20 -> 30 -> 40
    val = 25
    target = 30

    Output:
    10 -> 20 -> 25 -> 30 -> 40

    Example 2:
    Input:
    Linked List = 10 -> 20 -> 30
    val = 5
    target = 10

    Output:
    5 -> 10 -> 20 -> 30

    Example 3:
    Input:
    Linked List = 10 -> 20 -> 30
    val = 40
    target = 50

    Output:
    10 -> 20 -> 30

    Approach:
    1. Create a new node containing val.
    2. If the list is empty, return the original head.
    3. If the head contains target, insert before head.
    4. Otherwise, traverse until the next node contains
       the target value.
    5. If target is not found, return the original list.
    6. Connect the new node before the target node.
    7. Return the updated head.

    Concepts Used:
    - Singly Linked List
    - Dynamic Memory Allocation
    - Pointer Manipulation
    - Linked List Traversal
    - Insertion Before a Given Value

    Time Complexity: O(n)
    Auxiliary Space Complexity: O(1)
    New Node Space: O(1)

    
    Expected Output:

    Original Linked List: 10 20 30 40
    After Insertion Before 30: 10 20 25 30 40

    Complexity Analysis:

    Time Complexity:
    O(n) - In the worst case, the entire linked list
    may need to be traversed to find the target.

    Auxiliary Space Complexity:
    O(1) - Only a constant number of pointers are used.

    New Node Space:
    O(1) - One new node is dynamically allocated.

    Edge Cases:
    1. Empty linked list: No insertion.
    2. Target at head: Insert before head.
    3. Target in middle: Insert before target.
    4. Target at tail: Insert before tail.
    5. Target not found: Original list remains unchanged.
    6. Duplicate target values: Insert before first occurrence.
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
    ListNode* insertBeforeValue(ListNode* head, int val, int target) {

        // Create a new node
        ListNode* newNode = new ListNode(val);

        // If the linked list is empty
        if (head == NULL) {
            delete newNode;
            return head;
        }

        // If target is present at the head
        if (head->val == target) {
            newNode->next = head;
            return newNode;
        }

        // Traverse the linked list
        ListNode* temp = head;

        while (temp->next != NULL && temp->next->val != target) {
            temp = temp->next;
        }

        // If target is not found
        if (temp->next == NULL) {
            delete newNode;
            return head;
        }

        // Insert the new node before target
        newNode->next = temp->next;
        temp->next = newNode;

        return head;
    }
};
