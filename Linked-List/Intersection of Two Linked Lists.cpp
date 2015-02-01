/*
Write a program to find the node at which the intersection of two singly linked lists begins.


For example, the following two linked lists:

A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗            
B:     b1 → b2 → b3
begin to intersect at node c1.


Notes:

If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.
*/
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *pa = headA, *pb = headB;
        while (pa != NULL && pb != NULL) {
            pa = pa->next;
            pb = pb->next;
        }
        
        int cnt = 0;
        ListNode *fast = pa == NULL ? headB : headA;
        ListNode *slow = pa == NULL ? headA : headB;
        
        for (;  pa != NULL || pb != NULL; 
                pa = pa == NULL ? NULL : pa->next, pb = pb == NULL ? NULL : pb->next) {
            cnt++;
        }
        
        for (int i = 0; i < cnt; i++) {
            fast = fast->next;
        }
        while (fast != slow && fast != NULL && slow != NULL) {
            fast = fast->next;
            slow = slow->next;
        }
        
        if (fast == slow) {
            return fast;
        }
        return NULL;
    }
};
