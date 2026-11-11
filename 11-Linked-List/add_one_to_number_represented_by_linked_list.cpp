/*
Problem: Add One to a Number Represented by a Linked List

Description:
Given a singly linked list representing a non-negative
integer, add 1 to the number and return the updated head.

Each node contains a single digit.
Digits are stored in forward order (most significant
digit first).

Examples:

Example 1:
Input:
1 -> 2 -> 3

Output:
1 -> 2 -> 4

Explanation:
123 + 1 = 124

Example 2:
Input:
1 -> 2 -> 9

Output:
1 -> 3 -> 0

Explanation:
129 + 1 = 130

Example 3:
Input:
9 -> 9 -> 9

Output:
1 -> 0 -> 0 -> 0

Explanation:
999 + 1 = 1000

Example 4:
Input:
0 -> 0 -> 9

Output:
0 -> 1 -> 0

Explanation:
009 + 1 = 010

Approach: Recursion and Carry Propagation

1. Create a recursive helper function addHelp().
2. If temp is NULL, return carry 1.
3. Recursively process the next node.
4. Add the returned carry to the current node's digit.
5. If the digit is less than 10, return carry 0.
6. Otherwise, set the digit to 0 and return carry 1.
7. After recursion, check whether carry remains.
8. If carry is 1, create a new node containing 1
   and attach the original list after it.
9. Return the updated head.

Time Complexity: O(n)
Auxiliary Space Complexity: O(n)
New Node Space: O(1)

Edge Cases:
- Single-node list.
- Last digit less than 9.
- Carry propagation through multiple nodes.
- All digits are 9.
- Leading zeroes.
- Empty list (returns NULL).

Important:
The solution assumes a non-empty linked list
representing a number.
*/

class ListNode {
public:
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode* next)
        : val(x), next(next) {}
};

class Solution {
public:

    // Recursive helper function
    int addHelp(ListNode* temp) {

        // Base case: carry 1 for adding one
        if (temp == NULL) {
            return 1;
        }

        // Process the remaining nodes first
        int carry = addHelp(temp->next);

        // Add carry to current digit
        temp->val = temp->val + carry;

        // No further carry required
        if (temp->val < 10) {
            return 0;
        }

        // Current digit becomes 0
        temp->val = 0;

        // Propagate carry to previous node
        return 1;
    }

    ListNode* addOne(ListNode* head) {

        // Start recursive addition
        int carry = addHelp(head);

        // If carry remains, create a new head
        if (carry == 1) {

            ListNode* newNode = new ListNode(1);

            newNode->next = head;

            head = newNode;
        }

        return head;
    }
};

