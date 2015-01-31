/*
Implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "a*") → true
isMatch("aa", ".*") → true
isMatch("ab", ".*") → true
isMatch("aab", "c*a*b") → true
*/


class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        int s_len = strlen(s), p_len = strlen(p);
        vector<bool> dp_prev(p_len + 1, false);
        vector<bool> dp(p_len + 1, false);
        
        int index_i, index_j;
        
        //init
        dp_prev[0] = true;
        for (int j = 1; j <= p_len; j++) {
            index_j = j - 1;
            if (p[index_j] == '*') {
                if (index_j - 2 < 0 || p[index_j - 2] == '*') {
                    dp_prev[j] = true;
                    continue;
                }
                break;
            }
        }
        
        //build dp
        for (int i = 1; i <= s_len; i++) {
            for (int j = 1; j <= p_len; j++) {
                index_i = i - 1;
                index_j = j - 1;
                if (s[index_i] == p[index_j] || p[index_j] == '.') {
                    dp[j] = dp_prev[j - 1];
                }
                if (p[index_j]  == '*') {
                    if (s[index_i] == p[index_j - 1] || p[index_j - 1] =='.') {
                        dp[j] = dp_prev[j - 1] || dp_prev[j] || dp[j - 2];
                    } else {
                        dp[j] = dp[j - 2];
                    }
                }
            }
            dp_prev = dp;
            dp.assign(p_len + 1, false);
        }
        return dp_prev[p_len];
    }
};
