/*
Given an unsorted array, find the maximum difference between the successive elements in its sorted form.
Try to solve it in linear time/space.
Return 0 if the array contains less than 2 elements.
You may assume all elements in the array are non-negative integers and fit in the 32-bit signed integer range.
*/

/*
桶排序
*/

class Solution {
public:
    int maximumGap(vector<int> &num) {
        if (num.empty() || num.size() < 2) {
            return 0;
        }
        int high = *max_element(num.begin(), num.end());
        int low = *min_element(num.begin(), num.end());
        
        int min_gap = ceil((double)(high - low) / (double)(num.size() - 1));
        int bucket_cnt = (high - low) / min_gap + 1;
        
        vector<pair<int, int>> buckets(bucket_cnt, make_pair(INT_MIN, INT_MAX)); // max_num, min_num
        for (int i = 0; i < num.size(); i++) {
            int index = (num[i] - low) / min_gap;
            buckets[index].first = max(buckets[index].first, num[i]);
            buckets[index].second = min(buckets[index].second, num[i]);
        }
        
        int res = INT_MIN, prev_max = low;
        for (int i = 0; i < buckets.size(); i++) {
            if (buckets[i].first != INT_MIN) {
                res = max(res, buckets[i].second - prev_max);
                prev_max = buckets[i].first;
            }
        }
        return res;
    }
};
