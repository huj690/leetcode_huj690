/*
Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.
A region is captured by flipping all 'O's into 'X's in that surrounded region.
For example,
X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:
X X X X
X X X X
X X X X
X O X X
*/

/*
中心思想：广搜
思想：只需要找到四个边界上连通的O，visit置为true，然后再把所有没有visit过的O置为X就可以了
注意点：
1. 利用delta值做递增，不要复制四遍代码
2. 先标记visit，再que.push，注意逻辑TOT
*/


struct Node {
    int i;
    int j;
    Node(int i, int j) : i(i), j(j) {}
};
class Solution {
public:
    void solve(vector<vector<char>> &board) {
        if (board.empty()) {
            return;
        }
        int row = board.size(), col = board[0].size();
        visit = initVisit(row, col);
        // up | down | left | right bound
         for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if ((i == 0 || j == 0 || i == row - 1 || j == col -1 ) && board[i][j] == 'O' && !visit[i][j]) {
                    	Node *node = new Node(i, j);
				        bfs(node, board);
                }
            }
         }
        
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (!visit[i][j] && board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
        
        return;
    }
private:
    vector<vector<bool>> visit;
    queue<Node*> que;
    
    void bfs(Node* node, vector<vector<char>> &board) {
        visit[node->i][node->j] = true; //be careful
        que.push(node);
        while (!que.empty()) {
            Node* top = que.front();
            que.pop();
            
            int i = top->i, j = top->j;
            //up & down
            for (int deltaI = -1; deltaI <= 1; deltaI += 2) {
                if (isLegal(i + deltaI, j, board)  && (board[i + deltaI][j] == 'O' && !visit[i + deltaI][j])) {
                	Node *tmp = new Node(i + deltaI, j);
                	visit[tmp->i][tmp->j] = true;
                	que.push(tmp);
                }
            }
            //left & right
            for (int deltaJ = -1; deltaJ <= 1; deltaJ += 2) {
                if (isLegal(i, j + deltaJ, board)  && (board[i][j + deltaJ] == 'O' && !visit[i][j + deltaJ])) {
                	Node *tmp = new Node(i, j + deltaJ);
                	visit[tmp->i][tmp->j] = true;
                	que.push(tmp);
                }     
            }
        }
        return;
    }
    
    bool isLegal (int i, int j, vector<vector<char>> &board) {
        return i >= 0 && i < board.size() && j >= 0 && j < board[0].size();
    }
    
    vector<vector<bool>> initVisit(int row, int col) {
        vector<vector<bool>> res;
        for (int i = 0; i < row; i++) {
            vector<bool> sub;
            for (int j = 0; j < col; j++) {
                sub.push_back(false);
            }
            res.push_back(sub);
        }
        return res;
    }
};
