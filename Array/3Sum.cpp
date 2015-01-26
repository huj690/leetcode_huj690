/*
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:
Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
The solution set must not contain duplicate triplets.
    For example, given array S = {-1 0 1 2 -1 -4},

    A solution set is:
    (-1, 0, 1)
    (-1, -1, 2)
*/

/*
解题思路：
先排序，再左右夹逼，时间复杂度O(n^2)，空间O(1)
但是要小心重复元的处理
*/

/*
学到的东西：
res.push_back({num[i], num[low], num[high]});
*/
class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int>> res;
        if (num.empty() || num.size() < 3) {
            return res;
        }
        sort(num.begin(), num.end());
        for (int i = 0; i < num.size(); i++) {
            if (i > 0 && num[i] == num[i - 1]) {
                continue;
            }
            
            int target = 0 - num[i], low = i + 1, high = num.size() - 1;
            while (low < num.size() - 1 && high > i + 1 && low < high) {
                if (num[low] + num[high] == target) {
                    res.push_back({num[i], num[low], num[high]});
                    
                    low++; high--;
                    while (low < high && num[low] == num[low - 1] && num[high] == num[high + 1]) {
                        low++; high--;
                    }
                } else if (num[low] + num[high] < target) {
                    low++;
                    while (low < high && num[low] == num[low - 1]) {
                        low++;
                    }
                } else {
                    high--;
                    while (low < high && num[high] == num[high + 1]) {
                        high--;
                    }
                }
            }
        }
        
        return res;
    }
};
