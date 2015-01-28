/*
Given a collection of numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].
*/

/*
学到的东西：
在数组里找一个数的时候可以直接用find函数：
find(sub.begin(), sub.end(), num[i]) != sub.end()

本题也可以用一个全局的set来判断num[i]是否已经找过
*/

class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        if (num.empty()) {
            return res;
        }
        sort(num.begin(), num.end());
        this->num = num;
        vector<int> sub;
        enumPermutation(sub, 0);
        return res;
    }
private:
    vector<vector<int> > res;
    vector<int> num;
    
    void enumPermutation(vector<int> sub, int level) {
        if (level == num.size()) {
            res.push_back(sub);
            return;
        }
        for (int i = 0; i < num.size(); i++) {
            if (find(sub.begin(), sub.end(), num[i]) != sub.end()) {
                continue;
            }
            sub.push_back(num[i]);
            enumPermutation(sub, level + 1);
            sub.pop_back();
        }
    }
    
};
