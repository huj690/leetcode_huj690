/*
Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
 */
 
 /*
 有个地方处理不好，就是fast指针什么时候停的问题
 所以把单链表结构改变了
 */
class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        if (head == NULL) {
            return NULL;
        }
        ListNode *end = head;
        while (end->next != NULL) {
            end = end->next;
        }
        return buildBST(head, end);
    }

private:
    TreeNode *buildBST(ListNode* begin, ListNode* end) {
        if (begin == NULL || end == NULL) {
            return NULL;
        }
        if (begin == end) {
            return new TreeNode(begin->val);
        }
        ListNode *dummy = new ListNode(-1);
        dummy->next = begin;
        
        ListNode *fast = begin, *slow = begin, *prev = dummy;
        while (fast != end && fast != NULL) {
            fast = fast->next->next;
            slow = slow->next;
            prev = prev->next;
        }
        prev->next = NULL;
        TreeNode *root = new TreeNode(slow->val);
        root->left = buildBST(begin, prev);
        root->right = buildBST(slow->next, end);
        return root;
    }
    
    
    
        
};
