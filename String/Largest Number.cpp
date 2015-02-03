/*
Given a list of non negative integers, arrange them such that they form the largest number.
For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.
Note: The result may be very large, so you need to return a string instead of an integer.
*/

/*
注意cmp要写在class的外面
注意处理00000的情况
注意溢出的情况
*/
bool cmp (string a, string b) {
    return a + b > b + a;
}
class Solution {
public:
    string largestNumber(vector<int> &num) {
        if (num.empty()) {
            return "";
        }
        
        vector<string> num_str;
        for (auto i : num) {
            num_str.push_back(to_string(i));
        }
        sort(num_str.begin(), num_str.end(), cmp);
        string res = "";
        
        int i = 0;
        while (i < num_str.size() && num_str[i] == "0") {
            i++;
        }
        for (i; i < num_str.size(); i++) {
            res += num_str[i];
        }
        return res.empty() ? "0" : res;
    }
};
