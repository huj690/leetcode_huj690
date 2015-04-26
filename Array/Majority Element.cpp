/*
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        
        int cnt = 1, mar = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == mar) {
                cnt++;
            } else {
                cnt--;
                if (cnt == 0) {
                    mar = nums[i];
                    cnt = 1;
                }
            }
        }
        return mar;
    }
};
