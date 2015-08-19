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
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode *first = head;
        ListNode *second = splitList(head);
        first = sortList(first);
        second = sortList(second);
        return merge(first, second);
    }
private:
    ListNode* splitList(ListNode* head) {
        ListNode* fast = head, *slow = head, *prev = NULL;
        while (fast && fast->next) {
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }
        if (prev) {
            prev->next = NULL;
        }
        return slow;
    }
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(-1), *p = dummy;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                p->next = l1;
                l1 = l1->next;
            } else {
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }
        p->next = l1 ? l1 : l2;
        p = dummy->next;
        delete dummy;
        dummy = NULL;
        return p;
    }
};
