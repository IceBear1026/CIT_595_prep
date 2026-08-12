/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* curr1 = l1;
        ListNode* curr2 = l2;

        int l1_number = 0;
        int place1 = 1;
        while(curr1 != nullptr) {
            // for each number multiply by 10 * n (frequency)
            l1_number += (curr1->val) * place1;
            place1 *= 10;
            // default traversing
            curr1 = curr1->next;
        }

        int l2_number = 0;
        int place2 = 1;
        while(curr2 != nullptr) {
            // for each number multiply by 10 * n (frequency)
            l2_number += (curr2->val) * place2;
            place2 *= 10;
            // default traversing
            curr2 = curr2->next;
        }
        
        // placeholder node
        ListNode* dummy = new ListNode(0);

        // pointer to build the list
        ListNode* curr = dummy;

        // currently we have curr->dummy(node[0])
        int sum = l1_number + l2_number;
        int digitcount = to_string(sum).length();
        for(int i = 0; i < digitcount; ++i){
            // this will get the remainder.
            int value = sum % 10;

            // divide the integer by 10 so remainder is gone and the next number is one digit lower.
            sum /= 10;
            curr->next = new ListNode(value);
            //traverse to next node.
            curr = curr->next;
        }

        return dummy->next;
    }
};
