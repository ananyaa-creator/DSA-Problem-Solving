/*
Problem: Flatten a Linked List

Description:
Given a special linked list containing multiple sorted
linked lists, flatten it into one sorted linked list.

Each node contains:
- val: Stores the node's value.
- next: Points to the next horizontal list.
- child: Points to the next node in the vertical list.

The final flattened list must use child pointers.

Examples:

Example 1:

Input:
5 -> 7 -> 9
|    |    |
10   8    22
|    |
19   20

Output:
5 -> 7 -> 8 -> 9 -> 10 -> 19 -> 20 -> 22

Example 2:

Input:
1 -> 2
|    |
4    3

Output:
1 -> 2 -> 3 -> 4

Approach: Recursion and Merging Sorted Lists

1. If the list is empty or contains only one column,
   return the head.
2. Recursively flatten the remaining columns using
   flattenLinkedList(head->next).
3. Disconnect the horizontal next pointer of head.
4. Merge the current vertical list with the already
   flattened list.
5. Compare the values of both lists.
6. Attach the smaller node using the child pointer.
7. Attach the remaining nodes after one list ends.
8. Return the merged head.

Time Complexity: O(N * K)
Auxiliary Space Complexity: O(K)

Where:
N = Total number of nodes.
K = Number of horizontal linked lists.

Edge Cases:
- Empty linked list.
- Single column.
- Single node.
- Duplicate values.
- Unequal column lengths.

Important:
Every vertical linked list must be sorted.
The original nodes are reused.
The final list is connected using child pointers.
*/

struct ListNode {
    int val;
    ListNode* next;
    ListNode* child;

    ListNode() {
        val = 0;
        next = NULL;
        child = NULL;
    }

    ListNode(int data1) {
        val = data1;
        next = NULL;
        child = NULL;
    }

    ListNode(int data1, ListNode* next1, ListNode* child1) {
        val = data1;
        next = next1;
        child = child1;
    }
};

class Solution {

    // Merge two sorted vertical linked lists
    ListNode* merge(ListNode* list1, ListNode* list2) {

        ListNode* dummyNode = new ListNode(-1);
        ListNode* res = dummyNode;

        // Merge both lists
        while (list1 != NULL && list2 != NULL) {

            if (list1->val < list2->val) {

                res->child = list1;
                res = list1;

                list1 = list1->child;
            }
            else {

                res->child = list2;
                res = list2;

                list2 = list2->child;
            }

            // Remove horizontal connection
            res->next = NULL;
        }

        // Attach remaining nodes of list1
        while (list1 != NULL) {

            res->child = list1;
            res = list1;

            list1 = list1->child;

            res->next = NULL;
        }

        // Attach remaining nodes of list2
        while (list2 != NULL) {

            res->child = list2;
            res = list2;

            list2 = list2->child;

            res->next = NULL;
        }

        // Store the merged head
        ListNode* mergedHead = dummyNode->child;

        // Delete dummy node
        delete dummyNode;

        return mergedHead;
    }

public:

    // Flatten the complete linked list
    ListNode* flattenLinkedList(ListNode*& head) {

        // Base case
        if (head == NULL || head->next == NULL) {
            return head;
        }

        // Recursively flatten remaining columns
        ListNode* mergeHead = flattenLinkedList(head->next);

        // Remove horizontal connection
        head->next = NULL;

        // Merge current list with flattened list
        head = merge(head, mergeHead);

        return head;
    }
};

