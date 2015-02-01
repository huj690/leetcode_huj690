/*
Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

For example,
Given:
s1 = "aabcc",
s2 = "dbbca",

When s3 = "aadbbcbcac", return true.
When s3 = "aadbbbaccc", return false.
*/

/*
滚动数组：
dp[i - 1][j] 可以表示为 dp[j]
dp[i][j - 1] 可以表示为 dp[j - 1]
*/


class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s3.length() != s1.length() + s2.length()) {
            return false;
        }
        
        if (s1.length() > s2.length()) {
            isInterleave(s2, s1, s3);
        }
        
        vector<bool> dp(s2.length() + 1, false);
        
        // init
        dp[0] = true;
        for (int j = 1; j <= s2.length(); j++) {
            dp[j] = s2[j - 1] == s3[j - 1] && dp[j - 1];
        }
        
        // build dp
        for (int i = 1; i <= s1.length(); i++) {
            dp[0] = s1[i - 1] == s3[i - 1] && dp[0];
            
            for (int j = 1; j <= s2.length(); j++) {
                dp[j] = dp[j] && (s3[i + j - 1] == s1[i - 1])
                    || dp[j - 1] && (s3[i + j - 1] == s2[j - 1]);
            }
        }
        
        return dp[s2.length()];
    }
};
