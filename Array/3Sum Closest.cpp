/*
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.
For example, given array S = {-1 2 1 -4}, and target = 1.
The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/

/*
学到的东西：
赋值就是赋值，不可以加表达式在里面：
minGap = minGap < abs(target - tmpSum) ? minGap : abs(target - tmpSum), sum = tmpSum;
是错的！
*/
class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        if (num.empty() || num.size() < 3) {
            return 0;
        }
        
        int minGap = INT_MAX, sum = 0;
        sort(num.begin(), num.end());
        for (int i = 0; i < num.size(); i++) {
            int low = i + 1, high = num.size() - 1;
            while (low < high) {
                int tmpSum = num[i] + num[low] + num[high], tmpGap = abs(target - tmpSum);
                if (tmpGap < minGap) {
                    minGap = tmpGap;
                    sum = tmpSum;
                } 
                if (tmpSum < target) {
                    low++;
                } else {
                    high--;
                }
            }
        }
        return sum;
    }
};
