// Given the head of a singly linked list, reverse the list, and return the reversed list.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     
 *     These are different constructors that pass different parameters. 
 *     So this one below is a constructor that takes no parameters and sets the val to 0 and the next pointer to nullptr. 
 *     ListNode() : val(0), next(nullptr) {}
 * 
 *     This one below is a constructor that takes an integer parameter and sets the val to that integer and the next pointer to nullptr.
 *     ListNode(int x) : val(x), next(nullptr) {}
 * 
 *     This one below is a constructor that takes an integer parameter and a pointer to another ListNode and sets the val to that integer and the next pointer to that ListNode.
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    // return ListNode* (a head pointer to the reversed linked list)
    // this function takes in the linkedlist basically since the head pointer is the only way to access the linked list.
    ListNode* reverseList(ListNode* head) {
        // we can use three pointers to keep track of the previous, current, and next nodes.
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = nullptr;

        // we iterate through the linked list until we hit the end (curr becomes nullptr).
        while (curr != nullptr) {
            // we store the next node in a temporary variable.
            next = curr->next;
            // we reverse the pointer of the current node to point to the previous node.
            curr->next = prev;
            // we move the previous and current pointers forward. 
            prev = curr;

            // essentailly doing curr = curr->next because we STORED "next" in a temporary variable before we changed the pointer of the current node to point to the previous node. So we are moving forward to next node.
            curr = next;
        }

        /*
        First iteration would look like this:
        Reversed part:

        prev
        |
        v
        [1] -> nullptr


        Unprocessed part:

        curr
        |
        v
        [2] -> [3] -> nullptr

        At the end of the first iteration, the list is split into two parts:

        Reversed part:

        prev
        |
        v
        [1] -> nullptr


        Not-yet-reversed part:

        curr
        |
        v
        [2] -> [3] -> nullptr

        Technically, next also still points to node 2 from the previous iteration, but its value will immediately be replaced.

        Now the second iteration begins.

        Step 1: Save the node after curr
        next = curr->next;

        curr points to node 2, and node 2 currently points to node 3.

        Therefore:

        prev -> [1] -> nullptr

        curr -> [2] -> [3] -> nullptr
                    ^
                    |
                    next

        Or:

        prev = node 1
        curr = node 2
        next = node 3

        We save node 3 because we are about to overwrite node 2’s next pointer.

        Step 2: Reverse node 2’s pointer
        curr->next = prev;

        Currently:

        curr -> node 2
        prev -> node 1

        So this changes node 2 from pointing to node 3:

        [2] -> [3]

        to pointing backward to node 1:

        [2] -> [1] -> nullptr

        Now the structure is:

        curr
        |
        v
        [2] -> [1] -> nullptr
                ^
                |
                prev


        next
        |
        v
        [3] -> nullptr

        Notice that we did not lose node 3, because next saved its address before we changed curr->next.

        Step 3: Move prev to node 2
        prev = curr;

        Now both prev and curr temporarily point to node 2:

        prev ----+
                |
        curr ----+
                v
            [2] -> [1] -> nullptr

        next -> [3] -> nullptr

        The reversed section has now grown:

        [2] -> [1] -> nullptr
        Step 4: Move curr to node 3
        curr = next;

        Now:

        prev
        |
        v
        [2] -> [1] -> nullptr


        curr
        |
        v
        [3] -> nullptr

        At the end of the second iteration:

        Reversed part:

        prev
        |
        v
        [2] -> [1] -> nullptr


        Unprocessed part:

        curr
        |
        v
        [3] -> nullptr
        */
        return prev;
    }
};