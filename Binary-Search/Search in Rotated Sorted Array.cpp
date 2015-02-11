/*
Suppose a sorted array is rotated at some pivot unknown to you beforehand.
(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
You are given a target value to search. If found in the array return its index, otherwise return -1.
You may assume no duplicate exists in the array.
*/

class Solution {
public:
    int search(int A[], int n, int target) {
        if (n == 0) {
            return 0;
        }
        
        int low = 0, high = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (A[mid] == target) {
                return mid;
            }
            if (A[low] < A[mid]) { // low part is sorted
                if (A[low] <= target && target <= A[mid - 1]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            } else { // high part is sorted
                if (A[mid + 1] <= target && target <= A[high]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }
        return -1;
    }
};
