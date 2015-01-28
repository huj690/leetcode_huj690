/*
Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 2,3,6,7 and target 7, 
A solution set is: 
[7] 
[2, 2, 3] 
*/

/*
注意level并不是万能的，有时候需要枚举的是起始位置start
*/

class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        if (candidates.empty()) {
            return res;
        }
        sort(candidates.begin(), candidates.end());
        this->candidates = candidates;
        vector<int> sub;
        enumCombination(sub, 0, target);
        return res;
    }
private:
    vector<vector<int> > res;
    vector<int> candidates;
    void enumCombination(vector<int> sub, int start, int target) {
        if (target == 0) {
            res.push_back(sub);
            return;
        }
        for (int i = start; i < candidates.size(); i++) {
            if (candidates[i] > target) { //这个剪枝很有效
                return;
            }
            sub.push_back(candidates[i]);
            enumCombination(sub, i, target - candidates[i]);
            sub.pop_back();
        }
    }
};
