struct cmp {
    bool operator() (ListNode *p1, ListNode *p2) {
        return p1->val > p2->val;
    }
};
class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if (lists.empty()) {
            return NULL;
        }
        
        priority_queue<ListNode*, vector<ListNode*>, cmp> heap;
        for(int i = 0; i < lists.size(); i++) {
            if (lists[i]) {
                heap.push(lists[i]);
            }
        }
        
        ListNode *dummy = new ListNode(-1), *p = dummy;
        while (!heap.empty()) {
            auto top = heap.top();
            heap.pop();
            p->next = top;
            p = p->next;
            if (top->next) {
                heap.push(top->next);
            }
        }
        return dummy->next;
        
        
    }
};
