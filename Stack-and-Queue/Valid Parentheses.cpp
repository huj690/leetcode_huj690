/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
*/

class Solution {
public:
    bool isValid(string s) {
        if (s.empty()) {
            return true;
        }
        stack<char> stk;
        string left = "([{";
        string right = ")]}";
        for (int i = 0; i < s.length(); i++) {
           if (left.find(s[i]) != string :: npos) {
               stk.push(s[i]);
           } else {
               if (stk.empty() || stk.top() != left[right.find(s[i])]) {
                   return false;
               }
               stk.pop();
           }
        }
        return stk.empty();
    }
};
