/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

For example:
Given array A = [2,3,1,1,4]

The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)
*/

class Solution {
public:
    int jump(int A[], int n) {
        if (n == 0) {
            return 0;
        }
        // 用left和right框住本层最近和最远的距离，贪心策略：每次跳到最远的地方
        int left = 0, right = 0, step = 0;
        while (left <= right) {
            if (right >= n - 1) {
                return step;
            }
            step++;
            int max_step = -1, min_step = INT_MAX;
            for (int i = left; i <= right; i++) {
                max_step = max(max_step, i + A[i]);
            }
            left = right + 1;
            right = max_step;
        }
        
    }
};
