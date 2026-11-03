/*
Problem: Linked List Traversal

Concepts:
- Singly Linked List
- Pointers
- Dynamic Data Structures
- Vector

Description:
Given the head of a singly linked list, traverse the entire
linked list and return all its elements in a vector in the
same order as their appearance.

Example 1:
Input:
linkedList = {5, 4, 3, 1, 0}

Output:
{5, 4, 3, 1, 0}

Explanation:
The linked list is:
5 -> 4 -> 3 -> 1 -> 0

Starting from the head, visit every node and store its
data in the result vector.

Approach: Iterative Traversal
1. Create an empty vector to store the elements.
2. Initialize a temporary pointer with head.
3. Traverse while temp is not nullptr.
4. Add temp->data to the vector.
5. Move temp to the next node.
6. Return the vector after reaching the end.

Time Complexity: O(n)
Auxiliary Space Complexity: O(n)

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
    vector<int> LLTraversal(ListNode* head) {
        vector<int> ans;

        ListNode* temp = head;

        // Traverse the linked list.
        while (temp != nullptr) {
            ans.push_back(temp->data);
            temp = temp->next;
        }

        return ans;
    }
};

