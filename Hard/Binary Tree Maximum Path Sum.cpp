/**
Given a binary tree, find the maximum path sum.
The path may start and end at any node in the tree.
For example:
Given the below binary tree,
       1
      / \
     2   3
Return 6.
 */
 
 
class Solution {
public:
    int maxPathSum(TreeNode *root) {
        if (!root) {
            return 0;
        }
        globalMax = INT_MIN;
        enumMaxPathSum(root);
        return globalMax;
    }
private:
    int globalMax;
    int enumMaxPathSum(const TreeNode* root) {
        if (!root) {
            return 0;
        }
        int sum = root->val; //sum means: though this root, can get maxSum = sum
        int leftSum = enumMaxPathSum(root->left);
        int rightSum = enumMaxPathSum(root->right);
        
        if (leftSum > 0) {
            sum += leftSum;
        }
        if (rightSum > 0) {
            sum += rightSum;
        }
        
        globalMax = max(globalMax, sum);
        return max(leftSum, rightSum) > 0 ? max(leftSum, rightSum) + root->val : root->val; //回溯时只能选择一边！
    }
};
