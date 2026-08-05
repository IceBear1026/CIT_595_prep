#include <iostream> 

using namespace std;

// when creating a tree, we will need to create a class for the node of the tree. 

class BinarySearchTree {
    private:
        // This is simple enough where we are creating a private Node struct which will contain the value and the pointers for left and right. 
        struct Node {
            int value;
            Node* left;
            Node* right;
        };
        // We have to start somewhere, so we will create a pointer that will point to the root of the tree and we are calling it m_root.
        Node* m_root;

    public:
        // We will create a constructor for the BinarySearchTree class that will initialize the m_root pointer to nullptr, indicating that the tree is initially empty. 

        // this way is initializer list within a constructor. 
        BinarySearchTree() : m_root(nullptr) {}

        /*
        You can also initialize the m_root pointer to nullptr in the constructor body like this:
        BinarySearchTree() {
            m_root = nullptr;
        }
        */
};

int main () {
    // This creates the BinarySearchTree object called tree. It will trigger the initializer list constructor and point its m_root pointer to nullptr.
    BinarySearchTree tree; 

    return 0; 
}