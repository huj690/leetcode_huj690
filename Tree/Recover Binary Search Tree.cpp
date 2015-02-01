/*
Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.

Note:
A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?
*/

/*
solution:
inorder travel all tree, meanwhile recode the previous of the root
if (root->val > prev->val) two case must be considered:
1. prev and root are both wrong.
2. prev is wrong, and there another wrong node behind.
*/


class Solution {
public:
    void recoverTree(TreeNode *root) {
        if (!root) {
            return;
        }
        TreeNode *prev;
        node1 = node2 = prev = NULL;
        inOrder(root, prev);
        swap(node1->val, node2->val);
    }
private:
    TreeNode *node1, *node2;
    void inOrder(TreeNode* root, TreeNode* &prev) {
        if (!root) {
            return;
        }
        inOrder(root->left, prev);
        if (prev && root->val < prev->val) {
            if (!node2) {
                node1 = prev;
                node2 = root;
            } else {
                node2 = root;
            }
        }
        prev = root;
        inOrder(root->right, prev);
    }
};
