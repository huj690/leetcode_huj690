/*
You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
*/

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(-1), *p = dummy;
        ListNode *p1 = l1, *p2 = l2;
        
        int carry = 0;
        while (p1 || p2) {
            int num1 = p1 ? p1->val : 0;
            int num2 = p2 ? p2->val : 0;
            
            int val = (num1 + num2 + carry) % 10;
            carry = (num1 + num2 + carry) / 10;
            p->next = new ListNode(val);
            
            p = p->next;
            p1 = p1 ? p1->next : NULL;
            p2 = p2 ? p2->next : NULL;
        }
        
        p->next = carry > 0 ? new ListNode(carry) : NULL;
        return dummy->next;
        
    }
};
