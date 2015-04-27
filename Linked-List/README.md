链表的题很简单，但是要小心

1. dummy node
2. 删除
  一般情况：用两个指针prev cur
  聪明的情况：走到删除节点的前一个节点
  回收：delete tmp
3. 快行慢行
  while (fast->next && fast->next->next)
4. 有些停止条件可以“等待”
  next = cur ? cur->next : NULL;
5. 合并链表不需要新开空间
  ListNode *p = dummy;
  if (p1->val < p2->val) {
    p->next = p1;
    p1 = p1->next;
  } else {
    ...
  }
  p = p->next;
6. 有时用三个指针
  prev cur next
7. 写完检查代码：
  1)检查链表为空的情况
  2)检查只有一个节点
  3)检查只有两个节点
