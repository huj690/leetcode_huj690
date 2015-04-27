/*
Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You must do this in-place without altering the nodes' values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}.
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode *head) {
        if (head == NULL) {
            return;
        }
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        
        ListNode *fast = head, *slow = head;
        while (fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        
        ListNode *p1 = head, *p2 = reverse(slow->next), *p = dummy; // reverse
        slow->next = NULL; // cut off
        
        while (p1 && p2) { // merge
            p->next = p1;
            p1 = p1->next;
            p = p->next;
            
            p->next = p2;
            p2 = p2->next;
            p = p->next;
        }
        p->next = p1 ? p1 : p2;
    }
    
private:
    ListNode* reverse(ListNode *head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode *prev = head, *cur = head->next, *next = cur->next;
        prev->next = NULL;
        while (1) {
            cur->next = prev;
            if (next == NULL) {
                break;
            }
            prev = cur;
            cur = next;
            next = next->next;
        }
        return cur;
    } 
};
