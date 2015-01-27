/*
Given a collection of integers that might contain duplicates, S, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If S = [1,2,2], a solution is:

[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
*/

/*
学到的东西：
有重复元的意义在于：之前是一个元素只能出现0次或1次，现在是0次或多次
*/

class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        if (S.empty()) {
            return res;
        }
        sort(S.begin(), S.end());
        this->S = S;
        vector<int> sub;
        enumSubsets(sub, 0);
        return res;
    }
private:
    vector<vector<int> > res;
    vector<int> S;
    void enumSubsets(vector<int> sub, int level) {
        if (level == S.size()) {
            sort(sub.begin(), sub.end());
            res.push_back(sub);
            return;
        }
        int cnt = 1;
        while (level < S.size() - 1 && S[level] == S[level + 1]) {
            cnt++; level++;
        }
        for (int i = 0; i <= cnt; i++) {
            for (int j = 0; j < i; j++) {
                sub.push_back(S[level]);
            }
            enumSubsets(sub, level + 1);
            for (int j = 0; j < i; j++) {
                sub.pop_back();
            }
        }
    }
};
