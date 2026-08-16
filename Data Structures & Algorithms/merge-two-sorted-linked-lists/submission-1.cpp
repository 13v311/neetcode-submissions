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

//i made entirely new nodes each time but that is nt necessary for this problem
//u can reuse the existing ones
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy(0);
        ListNode* merged = &dummy;

        while(list1 != nullptr && list2 != nullptr) {
            if(list1->val <= list2->val) {
                ListNode* newNode = new ListNode(list1->val);
                merged->next = newNode;
                merged = merged->next;
                list1 = list1->next;
            } else {
                ListNode* newNode = new ListNode(list2->val);
                merged->next = newNode;
                merged = merged->next;
                list2 = list2->next;
            }
  
        }

        if(list1 != nullptr) {
            while(list1 != nullptr) {
                ListNode* newNode = new ListNode(list1->val);
                merged->next = newNode;
                merged = merged->next;
                list1 = list1->next;
            }
        } else if(list2 != nullptr) {
            while(list2 != nullptr) {
                ListNode* newNode = new ListNode(list2->val);
                merged->next = newNode;
                merged = merged->next;
                list2 = list2->next;
            }
        }
        return dummy.next;
    }
};
