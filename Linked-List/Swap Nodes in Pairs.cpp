/*
Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.

*/

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        
        ListNode *prev = dummy, *cur = head, *next = head->next;
        while (next) {
            prev->next = next;
            cur->next = next->next;
            next->next = cur;
            
            prev = cur;
            cur = prev->next;
            next = cur ? cur->next : NULL; // 这句写法很棒~~可以节省特判用的代码！~
        }
        
        return dummy->next;
    }
};
