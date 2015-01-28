/*
Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:
[1,1,2], [1,2,1], and [2,1,1].
*/

/*
本题有两种解法：
1. 递归
  注意点是有两个地方是需要跳过的：1）出现过的i不可以再出现 2）同层不能出现相同元素
2. 不断调用next_permutation
*/

//解法1
class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
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
    unordered_set<int> set;
    
    void enumPermutation(vector<int> sub, int level) {
        if (level == num.size()) {
            res.push_back(sub);
            return;
        }
        int prev = INT_MIN;
        for (int i = 0 ; i < num.size(); i++) {
            if (set.count(i) > 0 || prev == num[i]) {
                continue;
            }
            
            set.insert(i);
            prev = num[i];
            sub.push_back(num[i]);
            enumPermutation(sub, level + 1);
            sub.pop_back();
            set.erase(i);
        }
    }
};



//解法2
class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        vector<vector<int>> res;
        if (num.empty()) {
            return res;
        }
        sort(num.begin(), num.end());
        
        do {
            res.push_back(num);
        } while (!isNextPermutationFinish(num));
        return res;
    }
private:
    bool isNextPermutationFinish(vector<int> &num) {
        int i = num.size() - 1;
        while (i > 0 && num[i - 1] >= num[i]) {
            i--;
        }
        i--;
        if (i < 0) {
            return true;
        }
        
        int j = num.size() - 1; 
        while (num[i] >= num[j]) {
            j--;
        }
        swap(num[i], num[j]);
        sort(num.begin() + i + 1, num.end());
        return false;
    }
    
};
