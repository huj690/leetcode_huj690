/*
You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
*/
class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
       if (!l1 || !l2) {
           return !l1 ? l2 : l1;
       }
       ListNode *head = new ListNode(-1), *prev = head;
       int carry = 0;
       for (ListNode *pa = l1, *pb = l2; pa != NULL || pb != NULL; pa = pa == NULL ? NULL : pa->next, pb = pb == NULL ? NULL : pb->next) {
           int ai = pa == NULL ? 0 : pa->val;
           int bi = pb == NULL ? 0 : pb->val;
           int resi = (ai + bi + carry) % 10;
           carry = (ai + bi + carry) / 10;
           prev->next = new ListNode(resi);
           prev = prev->next;
       }
       
       if (carry > 0) {
           prev->next = new ListNode(1);
       }
       
       return head->next;
    }
};
