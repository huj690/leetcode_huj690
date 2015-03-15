
class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> res;
        if (root == NULL) {
            return res;
        }
        
        TreeNode* prev = NULL;
        push_left(root);
        while (!stk.empty()) {
            auto cur = stk.top();
            while (cur->right && prev != cur->right) {
                push_left(cur->right);
                cur = stk.top();
            } 
            prev = cur;
            res.push_back(cur->val);
            stk.pop();
        }
        return res;
    }
private:
    stack<TreeNode*> stk;
    void push_left(TreeNode *root) {
        while (root != NULL) {
            stk.push(root);
            root = root->left;
        }
    }
};
