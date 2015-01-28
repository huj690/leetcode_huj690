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
        if (n == 0) {
            return 0;
        }
        int cnt = 0;
        while (n > 0) {
            cnt += n / 5;
            n /= 5;
        }
        return cnt;
    }
};
