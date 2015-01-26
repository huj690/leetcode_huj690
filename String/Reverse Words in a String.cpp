/*
Given an input string, reverse the string word by word.

For example,
Given s = "the sky is blue",
return "blue is sky the".
*/

class Solution {
public:
    void reverseWords(string &s) {
        if (s.empty()) {
            return;
        }
        string res = "";
        for (int i = 0; i < s.length(); i++) {
            if (s[i] ==  ' ') {
                continue;
            }
            int j = i + 1;
            while (j < s.length() && s[j] != ' ') {
                j++;
            }
            string word = s.substr(i, j - i);
            reverse(word.begin(), word.end());
            if (res.empty()) {
                res += word;
            } else {
                res += ' ' + word;
            }
            i = j;
        }
        s = res;
        reverse(s.begin(), s.end());
    }
};
