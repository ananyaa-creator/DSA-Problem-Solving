/*
Problem: Find Pairs with Given Sum in a Doubly Linked List

Description:
Given a sorted doubly linked list and an integer k,
find all pairs of nodes whose values add up to k.

Approach:
1. Find the tail of the doubly linked list.
2. Initialize two pointers:
   - left at the head.
   - right at the tail.
3. Traverse while left and right have not crossed.
4. Calculate the sum of their values.
5. If the sum equals k:
   - Store the pair in the answer vector.
   - Move left forward and right backward.
6. If the sum is smaller than k:
   - Move left forward to increase the sum.
7. If the sum is greater than k:
   - Move right backward to decrease the sum.
8. Return the answer vector.

Time Complexity: O(n)
Auxiliary Space Complexity: O(1)
Output Space: O(p), where p is the number of pairs.

Example:
Input:  1 <-> 2 <-> 3 <-> 4 <-> 5 <-> 6
k = 7

Output:
(1, 6), (2, 5), (3, 4)

Edge Cases:
1. Empty linked list.
2. List containing only one node.
3. No pair exists with the given sum.
4. Multiple pairs exist.
5. Pair consists of adjacent nodes.
*/


class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int x) {
        data = x;
        next = NULL;
        prev = NULL;
    }
};

// Function to find the tail of the doubly linked list
Node* findTail(Node* head) {
    if (head == NULL) {
        return NULL;
    }

    Node* tail = head;

    while (tail->next != NULL) {
        tail = tail->next;
    }

    return tail;
}

// Function to find all pairs with the given sum
vector<pair<int, int>> findPairs(Node* head, int k) {
    vector<pair<int, int>> ans;

    if (head == NULL) {
        return ans;
    }

    Node* left = head;
    Node* right = findTail(head);

    while (left != right && left->data < right->data) {

        int sum = left->data + right->data;

        if (sum == k) {
            ans.push_back({left->data, right->data});

            left = left->next;
            right = right->prev;
        }
        else if (sum < k) {
            left = left->next;
        }
        else {
            right = right->prev;
        }
    }

    return ans;
}

// Function to print the doubly linked list
void printList(Node* head) {
    Node* temp = head;

    while (temp != NULL) {
        cout << temp->data;

        if (temp->next != NULL) {
            cout << " <-> ";
        }

        temp = temp->next;
    }

    cout << endl;
}

