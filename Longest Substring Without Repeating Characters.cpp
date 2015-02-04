/*
Given a string, find the length of the longest substring without repeating characters. For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) {
            return 0;
        }
        vector<int> last(255, -1);
        int i = 0, j = i, max_len = -1;
        while (i < s.length()) {
            while (j < s.length() && last[s[j]] == -1) {
                last[s[j]] = j;
                j++;
            }
            max_len = max(max_len, j - i);
            if (j >= s.length() - 1) {
                break;
            }
            while (i < last[s[j]] + 1) {
                last[s[i]] = -1;
                i++;
            }
        }
        return max_len;
    }
};
