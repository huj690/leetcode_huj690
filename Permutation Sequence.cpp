/*
The set [1,2,3,…,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3):
"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.
Note: Given n will be between 1 and 9 inclusive.
*/

/*
e.g. n = 4, k = 7
1. 1234
2. 1243
3. 1324
4. 1342
5. 1423
6. 1432
---------
7. 2134
8. 2143
9. 2314
10. 2341
11. 2413
12. 2431
---------
13. 3...
......
---------
19. 4...
......
---------

思想：一位一位确定是什么数字
首先建立所有数字的集合：digits = "1234"
level = 1时， 排列数被分为 4!/4 = 6组，groupIndex = ceil(7 / 6) - 1 = 1。（减1的目的是为了对应0开始的digits数组下标）
              说明第7个数在第1组里，当前数位为digits[1] = 2
              下一位不再可能出现"2"，digits.earse(digits.begin() + 2) 同时更新k在group中的位置: k = 7 % 6 = 1
level = 2时， ......
*/
class Solution {
public:
    string getPermutation(int n, int k) {
        if (n == 0 || k == 0) {
            return "";
        }
        
        string res = "";
        string digits = "";
        for (int i = 1; i <= n; i++) {
            digits += to_string(i);
        }
        
        int level = 0;
        int fac = factorial(n);
        while (level++ < n) {
            fac /= (n - level + 1);
            int groupIndex = ceil((double)k / (double)fac) - 1;
            res += digits[groupIndex];
            k %= fac;
			if (k == 0) {
				k = fac;
			}
            digits.erase(digits.begin() + groupIndex);
        }
        return res;
    }
private:
    int factorial(int n) {
        int res = 1;
        while (n--) {
            res *= (n + 1);
        }
        return res;
    }
};
