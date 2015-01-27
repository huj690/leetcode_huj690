/*
Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321
*/

/*
学到的东西：
1. 给数字按位取反这么做：
int res = 0;
while (x != 0) {
    res = res * 10 + x % 10;
    x /= 10;
}
2. 负数取模=负数
3. 模运算与基本四则运算有些相似，但是除法例外。其规则如下：
(a + b) % p = (a % p + b % p) % p （1）
(a - b) % p = (a % p - b % p) % p （2）
(a * b) % p = (a % p * b % p) % p （3）
a ^ b % p = ((a % p)^b) % p （4）
结合律：
((a+b) % p + c) % p = (a + (b+c) % p) % p （5）
((a*b) % p * c)% p = (a * (b*c) % p) % p （6）
交换律：
(a + b) % p = (b+a) % p （7）
(a * b) % p = (b * a) % p （8）
分配律：
((a +b)% p * c) % p = ((a * c) % p + (b * c) % p) % p （9）
重要定理
若a≡b (% p)，则对于任意的c，都有(a + c) ≡ (b + c) (%p)；（10）
若a≡b (% p)，则对于任意的c，都有(a * c) ≡ (b * c) (%p)；（11）
若a≡b (% p)，c≡d (% p)，则 (a + c) ≡ (b + d) (%p)，(a - c) ≡ (b - d) (%p)，(a * c) ≡ (b * d) (%p)，(a / c) ≡ (b / d) (%p) （12）
*/

class Solution {
public:
    int reverse(int x) {
        int res = 0;
        while (x != 0) {
            if (res > 214748364 || res < -214748364) {
                return 0;
            }
            res = res * 10 + x % 10;
            x /= 10;
        }
        return res;
    }
};
