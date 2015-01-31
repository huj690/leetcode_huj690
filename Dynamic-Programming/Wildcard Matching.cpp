/*
Implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "*") → true
isMatch("aa", "a*") → true
isMatch("ab", "?*") → true
isMatch("aab", "c*a*b") → false
*/


class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        int len_s = strlen(s), len_p = strlen(p);
        vector<bool> dp_prev(len_p + 1, false);
        vector<bool> dp(len_p + 1, false);
        
        //init
        dp_prev[0] = true;
        for (int j = 1; j <= len_p; j++) {
            if (p[j - 1] != '*') {
                break;
            }
            dp_prev[j] = true;
        }
        
        //build DP
        int index_i, index_j;
        for (int i = 1; i <= len_s; i++) {
            for (int j = 1; j <= len_p; j++) {
				index_i = i - 1; 
				index_j = j - 1;
                if (s[index_i] == p[index_j] || p[index_j] == '?') {
                    dp[j] = dp_prev[j - 1];
                } else if (p[index_j] == '*') {
                    dp[j] = dp_prev[j - 1] || dp_prev[j] || dp[j - 1]; //assume 1, assume many, assume 0;
                }
            }
			dp_prev = dp;
			dp.assign(len_p + 1, false);
        }
        
        return dp_prev[len_p];
    }
};
