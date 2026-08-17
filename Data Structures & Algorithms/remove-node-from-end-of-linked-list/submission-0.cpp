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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //im thinking to go through the whole list once to figure out the total length. once we figure that out, then we can go to the index length - n which happens to be the nth node from the end
        ListNode* curr = head;
        int length = 0;
        if(curr == nullptr) {return head;}
        else {
            while(curr != nullptr) {
                length++;
                curr = curr->next;
            }
        }

        int index = length - n; //this is the index we want to get to
        curr = head;
        int count = 0;
        if(index == 0) {
            curr = curr->next;
            return curr;
        } else {
            while(count < index-1) {
                count++;
                curr = curr->next;
            }
            ListNode* newNext = curr->next->next;
            curr->next = newNext;
        }

        
        return head;
    }
};
