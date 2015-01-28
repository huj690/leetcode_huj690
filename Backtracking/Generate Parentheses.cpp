/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()"
*/

/*
找到backtracking类题目的窍门：
画递归树，找到限制条件，把限制条件表示出来~结束~！
*/

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if (n == 0) {
            return res;
        }
        enumParen("", 0, 0, n);
        return res;
    }
private:
    vector<string> res;
    void enumParen(string sub, int left, int right, const int &n) {
        if (left == n && right == n) {
            res.push_back(sub);
            return;
        }
        if (left < right || left > n || right > n) {
            return;
        }
        enumParen(sub + '(', left + 1, right, n);
        enumParen(sub + ')', left, right + 1, n);
    }
};
