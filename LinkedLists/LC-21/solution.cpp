#include "ListNode.h"
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // so the idea is to splice 
        // for each time a connection is to be made ?
        // I can save the next in a temp and move curr 
        // 1 temp = 2->4
        // 1->1-> curr becomes the second "1"
        // list1 becomes temp
        // 1 against 2, attach 2 
        // hold the next of 2 
        // 1->1->2
        ListNode* head = new ListNode();
        ListNode* curr = head;

        while(list1 && list2){
            if(list1->val < list2->val){
                curr->next = list1;
                list1 = list1->next;

            }
            else{
                curr->next = list2;
                list2 = list2->next;
            }

            curr = curr->next;
        }
        if (list1 != nullptr){
            curr->next = list1;
        }

        if (list2 != nullptr){
            curr->next = list2;
        }
        return head->next;
    }
};