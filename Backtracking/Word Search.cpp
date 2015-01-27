/*
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

For example,
Given board =

[
  ["ABCE"],
  ["SFCS"],
  ["ADEE"]
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.
*/

/*
学到的东西：
1. 二元数组初始化：vector<vector<bool> > visit (board.size(), vector<bool> (board[0].size(), false));
2. 无论何时，都记得要变回原来的样子：
visit[x][y] = true;
bool res = enumPath(pos + 1, x - 1, y) ||
        enumPath(pos + 1, x + 1, y) ||
        enumPath(pos + 1, x, y - 1) ||
        enumPath(pos + 1, x, y + 1);
visit[x][y] = false;
*/

class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        if (board.empty()) {
            return false;
        }
        this->board = board;
        this->word = word;
        vector<vector<bool> > visit (board.size(), vector<bool> (board[0].size(), false));
        this->visit = visit;
        
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (enumPath(0, i, j)) {
                    return true;
                }
            }
        }
        return false;
    }
private:
    string word;
    vector<vector<char> > board;
    vector<vector<bool> > visit;
    bool enumPath(int pos, int x, int y) {
        if (pos == word.size()) {
            return true;
        }
        if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size()) {
            return false;
        }
        if (visit[x][y]) {
            return false;
        }
        if (board[x][y] != word[pos]) {
            return false;
        }
        
        visit[x][y] = true;
        bool res = enumPath(pos + 1, x - 1, y) ||
                enumPath(pos + 1, x + 1, y) ||
                enumPath(pos + 1, x, y - 1) ||
                enumPath(pos + 1, x, y + 1);
        visit[x][y] = false;
        return res;
    }
    
};
