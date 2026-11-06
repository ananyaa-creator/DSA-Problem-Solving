
/*
    Problem: Insert a Node at the Kth Position in a Linked List

    Description:
    Given the head of a singly linked list, an integer val,
    and an integer k, insert a new node containing val at
    the kth position in the linked list.

    Position k is 1-indexed.

    Return the head of the updated linked list.

    Example 1:
    Input:
    Linked List = 10 -> 20 -> 30 -> 40
    val = 25
    k = 3

    Output:
    10 -> 20 -> 25 -> 30 -> 40

    Example 2:
    Input:
    Linked List = 10 -> 20 -> 30
    val = 5
    k = 1

    Output:
    5 -> 10 -> 20 -> 30

    Example 3:
    Input:
    Linked List = 10 -> 20
    val = 30
    k = 3

    Output:
    10 -> 20 -> 30

    Approach:
    1. Create a new node containing val.
    2. If k == 1, insert the new node at the head.
    3. Otherwise, traverse the linked list to reach
       the (k-1)th node.
    4. If the required position does not exist,
       return the original linked list.
    5. Connect the new node to the next node.
    6. Connect the (k-1)th node to the new node.
    7. Return the head.

    Concepts Used:
    - Singly Linked List
    - Dynamic Memory Allocation
    - Pointer Manipulation
    - Linked List Traversal
    - Insertion at a Given Position

    Time Complexity: O(n)
    Auxiliary Space Complexity: O(1)
    New Node Space: O(1)

    Expected Output:

    Original Linked List: 10 20 30 40
    After Insertion at Position 3: 10 20 25 30 40

    Complexity Analysis:

    Time Complexity:
    O(n) - In the worst case, we traverse the linked list
    to reach the required position.

    Auxiliary Space Complexity:
    O(1) - Only a temporary pointer and a counter are used.

    New Node Space:
    O(1) - One new node is dynamically allocated.

    Edge Cases:
    1. k = 1:
       Insert the node at the beginning.

    2. Empty linked list and k = 1:
       New node becomes the head.

    3. k = length + 1:
       Insert the node at the tail.

    4. k > length + 1:
       No insertion takes place.

    5. k <= 0:
       No insertion takes place.
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
    ListNode* insertAtKthPosition(ListNode* head, int val, int k) {

        // Invalid position
        if (k <= 0) {
            return head;
        }

        // Create a new node
        ListNode* newNode = new ListNode(val);

        // Insert at the beginning
        if (k == 1) {
            newNode->next = head;
            return newNode;
        }

        ListNode* temp = head;
        int cnt = 1;

        // Traverse to the (k-1)th node
        while (temp != NULL && cnt < k - 1) {
            temp = temp->next;
            cnt++;
        }

        // If position is out of bounds
        if (temp == NULL) {
            delete newNode;
            return head;
        }

        // Insert the new node
        newNode->next = temp->next;
        temp->next = newNode;

        return head;
    }
};
