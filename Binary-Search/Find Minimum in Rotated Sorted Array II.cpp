/*
Follow up for "Find Minimum in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?
*/


class Solution {
public:
    int findMin(vector<int> &num) {
        if (num.empty()) {
            return 0;
        }
        
        int low = 0, high = num.size() - 1;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (num[low] <= num[mid]) {
                if (num[mid] < num[high]) {
                    return num[low];
                }
                if (num[mid] == num[high]) { //多举几个例子，然后对照着改
                    high--;
                } 
                if (num[mid] > num[high]) {
                    low = mid + 1;
                }
            } else {
                high = mid;
            }
        }
        return num[low];
    }
};
