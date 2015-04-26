/*
Given an integer n, return the number of trailing zeroes in n!.
Note: Your solution should be in logarithmic time complexity.
*/

/*
末尾的0是由5来贡献的，一个5贡献1个，一个25贡献2个....
*/

class Solution {
public:
    int trailingZeroes(int n) {
        int res = 0;
        while (n != 0) {
            res += n / 5;
            n /= 5;
        }
        return res;
    }
};
