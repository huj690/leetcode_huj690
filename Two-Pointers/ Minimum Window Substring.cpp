/*
Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

For example,
S = "ADOBECODEBANC"
T = "ABC"
Minimum window is "BANC".

Note:
If there is no such window in S that covers all characters in T, return the emtpy string "".

If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.
*/

/*
思路：先找到第一个包含所有T中元素的窗口，然后窗口头部向前缩
*/

class Solution {
public:
    string minWindow(string S, string T) {
        if (S.empty() || T.empty()) {
            return "";
        }
        vector<int> expect(256, 0);
        vector<int> cur(256, 0);
        for (int i = 0; i < T.size(); i++) {
            expect[T[i]]++;
        }
        
        // i 代表窗口的开始，j 代表窗口的结束
        int min_win = INT_MAX, begin = 0, end = 0;
        int i = 0, cur_cnt = 0; // cur_cnt记录满足条件的字符数目
        
        // 遍历窗口的结束
        for (int j = 0; j < S.size(); j++) {
            if (expect[S[j]] > 0) { // S[j] 在T中可以找到
                cur[S[j]]++;
                if (cur[S[j]] <= expect[S[j]]) { // 当前字符的数目没有满的情况下可以给它加，满了之后就不再计入
                    cur_cnt++;
                }
            }
            
            if (cur_cnt == T.size()) { // 到j位置，已经包含一个完整的T了（但有重复元素）
                while (cur[S[i]] > expect[S[i]] || expect[S[i]] == 0) { // 如果这个字符是重复的删了没事 || 不在T中
                    cur[S[i]]--;
                    i++;
                }
                if (j - i + 1 < min_win) { // 更新窗长
                    begin = i;
                    min_win = j - i + 1;
                }
            }
        }
        
        return min_win == INT_MAX ? "" : S.substr(begin, min_win);
    }
};
