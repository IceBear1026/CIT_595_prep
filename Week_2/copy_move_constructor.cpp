#include <cstddef>
#include <iostream>
#include <utility>
#include <string> 

using namespace std;

class LinkedList {
    private:
        struct Node {
            string value;
            Node* next;
        };

        Node* m_head;
        Node* m_tail;
        size_t m_len;
    
    public:
        // default constructor
        LinkedList() : m_head(nullptr), m_tail(nullptr), m_len(0) {}

        // Copy Constructor
        LinkedList(const LinkedList& other) : m_head(nullptr), m_tail(nullptr), m_len(0){
            // create an independent deep copy
            Node* current = other.m_head;

            // Walk through every node in other
            while (current != nullptr) {
                // This is the first node
                this->m_head = new_node;
                this->m_tail = new_node;
            } else {
                // attach the new node after the current tail
                this->m_tail->next = new_node;
                this->m_tail = new_node;
            }
            ++this->m_len;
            current = current->next;
        }

        // Move Constructor
        LinkedList(LinkedList&& other) : m_head(nullptr), m_tail(nullptr), m_len(0) {
            // Take ownership of other's nodes
            this->m_head = other.m_head;
            this->m_tail = other.m_tail;
            this->m_len = other.m_len;

            // Make other an empty valid list
            other.m_head = nullptr;
            other.m_tail = nullptr;
            other.m_len = 0;

        }
};