class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        vector<bool> dp(s.length(), false);
        for (int i = 0; i < s.length(); ++i) {
            for (int k = 0; k <= i; ++k) {
                bool last_word_in_dict = wordDict.find(s.substr(k, i - k + 1)) != wordDict.end();
                if (k > 0) {
                    dp[i] = dp[k - 1] && last_word_in_dict;
                } else {
                    dp[i] = last_word_in_dict;
                }
                if (dp[i]) {
                    break;
                }
            }
        }
        return dp[s.length() - 1];
    }
};
