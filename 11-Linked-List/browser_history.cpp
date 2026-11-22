/*
Problem: Design Browser History Using Doubly Linked List

Description:
Implement a browser history system that supports:
1. Visiting a new URL.
2. Moving backward by a given number of steps.
3. Moving forward by a given number of steps.

Each node stores a webpage URL and pointers to the
previous and next webpages.

Approach:
1. Use a doubly linked list to maintain browser history.
2. Maintain a pointer currentPage to track the active webpage.
3. Constructor:
   - Create a node containing the homepage.
4. Visit:
   - Create a new node for the given URL.
   - Connect it after the current page.
   - Move currentPage to the new node.
   - This removes any existing forward history.
5. Back:
   - Move currentPage backwards using the back pointer.
   - Stop if there is no previous page.
6. Forward:
   - Move currentPage forward using the next pointer.
   - Stop if there is no next page.
7. Return the URL of the current page.

Time Complexity:
- Constructor: O(1)
- Visit: O(1)
- Back: O(steps)
- Forward: O(steps)

Auxiliary Space Complexity: O(1) per operation.
Overall Space Complexity: O(n), where n is the number
of webpages stored in the browser history.

Example:
Homepage = "google.com"

Operations:
visit("youtube.com")
visit("github.com")
back(1)
back(1)
forward(1)
visit("leetcode.com")

Expected Current Pages:
youtube.com
google.com
youtube.com
leetcode.com

Edge Cases:
1. Backward movement beyond available history.
2. Forward movement beyond available history.
3. Visiting a new URL after moving backward.
4. Homepage as the only webpage.
5. Zero steps in back() or forward().
*/



class Node {
public:
    string data;
    Node* next;
    Node* back;

    Node(string x) {
        data = x;
        next = nullptr;
        back = nullptr;
    }
};

class Browser {
    Node* currentPage;

public:

    // Constructor
    Browser(string& homepage) {
        currentPage = new Node(homepage);
    }

    // Visit a new webpage
    void visit(string& url) {
        Node* newNode = new Node(url);

        currentPage->next = newNode;
        newNode->back = currentPage;

        currentPage = newNode;
    }

    // Move backward by given steps
    string back(int steps) {
        while (steps > 0) {
            if (currentPage->back != nullptr) {
                currentPage = currentPage->back;
            }
            else {
                break;
            }

            steps--;
        }

        return currentPage->data;
    }

    // Move forward by given steps
    string forward(int steps) {
        while (steps > 0) {
            if (currentPage->next != nullptr) {
                currentPage = currentPage->next;
            }
            else {
                break;
            }

            steps--;
        }

        return currentPage->data;
    }

    // Destructor to free browser history
    ~Browser() {
        // Move to the first webpage
        while (currentPage->back != nullptr) {
            currentPage = currentPage->back;
        }

        // Delete all nodes
        while (currentPage != nullptr) {
            Node* temp = currentPage;
            currentPage = currentPage->next;
            delete temp;
        }
    }
};

