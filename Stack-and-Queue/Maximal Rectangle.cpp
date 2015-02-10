/*
Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing all ones and return its area.
*/

/*
做法：当做二维的直方图最大矩阵面积来做
*/

class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        if (matrix.empty()) {
            return 0;
        }
        int row = matrix.size(), col = matrix[0].size();
        int res = 0;
        
        vector<int> height_prev(col, 0);
        vector<int> height(col, 0);
        for (int j = 0; j < col; j++) {
            if (matrix[0][j] == '1') {
                height_prev[j] = 1;
            }
        }
        res = max(res, getMax(height_prev));
        
        for (int i = 1; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (matrix[i][j] == '1') {
                    height[j] = height_prev[j] == 0 ? 1 : height_prev[j] + 1; 
                }
            }
            res = max(res, getMax(height));
            height_prev = height;
            height.assign(col, 0);
        }
        return res;
    }

private:
    int getMax(vector<int> &height) {
        if (height.empty()) {
            return 0;
        }
        height.push_back(0);
        stack<int> stk;
        int max_area = 0;
        for (int i = 0; i < height.size();) {
            if (stk.empty() || height[i] > height[stk.top()]) {
                stk.push(i++);
            } else {
                auto top = stk.top();
                stk.pop();
                int right = i, left = stk.empty() ? -1 :  stk.top();
                max_area = max(max_area, height[top] * (right - left - 1));
            }
        }
        return max_area;
    }
};
