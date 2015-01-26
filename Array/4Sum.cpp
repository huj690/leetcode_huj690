/*
Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note:
Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
The solution set must not contain duplicate quadruplets.
    For example, given array S = {1 0 -1 0 -2 2}, and target = 0.

    A solution set is:
    (-1,  0, 0, 1)
    (-2, -1, 1, 2)
    (-2,  0, 0, 2)
*/

/*
据说这个方法更好，回来试一试：
// LeetCode, 4Sum
// 用一个 hashmap 先缓存两个数的和
// 时间复杂度，平均 O(n^2) ，最坏 O(n^4) ，空间复杂度 O(n^2)
*/

class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int> > res;
        if (num.empty() || num.size() < 4) {
            return res;
        }
        sort(num.begin(), num.end());
        for (int i = 0; i < num.size(); i++) {
            if (i > 0 && num[i] == num[i - 1]) {
                continue;
            }
            int target_i = target - num[i];
            for (int j = i + 1; j < num.size(); j++) {
                if (j > i + 1 && num[j] == num[j - 1]) {
                    continue;
                }
                int target_j = target_i - num[j];
                
                int low = j + 1, high = num.size() - 1;
                while (low < high) {
                    if (num[low] + num[high] == target_j) {
                        res.push_back( {num[i], num[j], num[low], num[high]} );
                        do { low++; high--; } while (low < high && num[low] == num[low - 1] && num[high] == num[high + 1]);
                    } else if (num[low] + num[high] < target_j) {
                        do { low++; } while (low < high && num[low] == num[low - 1]);
                    } else {
                        do { high--; } while (low < high && num[high] == num[high + 1]);
                    }
                }
            }
        }
        
        return res;
    }
};
