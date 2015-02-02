/*
Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 ≤ m ≤ n ≤ length of list.
*/

/*
找到prev和pn的位置，
每次把prev下一个节点挪到pn的下一个就可以了
*/
class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if (m >= n) {
            return head;
        }
        
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        
        ListNode *pn = dummy, *prev;
        for (int i = 0; i < n; i++) {
            if (i == m - 1) {
                prev = pn;
            }
            pn = pn->next;
        }
        ListNode *cur = prev->next;
        while (cur != pn) {
            prev->next = cur->next;
            cur->next = pn->next;
            pn->next = cur;
            
            cur = prev->next;
        }
        return dummy->next;
    }
};
