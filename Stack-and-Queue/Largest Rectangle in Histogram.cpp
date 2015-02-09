/*
Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.
Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].
The largest rectangle is shown in the shaded area, which has area = 10 unit.

For example,
Given height = [2,1,5,6,2,3],
return 10.
*/

/*
思路：
当我以某个height[i]作为矩形最低点时，我需要向右去第一个比他小的，向左找第一个比他小的，两个边界围成的矩形即为所求。
于是维护一个栈，遍历height数组，如果height[i] > top，则入栈。当遇到height[i] <= top，则说明找到了栈顶元素的右边界，取出栈顶并pop
则当前栈顶为cur的左边界，于是可以开始计算cur的res啦~~

值得注意的是~~最后一个区域没办法计算，怎么办？~只需要给height多加一个0在后面就可以解决了
*/

class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        if (height.empty()) {
            return 0;
        }
        
        int res = 0;
        stack<int> stk;
        
        height.push_back(0); // add to end
        for (int i = 0; i < height.size();) {
            if (stk.empty() || height[i] > height[stk.top()]) {
                stk.push(i++);
            } else {
                int cur_low = stk.top();
                stk.pop();
                int right = i, left = stk.empty() ? -1 : stk.top();
                res = max(res, height[cur_low] * (right - left - 1));
            }
        }
        
        return res;
    }
};
