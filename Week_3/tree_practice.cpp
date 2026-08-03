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
            // We found an empty position for the new node.
            // so this means the current node we received is nullptr, and we can create a new node here. This means there is a space after looping through the tree and we can insert the new node here.
            if (current == nullptr) {
                // after creating a new Node, we are turning it with the value we want to insert along with both left and right null pointers.
                return new Node{value, nullptr, nullptr};
            }
            
            // so if the the current value is less than the value we have, it will go left side. 
            if (value < current->value) {
                // this is a nested call to the insert_node function, and we are passing the left child of the current node as the new current node, and the value we want to insert. This will continue until we find a nullptr position to insert the new node. 
                current->left = insert_node(current->left, value);
            } else if (value > current->value) {
                // if the value is greater than the current value, it will go to the right side until we see the nullptr position to insert the new node.
                current->right = insert_node(current->right, value);
            }

            // if value == current->value, ignore the duplicate. 
            return current;
        }

        // we are writing a function to check if a node with a specific value exists in the tree. So we receive the current and the target value we are looking for. If the current node is nullptr, we return false. 
        bool contains_node(Node* current, int target) const {

            // if it's nullptr then the node is not found, so we return false. Basically it hit the end of the tree and didn't find the target value.
            if (current == nullptr) {
                return false; 
            }

            // this is checking after recursive loop if the current node's value is equal to the target value, then we found the node and return true.
            if (target == current->value) {
                return true; 
            }

            // this is iterating over the nodes depending on the value of the node. 
            if (target < current->value) {
                return contains_node(current->left, target);
            } 

            return contains_node(current->right, target);
            }

        void print_in_order(Node* current) const {
            // if the current node is nullptr, we return This means we have reached the end of the tree. 
            if(current == nullptr) {
                // return ends the loop/function.
                return;
            }

            // this is basically trying to list out in a ordered value. So we are going to the left side of the tree first, then printing the current node's value, and then going to the right side of the tree. This is a recursive function that will continue until it reaches the end of the tree.
            print_in_order(current->left);
            cout << current->value << " ";
            print_in_order(current->right);
        }
        void clear(Node* current) {
            if (current == nullptr) {
                return; 
            }

            clear(current->left);
            clear(current->right);

            delete current;
        }
    public:
        // this is a constructor with initializer list with it's member variable m_root being initialized with nullptr because usually first pointer will have to point to nullptr because there is no node in the tree yet.
        BinarySearchTree() : m_root(nullptr) {}

        ~BinarySearchTree() {
            clear(m_root);
        }

        // Disable copying for now because the default copy would be shallow. 
        BinarySearchTree(const BinarySearchTree&) = delete; 
        BinarySearchTree& operator=(const BinarySearchTree&) = delete;

        void insert(int value) {
            m_root = insert_node(m_root, value);
        }

        bool contains(int target) const {
            return contains_node(m_root, target);
        }

        void print() const {
            print_in_order(m_root);
            cout << endl;
        }

}
