#include <iostream> 

using namespace std;
// Let's now use the left and right pointers. Let's try recursive version.
class BinarySearchTree {
    private:
        struct Node {
            int value;
            Node* left;
            Node* right;
        };
        Node* m_root;

        // Recursive helper function
        // This function will insert a new node with the given value into the tree. The reason why we are passing "current" is because we will use that to recursively traverse the tree.
        Node* insert_node(Node* current, int value) {
            // Base case: we found an empty location
            if (current == nullptr) {
                return new Node{value, nullptr, nullptr};
            }
            // Recursive case: traverse the tree
            if (value < current->value) {
                current->left = insert_node(current->left, value);
            } else if (value > current->value) {
                current->right = insert_node(current->right, value);
            }
            // return the root of this subtree.
            return current;
        }


    public:
        BinarySearchTree() : m_root(nullptr) {}

        void insert(int value) {
            m_root = insert_node(m_root, value);
        }
};

int main () {
    BinarySearchTree tree; 
    tree.insert(8);
    tree.insert(3);
    tree.insert(10);
    tree.insert(1);
    tree.insert(6);
    tree.insert(14);
    tree.insert(4);
    return 0; 
}