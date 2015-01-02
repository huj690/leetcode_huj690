/*
Given a string S, find the longest palindromic substring in S. 
You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
*/

/*
for (i = 0..s.length()) : assume s[i] is the palidrome's center
if the palidrome's length is odd : aba : left = i - 1; right = i + 1; cnt = 1;
if is even: abba : left = i; right = i + 1; cnt = 0;
*/

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) {
            return "";
        }
        
        int maxLength = 0;
        string res = "";
        
        //odd
        for (int i = 0; i < s.length(); i++) {
            int left = i - 1, right = i + 1, cnt = 1;
            while (left >= 0 && right <s.length() && s.at(left) == s.at(right)) {
                cnt += 2;
                left--; right++;
            }
            if (cnt > maxLength) {
                maxLength = cnt;
                res = s.substr(left + 1, right - left - 1);
            }
        }
        
        //even
        for (int i = 0; i < s.length(); i++) {
            int left = i, right = i + 1, cnt = 0;
            while (left >= 0 && right <s.length() && s.at(left) == s.at(right)) {
                cnt += 2;
                left--; right++;
            }
            if (cnt > maxLength) {
                maxLength = cnt;
                res = s.substr(left + 1, right - left - 1);
            }
        }
        
        return res;
    }
};
