#include <iostream> 

using namespace std;

class BinarySearchTree {
    private:
        struct Node {
            int value;
            Node* left;
            Node* right;
        };
        Node* m_root;

    public:
        BinarySearchTree() : m_root(nullptr) {}

        // This is where we will implement the insert function for the BinarySearchTree class. The insert function will take an integer value as a parameter and insert it into the tree. 

        // let's practice inserting the first node only. We will not handle left and right traversal yet. 
        void insert(int value) {
            // if m_root is nullptr, the tree is currently empty.
            if (m_root == nullptr) {
                // allocate the first node on the heap.
                m_root = new Node{value, nullptr, nullptr};
                /*
                The values inside the new Node are being initialized using an initializer list. The value is set to the provided value, and both left and right pointers are set to nullptr, indicating that this node has no children yet. They follow the order of the struct definition, which is value, left, right.
                */
            }
        }
};

int main () {
    BinarySearchTree tree; 

    // Now we can call the insert function to add a value to the tree. Since the tree is initially empty, this will create the first node with the value 0. 
    // m_root -> Node{0, nullptr, nullptr}
    tree.insert(0);

    /*
    Stack:

    tree
    └── m_root ───────────┐
    Heap:                 v
                        [ 0 ]
                    /     \
                nullptr   nullptr
    */

    return 0; 
}