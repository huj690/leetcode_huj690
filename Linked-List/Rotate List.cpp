/*
Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.

*/
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || k == 0) {
            return head;
        }
        
        int len = 1;
        ListNode *p = head;
        while (p->next) { // 求长度
            len++;
            p = p->next;
        }
        p->next = head; // 首尾相连
        
        k = len - k % len;
        while (k--) { // 接着往后跑
            p = p->next;
        }
        
        head = p->next;
        p->next = NULL; // 截断
        return head;
    }
};
