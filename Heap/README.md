使用堆要注意的地方 <br>

struct cmp {<br>
  bool operator() (ListNode *p1, ListNode *p2) {<br>
    return p1->val > p2->val; //小顶堆<br>
  }<br>
};<br>
<br>
priority_queue<ListNode*, vector<ListNode*>, cmp> heap;<br>

