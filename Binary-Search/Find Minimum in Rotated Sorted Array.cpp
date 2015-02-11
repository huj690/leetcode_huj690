/*
Suppose a sorted array is rotated at some pivot unknown to you beforehand.
(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
Find the minimum element.
The array not contain duplicates.

*/
class Solution {
public:
    int findMin(vector<int> &num) {
        if (num.empty()) {
            return 0;
        }
        
        int low = 0, high = num.size() - 1;
        while (low < high) { // 注意不能用=
            int mid = low + (high - low) / 2;
            if (num[low] <= num[mid]) { // 左半边是有序的（注意相等时也是表示有序）
                if (num[mid] < num[high]) { // 整个数组是有序的
                    return num[low];
                } else { //右半边是有序的
                    low = mid + 1;
                }
            } else {
                high = mid;
            }
        }
        return num[low];
    }
};
