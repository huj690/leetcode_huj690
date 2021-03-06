class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        if (S.empty()) {
            return res;
        }
        sort(S.begin(), S.end());
        this->S = S;
        vector<int> sub;
        enumSubSets(sub, 0);
        return res;
    }
private:
    vector<int> S;
    vector<vector<int> > res;
    void enumSubSets(vector<int> sub, int level) {
        if (level == S.size()) {
            res.push_back(sub);
            return;
        }
        
        enumSubSets(sub, level + 1);
        sub.push_back(S[level]);
        enumSubSets(sub, level + 1);
        sub.pop_back();
        
    }
    
};
