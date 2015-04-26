class MinStack {
public:
    void push(int x) {
        int cur_min = x;
        if (!stk.empty()) {
            auto top = stk.top();
            cur_min = x < top.second ? x : top.second;
        }
        stk.push(make_pair(x, cur_min));
    }

    void pop() {
        if (!stk.empty()) {
            stk.pop();
        }
    }

    int top() {
        if (!stk.empty()) {
            return stk.top().first;
        }
    }

    int getMin() {
        if (!stk.empty()) {
            return stk.top().second;
        }
    }
private:
    stack<pair<int, int>> stk;
};
