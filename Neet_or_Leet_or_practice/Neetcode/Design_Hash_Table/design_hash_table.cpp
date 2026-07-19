// A hash table (Unordered Map) is a vector of buckets, and each bucket is the head of a small singly linked list.
#include <vector>
using namespace std;
class HashTable {

private:
    struct Node {
        int key;
        int value;
        Node* next;
    };
    int capacity;
    int size; 
    vector<Node*> buckets;

public:
    HashTable(int capacity) {
        this->size = 0;
        this->capacity = capacity;
        // create a vector with capacity elements, and initialize every element to nullptr.
        // this->buckets.assign(capacity, nullptr); also works. 
        // so if the capacity is 4 when creating this class type object, it will create 4 empty nullptr buckets. 
        this->buckets = vector<Node*>(capacity, nullptr);

        /*
        Conceptually:

        this->buckets[0] = nullptr
        this->buckets[1] = nullptr
        this->buckets[2] = nullptr
        this->buckets[3] = nullptr
        */
    }
    /*
    1. Key already exists
    → update its value
    → size does not change

    2. Key does not exist
    → create a new node
    → add it to that bucket
    → size increases
    → possibly resize
    */
    void insert(int key, int value) {
        // find the correct bucket.
        int bucket_index = key % this->capacity;
        Node* current = this->buckets[bucket_index];

        // loop through and non-empty linkedlist and replace the value with given insert value.
        while (current != nullptr) {
            if(current->key == key) {
                current->value = value;
                return;
            }
            current = current->next;
        }

        // If the execution reaches here, the key was not found.
        // the next step will create and insert a new node. 

        Node* new_node = new Node();
        new_node->key = key;
        new_node->value = value;

        // new_node->next = current;
        // current = new_node;
        // This copies the address stored in the bucket into a separate local pointer.
        // Node* current = this->buckets[bucket_index];

        new_node->next = this->buckets[bucket_index];
        this->buckets[bucket_index] = new_node;

        this->size++;
    }

    int get(int key) {
        // we are using key % capacity to determine which bucket this key will be in. 
        /*
        key 1: 1 % 4 = bucket 1
        key 5: 5 % 4 = bucket 1
        key 9: 9 % 4 = bucket 1

        Those keys collide, so they might be stored like:

        buckets[1]
            |
            v
        [key=1,value=10] -> [key=5,value=50] -> [key=9,value=90]
        */
        int bucket_index = key % this->capacity;

        Node* current = this->buckets[bucket_index];

        // if the current bucket isn't empty
        while (current != nullptr) {
            // check if the key of the current node == the key we are trying to find.
            if (current->key == key){
                return current->value;
            } 
            current = current->next;
        }
        return -1;
    }

    bool remove(int key) {
        
    }

    // the final "const" means that this function promises not to modify the HashTable object. 
    int getSize() const {
        return this->size;
    }

    int getCapacity() const {
        return this->capacity;
    }

    /*
    Doubling the bucket vector is not enough. Every existing key must be placed into a bucket again because its bucket index depends on capacity.

    For example:

    key = 5

    Old capacity = 4:
    5 % 4 = 1

    New capacity = 8:

Ask NeetBot

999798949596929390918889858687838481827879807677100101102103104105106107108$0
    5 % 8 = 5
    */

    void resize() {
        int new_capacity = this->capacity * 2;

        vector<Node*> new_buckets(new_capacity, nullptr);

        // Visit every old bucket.
        for (int i = 0; i < this->capacity; ++i) {
            Node* current = this->buckets[i];

            // Visit every node in the old bucket's chain.
            while (current != nullptr) {
                // Save the next old node before changing current->next.
                Node* next_node = current->next;

                /*===============================================*/
                // Find the node's bucket using the new capacity.
                int new_bucket_index =
                    current->key % new_capacity;

                // Insert the existing node at the front
                // of the new bucket's chain.
                current->next =
                    new_buckets[new_bucket_index];

                new_buckets[new_bucket_index] =
                    current;

                // Continue through the original old chain.
                current = next_node;
            }
        }

        this->buckets = new_buckets;
        this->capacity = new_capacity;
    }
};
