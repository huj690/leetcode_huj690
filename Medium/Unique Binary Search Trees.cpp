/*
Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
*/

/*
n = 0:      n = 1:      n = 2:                                n = 3:
f(0) = 1;   f(1) = 1;   f(2) = f(0) * f(1) + f(1) * f(0);     f(3) = SUM(f(i) * f(n - 1 - i)) i = 0..n-1  (一个节点为根)
            o           o   o
                      /       \
                    o           o
*/

class Solution {
public:
    int numTrees(int n) {
        if (n == 0) {
            return 0;
        }
        int *dp = new int[n];
        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            dp[i] = 0;
            for (int j = 0; j <= i - 1; j++) {
                dp[i] += dp[j] * dp[i - 1 - j];
            }
        }
        return dp[n];
    }
};
