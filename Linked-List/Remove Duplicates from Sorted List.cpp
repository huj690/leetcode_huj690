/*
Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.
*/

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL) {
            return head;
        }
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        
        ListNode* prev = head, *cur = head->next;
        while (cur) {
            if (prev->val == cur->val) {
                prev->next = cur->next;
                delete cur;
                cur = prev->next;
            } else {
                prev = prev->next;
                cur = cur->next;
            }
            
        }
        return dummy->next;
    }
};
