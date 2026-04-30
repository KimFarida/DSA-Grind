#include "ListNode.h"
class Solution {
public:
    ListNode* findMiddle(ListNode* head){
        ListNode* slow;
        ListNode* fast;
        ListNode* prev; // to break beginning from mid
        slow = fast = head;
        prev = nullptr;

        while(fast != nullptr && fast->next != nullptr){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        prev->next = nullptr;

        return slow;

    }

    ListNode* reverseList(ListNode* head){
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while(curr){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;

        }

        return prev;
    }

    ListNode* merge(ListNode* list1, ListNode* list2){
        ListNode head;
        ListNode* curr = &head;
        int i = 0;

        while(list1 && list2){
            if ( i % 2 == 0){
                curr->next = list1;
                list1=list1->next;
            }
            else{
                curr->next = list2;
                list2=list2->next;
            }

            curr = curr->next;
            i++;
        }

        if (list1){
            curr->next = list1;
        }
        if(list2){
            curr->next = list2;
        }

        return head.next;

    }

    void reorderList(ListNode* head) {
        if(head->next == nullptr){
            return;
        }
        ListNode* mid = findMiddle(head);
        ListNode* reverse = reverseList(mid);

        merge(head, reverse);
        
    }
};