/*
Given a non-negative number represented as an array of digits, plus one to the number.
The digits are stored such that the most significant digit is at the head of the list.
*/
class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        if (digits.empty()) {
            return digits;
        }
        add(digits, 1);
        return digits;
    }
private:
    void add(vector<int> &digits, int num) {
        int carry = num;
        for (int i = digits.size() - 1; i >= 0; i--) {
            digits[i] += carry;
            carry = digits[i] / 10;
            digits[i] %= 10;
        }
        if (carry > 0) {
            digits.insert(digits.begin(), 1);
        }
    }
};
