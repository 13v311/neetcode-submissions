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
    bool hasCycle(ListNode* head) {
        if(head == nullptr) {return false;}
        ListNode* slow = head;
        ListNode* fast = slow->next;

        while(fast != nullptr) {
            if(slow == fast) {return true;}
            slow = slow->next;
            if(fast->next != nullptr) {fast = fast->next->next;} 
            else {return false;}
        }
        return false;
    }
};
