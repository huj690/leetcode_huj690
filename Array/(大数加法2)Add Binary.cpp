/*
Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".
*/

class Solution {
public:
    string addBinary(string a, string b) {
        if (a.empty()) {
            return b;
        }
        if (b.empty()) {
            return a;
        }
        int max_len = a.size() > b.size() ? a.size() : b.size();
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        
        string res = "";
        int carry = 0;
        for (int i = 0; i < max_len; i++) {
            int numa = i < a.size() ? a[i] - '0' : 0;
            int numb = i < b.size() ? b[i] - '0' : 0;
            int val = (numa + numb + carry) % 2;
            carry = (numa + numb + carry) / 2;
            res.insert(res.begin(), val + '0');
        }
        if (carry > 0) {
            res.insert(res.begin(), '1');
        }
        return res;
    }
};
