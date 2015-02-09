/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
 
 /*
    第一步：将每个节点复制并插入相邻节点中。如1->2->3->NULL变为：1->1'->2->2'->3->3'->NULL。
    第二步：接下来连接Random指针，如果存在一条Random指针从A指向B，那么将A->next的Random指针指向B->next。
    第三步：将链表拆开。A=head, A'=head->next;  A->next=A->next->next；A'->next=A'->next->next; ...
    时间复杂度O(n)，额外空间复杂度O(1)
 */
 
typedef RandomListNode RListNode;
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head == NULL) {
            return NULL;
        }
        for (RandomListNode *p = head; p != NULL; p = p->next->next) {
            RandomListNode *tmp = new RandomListNode(p->label);
            tmp->next = p->next;
            p->next = tmp;
        }
        
        for (RandomListNode *p = head; p != NULL; p = p->next->next) {
            if (p->random) {
                p->next->random = p->random->next;
            }
        }
        RandomListNode *dummy = new RandomListNode(-1);
        dummy->next = head;
        for (RandomListNode *newp = dummy, *p = head; p != NULL; newp = newp->next, p = p->next) {
            newp->next = newp->next->next;
            p->next = p->next->next;
        }
        return dummy->next;
    }
};
