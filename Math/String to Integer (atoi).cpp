/*
Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.

Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.

spoilers alert... click to show requirements for atoi.

Requirements for atoi:
The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.

The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.

If no valid conversion could be performed, a zero value is returned. If the correct value is out of the range of representable values, INT_MAX (2147483647) or INT_MIN (-2147483648) is returned.
*/

/*
学到的东西：
while (i < length && str[i] <= '9' && str[i] >= '0') {
    if (res > INT_MAX / 10 || res == INT_MAX / 10 && str[i] - '0' > INT_MAX % 10) {
        return sig == '+' ? INT_MAX : INT_MIN;
    }
    res = res * 10 + str[i] - '0';
    i++;
}
在计算res时便判断是否溢出
溢出也不用判断正负号了，res == INT_MAX / 10 && str[i] - '0' > INT_MAX % 10就可以了！
*/

class Solution {
public:
    int atoi(const char *str) {
        if (str == NULL) {
            return 0;
        }
        int length = strlen(str);
        int i = 0, sigCnt = 0, res = 0;
        string resStr = "";
        char sig = '+';
        
        //begining blanks
        while (i < length && str[i] == ' ') {
            i++;
        }
        
        //sig
        while (i < length && str[i] == '+' || str[i] == '-') {
            sigCnt++;
            sig = str[i];
            i++;
        }
        if (sigCnt > 1) {
            return 0;
        }
        
        //digits
        while (i < length && str[i] <= '9' && str[i] >= '0') {
            if (res > INT_MAX / 10 || res == INT_MAX / 10 && str[i] - '0' > INT_MAX % 10) {
                return sig == '+' ? INT_MAX : INT_MIN;
            }
            res = res * 10 + str[i] - '0';
            i++;
        }
        
        return sig == '-' ? -1 * res : res;
        
    }
};
