/*
Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).
For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
]
*/

/*
注意点：
1. 当前que的size大小就是该层节点个数：
while (!q.empty()){
  int n = q.size();
  while (n--){
    ......
  }
}
*/


/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int>> res;
        if (root == nullptr){
            return res;
        }
        
        queue<TreeNode*> q;
        vector<int> levelList;
        q.push(root);
        
        while (!q.empty()){
            int n = q.size();
            while (n--){
                TreeNode* node = q.front();
                q.pop();
                levelList.push_back(node -> val);
                if (node -> left != nullptr){
                    q.push(node -> left);
                }
                if(node -> right != nullptr){
                    q.push(node -> right);
                }
            }
            res.push_back(levelList);
            levelList.clear();
        }
        return vector<vector<int>> (res.rbegin(), res.rend());
    }
};
