/*
Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

a) Insert a character
b) Delete a character
c) Replace a character
*/

class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<int> dp_prev(word1.length() + 1, 0);
        vector<int> dp = dp_prev;
        
        //init
        for (int j = 0; j <= word1.length(); j++) {
            dp_prev[j] = j;
        }
        
        //build dp
        int i_index, j_index;
        for (int i = 1; i <= word2.length(); i++) {
            dp[0] = i;
            for (int j = 1; j <= word1.length(); j++) {
                i_index = i - 1;
                j_index = j - 1;
                dp[j] = min (dp_prev[j], 
                        min(dp[j - 1], 
                        word2[i_index] == word1[j_index] ? dp_prev[j - 1] - 1 : dp_prev[j - 1]
                        )) + 1;
            }
            dp_prev = dp;
            dp.assign(word1.length() + 1, 0);
        }
        return dp_prev[word1.length()];
     }
};


//滚动数组
class Solution {
public:
    int minDistance(string word1, string word2) {
        if (word2.length() < word1.length()) {
            return minDistance(word2, word1);
        }
        vector<int> dp(word1.length() + 1, 0);
        int upper_left = 0; // dp[i - 1][j - 1]
        
        // init
        for (int j = 0; j <= word1.length(); j++) {
            dp[j] = j;
        }
        
        // build dp
        for (int i = 1; i <= word2.length(); i++) {
            upper_left = dp[0];
            dp[0] = i;
            
            for (int j = 1; j <= word1.length(); j++) {
                int upper = dp[j];
                dp[j] = min (dp[j], min(dp[j - 1], word2[i - 1] == word1[j - 1] ? upper_left - 1 : upper_left)) + 1;
                upper_left = upper;
            }
        }
        return dp[word1.length()];
     }
};
