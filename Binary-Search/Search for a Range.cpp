/*
Given a sorted array of integers, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].
*/

class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> res(2, -1);
        if (n == 0) {
            return res;
        }
        
        int low = 0, high = n - 1, pos = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (A[mid] == target) {
                pos = mid;
                break;
            } else if (A[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        if (pos == -1) { // 注意！
            return res;
        }
        int i = pos, j = pos;
        while (i >= 0 && A[i] == target) {
            i--;
        }
        while (j < n && A[j] == target) {
            j++;
        }
        res[0] = i + 1; res[1] = j - 1;
        return res;
    }
};
