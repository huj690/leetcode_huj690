/*
Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 10,1,2,7,6,1,5 and target 8, 
A solution set is: 
[1, 7] 
[1, 2, 5] 
[2, 6] 
[1, 1, 6] 
*/

/*
每种元素在同一层中只能使用一次，所以用一个prev记录
*/


class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        if (num.empty()) {
            return res;
        }    
        sort(num.begin(), num.end());
        this->num = num;
        vector<int> sub;
        enumCombination(sub, 0, target);
        return res;
    }
private:
    vector<vector<int> > res;
    vector<int> num;
    void enumCombination(vector<int> sub, int start, int target) {
        if (target == 0) {
            res.push_back(sub);
            return;
        }
        int prev = -1;
        for (int i = start; i < num.size(); i++) {
            if (prev == num[i]) {
                continue;
            }
            if (num[i] > target) {
                return;
            }
            sub.push_back(num[i]);
            prev = num[i];
            enumCombination(sub, i + 1, target - num[i]);
            sub.pop_back();
        }
    }
    
};
