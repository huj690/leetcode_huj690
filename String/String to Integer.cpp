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
    int atoi(const char *str) {
        if (strlen(str) == 0) {
            return 0;
        }
        
        int i = 0;
        while (str[i] == ' ') {
            i++;
        }
        bool positive = true;
        if (str[i] == '-') {
            positive = false;
            i++;
        } else if (str[i] == '+') {
            i++;
        }
        
        string valid = "";
        while(str[i] <= '9' && str[i] >= '0') {
            valid += str[i];
            i++;
        }
        
		if (valid.length() > 10) {
				return positive == true ? INT_MAX : INT_MIN;
			}
        if (valid.length() == 10) {
            if (positive && valid > "2147483647") {
                return INT_MAX;
            }
            if (!positive && valid > "2147483648"){
                return INT_MIN;
            }
        }
        
        int res = 0;
        while (!valid.empty()) {
            res = res * 10 + valid[0] - '0';
            valid = valid.substr(1, valid.length() - 1);
        }
        return positive == true ? res : (-1) * res;
    }
};
