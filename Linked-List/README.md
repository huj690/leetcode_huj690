链表的题很简单，但是要小心

1. dummy node <br>
2. 删除 <br>
  一般情况：用两个指针prev cur <br>
  聪明的情况：走到删除节点的前一个节点 <br>
  回收：delete tmp <br>
3. 快行慢行 <br>
  while (fast->next && fast->next->next) <br>
4. 有些停止条件可以“等待” <br>
  next = cur ? cur->next : NULL; <br>
5. 合并链表不需要新开空间 <br>
  ListNode *p = dummy; <br>
  if (p1->val < p2->val) { <br>
    p->next = p1; <br>
    p1 = p1->next; <br>
  } else { <br>
    ... <br>
  } <br>
  p = p->next; <br>
6. 有时用三个指针 <br>
  prev cur next <br>
7. 写完检查代码： <br>
  1)检查链表为空的情况 <br>
  2)检查只有一个节点 <br>
  3)检查只有两个节点 <br>
