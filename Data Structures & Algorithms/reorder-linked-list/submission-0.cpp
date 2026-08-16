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
    void reorderList(ListNode* head) {
        int length = 0;

        ListNode* curr = head;
        ListNode* result = curr;
        ListNode* tail = head;

        while(tail != nullptr) {
            length++;
            tail = tail->next;
        }
        tail = head;
        //im thinking to reverse the list so that we can have a pointer at the front and back of it; i was close, but the issue is that will universally change the list and curr will go from the beginning of the list straight to nullptr. i need to reverse only half of the list so that we can still have some of the existing order that we need

        int count = length / 2;
        while(count > 0) {
            tail = tail->next;
            count--;
        }

        ListNode* prev = nullptr;
        while(tail != nullptr) { //reverse list logic
            ListNode* next = tail->next;
            tail->next = prev;
            prev = tail;
            tail = next;
        }
        //tail will be nullptr, so instead we start with prev as the tail end of the list

        tail = prev;
        //prev = curr;
        while(tail != nullptr && tail != curr) {
            ListNode* currNext = curr->next; //save the next
            ListNode* tailNext = tail->next;
            //if(tail == nullptr) {break;} 
            curr->next = tail; //first the next is the tail
            tail = tailNext;
            if(tail == nullptr) {break;}
            curr = curr->next;
            curr->next = currNext; //then the next next is the original next 
            curr = curr->next;
        }

        

    }
};
