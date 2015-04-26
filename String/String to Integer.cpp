/*
Implement atoi to convert a string to an integer.
*/

/*
test case:
1234
    1234
  +1234
 -234
12   234  
12afafkk1233
2147483647
-2147483648
198302183981401712341243124
123213.1231231
*/

class Solution {
public:
    int myAtoi(string str) {
        if (str.empty()) {
            return 0;
        }
        
        int sig = 1;
        int i = 0, len = str.length();
        while (i < len && str[i] == ' ') {
            i++;
        }
        if (str[i] == '+') {
            i++;
        } else if (str[i] == '-'){
            sig = -1;
            i++;
        }
        
        int res = 0;
        for (; i < len; i++) {
            if (str[i] > '9' || str[i] < '0') {
                break;
            }
            if (res > INT_MAX / 10 || (res == INT_MAX / 10 && str[i] - '0' > INT_MAX % 10)) {
                return sig < 0 ? INT_MIN : INT_MAX;
            }
            res = res * 10 + str[i] - '0';
        }
        return sig * res;
        
    }
};
