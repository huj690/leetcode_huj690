/*
Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?
Would this affect the run-time complexity? How and why?
Write a function to determine if a given target is in the array.
*/

class Solution {
public:
    bool search(int A[], int n, int target) {
        int low = 0, high = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (A[mid] == target) {
                return true;
            }
            if (A[low] < A[mid]) { // low part is sorted
                if (A[low] <= target && target <= A[mid - 1]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            if (A[low] == A[mid]) {
                low++;
            }
            if (A[mid] < A[high]) { // high part is sorted
                if (A[mid + 1] <= target && target <= A[high]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
            if (A[mid] == A[high]) {
                high--;
            }
        }
        return false;
    }

};
