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


        Node* insert_node(Node* current, int value) {
            if (current == nullptr) {
                return new Node{value, nullptr, nullptr};
            }
            if (value < current->value) {
                current->left = insert_node(current->left, value);
            } else if (value > current->value) {
                current->right = insert_node(current->right, value);
            }
            return current;
        }

        // checking if the node exists in the tree.
        // A pattern I noticed when dealing with linkedlist or tree is that we have to check these two important edge cases before we can worry about the actual traversal. It's to check whether the initial pointer is pointing at anything (nullptr) and next is doing an exclusive checks for one node lists/trees. 
        bool contains_node(Node* current, int target){
            if (current == nullptr) {
                return false;
            }
            if (current->value == target) {
                return true;
            }

            if (target < current->value) {
                return contains_node(current->left, target);
            } 
            
            return contains_node(current->right, target);
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

    cout << boolalpha;

    cout << "Contains 6: " << tree.contains(6) << '\n';
    cout << "Contains 7: " << tree.contains(7) << '\n';
    cout << "Contains 8: " << tree.contains(8) << '\n';

    return 0; 
}