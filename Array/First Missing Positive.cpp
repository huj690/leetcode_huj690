/*
Given an unsorted integer array, find the first missing positive integer.

For example,
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.

Your algorithm should run in O(n) time and uses constant space.
*/


//attention: 1, 11, 3431

class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        if (n == 0) {
            return 1;
        }
        for (int i = 0; i < n; i++) {
            while (A[i] != i + 1 && A[i] != A[A[i] - 1] && A[i] >= 1 && A[i] <= n) {
                swap(A[i], A[A[i] - 1]);
            }
        }
        for (int i = 0; i < n; i++) {
            if (A[i] != i + 1) {
                return i + 1;
            }
        }
        return n + 1;
    }
};
