/*
Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.

*/
class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        if (head == nullptr) {
            return head;
        }
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        
        ListNode* p = dummy; //这样停下来的时候就是最后一个节点而不是空
        int length = 0;
        while (p->next != nullptr) {
            length++;
            p = p->next;
        }
        
        k %= length; //可能k > n
        p->next = head; //连成一个环，再跑剩下的路程
        for (int i = 0; i < length - k; i++) {
            p = p->next;
        }
        
        dummy->next = p->next; //截断
        p->next = nullptr;
        
        return dummy->next;
        
    }
};
