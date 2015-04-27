/*
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.
*/
/*
思路:先把重复的删掉，然后把头删掉
*/

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL) {
            return head;
        } 
        
        ListNode *dummy = new ListNode(INT_MAX); // dummy
        dummy->next = head;
        ListNode *prev = dummy, *cur = head;
        
        while (cur) {
            bool isDup = false; // 标记
            while (cur->next && cur->val == cur->next->val) { // 重复的后续全删掉
                isDup = true;
                ListNode *tmp = cur->next;
                cur->next = tmp->next;
                delete tmp;
            }
            if (isDup) { // 处理剩下的头
                prev->next = cur->next;
                delete cur;
                cur = prev->next;
            } else { // 继续前进
                prev = prev->next;
                cur = cur->next;
            }
        }
        return dummy->next;
    }
};
