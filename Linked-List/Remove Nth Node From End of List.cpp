/*
Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
Try to do this in one pass.
*/


class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if (head == nullptr) {
            return head;
        }
        
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        
        ListNode *fast = dummy, *slow = dummy;
        for (int i = 0; i < n; i++) {
            if (fast == nullptr) { //判断合法
                return head;
            }
            fast = fast->next;
        }
        
        while (fast->next != nullptr) { //fast->next，这样控制住slow为要删除节点的前驱
            fast = fast->next;
            slow = slow->next;
        }
        
        ListNode *tmp = slow->next; //这样才能delete
        slow->next = slow->next->next;
        delete tmp;
        
        return dummy->next;
        
    }
};
