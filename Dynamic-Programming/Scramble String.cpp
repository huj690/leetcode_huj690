/*
Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.
Below is one possible representation of s1 = "great":
    great
   /    \
  gr    eat
 / \    /  \
g   r  e   at
           / \
          a   t
To scramble the string, we may choose any non-leaf node and swap its two children.
For example, if we choose the node "gr" and swap its two children, it produces a scrambled string "rgeat".
    rgeat
   /    \
  rg    eat
 / \    /  \
r   g  e   at
           / \
          a   t
We say that "rgeat" is a scrambled string of "great".
Similarly, if we continue to swap the children of nodes "eat" and "at", it produces a scrambled string "rgtae".
    rgtae
   /    \
  rg    tae
 / \    /  \
r   g  ta  e
       / \
      t   a
We say that "rgtae" is a scrambled string of "great".
Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1.
*/

/*
思路：
递归+剪枝
如果相等，返回true
如果长度不等，返回false
如果包含的字母不同，返回false

枚举分割位置i = 1..len-1： isScramble(前i个, 前i个) && isScramble(后len - i个, 后len - i个) || isScramble(前i个, 后i个) && isScramble(后len - i个, 前len - i个)
*/
class Solution {
public:
    bool isScramble(string s1, string s2) {
        // lengths are same
        if (s1 == s2) {
            return true;
        }
        if (s1.size() != s2.size()) {
            return false;
        }
        
        // characters are same
        vector<int> dic(26, 0);
        int len = s1.size();
        for (int i = 0; i < len; i++) {
            dic[s1[i] - 'a']++;
            dic[s2[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++) {
            if (dic[i] != 0) {
                return false;
            }
        }
        
        for (int i = 1; i < len; i++) {
            if ((isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i, len - i), s2.substr(i, len - i)))
                ||  (isScramble(s1.substr(0, i), s2.substr(len - i, i)) && isScramble(s1.substr(i, len - i), s2.substr(0, len - i)))) {
                    return true;
                }
        }
        return false;
    }
};
