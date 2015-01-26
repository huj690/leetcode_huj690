class Solution {
public:
    string addBinary(string a, string b) {
        string res = "";
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int length = max(a.length(), b.length());
        int carry = 0;
        for (int i = 0; i < length; i++) {
            int ai = i < a.length() ? a[i] - '0' : 0;
            int bi = i < b.length() ? b[i] - '0' : 0;
            int resi = (ai + bi + carry) % 2;
            carry = (ai + bi + carry) / 2;
            res += to_string(resi);
        }
        if (carry > 0) {
            res += '1';
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
