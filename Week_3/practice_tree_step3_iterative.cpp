#include <iostream> 

using namespace std;
// Let's now use the left and right pointers. Let's start off with iterative version first. 
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

        void insert(int value) {
            // Case 1: The tree is empty.
            if (m_root == nullptr) {
                m_root = new Node{value, nullptr, nullptr};
                return;
            }

            // Start at the root and travel through the tree.
            
            // "current" node pointer is receiving the m_root pointer memory address and so current is now pointing at the root node. This will help us keep track of where we are in the tree as we traverse it.
            Node* current = m_root;

            // Case 2: The tree is not empty. We need to find the correct location for the new value.

            // while(true) will keep looping until we find the correct location for the new value. We will break out of the loop when we find the correct location.
            while (true) {
                if(value < current->value) {
                    // The new value belongs somewhere on the left side of the current node.
                    if (current->left == nullptr) {
                        current->left = new Node{value, nullptr, nullptr};
                        return;
                    }

                    // A left child already exists, so continue downward.
                    current = current->left;
                } else if (value > current->value) {
                    // the new value belongs somewhere on the right.
                    if (current->right == nullptr) {
                        current->right = new Node{value, nullptr, nullptr};
                        return;
                    }

                    current = current->right;
                }
                else {
                    // the value already exists, so ignore the duplicate.
                    return;
                }
            }
        }
};

int main () {
    BinarySearchTree tree; 
    tree.insert(0);
    tree.insert(8);
    tree.insert(3);
    tree.insert(10);
    tree.insert(1);
    tree.insert(6);
    return 0; 
}