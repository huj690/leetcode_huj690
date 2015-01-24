/*
Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.
*/

class Solution {
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        if (inorder.empty() || postorder.empty()) {
            return NULL;
        }
        this->postorder = postorder;
        this->inorder = inorder;
        return buildTree(0, inorder.size() - 1, 0, postorder.size() - 1);
    }
private:
    vector<int> postorder, inorder;
    TreeNode *buildTree(int inB, int inE, int postB, int postE) {
        int rootIndex = 0;
        for (int i = inB; i <= inE; i++) {
            if (inorder[i] == postorder[postE]) {
                rootIndex = i;
                break;
            }
        }
        
        int leftCnt = rootIndex - inB, rightCnt = inE - rootIndex;
        TreeNode *root = new TreeNode(postorder[postE]);
        if (leftCnt > 0) {
            root->left = buildTree(inB, rootIndex - 1, postB, postB + leftCnt - 1);   
        }
        if (rightCnt > 0) {
            root->right = buildTree(rootIndex + 1, inE, postB + leftCnt, postE - 1);
        }
        return root;
    }
};
