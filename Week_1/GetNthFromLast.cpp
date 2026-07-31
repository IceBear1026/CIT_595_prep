#include <iostream>

using namespace std;


struct node {
    int value;
    node* next;
};

// Returns a pointer to the node that is n positions behind the last node.
//
// n = 0 -> last node
// n = 1 -> second-to-last node
// n = 2 -> third-to-last node
//
// Returns nullptr if:
// - head is nullptr
// - n is too large for the list
node* GetNthFromLast(node* head, size_t n) {
    // Both pointers begin at the first node.
    node* curr = head;
    node* look_ahead = head;

    // Check if linkedlist is empty.
    if (head == nullptr) {
        return nullptr;
    }

    for (size_t i = 0; i < n; ++i) {
        // this shows that the look_ahead pointer has reached the end of the list before moving n nodes forward, which means n is too large for the list. This is becauase nth number should be between the linkedlist size and i = 0. And if we hit the end, it means we went past the linkedlist size. So we return nullptr to indicate that there is no matching node.
        if (look_ahead->next == nullptr) {
            return nullptr;
        }
        look_ahead = look_ahead->next;
    }

    // Now that the lok_ahead is on the nth node, we can move both pointers at the same time. 

    for (size_t i = 0; look_ahead->next != nullptr; ++i) {
        curr = curr->next;
        look_ahead = look_ahead->next;
    }

    return curr;
}

int main() {
    /*
    head
     |
     v
    [10] -> [20] -> [30] -> [40] -> [50] -> nullptr
    */

    node node5{50, nullptr};
    node node4{40, &node5};
    node node3{30, &node4};
    node node2{20, &node3};
    node node1{10, &node2};

    node* head = &node1;

    size_t n = 2;

    node* result = GetNthFromLast(head, n);

    if (result == nullptr) {
        cout << "No matching node was found." << endl;
    } else {
        cout << "Result: " << result->value << endl;
    }

    return 0;
}