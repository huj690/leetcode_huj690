/*
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:
Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

Example 2:
Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].

This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
*/

/*
做法
1. Sort the intervals based on increasing order of starting time.
2. Push the first interval on to a stack.
3. For each interval do the following
……..a. If the current interval does not overlap with the stack top, push it.
……..b. If the current interval overlaps with stack top and ending time of current interval is more than that of stack top, update stack top with the ending time of current interval.
4. At the end stack contains the merged intervals.
*/




 bool cmp(Interval a, Interval b) {
  return a.start < b.start;
};

class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end(), cmp); 
        stack<Interval> stk;
        stk.push(intervals[0]);
        
        for (int i = 1; i < intervals.size(); i++) {
            auto top = stk.top();
            if (isOverlap(top, intervals[i])) {
                if (intervals[i].end > top.end) {
                    stk.pop();
                    Interval newInt(top.start, intervals[i].end);
                    stk.push(newInt);
                }
            } else {
                stk.push(intervals[i]);
            }
        }
        
        vector<Interval> res;
        while (!stk.empty()) {
            res.push_back(stk.top());
            stk.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }

private:
    bool isOverlap(Interval a, Interval b) {
        return !(a.end < b.start || b.end < a.start);
    }
};

