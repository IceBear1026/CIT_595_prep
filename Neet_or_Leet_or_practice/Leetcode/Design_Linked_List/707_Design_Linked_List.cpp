class MyLinkedList {
private:
    struct Node {
        int val;
        Node* next;
        // double linkedlist
        Node* prev;
    };

    int size;
    Node* head;
    Node* tail;

public:
    MyLinkedList() {
        this->size = 0;
        this->head = nullptr;
        this->tail = nullptr;
    }
    
    int get(int index) {
        if (index < 0 || index >= size){
            return -1;
        }
        Node* current = this->head;
        // iterate through up until given index and in parallel go through the next node using current = current->next.
        for (int i = 0; i < index; i++){
            current = current->next;
        }
        return current->val;
    }
    
    // new_node has both prev and next. 
    void addAtHead(int val) {
        Node* new_node = new Node();
        new_node->val = val;
        // we are keep new_node->prev as nullptr because we are replacing the first node (this->head)
        new_node->prev = nullptr;
        new_node->next = this->head;

        // checking if the linkedlist is empty.
        if (this->head == nullptr) {
            this->tail = new_node;
        } else {
            // the old head now points backwards to the new node.
            this->head->prev = new_node;
        }
        this->head = new_node;
        this->size++;
    }
    
    void addAtTail(int val) {
        Node* new_node = new Node();
        new_node->val = val;
        new_node->next = nullptr;
        new_node->prev = this->tail;
        
        if (this->tail == nullptr){
            this->head = new_node;
        } else {
            this->tail->next = new_node;
        }
        this->tail = new_node;
        this->size++;
    }
    
    // I need to cover all cases:
    /*
    index > size -> do nothing
    index == 0 -> add at head
    index == size -> add at tail
    otherwise -> insert between two existing nodes
    */
    void addAtIndex(int index, int val) {
        if (index < 0 || index > this->size) {
            return;
        }

        if (index == 0) {
            this->addAtHead(val);
            return;
        }

        if (index == this->size) {
            this->addAtTail(val);
            return;
        }

        // At this point, 0 < index < size,
        // so we are definitely inserting between two existing nodes.
        Node* current = this->head;

        for (int i = 0; i < index; i++) {
            current = current->next;
        }

        Node* previous = current->prev;

        Node* new_node = new Node();
        new_node->val = val;
        new_node->prev = previous;
        new_node->next = current;

        previous->next = new_node;
        current->prev = new_node;

        this->size++;
    }
    
    void deleteAtIndex(int index) {
    // Invalid index: do nothing.
    if (index < 0 || index >= this->size) {
        return;
    }

    // Find the node at the requested index.
    Node* current = this->head;

    for (int i = 0; i < index; i++) {
        current = current->next;
    }

    Node* previous = current->prev;
    Node* next_node = current->next;

    // Update the left side.
    if (previous == nullptr) {
        // Current is the head.
        this->head = next_node;
    } else {
        previous->next = next_node;
    }

    // Update the right side.
    if (next_node == nullptr) {
        // Current is the tail.
        this->tail = previous;
    } else {
        next_node->prev = previous;
    }

    delete current;
    this->size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */