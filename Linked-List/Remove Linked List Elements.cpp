/*
Remove all elements from a linked list of integers that have value val.

Example
Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
Return: 1 --> 2 --> 3 --> 4 --> 5
*/

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (head == NULL) {
            return head;
        }
        
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        
        ListNode *prev = dummy, *cur = head;
        while (cur) {
            if (cur->val == val) {
                prev->next = cur->next;
                delete cur;
                cur = prev->next;
            } else {
                prev = cur;
                cur = cur->next;
            }
            
        }
        return dummy->next;
    }
};
