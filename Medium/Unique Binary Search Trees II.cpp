/*
又对递归理解更深入了一些~加油！！
*/
class Solution {
public:
    vector<TreeNode *> generateTrees(int n) {
        return buildTree(1, n);
    }
private:
    vector<TreeNode*> buildTree(int begin, int end) {
        vector<TreeNode*> treeList;
        if (begin > end) {
            treeList.push_back(nullptr);
            return treeList;
        }
        
        for (int rootVal = begin; rootVal <= end; rootVal++) {
            vector<TreeNode*> leftList, rightList;
            leftList = buildTree(begin, rootVal - 1);
            rightList = buildTree(rootVal + 1, end);
            
            for (int i = 0; i < leftList.size(); i++) {
                for (int j = 0; j < rightList.size(); j++) {
                    TreeNode *root = new TreeNode(rootVal);
                    root->left = leftList[i];
                    root->right = rightList[j];
                    treeList.push_back(root);
                }
            }
            
        }
        return treeList;
    }
}; 
