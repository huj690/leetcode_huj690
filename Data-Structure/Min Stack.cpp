/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
*/

class MinStack {
public:
    void push(int x) {
        int curMin = INT_MAX;
        if (!stk.empty()) {
            curMin = stk.top().second;
        }
        stk.push(make_pair(x, min(x, curMin)));
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
