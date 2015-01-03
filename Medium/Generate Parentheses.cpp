/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
For example, given n = 3, a solution set is:
"((()))", "(()())", "(())()", "()(())", "()()()"
*/
/*
Pay attention:
    the first place must be "(", and the last place must be ")"
    int left: currently "(" numbers
    int right: currently ")" numbers
*/

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if (n == 0) {
            return res;
        }    
		this->n = n;
		enumParent("", 0, n);
		return res;
    }
private:
	int n;
    vector<string> res;
    void enumParent(string s, int left, int right) {
        if (left == n && right == n) {
			res.push_back(s);
			return;
        }
		if (left < n) {
			enumParent(s + '(', left + 1, right - 1);
		}
		if (right < n) {
			enumParent(s + ')', left, right + 1);
		}
    }
	
};
