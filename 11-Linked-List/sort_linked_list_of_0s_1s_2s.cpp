/*
Problem: Sort a Linked List of 0s, 1s and 2s

Description:
Given the head of a singly linked list containing only
0s, 1s and 2s, sort the linked list in ascending order.

Rearrange the existing nodes instead of creating a
completely new linked list.

Examples:

Example 1:
Input:
1 -> 0 -> 2 -> 1 -> 0 -> 2

Output:
0 -> 0 -> 1 -> 1 -> 2 -> 2

Example 2:
Input:
2 -> 2 -> 1 -> 0

Output:
0 -> 1 -> 2 -> 2

Example 3:
Input:
0 -> 0 -> 0

Output:
0 -> 0 -> 0

Example 4:
Input:
NULL

Output:
NULL

Approach: Three Dummy Linked Lists

1. Create three dummy nodes:
   zeroHead, oneHead and twoHead.
2. Maintain three pointers:
   zero, one and two.
3. Traverse the original linked list.
4. Depending on the node's value, attach it to
   the corresponding list.
5. Connect the three lists in ascending order:
   Zero List -> One List -> Two List.
6. Handle cases where one or more lists are empty.
7. Set the last node's next pointer to NULL.
8. Store the new head.
9. Delete the three dummy nodes.
10. Return the new head.

Time Complexity: O(n)
Auxiliary Space Complexity: O(1)

Edge Cases:
- Empty linked list.
- Single-node linked list.
- All nodes contain 0.
- All nodes contain 1.
- All nodes contain 2.
- One or more categories are missing.

Important:
The solution assumes that the linked list contains
only 0, 1 and 2.
The original nodes are reused; only three dummy
nodes are created.
*/


class ListNode {
public:
    int data;
    ListNode* next;

    ListNode() : data(0), next(nullptr) {}

    ListNode(int x) : data(x), next(nullptr) {}

    ListNode(int x, ListNode* next)
        : data(x), next(next) {}
};

class Solution {
public:
    ListNode* sortList(ListNode*& head) {

        // Empty list or single-node list
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        // Create three dummy nodes
        ListNode* zeroHead = new ListNode(-1);
        ListNode* oneHead = new ListNode(-1);
        ListNode* twoHead = new ListNode(-1);

        // Pointers for maintaining the three lists
        ListNode* zero = zeroHead;
        ListNode* one = oneHead;
        ListNode* two = twoHead;

        ListNode* temp = head;

        // Separate nodes into three lists
        while (temp != nullptr) {

            if (temp->data == 0) {
                zero->next = temp;
                zero = zero->next;
            }
            else if (temp->data == 1) {
                one->next = temp;
                one = one->next;
            }
            else {
                two->next = temp;
                two = two->next;
            }

            temp = temp->next;
        }

        // Connect the three lists
        zero->next = (oneHead->next != nullptr)
                     ? oneHead->next
                     : twoHead->next;

        one->next = twoHead->next;

        // Terminate the final list
        two->next = nullptr;

        // Store the new head
        ListNode* newHead = zeroHead->next;

        // Delete dummy nodes
        delete zeroHead;
        delete oneHead;
        delete twoHead;

        return newHead;
    }
};
