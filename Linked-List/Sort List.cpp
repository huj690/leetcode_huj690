/*
Sort a linked list in O(n log n) time using constant space complexity.
*/
class Solution {
public:
    ListNode *sortList(ListNode *head) {
        if (head == NULL || head->next == NULL) { // 注意！
            return head;
        }
        ListNode *fast = head, *slow = head;
        while (fast->next != NULL && fast->next->next != NULL) { // 注意！！！
            fast = fast->next->next;
            slow = slow->next;
        }
        fast = slow->next;
        slow->next = NULL;
        
        ListNode *l1 = sortList(head);
        ListNode *l2 = sortList(fast);
        
        return merge(l1, l2); // 注意！！
    }
    
private:
    ListNode *merge(ListNode *pa, ListNode* pb) {
        ListNode *dummy = new ListNode(-1), *p = dummy;
        for (; pa != NULL && pb != NULL; p = p->next) {
            if (pa->val < pb->val) {
                p->next = pa;
                pa = pa->next;
            } else {
                p->next = pb;
                pb = pb->next;
            }
        }
        p->next = pa ? pa : pb;
        return dummy->next;
    }
};
