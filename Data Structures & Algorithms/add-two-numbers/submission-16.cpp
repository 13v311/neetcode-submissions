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

        if(curr1 == nullptr) {return curr1;}

        ListNode* l3 = new ListNode();
        ListNode* curr3 = l3;
        int result;
        int carry = 0;
        while(curr1 != nullptr) {
            int total;
            if(curr2 != nullptr) {total = curr1->val + curr2->val + carry;} 
            else {total = curr1->val + carry;}

            result = total % 10;
            carry = total / 10;

            curr3->val = result;
            if(carry > 0) {
                curr3->next = new ListNode(carry);
                curr3 = curr3->next;
            } else if(curr1->next != nullptr || (curr2 != nullptr && curr2->next != nullptr)) {
                curr3->next = new ListNode();
                curr3 = curr3->next;
            } 

            curr1 = curr1->next;
            if(curr2 != nullptr) {curr2 = curr2->next;}

            result = 0;
            //carry = 0;

        }

        while(curr2 != nullptr) {
            int total;
            total = curr2->val + carry;

            result = total % 10;
            carry = total / 10;      

            curr3->val = result;
            if(carry > 0) {
                curr3->next = new ListNode(carry);
                curr3 = curr3->next;
            } else if(curr2->next != nullptr) {
                curr3->next = new ListNode();
                curr3 = curr3->next;
            } 

            curr2 = curr2->next;
            result = 0;

        }

        return l3;
    }
};
