/*
Given a unsorted array with integers, find the median of it. 
A median is the middle number of the array after it is sorted. 
If there are even numbers in the array, return the N/2-th number after sorted.

Example
Given [4, 5, 1, 2, 3], return 3
Given [7, 9, 4, 5], return 5

Challenge
O(n) time.
*/

class Solution {
public:
    int median(vector<int> &nums) {
        if (nums.empty()) {
            return 0;
        }
        priority_queue<int> heap;
        for (auto x : nums) {
            heap.push(x);
        }
        int k = nums.size() / 2 + 1;
        int top = 0;
        while (k--) {
            top = heap.top();
            heap.pop();
        }
        return top;
    }
};

