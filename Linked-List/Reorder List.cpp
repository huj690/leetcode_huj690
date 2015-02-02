/*
Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You must do this in-place without altering the nodes' values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}.
*/
class Solution {
public:
    void reorderList(ListNode *head) {
        if (head == NULL || head->next == NULL) {
            return;
        }
        
        ListNode *fast = head, *slow = head;
        while (fast->next != NULL && fast->next->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }
        
        // reverse after mid
        reverseList(slow);
        
        // merge 2 list
        ListNode *p1 = head, *p2 = slow->next;
        while (p1 != slow) {
            slow->next = p2->next;
            p2->next = p1->next;
            p1->next = p2;
            
            p1 = p2->next;
            p2 = slow->next;
        }
    }
private:
    void reverseList(ListNode *prev) {
        if (prev == NULL || prev->next == NULL) {
            return;
        }
        
        ListNode *last = prev;
        while (last->next != NULL) {
            last = last->next;
        }
        ListNode *cur = prev->next;
        while (cur != last) {
            prev->next = cur->next;
            cur->next = last->next;
            last->next = cur;
            
            cur = prev->next;
        }
    }
};
